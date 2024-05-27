/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   25_cmdNick.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:16:31 by fragarci          #+#    #+#             */
/*   Updated: 2024/04/26 10:55:15 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IRCServer.hpp"

void	IRCServer::_cmdNick(User &usr, std::vector<std::string> args)
{
	std::string	response = "";

	if (args.size() != 1 || args[0] == "NICK")
		response = ":" + usr.getIp() + " 431 :No nickname given\r\n";
	if (response.empty())
		for (std::map<int, User>::iterator it = _users.begin(); it != _users.end(); it++)
			if (it->second.getNickname() == args[0])
				response = ":" + usr.getIp() + " 433 " + args[0] + " :Nickname is already in use";
	if (response.empty())
	{
		usr.setNickname(args[0]);
		response = ":" + usr.getNickname() + "!@" + usr.getIp() + " NICK " + usr.getNickname() + "\r\n";
	}
	send(usr.getFd(), response.c_str(), response.size(), 0);
	std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
				<< "(" << usr.getIp() << ") >> " << response;
}
