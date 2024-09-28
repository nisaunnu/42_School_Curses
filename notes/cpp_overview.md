## İçerik

- [İçerik](#i̇çerik)
- [C++ Genel Bakış](#c-genel-bakış)
	- [➤ C++ Nedir?](#-c-nedir)
	- [➤ C++'ın Bazı Temel Özellikleri](#-cın-bazı-temel-özellikleri)
- [C++ 98 Nedir?](#c-98-nedir)
	- [➤ C++ Sürümlerinin Karşılaştırılması](#-c-sürümlerinin-karşılaştırılması)
- [Temel Dosya Uzantıları](#temel-dosya-uzantıları)
	- [➤ Açıklamalar](#-açıklamalar)
	- [➤ Derleme ve Bağlama Süreci](#-derleme-ve-bağlama-süreci)
- [Temel İfadelerin Anlamları](#temel-i̇fadelerin-anlamları)

<br></br>

## C++ Genel Bakış

### ➤ C++ Nedir?

C++, geniş bir kullanım alanına sahip, güçlü ve çok yönlü bir programlama dilidir. 1980'lerin başında Bjarne Stroustrup tarafından geliştirilen C++, C dilinin üzerine nesne yönelimli programlama (OOP) ve diğer yüksek seviyeli özellikler ekleyerek oluşturulmuştur.

### ➤ C++'ın Bazı Temel Özellikleri

1. **Nesne Yönelimli Programlama (OOP)**: C++, sınıflar ve nesneler aracılığıyla kodun daha düzenli ve yönetilebilir olmasını sağlayan OOP desteği sunar. Bu, miras, çok biçimlilik (polymorphism), kapsülleme (encapsulation) ve soyutlama (abstraction) gibi OOP prensiplerini içerir.
2. **Yüksek Performans**: C++ derlenen bir dil olduğu için, yazılan kod doğrudan makine diline çevrilir ve bu da yüksek performans sağlar. Bu nedenle C++, sistem programlama, oyun geliştirme, gerçek zamanlı sistemler ve yüksek performans gerektiren uygulamalar için sıkça tercih edilir.
3. **Standart Kütüphane (Standard Library)**: C++, geniş bir standart kütüphane ile birlikte gelir. Bu kütüphane, veri yapıları, algoritmalar, girdi/çıktı işlemleri ve diğer yaygın programlama görevleri için kullanışlı araçlar sunar.
4. **Düşük Seviye Bellek Yönetimi**: C++ programcılarına bellek yönetimi üzerinde doğrudan kontrol sağlar. Geliştiriciler dinamik bellek tahsisi ve serbest bırakma işlemlerini manuel olarak yönetebilirler. Bu, performansı artırabilir ancak aynı zamanda bellek sızıntıları ve diğer hatalara da yol açabilir.
5. **Çoklu Paradigma Desteği**: C++, sadece OOP değil, aynı zamanda prosedürel programlama, generic programming ve fonksiyonel programlama gibi çeşitli programlama paradigmalarını da destekler. Bu, programcıların farklı yaklaşımları birleştirerek daha esnek ve güçlü çözümler geliştirmesine olanak tanır.

<br></br>

## C++ 98 Nedir?

C++ 98, C++ dilinin ilk geniş çapta kabul edilen ve kullanılan standardıdır. Sonraki sürümler olan C++ 03, C++ 11, C++ 14, C++ 17, C++ 20, ve C++ 23, dilde önemli iyileştirmeler ve eklemeler yapmıştır.

### ➤ C++ Sürümlerinin Karşılaştırılması

| Sürüm  | Yayın Yılı | Özellikler | C++ 98'den Farklar |
| ------ | ---------- | ---------- | ------------------ |
| C++ 98 | 1998       | C++ dilinin ilk tam standardı. Temel OOP özellikleri, STL (Standard Template Library), namespaces, exceptions içerir. | Temel özellikler tanıtıldı, ama modern C++ özellikleri eksikti. |
| C++ 03 | 2003       | C++ 98'in ufak tefek hata düzeltmeleri ve küçük iyileştirmelerle güncellenmiş hali. | C++ 98 ile neredeyse aynıdır. Özellikle bazı STL implementasyon hataları düzeltildi.  |
| C++ 11 | 2011       | Büyük bir güncelleme: `auto`, `lambda` ifadeleri, `range-based for` döngüsü, `nullptr`, `std::thread`, `std::shared_ptr` vb. | Modern C++'ın başlangıcı olarak kabul edilir. C++ 98'e göre çok daha esnek ve güçlü bir dil haline geldi. |
| C++ 14 | 2014       | C++ 11'e dayalı iyileştirmeler ve küçük eklemeler: `lambda` fonksiyonları için genelleştirilmiş yakalama, binary literals | C++ 11'deki bazı karmaşıklıklar giderildi, ek iyileştirmeler ve küçük özellikler eklendi. |
| C++ 17 | 2017       | Daha fazla dil özelliği: `std::optional`, `std::variant`, `if constexpr`, `inline variables`, `structured bindings` vb. | C++ 11 ve 14'ün üzerine, daha güçlü bir dil haline geldi. Yine performans ve kod okunabilirliği iyileştirildi. |
| C++ 20 | 2020       | Konseptler, ranges, coroutines, modules, `std::format`, coroutines ve daha fazlası | C++ diline devrim niteliğinde eklemeler yapıldı. Modüler yapılar ve paralel programlama desteği genişletildi. |
| C++ 23 | 2023       | Küçük eklemeler ve düzeltmeler: `std::expected`, `if consteval`, `enhanced enums`, ve yeni kütüphane güncellemeleri | C++ 20'de başlatılan birçok özelliğin gelişmiş hali. Stabilite ve kullanım kolaylığı artırıldı. |

C++ 98, C++ dilinin temelini atan sürümdür, ancak modern programlama gereksinimlerini karşılamak için sonraki sürümler önemli ölçüde genişletilmiştir. C++ 11, modern C++'ın başlangıcı olarak kabul edilir ve sonraki sürümler (C++ 14, 17, 20, 23) bu temel üzerine eklemeler yaparak dili daha güçlü, esnek ve kullanımı kolay hale getirmiştir.

<br></br>

## Temel Dosya Uzantıları

| Dosya Uzantısı | Açıklama                                                                                                          | Örnekler                    |
| -------------- | ----------------------------------------------------------------------------------------------------------------- | --------------------------- |
| `.cpp`         | C++ kaynak dosyası. C++ kodunu içerir ve derleme sürecinin ilk aşamasında derleyici tarafından işlenir.           | `main.cpp`, `utils.cpp`     |
| `.h / .hpp`    | C++ başlık dosyası. Fonksiyon prototipleri, sınıf tanımları ve diğer bildirimleri içerir.                         | `main.h`, `utils.hpp`       |
| `.o / .obj`    | Nesne dosyası. Kaynak dosyaların derlenmesi sonucu oluşturulan ara dosyalardır.                                   | `main.o`, `utils.obj`       |
| `.exe`         | Çalıştırılabilir dosya. Derleme ve bağlama işlemlerinin ardından oluşturulan çalıştırılabilir program dosyasıdır. | `program.exe`               |
| `.lib / .a`    | Statik kütüphane dosyası. Derlenmiş kodların statik olarak bağlanmasını sağlar.                                   | `library.lib`, `library.a`  |
| `.dll / .so`   | Dinamik kütüphane dosyası. Program çalışırken dinamik olarak bağlanabilen kütüphanelerdir.                        | `library.dll`, `library.so` |

### ➤ Açıklamalar

- **Kaynak Dosyaları (`.cpp`)**
	- **Açıklama**: C++ kodunuzu içerir. Derleme sürecinin ilk aşamasında derleyici tarafından işlenir.
	- **Örnek**: `main.cpp`

		```cpp
		#include <iostream>
		#include "utils.h"

		int main() {
			std::cout << "Hello, World!" << std::endl;
			return 0;
		}

		// Çıktı : Hello World!
		```

	- **Örnek**: `utils.cpp`

		```cpp
		#include <iostream>
		#include "utils.h"

		void printMessage() {
			std::cout << "Hello from utils!" << std::endl;
		}

		// Çıktı : Hello from utils!

		```

- **Başlık Dosyaları (`.h`, `.hpp`)**
	- **Açıklama**: Fonksiyon ve sınıf bildirimlerini içerir. Bu dosyalar, kaynak dosyalar tarafından `#include` direktifi ile eklenir.
	- Bir üstte tanımlanmış olan "Kaynak Dosyaları" başlığında bulunan örnekte `#include "utils.h"` kod satırı ile başlık dosyasını kaynak dosyasına ekleme durumu gösterilmiştir.
	- **Örnek**: `utils.h`

		```cpp
		#ifndef UTILS_H
		#define UTILS_H

		void printMessage();

		#endif
		```


### ➤ Derleme ve Bağlama Süreci

1. **Derleme**: Kaynak dosyalar (`.cpp`) nesne dosyalarına (`.o`, `.obj`) dönüştürülür.
2. **Bağlama**: Nesne dosyaları, çalıştırılabilir bir program (`.exe`) oluşturmak için bağlanır.

<br></br>

## Temel İfadelerin Anlamları
Çıktıya `Hello World!` yazdıralım:

```cpp
#include <iostream>

int main()
{
	std::cout << "Hello World!" << std::endl;
}
```

Kodun detayları:
* `#include <iostream>` -> standart C++ üstbilgi dosyası iostream'in (standard input output stream) içeriğini içeren bir önişlemci yönergesidir.
  * iostream, standart giriş ve çıkış akışlarının tanımlarını içeren standart bir kitaplık üstbilgi dosyasıdır.
  * Standart giriş/çıkış (G/Ç) akışları, programların harici bir sistemden - genellikle terminalden - giriş ve çıkış alması için yollar sağlar.
* `int main() { ... }` -> main adında yeni bir işlev tanımlar.
  * Kural olarak, programın yürütülmesi üzerine ana işlev çağrılır.
  * Bir C++ programında yalnızca bir ana işlev olmalı ve her zaman int türünde bir sayı döndürmelidir.
  * Burada int, işlevin dönüş türü olarak adlandırılan şeydir. Ana işlev tarafından döndürülen değer bir çıkış kodudur.
  * Kural olarak, 0 veya EXIT_SUCCESS program çıkış kodu, programı yürüten bir sistem tarafından başarı olarak yorumlanır. Başka herhangi bir dönüş kodu bir hatayla ilişkilendirilir.
  * Return ifadesi yoksa, ana işlev (ve dolayısıyla programın kendisi) varsayılan olarak 0 değerini döndürür. Bu örnekte, açıkça return 0 yazmamıza gerek yoktur.
  * Void türünü döndürenler dışındaki diğer tüm işlevler, dönüş türlerine göre açıkça bir değer döndürmeli veya hiç döndürmemelidir.
* `std::cout << "Hello World!" << std::endl;` -> "Hello World!" standart çıkışa yazdırılır:
  * `std::cout` -> standart çıkış akışıdır.
	* `std` -> bir ad alanıdır (namespaces).
	* `::` -> ad alanı (namespaces) içindeki nesneleri ada göre aramanıza izin veren kapsam çözümleme işlecidir.
	* Birçok ad alanı (namespaces) var. Burada, `std` ad alanından `cout` kullanmak istediğimizi göstermek için `::` kullanıyoruz.
	* `std::cout` -> iostream'de tanımlanan standart çıktı akışı nesnesidir ve çıktıyı standarda yazdırır (stdout).
  * `<<` -> akış nesnesine bir nesne eklediği için **akış ekleme işleci** olarak adlandırılır.

	> Standart kitaplık, belirli veri türleri için çıktı akışlarına veri ekleme işlemini gerçekleştirmek üzere `<<` işlecini tanımlar. Akış (std::cout) + `<<` + içerik ("Hello World!"), akışa içerik ekler ve aynı, ancak güncellenmiş akışı döndürür. Bu, akış eklemelerinin zincirlenmesine izin verir: `std::cout << "Foo" << " Bar";` konsola `"FooBar"` yazdırır.

  * "Hello World!" bir karakter dizesi değişmezi veya bir "metin değişmezidir". Karakter dizesi değişmezleri için akış ekleme işleci, iostream dosyasında tanımlanır.

<br></br>

