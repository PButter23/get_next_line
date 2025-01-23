/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arde-jes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:55:35 by arde-jes          #+#    #+#             */
/*   Updated: 2025/01/20 15:55:36 by arde-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_read_file(char *buffer, int fd)
{	
	char	*stash;
	ssize_t	bytes;

	stash = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!stash)
		return (NULL);
	bytes = 1;
	while (!strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, stash, BUFFER_SIZE);
		if (bytes == -1)
			return (free(stash), free(buffer), NULL);
		stash[bytes] = '\0';
		buffer = strjoin(buffer, stash);
		if (!buffer)
		{
			free(stash);
			return (NULL);
		}
	}
	free(stash);
	return (buffer);
}

char	*ft_extract_line(char *buffer)
{
	char	*line;
	int	ct;

	ct = 0;
	if (!buffer)
		return (NULL);
	while (buffer[ct] != '\n' && buffer[ct] != '\0')
		ct++;
	line = (char *)malloc((ct + 2) * sizeof(char));
	ct = 0;
	while (buffer[ct] != '\n' && buffer[ct] != '\0')
	{
		line[ct] = buffer[ct];
		ct++;
	}
	if (buffer[ct] == '\n')
	{
		line[ct] = '\n';
		ct++;
	}
	line[ct] = '\0';
	return (line);
}

char	*ft_update_buffer(char *buffer)
{
	int	ct;
	char	*extra_buffer;
	int	len;
	int	newct;

	newct = 0;
	ct = strchr(buffer, '\n') - buffer;
	if (ct == -1)
		return (NULL);
	len = strlen(buffer);
	extra_buffer = (char *)malloc((len - ct) * sizeof(char));
	if (!extra_buffer)
		return (NULL);
	while (buffer[ct + 1 + newct] != '\0')
	{
		extra_buffer[newct] = buffer[ct + 1 + newct];
		newct++;
	}
	extra_buffer[newct] = '\0';
	buffer[ct] = '\0';
	return (extra_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
		buffer = ft_read_file(buffer, fd);
	if (!buffer)
	{
		buffer = ft_calloc(1, sizeof(char));
		if (!buffer);
			return (NULL);
	}
	line = ft_extract_line(buffer);
	buffer = ft_update_buffer(buffer);
	return (line);
}