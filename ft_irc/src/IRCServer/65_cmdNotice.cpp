/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   65_cmdNotice.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:29:31 by fragarci          #+#    #+#             */
/*   Updated: 2024/05/06 12:36:33 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IRCServer.hpp"

void IRCServer::_cmdNotice(User &usr, Message &msg)
{
	std::string	response = "";
	if (msg.getArgs()[0] == "NOTICE")
		return ;// 411 ERR_NORECIPIENT
	if (msg.getArgs().size() == 1 && msg.getMessageText().empty())
		return ;// 412 ERR_NOTEXTTOSEND
	// PRIVMSG response
	response = ":" + usr.getNickname() + "!" + usr.getUsername() + "@" + usr.getIp()
			+ " NOTICE " + msg.getArgs()[0];
	if (!msg.getMessageText().empty())
		response += " :" + msg.getMessageText();
	else
		response += " " + msg.getArgs()[1];
	response += "\r\n";
	bool found = false;
	if (msg.getArgs()[0][0] == '#')
	{
		for (std::map<std::string, Channel>::iterator cit = _channels.begin(); cit != _channels.end(); cit++)
		{
			if (cit->first != msg.getArgs()[0])
				continue;
			found = true;
			std::vector<User> ch_users = _channels[msg.getArgs()[0]].getUsers();
			bool user_in_channel = false;
			for (std::vector<User>::iterator uit = ch_users.begin(); uit != ch_users.end(); uit++)
				if (uit->getNickname() == usr.getNickname())
					user_in_channel = true;
			if (!user_in_channel)
			{
				// 404 ERR_CANNOTSENDTOCHAN
				return ;
			}
			for (std::vector<User>::iterator uit = ch_users.begin(); uit != ch_users.end(); uit++)
			{
				if (uit->getNickname() == usr.getNickname())
					continue;
				send(uit->getFd(), response.c_str(), response.size(), 0);
				std::cout	<< "[ SERVER ] Message sent to client " << uit->getFd()
							<< "(" << uit->getIp() << ") >> " << response;
			}
			return ;
		}
		if (!found)
		{
			// 404 ERR_CANNOTSENDTOCHAN
			response = ":" + usr.getIp() + " 404 " + usr.getNickname()
					+ " " + msg.getArgs()[0] + " :Cannot send to channel\r\n";
			send(usr.getFd(), response.c_str(), response.size(), 0);
			std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
						<< "(" << usr.getIp() << ") >> " << response;
			return ;
		}
	}
	else
	{
		bool found = false;
		for (std::map<int, User>::iterator it = _users.begin(); it != _users.end(); it++)
		{
			if (it->second.getNickname() != msg.getArgs()[0])
				continue;
			found = true;
			send(it->second.getFd(), response.c_str(), response.size(), 0);
			std::cout	<< "[ SERVER ] Message sent to client " << it->second.getFd()
						<< "(" << it->second.getIp() << ") >> " << response;
			return ;
		}
		if (!found)
		{
			// 401 ERR_NOSUCHNICK
			return ;
		}
	}
}
