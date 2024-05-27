/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:42:33 by abeltran          #+#    #+#             */
/*   Updated: 2024/04/25 10:43:21 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_HPP
# define MESSAGE_HPP

# include <iostream>
# include <vector>

class Message
{
	private:
		std::string					_baseMessage;
		std::string					_messageText;
		std::vector<std::string>	_args;
		std::string					_cmd;

	public:
		// Constructors and destructors
		Message(std::string msg);
		Message(const Message &message);
		~Message();

		// Operator overloads
		Message & operator = (const Message &message);

		/**
		 * @brief Parses the message object into its components:
		 * - Command
		 * - Arguments
		 * - Message text
		 * 
		 * A message is structured as follows:
		 * [command] [args (0..n)] :[message]\r\n
		 * 
		 * The command is the first word in the message.
		 * The arguments are the words between the command and the colon.
		 * The message text is the text after the colon.
		 * 
		 * A command is always present, but arguments and message text may not be.
		 * 
		 * Example:
		 * PRIVMSG #channel :Hello, world!\r\n
		 * - Command: PRIVMSG
		 * - Arguments: #channel
		 * - Message text: Hello, world!
		 * 
		 * Example:
		 * JOIN #channel\r\n
		 * - Command: JOIN
		 * - Arguments: #channel
		 * - Message text: ""
		 * 
		 * Messages *must* end with \r\n. If the message does not end with \r\n, it is considered invalid and will not be parsed.
		 * There may be more than one message in the buffer, so the message is not fully cleared after parsing.
		 * Instead, the message is cleared up to the first \r\n. If the \r\n is the last character in the message,
		 * the message is cleared entirely.
		 * 
		 * Allows easy access to the command, arguments, and message text for execution.
		*/
		void						parse(void);

		/**
		 * @brief Checks if the message is valid.
		 * A message is considered valid if it contains \r\n, considered as its terminator.
		 * 
		 * @return true / false
		*/
		bool						isValid(void);

		/**
		 * @brief Clears the message object.
		 * 
		 * The message object is cleared by removing the base message up to the first \r\n.
		 * If the \r\n is the last character in the message, the message is cleared entirely.
		 * 
		 * The command and arguments are also cleared for the next message.
		*/
		void						clear(void);

		// Getters
		/**
		 * @brief Returns the base message without parsing
		 * 
		 * @return std::string 
		*/
		std::string					getMessage(void);

		/**
		 * @brief Returns the arguments of the command.
		 * @brief Overloaded to return the arguments at index i.
		 * 
		 * @return std::vector<std::string> 
		*/
		std::vector<std::string>	getArgs(void);
		std::string					getArgs(int i);

		/**
		 * @brief Returns the command itself
		 * 
		 * @return std::string 
		*/
		std::string					getCmd(void);

		/**
		 * @brief Returns the text part of the message
		 * 
		 * @return std::string 
		*/
		std::string					getMessageText(void);
};

std::ostream & operator << (std::ostream &out, const Message &message);

#endif