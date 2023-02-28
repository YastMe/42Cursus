/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:35:53 by abeltran          #+#    #+#             */
/*   Updated: 2023/01/27 18:45:21 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/**
 * @brief Reads a string from a fd until the end of the 
 * 		  line and/or until BUFFER_SIZE.
 * 
 * @param fd 
 * @param str 
 * @return char* 
 */
char	*ft_readstr(int fd, char *str);

/**
 * @brief Gets the next line from the given file descriptor.
 * 
 * @param fd 
 * @return char* 
 */
char	*get_next_line(int fd);

/**
 * @brief Len of a str.
 * 
 * @param str 
 * @return size_t 
 */
size_t	ft_strlen(char *str);

/**
 * @brief Searches a char inside a str.
 * 
 * @param str 
 * @param c 
 * @return char* 
 */
char	*ft_strchr(char *str, char c);

/**
 * @brief Reallocates memory for a string that
 * 		  combines the two parameters.
 * 
 * @param full_str 
 * @param buff 
 * @return char* 
 */
char	*ft_strjoin(char *full_str, char *buff);

/**
 * @brief Returns the string up until the end of the line.
 * 
 * @param str 
 * @return char* 
 */
char	*ft_getline(char *str);

/**
 * @brief Returns the string after the end of the line.
 * 
 * @param str 
 * @return char* 
 */
char	*ft_getremain(char *str);

#endif
