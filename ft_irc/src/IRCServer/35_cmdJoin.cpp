/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   35_cmdJoin.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:51:08 by fragarci          #+#    #+#             */
/*   Updated: 2024/05/15 12:12:00 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IRCServer.hpp"

void	IRCServer::_cmdJoin(User &usr, Message &msg)
{
	std::string	response = "";

	// Not enough params
	if (msg.getArgs().size() < 1 || msg.getArgs()[0] == "JOIN")
	{
		response = ":" + usr.getIp() + " 461 " + usr.getNickname()
				+ " JOIN :Not enough parameters\r\n";
		send(usr.getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
					<< "(" << usr.getIp() << ") >> " << response;
		return ;
	}
	// Channel doesn't start with #
	if (msg.getArgs()[0][0] != '#')
	{
		// 403 ERR_NOSUCHCHANNEL
		response = ":" + usr.getIp() + " 403 " + usr.getNickname()
				+ " " + msg.getArgs()[0] + " :No such channel\r\n";
		send(usr.getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
					<< "(" << usr.getIp() << ") >> " << response;
		return ;
	}
	// JOIN with 1 param when channel doesn't exist
	if (msg.getArgs().size() == 1 && _channels.find(msg.getArgs()[0]) == _channels.end())
	{
		Channel new_channel = Channel(msg.getArgs()[0], usr);
		new_channel.getUsers().push_back(usr);
		_channels[msg.getArgs()[0]] = new_channel;
		// JOIN Message Confirmation
		response = ":" + usr.getNickname() + "!" + usr.getUsername() + "@" + usr.getIp()
				+ " JOIN :" + msg.getArgs()[0] + "\r\n";
		send(usr.getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
					<< "(" << usr.getIp() << ") >> " << response;
		// 353 RPL_NAMREPLY
		response = ":" + usr.getIp() + " 353 " + usr.getNickname()
				+ " = " + msg.getArgs()[0] + " :@" + usr.getNickname() + "\r\n";
		send(usr.getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
					<< "(" << usr.getIp() << ") >> " << response;
		// 366 RPL_ENDOFNAMES
		response = ":" + usr.getIp() + " 366 " + usr.getNickname()
				+ " " + msg.getArgs()[0] + " :End of /NAMES list.\r\n";
		send(usr.getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
					<< "(" << usr.getIp() << ") >> " << response;
		return ;
	}
	// Channel is invite only
	if (_channels[msg.getArgs()[0]].getModes().find("i") != std::string::npos)
	{
		std::vector<User> invites = _channels[msg.getArgs()[0]].getInvite();
		bool found = false;
		for (std::vector<User>::iterator it = invites.begin(); it != invites.end(); it++)
			if (it->getNickname() == usr.getNickname())
				found = true;
		if (!found)
		{
			// 473 ERR_INVITEONLYCHAN
			response = ":" + usr.getIp() + " 473 " + usr.getNickname()
					+ " " + msg.getArgs()[0] + " :Cannot join channel (+i)\r\n";
			send(usr.getFd(), response.c_str(), response.size(), 0);
			std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
						<< "(" << usr.getIp() << ") >> " << response;
			return ;
		}
	}
	// Channel has a user limit
	if (_channels[msg.getArgs()[0]].getMaxUsers() > 0)
	{
		if ((int)_channels[msg.getArgs()[0]].getUsers().size() >= _channels[msg.getArgs()[0]].getMaxUsers())
		{
			// 471 ERR_CHANNELISFULL
			response = ":" + usr.getIp() + " 471 " + usr.getNickname()
					+ " " + msg.getArgs()[0] + " :Cannot join channel (+l)\r\n";
			send(usr.getFd(), response.c_str(), response.size(), 0);
			std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
						<< "(" << usr.getIp() << ") >> " << response;
			return ;
		}
	}
	// Check if the user allready joined the channel
	std::vector<User> ch_users = _channels[msg.getArgs()[0]].getUsers();
	for (std::vector<User>::iterator it = ch_users.begin(); it != ch_users.end(); it++)
	{
		if (it->getNickname() != usr.getNickname())
			continue;
		return;
	}
	// Channel has password
	if (!_channels[msg.getArgs()[0]].getPasswd().empty())
	{
		if (msg.getArgs().size() != 2 || msg.getArgs()[1] != _channels[msg.getArgs()[0]].getPasswd())
		{
			// 475 ERR_BADCHANNELKEY
			response = ":" + usr.getIp() + " 475 " + usr.getNickname()
					+ " " + msg.getArgs()[0] + " :Cannot join channel (+k)\r\n";
			send(usr.getFd(), response.c_str(), response.size(), 0);
			std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
						<< "(" << usr.getIp() << ") >> " << response;
			return ;
		}
	}
	// After all of this, FINALLY, let the user in the channel.
	_channels[msg.getArgs()[0]].getUsers().push_back(usr);
	std::vector<User> users = _channels[msg.getArgs()[0]].getUsers();
	// JOIN Message Confirmation to all users in the channel
	response = ":" + usr.getNickname() + "!" + usr.getUsername() + "@" + usr.getIp()
			+ " JOIN :" + msg.getArgs()[0] + "\r\n";
	for (std::vector<User>::iterator it = users.begin(); it != users.end(); it++)
	{
		send(it->getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << it->getFd()
					<< "(" << it->getIp() << ") >> " << response;
	}
	// 332 RPL_TOPIC
	if (!_channels[msg.getArgs()[0]].getTopic().empty())
	{
		response = ":" + usr.getIp() + " 332 " + usr.getNickname()
				+ " " + msg.getArgs()[0] + " :" + _channels[msg.getArgs()[0]].getTopic() + "\r\n";
		send(usr.getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
					<< "(" << usr.getIp() << ") >> " << response;
	}
	// Build 353 RPL_NAMREPLY
	response = ":" + usr.getIp() + " 353 " + usr.getNickname()
			+ " = " + msg.getArgs()[0] + " :";
	for (std::vector<User>::iterator it = users.begin(); it != users.end(); it++)
	{
		if (it == users.begin())
		{
			if (it->getNickname() == _channels[msg.getArgs()[0]].getOp().getNickname())
				response += "@" + it->getNickname();
			else
				response += it->getNickname();
			continue;
		}
		if (it->getNickname() == _channels[msg.getArgs()[0]].getOp().getNickname())
				response += " @" + it->getNickname();
		else
			response += " " + it->getNickname();
	}
	response += "\r\n";
	std::string	eon = ":" + usr.getIp() + " 366 " + usr.getNickname()
			+ " " + msg.getArgs()[0] + " :End of /NAMES list.\r\n";
	for (std::vector<User>::iterator it = users.begin(); it != users.end(); it++)
	{
		// Send 353 RPL_NAMREPLY
		send(it->getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << it->getFd()
					<< "(" << it->getIp() << ") >> " << response;
		//  Send 366 RPL_ENDOFNAMES
		send(it->getFd(), eon.c_str(), eon.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << it->getFd()
					<< "(" << it->getIp() << ") >> " << eon;
	}
}
