/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra <abouabra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:37:28 by abouabra          #+#    #+#             */
/*   Updated: 2022/10/22 15:35:58 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_fd(int fd, char *line)
{
	char	str[BUFFER_SIZE + 1];
	int		counter;

	counter = 1;
	while (!ft_strchr(line, '\n') && counter != 0)
	{
		counter = read(fd, str, BUFFER_SIZE);
		if (counter == -1)
			return (0);
		str[counter] = '\0';
		line = ft_strjoin(line, str);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line[OPEN_MAX];
	char		*final;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	final = 0;
	line[fd] = read_fd(fd, line[fd]);
	if (!line[fd])
		return (0);
	final = set_the_line(line[fd]);
	line[fd] = set_next_line(line[fd]);
	return (final);
}
