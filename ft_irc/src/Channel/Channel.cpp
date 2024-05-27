/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:12:46 by fragarci          #+#    #+#             */
/*   Updated: 2024/04/28 12:29:19 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"

Channel::Channel(void): _name(""), _passwd(""), _topic(""),_max_users(0), _modes("") {}
Channel::Channel(std::string name, User &op): _name(name), _passwd(""), _op(op), _topic(""), _max_users(0), _modes("") {}
Channel::Channel(const Channel &src) { *this = src; }
Channel::~Channel(void) {}

Channel &Channel::operator=(const Channel &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_passwd = src._passwd;
		this->_users = src._users;
		this->_op = src._op;
		this->_topic = src._topic;
		this->_max_users = src._max_users;
	}
	return (*this);
}


// Getters

std::string	Channel::getName(void) const { return (this->_name); }
std::string	Channel::getPasswd(void) const { return (this->_passwd); }
std::vector<User>	&Channel::getUsers(void) { return (this->_users); }
std::vector<User>	&Channel::getInvite(void) { return (this->_invite); }
User Channel::getOp(void) const { return (this->_op); }
std::string Channel::getTopic(void) const { return (this->_topic); }
int	Channel::getMaxUsers(void) const { return (this->_max_users); }
std::string Channel::getModes(void) const { return (this->_modes); }

// Setters

void	Channel::setName(std::string name) { this->_name = name; }
void	Channel::setPasswd(std::string passwd) { this->_passwd = passwd; }
void	Channel::setOp(User &op) { this->_op = op; }
void	Channel::setTopic(std::string topic) { this->_topic = topic; }
void	Channel::setMaxUsers(int max_users) { this->_max_users = max_users; }
void	Channel::setModes(std::string modes) { this->_modes = modes; }
