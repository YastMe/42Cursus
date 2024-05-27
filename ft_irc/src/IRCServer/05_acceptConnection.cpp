/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_acceptConnection.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:42:26 by fragarci          #+#    #+#             */
/*   Updated: 2024/04/24 13:19:52 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IRCServer.hpp"

void	IRCServer::_acceptConnection(void)
{
	struct sockaddr_in	cliaddr;
	struct pollfd		clipoll;
	socklen_t			addrlen;
	User				new_user;
	int 				clifd;

	// Accept incoming connection
	addrlen = sizeof(cliaddr);
	clifd = accept(this->_server_fd, (struct sockaddr *)&cliaddr, &addrlen);
	if (clifd == -1)
		return (std::perror("accept"), (void)0);

	// Set incoming connection's fd to Non Blocking Mode
	if (fcntl(clifd, F_SETFL, O_NONBLOCK) == -1)
		return (std::perror("fcntl"), (void)0);

	// Fill pollfd struct and push it to pollfds vector
	clipoll.fd = clifd;
	clipoll.events = POLLIN;
	this->_pollfds.push_back(clipoll);

	// Create new User and add it to the users Map
	new_user = User(clipoll.fd);
	new_user.setIp(inet_ntoa((in_addr)cliaddr.sin_addr));
	this->_users[new_user.getFd()] = new_user;
	std::cout << "new connection stablished" << std::endl;
}
