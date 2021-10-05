/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrodri <matrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:44:14 by matrodri          #+#    #+#             */
/*   Updated: 2021/09/14 18:00:18 by matrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *src, int fd)
{
	char	*buffer;
	int		size;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	size = 1;
	while (!ft_strchr(src, '\n') && size != 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[size] = '\0';
		src = ft_strjoin(src, buffer);
	}
	free(buffer);
	return (src);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*next_line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	next_line = get_line(next_line, fd);
	if (next_line == NULL)
		return (NULL);
	line = ft_read_line(next_line);
	next_line = ft_save(next_line);
	if (line[0] == '\0')
	{
		free(next_line);
		free(line);
		return (NULL);
	}
	return (line);
}

/*#include <stdio.h>
#include <fcntl.h>
int    main(void)
{
    char    *line;
    int        i;
//    int        fd1;
    int        fd2;
//    int        fd3;
//    fd1 = open("test.txt", O_RDONLY);
    fd2 = open("test2.txt", O_RDONLY);
//    fd3 = open("test3.txt", O_RDONLY);
    i = 1;
    while (i < 7)
    {
//        line = get_next_line(fd1);
//        printf("line [%02d] test1: %s", i, line);
//        free(line);
        line = get_next_line(fd2);
        printf("line [%02d] test2: %s", i, line);
//        free(line);
//        line = get_next_line(fd3);
//        printf("line [%02d] test2: %s", i, line);
        free(line);
        i++;
    }
//    close(fd1);
    close(fd2);
//    close(fd3);
    return (0);
}*/
