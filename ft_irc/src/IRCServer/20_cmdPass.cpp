/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   20_cmdPass.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:10:31 by fragarci          #+#    #+#             */
/*   Updated: 2024/04/26 10:57:16 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IRCServer.hpp"

void	IRCServer::_cmdPass(User &usr, std::vector<std::string> args)
{
	std::string response = "";

	if (args.size() != 1 || args[0] == "PASS")
		response = ":" + usr.getIp() + " 461 PASS :Not enough parameters\r\n";
	else if (args[0] != this->_passwd)
		response = ":" + usr.getIp() + " 464 :Password incorrect\r\n";
	else if (usr.getPasswd())
		response = ":" + usr.getIp() + " 462 :You may not reregister\r\n";

	if (!response.empty())
	{
		send(usr.getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
					<< "(" << usr.getIp() << ") >> " << response;
	}
	else
		usr.setPasswd(true);

}
