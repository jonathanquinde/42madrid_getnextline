/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:48:37 by jquinde-          #+#    #+#             */
/*   Updated: 2024/10/23 15:26:26 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_and_free(char *old_buffer, char *read_buffer, size_t n_bytes)
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
	while (i - buffer_len < n_bytes)
	{
		new_buffer[i] = read_buffer[i - buffer_len];
		i++;
	}
	new_buffer[i] = 0;
	free (old_buffer);
	return (new_buffer);
}

void	ft_strncpy(char *dest, char *src, size_t n)
{
	while (n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	*dest = 0;
}

size_t	ft_strlen(const char *str)
{
	const char	*start;

	start = str;
	while (*str)
		str++;
	return (str - start);
}

int	is_newline(char *str, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
