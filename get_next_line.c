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

char	*read_file(char *buffer, int fd);
char	*join_and_free(char *buffer, char *read_buffer, int n_bytes);
void	get_line(char *buffer, char **result);
int		is_newline(char *read_buffer, int len);

char	*get_next_line(int fd)
{
	char static	*buffer;
	char		*result;

	result = NULL;
	buffer = ft_calloc(1, 1);
	if (buffer == NULL)
		return (NULL);
	read_file(buffer, fd);
	get_line(buffer, &result);
	return (result);
}

char	*read_file(char *buffer, int fd)
{
	char	*read_buffer;
	int		n_bytes;

	read_buffer = malloc(BUFFER_SIZE);
	if (read_buffer == NULL)
		return (NULL);
	n_bytes = read(fd, read_buffer, BUFFER_SIZE);
	while (n_bytes > 0)
	{
		/*
		printf("---------\nn_bytes: %d, read: \n|%s|:", n_bytes, read_buffer);
		for (size_t i = 0; i < n_bytes; i++)
		{
			printf(" %d\n", read_buffer[i]);
		}	
		*/
		buffer = join_and_free(buffer, read_buffer, n_bytes);
		//printf("-----------\n");

		if (is_newline(read_buffer, n_bytes))
		{
			free(read_buffer);
			return (buffer);
		}
		n_bytes = read(fd, read_buffer, BUFFER_SIZE);
	}
	return ("Hey porque");
}

char	*join_and_free(char *old_buffer, char *read_buffer, int n_bytes)
{
	char	*new_buffer;
	size_t	buffer_len;
	size_t	i;

	i = 0;
	buffer_len = ft_strlen(old_buffer);
	new_buffer = malloc(buffer_len + n_bytes + 1);
	if (new_buffer == NULL)
		return (NULL);
	while (i < buffer_len)
	{
		new_buffer[i] = old_buffer[i];
		i++;
	}
	while (i < n_bytes + buffer_len)
	{
		new_buffer[i] = read_buffer[i - buffer_len];
		i++;
	}
    //printf("Old Buffer: \n|%s|\nsize: %zu\n", old_buffer, buffer_len);
    new_buffer[i] = 0;
	free (old_buffer);
    //printf("New Buffer: \n|%s|\nsize: %zu\n", new_buffer, buffer_len + n_bytes);
	return (new_buffer);
}

void	get_line(char *buffer, char **result)
{
	size_t len;

	len = ft_strlen(buffer);
	*result = malloc(len + 1);
	if (*result == NULL)
		return ;
	ft_strlcpy(*result, buffer, len + 1);
	free(buffer);
}

int	is_newline(char *read_buffer, int len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (read_buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
