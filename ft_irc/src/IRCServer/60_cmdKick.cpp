/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   60_cmdKick.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:19:51 by abeltran          #+#    #+#             */
/*   Updated: 2024/05/15 10:47:40 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IRCServer.hpp"

void IRCServer::_cmdKick(User &usr, Message &msg)
{
	std::string	response;
	std::string	channel;
	std::string kicked_user;
	std::string	old_op;
	bool		found_user;
	bool		found_kicked;
	int			kicked_index;

	if (channel == msg.getCmd())
	{
		response = ":" + usr.getIp() + " 461 " + usr.getNickname()
				+ " KICK :Not enough parameters\r\n";
		send(usr.getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
					<< "(" << usr.getIp() << ") >> " << response;
		return ;
	}
	channel = msg.getArgs(0);
	kicked_user = msg.getArgs(1);
	if (_channels.find(channel) == _channels.end())
	{
		response = " :" + usr.getIp() + " 403 " + usr.getNickname()
				+ channel + 
				+ " :No such channel\r\n";
		send(usr.getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
					<< "(" << usr.getIp() << ") >> " << response;
		return ;
	}
	found_user = false;
	found_kicked = false;
	for (std::vector<User>::iterator it = _channels[channel].getUsers().begin(); 
		it != _channels[channel].getUsers().end(); it++)
	{
		if (it->getNickname() == usr.getNickname())
		{
			found_user = true;
			if (_channels[channel].getOp().getNickname() != usr.getNickname())
			{
				response = ":" + usr.getIp() + " 482 " + usr.getNickname() + " "
					+ _channels[channel].getName() + " :You're not channel operator\r\n";
				send(usr.getFd(), response.c_str(), response.size(), 0);
				std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
							<< "(" << usr.getIp() << ") >> " << response;
				return ;
			}	
			break;
		}
	}
	for (std::vector<User>::iterator it = _channels[channel].getUsers().begin(); 
		it != _channels[channel].getUsers().end(); it++)
	{
		if (it->getNickname() == msg.getArgs(1))
		{
			kicked_index = it - _channels[channel].getUsers().begin();
			found_kicked = true;
			break;
		}
	
	}
	if (!found_user)
	{
		response = ":" + usr.getIp() + " 442 " + usr.getNickname()
				+ channel + 
				+ " :You're not on that channel\r\n";
		send(usr.getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
					<< "(" << usr.getIp() << ") >> " << response;
		return ;
	}
	if (!found_kicked)
	{
		response = ":" + usr.getIp() + " 441 " + msg.getArgs(1)
				+ " " + channel + 
				+ " :They aren't on that channel\r\n";
		send(usr.getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
					<< "(" << usr.getIp() << ") >> " << response;
		return ;
	}
	response = ":" + usr.getNickname() + "!" + usr.getUsername() + "@" + usr.getIp()
		+ " KICK " + _channels[channel].getName() + " " + msg.getArgs(1) + " :";
	if (msg.getMessageText() != "")
		response += msg.getMessageText() + "\r\n";
	else
		response += "Kicked by " + usr.getNickname() + "\r\n";
	for (std::vector<User>::iterator it = _channels[channel].getUsers().begin();
		it != _channels[channel].getUsers().end(); it++)
	{
		send(it->getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << it->getFd()
					<< "(" << it->getIp() << ") >> " << response;
	}
	_channels[channel].getUsers().erase(_channels[channel].getUsers().begin() + kicked_index);
	if (_channels[msg.getArgs(0)].getUsers().size() == 0)
		_channels.erase(msg.getArgs(0));
	else if (_channels[msg.getArgs(0)].getUsers().size() == 1 || _channels[msg.getArgs(0)].getOp().getNickname() == msg.getArgs(1))
	{
		old_op = _channels[msg.getArgs(0)].getOp().getNickname();
		_channels[msg.getArgs(0)].setOp(_channels[msg.getArgs(0)].getUsers()[0]);
		for (std::vector<User>::iterator it = _channels[msg.getArgs(0)].getUsers().begin(); it != _channels[msg.getArgs(0)].getUsers().end(); it++)
		{
			response = ":" + usr.getNickname() + "!" + usr.getUsername() + "@" + usr.getIp()
				+ " MODE " + msg.getArgs()[0] + " -o " + old_op + "\r\n";
			send(it->getFd(), response.c_str(), response.size(), 0);
			std::cout	<< "[ SERVER ] Message sent to client " << it->getFd()
						<< "(" << it->getIp() << ") >> " << response;
			response = ":" + usr.getNickname() + "!" + usr.getUsername() + "@" + usr.getIp()
				+ " MODE " + msg.getArgs()[0] + " +o " + _channels[msg.getArgs(0)].getUsers()[0].getNickname() + "\r\n";
			send(it->getFd(), response.c_str(), response.size(), 0);
			std::cout	<< "[ SERVER ] Message sent to client " << it->getFd()
						<< "(" << it->getIp() << ") >> " << response;
		}
	}
}
