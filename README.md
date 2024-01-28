# get_next_line Projesi Notları
<br>

## 🖇️ İçerik
- [✏️ Mandatory Part](#️-mandatory-part)
- [✏️ Bonus Part](#️-bonus-part)
- [Statik Değişken Nedir ve Nasıl Kullanılır?](#statik-değişken-nedir-ve-nasıl-kullanılır)
  - [Dosya Kapsamında (File Scope) `static` Değişkenler](#dosya-kapsamında-file-scope-static-değişkenler)
  - [Fonksiyon Kapsamında (Function Scope) `static` Değişkenler](#fonksiyon-kapsamında-function-scope-static-değişkenler)
  - [Fonksiyonun `static` Olarak Tanımlanması](#fonksiyonun-static-olarak-tanımlanması)
- [Fonksiyon Açıklamaları](#fonksiyon-açıklamaları)
  - [`open` Fonksiyonu](#open-fonksiyonu)
  - [`read` Fonksiyonu](#read-fonksiyonu)
  - [`close` Fonksiyonu](#close-fonksiyonu)
  - [`malloc` Fonksiyonu](#malloc-fonksiyonu)
  - [`free` Fonksiyonu](#free-fonksiyonu)

<br>

### ✏️ Mandatory Part
---
<br>
<html lang="en">
	<body>
		<table>
			<tr><td><b>Program adı</b></td><td>get_next_line</td></tr>
			<tr><td><b>Prototip</b></td><td>char *get_next_line(int fd);</td></tr>
			<tr><td><b>Teslim edilecek dosyalar</b></td><td>get_next_line.c, get_next_line_utils.c, get_next_line.h</td></tr>
			<tr><td><b>Parametreler</b></td><td>fd: Okunacak dosya tanımlayıcı</td></tr>
			<tr><td><b>Dönüş değerleri</b></td><td>Read line: doğru davranış , NULL: okunacak başka bir şey yok veya bir hata oluştu</td></tr>
			<tr><td><b>Harici fonksiyonlar</b></td><td>read, malloc, free</td></tr>
			<tr><td><b>Açıklama</b></td><td>Dosya tanımlayıcıdan okunan satırı döndüren bir fonksiyon yazın</td></tr>
		</table>
	</body>
</html><br></br>

* `get_next_line()` işlevinize tekrarlanan çağrılar (örneğin bir döngü kullanarak), dosya tanımlayıcı tarafından işaret edilen metin dosyasını her seferinde bir satır olarak okumanıza izin vermelidir.
* İşleviniz okunan satırı döndürmelidir. Okunacak başka bir şey yoksa veya bir hata oluştuysa NULL döndürmelidir.
* Hem dosya okurken hem de standart girişten okurken işlevinizin beklendiği gibi çalıştığından emin olun.
* Lütfen, dosyanın sonuna ulaşıldığı ve \n karakteriyle bitmediği durumlar dışında, döndürülen satırın sonlandırıcı \n karakterini içermesi gerektiğini unutmayın.
* get_next_line.h başlık dosyanız en azından `get_next_line()` fonksiyonunun prototipini içermelidir.
* İhtiyacınız olan tüm yardımcı işlevleri get_next_line_utils.c dosyasına ekleyin.
* `get_next_line()` 'daki dosyaları okumak zorunda kalacağınız için derleyici çağrınıza bu seçeneği ekleyin: **`-D BUFFER_SIZE=n`**
  * `read()` için arabellek boyutunu tanımlayacaktır.
  * buffer boyutu değeri, kodunuzu test etmek için akran değerlendiricileriniz ve Moulinette tarafından değiştirilecektir.
* Bu projeyi alışılagelmiş flaglara ek olarak **`-D BUFFER_SIZE`** flagıyla ve flagsız olarak derleyebilmemiz gerekiyor. İstediğiniz varsayılan değeri seçebilirsiniz.
* Kodunuzu şu şekilde derleyeceksiniz (örnek olarak 42 arabellek boyutu kullanılmıştır):
	```c
	cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
	```
* Dosya tanımlayıcı tarafından işaret edilen dosya son çağrıdan bu yana değiştiyse, `read()` dosyanın sonuna ulaşmadıysa `get_next_line()` işlevinin tanımsız bir davranışa sahip olduğunu düşünüyoruz.
* Ayrıca `get_next_line()` fonksiyonunun bir ikili dosyayı okurken tanımsız bir davranışa sahip olduğunu da düşünüyoruz. Ancak isterseniz bu davranışı ele almanın mantıksal bir yolunu uygulayabilirsiniz.
* `get_next_line()` her çağrıldığında mümkün olduğunca az okumaya çalışın. Yeni bir satırla karşılaşırsanız mevcut satıra geri dönmeniz gerekir. Dosyanın tamamını okuyup ardından her satırı işlemeyin.

* **Yasaklı**
  * Bu projede libft'inizi kullanmanıza izin verilmiyor.
  * `lseek()` yasaktır.
  * Global değişkenler yasaktır.

<br></br>

### ✏️ Bonus Part
---
* Yalnızca tek bir statik değişken kullanarak `get_next_line()` 'ı geliştirin.
* `get_next_line()` 'ınız aynı anda birden fazla dosya tanımlayıcıyı yönetebilir. Örneğin, 3, 4 ve 5 numaralı dosya tanımlayıcılardan okuyabiliyorsanız, her dosya tanımlayıcının okuma dizisini kaybetmeden veya başka bir fd'den bir satır döndürmeden çağrı başına farklı bir fd'den okuyabilmelisiniz. Bu, fd 3'ten, sonra fd 4'ten, sonra 5'ten, sonra tekrar 3'ten, tekrar 4'ten vb. okumak için get_next_line()'ı çağırabilmeniz gerektiği anlamına gelir. Bonus parça dosyalarına _bonus.[c\h] sonekini ekleyin.
* Zorunlu parça dosyalarına ek olarak aşağıdaki 3 dosyayı da teslim edeceksiniz:
  * get_next_line_bonus.c
  * get_next_line_bonus.h
  * get_next_line_utils_bonus.c

<br></br>

### Statik Değişken Nedir ve Nasıl Kullanılır?
---
`static` kelimesi, farklı bağlamlarda kullanılabiliyor ve birçok durumda kullanımı bulunmaktadır. `static` kelimesi, bir değişkenin ömrü ve erişim kapsamı (scope) ile ilgili olarak kullanılabilir. İki ana durumda `static` değişkenler kullanılır:

<br>

#### Dosya Kapsamında (File Scope) `static` Değişkenler
---
   Eğer bir değişkeni `static` olarak tanımlarsanız, o değişkenin ömrü programın çalışma süresi boyunca sürer, yani program başlatıldığında oluşturulur ve program sona erdiğinde yok olur. Aynı zamanda, bu `static` değişken sadece tanımlandığı dosyada kullanılabilir, diğer dosyalardan erişilemez.

   Örnek:
   ```c
   #include <stdio.h>

   static int exampleVariable = 10; // static değişkenin tanımı (global değişken)

   int main()
   {
       printf("exampleVariable: %d\n", exampleVariable); // ekrana yazılan 10 değeridir
       return 0;
   }
   ```

<br>

#### Fonksiyon Kapsamında (Function Scope) `static` Değişkenler
---
   Eğer bir değişkeni bir fonksiyon içinde `static` olarak tanımlarsanız, o değişkenin ömrü fonksiyon çağrıldığında başlar ve programın çalışma süresi boyunca devam eder. Ancak, bu `static` değişken sadece tanımlandığı fonksiyon içinde erişilebilir.

   Örnek:
   ```c
   #include <stdio.h>

   void exampleFunction()
   {
       static int counter = 0; // Fonksiyon kapsamında static değişken
       counter++;
       printf("counter: %d\n", counter);
   }

   int main()
   {
       exampleFunction();
       exampleFunction();
       exampleFunction();
       return 0;
   }
   ```

<br>

#### Fonksiyonun `static` Olarak Tanımlanması
---
   Bir fonksiyonu `static` olarak tanımlamak, o fonksiyonun dosya kapsamında (file scope) sınırlı olmasını sağlar. Bu durumda, tanımlanan fonksiyon sadece aynı C dosyasında kullanılabilir ve diğer dosyalardan erişilemez.

   Örnek:
   ```c
   // Dosya: example.c adındadır

	#include <stdio.h>

	// static fonksiyonun tanımı
	static void exampleStaticFunction()
	{
		printf("Bu bir static fonksiyon!\n");
	}

	int main()
	{
		// static fonksiyon çağrısı
		exampleStaticFunction();
		return 0;
	}
   ```
Bu örnekte, `exampleStaticFunction` fonksiyonu static olarak tanımlandığı için, sadece `example.c` dosyasında kullanılabilir. Eğer bu fonksiyonu başka bir dosyada kullanmak istiyorsanız, static kelimesini kullanmamalısınız.


<br></br>

### Fonksiyon Açıklamaları
---

<br></br>

#### `open` Fonksiyonu
---
   - **Amaç:** Dosya sisteminden bir dosyayı açmak için kullanılır.
   - **Prototip:** `int open(const char *path, int flags, ... /* mode_t mode */);`
   - **Parametreler:**
     - `path`: Açılacak dosyanın veya cihazın yolunu belirten bir karakter dizisi.
     - `flags`: Açma işlemiyle ilgili kontrol bayraklarını belirten bir tamsayı.
     - `mode`: Opsiyonel olarak belirtilen, dosyanın oluşturulması durumunda izinleri belirten bir tamsayı. Bu genellikle `S_IRUSR`, `S_IWUSR`, vb. sabitlerle oluşturulan bir izin maskesidir.
   - **Return Değeri:** Okunan byte sayısı (-1 hata durumunu belirtir).

   **Örnek:**
   ```c
	#include <fcntl.h> // open fonksiyonunu içeren başlık dosyası
	#include <stdio.h>
	#include <sys/types.h>
	#include <sys/stat.h>

	int main()
	{
		int fileDescriptor = open("dosya.txt", O_RDONLY);
		if (fileDescriptor == -1)
		{
			perror("Dosya açma hatası");
			return 1;
		}
		return 0;
	}
   ```
<br>

#### `read` Fonksiyonu
---
   - **Amaç:** `read` fonksiyonu, bir dosyadan veya dosya tanımlayıcısından veri okumak için kullanılır.
   - **Prototip:** `ssize_t read(int fd, void *buf, size_t count);`
   - **Parametreler:**
     - `fd`: Dosya tanımlayıcısı (file descriptor), okuma yapılacak dosyayı veya kaynağı belirtir.
     - `buf`: Okunan verinin depolanacağı bellek bloğunun başlangıç adresini gösterir.
     - `count`: Okuma yapılacak maksimum byte sayısını belirtir.
   - **Return Değeri:** Okunan byte sayısı (-1 hata durumunu belirtir).

   **Örnek:**
   ```c
	#include <unistd.h>   // read, close fonksiyonlarını içeren başlık dosyası
	#include <fcntl.h>    // open fonksiyonunu içeren başlık dosyası
	#include <stdio.h>    // printf fonksiyonunu içeren başlık dosyası

	int main()
	{
		char buffer[100]; // Okuma işlemi için bir karakter dizisi (buffer)
		int file_descriptor = open("example.txt", O_RDONLY); // Dosya tanımlayıcısı (file descriptor) için bir değişken
		if (file_descriptor == -1) // Dosya açma işlemi başarısız olduysa -1 döner
		{
			perror("Dosya açma hatası");  // Hata mesajını yazdırır
			return 1;  // Programı hata durumunda sonlandırır
		}
		ssize_t bytesRead = read(file_descriptor, buffer, sizeof(buffer)); // Dosyadan okuma işlemi
		if (bytesRead == -1) // Okuma işlemi başarısız olduysa -1 döner
		{
			perror("Okuma hatası");  // Hata mesajını yazdırır
			return 1;  // Programı hata durumunda sonlandırır
		}
		printf("Okunan veri: %.*s", (int)bytesRead, buffer); // Okunan veriyi ekrana yazdırır
		close(file_descriptor); // Dosya tanımlayıcısını kapat
		return 0;  // Programı başarıyla sonlandır
	}
   ```
<br>

#### `close` Fonksiyonu
---
   - **Amaç:** Dosya tanımlayıcısını kapatmak için kullanılır.
   - **Prototip:** `ssize_t close(int fd);`
   - **Parametreler:**
     - `fd`: Dosya tanımlayıcısı (file descriptor), okuma yapılacak dosyayı veya kaynağı belirtir.
   - **Return Değeri:** Başarılıysa 0, hata durumunda -1 döner.

   **Örnek:**
   ```c
	#include <unistd.h>
	#include <fcntl.h>
	#include <stdio.h>

	int main()
	{
		int fileDescriptor = open("dosya.txt", O_RDONLY);
		if (fileDescriptor == -1)
		{
			perror("Dosya açma hatası");
			return 1;
		}

		// Dosyayı kullanma

		if (close(fileDescriptor) == -1)
		{
			perror("Dosya kapatma hatası");
			return 2;
		}
		return 0;
	}
   ```
<br>

#### `malloc` Fonksiyonu
---
   - **Amaç:** `malloc` fonksiyonu, dinamik bellek tahsis etmek için kullanılır. Yani, program çalışma zamanında bellek bloğu oluşturur.
   - **Prototip:** `void *malloc(size_t size);`
   - **Parametreler:**
     - `size`: Alokasyon yapılacak bellek bloğunun byte cinsinden boyutunu belirtir.
   - **Return Değeri:** Başarılı olması durumunda, başlangıç adresini gösteren bir işaretçi (pointer) döner. Başarısız olması durumunda `NULL` döner.

   **Örnek:**
   ```c
   #include <stdio.h>
   #include <stdlib.h>

   int main()
   {
       int *dynamicArray = (int *)malloc(5 * sizeof(int)); // Bellek tahsisi yap
       if (dynamicArray == NULL) // Bellek tahsisi yapılmadıysa hata mesajı yazdır
	   {
           perror("Bellek tahsis hatası");
           return 1;
       }
       return 0;
   }
   ```
<br>

#### `free` Fonksiyonu
---
   - **Amaç:** `free` fonksiyonu, dinamik olarak tahsis edilmiş belleği serbest bırakmak için kullanılır.
   - **Prototip:** `void free(void *ptr);`
   - **Parametreler:**
     - `ptr`: Serbest bırakılacak bellek bloğunun başlangıç adresini gösteren işaretçi.
   - **Return Değeri:** Yoktur.

   **Örnek:**
```c
   #include <stdlib.h>

   int main()
   {
       int *dynamicArray = (int *)malloc(5 * sizeof(int)); // Bellek tahsisi yap
       if (dynamicArray == NULL) // Bellek tahsisi yapılmadıysa hata mesajı yazdır
	   {
           perror("Bellek tahsis hatası");
           return 1;
       }
       free(dynamicArray); // Ayrılan belleği serbest bırak
       return 0;
   }
```
