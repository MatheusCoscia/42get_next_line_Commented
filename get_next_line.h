/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrodri <matrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:25:20 by matrodri          #+#    #+#             */
/*   Updated: 2021/10/05 16:24:55 by matrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

/*
** GNL
*/
char	*get_next_line(int fd);

/*
** GNL_UTILS
*/
char	*ft_read_line(char *src);
char	*ft_save(char *src);

/*
** UTILS
*/
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *src, int c);

#endif
