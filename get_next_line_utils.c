/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdemir <akdemir@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:39:11 by akdemir           #+#    #+#             */
/*   Updated: 2023/07/30 19:51:50 by akdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	nlcheck(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*p;
	int		i;
	int		s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (len > s_len - start)
		len = s_len - start;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		*s1 = '\0';
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (*(s1 + ++i))
		*(str + i) = *(s1 + i);
	j = -1;
	while (*(s2 + ++j))
		*(str + i + j) = *(s2 + j);
	*(str + i + j) = '\0';
	free(s1);//s2 malloclanmadığından free yok
	return (str);
}

#include <stdlib.h>

char *ft_strjoin(char *s1, char *s2)
{
    char *str;
    int len_s1 = 0;
    int len_s2 = 0;
    int i = 0;

    if (s1)
        while (s1[len_s1])
            len_s1++;

    if (s2)
        while (s2[len_s2])
            len_s2++;

    str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
    if (!str)
        return NULL;

    while (*s1)
        str[i++] = *s1++;

    while (*s2)
        str[i++] = *s2++;

    str[i] = '\0';

    free(s1 - len_s1); // Belleği serbest bırakma işlemi değiştirildi
    return str;
}
