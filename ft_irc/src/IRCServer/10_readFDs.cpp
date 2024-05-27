/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_readFDs.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:38:45 by fragarci          #+#    #+#             */
/*   Updated: 2024/05/13 11:16:40 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IRCServer.hpp"

void	IRCServer::_readFDs(void)
{
	char	buff[512];
	int		buff_size;

	// Listen for incoming data from all the FDs.
	if (poll(&_pollfds[0], _pollfds.size(), -1) <= 0)
		return;

	// First pollfd is allways the server, if there's something to reead from
	// the server, accept a new connection.
	if (_pollfds[0].revents & POLLIN)
		this->_acceptConnection();

	// Loop through all the FDs chicking for avaible reading operations.
	for (std::size_t i = 1; i < _pollfds.size(); i++)
	{
		// If there is nothing to read, continue.
		if (!(_pollfds[i].revents & POLLIN))
			continue;

		// Clear reading buffer and save new data.
		bzero(buff, 512);
		buff_size = recv(_pollfds[i].fd, buff, 511, 0);

		// If size of data recived is zero, connection is closed.
		if (buff_size <= 0)
		{
			Message quit = Message("QUIT\r\n");
			quit.parse();
			_cmdQuit(_users[_pollfds[i].fd], quit);
			continue;
		}

		// Append incoming data to user msg string
		_users[_pollfds[i].fd].setMsg(_users[_pollfds[i].fd].getMsg() + buff);
	}
}
