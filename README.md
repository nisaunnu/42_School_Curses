# 42 Curses Libft
Ecole 42 okullarında 42Curses (ana eğitim) olarak ilk yapılan proje libft projesidir. Libft projesi, kendi kütüphanemizi oluşturmaya olanak tanır. Sonraki projeler için bu kütüphane kullanılacaktır. Bu github deposu libft için gerekli açıklamaları ve kodları içermektedir.
<br></br>

## Fonksiyonlar
|İsim           |Man Açıklaması                                |Fonksiyon Yazımı      |
|:---           |:---                                          |:---                  |
|ft_isalpha     |Alfabede olup olmadığını kontrol eder         |int	ft_isalpha(int c) |
|ft_isdigit     |Sayı olup olmadığını kontrol eder             |int	ft_isdigit(int c) |
|ft_isalnum     |Alfabe veya sayı olup olmadığını kontrol eder |int	ft_isalnum(int c) |
|ft_isascii     |ASCII değer aralığında olup olmadığına bakar  |int	ft_isascii(int c) |
|ft_isprint     |Herhangi bir yazdırma karakterini test eder   |int	ft_isprint(int c) |
|ft_strlen      |Parametrenin uzunluğunu verir                 |size_t	ft_strlen(const char *s)|
|ft_memset      |Dİziye karakter kopyalar                      |void	*ft_memset(void *b, int c, size_t len)|
|ft_bzero       |Diziye null atar                              |void	ft_bzero(void *s, size_t n)|
|ft_memcpy      |Bellekteki verilerin bir bellek bloğundan başka bir bellek bloğuna kopyalar                      |void	*ft_memcpy(void *dst, const void *src, size_t n)|
|ft_memmove     |ft_memcpy ile aynı işlev gerçekleştirir, overloop oluşmaması için sondan kopyalama işlemi yapılır|void	*ft_memmove(void *dst, const void *src, size_t len)|
|ft_strlcpy     |src'yi dest'e kopyalama işlemi gerçekleştirir ve dest'in sonuna '\0' koyar                       |size_t	ft_strlcpy(char * dst, const char *src, size_t dstsize)|
|ft_strlcat     |src dizesini dst dizesinin sonuna ekler                                                         |size_t	ft_strlcat(char *dst, const char *src, size_t dstsizeV)|
|ft_toupper     |Küçük harfleri büyük harfe çevirir            |int	ft_toupper(int c)|
|ft_tolower     |Büyük harfleri küçük harfe çevirir            |int	ft_tolower(int c)|
|ft_strchr      |Dizide girilen karakteri arar ve bulduğu yerden itibaren yazdırır|char	*ft_strchr(const char *s, int c)|
|ft_strrchr     |ft_strchr ile aynı işlevi gerçekleştirir, farkı ise dizide karakteri ararken tersten arama yapar|char	*ft_strrchr(const char *s, int c)|
|ft_strncmp     |Girilen dizileri karşılaştırır ve farklı karakter bulunursa ASCII değerleri birbirinden çıkartılır|int	ft_strncmp(const char *s1, const char *s2, size_t n)|
|ft_memchr      |Herhangi bir türdeki bellek alanındaki dizide girilen karakteri arar ve bulduğu yerden itibaren yazdırır|void	*ft_memchr(const void *s, int c, size_t n)|
|ft_memcmp      |Herhangi bir türdeki bellek alanındaki dizide; girilen dizileri karşılaştırır ve farklı karakter bulunursa ASCII değerleri birbirinden çıkartılır|int	ft_memcmp(const void *s1, const void *s2, size_t n)|
|ft_strnstr     |Girilen haystack dizisi içerisinde, alt dizi veya alt karakter olan needle dizisini arar|char	*ft_strnstr(const char *haystack, const char *needle, size_t len)|
|ft_atoi        |ASCII'yi integer'a çevirir, birden fazla operatör döndürülürse return(0) döndürülür|int	ft_atoi(const char *str)|
|ft_calloc      |Girilen parametrelerin çarpımı kadar yer açılır ve NULL ile doldurulur|void	*ft_calloc(size_t count, size_t size)|
|ft_strdup      |Gelen dizinin uzunluğu bulup malloc ile yeni bir alan tahsis edilir ve gelen dizi yeni açılan adrese kopyalanır|char	*ft_strdup(const char *s1)|

<br></br>

## Extra Fonksiyonlar
|İsim           |Man Açıklaması                                |Fonksiyon Yazımı      |
|:---           |:---                                          |:---                  |
|ft_substr      |s dizisinden start değeri kadar ilerledikten sonra, len kadarını yeni bi `char *`' a kopyalar|char	*ft_substr(const char *s, unsigned int start, size_t len)|
|ft_strjoin     |*s1 ve *s2 dizisini birleştirerek yeni bir dizi oluşturur|char	*ft_strjoin(char const *s1, char const *s2)|
|ft_strtrim     |s1 dizisinin başında ve sonunda *set dizisinde verdiğimiz karakterleri bulursa kırpar|char	*ft_strtrim(char const *s1, char const *set)|
|ft_split       |Girilen tek boyutlu char dizisini parametredeki karakterle ayırarak çift boyutlu bi char dizisi yapar|char	**ft_split(char const *s, char c)|
|ft_itoa        |int to ascii gelen int değerin boyutunu hesaplar|char	*ft_itoa(int n)|
|ft_strmapi     |*s dizisinin her bir indexinin içerisine,  yazılan fonksiyon uygulanır|char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))|
|ft_striteri    |s dizisinin her indexini (sırasıyla) parametredeki fonksiyona parametre olarak gönderir|void	ft_striteri(char *s, void (*f)(unsigned int, char *))|
|ft_putchar_fd  |c karakterini oluşturulan fd (file descriptor/dosya tanımlayıcı) yolundaki dosyaya yazar|void	ft_putchar_fd(char c, int fd)|
|ft_putstr_fd   |s dizisini fd'nin gösterdiği yola yazar|void	ft_putstr_fd(char *s, int fd)|
|ft_putendl_fd  |s dizisini fd yoluna yazar ve bir alt satıra geçer|void	ft_putendl_fd(char *s, int fd)|
|ft_putnbr_fd   |Parametrede verilen sayıyı recursive şeklinde byte byte putchar_fd ile dosya yoluna yazar|void	ft_putnbr_fd(int n, int fd)|

<br></br>

## BONUS
|İsim           |Man Açıklaması                                |Fonksiyon Yazımı      |
|:---           |:---                                          |:---                  |
|ft_lstnew      |content ile yeni bir düğüm oluşturur ve yeni düğümün adresini döndürür|t_list	*ft_lstnew(void *content)|
|ft_lstadd_front|new'i list'in başına ekler|void	ft_lstadd_front(t_list **lst, t_list *new)|
|ft_lstsize     |lst listesinin uzunluğunu döndürür|int	ft_lstsize(t_list *lst)|
|ft_lstlast     |lst listesinin son düğümünü döndürür|t_list	*ft_lstlast(t_list *lst)|
|ft_lstadd_back |new'i list'in sonuna ekler|void	ft_lstadd_back(t_list **lst, t_list *new)|
|ft_lstdelone    |gelen lst structının content'ini del fonksiyonuna gönderir ve lst structını freeler|void	ft_lstdelone(t_list *lst, void (*del)(void *))|
|ft_lstclear    |lst listesinin içindeki tüm düğümlerine del fonksiyonunu uygular ve düğümleri freeler|void	ft_lstclear(t_list **lst, void (*del)(void *))|
|ft_lstiter     |linked listin her bir contentini f fonksiyonuna uygular|void	ft_lstiter(t_list *lst, void (*f)(void *))|
|ft_lstmap      |lst’ listesi üzerinde dolaşır, ‘f’ fonksiyonunu listenin her elemanına uygular ve yeni elemenlardan yeni bir liste oluşturur |t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))|

<br></br>
