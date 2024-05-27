/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:08:46 by fragarci          #+#    #+#             */
/*   Updated: 2024/04/25 10:18:52 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "User.hpp"

User::User(void): _passwd(false), _auth(false), _msg("") {};
User::User(int fd): fd(fd), _passwd(false), _auth(false), _msg("") {}
User::User(const User &src) {*this = src;}
User::~User(void) {}

User &User::operator=(const User &src)
{
	if (this != &src)
	{
		this->fd = src.fd;
		this->_nickname = src._nickname;
		this->_username = src._username;
		this->_realname = src._realname;
		this->_passwd = src._passwd;
		this->_auth = src._auth;
		this->_msg = src._msg;
		this->_ip = src._ip;
	}
	return (*this);
}

//Getters

int	User::getFd(void) const { return (this->fd); }
std::string	User::getNickname(void) const { return (this->_nickname); }
std::string	User::getUsername(void) const { return (this->_username); }
std::string	User::getRealname(void) const { return (this->_realname); }
bool User::getPasswd(void) const { return (this->_passwd); }
bool User::getAuth(void) const { return (this->_auth); }
std::string	User::getMsg(void) const { return (this->_msg); }
std::string	User::getIp(void) const { return (this->_ip); }

// Setters

void	User::setNickname(std::string nickname) { this->_nickname = nickname; }
void	User::setUsername(std::string username) { this->_username = username; }
void	User::setRealname(std::string realname) { this->_realname = realname; }
void	User::setPasswd(bool passwd) { this->_passwd = passwd; }
void	User::setAuth(bool auth) { this->_auth = auth; }
void	User::setMsg(std::string msg) { this->_msg = msg; }
void	User::setIp(std::string ip) {this->_ip = ip;}
void	User::setMessage(std::string msg) {this->_msg = msg;}

std::ostream &operator<<(std::ostream &o, const User &src)
{
	o <<
	"{ fd: " << src.getFd() <<
	", nickname: " << src.getNickname() <<
	", username: " << src.getUsername() <<
	", realname: " << src.getRealname() <<
	", auth: " << src.getAuth() <<
	", msg: " << src.getMsg() <<
	", ip: " << src.getIp() << " }";
	return (o);
}
