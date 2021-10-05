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

/* concatena duas strings */
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
/*	alocar memoria para s1 afim de retornar nossa resultado caso nossa linha seja nula */
	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
/*	alocar o espaço de memoria para que nossa nova string receba o conteudo de 's' em sua totalidade */
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
/*	copiar a primeira string em sua totalidade para nossa nova string */
	while (s1[j] != '\0')
		str[i++] = s1[j++];
	j = 0;
/*	copiar a segunda string em sua totalidade para nossa nova string */
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

/* contar a quantidade de caracteres de uma string */
size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
/*	enquanto minha string 's' nao chegar ao fim iremos incrementar nosso conta\
dor 'i' */
	while (s[i] != 0)
		i++;
/*	nosso contador 'i' possui o tamanho de nossa string */
	return (i);
}

/*	apontar em uma string a ultima ocorrencia de um caractere */
char	*ft_strchr(char *src, int c)
{
	size_t	i;

	i = 0;
	if (src == NULL)
		return (0);
/*	caso o caractere que buscamos seja '\0', devemos retornar sua ocorrencia */
	if (c == '\0')
		return ((char *)&src[ft_strlen(src)]);
/*	buscar por nosso caractere passado como parametro e retornar sua ocorrencia dentro de nossa string */
	while (src[i] != '\0')
	{
		if (src[i] == (char)c)
			return ((char *)&src[i]);
		i++;
	}
	return (0);
}

/*	retornar a linha que esta sendo "lida" neste momento */
char	*ft_read_line(char *src)
{
	size_t	i;
	char	*str;

	i = 0;
	if (src == NULL)
		return (NULL);
/*	procurar pelo caractere nulo '\0' ou quebra de linha '\n' */
	while (src[i] != '\0' && src[i] != '\n')
		i++;
/*	alocar memoria suficiente em nossa nova string */
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (str == NULL)
		return (NULL);
	i = 0;
/*	copiar caractere por caractere de nosso source para nossa nova string */
	while (src[i] != '\0' && src[i] != '\n')
	{
		str[i] = src[i];
		i++;
	}
/*	caso nossa string tenha sido copiada ate a quebra de linha, temos que obri/
toriamente printar uma quebra de linha */
	if (src[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

/*	"salvar" em um ponteiro estatico o restante do conteudo de nosso fd */
char	*ft_save(char *src)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
/*	procurar pelo caractere nulo '\0' ou quebra de linha '\n' */
	while (src[i] != '\0' && src[i] != '\n')
		i++;
/*	caso nossa string tenha sido copiada ate a quebra de linha, iremos fazer n/
ossa alocacao de memoria */
	if (src[i] == '\0')
	{
		free(src);
		return (0);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(src) - i + 1));
	if (str == NULL)
		return (NULL);
	i = i + 1;
	j = 0;
/*	copiar caractere por caractere de nosso source para nossa nova string */
	while (src[i] != '\0')
		str[j++] = src[i++];
	str[j] = '\0';
	free(src);
	return (str);
}

