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

int	ft_find_line(char *buffer, int fd)
{	
	
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!buffer)
	{
		buffer = ft_calloc(1, sizeof(char));
		if (!buffer);
			return (NULL);
	}

}