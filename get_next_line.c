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

//aloca 2 de base
//+3 si hay cosas dentro
//+1 por caracter

#include "get_next_line.h"

int		read_file(int fd, char	**buffer);
char	*get_line(char *buffer);
char	*trim_read_line(char *buffer);

char	*get_next_line(int fd)
{
	int			read_status;
	char static	*buffer;
	char		*result;

	if (buffer == NULL)
	{
		buffer = ft_calloc(1, 1);
		if (buffer == NULL)
			return (NULL);
	}
	if (!(is_newline(buffer, ft_strlen(buffer))))
		read_status = read_file(fd, &buffer);
	//printf("Status: %d\n", read_status);
	if (read_status == 0)
	{
		result = get_line(buffer);
		buffer = trim_read_line(buffer);
		return (result);
	}
	else if (read_status == 1)
	{
		//printf("Buffer: ");
		//print_decima(buffer);
		result = get_line(buffer);
		*buffer = 0;
		return (result);
	}
	return (NULL);
}

int	read_file(int fd, char **buffer)
{
	char	*read_buffer;
	int		n_bytes;

	read_buffer = malloc(BUFFER_SIZE);
	if (read_buffer == NULL)
		return (2);
	n_bytes = read(fd, read_buffer, BUFFER_SIZE);
	while (n_bytes > 0)
	{
		*buffer = join_and_free(*buffer, read_buffer, n_bytes);
		if (is_newline(read_buffer, n_bytes))
		{
			free(read_buffer);
			return (0);
		}
		n_bytes = read(fd, read_buffer, BUFFER_SIZE);
	}
	free(read_buffer);
	if (n_bytes == 0 && **buffer != 0)
		return (1);
	free (*buffer);
	return (2);
}

char	*get_line(char *buffer)
{
	char	*result;
	size_t	len;

	if (buffer == NULL)
		return (NULL);
	len = 0;
	while (buffer[len] != '\n' && buffer[len])
		len++;
	if (buffer[len] == 0)
	{
		result = malloc(len + 1);
		ft_memcpy(result, buffer, len + 1);
		return (result);
	}
	result = malloc(len + 2);
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, buffer, len + 1);
	result[len + 1] = 0;
	return (result);
}

char	*trim_read_line(char *buffer)
{
	char	*new_buffer;
	size_t	i;
	size_t	len;

	i = 0;
	//printf("Old buffer: ");
	//print_decima(buffer);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (!buffer[i])
		return (buffer);
	len = ft_strlen(&buffer[i + 1]);
	new_buffer = malloc(len + 1);
	ft_memcpy(new_buffer, &buffer[i + 1], len + 1);
	free (buffer);
	//printf("New buffer: ");
	//print_decima(new_buffer);
	return (new_buffer);
}
