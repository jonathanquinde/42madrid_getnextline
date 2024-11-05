/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:56:04 by jquinde-          #+#    #+#             */
/*   Updated: 2024/10/15 12:56:04 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_file(int fd, char	**buffer);
static char	*get_line(char **buffer);
void		trim_read_line(char **buffer, char **result);

char	*get_next_line(int fd)
{
	static char	*buffer;
	int			read_status;
	char		*result;

	if (buffer == NULL)
	{
		buffer = malloc(1);
		if (buffer == NULL)
			return (NULL);
		*buffer = 0;
	}
	read_status = 0;
	if (!(is_newline(buffer, ft_strlen(buffer))))
		read_status = read_file(fd, &buffer);
	if (read_status == 2)
	{
		free (buffer);
		return (buffer = NULL);
	}
	result = get_line(&buffer);
	if (read_status == 1)
		*buffer = 0;
	else
		trim_read_line(&buffer, &result);
	return (result);
}

//0=quedan bytes; 1=ultima linea; 2=error(mallloc, read)
static int	read_file(int fd, char **buffer)
{
	char	*read_buffer;
	int		n_bytes;

	read_buffer = malloc(BUFFER_SIZE);
	if (read_buffer == NULL)
		return (2);
	n_bytes = read(fd, read_buffer, BUFFER_SIZE);
	while (n_bytes > 0 && *buffer)
	{
		if (!join_and_free(buffer, read_buffer, n_bytes))
		{
			free (read_buffer);
			return (2);
		}
		if (is_newline(read_buffer, n_bytes) && *buffer)
		{
			free(read_buffer);
			return (0);
		}
		n_bytes = read(fd, read_buffer, BUFFER_SIZE);
	}
	free(read_buffer);
	if (n_bytes == -1 || **buffer == 0)
		return (2);
	return (1);
}

static char	*get_line(char **buffer)
{
	char	*result;
	size_t	len;

	len = 0;
	while ((*buffer)[len] != '\n' && (*buffer)[len])
		len++;
	result = malloc(len + 1 + ((*buffer)[len] == '\n'));
	if (result == NULL)
	{
		free (*buffer);
		*buffer = NULL;
		return (NULL);
	}
	ft_strncpy(result, *buffer, len + ((*buffer)[len] == '\n'));
	return (result);
}

void	trim_read_line(char **buffer, char **result)
{
	char	*new_buffer;
	size_t	i;
	size_t	len;

	i = 0;
	while ((*buffer)[i] != '\n')
		i++;
	len = ft_strlen(&((*buffer)[i + 1]));
	new_buffer = malloc(len + 1);
	if (new_buffer == NULL)
	{
		free (*buffer);
		*buffer = NULL;
		free (*result);
		*result = NULL;
		return ;
	}
	ft_strncpy(new_buffer, &((*buffer)[i + 1]), len);
	free (*buffer);
	*buffer = new_buffer;
}

int main(void)
{
	int fd;
	char *line;

	fd = open("hola.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		//printf("Line: %s", line);	
		free (line);
		line = get_next_line(fd);
	}
	//printf("\nLine: %s", line);	
}