/* ************************************************************ */
/*                                                              */
/*             ╓▀▀▀▀▀▀▄                 :::      ::::::::       */
/*            █▀      ▐               :+:      :+:    :+:       */
/*            █   ▀   ▓█            +:+ +:+         +:+         */
/*            █      █▓▓▓▓█       +#+  +:+       +#+            */
/*    ▄▄ ▄▄▄███████─▄▀█▀▀       +#+#+#+#+#+   +#+               */
/*    █ ███████████▄██ ██             #+#    #+#                */
/*    █  █▀▀   ██████████▌           ###   ########.fr          */
/*    █  ▀▄▄    ▀████████▌                                      */
/*     ▀█   ▀ ▄▄▄████████▌      42cursus | MCoscia | matrodri   */
/*        ▀▀  ▄▄▄▄▄▄▄▄▄█▀       quack quack |  vila pescopata   */
/*                                                              */
/* ************************************************************ */

#include "get_next_line.h"

/*	localizar a linha que deverá ser lida em nosso fd */
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
/*	enquanto procuramos nosso caractere '\n' */
	while (!ft_strchr(src, '\n') && size != 0)
	{
/*	verificar os bytes lidos e, caso não tenha ocorrido nenhum erro, salvar a quantidade de bytes lidos */
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free(buffer);
			return (NULL);
		}
/*	adicionar um caractere nulo a ultima posicao armazenada em nosso buffer */
		buffer[size] = '\0';
/*	concatenar nossas string */
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
/*	ler nossa linha em busca do caractere '\n' ou de qualquer erro*/
	next_line = get_line(next_line, fd);
	if (next_line == NULL)
		return (NULL);
/*	retornar a linha que foi "lida" */
	line = ft_read_line(next_line);
/*	salvar todo conteudo que ainda nao foi lido de nosso fd */
	next_line = ft_save(next_line);
	if (line[0] == '\0')
	{
		free(next_line);
		free(line);
		return (NULL);
	}
/*	retornar nossa linha que foi "lida" */
	return (line);
}
