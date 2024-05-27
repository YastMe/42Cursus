/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   80__cmdInvite.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 00:36:14 by fragarci          #+#    #+#             */
/*   Updated: 2024/05/15 12:00:29 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IRCServer.hpp"

static Channel	*search_channel(std::map<std::string, Channel> *channels, Message *msg)
{
	for (std::map<std::string, Channel>::iterator it = channels->begin(); it !=channels->end(); it++)
	{
		if (it->first == msg->getArgs()[1])
		{
			return &it->second;
		}
	}
	return NULL;
}

void	IRCServer::_cmdInvite(User &usr, Message &msg)
{
	std::string response;
	Channel *chn;
	// 1.- Check for missing arguments	(461)
	if (msg.getArgs().size() < 2)
	{
		response = ":" + usr.getIp() + " 461 " + usr.getNickname()
				   + " INVITE :Not enough parameters\r\n";
		send(usr.getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
					 << "(" << usr.getIp() << ") >> " << response;
		return ;
	}
	chn = search_channel(&_channels, &msg);
	// 2.- Check if the channel exists	(403)
	if (chn == NULL)
	{
		// 403 ERR_NOSUCHCHANNEL
		response = ":" + usr.getIp() + " 403 " + usr.getNickname()
				   + " " + msg.getArgs()[1] + " :No such channel\r\n";
		send(usr.getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
					 << "(" << usr.getIp() << ") >> " << response;
		return ;
	}
	// 3.- Check if the sender is in the channel	(442)
	bool user_in_channel = false;
	for (std::vector<User>::iterator it = _channels[msg.getArgs()[1]].getUsers().begin();
		 it != _channels[msg.getArgs()[1]].getUsers().end(); it++)
		if (it->getNickname() == usr.getNickname())
			user_in_channel = true;
	// 442 ERR_NOTONCHANNEL
	if (!user_in_channel)
	{
		response = ":" + usr.getIp() + " 442 " + usr.getNickname()
				   + " " + msg.getArgs(1) + " :You're not on that channel\r\n";
		send(usr.getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
					 << "(" << usr.getIp() << ") >> " << response;
		return ;
	}
	// 4.- Check if the sender is the OP of the channel	(482)
	if (usr.getNickname() != _channels[msg.getArgs()[1]].getOp().getNickname())
	{
		// 482 ERR_CHANOPRIVSNEEDED
		response = ":" + usr.getIp() + " 482 " + usr.getNickname()
				   + " " + msg.getArgs(1) + " :You're not channel operator\r\n";
		send(usr.getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
					 << "(" << usr.getIp() << ") >> " << response;
		return ;
	}
	// 5.- Check if the user being invited is allready on the channel	(443)
	bool found = false;
	for (std::vector<User>::iterator it = _channels[msg.getArgs(1)].getUsers().begin();
		 it != _channels[msg.getArgs(1)].getUsers().end(); it++)
	{
		if (it->getNickname() == msg.getArgs(0))
		{
			found = true;
			break;
		}
	}
	if (found)
	{
		response = ":" + usr.getIp() + " 443 " + usr.getNickname()
				   + " " + msg.getArgs(0) + " " + msg.getArgs(1) + " :is already on channel\r\n";
		send(usr.getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
					 << "(" << usr.getIp() << ") >> " << response;
		return ;
	}
	// 6.- Finally Invite the user
	response = ":" + usr.getIp() + " 341 " + usr.getNickname()
			   + " " + msg.getArgs(0) + " " + msg.getArgs(1) + "\r\n";
	send(usr.getFd(), response.c_str(), response.size(), 0);
	std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
				 << "(" << usr.getIp() << ") >> " << response;
	for (std::map<int, User>::iterator it = _users.begin(); it != _users.end(); it++)
	{
		if (it->second.getNickname() == msg.getArgs(0))
		{
			_channels[msg.getArgs(1)].getInvite().push_back(it->second);
			response = ":" + usr.getNickname() + "!" + usr.getUsername() + "@" + usr.getIp()
					   + " INVITE " + msg.getArgs()[0] + " " + msg.getArgs(1) + "\r\n";
			send(it->first, response.c_str(), response.size(), 0);
			std::cout	<< "[ SERVER ] Message sent to client " << it->first
						 << "(" << it->second.getIp() << ") >> " << response;
			break;
		}
	}

//	response = ":" + usr.getNickname() + "!" + usr.getUsername() + "@" + usr.getIp()
//			   + " INVITE " + msg.getArgs()[0] + " " + msg.getArgs(1) + "\r\n";
//	send(user_fd, response.c_str(), response.size(), 0);
//	std::cout	<< "[ SERVER ] Message sent to client " << user_fd
//				 << "(" << _users[user_fd].getIp() << ") >> " << response;


}
