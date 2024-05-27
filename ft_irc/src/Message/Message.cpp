/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:42:38 by abeltran          #+#    #+#             */
/*   Updated: 2024/04/25 10:55:07 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

/**
 * Constructors and destructors
 */

Message::Message(std::string msg) : _baseMessage(msg) {}

Message::Message(const Message &message) : _baseMessage(message._baseMessage) {}

Message::~Message() {}

Message & Message::operator = (const Message &message) {
	if (this == &message)
		return (*this);
	_baseMessage = message._baseMessage;
	return (*this);
}

/**
 * Operator overloads
 */

std::ostream &operator<<(std::ostream &out, const Message &message)
{
	(void)message;
	out << "Message [" << "" << "]";
	return (out);
}
/**
 * Member functions 
 */

bool	Message::isValid(void)
{
	if (_baseMessage.find("\r\n") != std::string::npos)
		return (true);
	return (false);
}

void	Message::clear(void)
{
	unsigned long	pos;

	if (isValid())
	{
		pos = _baseMessage.find("\r\n");
		
		if (pos == std::string::npos)
			return ;
		else if (pos == _baseMessage.length() - 2)
			_baseMessage = "";
		else
			_baseMessage = _baseMessage.substr(pos + 2, _baseMessage.length());
			
		_cmd = "";
		_args.clear();
	}
}

void	Message::parse(void)
{
	int		pos;
	std::string	tmp;

	if (!isValid())
		return ;
	
	pos = _baseMessage.find("\r\n");
	tmp = _baseMessage.substr(0, pos);
	_cmd = tmp.substr(0, tmp.find(" "));
	tmp = tmp.substr(tmp.find(" ") + 1, tmp.length());
	while (tmp.find(" ") != std::string::npos && tmp.find(" ") < tmp.find(":"))
	{
		_args.push_back(tmp.substr(0, tmp.find(" ")));
		tmp = tmp.substr(tmp.find(" ") + 1, tmp.length());
	}
	if (tmp.find(" ") == std::string::npos)
	{
		_args.push_back(tmp.substr(0, tmp.length()));
		tmp = tmp.substr(0, tmp.length());
	}
	if (tmp.find(":") != std::string::npos)
		_messageText = tmp.substr(tmp.find(":") + 1, tmp.length());
	else
		_messageText = "";
}

/**
 * Getters
 */

std::vector<std::string>	Message::getArgs(void)
{
	return (_args);
}

std::string	Message::getArgs(int i)
{
	if (i < 0 || i >= (int)_args.size())
		return ("");
	return (_args[i]);
}

std::string	Message::getCmd(void)
{
	return (_cmd);
}

std::string	Message::getMessageText(void)
{
	return (_messageText);
}

std::string	Message::getMessage(void)
{
	return (_baseMessage);
}
