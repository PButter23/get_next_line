/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arde-jes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:56:31 by arde-jes          #+#    #+#             */
/*   Updated: 2025/01/20 15:56:32 by arde-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	str = malloc (nmemb * size);
	if (str == NULL)
	{
		return (NULL);
	}
	ft_bzero(str, nmemb * size);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	ct;

	ct = 0;
	while (s[ct] != '\0')
	{
		if (s[ct] == (char)c)
		{
			return ((char *)&s[ct]);
		}
		ct++;
	}
	if ((char)c == '\0')
		return ((char *)&s[ct]);
	return (NULL);
}