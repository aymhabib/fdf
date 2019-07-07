/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymhabib <aymhabib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:59:06 by aymhabib          #+#    #+#             */
/*   Updated: 2019/07/07 04:47:55 by aymhabib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_line(char **str, int fd)
{
	int i;

	i = 0;
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_free(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = 0;
	free(s1);
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	int			i;
	int			j;
	static char	*str[4864];
	char		buffer[BUFF_SIZE + 1];
	char		*tmp;

	if (fd < 0 || read(fd, buffer, 0) || !line)
		return (-1);
	if (!str[fd])
		str[fd] = ft_strnew(0);
	while ((j = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[j] = '\0';
		str[fd] = ft_strjoin_free(str[fd], buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	i = count_line(str, fd);
	*line = ft_strsub(str[fd], 0, count_line(str, fd));
	if (!j && !ft_strlen(str[fd]) && !count_line(str, fd))
		return (0);
	tmp = str[fd];
	str[fd] = ft_strdup(str[fd] + i + (str[fd][count_line(str, fd)] ? 1 : 0));
	free(tmp);
	return (1);
}
