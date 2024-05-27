/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_initServer.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:41:25 by fragarci          #+#    #+#             */
/*   Updated: 2024/05/15 10:24:02 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IRCServer.hpp"

void	IRCServer::_initServer(void)
{
	struct pollfd	servpoll;

	signal(SIGPIPE, SIG_IGN);
	// Create Server Socket
	this->_server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (this->_server_fd == -1)
		return (std::perror("socket"), std::exit(EXIT_FAILURE));

	// Set Socket to Non Blocking Mode
	if (fcntl(this->_server_fd, F_SETFL, O_NONBLOCK) == -1)
		return (std::perror("fcntl"), std::exit(EXIT_FAILURE));

	// Fill sockaddr_in struct
	this->_server_addr.sin_family = AF_INET;
	this->_server_addr.sin_port = htons(this->_port);
	this->_server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	// Bind Socket
	if (bind(this->_server_fd, (struct sockaddr *)&this->_server_addr,
		sizeof(this->_server_addr)) == -1)
		return (std::perror("bind"), std::exit(EXIT_FAILURE));

	// Listen for connections
	if (listen(this->_server_fd, 5) == -1)
		return (std::perror("listen"), std::exit(EXIT_FAILURE));

	// Fill pollfd struct and push it into pollfds vector
	servpoll.fd = this->_server_fd;
	servpoll.events = POLLIN;
	_pollfds.push_back(servpoll);
	std::cout << "IRC Server started on port " << this->_port << std::endl;
}
