## CPP Module 01 Notları

- [Memory Allocation (Bellek Tahsisi)](#memory-allocation-bellek-tahsisi)
	- [1. Statik Bellek Tahsisi](#1-statik-bellek-tahsisi)
		- [Özellikler:](#özellikler)
	- [2. Dinamik Bellek Tahsisi](#2-dinamik-bellek-tahsisi)
		- [Özellikler:](#özellikler-1)
		- [`new` ve `delete` Operatörleri](#new-ve-delete-operatörleri)
	- [3. Bellek Sızıntıları (Memory Leaks)](#3-bellek-sızıntıları-memory-leaks)
	- [4. Smart Pointers (Akıllı İşaretçiler)](#4-smart-pointers-akıllı-i̇şaretçiler)
	- [5. `malloc` ve `free` (C'den Gelen Miras)](#5-malloc-ve-free-cden-gelen-miras)
		- [Bellek alanını başlatmak (initialize)](#bellek-alanını-başlatmak-initialize)
			- [**1. Değişkenlerin Başlatılması**](#1-değişkenlerin-başlatılması)
			- [**2. Dinamik Bellek Tahsisi Sırasında Başlatma**](#2-dinamik-bellek-tahsisi-sırasında-başlatma)
			- [**3. `malloc` ve `new` Arasındaki Fark**](#3-malloc-ve-new-arasındaki-fark)
- [Heap ve Stack Bellek](#heap-ve-stack-bellek)
- [Referanslar ve Adres İşleme](#referanslar-ve-adres-i̇şleme)
	- [1. **Adres İşleme (İşaretçiler)**](#1-adres-i̇şleme-i̇şaretçiler)
		- [Temel İşaretçi Kullanımı:](#temel-i̇şaretçi-kullanımı)
		- [Açıklama:](#açıklama)
	- [2. **Referanslar**](#2-referanslar)
		- [Temel Referans Kullanımı:](#temel-referans-kullanımı)
		- [Açıklama:](#açıklama-1)
	- [3. **İşaretçi ve Referans Arasındaki Farklar**](#3-i̇şaretçi-ve-referans-arasındaki-farklar)
	- [4. **Referans ve İşaretçilerin Fonksiyon Parametrelerinde Kullanımı**](#4-referans-ve-i̇şaretçilerin-fonksiyon-parametrelerinde-kullanımı)
		- [İşaretçi ile Fonksiyon Parametresi:](#i̇şaretçi-ile-fonksiyon-parametresi)
		- [Referans ile Fonksiyon Parametresi:](#referans-ile-fonksiyon-parametresi)
	- [Özet](#özet)
- [`fstream` ile Dosya İşlemleri](#fstream-ile-dosya-i̇şlemleri)
	- [`fstream` Kullanımı](#fstream-kullanımı)
	- [Örnek Kullanım](#örnek-kullanım)
	- [Önemli Noktalar](#önemli-noktalar)
- [`std::string::npos` Nedir?](#stdstringnpos-nedir)
- [Üyeler için İşaretçiler (Pointer to Members)](#üyeler-için-i̇şaretçiler-pointer-to-members)
	- [Üye İşaretçileri: Temel Kavramlar](#üye-i̇şaretçileri-temel-kavramlar)
		- [1. Üye Veri İşaretçileri (Member Data Pointers)](#1-üye-veri-i̇şaretçileri-member-data-pointers)
		- [2. Üye Fonksiyon İşaretçileri (Member Function Pointers)](#2-üye-fonksiyon-i̇şaretçileri-member-function-pointers)
	- [Üye İşaretçileri Kullanım Alanları](#üye-i̇şaretçileri-kullanım-alanları)
	- [Üye İşaretçilerinin Özel Kullanımları](#üye-i̇şaretçilerinin-özel-kullanımları)
	- [Bellek Yönetimi ile İşaretçiler](#bellek-yönetimi-ile-i̇şaretçiler)
	- [Özet](#özet-1)
- [Switch İfadesi](#switch-i̇fadesi)
	- [`switch` İfadesinin Sözdizimi](#switch-i̇fadesinin-sözdizimi)
	- [Örnek 1: Basit Bir `switch` Kullanımı](#örnek-1-basit-bir-switch-kullanımı)
	- [Örnek 2: `char` Tipi ile `switch`](#örnek-2-char-tipi-ile-switch)
	- [Örnek 3: `default` İfadesi Kullanımı](#örnek-3-default-i̇fadesi-kullanımı)
	- [Örnek 4: `switch` ile `enum` Kullanımı](#örnek-4-switch-ile-enum-kullanımı)
	- [`switch`'in Avantajları ve Dezavantajları](#switchin-avantajları-ve-dezavantajları)
		- [Avantajları:](#avantajları)
		- [Dezavantajları:](#dezavantajları)
	- [`switch`'in Limitleri:](#switchin-limitleri)
	- [Özet](#özet-2)

<br></br>



## Memory Allocation (Bellek Tahsisi)

C++'ta **memory allocation** (bellek tahsisi), programın çalışması sırasında ihtiyaç duyduğu verileri bellekte saklamak için kullanılan yöntemlerdir. C++ dilinde bellek tahsisi iki ana kategoride yapılır: **statik bellek tahsisi** ve **dinamik bellek tahsisi**.

### 1. Statik Bellek Tahsisi

Statik bellek tahsisi, derleme zamanında (compile-time) yapılır. Bu, bir değişkenin veya nesnenin bellekteki yerinin programın başından sonuna kadar sabit kaldığı anlamına gelir. Statik bellek tahsisi, genellikle stack üzerinde yapılır ve otomatik olarak yönetilir.

#### Özellikler:
- **Derleme Zamanı**: Statik bellek tahsisi, programın derlenmesi sırasında belirlenir.
- **Bellek Yönetimi**: Bellek otomatik olarak yönetilir. Değişken veya nesne tanımlandığı kapsamdan çıktığında bellek serbest bırakılır.
- **Hızlı**: Bellek tahsisi ve serbest bırakma işlemleri çok hızlıdır, çünkü yalnızca stack pointer hareket ettirilir.
- **Örnekler**:
  - Yerel değişkenler: `int x = 5;`
  - Sabit boyutlu diziler: `int arr[10];`
  - Global değişkenler: `int globalVar;`

### 2. Dinamik Bellek Tahsisi

Dinamik bellek tahsisi, programın çalışma zamanı (run-time) sırasında yapılır. Dinamik olarak tahsis edilen bellek, heap adı verilen daha büyük ve esnek bir bellek alanından gelir. Dinamik bellek tahsisi, genellikle daha büyük veri yapıları veya nesneler için kullanılır ve programcının manuel olarak yönetmesi gerekir.

#### Özellikler:
- **Çalışma Zamanı**: Dinamik bellek tahsisi, programın çalışması sırasında yapılır ve bellek ihtiyacı programın dinamik koşullarına göre belirlenir.
- **Bellek Yönetimi**: Programcı, tahsis edilen belleği manuel olarak serbest bırakmak zorundadır. Aksi takdirde bellek sızıntıları (memory leaks) oluşabilir.
- **Esneklik**: Dinamik bellek tahsisi daha esnektir, çünkü belleğin boyutu çalışma zamanı sırasında belirlenebilir ve daha büyük bellek alanları tahsis edilebilir.
- **Örnekler**:
  - `new` ve `delete`: Dinamik bellek tahsisi ve serbest bırakma için kullanılır.
  - Dinamik diziler: `int* arr = new int[size];`
  - Nesne oluşturma: `MyClass* obj = new MyClass();`

#### `new` ve `delete` Operatörleri
- **`new` Operatörü**: Dinamik bellek tahsis eder ve tahsis edilen belleğin adresini döndürür.
  ```cpp
  int* ptr = new int;        // Tek bir int için bellek tahsisi
  int* arr = new int[10];    // 10 elemanlı int dizisi için bellek tahsisi
  ```
- **`delete` Operatörü**: `new` ile tahsis edilen belleği serbest bırakır. Kullanılmadığı takdirde bellek sızıntılarına yol açabilir.
  ```cpp
  delete ptr;        // Tek bir int için tahsis edilen belleği serbest bırak
  delete[] arr;      // Bir dizi için tahsis edilen belleği serbest bırak
  ```

### 3. Bellek Sızıntıları (Memory Leaks)

Dinamik bellek tahsisi sırasında programcı, tahsis edilen belleği serbest bırakmayı unutursa, bu bellek tekrar kullanılmaz ve bu durumda bellek sızıntısı oluşur. Bellek sızıntıları, özellikle uzun süre çalışan programlarda ciddi performans sorunlarına neden olabilir.

### 4. Smart Pointers (Akıllı İşaretçiler)

C++11 ile birlikte gelen **smart pointers** (akıllı işaretçiler), dinamik bellek yönetimini kolaylaştırmak ve bellek sızıntılarını önlemek için kullanılır. `std::unique_ptr`, `std::shared_ptr` gibi akıllı işaretçiler, bellek otomatik olarak yönetilir ve işaretçinin kapsamı sona erdiğinde tahsis edilen bellek otomatik olarak serbest bırakılır.

### 5. `malloc` ve `free` (C'den Gelen Miras)

C++'ta `malloc` ve `free` fonksiyonları da dinamik bellek tahsisi ve serbest bırakma için kullanılabilir, ancak C++'ta `new` ve `delete` operatörleri bu iş için tercih edilir. `malloc` belleği tahsis eder, ancak bu belleği başlatmaz, oysa `new` operatörü hem bellek tahsisi yapar hem de bellek alanını başlatır.

#### Bellek alanını başlatmak (initialize)
---
Programda bir değişkenin veya nesnenin bellekte tahsis edilen alanını belirli bir başlangıç değeri ile doldurmak anlamına gelir. Bu, bellek alanının kullanılmadan önce belirli ve bilinen bir durumda olmasını sağlar. C++'ta bellek alanını başlatmanın iki yaygın durumu vardır: **değişkenlerin başlatılması** ve **dinamik bellek tahsisi sırasında başlatma**.

##### **1. Değişkenlerin Başlatılması**
---
Bir değişken tanımlandığında, ona bir başlangıç değeri atanması başlatma (initialization) olarak adlandırılır. Bu, değişkenin kullanılmadan önce rastgele bellek içeriği taşımaması için yapılır.

Örneğin:
```cpp
int a = 5; // 'a' değişkeni 5 ile başlatılır
```
Bu kodda, `a` değişkeni tanımlanır ve ona hemen 5 değeri atanır. Bu, `a`'nın bellekte 5 değeriyle başlatıldığı anlamına gelir.

Eğer bir değişken başlatılmazsa, içeriği belirsiz (undefined) olur ve bu, programda hatalara yol açabilir.

##### **2. Dinamik Bellek Tahsisi Sırasında Başlatma**
---
Dinamik bellek tahsisi sırasında bellek, programın çalışma zamanında (run-time) heap'ten ayrılır. Belleğin tahsis edilmesi, bellek alanının ayrılması anlamına gelirken, başlatılması bu ayrılan bellek alanının belirli bir başlangıç değeriyle doldurulması anlamına gelir.

Örneğin, `new` operatörü hem bellek tahsisi yapar hem de belleği başlatır:
```cpp
int* ptr = new int(10); // Dinamik olarak bir int için bellek tahsis edilir ve bu bellek 10 ile başlatılır
```
Bu kod, heap üzerinde bir `int` için bellek tahsisi yapar ve bu belleğe `10` değeri atanır. Yani, `ptr` işaretçisinin gösterdiği bellek alanı başlatılmış olur.

* **Bellek Alanının Başlatılmaması:** Bellek alanı başlatılmadığında, o alan önceden kullanılan rastgele verilerle dolu olabilir. Bu, belirsiz davranışlara yol açabilir ve programın hata vermesine neden olabilir. Örneğin:

	```cpp
	int* ptr = new int; // Bellek tahsis edilir, fakat başlatılmaz
	std::cout << *ptr;  // Bu durumda, ptr rastgele bir değeri gösterebilir
	```

##### **3. `malloc` ve `new` Arasındaki Fark**
---
C'de kullanılan `malloc` fonksiyonu, sadece bellek tahsisi yapar ama bu bellek alanını başlatmaz:

```cpp
int* ptr = (int*)malloc(sizeof(int)); // Sadece bellek tahsis edilir, ancak başlatılmaz
```

Bu durumda, `ptr` işaretçisinin gösterdiği alan rastgele veri içerebilir. Ancak, `new` operatörü kullanıldığında hem tahsis hem de başlatma yapılır:

```cpp
int* ptr = new int(0); // Bellek tahsis edilir ve 0 ile başlatılır
```

<br></br>

## Heap ve Stack Bellek

* Stack bellek (yığın belleği), programın çalışması sırasında fonksiyon çağrıları, yerel değişkenler ve fonksiyon parametreleri gibi geçici verileri depolamak için kullanılır.
* Heap bellek (yığın dışı bellek), daha büyük veri yapıları ve uzun ömürlü nesneler için kullanılan dinamik bellek alanıdır. Bu bellek bölgesi, programın çalışma süresi boyunca veri depolamak için kullanılır ve manuel olarak yönetilmelidir.

* Stack, hızlı ve otomatik olarak yönetilen bellek tahsisi sağlar, ancak sınırlı kapasitesi nedeniyle daha küçük ve kısa ömürlü veri yapıları için uygundur.
* Heap ise daha büyük ve esnek bir bellek alanı sunar, ancak manuel yönetim gerektirir ve bu nedenle stack'e göre daha yavaştır.

| Özellik                     | Stack Belleği                                  | Heap Belleği                              |
|-----------------------------|------------------------------------------------|-------------------------------------------|
| **Yerleşim**                | Fonksiyon çağrıları ve yerel değişkenler için ayrılan bellek. | Daha büyük veri yapıları ve uzun ömürlü nesneler için kullanılan dinamik bellek. |
| **Yönetim**                 | Stack belleği otomatik olarak yönetilir. Bir fonksiyon çağrıldığında, o fonksiyon için gereken bellek stack üzerinde tahsis edilir. Fonksiyon sona erdiğinde bu bellek otomatik olarak serbest bırakılır. | Heap belleği, programcı tarafından manuel olarak yönetilir. Dinamik bellek tahsisi new operatörü ile yapılır ve delete operatörü ile serbest bırakılır. Bellek yönetiminin manuel olması nedeniyle, bellek sızıntıları (memory leaks) oluşabilir. |
| **Hız**                     | Stack bellek çok hızlıdır çünkü bellek tahsisi ve serbest bırakma işlemleri basittir. Bellek tahsisi, yalnızca stack pointer’ı (yığın işaretçisi) hareket ettirerek gerçekleştirilir. | Stack'e göre daha yavaştır, çünkü bellek tahsisi ve serbest bırakma daha karmaşıktır. |
| **Bellek Sınırları** | Stack belleği sınırlı bir büyüklüğe sahiptir. Bu, genellikle sabit boyutlu küçük veri yapıları için yeterlidir, ancak büyük veri yapıları stack’te saklanamaz. | Heap belleği çok daha büyüktür ve bu nedenle büyük veri yapıları ve uzun ömürlü nesneler için kullanılabilir. Bellek, çalışma zamanı sırasında dinamik olarak tahsis edilebilir ve boyutu belirlenebilir. |
| **Kapsam**                  | Tanımlandıkları fonksiyonun veya blokun kapsamı dışına çıktığında otomatik olarak yok edilir. | Heap’teki veriler, manuel olarak serbest bırakılana kadar programın ömrü boyunca varlığını sürdürebilir. Bu, fonksiyonlar arasında veri paylaşımı ve uzun ömürlü nesneler için idealdir. |
| **Bellek Sızıntısı**        | Bellek sızıntısı olasılığı yoktur, çünkü bellek otomatik olarak serbest bırakılır. | Bellek sızıntısı riski vardır, çünkü serbest bırakma manuel olarak yapılmalıdır. |
| **Tipik Kullanım Alanları** | Yerel değişkenler, fonksiyon parametreleri, kısa ömürlü nesneler. | Büyük veri yapıları, uzun ömürlü nesneler, fonksiyonlar arasında paylaşılması gereken nesneler. |


<br></br>


## Referanslar ve Adres İşleme

İşaretçiler ve referanslar C++ programlarında doğrudan bellek üzerinde çalışmayı sağlar. Bu kavramları anlamak, bellek yönetimi, verimlilik ve daha derin programlama becerilerini geliştirmek için önemlidir.

### 1. **Adres İşleme (İşaretçiler)**
İşaretçiler (pointers), bellek adreslerini tutan özel değişkenlerdir. Bir işaretçi, başka bir değişkenin bellek adresini tutarak, o değişkene doğrudan erişimi sağlar. İşaretçilerin başında `*` sembolü kullanılır ve bir değişkenin adresini elde etmek için `&` sembolü kullanılır.

#### Temel İşaretçi Kullanımı:

```cpp
#include <iostream>

int main()
{
	int num = 42;       // Normal bir değişken
	int* ptr = &num;    // İşaretçi, num'un adresini tutuyor

	std::cout << "num değişkeninin değeri     : " << num << std::endl;
	std::cout << "ptr tarafından tutulan adres: " << ptr << std::endl;
	std::cout << "ptr'in işaret ettiği değer  : " << *ptr << std::endl;

	return 0;
}
```

#### Açıklama:
- `num` normal bir tamsayı değişkenidir.
- `ptr` bir işaretçidir ve `num` değişkeninin adresini tutar (`int* ptr = &num`).
- `ptr` işaretçisinin tuttuğu değeri (yani bellekteki adresi) yazdırdık ve `*ptr` kullanarak işaret ettiği değeri (`num`'un değeri) elde ettik.

İşaretçiler, özellikle dinamik bellek yönetimi ve dizilere erişimde yaygın olarak kullanılır.

### 2. **Referanslar**
Referanslar (references), bir değişkenin başka bir isimle anılmasını sağlayan bir yapıdır. Referanslar bir kez tanımlandıktan sonra başka bir değişkeni işaret edemezler, yani hep aynı değişkeni referans ederler. Referansların başında `&` sembolü kullanılır, ancak referans kendisi bir adres tutmaz, doğrudan ilgili değişkeni temsil eder.

#### Temel Referans Kullanımı:

```cpp
#include <iostream>

int main()
{
	int num = 42;       // Normal bir değişken
	int& ref = num;     // Referans, num'a bağlandı

	std::cout << "num değişkeninin değeri    : " << num << std::endl;
	std::cout << "ref'in referans ettiği değer: " << ref << std::endl;

	ref = 100; // referansı kullanarak num'un değerini değiştirebiliriz

	std::cout << "num değişkeninin yeni değeri: " << num << std::endl;

	return 0;
}
```

#### Açıklama:
- `num` değişkeni normal bir tamsayıdır.
- `ref` referansı, `num` değişkenine bağlanmıştır (`int& ref = num`).
- `ref` doğrudan `num`'u temsil eder, yani `ref` üzerinde yapılan işlemler aslında `num` üzerinde yapılır.
- Referans bir kez bağlandığında başka bir değişkeni işaret edemez.

### 3. **İşaretçi ve Referans Arasındaki Farklar**
- **İşaretçiler:** İşaretçiler bellek adreslerini tutar ve işaret ettikleri değişkenleri değiştirebilirler. `nullptr` gibi bir değerle işaretçi boş bırakılabilir. Bellek üzerinde doğrudan çalışmak gerektiğinde kullanılırlar (dinamik bellek, diziler vb.).

- **Referanslar:** Referanslar başlangıçta hangi değişkene bağlanmışlarsa hep o değişkeni işaret ederler. Bir referansın adresi yoktur (kendisi bir değişken değildir), sadece başka bir değişkene alternatif bir isimdir.

| Özellik             | İşaretçi (Pointer)                   | Referans (Reference)             |
|---------------------|--------------------------------------|----------------------------------|
| Bellek adresi tutar mı? | Evet (doğrudan bir bellek adresi tutar) | Hayır (bir değişkene bağlıdır)    |
| Null olabilir mi?     | Evet (`nullptr` veya `NULL` olabilir) | Hayır (daima bir değişkene bağlıdır) |
| Tanımlandıktan sonra başka bir değişkene atanabilir mi? | Evet | Hayır |
| Kullanımı            | Dinamik bellek, diziler, fonksiyon adresleri vb. | Geçici isimlendirme, fonksiyonlarda argüman iletimi |

### 4. **Referans ve İşaretçilerin Fonksiyon Parametrelerinde Kullanımı**
Hem işaretçiler hem de referanslar, fonksiyonlara değişkenleri referans yoluyla aktarmak için kullanılabilir. Bu, özellikle büyük veri yapılarını (örneğin dizileri veya büyük nesneleri) kopyalamak yerine referans olarak geçirmeyi sağlar.

#### İşaretçi ile Fonksiyon Parametresi:

```cpp
#include <iostream>

void square(int* ptr)
{
	*ptr = (*ptr) * (*ptr);
}

int main()
{
	int num = 5;

	square(&num);  // num'un adresini gönderiyoruz

	std::cout << "num'un karesi: " << num << std::endl;

	return 0;
}
```

#### Referans ile Fonksiyon Parametresi:

```cpp
#include <iostream>

void square(int& ref)
{
	ref = ref * ref;
}

int main()
{
	int num = 5;

	square(num);  // num'u referans olarak gönderiyoruz

	std::cout << "num'un karesi: " << num << std::endl;

	return 0;
}
```

### Özet
| **Konu**                           | **İşaretçi (Pointer)**                                         | **Referans (Reference)**                                     |
|------------------------------------|----------------------------------------------------------------|--------------------------------------------------------------|
| **Bellek adresi tutar mı?**        | Evet, bir bellek adresi tutar (`int* ptr = &num;`).            | Hayır, doğrudan bir değişkene bağlıdır (`int& ref = num;`)   |
| **Null olabilir mi?**              | Evet, `nullptr` veya `NULL` olabilir.                          | Hayır, null olamaz, her zaman bir değişkene bağlıdır.        |
| **Başka değişkene atanabilir mi?** | Evet, işaret edilen değişkeni değiştirebilir.                  | Hayır, bir kez bağlandığında başka bir değişkene atanamaz.   |
| **Bellek erişimi**                 | Bellek üzerinde doğrudan çalışır (dinamik bellek, diziler vb.).| Doğrudan belleğe erişim yapmaz, geçici isimlendirme sağlar.  |
| **Kullanımı**                      | Dinamik bellek, diziler, fonksiyon adresleri vb.               | Fonksiyonlarda argüman iletimi, geçici değişken isimlendirme.|
| **Fonksiyon parametrelerinde**     | Bellek adresini işaretçi ile iletir (`void func(int* ptr);`).  | Belleği referans ile iletir (`void func(int& ref);`)         |

<br></br>

## `fstream` ile Dosya İşlemleri
`fstream` (file stream), dosya girişi ve çıkışı işlemleri için kullanılan bir sınıftır. `fstream`, hem okuma hem de yazma işlemlerini destekler. Bu sınıf, `fstream`, `ifstream` (input file stream - okuma için) ve `ofstream` (output file stream - yazma için) sınıflarını içerir.

### `fstream` Kullanımı

1. **Dosya Açma**: Dosyayı açmak için bir `fstream` nesnesi oluşturulmalı ve dosya adı belirtilmelidir. Aşağıdaki modlar kullanılabilir:
   - `ios::in`: Dosya okuma modunda açılır.
   - `ios::out`: Dosya yazma modunda açılır.
   - `ios::app`: Dosyaya ekleme (append) modunda açılır.
   - `ios::binary`: Dosyayı ikili (binary) modda açar.

2. **Dosya Okuma**: Dosyadan veri okumak için `>>` operatörü veya `getline()` fonksiyonu kullanılabilir.

3. **Dosya Yazma**: Dosyaya veri yazmak için `<<` operatörü veya `write()` fonksiyonu kullanılabilir.

4. **Dosyayı Kapatma**: İşlemler tamamlandıktan sonra dosya kapatılmalıdır. Bu, `close()` fonksiyonu ile yapılır.

### Örnek Kullanım

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ofstream outfile("example.txt"); // Yazma için dosya aç

    if (outfile.is_open())
	{
        outfile << "Merhaba, Dünya!" << std::endl; // Dosyaya yaz
        outfile.close(); // Dosyayı kapat
    }
	else
        std::cerr << "Dosya açılamadı!" << std::endl;

    std::ifstream infile("example.txt"); // Okuma için dosya aç
    std::string line;

    if (infile.is_open())
	{
        while (getline(infile, line)) // Dosyadan satır satır oku
            std::cout << line << std::endl; // Satırı yazdır
        infile.close(); // Dosyayı kapat
    }
	else
        std::cerr << "Dosya açılamadı!" << std::endl;

    return 0;
}
```

### Önemli Noktalar

- **Hata Kontrolü**: Dosya açma işlemleri sonrasında hata kontrolü yapılmalıdır. `is_open()` fonksiyonu kullanılarak dosyanın açılıp açılmadığı kontrol edililir.
- **Veri Biçimi**: Yazılan verilerin biçimi, dosya okunurken dikkate alınmalıdır. Özellikle ikili dosya işlemleri yaparken veri yapısının uyumlu olması gerekir.

<br></br>

## `std::string::npos` Nedir?
`std::string::npos`, C++ dilinde `std::string` sınıfına ait özel bir sabittir ve genellikle bir arama işlemi sırasında sonucun bulunamadığını belirtmek için kullanılır. Değeri genellikle `-1` olup, `std::size_t` türüne dönüştürüldüğünde çok büyük bir pozitif değere eşittir (çünkü `std::size_t` işaretsiz bir tamsayıdır).

Örneğin, bir dizgede bir alt dize ararken (`find` fonksiyonu gibi), eğer alt dize bulunamazsa, fonksiyon `std::string::npos` döner:

```cpp
std::string str = "Hello, world!";
std::size_t found = str.find("C++");

if (found == std::string::npos)
{
    std::cout << "Alt dize bulunamadı!" << std::endl;
}
```

Bu örnekte, `"C++"` alt dizesi `"Hello, world!"` içinde olmadığı için `str.find("C++")` fonksiyonu `std::string::npos` döndürür, bu da alt dizenin bulunamadığını belirtir.

<br></br>

## Üyeler için İşaretçiler (Pointer to Members)
C++'ta **üye için işaretçiler** (member pointers), bir sınıfın üye değişkenlerine ya da üye fonksiyonlarına işaret eden işaretçilerdir. Sınıf üyelerine erişim sağlamak için işaretçiler kullanıldığında, dinamik bellek yönetimi ve polimorfizm gibi ileri seviye konularla çalışırken büyük avantajlar sağlarlar.

### Üye İşaretçileri: Temel Kavramlar

C++'ta iki tür üye işaretçi vardır:
1. **Üye Veri İşaretçileri**: Sınıfın bir üye değişkenine işaret eder.
2. **Üye Fonksiyon İşaretçileri**: Sınıfın bir üye fonksiyonuna işaret eder.

#### 1. Üye Veri İşaretçileri (Member Data Pointers)

Bu işaretçiler, bir sınıfın veri üyesine işaret eder. Ancak, normal bir işaretçiden farklı olarak, bu işaretçi bir sınıf türüne bağlıdır. İşaretçinin hangi sınıfın üyesine işaret ettiği belirtilmelidir.

**Sözdizimi:**
```cpp
int ClassName::* pointerToMember;
```

Bu ifade, `ClassName` sınıfındaki bir int veri üyesine işaret eden bir işaretçi tanımlar.

**Örnek:**
```cpp
#include <iostream>

class MyClass
{
	public:
		int value;
		MyClass(int v) : value(v) {}
};

int main()
{
    // MyClass'in int türündeki veri üyesine işaret eden işaretçi tanımı
    int MyClass::*ptr = &MyClass::value;

    // Bir MyClass nesnesi oluştur
    MyClass obj(10);

    // İşaretçiyi kullanarak nesneye erişim
    std::cout << "Objenin değeri: " << obj.*ptr << std::endl;  // Çıktı: 10

    // İşaretçiyi kullanarak değeri değiştirme
    obj.*ptr = 20;
    std::cout << "Yeni değer: " << obj.*ptr << std::endl;  // Çıktı: 20

    return 0;
}
```
Bu örnekte, `ptr` işaretçisi `MyClass` sınıfının `value` üyesine işaret eder. `obj.*ptr` ifadesi ile `value` üyesine erişir ve değerini değiştirebiliriz.

#### 2. Üye Fonksiyon İşaretçileri (Member Function Pointers)

Sınıfın üye fonksiyonlarına işaret eden işaretçiler, belirli bir sınıfa ait olan üye fonksiyonları için kullanılır. Bu tür işaretçiler, bir sınıf nesnesi tarafından çağrılacak fonksiyona dinamik olarak karar vermeye olanak tanır.

**Sözdizimi:**
```cpp
ReturnType (ClassName::* pointerToFunction)(ParameterTypes);
```

**Örnek:**
```cpp
#include <iostream>

class MyClass
{
	public:
		void display() {
			std::cout << "MyClass::display çağrıldı!" << std::endl;
		}
		void setValue(int v) {
			value = v;
			std::cout << "Değer ayarlandı: " << value << std::endl;
		}
	private:
		int value;
};

int main()
{
    // MyClass sınıfındaki display fonksiyonuna işaret eden işaretçi
    void (MyClass::*funcPtr)() = &MyClass::display;

    // Bir MyClass nesnesi oluştur
    MyClass obj;

    // İşaretçiyi kullanarak display fonksiyonunu çağır
    (obj.*funcPtr)();  // Çıktı: MyClass::display çağrıldı!

    // setValue fonksiyonuna işaret eden işaretçi
    void (MyClass::*setValuePtr)(int) = &MyClass::setValue;

    // İşaretçiyi kullanarak setValue fonksiyonunu çağır
    (obj.*setValuePtr)(42);  // Çıktı: Değer ayarlandı: 42

    return 0;
}
```

Bu örnekte:
- `funcPtr` işaretçisi, `MyClass::display` fonksiyonuna işaret eder ve `obj.*funcPtr()` kullanılarak çağrılır.
- `setValuePtr` ise `MyClass::setValue` fonksiyonuna işaret eder ve `obj.*setValuePtr(42)` kullanılarak parametreli fonksiyon çağrısı yapılır.

`void (MyClass::*)()` ifadesinde **`MyClass::`** yazmamızın sebebi, bu işaretçinin **`MyClass`** sınıfına ait bir **üye fonksiyon** (member function) olduğunu belirtmektir.

Normal fonksiyonlarla, sınıfa ait üye fonksiyonlar arasında bir fark vardır. Üye fonksiyonlar, bir sınıfa bağlıdır ve bu fonksiyonların çağrılması için bir sınıf nesnesi gereklidir. Fonksiyon işaretçileri ile çalışırken de, bu farkı belirtmek zorundayız.

Eğer yalnızca `void (*)()` şeklinde bir işaretçi tanımlamış olunsaydı, bu sıradan bir fonksiyon işaretçisi olurdu ve üye fonksiyonlara işaret edemezdi. Sınıfın üye fonksiyonlarına işaret eden işaretçilerin, sınıfın nesnelerine bağlı olmaları gerektiği için bu şekilde sınıf adı belirtilir.

Bu nedenle:

- **`void (*)()`**: Bu bir **normal** fonksiyon işaretçisidir. Herhangi bir sınıfa ait değildir ve herhangi bir fonksiyona işaret edebilir.

- **`void (MyClass::*)()`**: Bu ise **üye fonksiyon** işaretçisidir. Bu işaretçi, **`MyClass`** sınıfına ait bir fonksiyona işaret edebilir. Sınıfın fonksiyonları, bir sınıfın nesnesine bağlı olduklarından dolayı, işaretçinin tipi de o sınıfa özgü olmalıdır.

Özetle: `MyClass::` yazmamızın sebebi, işaretçinin **sadece `MyClass` sınıfına ait bir fonksiyona** işaret edebileceğini belirtmek içindir. Üye fonksiyon işaretçilerini, sınıftan bağımsız normal fonksiyon işaretçilerinden ayırmak zorundayız çünkü üye fonksiyonlar bir sınıfın nesnesine bağlı olarak çalışır.

-> Detaylı Anlatım:
`void (MyClass::*funcPtr)() = &MyClass::display;` ifadesini adım adım parçalayıp açıklayalım:

- `void` : Bu, işaretçinin işaret ettiği fonksiyonun **geri dönüş tipi**ni belirtir. Burada, `display` fonksiyonu herhangi bir değer döndürmediği için geri dönüş tipi `void` olarak tanımlanmıştır.
- `(MyClass::*)` : Bu kısım işaretçinin, **hangi sınıfın üye fonksiyonuna işaret ettiğini** belirtir. `MyClass::*` kısmı, bu işaretçinin **`MyClass`** sınıfına ait bir üye fonksiyon olduğunu gösterir. Eğer bu olmadan yazsaydık, işaretçi normal bir fonksiyona işaret edebilirdi, ancak biz burada üye fonksiyon işaretçisi tanımlıyoruz.
  - **`MyClass::*`**: Bu işaretçinin `MyClass` sınıfının bir üye fonksiyonuna işaret ettiğini belirtir.
  - **`*`**: İşaretçinin kendisini temsil eder.
- `funcPtr` : Bu, üye fonksiyon işaretçisinin **adı**dır. Yani, `funcPtr` bir değişkendir ve bu değişken, `MyClass` sınıfına ait üye fonksiyonlara işaret edebilir.

  - **`funcPtr`**: Üye fonksiyon işaretçisinin ismi. Program içinde bu işaretçiyi kullanarak bir fonksiyona işaret edeceğiz.

- `()` : Bu, işaretçinin **işaret edeceği fonksiyonun parametre listesi**ni belirtir. Burada parantezler boş olduğu için, işaret edilen fonksiyonun **parametresiz** olduğunu anlarız. Bu durumda işaretçi, parametre almayan bir fonksiyona işaret edebilir. `MyClass::display` fonksiyonu parametre almadığı için burada boş parantez kullanılır.
- `= &MyClass::display` : Bu kısım, işaretçiye **hangi fonksiyonu işaret ettiğini** atar.

  - **`&MyClass::display`**: Bu, `MyClass` sınıfındaki `display` fonksiyonunun adresini alır. Üye fonksiyonların adresini almak için `&MyClass::` biçiminde sınıfın ismiyle birlikte belirtilmesi gerekir.

Bu ifade şu anlama gelir:
- **`funcPtr`** adında bir üye fonksiyon işaretçisi tanımlanıyor.
- Bu işaretçi, geri dönüş tipi `void` ve parametre almayan bir fonksiyona işaret edebilir.
- İşaret ettiği fonksiyon, `MyClass` sınıfına ait bir üye fonksiyondur.
- İşaretçi, `MyClass` sınıfındaki `display` fonksiyonunu işaret etmektedir.

Kısaca özetlemek gerekirse, bu satır:
- `funcPtr` isimli bir işaretçiyi tanımlar.
- Bu işaretçi, `MyClass` sınıfına ait, parametre almayan ve `void` döndüren fonksiyonlara işaret edebilir.
- İşaretçi, başlangıçta `MyClass::display` fonksiyonuna işaret eder.

### Üye İşaretçileri Kullanım Alanları

Üye işaretçileri, dinamik ve esnek programlar yazmak için kullanışlıdır. Örneğin:
1. **Fonksiyonların dinamik seçimi**: Farklı durumlarda farklı üye fonksiyonlarını çağırmak gerektiğinde kullanılır.
2. **Callback mekanizmaları**: Özellikle GUI uygulamaları ve olay temelli programlamada, belirli bir olay gerçekleştiğinde çağrılacak fonksiyonu işaret eden işaretçilerin kullanımı.
3. **Polimorfizm**: İşaretçilerle farklı sınıf fonksiyonlarını bir arayüz ile çağırmak mümkündür.

### Üye İşaretçilerinin Özel Kullanımları

- **Dizi veya koleksiyonlarla**: Üye işaretçileri kullanarak, bir nesne dizisi üzerinde aynı üye fonksiyonunu çağırmak mümkündür.
- **Bağımsızlık sağlamak**: Sınıfların içerdiği birçok üye fonksiyonuna erişimi kolaylaştırarak, daha esnek ve genişletilebilir bir yapı oluşturmanıza yardımcı olur.

### Bellek Yönetimi ile İşaretçiler
Üye işaretçileri, dinamik bellek yönetimi ile birlikte kullanıldığında dikkatli olunmalıdır. Bellekte dinamik olarak ayrılan nesnelerin işaretçileri kullanılırken, bellekteki alanların silinmesini (delete) ihmal etmemek gerekir. Aksi takdirde bellek sızıntısı (memory leak) oluşabilir.

**Örnek: Dinamik Bellek Yönetimi**
```cpp
#include <iostream>

class MyClass
{
	public:
		int* data;
		MyClass(int val) {
			data = new int(val);  // Bellekte dinamik bir int nesnesi oluştur
			std::cout << "Nesne oluşturuldu, değer: " << *data << std::endl;
		}
		~MyClass() {
			delete data;  // Bellekteki veriyi serbest bırak
			std::cout << "Nesne yok edildi" << std::endl;
		}
};

int main()
{
    MyClass* obj = new MyClass(10);  // Dinamik olarak bir nesne oluştur
    delete obj;  // Nesneyi yok et ve belleği temizle

    return 0;
}
```
Bu örnekte, `MyClass` nesnesi heap'te dinamik olarak oluşturulur ve `delete` ile bellekten silinir.

### Özet

| **Konu**                    | **Üye Veri İşaretçileri (Member Data Pointers)**                                  | **Üye Fonksiyon İşaretçileri (Member Function Pointers)**                      |
|-----------------------------|-----------------------------------------------------------------------------------|--------------------------------------------------------------------------------|
| **Tanım**                   | Bir sınıfın veri üyelerine işaret eden işaretçiler.                               | Bir sınıfın üye fonksiyonlarına işaret eden işaretçiler.                       |
| **Sözdizimi**               | `int ClassName::* pointerToMember;`                                               | `ReturnType (ClassName::* pointerToFunction)(ParameterTypes);`                 |
| **Kullanım**                | Sınıfın veri üyelerine erişim sağlamak veya değiştirmek için kullanılır.          | Sınıfın üye fonksiyonlarını dinamik olarak seçmek ve çağırmak için kullanılır. |
| **Erişim Şekli**            | `object.*pointerToMember` ile üye değişkene erişilir.                             | `object.*pointerToFunction()` ile üye fonksiyona erişilir.                     |
| **Örnek Kullanım**          | `int MyClass::*ptr = &MyClass::value; obj.*ptr = 20;`                             | `void (MyClass::*funcPtr)() = &MyClass::display; (obj.*funcPtr)();`            |
| **Dinamik Bellek Yönetimi** | Bellekte dinamik olarak ayrılan veri üyelerine işaret ederken dikkat edilmelidir. | Dinamik olarak seçilen fonksiyonların yönetiminde dikkat edilmelidir.          |
| **Kullanım Alanları**       | Nesne veri üyelerine esnek erişim ve değiştirme.                                  | Dinamik fonksiyon seçimi, callback mekanizmaları, olay tabanlı programlama.    |

<br></br>

## Switch İfadesi
C++'ta **`switch` ifadesi**, bir değeri kontrol ederek bir dizi duruma göre (case) ilgili kod bloklarını çalıştırır. Özellikle **bir değişkenin birden çok sabit değere** sahip olabileceği durumlarda, çok sayıda **if-else** yapısı yerine daha düzenli ve okunabilir bir yapı sağlar. Genellikle tamsayı (`int`, `char`, vb.) ve sabit değerlerle çalışır.

### `switch` İfadesinin Sözdizimi
```cpp
switch (değer)
{
    case sabit1:
        // sabit1 ile eşleşirse bu kod bloğu çalıştırılır
        break;  // kontrolü switch'in dışına çıkarır
    case sabit2:
        // sabit2 ile eşleşirse bu kod bloğu çalıştırılır
        break;
    // İstediğiniz kadar case ekleyebilirsiniz
    default:
        // Hiçbir case ile eşleşmezse bu kod çalışır
        break;
}
```
- **`switch (değer)`**: `değer`, kontrol edilmek istenen değişkendir.
- **`case sabit:`**: `case` ile başlayan her blok, `değer`'in belirtilen sabit değerle eşleşip eşleşmediğini kontrol eder.
- **`break`**: `switch` ifadesinin çalışmasını durdurur ve kodu `switch` bloğunun dışına yönlendirir. **`break` kullanılmazsa**, kontrol akışı bir sonraki `case` bloğuna geçer. Bu, çoğu zaman istenmeyen bir davranış olabilir.
- **`default`**: Hiçbir `case` değeriyle eşleşmediğinde çalıştırılacak bloğu belirtir. `default` kullanımı zorunlu değildir, ancak genellikle bir yedek eylem sağlamak için faydalıdır.

### Örnek 1: Basit Bir `switch` Kullanımı
```cpp
#include <iostream>

int main()
{
    int num = 2;

    switch (num)
	{
        case 1:
            std::cout << "Sayı 1" << std::endl;
            break;
        case 2:
            std::cout << "Sayı 2" << std::endl;
            break;
        case 3:
            std::cout << "Sayı 3" << std::endl;
            break;
        default:
            std::cout << "Bilinmeyen sayı" << std::endl;
            break;
    }

    return 0;
}
```
- `num` değeri 2 olduğunda, `case 2` bloğu çalıştırılır ve ekrana "Sayı 2" yazdırılır.
- `break` kullanılarak, `switch` ifadesinden çıkılır. Eğer `break` kullanılmasaydı, sonraki tüm `case` blokları da çalıştırılırdı.

### Örnek 2: `char` Tipi ile `switch`
```cpp
#include <iostream>

int main()
{
    char grade = 'B';

    switch (grade)
	{
        case 'A':
            std::cout << "Mükemmel!" << std::endl;
            break;
        case 'B':
        case 'C':
            std::cout << "İyi!" << std::endl;
            break;
        case 'D':
            std::cout << "Kabul edilebilir" << std::endl;
            break;
        case 'F':
            std::cout << "Başarısız" << std::endl;
            break;
        default:
            std::cout << "Geçersiz not" << std::endl;
            break;
    }

    return 0;
}
```
- `grade` değişkeni `'B'` olduğu için **`case 'B'`** ve **`case 'C'`** blokları birlikte değerlendirilir. Çünkü `'B'` için bir `break` ifadesi yoktur, dolayısıyla `'C'` bloğuna düşer ve "İyi!" yazdırılır.
- `case 'B':` ve `case 'C':` arka arkaya yazılmıştır, bu da her iki durumda da aynı kodun çalıştırılmasını sağlar.

### Örnek 3: `default` İfadesi Kullanımı
```cpp
#include <iostream>

int main()
{
    int day = 7;

    switch (day)
	{
        case 1:
            std::cout << "Pazartesi" << std::endl;
            break;
        case 2:
            std::cout << "Salı" << std::endl;
            break;
        case 3:
            std::cout << "Çarşamba" << std::endl;
            break;
        case 4:
            std::cout << "Perşembe" << std::endl;
            break;
        case 5:
            std::cout << "Cuma" << std::endl;
            break;
        case 6:
            std::cout << "Cumartesi" << std::endl;
            break;
        case 7:
            std::cout << "Pazar" << std::endl;
            break;
        default:
            std::cout << "Geçersiz gün" << std::endl;
            break;
    }

    return 0;
}
```
- `day` değişkeni 7 olduğunda, `case 7` bloğu çalıştırılır ve "Pazar" yazdırılır.
- Eğer `day` değişkeni 1 ile 7 arasında değilse, **`default`** bloğu devreye girer ve "Geçersiz gün" yazdırılır.

### Örnek 4: `switch` ile `enum` Kullanımı
`switch` ifadesi, **enum (sabitler kümesi)** ile de kullanılabilir. Bu, durumsal kontrollerde sabit değerlerle çalışmayı kolaylaştırır.

```cpp
#include <iostream>

enum Color { RED, GREEN, BLUE };

int main()
{
    Color color = GREEN;

    switch (color)
	{
        case RED:
            std::cout << "Kırmızı" << std::endl;
            break;
        case GREEN:
            std::cout << "Yeşil" << std::endl;
            break;
        case BLUE:
            std::cout << "Mavi" << std::endl;
            break;
        default:
            std::cout << "Bilinmeyen renk" << std::endl;
            break;
    }

    return 0;
}
```
- Bu örnekte, `Color` adında bir `enum` türü tanımlanmıştır. `color` değişkeni `GREEN` olduğunda, **`case GREEN`** bloğu çalışır ve "Yeşil" yazdırılır.
- `enum` türleri, `switch` ifadelerinde sabit değerler olarak kullanılabilir ve kodun daha anlamlı olmasını sağlar.

### `switch`'in Avantajları ve Dezavantajları
#### Avantajları:
- **Okunabilirlik**: Bir değişkenin birden fazla sabit değere göre kontrol edilmesi gerekiyorsa, if-else bloklarına göre daha okunaklı ve düzenli bir yapı sağlar.
- **Performans**: Derleyiciler, `switch` ifadelerini genellikle daha hızlı çalıştırmak için optimize eder. Özellikle sabit değerlere karşı yapılan kontrollerde daha hızlı olabilir.
- **Modülerlik**: Duruma göre farklı işlemleri modüler bir şekilde yapmanıza olanak tanır.

#### Dezavantajları:
- **Dinamik Değerler Yok**: `switch` sadece **sabit değerlere** göre çalışır. Bu yüzden koşullu ifadeler ya da dinamik hesaplamalar ile `case` yapılamaz.
- **Tüm Veri Türleriyle Çalışmaz**: Sadece tam sayı ve `enum` gibi belirli türlerle çalışır. `float`, `double` gibi kayan nokta türleri veya karmaşık veri türleri ile kullanılamaz.

### `switch`'in Limitleri:
- `switch`, yalnızca tamsayılar (veya tamsayıya çevrilebilen türler) ile çalışır. `char`, `int`, `enum`, ve `bool` gibi türleri destekler, ancak `float`, `double`, veya `string` ile çalışmaz.

### Özet

| **Kavram**       | **Açıklama**                                                                                        | **Örnek**               |
|------------------|-----------------------------------------------------------------------------------------------------|-------------------------|
| **`switch`**     | Bir değişkenin değerini sabitlerle karşılaştırarak, ilgili kod bloklarını çalıştırır.               | `switch (value) { ... }`|
| **`case`**       | Kontrol edilecek sabit değerleri belirtir. Eşleşirse ilgili kod çalıştırılır.                       | `case 1: // kod bloğu`  |
| **`break`**      | Kontrol akışını `switch` bloğunun dışına çıkartır. Kullanılmazsa sonraki `case` blokları da çalışır.| `break;`                |
| **`default`**    | Hiçbir `case` sabiti ile eşleşme olmazsa çalıştırılacak kod bloğunu belirtir.                       | `default: // kod bloğu` |
| **Desteklenen Türler**    | `int`, `char`, `enum`, `bool` gibi tamsayı türleri ile çalışır.                  | `int`, `char`, `enum`, `bool` türleri ile kullanılabilir.     |
| **Desteklenmeyen Türler** | `float`, `double`, `string` gibi türlerle kullanılamaz.                          | `switch` ifadesi bu türlerle çalışmaz.                        |
| **Kullanım Avantajı**     | Daha okunabilir ve performans açısından optimize edilmiş kontrol yapıları sağlar.| Çoklu `if-else` yerine, daha düzenli ve hızlı bir yapı sağlar.|
| **Kullanım Dezavantajı**  | Sadece sabit değerlerle çalışır. Dinamik değerlerle kullanılamaz ve tüm veri türlerini desteklemez.| Dinamik koşullu ifadelerle veya karmaşık veri türleriyle kullanılamaz.|

<br></br>
