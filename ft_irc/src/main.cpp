/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:51:53 by fragarci          #+#    #+#             */
/*   Updated: 2024/03/01 10:47:21 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "IRCServer/IRCServer.hpp"

static bool check_args(char **argv) { return (atoi(argv[1]) > 0); }

int	main(int argc, char **argv)
{
	if (argc != 3 || !check_args(argv))
		return (std::cerr << "Usage: " << argv[0] << " <port> <password>" << std::endl, 1);

	IRCServer	server(atoi(argv[1]), argv[2]);
	server.start();
	return (0);
}
