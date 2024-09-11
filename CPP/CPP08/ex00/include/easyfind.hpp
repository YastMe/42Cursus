/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:04:39 by abeltran          #+#    #+#             */
/*   Updated: 2024/08/15 11:05:39 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <algorithm>

template <typename T>
bool easyfind(T &cont, int n)
{
	return (std::find(cont.begin(), cont.end(), n) != cont.end());
}