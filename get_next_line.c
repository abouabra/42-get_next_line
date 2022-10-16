/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra <abouabra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:37:28 by abouabra          #+#    #+#             */
/*   Updated: 2022/10/16 17:00:24 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*line;
	char		*final;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	final = 0;
	line = read_fd(fd, line);
	if (!line)
		return (0);
	final = set_the_line(line);
	line = set_next_line(line);
	return (final);
}
