/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   70_cmdMode.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:19:07 by fragarci          #+#    #+#             */
/*   Updated: 2024/05/10 10:49:24 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IRCServer.hpp"
#include <algorithm>

static void removeCharsFromString( std::string &str, std::string charsToRemove )
{
	for ( unsigned int i = 0; i < strlen(charsToRemove.c_str()); ++i )
		str.erase(std::remove(str.begin(), str.end(), charsToRemove[i]), str.end());
}

void	IRCServer::_cmdMode(User &usr, Message &msg)
{
	std::string	response = "";
	// 461 ERR_NEEDMOREPARAMS
	if (msg.getArgs()[0] == "MODE")
	{
		response = ":" + usr.getIp() + " 461 " + usr.getNickname()
				+ " MODE :Not enough parameters\r\n";
		send(usr.getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
					<< "(" << usr.getIp() << ") >> " << response;
		return ;
	}
	// 403 ERR_NOSUCHCHANNEL
	if (_channels.find(msg.getArgs()[0]) == _channels.end())
	{
		response = ":" + usr.getIp() + " 403 " + usr.getNickname()
				+ " " + msg.getArgs()[0] + " :No such channel\r\n";
		send(usr.getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
					<< "(" << usr.getIp() << ") >> " << response;
		return ;
	}
	bool user_in_channel = false;
	for (std::vector<User>::iterator it = _channels[msg.getArgs()[0]].getUsers().begin();
		it != _channels[msg.getArgs()[0]].getUsers().end(); it++)
		if (it->getNickname() == usr.getNickname())
			user_in_channel = true;
	// 442 ERR_NOTONCHANNEL
	if (!user_in_channel)
	{
		response = ":" + usr.getIp() + " 442 " + usr.getNickname()
				+ " " + msg.getArgs(0) + " :You're not on that channel\r\n";
		send(usr.getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
					<< "(" << usr.getIp() << ") >> " << response;
		return ;
	}
	// 324 RPL_CHANNELMODEIS
	if (msg.getArgs().size() == 1 || (msg.getArgs().size() == 2 && msg.getArgs()[1].empty()))
	{
		response = ":" + usr.getIp() + " 324 " + usr.getNickname()
				+ " " + msg.getArgs(0);
		if (!_channels[msg.getArgs()[0]].getModes().empty())
			response += " +" + _channels[msg.getArgs()[0]].getModes();
		response += "\r\n";
		send(usr.getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
					<< "(" << usr.getIp() << ") >> " << response;
		return ;
	}
	// 482 ERR_CHANOPRIVSNEEDED
	if (_channels[msg.getArgs()[0]].getOp().getNickname() != usr.getNickname())
	{
		response = ":" + usr.getIp() + " 482 " + usr.getNickname()
				+ " " + msg.getArgs(0) + " :You're not channel operator\r\n";
		send(usr.getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
					<< "(" << usr.getIp() << ") >> " << response;
		return ;
	}
	// 324 RPL_CHANNELMODEIS
	if (msg.getArgs()[1].size() != 2 || (msg.getArgs()[1][0] != '-' && msg.getArgs()[1][0] != '+'))
	{
		response = ":" + usr.getIp() + " 324 " + usr.getNickname()
				+ " " + msg.getArgs(0);
		if (!_channels[msg.getArgs()[0]].getModes().empty())
			response += " +" + _channels[msg.getArgs()[0]].getModes();
		response += "\r\n";
		send(usr.getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
					<< "(" << usr.getIp() << ") >> " << response;
		return ;
	}
	std::string ch_modes = "";
	switch (msg.getArgs()[1][1])
	{
		case 'i':
			if (msg.getArgs()[1][0] == '-')
			{
				ch_modes = _channels[msg.getArgs()[0]].getModes();
				if (ch_modes.find('i') != std::string::npos)
					removeCharsFromString(ch_modes, "i");
				_channels[msg.getArgs()[0]].setModes(ch_modes);
				response = ":" + usr.getNickname() + "!" + usr.getUsername() + "@" + usr.getIp()
					+ " MODE " + msg.getArgs()[0] + " -i\r\n";
			}
			else
			{
				ch_modes = _channels[msg.getArgs()[0]].getModes();
				if (ch_modes.find('i') == std::string::npos)
					ch_modes += "i";
				_channels[msg.getArgs()[0]].setModes(ch_modes);
				response = ":" + usr.getNickname() + "!" + usr.getUsername() + "@" + usr.getIp()
					+ " MODE " + msg.getArgs()[0] + " +i\r\n";
			}
			break;
		case 't':
			if (msg.getArgs()[1][0] == '-')
			{
				ch_modes = _channels[msg.getArgs()[0]].getModes();
				if (ch_modes.find('t') != std::string::npos)
					removeCharsFromString(ch_modes, "t");
				_channels[msg.getArgs()[0]].setModes(ch_modes);
				response = ":" + usr.getNickname() + "!" + usr.getUsername() + "@" + usr.getIp()
					+ " MODE " + msg.getArgs()[0] + " -t\r\n";
			}
			else
			{
				ch_modes = _channels[msg.getArgs()[0]].getModes();
				if (ch_modes.find('t') == std::string::npos)
					ch_modes += "t";
				_channels[msg.getArgs()[0]].setModes(ch_modes);
				response = ":" + usr.getNickname() + "!" + usr.getUsername() + "@" + usr.getIp()
					+ " MODE " + msg.getArgs()[0] + " +t\r\n";
			}
			break;
		case 'k':
			if (msg.getArgs()[1][0] == '-')
			{
				ch_modes = _channels[msg.getArgs()[0]].getModes();
				if (ch_modes.find('k') != std::string::npos)
					removeCharsFromString(ch_modes, "k");
				_channels[msg.getArgs()[0]].setModes(ch_modes);
				_channels[msg.getArgs()[0]].setPasswd("");
				response = ":" + usr.getNickname() + "!" + usr.getUsername() + "@" + usr.getIp()
					+ " MODE " + msg.getArgs()[0] + " -k\r\n";
			}
			else
			{
				// 461 ERR_NEEDMOREPARAMS
				if (msg.getArgs().size() != 3)
				{
					response = ":" + usr.getIp() + " 461 " + usr.getNickname()
							+ " MODE :Not enough parameters\r\n";
					send(usr.getFd(), response.c_str(), response.size(), 0);
					std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
								<< "(" << usr.getIp() << ") >> " << response;
					return ;
				}
				ch_modes = _channels[msg.getArgs()[0]].getModes();
				if (ch_modes.find('k') == std::string::npos)
					ch_modes += "k";
				_channels[msg.getArgs()[0]].setModes(ch_modes);
				_channels[msg.getArgs()[0]].setPasswd(msg.getArgs()[2]);
				response = ":" + usr.getNickname() + "!" + usr.getUsername() + "@" + usr.getIp()
					+ " MODE " + msg.getArgs()[0] + " +k ###REDACTED###\r\n";
			}
			break;
		case 'o':
			if (msg.getArgs()[1][0] == '-')
			{
				// 324 RPL_CHANNELMODEIS
				response = ":" + usr.getIp() + " 324 " + usr.getNickname()
						+ " " + msg.getArgs(0);
				if (!_channels[msg.getArgs()[0]].getModes().empty())
					response += " +" + _channels[msg.getArgs()[0]].getModes();
				response += "\r\n";
				send(usr.getFd(), response.c_str(), response.size(), 0);
				std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
							<< "(" << usr.getIp() << ") >> " << response;
				return ;
			}
			else
			{
				// 461 ERR_NEEDMOREPARAMS
				if (msg.getArgs().size() != 3)
				{
					response = ":" + usr.getIp() + " 461 " + usr.getNickname()
							+ " MODE :Not enough parameters\r\n";
					send(usr.getFd(), response.c_str(), response.size(), 0);
					std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
								<< "(" << usr.getIp() << ") >> " << response;
					return ;
				}
				bool user_in_channel = false;
				for (std::vector<User>::iterator it = _channels[msg.getArgs()[0]].getUsers().begin();
						it != _channels[msg.getArgs()[0]].getUsers().end(); it++)
					if (it->getNickname() == msg.getArgs()[2])
						user_in_channel = true;
				if (!user_in_channel)
				{
					// 401 ERR_NOSUCHNICK
					response = ":" + usr.getIp() + " 401 " + usr.getNickname()
							+ " " + msg.getArgs()[0] + " :No such nick/channel\r\n";
					send(usr.getFd(), response.c_str(), response.size(), 0);
					std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
								<< "(" << usr.getIp() << ") >> " << response;
					return ;
				}
				int new_op = 0;
				for (std::map<int, User>::iterator it = _users.begin(); it != _users.end(); it++)
					if (it->second.getNickname() == msg.getArgs()[2])
						new_op = it->first;
				if (!new_op)
					return (std::cout << "Something went incredibly wrong!" << std::endl, (void)0);
				std::vector<User> ch_users = _channels[msg.getArgs()[0]].getUsers();
				std::string old_op = _channels[msg.getArgs()[0]].getOp().getNickname();
				_channels[msg.getArgs()[0]].setOp(_users[new_op]);
				for (std::vector<User>::iterator it = ch_users.begin(); it != ch_users.end(); it++)
				{
					response = ":" + usr.getNickname() + "!" + usr.getUsername() + "@" + usr.getIp()
						+ " MODE " + msg.getArgs()[0] + " -o " + old_op + "\r\n";
					send(it->getFd(), response.c_str(), response.size(), 0);
					std::cout	<< "[ SERVER ] Message sent to client " << it->getFd()
								<< "(" << it->getIp() << ") >> " << response;
					response = ":" + usr.getNickname() + "!" + usr.getUsername() + "@" + usr.getIp()
						+ " MODE " + msg.getArgs()[0] + " +o " + msg.getArgs()[2] + "\r\n";
					send(it->getFd(), response.c_str(), response.size(), 0);
					std::cout	<< "[ SERVER ] Message sent to client " << it->getFd()
								<< "(" << it->getIp() << ") >> " << response;
				}
			}
			return;
		case 'l':
			if (msg.getArgs()[1][0] == '-')
			{
				ch_modes = _channels[msg.getArgs()[0]].getModes();
				if (ch_modes.find('l') != std::string::npos)
					removeCharsFromString(ch_modes, "l");
				_channels[msg.getArgs()[0]].setModes(ch_modes);
				_channels[msg.getArgs()[0]].setMaxUsers(0);
				response = ":" + usr.getNickname() + "!" + usr.getUsername() + "@" + usr.getIp()
					+ " MODE " + msg.getArgs()[0] + " -l\r\n";
			}
			else
			{
				// 461 ERR_NEEDMOREPARAMS
				if (msg.getArgs().size() != 3)
				{
					response = ":" + usr.getIp() + " 461 " + usr.getNickname()
							+ " MODE :Not enough parameters\r\n";
					send(usr.getFd(), response.c_str(), response.size(), 0);
					std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
								<< "(" << usr.getIp() << ") >> " << response;
					return ;
				}
				int	max_users = atoi(msg.getArgs()[2].c_str());
				if (max_users < 1)
				{
					ch_modes = _channels[msg.getArgs()[0]].getModes();
					if (ch_modes.find('l') != std::string::npos)
						removeCharsFromString(ch_modes, "l");
					_channels[msg.getArgs()[0]].setModes(ch_modes);
					_channels[msg.getArgs()[0]].setMaxUsers(0);
					response = ":" + usr.getNickname() + "!" + usr.getUsername() + "@" + usr.getIp()
						+ " MODE " + msg.getArgs()[0] + " -l\r\n";
				}
				else
				{
					ch_modes = _channels[msg.getArgs()[0]].getModes();
					if (ch_modes.find('l') == std::string::npos)
						ch_modes += "l";
					_channels[msg.getArgs()[0]].setModes(ch_modes);
					_channels[msg.getArgs()[0]].setMaxUsers(max_users);
					response = ":" + usr.getNickname() + "!" + usr.getUsername() + "@" + usr.getIp()
						+ " MODE " + msg.getArgs()[0] + " +l " + std::to_string(max_users) + "\r\n";
				}
			}
			break;
		default:
			// 324 RPL_CHANNELMODEIS
			response = ":" + usr.getIp() + " 324 " + usr.getNickname()
					+ " " + msg.getArgs(0);
			if (!_channels[msg.getArgs()[0]].getModes().empty())
				response += " +" + _channels[msg.getArgs()[0]].getModes();
			response += "\r\n";
			send(usr.getFd(), response.c_str(), response.size(), 0);
			std::cout	<< "[ SERVER ] Message sent to client " << usr.getFd()
						<< "(" << usr.getIp() << ") >> " << response;
			return ;
	}
	std::vector<User> ch_users = _channels[msg.getArgs()[0]].getUsers();
	for (std::vector<User>::iterator it = ch_users.begin(); it != ch_users.end(); it++)
	{
		send(it->getFd(), response.c_str(), response.size(), 0);
		std::cout	<< "[ SERVER ] Message sent to client " << it->getFd()
					<< "(" << it->getIp() << ") >> " << response;
	}
}
