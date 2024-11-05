/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:05:23 by jquinde-          #+#    #+#             */
/*   Updated: 2024/10/14 13:05:23 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H 
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define READ_ERROR 1
# define READ_SUCCESS 2

char	*get_next_line(int fd);
int		is_newline(char *read_buffer, size_t len);
void	ft_strncpy(char *dest, char *src, size_t n);
size_t	ft_strlen(const char *str);
char	*empty_byte(void);
#endif