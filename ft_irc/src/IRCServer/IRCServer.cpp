/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IRCServer.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:58:35 by fragarci          #+#    #+#             */
/*   Updated: 2024/04/26 11:31:56 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IRCServer.hpp"

IRCServer::IRCServer(void): _port(6667), _passwd("passwd") { return ; }
IRCServer::IRCServer(const IRCServer &src): _port(src._port), _passwd(src._passwd) { *this = src; }
IRCServer::IRCServer(int port, std::string passwd): _port(port), _passwd(passwd) { return; }
IRCServer::~IRCServer(void) { return ; }

IRCServer &IRCServer::operator=(const IRCServer &src)
{
	if (this != &src)
	{
		this->_server_fd = src._server_fd;
		this->_server_addr = src._server_addr;
		this->_pollfds = src._pollfds;
		this->_users = src._users;
		this->_channels = src._channels;
	}
	return (*this);
}

void	IRCServer::start(void)
{
	this->_initServer();
	this->_mainLoop();
}
