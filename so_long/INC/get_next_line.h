/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:32:26 by hverdugo          #+#    #+#             */
/*   Updated: 2025/01/13 02:33:00 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

size_t	ft_strlen1(const char *s);
void	*ft_calloc1(size_t x, size_t y);
void	ft_bzero1(void *str, size_t x);
char	*get_next_line(int fd);
char	*ft_strjoin1(char *s1, char *s2);
char	*ft_strdup1(const char *s);
int		ft_strchar1(char *str, char c);
#endif
