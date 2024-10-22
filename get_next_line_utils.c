/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:48:37 by jquinde-          #+#    #+#             */
/*   Updated: 2024/10/22 16:37:35 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	while (i - buffer_len < n_bytes)
	{
		new_buffer[i] = read_buffer[i - buffer_len];
		i++;
	}
	new_buffer[i] = 0;
	free (old_buffer);
	return (new_buffer);
}

void	print_decima(char *line)
{
	while (*line)
	{
		printf("%d ", *line);
		line++;
	}
	printf("%d ", *line);
	printf("\n");
}

int	is_newline(char *str, int len)
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