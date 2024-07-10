/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:05:47 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/07/10 15:09:54 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <fcntl.h>

void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
long	ft_atol(const char *str);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strchr(const char *str, int c);
int		ft_strlen(const char *str);

/*.........................PRINTF.........................*/

int		ft_putchar(int c);
int		ft_printf(const char *str, ...);
int		ft_puthexa(unsigned int nbr, const char c);
int		ft_putnbr(int nbr, int u);
int		ft_putpointer(unsigned long nbr);
int		ft_putpointerhexa(unsigned long nbr, const char c);
int		ft_putstr(char *str);

/*.....................GET_NEXT_LINE......................*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
int		ft_strlen(const char *str);

#endif