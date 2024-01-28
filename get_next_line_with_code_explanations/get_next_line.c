/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:25:25 by nunnu             #+#    #+#             */
/*   Updated: 2024/01/28 14:17:48 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// stash'i buf ile birleştirip yeni bir dize oluşturan yardımcı fonksiyon
static char	*ft_copy_to_stash(char *stash, char *buf)
{
	char	*res;

	res = 0;
	if (!stash && buf) // eğer stash boşsa ve buf doluysa
	{
		res = ft_strdup(buf); // buf'u kopyalayarak yeni bir dize oluştur
		if (!res) // bellek tahsisi başarısız olursa NULL döndür
			return (NULL);
		return (res); // yeni diziyi döndür
	}
	res = ft_strjoin(stash, buf); // eğer stash doluysa, stash ve buf'u birleştir
	ft_free_stash(&stash, 0); // stash'i temizle ve bellek tahsis hatası durumunda NULL döndür
	return (res); // oluşturulan yeni diziyi döndür
}

// Bir dizide yeni satır karakteri var mı diye kontrol eden yardımcı fonksiyon
static int	ft_have_nl(char *s)
{
	size_t	i;

	if (!s) // eğer dize boşsa veya NULL ise yeni satır yoktur
		return (0);
	i = -1;
	while (s[++i] != '\0') // dize boyunca dolaşarak yeni satır karakterini kontrol et
		if (s[i] == '\n')
			return (1);
	return (0); // yeni satır karakteri bulunamazsa 0 döndür
}

// stash içindeki verilerden yeni satır karakterine kadar olan kısmı kopyalayan fonksiyon
static char	*ft_extract_line(char *stash)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	if (!stash) // eğer stash boşsa, 0 döndür
		return (0);
	while (stash[i] != '\n') // stash içindeki verilerden yeni satır karakterine kadar olan kısmı bul
		i++;
	line = malloc(sizeof(char) * (i + 2)); // yeni bir dize için bellek tahsis et
	if (!line) // bellek tahsis hatası durumunda 0 döndür
		return (0);
	j = 0;
	while (j < i + 1) // stash içindeki verilerden yeni satır karakterine kadar olan kısmı kopyala
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0'; // null karakterle sonlandır
	return (line); // oluşturulan diziyi döndür
}

// stash içindeki verilerden kalan kısmı yeni bir dize oluşturarak taşıyan fonksiyon
static char	*ft_recreate_stash(char *stash)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!stash) // eğer stash boşsa, NULL döndür
		return (NULL);
	while (stash[i] != '\n') // stash içindeki verilerden yeni satır karakterine kadar olan kısmı bul
		i++;
	if (stash[i + 1] == '\0') // eğer yeni satır karakteri sonrasında veri kalmamışsa
		return (ft_free_stash(&stash, 0)); // stash'i temizle ve NULL döndür
	res = ft_substr(stash, i + 1, ft_strlen(stash)); // yeni bir dize oluşturarak kalan veriyi taşı
	if (!res) // bellek tahsis hatası durumunda, stash'i temizle ve NULL döndür
	{
		ft_free_stash(&stash, 0);
		return (NULL);
	}
	ft_free_stash(&stash, 0); // stash'i temizle
	return (res); // oluşturulan diziyi döndür
}

// Ana get_next_line fonksiyonu
char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	long		bytes_read;
	static char	*stash = NULL;
	char		*line;

	line = 0; // başlangıçta line'ı NULL olarak ayarla
	bytes_read = BUFFER_SIZE; // başlangıçta bytes_read'i BUFFER_SIZE olarak ayarla
	if (fd < 0 || BUFFER_SIZE <= 0) // BUFFER_SIZE negatif veya sıfır ise veya fd negatifse, stash'i temizle ve NULL döndür
		return (ft_free_stash(&stash, 0));
	while (bytes_read > 0) // okuma işlemleri
	{
		bytes_read = read(fd, buf, BUFFER_SIZE); // dosyadan okuma yap
		if ((bytes_read <= 0 && !stash) || bytes_read == -1) // Okuma başarısız ve stash boşsa veya read fonksiyonu -1 döndürürse, stash'i temizle ve NULL döndür
			return (ft_free_stash(&stash, 0));
		buf[bytes_read] = '\0'; // okunan veriyi null karakterle sonlandır
		stash = ft_copy_to_stash(stash, buf); // stash ve buf'u birleştir
		if (ft_have_nl(stash)) // stash içinde yeni satır karakteri varsa
		{
			line = ft_extract_line(stash); // stash içindeki verilerden bir satır çıkar ve line olarak sakla
			if (!line) // line oluşturulamazsa, stash'i temizle ve NULL döndür
				return (ft_free_stash(&stash, 0));
			return (stash = ft_recreate_stash(stash), line); // stash'i güncelle (yeni satır karakterinden sonrasını alarak) ve line döndür
		}
	}
	return (ft_free_stash(&stash, 1)); // okuma işlemleri tamamlandığında veya hata durumunda stash'i temizle ve NULL döndür
}
