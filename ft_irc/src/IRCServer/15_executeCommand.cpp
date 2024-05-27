/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15_executeCommand.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:13:12 by fragarci          #+#    #+#             */
/*   Updated: 2024/05/15 10:53:31 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IRCServer.hpp"

void IRCServer::_executeCommand(User &usr, Message &msg)
{
	bool	auth = usr.getAuth();
	std::cout	<< "[ CLIENT ] Message received from client " << usr.getFd()
				<< "(" << usr.getIp() << ")" << " << " << msg.getCmd();
	for (std::size_t i = 0; i < msg.getArgs().size(); i++)
		std::cout << " " << msg.getArgs()[i];
	if (!msg.getMessageText().empty())
		std::cout << " :" << msg.getMessageText();
	std::cout << std::endl;
	if (msg.getCmd() == "PASS")
		this->_cmdPass(usr, msg.getArgs());
	else if (msg.getCmd() == "NICK")
		this->_cmdNick(usr, msg.getArgs());
	else if (msg.getCmd() == "USER")
		this->_cmdUser(usr, msg);
	else if (!auth)
		std::cout << "Client " << usr.getFd() << " not authenticated. Ignored." << std::endl;
	else if (msg.getCmd() == "JOIN")
		this->_cmdJoin(usr, msg);
	else if (msg.getCmd() == "QUIT")
		this->_cmdQuit(usr, msg);
	else if (msg.getCmd() == "PRIVMSG")
		this->_cmdPrivmsg(usr, msg);
	else if (msg.getCmd() == "PING")
		this->_cmdPing(usr, msg);
	else if (msg.getCmd() == "PART")
		this->_cmdPart(usr, msg);
	else if (msg.getCmd() == "KICK")
		this->_cmdKick(usr, msg);
	else if (msg.getCmd() == "NOTICE")
		this->_cmdNotice(usr, msg);
	else if (msg.getCmd() == "MODE")
		this->_cmdMode(usr, msg);
	else if (msg.getCmd() == "TOPIC")
		this->_cmdTopic(usr, msg);
	else if (msg.getCmd() == "INVITE")
		this->_cmdInvite(usr, msg);
	else
		std::cout << "Command " << msg.getCmd() << " not supported" << std::endl;
	std::cout << std::endl;
}
