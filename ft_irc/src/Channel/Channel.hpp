/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:59:42 by fragarci          #+#    #+#             */
/*   Updated: 2024/04/28 12:28:20 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include "../User/User.hpp"
# include <string>
# include <vector>

class Channel
{
	private:
		std::string			_name;
		std::string			_passwd;
		std::vector<User>	_users;
		std::vector<User>	_invite;
		User				_op;
		std::string			_topic;
		int					_max_users;
		std::string			_modes;
	public:
		Channel(void);
		Channel(std::string name, User &op);
		Channel(const Channel &src);
		~Channel(void);
		Channel &operator=(const Channel &src);

// Getters

		std::string			getName(void) const;
		std::string			getPasswd(void) const;
		std::vector<User>	&getUsers(void);
		std::vector<User>	&getInvite(void);
		User				getOp(void) const;
		std::string			getTopic(void) const;
		int					getMaxUsers(void) const;
		std::string			getModes(void) const;

// Setters

		void	setName(std::string name);
		void	setPasswd(std::string passwd);
		void	setOp(User &op);
		void	setTopic(std::string topic);
		void	setMaxUsers(int max_users);
		void	setModes(std::string modes);
};

#endif
