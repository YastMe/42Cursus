/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   99_mainLoop.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:50:29 by fragarci          #+#    #+#             */
/*   Updated: 2024/05/15 10:18:46 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IRCServer.hpp"
#include "../Message/Message.hpp"


void	IRCServer::_mainLoop(void)
{
	int	more_cmd;

	while (1)
	{
		// Read data from all clients
		this->_readFDs();
		// ↓↓↓ Execute commands ↓↓↓
		do
		{
			more_cmd = 0;
			for (std::map<int, User>::iterator it = _users.begin(); it != _users.end(); it++)
			{
				Message msg = Message(it->second.getMsg());
				if (!msg.isValid())
					continue;
				// Parse the message
				msg.parse();

				// Execute the command
				this->_executeCommand(it->second, msg);

				// Clear the message object and the user's message for the next iteration
				msg.clear();
				it->second.setMessage(msg.getMessage());
				more_cmd++;
			}
			// If someone left the server, remove them.
			while (!_usr_delete.empty())
			{
				_users.erase(_usr_delete.top());
				_usr_delete.pop();
			}
		} while (more_cmd > 0);
	}
}
