/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdemir <akdemir@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:44:52 by akdemir           #+#    #+#             */
/*   Updated: 2023/08/02 16:58:14 by akdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(char *str, int fd)
{
	char	*tmp;
	int		byt;

	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	byt = 1;
	while (!nlcheck(str) && byt != 0)
	{
		byt = read(fd, tmp, BUFFER_SIZE);
		if (byt == -1)
		{
			if (str)
				free(str);
			free(tmp);
			return (NULL);
		}
		tmp[byt] = '\0';
		str = ft_strjoin(str, tmp);
	}
	free(tmp);
	return (str);
}

char	*ft_getline(char *s)
{
	int		i;
	char	*arr;

	i = -1;
	while (s[++i])
		if (s[i] == '\n')
			break ;
	if (s[i] == '\n')
		i++;
	arr = (char *)malloc(sizeof(char) * (i + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		arr[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_cutline(char *str)
{
	char	*cline;
	int		start; 
	int		len;
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			break ;
	if (str[i] == '\n')
		i++;
	start = i;
	len = (ft_strlen(str) - start);
	if (len == 0)
	{
		free(str);
		return (NULL);
	}
	cline = ft_substr(str, start, len);
	free (str);
	return (cline);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = ft_read(str[fd], fd);
	if (!str[fd] || !*str[fd])
	{
		if (str[fd])
			free(str[fd]);
		str[fd] = NULL;
		return (NULL);
	}
	line = ft_getline(str[fd]);
	str[fd] = ft_cutline(str[fd]);
	return (line);
}
