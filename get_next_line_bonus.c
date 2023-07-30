/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdemir <akdemir@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:44:52 by akdemir           #+#    #+#             */
/*   Updated: 2023/07/30 19:40:15 by akdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(char *str, int fd)
{
	char	*temp;
	int		byte;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	byte = 1;
	while (!new_check(str) && byte != 0)
	{
		byte = read(fd, temp, BUFFER_SIZE);
		if (byte == -1)
		{
			if (str)
				free(str);
			free(temp);
			return (NULL);
		}
		temp[byte] = '\0';
		str = ft_strjoin_gnl(str, temp);
	}
	free(temp);
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
	arr = malloc(sizeof(char) * (i + 1));
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
	char	*cuttedline;
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
	cuttedline = ft_substr(str, start, len);
	free (str);
	return (cuttedline);
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
