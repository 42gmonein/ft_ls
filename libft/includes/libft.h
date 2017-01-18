/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 06:10:07 by gmonein           #+#    #+#             */
/*   Updated: 2017/01/18 01:44:33 by gmonein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

void	*ft_memalloc(size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strnew(size_t size);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strsub(char const *s, unsigned int start, size_t end);
char	*ft_strdup(char *s);
void	ft_strdel(char **s);
char	*ft_stradd(char *str, char c, int a);
int		ft_strcmp(char *s1, char *s2);
void	ft_putnbr(int c);
char	**ft_strsplit(char const *s, char c);

#endif
