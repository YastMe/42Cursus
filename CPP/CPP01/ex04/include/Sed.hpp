/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:06:55 by abeltran          #+#    #+#             */
/*   Updated: 2023/08/11 14:12:30 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>

# define RED "\033[0;31m"
# define DEFAULT "\033[;0m"

class Sed
{
public:
    Sed(std::string filename);
    ~Sed();
    void    replace(std::string s1, std::string s2);
private:
    std::string _filename;
};

#endif