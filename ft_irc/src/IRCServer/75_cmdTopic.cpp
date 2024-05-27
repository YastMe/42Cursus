/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   75_cmdTopic.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:58:10 by jzaragoz          #+#    #+#             */
/*   Updated: 2024/05/15 00:25:04 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IRCServer.hpp"

// This is in a temp state, just wanna make sure the basic functionality works.

static Channel	*search_channel(std::map<std::string, Channel> *channels, Message *msg)
{
	for (std::map<std::string, Channel>::iterator it = channels->begin(); it !=channels->end(); it++)
	{
		if (it->first == msg->getArgs()[0])
		{
			return &it->second;
		}
	}
	return NULL;
}

void	IRCServer::_cmdTopic(User &usr, Message &msg)
{
	Channel	*chn;
	std::string	response;

	// Missing arguments err
	if (msg.getArgs()[0] == "TOPIC" || msg.getArgs()[0].empty())
	{
		response = ":" + usr.getIp() + " 461 " + usr.getNickname()
				+ " TOPIC :Not enough parameters\r\n";
		send(usr.getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
					<< "(" << usr.getIp() << ") >> " << response;
		return;
	}
	chn = search_channel(&_channels, &msg);
	// Channel not found
	if (chn == NULL)
	{
		// 403 ERR_NOSUCHCHANNEL
		response = ":" + usr.getIp() + " 403 " + usr.getNickname()
				+ " " + msg.getArgs()[0] + " :No such channel\r\n";
		send(usr.getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
					<< "(" << usr.getIp() << ") >> " << response;
		return ;
	}
	// User not in channel
	bool user_in_channel = false;
	for (std::vector<User>::iterator it = _channels[msg.getArgs()[0]].getUsers().begin();
		it != _channels[msg.getArgs()[0]].getUsers().end(); it++)
		if (it->getNickname() == usr.getNickname())
			user_in_channel = true;
	// 442 ERR_NOTONCHANNEL
	if (!user_in_channel)
	{
		response = ":" + usr.getIp() + " 442 " + usr.getNickname()
				+ " " + msg.getArgs(0) + " :You're not on that channel\r\n";
		send(usr.getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
					<< "(" << usr.getIp() << ") >> " << response;
		return ;
	}

	// Display topic in terminal
	if (msg.getArgs().size() == 1 && msg.getMessageText().empty())
	{
		if (_channels[msg.getArgs()[0]].getTopic().empty())
		{
			response = ":" + usr.getIp() + " 331 " + usr.getNickname()
					+ " " + msg.getArgs(0) + " :No topic is set\r\n";
			send(usr.getFd(), response.c_str(), response.size(), 0);
			std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
						<< "(" << usr.getIp() << ") >> " << response;
		}
		else
		{
			response = ":" + usr.getIp() + " 332 " + usr.getNickname()
					+ " " + msg.getArgs(0) + " :" + _channels[msg.getArgs()[0]].getTopic() + "\r\n";
			send(usr.getFd(), response.c_str(), response.size(), 0);
			std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
						<< "(" << usr.getIp() << ") >> " << response;
		}
		return;
	}
	// Change topic if t flag isnt set. (If t flag is set, user must be a OP)
	if (_channels[msg.getArgs()[0]].getModes().find("t") == std::string::npos ||
		(_channels[msg.getArgs()[0]].getModes().find("t") != std::string::npos &&
			usr.getNickname() == _channels[msg.getArgs()[0]].getOp().getNickname()))
	{
		std::vector<User> ch_users = _channels[msg.getArgs()[0]].getUsers();
		std::string new_topic = "";
		if (msg.getMessageText().empty())
			new_topic = msg.getArgs()[1];
		else
			new_topic = msg.getMessageText();
		_channels[msg.getArgs()[0]].setTopic(new_topic);
		response = ":" + usr.getIp() + " 332 " + usr.getNickname()
				+ " " + msg.getArgs(0) + " :" + new_topic + "\r\n";
		for (std::vector<User>::iterator it = ch_users.begin(); it != ch_users.end(); it++)
		{
			send(it->getFd(), response.c_str(), response.size(), 0);
			std::cout	<< "[ SERVER ] Message sent to client " << it->getFd()
						<< "(" << it->getIp() << ") >> " << response;
		}
		return;
	}
	else
	{
		// 482 ERR_CHANOPRIVSNEEDED
		response = ":" + usr.getIp() + " 482 " + usr.getNickname()
				+ " " + msg.getArgs(0) + " :You're not channel operator\r\n";
		send(usr.getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
					<< "(" << usr.getIp() << ") >> " << response;
		return ;
	}
}
