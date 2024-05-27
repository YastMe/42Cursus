/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:54:08 by fragarci          #+#    #+#             */
/*   Updated: 2024/04/24 14:07:58 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_HPP
# define USER_HPP

# include <poll.h>

# include <iostream>
# include <string>

class User
{
	private:
		int	fd;
		std::string		_nickname;
		std::string		_username;
		std::string		_realname;
		bool			_passwd;
		bool			_auth;
		std::string		_msg;
		std::string		_ip;

	public:
		User(void);
		User(int fd);
		User(const User &src);
		~User(void);
		User &operator=(const User &src);

// Getters

		int	getFd(void) const;
		std::string	getNickname(void) const;
		std::string getUsername(void) const;
		std::string getRealname(void) const;
		bool		getPasswd(void) const;
		bool		getAuth(void) const;
		std::string	getMsg(void) const;
		std::string	getIp(void) const;

// Setters

		void	setNickname(std::string nickname);
		void	setUsername(std::string username);
		void	setRealname(std::string realname);
		void	setPasswd(bool passwd);
		void	setAuth(bool auth);
		void	setMsg(std::string msg);
		void	setIp(std::string ip);
		void	setMessage(std::string msg);
};

std::ostream &operator<<(std::ostream &o, const User &src);

#endif
