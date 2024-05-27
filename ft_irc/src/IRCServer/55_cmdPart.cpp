/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   55_cmdPart.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:19:54 by abeltran          #+#    #+#             */
/*   Updated: 2024/05/15 10:48:05 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IRCServer.hpp"

void IRCServer::_cmdPart(User &usr, Message &msg)
{
	std::string	response;
	std::string	old_op;
	bool		found;

	if (msg.getArgs(0) == msg.getCmd())
	{
		response = ":" + usr.getIp() + " 461 " + usr.getNickname()
				+ " PART :Not enough parameters\r\n";
		send(usr.getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
					<< "(" << usr.getIp() << ") >> " << response;
		return ;
	}
	if (_channels.find(msg.getArgs(0)) == _channels.end())
	{
		response = ":" + usr.getIp() + " 403 " + usr.getNickname()
				+ msg.getArgs(0) + 
				+ " :No such channel\r\n";
		send(usr.getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
					<< "(" << usr.getIp() << ") >> " << response;
		return ;
	}
	found = false;
	for (std::vector<User>::iterator it = _channels[msg.getArgs(0)].getUsers().begin(); 
		it != _channels[msg.getArgs(0)].getUsers().end(); it++)
	{
		if (it->getNickname() == usr.getNickname())
		{
			_channels[msg.getArgs(0)].getUsers().erase(it);
			found = true;
			break;
		}
	}
	if (!found)
	{
		response = ":" + usr.getIp() + " 442 " + usr.getNickname()
				+ msg.getArgs(0) + 
				+ " :You're not on that channel\r\n";
		send(usr.getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
					<< "(" << usr.getIp() << ") >> " << response;
		return ;
	}
	response = ":" + usr.getNickname() + "!" + usr.getUsername() + "@" + usr.getIp()
		+ " PART " + msg.getArgs(0);
	if (msg.getMessageText().empty())
		response += " Leaving\r\n";
	else
		response += " " + msg.getMessageText() + "\r\n";
	send(usr.getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
					<< "(" << usr.getIp() << ") >> " << response;
	for (std::vector<User>::iterator it = _channels[msg.getArgs(0)].getUsers().begin();
		it != _channels[msg.getArgs(0)].getUsers().end(); it++)
	{
		send(it->getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << it->getFd()
					<< "(" << it->getIp() << ") >> " << response << std::endl;
	}

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
