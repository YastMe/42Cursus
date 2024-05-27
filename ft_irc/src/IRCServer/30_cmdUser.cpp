/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   30_cmdUser.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:09:52 by fragarci          #+#    #+#             */
/*   Updated: 2024/04/25 10:32:43 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IRCServer.hpp"

void IRCServer::_cmdUser(User &usr, Message &msg)
{
	std::string	response = "";

	if (usr.getAuth())
		response = ":" + usr.getIp() + " 462 " + usr.getNickname() + ": You may not reregister\r\n";
	else if (msg.getArgs().size() < 3)
		response = ":" + usr.getIp() + " 461 " + usr.getNickname() + " USER: Not enough parameters\r\n";
	else if (!usr.getPasswd() || usr.getNickname().empty())
		return ;
	if (!response.empty())
	{
		send(usr.getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
					<< "(" << usr.getIp() << ") >> " << response;
		return ;
	}
	usr.setUsername(msg.getArgs()[0]);
	if (!msg.getMessageText().empty())
		usr.setRealname(msg.getMessageText());
	else
		usr.setRealname(msg.getArgs()[3]);
	usr.setAuth(true);
	// 001 RPL_WELCOME
	response = ":" + usr.getIp() + " 001 " + usr.getNickname()
			+ " :Welcome to the IRC Network, :"
			+ usr.getNickname() + "!" + usr.getUsername() + "@" + usr.getIp() + "\r\n";
	send(usr.getFd(), response.c_str(), response.size(), 0);
	std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
				<< "(" << usr.getIp() << ") >> " << response;
	// 002 RPL_YOURHOST
	response = ":" + usr.getIp() + " 002 " + usr.getNickname()
			+ " :Your host is ft_irc, running version 1.0\r\n";
	send(usr.getFd(), response.c_str(), response.size(), 0);
	std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
				<< "(" << usr.getIp() << ") >> " << response;
	// 003 RPL_CREATED
	response = ":" + usr.getIp() + " 003 " + usr.getNickname()
			+ " :This server was created 06-09-6969 00:00:00\r\n";
	send(usr.getFd(), response.c_str(), response.size(), 0);
	std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
				<< "(" << usr.getIp() << ") >> " << response;
	// 004 RPL_MYINFO
	response = ":" + usr.getIp() + " 004 " + usr.getNickname()
			+ " localhost 1.0 io kost k\r\n";
	send(usr.getFd(), response.c_str(), response.size(), 0);
	std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
				<< "(" << usr.getIp() << ") >> " << response;
	// 005 RPL_ISUPPORT
	response = ":" + usr.getIp() + " 005 " + usr.getNickname()
			+ " CHANNELLEN=32 NICKLEN=32 TOPICLEN=255 :are supported by this server\r\n";
	send(usr.getFd(), response.c_str(), response.size(), 0);
	std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
				<< "(" << usr.getIp() << ") >> " << response;
	// 375 RPL_MOTDSTART
	response = ":" + usr.getIp() + " 375 " + usr.getNickname()
			+ " :- ft_irc Message of the day - \r\n";
	send(usr.getFd(), response.c_str(), response.size(), 0);
	std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
				<< "(" << usr.getIp() << ") >> " << response;
	// 372 RPL_MOTD
	response = ":" + usr.getIp() + " 372 " + usr.getNickname()
			+ " :Message of the day\r\n";
	send(usr.getFd(), response.c_str(), response.size(), 0);
	std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
				<< "(" << usr.getIp() << ") >> " << response;
	// 376 RPL_ENDOFMOTD
	response = ":" + usr.getIp() + " 376 " + usr.getNickname()
			+ " :End of /MOTD command.\r\n";
	send(usr.getFd(), response.c_str(), response.size(), 0);
	std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
				<< "(" << usr.getIp() << ") >> " << response;
}
