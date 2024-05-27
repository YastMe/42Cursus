/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   50_cmdPing.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:52:31 by jzaragoz          #+#    #+#             */
/*   Updated: 2024/05/03 08:57:03 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IRCServer.hpp"

void	IRCServer::_cmdPing(User &usr, Message &msg)
{
	std::string	response;
	// 461 ERR_NEEDMOREPARAMS
	if (msg.getArgs()[0] == "PING")
	{
		response = ":" + usr.getIp() + " 461 " + usr.getNickname()
				+ " PING :Not enough parameters\r\n";
		send(usr.getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
					<< "(" << usr.getIp() << ") >> " << response;
		return ;
	}

	// Build and send response to Pinger to keep connection alive.
	response = ":" + usr.getNickname() + "!" + usr.getUsername() + "@" + usr.getIp()
			   + " PONG " + msg.getArgs()[0] + "\r\n";
	send(usr.getFd(), response.c_str(), response.size(), 0);
	std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
				 << "(" << usr.getIp() << ") >> " << response;
}
