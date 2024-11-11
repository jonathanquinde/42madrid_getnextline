/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:37:48 by jquinde-          #+#    #+#             */
/*   Updated: 2024/11/11 13:47:55 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	put_str(char *str);

int main(void)
{
	int fd;
	char *line;

	fd = open("hola.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		put_str(line);
		free (line);
		line = get_next_line(fd);
	}
	put_str(line);
	close (fd);
}

void	put_str(char *str)
{
	if (str == NULL)
	{
		write(1, "---null\n", 8);
		return ;
	}
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}