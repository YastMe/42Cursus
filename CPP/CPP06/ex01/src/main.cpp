/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:13:11 by abeltran          #+#    #+#             */
/*   Updated: 2024/07/22 13:17:16 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"
#include <iostream>

int	main(void)
{
    Data data;
    uintptr_t serialized;
    Data *deserialized;

    data.str_member = "Hola buenas tardes";
    data.int_member = 413;

    std::cout << "Original: " << &data << std::endl;
    std::cout << "str_member: " << data.str_member << std::endl;
    std::cout << "int_member: " << data.int_member << std::endl;

    serialized = Serializer::serialize(&data);
    std::cout << "Serialized: " << serialized << std::endl;
    std::cout << "str_member: " << data.str_member << std::endl;
    std::cout << "int_member: " << data.int_member << std::endl;

    deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized: " << deserialized << std::endl;
    std::cout << "str_member: " << deserialized->str_member << std::endl;
    std::cout << "int_member: " << deserialized->int_member << std::endl;
}
