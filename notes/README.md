# Libft Projesi Notları

## İçerik
1. [`typedef` nedir?](#typedef-nedir)
2. [`size_t` ne demek?](#size_t-ne-demek)
3. [`const` nedir?](#const-nedir)
4. [`src + i` ifadesi nedir?](#src--i-ifadesi-nedir)
5. [Type Casting (Tür Dönüştürme)](#type-casting-tür-dönüştürme)
6. [Char - Integer Dönüşümü : ASCII Temelli Yaklaşım](#char---integer-dönüşümü--ascii-temelli-yaklaşım)
7. [`malloc` Kullanımı ve Heap Bellek](#malloc-kullanımı-ve-heap-bellek)
8. [Tür Dönüşümü ile `malloc` Kullanımı: Bellek Ayırma ve Veri Türü Uyumu](#tür-dönüşümü-ile-malloc-kullanımı-bellek-ayırma-ve-veri-türü-uyumu)
9. [File Descriptor (FD) ve `open` Fonksiyonu: Dosya Açma Modları ve Seçenekleri](#file-descriptor-fd-ve-open-fonksiyonu-dosya-açma-modları-ve-seçenekleri)
	- [File Descriptor (FD)](#file-descriptor-fd)
	- [`open` Fonksiyonu ve Dosya Açma Seçenekleri](#open-fonksiyonu-ve-dosya-açma-seçenekleri)
11. [`struct` nedir?](#struct-nedir)
	- [`struct pointer` nedir ve neden kullanılır?](#struct-pointer-nedir-ve-neden-kullanılır)
	- [`struct`'larda Operatörler ve Kullanımları](#structlarda-operatörler-ve-kullanımları)
		- [Nokta (Point) Operatörü (.)](#nokta-point-operatörü-)
		- [Ok İşareti (Arrow) Operatörü (-\>)](#ok-i̇şareti-arrow-operatörü--)
		- [Operatörler Hakkında Ek Bilgiler](#operatörler-hakkında-ek-bilgiler)
12. [Bağlı Liste ve Node Nedir?](#bağlı-liste-ve-node-nedir)
13. [Fonksiyonlar Hakkında Satır Açıklamaları](#fonksiyonlar-hakkında-satır-açıklamaları)
	- [`is` ile başlayan fonksiyonlar : Neden `int` veri tipi ile argüman alınır?](#is-ile-başlayan-fonksiyonlar--neden-int-veri-tipi-ile-argüman-alınır)
	- [`ft_memset` : Neden `void *b` tanımlandıktan sonra `unsigned char *b` tanımlıyoruz?](#ft_memset--neden-void-b-tanımlandıktan-sonra-unsigned-char-b-tanımlıyoruz)
	- [`ft_memcpy` : `if (dst == src)` ve `else if (ds > sr)`kod satırlarında yer alan dizilerin karşılaştırılmaları nasıl yapılıyor?](#ft_memcpy--if-dst--src-ve-else-if-ds--srkod-satırlarında-yer-alan-dizilerin-karşılaştırılmaları-nasıl-yapılıyor)
	- [`ft_memmove` ve `ft_memcpy` : Overloop Durumu](#ft_memmove-ve-ft_memcpy--overloop-durumu)
	- [`ft_strlcpy` : fonksiyon açıklaması, `ft_strlen(src)`kullanımı ve `size - 1` yazımı](#ft_strlcpy--fonksiyon-açıklaması-ft_strlensrckullanımı-ve-size---1-yazımı)
	- [`ft_strmapi` : `f(i, s[i])` anlamı](#ft_strmapi--fi-si-anlamı)
	- [`libft.h` : bonus kısmında eklenmesi zorunlu `struct` açıklaması](#libfth--bonus-kısmında-eklenmesi-zorunlu-struct-açıklaması)
	- [`ft_lstnew` : neden `t_list *ft_lstnew` şeklinde fonksiyonu tanımlıyoruz?](#ft_lstnew--neden-t_list-ft_lstnew-şeklinde-fonksiyonu-tanımlıyoruz)
	- [`ft_lstdelone` : `del` fonksiyonu nasıl kullanılır?](#ft_lstdelone--del-fonksiyonu-nasıl-kullanılır)
14. [Makefile](#makefile)
	- [Derleyici](#derleyici)
		- [Derleme Adımları](#derleme-adımları)
		- [Linker (Bağlayıcı)](#linker-bağlayıcı)
		- [Statik Kitaplık](#statik-kitaplık)
	- [Makefile Dosya İçeriği (Basic)](#makefile-dosya-i̇çeriği-basic)

<br></br>

# `typedef` nedir?
`typedef`, C ve C++ gibi programlama dillerinde kullanılan bir deklarasyon (bildirme) yönergesidir. `typedef`, mevcut bir veri türünün (örneğin, int, float, char gibi) adını değiştirerek veya kullanımını kolaylaştırarak yeni bir veri türü oluşturmak için kullanılır. Bu, kodun daha anlaşılır olmasını sağlamak ve tekrar eden karmaşık veri türlerini basitleştirmek için yaygın olarak kullanılan bir tekniktir.

Örnek olarak, `typedef`, özel veri türleri oluştururken de kullanılabilir. Örneğin:

```c
#include <stdio.h>

typedef int Marks;	// Yeni bir veri türü tanımlama

int main()
{
    Marks math = 90;
    Marks physics = 85;

    printf("Math: %d, Physics: %d\n", math, physics);

    return 0;
}
```

Bu örnekte, `typedef` ile `int` türüne `"Marks"` adını veriyoruz. Sonrasında, `Marks` türünü kullanarak iki farklı dersin notlarını depoluyoruz. Bu şekilde, daha anlamlı ve semantik açıdan zengin bir kod elde edilir.

<br></br>

# `size_t` ne demek?

C'de `size_t`, nesnelerin boyutunu bayt cinsinden temsil etmek için kullanılan işaretsiz bir tamsayı türüdür. En fazla limite sahip int türlerinin kendi limitini aşabilen bir boyut olamayacağını belirtir.

`size_t`, `unsigned int` 'in `typedef`'idir:
```c
typedef unsigned int size_t;
```

`size_t` veri türü, bir nesnenin boyutunu temsil etmek için kullanılır. `sizeof` operatörü, bir nesnenin boyutunu bayt cinsinden döndürür.
<br> </br>
**Gereksinimler:**
* **Başlık Dosyası:** `<stddef.h>` ve `<stdlib.h>` başlık dosyalarından birini tanımlayarak kullanabilir.
* **`printf()`:** Bir nesnenin boyutunu yazdırmak için `%zu` biçim belirleyicisi kullanılır. `%zu`, derleyiciye `printf()` işlevinin argümanının `size_t` türünde olduğunu söyleyen bir uzunluk değiştiricisidir.

     *Örnek:  `printf("%zu", ft_strlen("nisa"));`*
<br> </br>

**`size_t` türü, aşağıdakiler de dahil olmak üzere çeşitli amaçlar için kullanılır:**

* Dizilerin, bellek bloklarının ve dizilerin boyutunu temsil etmek için.
    ```c
    int *array = malloc(10 * sizeof(int));
    size_t array_size = sizeof(array) / sizeof(int);
    ```
* Bilinmeyen boyuttaki nesneler üzerinde çalışan işlevlere yönelik bağımsız değişkenlerin boyutunu belirtmek ve işlevlerden değer döndürmek için.
    ```c
    int strlen(char *str)
    {
        size_t len = 0;
        while (*str != '\0')
        {
            len++;
            str++;
        }
        return len;
    }
    ```
* Diziler ve dizeler üzerinde yineleme yapmak için.
    ```c
    for (size_t i = 0; i < array_size; i++)
        printf("The value of element %d is %d\n", i, array[i]);
    ```
<br> </br>
`size_t` türü tipik olarak işaretsiz bir uzun tamsayıdır, ancak uygulamaya bağlı olarak farklı bir tür olabilir. Örneğin `size_t`; 32 bit sistemde `unsigned int` olabilirken, 64 bit sistemde `unsigned long long int` olabilir.

`size_t` türü, bellekteki herhangi bir nesnenin boyutunu temsil edecek kadar büyük olması garanti edildiğinden kullanılır ve C dilinde boyutu bilinmeyen nesnelerle çalışmak için kullanışlı bir araçtır. `size_t` kullanarak, programlarınızın taşınabilir olmasını ve her boyuttaki nesneyi işleyebilmesini sağlayabilirsiniz.

<br> </br>

# `const` nedir?

C'deki `const` anahtar sözcüğü, değişkenlere, işaretçilere ve işlevlere uygulanabilen bir tür niteleyicisidir. Derleyiciye değişkenin, işaretçinin veya işlevin değerinin değiştirilmemesi gerektiğini söyler.
<br> </br>
`const` anahtar kelimesi, C kodunda çeşitli yerlerde kullanılabilir. Yaygın kullanım alanları:

* **Sabit Değişkenleri Bildirme:**

    ```c
    const int MAX_VALUE = 100;
    ```

    Bu, "MAX_VALUE" değişkenini sabit olarak bildirir. "MAX_VALUE" değeri, başlatıldıktan sonra değiştirilemez.
<br> </br>
* **Sabit İşaretçileri Bildirme:**

    ```c
    const char *str = "Merhaba dünya!";
    ```

    Bu, `str` işaretçisini sabit bir işaretçi olarak bildirir. `str` işaretçisinin değeri değiştirilemez, ancak işaretçinin kendisi değiştirilebilir.

    `s` işaretçisinin kendisi değiştirilebilir, çünkü `const` anahtar sözcüğü yalnızca işaretçinin değeri için geçerlidir, işaretçinin kendisi için geçerli değildir. Bu, `s` işaretçisine yeni bir değer atanabileceği veya artırılabileceği veya azaltılabileceği anlamına gelir.

    Örneğin, aşağıdaki kod geçerlidir:

    ```c
    const char *s = "Merhaba dünya!";

    printf("%s", (char *)s);         // Çıktı: Merhaba dünya!

    s = "Hoşçakal dünya!"; // işaretçinin değerini değiştirdiği için geçerli

	printf("%s", (char *)s);        // Çıktı: Hoşçakal dünya!
	printf("%s", s);                // Çıktı: Hoşçakal dünya!
    ```

    Ancak, aşağıdaki kod geçerli değildir:

    ```c
    const char *s = "Merhaba dünya!";

    s[0] = 'a'; // İşaretçi tarafından işaret edilen karakterin değerini değiştirmeye çalıştığı için geçerli değil
    ```

    Geçerli olmamasının nedeni, `const` anahtar sözcüğünün derleyiciye `s` değerinin değiştirilmemesi gerektiğini söylemesidir.

    `const` anahtar sözcüğü, verilerde yanlışlıkla değişiklik yapılmasını önlemenin kullanışlı bir yoludur. Ancak, `const` anahtar sözcüğünün işaretçinin kendisinin değiştirilmesini engellemediğini anlamak önemlidir. Belirli değerlerin değiştirilmemesi gerektiğini netleştirerek kodun okunabilirliğini artırmak için de kullanılabilir.
<br> </br>
* **Sabit İşlevleri Bildirme:**

    ```c
    const int strlen(const char *s)
    {
        int len = 0;
        while (*s != '\0')
        {
            len++;
            s++;
        }
        return (len);
    }
    ```

    Bu, `strlen` fonksiyonunu sabit bir fonksiyon olarak ilan eder. `strlen` işlevi kendisine iletilen dizeyi değiştiremez.

    İşlev bildirimindeki `const char *s`, `s`'nin sabit bir karaktere işaretçi olduğu anlamına gelir. Bu, `s` tarafından işaret edilen karakterin değerinin değiştirilemeyeceği, ancak `s` işaretçisinin kendisinin değiştirilebileceği anlamına gelir.
<br> </br>

**`const` anahtar sözcüğünü kullanmanın yararları:**

* **Hataların önlenmesine yardımcı olabilir:** `const` anahtar kelimesi, verilerde yanlışlıkla değişiklik yapılmasını önleyerek koddaki hataların önlenmesine yardımcı olabilir.
* **Okunabilirliği artırabilir:** `const` anahtar kelimesi, belirli değerlerin değiştirilmemesi gerektiğini açıkça belirterek kodun okunabilirliğini artırabilir.
* **Performansı artırabilir:** Bazı durumlarda, `const` anahtar sözcüğü, derleyicinin kodu optimize etmesine izin vererek kodun performansını artırabilir.

Genel olarak, `const` anahtar sözcüğü, C kodunun kalitesini artırmak için kullanılabilecek güçlü bir araçtır.

<br></br>

# `src + i` ifadesi nedir?

`src + i` ifadesi belirli bir elemana veya belirli index'ten sonra diziye ulaşmak için kullanılır.

```c
#include <stdio.h>

int main()
{
	char *src = "Hello, world!";

	char c = *(src + 2);
	int i = *(src + 2);

	printf("%c\n", c);        // Çıktı: l  (veri tipi: char)
	printf("%c\n", i);        // Çıktı: l  (veri tipi: int)
	printf("%s\n", src + 2);  // Çıktı: llo, world!  (veri tipi: char * yani bir dizin)
}
```

Belirtilen koda göre;
* `char` olarak tanımlanan `c` için `src + 2`, src dizisinin 2.indexine eriş demektir.
* `int` olarak tanımlanan `i` 'nin çıktısı ise `char c` ile aynıdır. Çünkü `int` veri tipi bütün karakterleri içerisinde saklayabilir.
* Eğer ki `src`'nin 2.indexinden itibaren yazdırılmasını istiyorsanız `printf("%s\n", src + 2);` diyebilirsiniz. `src` bir dizin olduğundan çıktınızda bir dizin olur.

<br></br>


# Type Casting (Tür Dönüştürme)
Tür dönüştürme veya `type casting`, programlama dillerinde bir veri türünü başka bir veri türüne dönüştürme işlemidir. Bu işlem, bir değişkenin veya ifadenin türünü değiştirmek amacıyla kullanılır. Program içerisinde farklı veri türleri arasında dönüşüm yaparken veya bir ifadeyi farklı bir türde kullanırken bu tür dönüştürmeler genellikle gereklidir.

Programlama dilleri, genellikle otomatik tür dönüşümü yapabilir. Örneğin, bir `int` değeri bir `float` değerine atanırken otomatik olarak dönüşüm gerçekleştirilebilir. Ancak, bazen açıkça bir tür dönüştürme yapmak gerekebilir. Bu durumda, tür dönüştürmesi yapmak için `type cast` operatörü kullanılır.

```c
float x = 2.42;
int y = (int)x; // 'x' değişkeni int türüne dönüştürülüyor
```

Bu örnekte, `(int)x` ifadesi x değişkeninin `float` türünden `int` türüne dönüştürülmesini sağlar.

Type casting dikkatli kullanılmalıdır çünkü türler arasında anlamsal veya hassasiyet farkları olabilir ve yanlış tür dönüştürmeleri hatalara neden olabilir. Bu nedenle, tür dönüştürmeleri yapmadan önce dikkatli bir şekilde değerlendirilmeli ve gerekliliği doğrulanmalıdır.

<br></br>

# Char - Integer Dönüşümü : ASCII Temelli Yaklaşım
C programlama dilinde, bir `karakter (char)` değerini bir `tamsayıya (int)` dönüştürmek oldukça yaygın bir işlemdir. Özellikle rakam karakterlerini (örneğin, '0', '1', ..., '9') tamsayılara dönüştürmek için sıkça kullanılır. Bu dönüşüm işlemi, karakterlerin ASCII kodlamasını temel alır. Her karakterin ASCII tablosunda bir sayı değeri vardır.

Örneğin, `'2'` karakterini bir tamsayıya dönüştürmek istediğimizi düşünelim:

1. Karakter `'2'` ile karakter `'0'` arasındaki farkı buluruz: `'2' - '0' = 50 - 48 = 2`
2. Bu fark, karakter `'2'` nin ASCII değeri olan `50` ile karakter `'0'` ın ASCII değeri olan `48` arasındaki farkı temsil eder.
3. Sonuç olarak, `'2'` karakterini tamsayı olarak `2` olarak elde ederiz.

Bu basit aritmetik işlem sayesinde, rakam karakterlerini tamsayılara dönüştürebiliriz. Bu yöntem sayesinde karakterlerin tamsayılara dönüştürülmesi hızlı ve etkili bir şekilde gerçekleştirilebilir.

<br></br>

# `malloc` Kullanımı ve Heap Bellek

`malloc` fonksiyonu, programın çalışma zamanında dinamik bellek tahsisi yapmak için kullanılan bir işlevdir. Bellek tahsisi, programın çalışma sırasında ihtiyaca göre bellek alanı ayırmak anlamına gelir. Bu, programın derleme sırasında sabit boyutta bellek tahsis etmek yerine, ihtiyaca göre esnek bir şekilde bellek ayırmasını sağlar.

Bellek tahsis edilen bu alan, **"heap"** adı verilen bellek bölgesinde yer alır. **Heap**, programın çalışma zamanında dinamik olarak yönetilen bir bellek alanıdır. Veriler ve nesneler genellikle heap bellek alanında saklanır ve bu alanın boyutu çalışma zamanında belirlenir.

`malloc` fonksiyonu, bellekte dinamik olarak bir alan ayırır ve bu bellek bloğunun başlangıç adresini (pointer'ı) döndürür. Ayırdığınız bellek bloğunu kullanabilmeniz için bu başlangıç adresini bir pointer değişkenine atamanız gerekmektedir. Yani, malloc'un döndürdüğü bellek adresini bir pointer ile saklamanız, o bellek bloğuna erişim sağlamak için gereklidir. Bunun nedeni şunlardır:

* **Bellek Erişimi:** Ayırdığınız bellek bloğuna erişmek ve içeriği değiştirmek için bir pointer gereklidir. Pointer, bellek bloğunun başlangıç adresini tutar ve bu adresi kullanarak belleğe erişim sağlar.
* **Bellek Kontrolü:** Bellek bloğunun ne kadar alan kapladığını ve ne kadar kullanıldığını takip etmek önemlidir. Pointer, başlangıç adresini sakladığı için, malloc ile ayırdığınız bellek bloğunu kontrol etmenizi sağlar ve gerektiğinde belleği serbest bırakmanızı sağlar.
* **Bellek Serbest Bırakma:** malloc ile ayrılan bellek bloğunu programın bitiminden önce serbest bırakmanız gerekmektedir. Bu, bellek sızıntılarını önlemek için önemlidir. Belleği serbest bırakmak için de bellek bloğunun başlangıç adresine erişim sağlayan bir pointer kullanmanız gerekir.

Aşağıda, malloc ve heap bellek alanını kullanarak bir örnek bulunmaktadır:

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    int size = 12;

    ptr = (int *)malloc(size * sizeof(int));   // Bellekte 12 tane int boyutunda alan ayır

    if (ptr == NULL)
	{
        printf("Bellek tahsisi başarısız.\n");
        return 1;
    }

    for (int i = 0; i < size; i++)   // Bellekte ayrılan alana veri koy
        ptr[i] = i * 2;

    for (int i = 0; i < size; i++)   // Verileri ekrana yazdır
        printf("%d ", ptr[i]);
    printf("\n");

    free(ptr);   // Belleği serbest bırak

    return 0;
}
```

Bu örnekte, `malloc` ile 12 tane `int` boyutunda bellek alanı ayarlanır. Bu alan, heap bellek bölgesinde yer alır. Ardından bu alana veriler atanır ve veriler ekrana yazdırılır. Son olarak, bellek `free` fonksiyonuyla serbest bırakılır.

**Heap bellek** alanının kullanımı, programın çalışma süresi boyunca dinamik olarak büyütülüp küçültülebilir. Bu, programın ihtiyacına bağlı olarak bellek kullanımını optimize etmesine olanak tanır. Ancak, **heap belleğin** düzgün yönetilmesi önemlidir; belleği kullanıldıktan sonra mutlaka serbest bırakmak gerekir, aksi takdirde **bellek sızıntıları (memory leaks)** oluşabilir.

<br></br>

# Tür Dönüşümü ile `malloc` Kullanımı: Bellek Ayırma ve Veri Türü Uyumu

Dinamik bellek yönetimi, C programlamada önemli bir bileşen olup, `malloc` fonksiyonu bu alanda kullanılan temel araçlardan biridir. Ancak, `malloc` fonksiyonu `void *` türünde bir bellek bloğu döndürür. Bu bloğun hangi türde veriyi temsil ettiğini bilemediğimiz için, bu bellek bloğunu kullanmadan önce uygun veri türüne dönüştürmemiz gerekmektedir. Bu süreç, `tür dönüşümü (type casting)` olarak adlandırılır.

**1. Tür Dönüşümü ve Malloc Kullanımı**
```c
int *ptr;
ptr = (int *) malloc(sizeof(int));
```
	Yukarıdaki örnekte, `malloc` fonksiyonu bir `int` veri türü için gereken bellek miktarını hesaplar ve bu miktar kadar bellek alanı ayırır. Ardından, `malloc`'ın döndürdüğü `void *` türündeki bellek adresini, `int *` türüne dönüştürerek `ptr` adlı işaretçiye atarız.

**2. Güvenli ve Doğru Veri Kullanımı**

	Bu tür dönüşümü, programın derleyiciye, bellek bloğunun hedeflenen veri türünde olduğunu belirtmesini sağlar. Ancak, bu dönüşüm gerçekte bu türde veri olduğunu garanti etmez. Bu nedenle, malloc ile ayrılan bellek bloğunu kullanmadan önce, hedeflenen veri türünün gerektirdiği şekilde kullanıldığından emin olmalıyız.

**3. Sonuç Olarak**

	`malloc` fonksiyonu ve tür dönüşümü, dinamik bellek ayırma işlemlerinde veri türü uyumunu sağlamamıza yardımcı olan önemli araçlardır. Bu kombinasyon, bellek yönetimi ve güvenli veri işlemi açısından programlarınızı daha sağlam hale getirir.

<br></br>

# File Descriptor (FD) ve `open` Fonksiyonu: Dosya Açma Modları ve Seçenekleri

## File Descriptor (FD)
File Descriptor (FD), Unix benzeri işletim sistemlerinde dosyaları ve soketleri temsil etmek için kullanılan bir tamsayıdır. Bir program, bir dosyaya veya bir giriş/çıkış kaynağına erişmek istediğinde bu dosya tanımlayıcısını kullanır. FD, işletim sistemi çekirdeği ile kullanıcı programı arasındaki iletişimi sağlar.

**File Descriptorlar genellikle şu şekillerde kullanılır:**

 * `0`: Standart giriş `(stdin)`
 * `1`: Standart çıkış `(stdout)`
 * `2`: Standart hata `(stderr)`

Aynı zamanda bu ön tanımlı FD'lerden sonraki sayılar, program tarafından açılan dosya veya soketler için kullanılır. Her açılan dosya veya soket, bir FD numarasına atanır. Örneğin, bir program birden fazla dosyaya veya sokete erişiyorsa, her birinin kendine ait bir FD'si olacaktır.
<br></br>

## `open` Fonksiyonu ve Dosya Açma Seçenekleri
Dosya işlemleri yaparken, open fonksiyonu kullanılarak dosya açma işlemi gerçekleştirilir. open fonksiyonu dosyayı açarken kullanılan modları ve seçenekleri belirlemek için flags (bayraklar) parametresini kullanır. Bu bayraklar, dosya açma modunu ve seçeneklerini belirler.

Örnek open fonksiyonu kullanımı:

```c
#include <fcntl.h>

int main()
{
    int fd = open("dosya.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (fd == -1)
	{
        perror("Dosya açma hatası");
        return 1;
    }

    // Dosyaya veri yazma ve kapatma işlemleri

    close(fd);
    return 0;
}
```

`flags` parametresinde kullanılan bazı yaygın seçenekler şunlardır:

* `O_RDONLY`: Sadece okuma modunda dosya açar.
* `O_WRONLY`: Sadece yazma modunda dosya açar.
* `O_RDWR`: Hem okuma hem de yazma modunda dosya açar.
* `O_CREAT`: Eğer dosya mevcut değilse, yeni bir dosya oluşturur.
* `O_APPEND`: Dosyanın sonuna veri eklemek için kullanılır.
* `O_TRUNC`: Dosya açıldığında içeriğini siler (kırpma).
* `O_EXCL`: Eğer `O_CREAT` ile birlikte kullanılıyorsa ve dosya zaten mevcutsa hata verir.
* `O_SYNC` veya `O_DSYNC`: Eşzamanlı dosya yazmalarını yaparken, verinin fiziksel olarak diske yazılmasını sağlar.
* `O_NONBLOCK` veya `O_NDELAY`: Bloklanmadan dosya veya soket açmayı dener.
* `O_CLOEXEC`: Dosya açıldığında exec işlevi çağrıldığında otomatik olarak kapatılır.

`mode` parametresi ise, `O_CREAT` seçeneği ile yeni bir dosya oluşturulduğunda kullanılacak izinleri belirler. Bu parametre, okuma (r, sayısal karşılığı: 4), yazma (w, sayısal karşılığı: 2) ve çalıştırma (x, sayısal karşılığı: 1) izinlerini belirtmek için oktallarla ifade edilen bir sayıdır.

<br></br>

# `struct` nedir?

`struct (structure)`, farklı veri tiplerini bir araya getirerek kendi veri tipinizi oluşturmanızı sağlayan bir yapıdır. Bu, farklı türlerdeki verileri tek bir yapı içinde gruplayarak daha düzenli ve anlamlı veri yapıları oluşturmanızı sağlar. Örneğin; bir kişinin adını, yaşını ve telefon numarasını saklamak için bir struct oluşturabilirsiniz.

struct yapısını tanımlamak:

```c
struct Person {
    int		age;
    char	name[50];
    char	phone[15];
};
```

Oluşturduğunuz struct yapısını kullanmak için, struct türünden değişkenler oluşturabilir ve bu değişkenler üzerinden veri elemanlarına erişebilirsiniz. Örneğin, "Person" struct'ınızı kullanarak bir kişiyi temsil eden bir değişken oluşturabilirsiniz. Bu değişken üzerinden struct'ın veri elemanlarına erişebilir ve bu verileri kullanabilirsiniz.

Önceki örnekteki "struct Person" yapısını kullanarak bir kişiyi temsil eden bir değişken oluşturmak:

```c
struct Person person1;
```

"person1" değişkeninin veri elemanlarına erişerek yeni veriler atamak:
```c
person1.age = 22;
strcpy(person1.name, "Venus");      // strcpy ile karakter dizisi kopyalaması yapılmalı
strcpy(person1.phone, "121-212";);  // strcpy ile karakter dizisi kopyalaması yapılmalı
```

Struct'lar C programlama dilinde veri yapılarını düzenlemek ve yönetmek için kullanışlıdır.

`struct` 'ların yaygın kullanım alanları:
* Karmaşık veri yapılarını temsil etmek
* Veriyi gruplamak
* Veriyi yönetmek

<br></br>

## `struct pointer` nedir ve neden kullanılır?

<br>

`Struct pointer`, bir struct türündeki veri yapısının bellek adresini tutan bir göstericidir. Bu pointer, struct'ın elemanlarına erişim sağlamak için kullanılır. `Struct pointer`'ları, struct'ın veri elemanlarına direkt olarak değil, o struct'ın bellek adresine işaret ederek erişim sağlar.

Bir fonksiyona struct'ı adres olarak göndermenin temel nedeni, struct'ın kopyasını oluşturmak yerine doğrudan orijinal struct üzerinde işlem yapma yeteneğini elde etmektir. C programlama dilinde fonksiyonlara argümanlar geçirildiğinde, argümanlar varsayılan olarak değer kopyaları olarak aktarılır. Bu, fonksiyonun aldığı argümanın kopyasının fonksiyon içerisinde oluşturulduğu ve bu kopya üzerinde işlem yapıldığı anlamına gelir.

Ancak, struct pointer'ları kullanarak struct'ın bellek adresini fonksiyona aktarabilirsiniz. Bu sayede, fonksiyon, bu bellek adresine sahip struct'ın orijinal verisine erişebilir ve bunun üzerinde değişiklikler yapabilir.

`struct pointer`'ları ile bir fonksiyona struct'ın adresini gönderme nedenleri:

* **Bellek ve Performans Tasarrufu:** Struct'ın kopyasını oluşturmak yerine, adresi üzerinden erişim yaparak gereksiz bellek kopyalamasını önleriz. Bu daha hızlı çalışmaya ve bellek kullanımında tasarrufa yol açar.
* **Veri Değişiklikleri:** Fonksiyon içerisinde struct'ın içeriğine yapılan değişiklikler, orijinal struct üzerinde de etki eder. Bu, fonksiyonun sonuçlarından dönen struct veya değer dönüşlerine gerek kalmadan veri değişikliklerini elde etmenizi sağlar.
* **Karmaşık Veri Yapıları:** Struct'lar genellikle karmaşık veri yapılarını temsil eder. Bu veri yapıları büyük olabilir ve bunları kopyalamanın maliyeti yüksek olabilir. Struct pointer'ları kullanarak, fonksiyonlara bu karmaşık veri yapılarını daha verimli bir şekilde aktarabilirsiniz.

<br></br>

## `struct`'larda Operatörler ve Kullanımları

<br>

`Struct`'ların ve `struct pointer`'larının üyelerine erişmek için kullanılan operatörler vardır. Bu operatörlerin işlevleri ve nasıl kullanıldıkları şu şekildedir:

<br>

### Nokta (Point) Operatörü (.)
---
Nokta operatörü, bir struct değişkeninin veya structın kendisinin veri elemanlarına erişmek için kullanılır. Yani, struct değişkeni tanımlandığında doğrudan kullanılır.

```c
// Point isminde ve içerisinde 2 tane int tipinde değişken olan bir struct tanımladık
struct Point {
    int x;
    int y;
};

// struct Point tipini kullanan p1 adında bir değişken oluşturduk
struct Point p1;

// p1 değişkenine ait x değerini 10, y değerini 20 olarak atadık
p1.x = 10;
p1.y = 20;
```

<br>

### Ok İşareti (Arrow) Operatörü (->)
---
Ok işareti operatörü, `struct pointer`'larının gösterdiği bellek alanlarındaki veri elemanlarına erişmek için kullanılır. Yani, `struct pointer`'ı üzerinden elemanlara erişilir.

```c
// Point isminde ve içerisinde 2 tane int tipinde değişken olan bir struct tanımladık
struct Point {
    int x;
    int y;
};

struct Point p1;

// ptr değişkenine p1 adresini atayarak işaret ediyoruz
struct Point *ptr = &p1;

// p1 değişkeninin x değeri 30, y değeri 40 olacaktır
ptr->x = 30;
ptr->y = 40;
```
Burada ptr adında bir `struct pointer`'ı tanımlandı ve ptr ile `struct`'ın elemanlarına erişilmiştir.

Özet: Nokta operatörü bir struct değişkeninin elemanlarına erişmek için kullanılırken, ok işareti operatörü struct pointer'larının gösterdiği bellek alanlarındaki elemanlara erişmek için kullanılır.

<br>

### Operatörler Hakkında Ek Bilgiler
---

Eğer bir struct pointer'ı kullanıyorsanız, ok işareti operatörü (->) ile erişim yapmanız gerekmektedir. Nokta operatörü (.) yalnızca struct değişkenlerine uygulanabilir.

Doğru erişim şekilleri:

* Struct değişkeni: `p1.x = 12;`
* Struct pointer'ı: `ptr->x = 12;`

<br>

**p1->x = 12 şeklinde atama yapamaz mıyım?**
<br>

Hayır. Doğru erişim şekli p1.x olmalıdır. Struct değişkenlerine nokta operatörü (.) ile erişilirken, struct pointer'larına (ptr) ok işareti operatörü (->) ile erişilir.

Yani, p1->x = 12; şeklinde erişim yapılamaz, bunun yerine p1.x = 12; şeklinde erişim yapmanız gerekmektedir.

<br></br>

# Bağlı Liste ve Node Nedir?

<br>

Bağlı liste (linked list), veri elemanlarını (veri) ve bu elemanların bir sonraki elemanın adresini (bağ) içeren düğümlerden oluşan bir veri yapısıdır. Bu yapı, veri elemanlarını sıralı bir şekilde saklamak ve manipüle etmek için kullanılır. Her düğüm, veriyi saklamak için kullanılan bir alan ve bir sonraki düğümün adresini tutan bir alan içerir. Bu sayede elemanlar arasında sıralı bir ilişki oluşturulur.

Bağlı listeler, veri ekleme, çıkarma ve manipülasyon işlemlerini etkili bir şekilde gerçekleştirmenizi sağlar.

<br>

Bağlı listelerin temel bileşenleri:
* **Düğüm (Node):** Bir veri elemanını saklayan, bir sonraki düğümün adresini içeren yapılardır. Her düğüm, en az iki bileşen içerir: veri elemanı ve bir sonraki düğümün adresi. Düğümler verileri sakladığı gibi, birbiriyle bağlantı kurarak liste oluştururlar.
* **Veri (Data):** Her düğümde saklanan gerçek veriyi ifade eder. Bu veri, bağlı listenin amacına göre farklı tipte olabilir (örneğin, tam sayı, metin, yapılardan oluşan veri vb.).
* **Bağ (Link):** Düğümler arasındaki ilişkiyi ifade eder. Bir düğümün bir sonraki düğümünü gösteren bir referans içermesi, düğümleri birbirine bağlar.

<br>

Bağlı listelerin türleri:
* **Tek Yönlü Bağlı Liste (Singly Linked List):** Her düğüm, sadece bir sonraki düğümün adresini içerir. Listenin sonu, son düğümün sonraki düğümünü temsil eden bir gösterge (NULL) ile belirtilir. Burada her düğümde bir veri elemanı ve bir sonraki düğümün adresi bulunur. Örneğin, 1 numaralı düğümün verisi 1'dir ve bir sonraki düğüm olan 2 numaralı düğümü işaret eder. Aynı şekilde, 2 numaralı düğümün verisi 2'dir ve bir sonraki düğüm olan 3 numaralı düğümü işaret eder, ve böyle devam eder.
  ```rust
  1 -> 2 -> 3 -> 4 -> NULL
  ```
* **Çift Yönlü Bağlı Liste (Doubly Linked List):** Her düğüm, hem bir sonraki düğümün hem de önceki düğümün adresini içerir. Bu, düğümlerin hem ileri hem de geri yönde gezinilebilmesini sağlar.
  ```rust
  NULL <- 1 <-> 2 <-> 3 <-> 4 <-> 5 -> NULL
  ```
* **Dairesel Bağlı Liste (Circular Linked List):** Tek yönlü veya çift yönlü bağlı listenin son düğümü, ilk düğümü işaret eder. Böylece liste döngüsel bir yapıya sahip olur.
  ```rust
  1 -> 2 -> 3 -> 4 -> 5 -> 1
  ```


<br></br>

# Fonksiyonlar Hakkında Satır Açıklamaları

<br>

## `is` ile başlayan fonksiyonlar : Neden `int` veri tipi ile argüman alınır?

C'de `is` ile başlayan işlevler, kontrol ettikleri koşullar tipik olarak tamsayılar olarak temsil edildiğinden, genellikle `int` türünde bağımsız değişkenler alır. Bunun nedeni, C'deki tüm veri türlerinin tamsayı eşdeğerlerinin olması ve `int`'in en temel veri türü olmasıdır. `int`, temel ASCII tablosunda olmayanlar da dahil olmak üzere tüm karakterleri saklayabilir. Bu nedenle, bu işlevler için bağımsız değişken türü olarak `int` kullanılması, derleyicinin diğer veri türleriyle mümkün olmayan optimizasyonlar gerçekleştirmesini sağlar.
<br></br>

## `ft_memset` : Neden `void *b` tanımlandıktan sonra `unsigned char *b` tanımlıyoruz?

`ft_memset()` işlevi, ilk bağımsız değişkeni olarak boşluğa bir işaretçi alır. Bu, işaretçinin karakterler, tamsayılar ve işaretçiler dahil olmak üzere herhangi bir veri türüne işaret edebileceği anlamına gelir. Bununla birlikte, `ft_memset()` işlevi yalnızca karakterlerle çalışır, bu nedenle, kullanabilmesi için önce bir karakter işaretçisine geçersiz işaretçi atması gerekir.

`((unsigned char *)b)[i++] = c;` kodu, `b` geçersiz işaretçisini işaretsiz bir karaktere işaretçiye çevirir ve ardından bellekteki `i`nci karaktere erişmek için alt simge operatörünü kullanır. `b` ile gösterilen konum. Daha sonra `c`, `i`inci karaktere atanır.

Boşluk işaretçisi `b`'nin işaretsiz bir karaktere yönelik bir işaretçiye dönüştürülmesinin nedeni, alt simge operatörünün yalnızca türleri tamamlamak için işaretçilerle çalışmasıdır. `void` türü tamamlanmamış bir türdür, bu nedenle derleyici, önce tam bir türe dönüştürmeden bir geçersiz işaretçide alt simge işlecini kullanamaz.

Bu durumda, geçersiz işaretçinin kullanıldığı tam tür `unsigned char`'dır. Bunun nedeni, `ft_memset()` işlevinin yalnızca karakterlerle çalışması ve karakterlerin bellekte işaretsiz karakterler olarak saklanmasıdır.
<br></br>

## `ft_memcpy` : `if (dst == src)` ve `else if (ds > sr)`kod satırlarında yer alan dizilerin karşılaştırılmaları nasıl yapılıyor?
if (dst == src) ve else if (ds > sr) ifadeleri, ft_memcpy fonksiyonunun içinde hedef (destination) ve kaynak (source) bellek bloklarının karşılaştırılmasını ifade eder.

1. `if (dst == src)` ifadesi: Bu ifade, hedef ve kaynak bellek bloklarının başlangıç adreslerinin aynı olup olmadığını kontrol eder. Eğer hedef ve kaynak bellek blokları aynı başlangıç adresine sahipse, bu durumda bellek blokları aynı olduğu için herhangi bir kopyalama işlemine gerek yoktur. Bu tür durumlar için genellikle bellek kopyalama işlemi yapılmadan işlevden çıkılır.
2. `else if (ds > sr)` ifadesi: Bu ifade, hedef bellek bloğunun başlangıç adresinin kaynak bellek bloğunun başlangıç adresinden büyük olduğu durumu kontrol eder. Eğer hedef bellek bloğu, kaynak bellek bloğundan daha yüksek adresli bir bölgede bulunuyorsa, bellek blokları birbirine üst üste bindiği için kopyalama işlemi güvenli bir şekilde yapılabilir. Bu durumda bellek blokları birbirini örtmediği ve hedef blokunun daha yüksek adresli olduğu varsayıldığından, bellek kopyalama işlemi doğru sonuç verecektir.
<br></br>

## `ft_memmove` ve `ft_memcpy` : Overloop Durumu
memcpy işlevi, bellekteki verilerin bir bellek bloğundan başka bir bellek bloğuna kopyalanmasını sağlar. Ancak, memcpy işlevinin kullanımında dikkat edilmesi gereken bir durum, kaynak ve hedef bellek blokları arasında bir overlap durumu olup olmadığıdır.

Eğer memcpy işlevinde kaynak ve hedef bellek blokları tamamen ayrık ve birbirinden bağımsız ise, yani herhangi bir örtüşme (overloop) yoksa, bir sorun oluşmaz ve veriler doğru şekilde kopyalanır.

Fakat, kaynak ve hedef bellek blokları arasında bir örtüşme (overloop) varsa (iki bellek bloğu birbirini kısmen veya tamamen içeriyorsa) memcpy işlevi tanımsız bir davranışa neden olur. Bu durumda, sonuç öngörülemez ve istenmeyen sonuçlar ortaya çıkabilir.

Overloop durumu, kaynak ve hedef bellek bloklarının adreslerinin ilişkisine bağlıdır.

Overloop durumunun oluşma koşulu:
* Kaynak bellek bloğunun adresi, hedef bellek bloğunun adresinden daha önceyse overloop durumu oluşur.
* Hedef bellek bloğunun adresi, kaynak bellek bloğunun adresinden daha önceyse, overloop durumu oluşur.

memmove işlevi, kaynak ve hedef arabelleklerinin overlap durumu olduğunda kullanılmalıdır. Memcpy işlevi yalnızca overlap durumu olmadığında kullanılmalıdır.
<br></br>

## `ft_strlcpy` : fonksiyon açıklaması, `ft_strlen(src)`kullanımı ve `size - 1` yazımı
src'yi dest'e kopyalama işlemi gerçekleştirir ve dest'in sonuna '\0' atayarak dest'i sonlandırır.

return (ft_strlen(src)); kullanılmasının nedeni, ft_strlcpy işlevinin dönüş değerinin kaynak dizinin uzunluğunu yansıtmasıdır.

ft_strlcpy işlevi, kaynak dizinin boyutunu dikkate alarak kopyalama işlemi yapar ve hedef dizinin sonuna null karakterini ekler. Sonuç olarak, hedef dizinin uzunluğu, kaynak dizinin uzunluğuna eşit olmayabilir. Bu nedenle, ft_strlen(dst) yerine ft_strlen(src) kullanılır.

Eğer `ft_strlen(dst)` kullanılsaydı, hedef dizinin boyutunu yansıtmayabilirdi çünkü `ft_strlcpy` işlevi, hedef dizinin tamamını doldurmayabilir. Bu nedenle, hedef dizisinin gerçek uzunluğunu elde etmek için `ft_strlen(src)` kullanılır.

`(size - 1)` kullanılmasının nedeni, hedef dizinin sonuna null karakterini eklemek için bir boşluk bırakmaktır. `ft_strlcpy` işlevi, kaynak diziyi hedef dizinin başına kopyalar ve hedef dizinin sonuna null karakterini ekler. size parametresi, hedef dizinin boyutunu belirtir. Eğer size parametresi 0 veya daha küçük bir değerse, hiçbir kopyalama işlemi yapılmaz ve sadece kaynak dizinin uzunluğu döndürülür.
<br></br>

## `ft_strmapi` : `f(i, s[i])` anlamı
`f(i, s[i])` ifadesi, genel olarak işlev/fonksiyon çağrısı anlamına gelir. Bu ifade içinde `i` ve `s[i]` sembolleri bulunur ve bunlar işlevin/fonksiyonun argümanları olarak kullanılır.
```c
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
```
`ft_strmapi`fonksiyonu yukarıda belirtildiği gibi yazılması istenilmiştir. Çağırılan fonksiyonun ilk girdisi `unsigned int` türünde, ikinci girdisi ise `char`türünde olmalıdır. Fonksiyonun dönüşü (return ettiği) `char *` olmalıdır. `main` dışında bu fonksiyon yazılmalıdır.
<br></br>

## `libft.h` : bonus kısmında eklenmesi zorunlu `struct` açıklaması
```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```
Bu kod parçası, C programlama dilinde bir bağlı liste veri yapısını (linked list) tanımlamak için kullanılır. Bu kod parçasında kullanılan terimlerin açıklamaları:

* `typedef`: C programında mevcut bir veri türünü yeniden adlandırmak için kullanılan bir anahtar kelimedir. Yani, `typedef`ile bir veri türüne kendi isimlerimizi verebiliriz.
* `t_list`: `typedef` anahtar kelimesi ile yapıya isim verilerek, bu yapıyı daha kısa ve kullanışlı bir şekilde kullanmamız sağlanır.
* `struct s_list`: Bu ifade, `s_list` adında bir yapı (structure) tipini tanımlar. Yapılar, farklı veri türlerinin bir araya getirilerek yeni bir veri yapısı oluşturulmasını sağlar.
* `void *content`: Bu ifade, `s_list` yapısının bir elemanıdır ve `void *` türünde bir işaretçi (pointer) olan `content` adında bir değişkeni temsil eder. Bu, bağlı listenin her bir elemanının içeriğini temsil etmek için kullanılır. `void *` türü, herhangi bir veri türüne işaret edebilen bir işaretçi türüdür.
* `struct s_list *next`: Bu ifade, `s_list` yapısının bir diğer elemanıdır ve bir sonraki bağlı listesinin elemanına işaret eden bir işaretçi olan `next` adında bir değişkeni temsil eder. Bu, bağlı listelerdeki elemanları birbirine bağlamak için kullanılır.

Kısacası, bu kod parçası bir bağlı liste veri yapısını tanımlar. Her eleman, içeriği `void *` türünde bir işaretçi olan `content` ve bir sonraki elemana işaret eden bir işaretçi olan `next` içerir. Bu yapının kullanımı, dinamik veri depolama ve elemanları bağlama gereksinimlerini karşılamak için oldukça yaygındır.
<br></br>

## `ft_lstnew` : neden `t_list *ft_lstnew` şeklinde fonksiyonu tanımlıyoruz?

Bir struct yapıları dizisi veya bağlı liste gibi veri yapıları oluşturmak istediğinizde, her bir elemanın farklı büyüklükte olabileceği durumlar söz konusu olabilir. Dinamik bellek tahsisi, her bir elemanın ihtiyaca göre ayarlanabilmesini sağlar. Bu yüzden `ft_lstnew` fonksiyonunu yazarken `malloc`kullanılmalıdır.

`ft_lstnew` fonksiyonunun dönüş değeri `t_list` türünde bir değişken değil, `t_list` türünden bir `struct pointer` (`t_list *`) olmalıdır.

Bunun nedeni, `ft_lstnew` fonksiyonunun dinamik bellek tahsis etmesi ve bu bellek bloğunun adresini döndürmesi gerektiğidir. Eğer `t_list` türünden bir struct değişkeni döndürürseniz, bellekte tahsis edilen alanın adresini geri döndürme imkanınız olmaz.

```c
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list)); // Bellek tahsis ediliyor
	if (!new)
		return (0);               // Bellek tahsisi başarısız olduysa 0 döndürülüyor
	new->content = content;
	new->next = NULL;
	return (new);                 // Yeni oluşturulan t_list yapısının adresi döndürülüyor
}
```

<br>

Kod açıklamaları:
* **`void *content` kullanılma nedeni:** ft_lstnew fonksiyonunun daha genel ve esnek olmasını sağlamak için kullanılır. void işaretçisi (void *) herhangi bir türdeki veriye işaret edebilir, bu nedenle fonksiyona farklı veri tiplerinde içerikleri iletebilmenizi sağlar. Bu yöntem, veri yapısıyla çalışırken tür uyumsuzluğunu gidermeye yardımcı olur ve fonksiyonun daha geniş bir kullanım alanına sahip olmasını sağlar.
* **`new`'in `t_list *` türünde olmasının nedeni:** `malloc` ile `t_list` boyutunda bellekte yer ayırmasını gerçekleştirdikten sonra bir pointer'a atamak gereklidir (Bunun nedenini **["`malloc` Kullanımı ve Heap Bellek"](#malloc-kullanımı-ve-heap-bellek)** adlı başlıktan detaylarına bakabilirsiniz.). Bu pointer'da yukarıda bahsedilen kod loğundaki `new` olur böylelikle.
* **Arrow (`->`) operatörü kullanılmasının nedeni:** `Struct pointer` kullanıldığı için arrow operatörü kullanılmaktadır. new değişkeni `t_list` olarak tanımlansaydı eğer point (.) operatörü kullanılacaktı. Bu konunun detaylı açıklamasına **["`struct`'larda Operatörler ve Kullanımları"](#structlarda-operatörler-ve-kullanımları)** adlı başlıktan detaylarına bakabilirsiniz.

<br></br>

## `ft_lstdelone` : `del` fonksiyonu nasıl kullanılır?
Linked list yapıları içerisinde yer alan elemanların bellekten silinmesi önemlidir. Bu işlem, hafıza sızıntılarını önlemek ve gereksiz bellek kullanımını engellemek açısından kritiktir. `del` fonksiyonu, bir linked list elemanının içeriğini temizlemek ve bellekten serbest bırakmak amacıyla kullanılır.

Örneğin, elimizde şu şekilde bir del_int fonksiyonu olsun:

```c
void	del_int(void *content)
{
    free(content);
}
```

Bu fonksiyon, bir `void *` işaretçi alanını alır, bu işaretçiyi `int` veri türüne dönüştürür ve ardından `free` fonksiyonu ile bellekten siler. Bu işlem, linked list elemanının içeriğini temizlemek için kullanılır. Bunu kullanarak, `ft_lstdelone` gibi bir fonksiyon içerisinde `del_int` fonksiyonunu çağırabilirsiniz.

```c
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}
```

`ft_lstdelone` fonksiyonu, verilen bir `t_list` elemanını silerken içeriği `del` fonksiyonu ile temizler ve ardından bellekten serbest bırakır. Bu şekilde, `del` fonksiyonu kullanılarak linked list elemanlarını bellekten güvenli bir şekilde silebilirsiniz.

<br></br>

# Makefile

Makefile, bir programı derlemek ve bağlamak için yönergeler içeren bir metin dosyasıdır. Derleme sürecini otomatikleştirebilen ve size çok zaman kazandırabilen güçlü bir araçtır.

Makefile bir dizi kuraldan oluşur. Her kural, bir hedefi ve bu hedefi oluşturmak için çalıştırılması gereken komutları tanımlar. Hedef; bir dosya, bir dizin, hatta bir komut olabilir.

Bir makefile kuralının sözdizimi aşağıdaki gibidir:

```makefile
target: prerequisites
	commands
```

`target (hedef)`, kuralın oluşturduğu dosya veya dizinin adıdır. `prerequisites (ön koşullar)`, komutların çalıştırılabilmesi için önce var olması gereken dosyalardır. `commands (komutlar)`, hedefi oluşturmak için çalıştırılması gereken asıl komutlardır.

Komutlar boşlukla değil sekme karakteriyle başlamalıdır. Makefile komutların metin değil, komut olduklarını bu şekilde ayırt eder.

C programını derleyen makefile kuralına bir örnek:

```makefile
myprog: main.c
	gcc -o myprog main.c
```

Bu kural, `myprog` adlı bir hedefi tanımlar. `myprog` için ön koşul, `main.c` dosyasıdır. `myprog` komutları, `main.c` dosyasını myprog adlı bir yürütülebilir dosyada derleyen `gcc` komutudur.

Bir makefile yazdıktan sonra, programınızı oluşturmak için make komutunu çalıştırabilirsiniz. `make` komutu makefile dosyasına bakacak ve hangi kuralların çalıştırılması gerektiğini belirleyecektir. Daha sonra hedef dosyaları oluşturmak için bu kuralları çalıştıracaktır.

```makefile
make
```

Bu komut `makefile` dosyasını çalıştıracak ve `myprog` yürütülebilir dosyasını oluşturacaktır.

Makefile yazmak için bazı ek ipuçları:

* Hedefleriniz için açıklayıcı isimler kullanın. Bu, makefile'nin ne yaptığını anlamayı kolaylaştıracaktır.
* Makefile dosyanızın ne yaptığını açıklamak için yorumları kullanın. Bu, makefile dosyanızın bakımını kolaylaştıracaktır.
* Yaygın olarak kullanılan değerleri saklamak için değişkenleri kullanın. Bu, makefile dosyanızı daha özlü ve okunması kolay hale getirecektir.
* Diğer makefile dosyalarını dahil etmek için `include` direktifini kullanın. Bu, makefile dosyalarınızı düzenlemek için yararlı olabilir.

<br></br>

## Derleyici

Derleyici, yüksek seviyeli bir dilde yazılmış bir programı, makine dili gibi düşük seviyeli bir dildeki bir programa çeviren bir programdır.
<br></br>

### Derleme Adımları
---
* Derleyici; önişlemci kaynak kodu alır, yorumları ve kütüphaneleri kaldırır, makroları genişletir ve başlık dosyası içeriklerini çözer.
* Derleyici, kodu assembly diline çevirir. Oluşan dosya uzantısı ".s" tir.
* Derleyici, assembly dilindeki kodu makine dili olan object code'a çevirir. Oluşan dosya uzantısı ".o" dur.
* Bağlayıcı (Linker) daha sonra makine dili nesne dosyalarını (.o uzantılı dosya) yürütülebilir bir dosyaya bağlar.
<br></br>

### Linker (Bağlayıcı)
---

Bağlayıcı, nesne dosyalarını alan ve bunları yürütülebilir bir dosyada birleştiren bir programdır. Bağlayıcı ayrıca, işlev çağrıları ve genel değişkenler gibi nesne dosyaları arasındaki referansları da çözer.

Bağlayıcı, makine dili kodunu nesne dosyalarından alır ve tek bir ikili dosyada birleştirir. Bu ikili dosyaya yürütülebilir dosya denir. Yürütülebilir dosya daha sonra işletim sistemi tarafından çalıştırılabilir. Bağlayıcı ayrıca, işlev çağrıları ve genel değişkenler gibi nesne dosyaları arasındaki referansları da çözer. Bu, yürütülebilir dosyanın doğru şekilde çalıştırılabilmesini sağlar.

Bağlayıcı, önce bir sembol tablosu oluşturarak çalışır. Sembol tablosu, fonksiyon adları ve global değişkenler gibi nesne dosyalarındaki tüm sembollerin bir listesidir. Bağlayıcı daha sonra nesne dosyaları arasındaki referansları çözmek için sembol tablosunu kullanır.

Bağlayıcı hakkında bazı ek ayrıntılar şunlardır:
* Bağlayıcı genellikle derleyici tarafından çağrılır.
* Bağlayıcı, iki veya daha fazla nesne dosyasını girdi olarak alır ve çıktı olarak çalıştırılabilir bir dosya üretir.
* Bağlayıcı, nesne dosyaları arasındaki referansları çözmek için sembol tablosunu kullanır.
* Bağlayıcı, statik kitaplıklar oluşturmak için de kullanılabilir.
<br></br>

### Statik Kitaplık
---

Statik kitaplık, yürütülebilir bir dosya oluşturmak için birbirine bağlanabilen bir nesne dosyaları koleksiyonudur. Statik kitaplıklar genellikle farklı programlar arasında kod paylaşmak için kullanılır.

Statik bir kitaplık oluşturmak için `ar` komutunu kullanmanız gerekir. "ar" komutu iki bağımsız değişken alır, bunlar kitaplığın adı ve kitaplığa dahil edilecek nesne dosyalarının listesidir.

Örneğin, "ft_strcat.o" ve "ft_strcmp.o" nesne dosyalarını içeren "libft.a" adında bir statik kitaplık oluşturmak için aşağıdaki komutu kullanırsınız:

```makefile
ar rcs libft.a ft_strcat.o ft_strcmp.o
```
<br></br>

## Makefile Dosya İçeriği (Basic)

Makefile; değişken bildirimleri, kaynak dosyalar, nesne dosyaları ve statik kitaplık gibi projede kullanılacak farklı dosyaların adlarını tanımlar. Hedef kurallar, projede farklı dosyalar oluşturmak için atılması gereken adımları tanımlar. Örneğin, `all` hedefi için hedef kuralı şöyle görünebilir:

```makefile
all: libft.a
    gcc -o main main.c -L. -lft
```

Bu hedef kuralı,`main` yürütülebilir dosyasını oluşturmak için önce `libft.a` statik kitaplığının oluşturulması gerektiğini söyler. Ardından, `main.c` kaynak dosyasını derlemek ve `main` çalıştırılabilir dosyayı oluşturmak için `gcc` komutu kullanılabilir.

**Örnek:** Basit bir program oluşturmak için kullanılabilecek bir `makefile` örneği:

```makefile
NAME = my_program
SRC = main.c
OBJ = main.o
FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAG) -o $(NAME) $(OBJ)

$(OBJ): $(SRC)
	gcc $(FLAG) -c $(SRC)

clean:
	rm -f $(OBJ) $(NAME)

fclean: clean
	rm -f *.o

re: fclean all

.PHONY: all clean fclean re

```

Makefile'lerde değişkenleri (geçerli hedefi) temsil etmek için `$` işareti kullanılır. Değişkenler, makefile boyunca kullanılabilecek değerleri depolamak için kullanılır.
<br></br>

Bu `makefile` aşağıdaki değişkenleri tanımlar:

* `NAME`, yürütülebilir dosyanın adıdır.
* `SRC`, kaynak dosyaların (.c vb. uzantılı dosyalar) listesidir.
* `OBJ`, nesne dosyalarının (.o uzantılı dosyalar) listesidir.
* `FLAG`, kaynak dosyaları derlerken kullanılacak derleyici bayraklarını belirtmek için kullanılır.

Derleyici bayrakları, derleme sürecini kontrol etmek için derleyiciye iletilebilen bir dizi seçenektir. Örneğin, `-Wall` bayrağı derleyiciye tüm uyarıları bildirmesini söyler. `-Wextra` bayrağı, derleyiciye daha fazla uyarı bildirmesini söyler. `-Werror` bayrağı, derleyiciye tüm uyarıları hata olarak değerlendirmesini söyler.
<br></br>

Bu `makefile` aşağıdaki hedefleri tanımlar:
* `all`, yürütülebilir `my_program` dosyasını oluşturmak için atılması gereken adımları tanımlar.
* `clean`, nesne dosyalarını (OBJ dosyaları) ve yürütülebilir dosyayı silmek için atılması gereken adımları tanımlar.
* `fclean`; nesne dosyalarını, yürütülebilir dosyayı ve `".o"` dosya uzantısını silmek için kullanılır.
* `re`, `fclean` hedefini ve ardından `all` hedefini çalıştırarak projeyi yeniden oluşturmak için kullanılır.
* `.PHONY`, hedeflerin gerçek dosyalar olmadığını belirtmek için kullanılır. Bu hedef, `clean` ve `fclean` hedefleri için kullanışlıdır çünkü bunlar aslında herhangi bir dosya oluşturmazlar.
<br></br>

Bazı bayraklar ve açıklamaları:
* `-c` bayrağı, kaynak dosyalarını derleyerek nesne dosyalarını oluşturur, ancak derlenmiş nesne dosyalarını birleştirme veya bağlama işlemi yapmaz. `-c` bayrağı kullanılmaz ise nesne dosyalarının oluşturulması engellenir. Bunun yerine, derleme ve bağlama işlemleri aynı anda gerçekleşir ve sonuç olarak doğrudan bir arşiv dosyası (.a dosyası) oluşturulur.
* `-o` bayrağı, derlenen kaynak dosyalarının birleştirilerek oluşturulacak hedef dosyanın adını belirtmek için kullanılır. Bu bayrak, `gcc` komutunu kullanırken derleme sonucunda oluşturulacak yürütülebilir veya hedef dosyanın adını belirlemek için kullanılır. `-o` bayrağı kullanılmadığı takdirde, `gcc` derleyici, derlenen kaynak dosyalarını varsayılan olarak `a.out` adlı bir yürütülebilir dosya olarak oluşturur. Yani, `$(NAME)` değişkeni veya `-o` bayrağı belirtilmediğinde, hedef dosyanın adı `a.out` olur.
* `ar` komutu, Unix tabanlı sistemlerde arşiv dosyalarını oluşturmak, düzenlemek ve yönetmek için kullanılır.
* `ar rc`'deki `r` bayrağı, arşiv dosyasına nesne dosyalarını ekler veya mevcut nesne dosyalarını günceller.
* `ar rc`'deki `c` bayrağı, arşiv dosyasının oluşturulmasını zorlar. Eğer arşiv dosyası zaten mevcutsa bile, c bayrağı kullanıldığında yeni bir arşiv dosyası (.a uzantılı dosya) oluşturulur.
* `rm -f` ifadesi, `rm` kısaltması "remove" (sil) anlamına gelir.
* `rm -f` ifadesindeki `-f` bayrağı, "force" (zorla) anlamına gelir ve dosyanın var olup olmadığına bakılmaksızın, silme işlemini gerçekleştirir. Dosya varsa siler, yoksa hata mesajı vermez.

Programı derlemek ve çalıştırmak için aşağıdaki komutları kullanmalısınız:

```
make
./my_program
```
<br></br>
