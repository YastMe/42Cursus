/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   40_cmdQuit.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:14:51 by fragarci          #+#    #+#             */
/*   Updated: 2024/05/13 11:37:13 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IRCServer.hpp"

void	IRCServer::_cmdQuit(User &usr, Message &msg)
{
	std::string	response;
	std::vector<std::string> cnames;

	// Build response and send to the user
	response = ":" + usr.getNickname() + "!" + usr.getUsername() + "@" + usr.getIp()
			+ " QUIT :Quit:";
	if (msg.getArgs().size() == 1 && msg.getArgs()[0] != "QUIT")
		response += msg.getArgs()[0];
	else if (!msg.getMessageText().empty())
		response += msg.getMessageText();
	response += "\r\n";
	//send(usr.getFd(), response.c_str(), response.size(), 0);
	//std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
	//			<< "(" << usr.getIp() << ") >> " << response;
	std::cout << usr.getNickname() << " Left" << std::endl;
	// Iterate over every channel
	for (std::map<std::string, Channel>::iterator cit = _channels.begin(); cit != _channels.end(); cit++)
	{
		// Search if the user is in the channel
		std::vector<User>::iterator index = cit->second.getUsers().end();
		for (std::vector<User>::iterator uit = cit->second.getUsers().begin(); uit != cit->second.getUsers().end(); uit++)
			if (uit->getNickname() == usr.getNickname())
				index = uit;
		// If true, remove the user from the channel
		if (index == cit->second.getUsers().end())
			continue;
		cit->second.getUsers().erase(index);
		if (cit->second.getUsers().empty())
		{
			cnames.push_back(cit->first);
			continue;
		}
		// Notify all the users on the channel
		for (std::vector<User>::iterator uit = cit->second.getUsers().begin(); uit != cit->second.getUsers().end(); uit++)
		{
			send(uit->getFd(), response.c_str(), response.size(), 0);
			std::cout	<< "[ SERVER ] Message sent to client " << uit->getFd()
						<< "(" << uit->getIp() << ") >> " << response;
		}
	}
	// Close connection, delete _pollfd and delete user.
	std::vector<struct pollfd>::iterator poll_erase = _pollfds.end();
	for (std::vector<struct pollfd>::iterator it = _pollfds.begin(); it != _pollfds.end(); it++)
		if (it->fd == usr.getFd())
			poll_erase = it;
	_pollfds.erase(poll_erase);
	close(usr.getFd());
	_usr_delete.push(usr.getFd());
	if (cnames.empty())
		return ;
	// Delete empty channels
	for (std::vector<std::string>::iterator it = cnames.begin(); it != cnames.end(); it++)
		_channels.erase(it->c_str());
}
