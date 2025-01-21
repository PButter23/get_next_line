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

int	strlen(char	*buffer)
{
	int	len;

	len = 0;
	while (buffer[len] != '\n' || buffer[len] != '\0' && len <= BUFFER_SIZE)
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*n;
	int		ct;
	int		c;

	c = ft_strlen((char *)s1);
	ct = ft_strlen((char *)s2);
	n = (char *)malloc(ct + c + 1);
	if (n == NULL)
		return (NULL);
	ct = 0;
	c = 0;
	while (s1[ct] != '\0')
	{
		n[ct] = s1[ct];
		ct++;
	}
	while (s2[c] != '\0')
	{
		n[ct] = s2[c];
		ct++;
		c++;
	}
	n[ct] = '\0';
	return (n);
}