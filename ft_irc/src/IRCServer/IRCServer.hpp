/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IRCServer.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:52:58 by fragarci          #+#    #+#             */
/*   Updated: 2024/05/15 00:35:57 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRCSERVER_HPP
# define IRCSERVER_HPP

# include "../Message/Message.hpp"
# include "../Channel/Channel.hpp"
# include "../User/User.hpp"

# define _BSD_SOURCE
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>
# include <fcntl.h>
# include <poll.h>

# include <iostream>
# include <cstdlib>
# include <vector>
# include <string>
# include <stack>
# include <map>

class IRCServer
{
	private:
		const int						_port;
		const std::string				_passwd;
		int								_server_fd;
		struct	sockaddr_in				_server_addr;
		std::vector<struct pollfd>		_pollfds;
		std::map<int, User>				_users;
		std::map<std::string, Channel>	_channels;
		std::stack<int>				_usr_delete;

		void	_initServer(void);
		void	_acceptConnection(void);
		void	_readFDs(void);
		void	_executeCommand(User &usr, Message &msg);
		void	_cmdPass(User &usr, std::vector<std::string> args);
		void	_cmdNick(User &usr, std::vector<std::string> args);
		void	_cmdUser(User &usr, Message &msg);
		void	_cmdJoin(User &usr, Message &msg);
		void	_cmdQuit(User &usr, Message &msg);
		void	_cmdPrivmsg(User &usr, Message &msg);
		void	_cmdPing(User &usr, Message &msg);
		void	_cmdPart(User &usr, Message &msg);
		void	_cmdKick(User &usr, Message &msg);
		void	_cmdNotice(User &usr, Message &msg);
		void	_cmdMode(User &usr, Message &msg);
		void	_cmdTopic(User &usr, Message &msg);
		void	_cmdInvite(User &usr, Message &msg);
		void	_mainLoop(void);

	public:
		IRCServer(void);
		IRCServer(const IRCServer &src);
		IRCServer(int port, std::string passwd);
		~IRCServer(void);
		IRCServer &operator=(const IRCServer &src);
		void	start(void);
};

#endif
