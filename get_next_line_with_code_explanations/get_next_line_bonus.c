/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:24:46 by nunnu             #+#    #+#             */
/*   Updated: 2024/01/28 14:42:30 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

// Stash'ten bir satır çıkaran yardımcı fonksiyon
static char	*ft_extract_line(char *stash)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	if (!stash) // eğer stash boşsa, stash'i temizle ve NULL döndür
		return (ft_free_stash(&stash, 0));
	while (stash[i] != '\n') // stash'te yeni satır karakterini bulana kadar ilerle
		i++;
	line = malloc(sizeof(char) * (i + 2)); // beni bir bellek bloğu tahsis et
	if (!line) // bellek tahsisi başarısız olursa, stash'i temizle ve NULL döndür
		return (ft_free_stash(&line, 0));
	j = 0;
	while (j < i + 1) // satırın tamamını yeni bellek bloğuna kopyala
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0'; // null karakter ile sonlandır
	return (line); // oluşturulan satır dizisini döndür
}

// Stash'i güncelleyerek yeni bir stash oluşturan yardımcı fonksiyon
static char	*ft_recreate_stash(char *stash)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!stash) // eğer stash boşsa, NULL döndür
		return (NULL);
	while (stash[i] != '\n') // stash'te yeni satır karakterini bulana kadar ilerle
		i++;
	if (stash[i + 1] == '\0') // yğer stash'te yeni satır karakterinin hemen sonrası null karakterse
		return (ft_free_stash(&stash, 0));
	res = ft_substr(stash, i + 1, ft_strlen(stash)); // yeni bir stash oluştur, yeni satır karakterinin sonrasından başla
	if (!res) // bellek tahsisi başarısız olursa, stash'i temizle ve NULL döndür
	{
		ft_free_stash(&stash, 0);
		return (NULL);
	}
	ft_free_stash(&stash, 0); // stash'i temizle
	return (res); // oluşturulan yeni stash'i döndür
}
// Ana get_next_line fonksiyonu
char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	long		ret;
	static char	*stash [NUM_OF_FD];
	char		*line;

	line = 0; // başlangıçta line'ı NULL olarak ayarla
	ret = BUFFER_SIZE; // başlangıçta ret'i BUFFER_SIZE olarak ayarla
	if (fd < 0 || BUFFER_SIZE <= 0) // geçersiz dosya tanıtıcısı veya negatif tampon boyutu kontrolü
		return (ft_free_stash(&stash[fd], 0)); // stash'i temizle ve NULL döndür
	while (ret > 0) // okuma işlemleri
	{
		ret = read(fd, buf, BUFFER_SIZE); // dosyadan okuma işlemini gerçekleştirerek ret değerini güncelle
		if ((ret <= 0 && !stash[fd]) || ret == -1) // okuma hatası veya stash boşsa
			return (ft_free_stash(&stash[fd], 0)); // stash'i temizle ve NULL döndür
		buf[ret] = '\0'; // okunan veriyi null karakterle sonlandır
		stash[fd] = ft_copy_to_stash(stash[fd], buf); // stash'i güncelleyerek buf ile birleştir
		if (ft_have_nl(stash[fd])) // stash'te yeni satır karakteri varsa
		{
			line = ft_extract_line(stash[fd]); // stash'ten bir satır çıkart
			if (!line) // satır çıkarma başarısız olursa, stash'i temizle ve NULL döndür
				return (ft_free_stash(&stash[fd], 0));
			return (stash[fd] = ft_recreate_stash(stash[fd]), line); // stash'i güncelleyerek yeni bir stash oluştur ve line'ı döndür
		}
	}
	return (ft_free_stash(&stash[fd], 1)); // dosya sonuna ulaşıldığında veya hata durumunda stash'i temizle
}
