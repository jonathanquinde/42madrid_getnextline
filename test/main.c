/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:37:48 by jquinde-          #+#    #+#             */
/*   Updated: 2024/11/12 13:28:48 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define MAX_MALLOCS 10

void	put_str(char *str);

/*
int main(void)
{
	int fd;
	char *line;

	malloc_to_fail = 1;
	while (malloc_to_fail <= MAX_MALLOCS)
	{
		num_allocs = 0;
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
		malloc_to_fail++;
	}
}
*/

/*
int main(void)
{
	int		fd;
	char	*line;

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
*/

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

//13 malloc ; 0 + 1 +2 +3 +4 +5 +6 +7 +8 + 9 + 10 +11 +12 = 78
//7 malloc ; 0 + 1 +2 +3 +4 +5 + 6 = 28 
//10 mallocs ; 0 + 1 +2 +3 +4 +5 +6 +7 +8 + 9 = 45