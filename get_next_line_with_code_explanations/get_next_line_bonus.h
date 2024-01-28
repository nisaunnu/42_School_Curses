/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:24:52 by nunnu             #+#    #+#             */
/*   Updated: 2024/01/28 14:31:13 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// önişlemci direktifleri: GET_NEXT_LINE_BONUS_H sembolüyle başlık dosyasının çoğaltılmasını önler
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

// standart kütüphane başlık dosyalarını içe aktar
# include <stdlib.h>
# include <unistd.h>

// BUFFER_SIZE tanımlanmamışsa, varsayılan değeri 32 olarak ayarla
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

// NUM_OF_FD tanımlanmamışsa, varsayılan değeri 4096 olarak ayarla
# ifndef NUM_OF_FD
#  define NUM_OF_FD 4096
# endif

char	*get_next_line(int fd);										// get_next_line fonksiyonunun prototipi
size_t	ft_strlen(const char *s);									// ft_strlen fonksiyonunun prototipi
char	*ft_strdup(const char *s1);									// ft_strdup fonksiyonunun prototipi
char	*ft_strjoin(char const *s1, char const *s2);				// ft_strjoin fonksiyonunun prototipi
void	*ft_free_stash(char **stash, int create_line);				// ft_free_stash fonksiyonunun prototipi
char	*ft_substr(char const *s, unsigned int start, size_t len);	// ft_strjoin fonksiyonunun prototipi

#endif
