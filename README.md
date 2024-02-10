# Exam Rank 03

Bütün exam rank 03 sorularının işlevleri ve kodları bu repository'nin içerisinde yer almaktadır.

Exam Rank 03, tek soruluk bir sınavdır. Sınavda soru olarak karşınıza çıkabilecek iki farklı soru çeşidi bulunmaktadır:
1. ft_printf
2. get_next_line

<br></br>

## `ft_printf`
`ft_printf` , biçimlendirilmiş çıktıları ekrana yazdırmak için kullanılır. İlgili başlık dosyalarını (`<unistd.h>` ve `<stdarg.h>`) içerir ve bir değişken argüman listesi kullanır.

- `void ft_putstr(char *str, int *len)`: Bir stringi ekrana yazdırmak için yardımcı bir fonksiyondur. Eğer string NULL ise, "(null)" stringini yazdırır.

- `void ft_int(long long int nb, int *len, int base)`: Bir tamsayıyı belirtilen sayı tabanına göre ekrana yazdırmak için yardımcı bir fonksiyondur. Negatif sayıları da ele alır ve gerekirse eksi işareti ekler.

- `int ft_printf(const char *format, ...)`: Biçimlendirilmiş çıktıları ekrana yazdıran ana fonksiyondur. `format` stringi, çıktının formatını belirtir. `%` işareti ile başlayan özel belirteçleri tanır ve bu belirteçlere göre ilgili değerleri ekrana yazdırır. Desteklenen belirteçler arasında `%s` (string), `%d` (ondalık tamsayı), `%x` (hexadecimal tamsayı) bulunur.

<br></br>

## `get_next_line`
`get_next_line` , bir dosyadan satır satır okuma işlemini gerçekleştirir. Başlık dosyasını (`"get_next_line.h"`) içerir.

- `int ft_strlen(char *str)`: Bir stringin uzunluğunu hesaplamak için yardımcı bir fonksiyondur.

- `char *ft_strjoin(char *str1, char *str2)`: İki stringi birleştirmek için yardımcı bir fonksiyondur.

- `char *ft_substr(char *str, int i)`: Belirli bir aralıktaki karakterleri kopyalamak için yardımcı bir fonksiyondur.

- `int check(char *line)`: Verilen string içinde bir newline karakteri (satır sonu) kontrol eder. Eğer varsa, indeksini döndürür; yoksa, -1 döndürür.

- `char *next_line(char *line, int fd)`: Dosyadan bir satır okuma işlemini gerçekleştiren yardımcı bir fonksiyondur. `BUFFER_SIZE` kadar okuma yapar ve okunan veriyi stringe ekler.

- `char *get_next_line(int fd)`: Bir dosyadan satır satır okuma işlemini gerçekleştiren ana fonksiyondur. `check` ve `next_line` fonksiyonlarını kullanarak dosyadan satırları okur ve geri döndürür. Bu fonksiyon, statik bir değişken olan `line` üzerinde çalışır ve dosyadan okunan satırları saklar. Okuma işlemi tamamlandığında, kalan veriyi ve bellek temizleme işlemlerini gerçekleştirir.
