## CPP Module 00 Notları
- [Temel Stdio Streamleri](#temel-stdio-streamleri)
- [`<iostream>` Kütüphanesi](#iostream-kütüphanesi)
	- [➤ `<iostream>` Kütüphanesinin İçeriği](#-iostream-kütüphanesinin-i̇çeriği)
		- [1. `std::istream` Sınıfı](#1-stdistream-sınıfı)
		- [2. `std::ostream` Sınıfı](#2-stdostream-sınıfı)
		- [3. `std::cin`, `std::cout`, `std::cerr`, `std::clog` Nesneleri](#3-stdcin-stdcout-stdcerr-stdclog-nesneleri)
		- [4. `std::fstream`, `std::ifstream`, `std::ofstream` (Ekstra: `<fstream>` Kütüphanesi)](#4-stdfstream-stdifstream-stdofstream-ekstra-fstream-kütüphanesi)
		- [5. `std::endl` ve `std::flush` Manipülatörleri](#5-stdendl-ve-stdflush-manipülatörleri)
		- [6. `std::ws` Manipülatörü](#6-stdws-manipülatörü)
- [STL (Standard Template Library) Nedir?](#stl-standard-template-library-nedir)
- [Class (Sınıf) Yapıları](#class-sınıf-yapıları)
	- [➤ Sınıf Yapısı](#-sınıf-yapısı)
	- [➤ Sınıfın Kullanımı](#-sınıfın-kullanımı)
	- [➤ Erişim Belirleyicilerin Detaylandırılması](#-erişim-belirleyicilerin-detaylandırılması)
		- [1. `public` Erişim Belirleyicisi](#1-public-erişim-belirleyicisi)
		- [2. `private` Erişim Belirleyicisi](#2-private-erişim-belirleyicisi)
		- [3. `protected` Erişim Belirleyicisi](#3-protected-erişim-belirleyicisi)
	- [➤ Genellikle Veri Üyeleri Neden `private` Altında Tanımlanır?](#-genellikle-veri-üyeleri-neden-private-altında-tanımlanır)
		- [1. Kapsülleme (Encapsulation)](#1-kapsülleme-encapsulation)
		- [2. Kullanıcı Arayüzü (Interface) Tasarımı](#2-kullanıcı-arayüzü-interface-tasarımı)
		- [3. Gelecekteki Değişikliklerin Kolay Yönetimi](#3-gelecekteki-değişikliklerin-kolay-yönetimi)
		- [4. Kötüye Kullanımın Önlenmesi](#4-kötüye-kullanımın-önlenmesi)
	- [➤ Destructor Kullanımı](#-destructor-kullanımı)
		- [Yıkıcının Rolü](#yıkıcının-rolü)
		- [Yıkıcı Olmadığında](#yıkıcı-olmadığında)
	- [➤ `this` İşareti](#-this-i̇şareti)
		- [Kullanım Alanları](#kullanım-alanları)
		- [`this` İşaretinin Özellikleri](#this-i̇şaretinin-özellikleri)
- [Member Fonksiyonlar](#member-fonksiyonlar)
	- [➤ Member Fonksiyonların Kullanımı ve Önemi](#-member-fonksiyonların-kullanımı-ve-önemi)
	- [➤ Member Fonksiyon Örneği](#-member-fonksiyon-örneği)
	- [➤ Getter ve Setter Fonksiyonları](#-getter-ve-setter-fonksiyonları)
		- [Getter Fonksiyonları:](#getter-fonksiyonları)
		- [Setter Fonksiyonları:](#setter-fonksiyonları)
		- [Örnek: `Person` Sınıfı ile Getter ve Setter Fonksiyonları](#örnek-person-sınıfı-ile-getter-ve-setter-fonksiyonları)
	- [➤ Neden Getter ve Setter Kullanılır?](#-neden-getter-ve-setter-kullanılır)
- [Temel Veri Yapıları ve Sınıflar](#temel-veri-yapıları-ve-sınıflar)
	- [1. `std::string`](#1-stdstring)
		- [Detaylı Özellikler](#detaylı-özellikler)
		- [Detaylı Örnek](#detaylı-örnek)
	- [2. `std::vector`](#2-stdvector)
		- [Detaylı Özellikler](#detaylı-özellikler-1)
		- [Detaylı Örnek](#detaylı-örnek-1)
	- [3. `std::map`](#3-stdmap)
		- [Detaylı Özellikler](#detaylı-özellikler-2)
		- [Detaylı Örnek](#detaylı-örnek-2)
	- [4. `std::set`](#4-stdset)
		- [Detaylı Özellikler](#detaylı-özellikler-3)
		- [Detaylı Örnek](#detaylı-örnek-3)
	- [5. `std::queue`](#5-stdqueue)
		- [Detaylı Özellikler](#detaylı-özellikler-4)
		- [Detaylı Örnek](#detaylı-örnek-4)
	- [6. `std::stack`](#6-stdstack)
		- [Detaylı Özellikler](#detaylı-özellikler-5)
		- [Detaylı Örnek](#detaylı-örnek-5)
- [Template Nedir?](#template-nedir)
	- [Temel Tanım](#temel-tanım)
	- [Temel Türleri](#temel-türleri)
	- [Kullanım Alanları](#kullanım-alanları-1)
	- [Fonksiyon Templatelere Örnek](#fonksiyon-templatelere-örnek)
	- [Sınıf Templatelere Örnek](#sınıf-templatelere-örnek)
	- [Template Parametreleri](#template-parametreleri)
	- [Derleme Zamanı ve Uzmanlaşma](#derleme-zamanı-ve-uzmanlaşma)
- [Implement Edilen Dosya Ne Demek?](#implement-edilen-dosya-ne-demek)
- [Korunmayan Header Dosyası](#korunmayan-header-dosyası)
- [`std::string` için Kütüphane Sorunu](#stdstring-için-kütüphane-sorunu)
- [Başlatma Listeleri (Initialization Lists)](#başlatma-listeleri-initialization-lists)
	- [➤ Başlatma Listesinin Kullanım Nedenleri](#-başlatma-listesinin-kullanım-nedenleri)
	- [➤ Başlatma Listesi Nasıl Kullanılır?](#-başlatma-listesi-nasıl-kullanılır)
		- [Örnek: Başlatma Listesi Kullanımı](#örnek-başlatma-listesi-kullanımı)
- [`static` ve `const` Anahtar Kelimeleri](#static-ve-const-anahtar-kelimeleri)
	- [➤ `static` Anahtar Kelimesi](#-static-anahtar-kelimesi)
	- [➤ `const` Anahtar Kelimesi](#-const-anahtar-kelimesi)
- [`static_cast` Operatörü](#static_cast-operatörü)
	- [➤ Örnek ile `static_cast` Kullanımı ve Güvenliği](#-örnek-ile-static_cast-kullanımı-ve-güvenliği)
	- [➤ Neden `static_cast` Kullanmalıyız?](#-neden-static_cast-kullanmalıyız)
- [Nesneye Yönelimli Programlama (OOP)](#nesneye-yönelimli-programlama-oop)
	- [➤ Temel Kavramlar](#-temel-kavramlar)
	- [➤ OOP'nin Faydaları](#-oopnin-faydaları)
- [Namespace (Ad Alanı)](#namespace-ad-alanı)
	- [➤ `namespace` Kullanımının Temel Faydaları](#-namespace-kullanımının-temel-faydaları)
		- [Örneklerle Açıklanması](#örneklerle-açıklanması)
		- [Dezavantajlar](#dezavantajlar)
	- [➤ `namespace` Hatalı Kullanımı](#-namespace-hatalı-kullanımı)
		- [1. İsim Çakışmaları ve `using namespace` Hatası](#1-i̇sim-çakışmaları-ve-using-namespace-hatası)
		- [2. Global Namespace Kirliliği](#2-global-namespace-kirliliği)
		- [3. İç İçe (Nested) `namespace` Kullanımında Yanlış Yönlendirme](#3-i̇ç-i̇çe-nested-namespace-kullanımında-yanlış-yönlendirme)
		- [4. Farklı Dosyalarda `namespace` İle Çakışma](#4-farklı-dosyalarda-namespace-i̇le-çakışma)
		- [5. Kapsam Dışı Kalan `namespace` Elemanları](#5-kapsam-dışı-kalan-namespace-elemanları)
- [`friend` Nedir?](#friend-nedir)

<br></br>

## Temel Stdio Streamleri

C++'de **stdio streamleri**, giriş (input) ve çıkış (output) işlemlerini gerçekleştirmek için kullanılan akışlardır (streams). Bu akışlar, standart giriş ve çıkış cihazlarıyla (örneğin klavye ve ekran) veri alışverişi yapmak için kullanılır.

Temel stdio stream'leri:

1. **`std::cin` (Standard Input Stream):**
   - Kullanıcıdan veri almak için kullanılır.
   - Klavyeden veri okumak amacıyla kullanılır.
   - `std::cin` genellikle `>>` operatörü ile birlikte kullanılır. Örneğin:
     ```cpp
     int age;
     std::cin >> age;
     ```

2. **`std::cout` (Standard Output Stream):**
   - Ekrana veri yazdırmak için kullanılır.
   - Çıkış verilerini terminale (veya komut satırına) yazdırmak için kullanılır.
   - `std::cout` genellikle `<<` operatörü ile birlikte kullanılır. Örneğin:
     ```cpp
     std::cout << "Hello, World!" << std::endl;
     ```

3. **`std::cerr` (Standard Error Stream):**
   - Hata mesajlarını veya önemli uyarıları ekrana yazdırmak için kullanılır.
   - `std::cout` gibi davranır, ancak genellikle hata veya uyarı mesajları için kullanılır.
   - `std::cerr` da `<<` operatörü ile birlikte kullanılır. Örneğin:
     ```cpp
     std::cerr << "An error occurred!" << std::endl;
     ```

4. **`std::clog` (Standard Log Stream):**
   - Genel bilgilendirme mesajları ve loglama için kullanılır.
   - `std::cerr` gibi `<<` operatörü ile kullanılır.
   - Örneğin:
     ```cpp
     std::clog << "Starting the application..." << std::endl;
     ```

<br></br>

## `<iostream>` Kütüphanesi

`<iostream>` kütüphanesi, C++'ta giriş ve çıkış işlemleri için kullanılan temel kütüphanedir. Bu kütüphane, akış (stream) kavramı üzerine kuruludur ve veri akışlarını yönetir. `<iostream>` kütüphanesi, giriş ve çıkış işlemleri için kullanabileceğiniz çeşitli sınıfları ve nesneleri içerir.

### ➤ `<iostream>` Kütüphanesinin İçeriği

#### 1. `std::istream` Sınıfı
- **Tanım:** `std::istream` (input stream), giriş işlemleri için kullanılan temel sınıftır. Klavye veya dosya gibi bir kaynaktan veri almanızı sağlar.
- **Kullanım:** `std::cin`, bir `std::istream` nesnesidir ve standart giriş (genellikle klavye) için kullanılır.

  **Örnek:**
  ```cpp
  #include <iostream>

  int main()
  {
    int age;

    std::cout << "Enter your age: ";
    std::cin >> age;  // Kullanıcıdan yaşını girmesini ister.
    std::cout << "Your age is " << age << std::endl;

    return 0;
  }
  ```

#### 2. `std::ostream` Sınıfı
- **Tanım:** `std::ostream` (output stream), çıkış işlemleri için kullanılan temel sınıftır. Veri yazmanızı sağlar, genellikle ekran veya dosya gibi bir hedefe yazılır.
- **Kullanım:** `std::cout`, bir `std::ostream` nesnesidir ve standart çıkış (genellikle ekran) için kullanılır. `std::cerr` ve `std::clog` de `std::ostream` türündedir ve sırasıyla hata mesajları ve günlükler (logs) için kullanılır.

  **Örnek:**
  ```cpp
  #include <iostream>

  int main()
  {
    std::cout << "Hello, World!" << std::endl;  // Ekrana mesaj yazar.
    std::cerr << "This is an error message." << std::endl;  // Hata mesajı olarak yazar.
    std::clog << "This is a log message." << std::endl;  // Günlük mesajı olarak yazar.

	return 0;
  }
  ```

#### 3. `std::cin`, `std::cout`, `std::cerr`, `std::clog` Nesneleri
- **`std::cin`:** Standart giriş akışı. Kullanıcıdan veri almak için kullanılır.
- **`std::cout`:** Standart çıkış akışı. Veriyi ekrana yazmak için kullanılır.
- **`std::cerr`:** Standart hata çıkış akışı. Hata mesajlarını yazmak için kullanılır (genellikle `std::cout` gibi çalışır, ancak bufferlanmaz).
- **`std::clog`:** Standart log çıkış akışı. Günlük mesajlarını yazmak için kullanılır (genellikle `std::cerr` ile aynı yöne yönlendirilir, ancak bufferlanır).

#### 4. `std::fstream`, `std::ifstream`, `std::ofstream` (Ekstra: `<fstream>` Kütüphanesi)
- **Tanım:** Bu sınıflar, dosya giriş ve çıkışı için kullanılır. `<iostream>` kütüphanesi doğrudan bu sınıfları içermez, ancak `<iostream>` ile çok yakından ilişkilidir ve genellikle birlikte kullanılır.
  - **`std::ifstream`:** Dosyadan okuma işlemi için kullanılır (`input file stream`).
  - **`std::ofstream`:** Dosyaya yazma işlemi için kullanılır (`output file stream`).
  - **`std::fstream`:** Hem okuma hem yazma işlemi için kullanılır (`file stream`).

#### 5. `std::endl` ve `std::flush` Manipülatörleri
- **`std::endl`:** Satır sonu karakteri ekler (`'\n'`) ve akışı flush eder (yani buffer'ı temizler ve veriyi hemen yazar).
- **`std::flush`:** Akışı flush eder ancak satır sonu karakteri eklemez.

  **Örnek:**
  ```cpp
  #include <iostream>

  int main()
  {
    std::cout << "First line" << std::endl;  // Satır sonu ekler ve akışı flush eder.
    std::cout << "Second line" << std::flush;  // Sadece flush eder, satır sonu eklemez.

	return 0;
  }
  ```

#### 6. `std::ws` Manipülatörü
- **Tanım:** `std::ws`, giriş akışındaki beyaz boşluk karakterlerini (whitespace) atlamak için kullanılır. Boşluk karakterleri, tab karakterleri ve yeni satır karakterleri bu gruba dahildir.

  **Örnek:**
  ```cpp
  #include <iostream>

  int main()
  {
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> std::ws;  // Boşluk karakterlerini atla.
    std::getline(std::cin, name);  // Kullanıcıdan tam bir satır al.
    std::cout << "Hello, " << name << std::endl;

	return 0;
  }
  ```

<br></br>

## STL (Standard Template Library) Nedir?
C++'da STL, standart kütüphaneye dahil olan bir koleksiyonlar ve algoritmalar setidir. STL, genellikle veri yapılarını ve algoritmaları genel bir şekilde kullanabilmenizi sağlar. STL'nin başlıca bileşenleri şunlardır:

1. **Kapsayıcılar (Containers)**: Verileri saklayan sınıflardır. Örnekler:
   - `vector`: Dinamik dizi
   - `list`: Çift bağlı liste
   - `deque`: Çift uçlu kuyruk
   - `set`: Benzersiz elemanlar içeren koleksiyon
   - `map`: Anahtar-değer çiftleri içeren koleksiyon

2. **Algoritmalar (Algorithms)**: Koleksiyonlar üzerinde işlem yapmanızı sağlayan fonksiyonlardır. Örnekler:
   - `sort()`: Sıralama
   - `find()`: Arama
   - `accumulate()`: Toplama
   - `count()`: Eleman sayısı

3. **İteratörler (Iterators)**: Koleksiyonlar üzerindeki elemanlara erişim sağlar ve bu koleksiyonlarda gezinebilmenizi mümkün kılar.

4. **Fonksiyon Nesneleri (Function Objects)**: Fonksiyon gibi davranan nesnelerdir. Örneğin, `std::greater` ve `std::less` gibi.

STL, şablonlar kullanarak genel veri yapılarını ve algoritmaları tanımlar, bu sayede farklı türlerle çalışabilir ve yeniden kullanılabilir kod yazabilirsiniz.

<br></br>

## Class (Sınıf) Yapıları

Sınıf (class) yapıları, nesne yönelimli programlamanın temel taşlarıdır ve kodunuzu organize etmenin yanı sıra veri ve işlevleri bir arada tutmanıza olanak tanır.

### ➤ Sınıf Yapısı

1. **Sınıf Tanımlama:**
   C++'ta bir sınıfı `class` anahtar kelimesi ile tanımlarsınız. Sınıf, veri üyeleri (özellikler) ve üye işlevlerden (metotlar) oluşur.

   ```cpp
   class MyClass
   {
		public:
			// Üye işlevler yani fonksiyonlar
			void myFunction();

		private:
			// Üye değişkenler
			int myVariable;
   };
   ```

   Bu örnekte, `MyClass` adında bir sınıf tanımladık. Sınıfın içinde `public` ve `private` erişim belirleyicileri kullanarak üyeleri belirledik.

2. **Erişim Belirleyiciler:**
   - `public`: Bu erişim belirleyicisi altında tanımlanan üyeler, sınıfın dışında da erişilebilir.
   - `private`: Bu erişim belirleyicisi altında tanımlanan üyeler, sadece sınıfın içinden erişilebilir. Dışarıdan erişilemezler.
   - `protected`: Bu erişim belirleyicisi, üyelerin sınıfın ve türemiş sınıfların içinde erişilebilir olmasını sağlar. Dışarıdan erişim engellenir.

3. **Kapsülleme:**
   Kapsülleme, verileri ve işlevleri bir arada tutarak, verilerin yalnızca belirli işlevler aracılığıyla erişilmesini sağlar. Bu, verilerin güvenliğini ve nesne tutarlılığını sağlar.

### ➤ Sınıfın Kullanımı

1. **Sınıf Üyesi Değişkenler ve Fonksiyonlar:**
   Bir sınıfın üye değişkenleri ve işlevleri sınıfın tanımında belirtilir ve sınıfın bir örneği oluşturulduğunda kullanılabilir.

	```cpp
	class MyClass
	{
		public:
			void setVariable(int value) {
				myVariable = value;
			}

			int getVariable() {
				return myVariable;
			}

		private:
			int myVariable;
	};
	```

   Burada `setVariable` ve `getVariable` işlevleri, `myVariable` adlı özel değişkene erişim sağlar.

2. **Nesne Oluşturma:**
   Bir sınıfın örneğini oluşturmak için sınıf (class) adını kullanır ve bir değişken tanımlarsınız.

   ```cpp
   MyClass obj;  // MyClass türünde bir nesne oluşturur
   obj.setVariable(10);  // Nesnenin üye işlevini çağırır
   int value = obj.getVariable();  // Üye işlevi ile değeri alır
   ```

3. **Kapsayıcı (Constructor) ve Yıkıcı (Destructor):**
   Sınıflarda özel işlevler olan yapıcı (constructor) ve yıkıcı (destructor) kullanabilirsiniz.

   ```cpp
   class MyClass {
   public:
       MyClass() { // Yapıcı
           myVariable = 0;
       }

       ~MyClass() { // Yıkıcı
           // Temizlik kodları
       }

   private:
       int myVariable;
   };
   ```

   Yapıcı işlev, sınıfın bir örneği oluşturulduğunda çağrılır, yıkıcı işlev ise nesne yok edilirken çağrılır.

4. **Kalıtım:**
   C++'ta bir sınıf başka bir sınıftan türeyebilir (inheritance). Bu, kodun yeniden kullanılmasını ve genişletilmesini sağlar.

   ```cpp
   class Base
   {
		public:
			void baseFunction() {}
   };

   class Derived : public Base
   {
		public:
			void derivedFunction() {}
   };
   ```

   Burada `Derived` sınıfı `Base` sınıfından türemiştir ve `Base` sınıfının işlevlerine erişebilir.

### ➤ Erişim Belirleyicilerin Detaylandırılması
Erişim belirleyiciler, C++ gibi nesne yönelimli programlama dillerinde sınıf üyelerinin (veri üyeleri ve üye fonksiyonları) hangi alanlardan erişilebileceğini belirler.

#### 1. `public` Erişim Belirleyicisi
`public` erişim belirleyicisi altında tanımlanan üyeler, sınıfın dışından herhangi bir yerden erişilebilir.

```cpp
#include <iostream>

class MyClass // Sınıf tanımı
{
	public:
		int publicVariable;

		void publicMethod() {
			std::cout << "This is a public method." << std::endl;
		}
};

int main()
{
    MyClass obj;
    obj.publicVariable = 5;  // Erişim mümkün
    obj.publicMethod();      // Erişim mümkün

    return 0;
}
```

**Sonuç:** `publicVariable` ve `publicMethod` sınıfın dışından doğrudan erişilebilir.

#### 2. `private` Erişim Belirleyicisi
`private` erişim belirleyicisi altında tanımlanan üyeler, sadece sınıfın içinden erişilebilir. Sınıf dışından doğrudan erişim mümkün değildir.

```cpp
#include <iostream>

class MyClass
{
	private:
		int privateVariable;

		void privateMethod() {
			std::cout << "This is a private method." << std::endl;
		}

	public:
		void accessPrivate() {
			privateVariable = 10; // Erişim mümkün, çünkü sınıf içinde
			privateMethod();      // Erişim mümkün, çünkü sınıf içinde
		}
};

int main()
{
    MyClass obj;
    // obj.privateVariable = 5;  // HATA: Erişim mümkün değil
    // obj.privateMethod();      // HATA: Erişim mümkün değil
    obj.accessPrivate();         // Erişim mümkün, çünkü public method

    return 0;
}
```

**Sonuç:**
- `privateVariable` ve `privateMethod` sınıf dışından doğrudan erişilemez, ancak sınıf içinden erişilebilir.
- `accessPrivate` fonksiyonu üzerinden dolaylı olarak erişim sağlanabilir.

#### 3. `protected` Erişim Belirleyicisi
`protected` erişim belirleyicisi altında tanımlanan üyeler, sınıfın ve türemiş sınıfların (alt sınıflar) içinde erişilebilir. Ancak, sınıf dışından doğrudan erişim mümkün değildir.

```cpp
#include <iostream>

class BaseClass
{
	protected:
		int protectedVariable;

		void protectedMethod() {
			std::cout << "This is a protected method." << std::endl;
		}
};

class DerivedClass : public BaseClass // BaseClass'tan türetilmiş sınıf
{
	public:
		void accessProtected() {
			protectedVariable = 15; // Erişim mümkün, çünkü türemiş sınıf içinde
			protectedMethod();      // Erişim mümkün, çünkü türemiş sınıf içinde
		}
};

int main()
{
    DerivedClass obj;
    // obj.protectedVariable = 5;  // HATA: Erişim mümkün değil
    // obj.protectedMethod();      // HATA: Erişim mümkün değil
    obj.accessProtected();        // Erişim mümkün, çünkü türemiş sınıf içindeki public method

    return 0;
}
```

**Sonuç:** `protectedVariable` ve `protectedMethod` sınıf dışından doğrudan erişilemez, ancak türemiş sınıf içinden erişilebilir.

### ➤ Genellikle Veri Üyeleri Neden `private` Altında Tanımlanır?
Veri üyelerini `private` erişim belirleyici altında tanımlamanın birkaç önemli nedeni vardır:

#### 1. Kapsülleme (Encapsulation)

Kapsülleme, nesne yönelimli programlamanın (OOP) temel ilkelerinden biridir. Bu ilke, verilerin ve bu verilere erişim yöntemlerinin bir arada gruplanmasını ve verilerin dışarıdan doğrudan erişimini sınırlamayı sağlar. Bu sayede:

- **Veri Gizliliği:** Veriler sadece sınıf içindeki fonksiyonlar tarafından erişilebilir ve değiştirilebilir. Bu, verilerin yanlışlıkla veya kötü niyetle değiştirilmesini önler.
- **Kontrol:** Sınıf içindeki fonksiyonlar veri üyeleri üzerinde belirli kontroller veya iş kuralları uygulayabilir. Örneğin, bir `setAge` fonksiyonu yaşın geçerli bir aralıkta olup olmadığını kontrol edebilir.

#### 2. Kullanıcı Arayüzü (Interface) Tasarımı

Bir sınıfın dışarıya sunduğu arayüz (public fonksiyonlar) ile veri üyeleri arasındaki ayrım, sınıfın kullanımını ve bakımını kolaylaştırır. Kullanıcılar:

- **Yalnızca İhtiyaç Duydukları İşlevleri Kullanır:** Veri üyeleri doğrudan erişim yerine, sınıfın sağladığı işlevlerle verilere erişirler. Bu, sınıfın işleyişi hakkında bilgi sahibi olmadan da sınıfın kullanılmasını sağlar.
- **Daha Temiz ve Anlaşılır Kod:** Sınıfın iç yapısı hakkında bilgi sahibi olmadan, yalnızca sağladığı işlevlere odaklanarak kod yazabilirsiniz.

#### 3. Gelecekteki Değişikliklerin Kolay Yönetimi

Veri üyelerini `private` olarak tanımlamak, sınıfın iç yapısını değiştirmenin daha kolay olmasını sağlar. Örneğin:

- **Yeniden Yapılandırma:** Eğer veri üyelerini `private` olarak tutarsanız, iç yapıyı değiştirdiğinizde (örneğin veri türünü değiştirme), sadece sınıf içindeki fonksiyonları güncelleyerek değişiklik yapabilirsiniz. Dışarıdan erişim olmadığı için, dış kodu etkilenmez.
- **Geriye Dönük Uyumluluk:** `private` veri üyeleri ile sınıfın dışarıya sağladığı arayüz arasındaki bağımlılık azdır. Bu, sınıfın dışarıdan kullanımını etkileyen değişikliklerin daha kolay yönetilmesini sağlar.

#### 4. Kötüye Kullanımın Önlenmesi

- **Veri Bütünlüğü:** `private` veri üyeleri, dış kodun veri üzerinde doğrudan değişiklik yapmasını engeller. Bu, verilerin beklenmedik veya geçersiz durumlara geçmesini önler.
- **Güvenlik:** Veri üyelerini `private` olarak tanımlamak, veri bütünlüğünü ve güvenliğini artırır. Sınıf dışından veri üyelerine doğrudan erişim olmadığı için veri güvenliği sağlanır.

### ➤ Destructor Kullanımı
Bir C++ sınıfında yıkıcı (destructor) işlevinin bulunması zorunlu değildir, ancak belirli durumlarda önemli bir rol oynar.
#### Yıkıcının Rolü

1. **Kaynak Yönetimi:**
   Yıkıcı, nesne ömrü sona erdiğinde kaynakları serbest bırakmak için kullanılır. Bu kaynaklar, dinamik bellek (heap) tahsisi, dosya açma, ağ bağlantıları veya diğer dış kaynaklar olabilir. Eğer bir sınıf bu tür kaynakları yönetiyorsa, yıkıcı bu kaynakların düzgün bir şekilde serbest bırakılmasını sağlar.

   ```cpp
   class MyClass {
   public:
       MyClass() {
           // Dinamik bellek tahsisi
           data = new int[10];
       }

       ~MyClass() {
           // Dinamik bellek serbest bırakma
           delete[] data;
       }

   private:
       int* data;
   };
   ```

2. **Temizlik:**
   Yıkıcı, nesne yok edilirken yapılması gereken temizlik işlerini gerçekleştirebilir. Örneğin, bir sınıf, açılmış dosyaları kapatmak veya kilitleri serbest bırakmak için bir yıkıcı kullanabilir.

3. **Otomatik Temizlik:**
   C++ dilinde, bir nesne oluşturulduğunda yapıcı (constructor) çağrılır, ve nesne yok edildiğinde yıkıcı otomatik olarak çağrılır. Bu, kaynakların yönetimini daha güvenilir hale getirir.

#### Yıkıcı Olmadığında

1. **Basit Sınıflar:**
   Eğer bir sınıf yalnızca temel veri türlerini içeriyorsa ve dinamik bellek, dosya işlemleri veya dış kaynaklarla etkileşimde bulunmuyorsa, özel bir yıkıcıya ihtiyaç duyulmaz. Bu tür sınıflar, varsayılan yıkıcıyı kullanabilirler.

   ```cpp
   class SimpleClass {
   public:
       int value;
   };
   ```

   Bu durumda, C++ dilinin derleyicisi, sınıfın üye değişkenlerini otomatik olarak yönetir ve özel bir yıkıcı tanımlamanıza gerek kalmaz.

2. **Yönetilen Kaynaklar:**
   Eğer sınıf yalnızca diğer sınıflardan oluşuyorsa ve bu sınıflar kendi kaynak yönetimlerini yapıyorsa, yıkıcıya ihtiyaç duyulmayabilir. Yıkıcı genellikle yalnızca kaynakları doğrudan yöneten sınıflar için gereklidir.

### ➤ `this` İşareti

`this` işareti, C++'ta bir üye işlevi (metot) içinde, sınıfın mevcut nesnesine referans veren bir işarettir. `this` işareti, nesnenin kendisini temsil eder ve genellikle şu durumlarda kullanılır:

#### Kullanım Alanları

1. **Nesneye Erişim:**
   `this`, bir üye işlev içinde sınıfın mevcut nesnesine erişmek için kullanılır. Özellikle, aynı isimdeki parametrelerle veri üyelerini ayırt etmek için kullanılır.

   ```cpp
   class MyClass
   {
		public:
			void setValue(int value) {
				this->value = value;  // `this->value` veri üyesini, `value` ise parametreyi temsil eder.
			}

		private:
			int value;
   };
   ```

   Burada `this->value`, sınıfın veri üyesi `value`'yu ifade eder, `value` ise parametre adıdır.

2. **Metot Zincirleme (Method Chaining):**
   `this` işareti, bir işlevden sonra aynı nesne üzerinde başka bir işlev çağrısı yapılmasını sağlar. Bu, metot zincirlemesi olarak bilinir.

   ```cpp
   class MyClass
   {
		public:
			MyClass& setValue(int value) {
				this->value = value;
				return *this;  // Mevcut nesneyi döndürür
			}

			void showValue() const {
				std::cout << value << std::endl;
			}

		private:
			int value;
   };

   int main()
   {
		MyClass obj;
		obj.setValue(10).showValue();  // Metot zincirleme
		return 0;
   }
   ```

   `setValue` işlevi `*this` döndürerek nesne üzerinde başka işlev çağrısı yapılmasını sağlar.

3. **Nesne'nin Bellek Adresini Almak:**
   `this` işareti, mevcut nesnenin bellekteki adresini almak için kullanılabilir.

   ```cpp
   class MyClass
   {
		public:
			void printAddress() const {
				std::cout << "Address: " << this << std::endl;
			}
   };

   int main()
   {
		MyClass obj;
		obj.printAddress();  // `this` işareti, obj'nin bellekteki adresini yazdırır
		return 0;
   }
   ```

> Özet: `this` işareti, C++'ta mevcut nesneyi temsil eden bir işarettir ve sınıfın üye işlevleri içinde nesnenin veri üyelerine ve işlevlerine erişmek için kullanılır.

#### `this` İşaretinin Özellikleri

- **Sadece Üye İşlevlerde Kullanılabilir:** `this` işareti yalnızca üye işlevlerde kullanılabilir. Statik işlevlerde veya global fonksiyonlarda geçerli değildir.
- **Bu Nesneyi Temsil Eder:** `this`, çağrılan metodu belirli bir nesne üzerinde çalıştırır ve bu nesnenin adresini döndürür.
- **Kendini Döndüren Metodlar:** Yöntem zincirlemesini destekleyen `this` işaretinin kendisini döndüren işlevlerde kullanımı yaygındır.

<br></br>

## Member Fonksiyonlar

C++'da **member fonksiyonlar** (üye fonksiyonlar), bir sınıfın (class) içerisinde tanımlanmış fonksiyonlardır. Bu fonksiyonlar, sınıfın nesneleri (object) üzerinde işlem yapmak için kullanılır ve sınıfın verilerine (member variables) erişebilir. Member fonksiyonlar, sınıfın davranışlarını tanımlar ve sınıfın özelliklerine (properties) erişim sağlar.

### ➤ Member Fonksiyonların Kullanımı ve Önemi

1. **Sınıfın Davranışlarını Tanımlama:**
   - Member fonksiyonlar, bir sınıfın nesnelerinin nasıl davranacağını tanımlar. Örneğin, bir "Car" sınıfı, arabanın hızlanması, fren yapması gibi işlemleri gerçekleştiren member fonksiyonlara sahip olabilir.

2. **Veri Kapsülleme (Encapsulation):**
   - Sınıfın private olarak tanımlanan verilerine doğrudan dışarıdan erişilemez. Bu verilere erişmek veya bu veriler üzerinde işlem yapmak için public olarak tanımlanan member fonksiyonlar kullanılır.

3. **Sınıfın İç Durumunu Yönetme:**
   - Member fonksiyonlar, sınıfın verilerini yönetmek, güncellemek veya bu verilere erişim sağlamak için kullanılır. Bu sayede, sınıfın iç durumu (state) güvenli bir şekilde kontrol edilebilir.

### ➤ Member Fonksiyon Örneği

```cpp
#include <iostream>

class Rectangle
{
	private:
		int width;   // Dikdörtgenin genişliği
		int height;  // Dikdörtgenin yüksekliği

	public:
		// Member fonksiyon - Dikdörtgenin genişliğini ve yüksekliğini ayarla
		void setDimensions(int w, int h) {
			width = w;
			height = h;
		}

		// Member fonksiyon - Dikdörtgenin alanını hesapla
		int calculateArea() {
			return width * height;
		}

		// Member fonksiyon - Dikdörtgenin çevresini hesapla
		int calculatePerimeter() {
			return 2 * (width + height);
		}
};

int main()
{
    // Rectangle sınıfından bir nesne oluşturuyoruz
    Rectangle myRectangle;

    // Dikdörtgenin genişlik ve yüksekliğini ayarlıyoruz
    myRectangle.setDimensions(5, 3);

    // Dikdörtgenin alanını ve çevresini hesaplıyoruz
    int area = myRectangle.calculateArea();
    int perimeter = myRectangle.calculatePerimeter();

    // Sonuçları ekrana yazdırıyoruz
    std::cout << "Dikdörtgenin Alanı: " << area << std::endl;        // Dikdörtgenin Alanı: 15
    std::cout << "Dikdörtgenin Çevresi: " << perimeter << std::endl; // Dikdörtgenin Çevresi: 16

    return 0;
}
```

**Açıklamalar:**

1. **`Rectangle` Sınıfı:**
   - `width` (genişlik) ve `height` (yükseklik) adında iki private (özel) member değişkene sahiptir.
   - Bu veriler doğrudan dışarıdan erişilemez. Sadece sınıf içindeki member fonksiyonlar tarafından erişilebilirler.

2. **Member Fonksiyonlar:**
   - **`setDimensions(int w, int h)`**: Dikdörtgenin genişlik ve yüksekliğini ayarlar.
   - **`calculateArea()`**: Dikdörtgenin alanını hesaplar ve geri döndürür.
   - **`calculatePerimeter()`**: Dikdörtgenin çevresini hesaplar ve geri döndürür.

3. **Nesne Oluşturma ve Kullanma:**
   - `main` fonksiyonunda, `Rectangle` sınıfından `myRectangle` adında bir nesne oluşturuluyor.
   - `setDimensions` fonksiyonu ile dikdörtgenin genişliği `5`, yüksekliği ise `3` olarak ayarlanıyor.
   - `calculateArea` ve `calculatePerimeter` fonksiyonları kullanılarak dikdörtgenin alanı ve çevresi hesaplanıyor ve ekrana yazdırılıyor.

### ➤ Getter ve Setter Fonksiyonları

**Getter** ve **setter** fonksiyonları, sınıfın (class) özel (private) üye değişkenlerine erişimi kontrol etmek için kullanılan üye fonksiyonlardır. Bu fonksiyonlar, nesne yönelimli programlamada (OOP) veri kapsülleme (encapsulation) ilkesini uygular.

#### Getter Fonksiyonları:
- **Getter** fonksiyonları, bir sınıfın private üye değişkenlerinin değerini dış dünyaya (diğer sınıflar veya fonksiyonlar) okumak (getirmek) için kullanılır.
- Genellikle `get` kelimesiyle başlar ve geri dönüş değeri olarak private üye değişkeninin değerini döndürür.

#### Setter Fonksiyonları:
- **Setter** fonksiyonları, bir sınıfın private üye değişkenlerinin değerini dış dünyadan gelen verilerle ayarlamak (set etmek) için kullanılır.
- Genellikle `set` kelimesiyle başlar ve bir parametre alarak bu parametreyi private üye değişkenine atar.

#### Örnek: `Person` Sınıfı ile Getter ve Setter Fonksiyonları

```cpp
#include <iostream>
#include <string>

class Person
{
	private:
		std::string name;
		int age;

	public:
		// Setter fonksiyonu - İsmi ayarlar
		void setName(const std::string &newName) {
			name = newName;
		}

		// Getter fonksiyonu - İsmi getirir
		std::string getName() const {
			return name;
		}

		// Setter fonksiyonu - Yaşı ayarlar
		void setAge(int newAge) {
			if (newAge >= 0) {  // Yaşın pozitif bir değer olmasını sağlıyoruz
				age = newAge;
			} else {
				std::cout << "Geçersiz yaş değeri!" << std::endl;
			}
		}

		// Getter fonksiyonu - Yaşı getirir
		int getAge() const {
			return age;
		}
};

int main()
{
    // Person sınıfından bir nesne oluşturuyoruz
    Person person;

    // Setter fonksiyonlarını kullanarak name ve age ayarlıyoruz
    person.setName("Alice");
    person.setAge(25);

    // Getter fonksiyonlarını kullanarak name ve age değerlerini alıyoruz
    std::cout << "Name: " << person.getName() << std::endl; // Name: Alice
    std::cout << "Age: " << person.getAge() << std::endl;   // Age: 25

    // Geçersiz yaş değeri denemesi
    person.setAge(-5); // Geçersiz yaş değeri!

    return 0;
}
```

**Açıklamalar:**

1. **`Person` Sınıfı:**
   - `name` ve `age` adında iki private üye değişkene sahiptir. Bu değişkenler sınıf dışından doğrudan erişilemez.

2. **Setter Fonksiyonları:**
   - **`setName(const std::string &newName)`**: Bu fonksiyon, `name` değişkeninin değerini ayarlamak için kullanılır.
   - **`setAge(int newAge)`**: Bu fonksiyon, `age` değişkeninin değerini ayarlamak için kullanılır. Yaşın negatif olmasını engellemek için bir kontrol eklenmiştir.

3. **Getter Fonksiyonları:**
   - **`getName() const`**: Bu fonksiyon, `name` değişkeninin değerini döndürmek için kullanılır.
   - **`getAge() const`**: Bu fonksiyon, `age` değişkeninin değerini döndürmek için kullanılır.

4. **Kapsülleme:**
   - Getter ve setter fonksiyonları, `name` ve `age` değişkenlerinin sadece `Person` sınıfının kontrolü altında değiştirilmesini sağlar. Bu, kapsülleme ilkesinin bir parçasıdır ve verilerin korunmasına yardımcı olur.

### ➤ Neden Getter ve Setter Kullanılır?
- **Veri Gizliliği:** Private üye değişkenlerin dışarıdan doğrudan erişilmesini engelleyerek verilerinizi korursunuz.
- **Veri Doğrulama:** Setter fonksiyonlarında belirli kurallar koyarak (örneğin, yaşın negatif olmamasını sağlamak) hatalı veri girişini engelleyebilirsiniz.
- **Esneklik:** Getter ve setter fonksiyonlarını kullanarak, bir değişkenin nasıl okunacağını veya ayarlanacağını kontrol edebilir, ileride bu fonksiyonları değiştirdiğinizde sınıfı kullanan diğer kodları etkilemeden güncellemeler yapabilirsiniz.

<br></br>

## Temel Veri Yapıları ve Sınıflar

C++'da **`std::string`**, **`std::vector`**, **`std::map`** gibi ifadeler, C++ Standard Template Library (STL) ve diğer standart kütüphane bileşenleri tarafından sağlanan veri yapıları ve sınıfları ifade eder. Bu yapılar, programcıların veri yönetimi ve algoritmalarını daha kolay ve verimli bir şekilde gerçekleştirmelerine olanak tanır. Bu yapıların her biri, farklı veri türlerini ve işlemlerini desteklemek üzere tasarlanmıştır.

### 1. `std::string`

`std::string`, C++'da dinamik olarak yönetilen bir karakter dizisini (string) temsil eder. C-tarzı karakter dizilerinin (null-terminated arrays of `char`) aksine, `std::string` sınıfı, metinle ilgili işlemleri çok daha güvenli ve kolay bir şekilde yapmanızı sağlar.

#### Detaylı Özellikler

- **Dinamik Boyut:** `std::string` nesneleri dinamik olarak boyutlandırılır. Yani, bir `std::string` nesnesine karakterler ekledikçe boyutu otomatik olarak büyür.
- **Bellek Yönetimi:** `std::string` nesneleri, bellek yönetimiyle ilgili detayları gizler. Bu sayede programcılar, bellek taşması (buffer overflow) gibi yaygın hatalardan kaçınabilir.
- **Zengin Fonksiyon Desteği:** `std::string` sınıfı, metin işleme için çeşitli üye fonksiyonlar sunar (örneğin, `length`, `substr`, `find`, `append`).

#### Detaylı Örnek
```cpp
#include <iostream>
#include <string>

int main()
{
    // Bir string oluşturma
    std::string greeting = "Hello";

    // Stringe karakterler ekleme
    greeting += ", World!";

    // Stringin boyutunu bulma
    std::cout << "Greeting: " << greeting << std::endl;  // Output: Hello, World!
    std::cout << "Length: " << greeting.length() << std::endl;  // Output: 13

    // Alt string (substring) alma
    std::string sub = greeting.substr(7, 5);
    std::cout << "Substring: " << sub << std::endl;  // Output: World

    // String içinde karakter arama
    size_t pos = greeting.find("World");
    if (pos != std::string::npos) {
        std::cout << "'World' found at position: " << pos << std::endl;  // Output: 7
    }

    return 0;
}
```

### 2. `std::vector`

`std::vector`, dinamik boyutlu bir dizi (array) temsil eder. Boyutunu çalışma zamanında değiştirebilirsiniz ve C tarzı dizilere göre daha esnek bir yapıdır.

#### Detaylı Özellikler
- **Dinamik Boyut:** `std::vector` nesneleri, elemanlar eklendikçe veya silindikçe otomatik olarak büyüyüp küçülebilir.
- **Bellek Yeniden Tahsisi:** `std::vector`, gerekirse belleği yeniden tahsis eder. İçerideki elemanlar aynı sırada korunur.
- **Rasgele Erişim:** `std::vector`, elemanlara indeks ile doğrudan erişim sağlar.
- **Verimli Ekleme/Silme:** Sondan ekleme ve çıkarma işlemleri (push_back, pop_back) amortize edilmiş O(1) zaman karmaşıklığına sahiptir.

#### Detaylı Örnek
```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Eleman ekleme
    numbers.push_back(6);

    // Eleman silme
    numbers.pop_back();

    // Elemanlara indeksle erişim
    std::cout << "First element: " << numbers[0] << std::endl;  // Output: 1

    // Eleman sayısını alma
    std::cout << "Vector size: " << numbers.size() << std::endl;  // Output: 5

    // Vector'ü tersine çevirme
    std::reverse(numbers.begin(), numbers.end());

    // Elemanları yazdırma
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;  // Output: 5 4 3 2 1

    return 0;
}
```

### 3. `std::map`

`std::map`, anahtar-değer (key-value) çiftlerini sıralı olarak depolayan bir veri yapısıdır. Bir anahtar yalnızca bir değere karşılık gelir ve anahtarlar benzersizdir.

#### Detaylı Özellikler
- **Sıralı Depolama:** `std::map`, anahtarları sıralı olarak depolar. Varsayılan olarak, bu sıralama işlemi `<` operatörüne göre yapılır.
- **O(log n) Zaman Karmaşıklığı:** `std::map`, veri ekleme, silme ve arama işlemleri için O(log n) zaman karmaşıklığı sunar.
- **İteratör Desteği:** `std::map`, kapsayıcının içindeki öğeler arasında gezinmek için iteratörler sunar.
- **Otomatik Anahtar Ekleme:** Bir anahtara değer atandığında, eğer anahtar önceden mevcut değilse otomatik olarak eklenir.

#### Detaylı Örnek
```cpp
#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> ageMap;

    // Eleman ekleme
    ageMap["Alice"] = 30;
    ageMap["Bob"] = 25;
    ageMap.insert({"Charlie", 35});

    // Elemanlara erişim
    std::cout << "Alice's age: " << ageMap["Alice"] << std::endl;  // Output: 30

    // Anahtar arama
    if (ageMap.find("David") == ageMap.end()) {
        std::cout << "David not found" << std::endl;  // Output: David not found
    }

    // Tüm elemanları yazdırma
    for (const auto& pair : ageMap) {
        std::cout << pair.first << " is " << pair.second << " years old." << std::endl;
    }
    // Output:
    // Alice is 30 years old.
    // Bob is 25 years old.
    // Charlie is 35 years old.

    return 0;
}
```

### 4. `std::set`

`std::set`, benzersiz elemanları sıralı olarak depolayan bir veri yapısıdır. Bir eleman yalnızca bir kez yer alır ve set, elemanları otomatik olarak sıralar.

#### Detaylı Özellikler
- **Benzersiz Elemanlar:** Aynı eleman set içinde birden fazla bulunamaz.
- **Sıralı Depolama:** Set, elemanları belirli bir sıraya göre depolar (varsayılan olarak `<` operatörü).
- **O(log n) Zaman Karmaşıklığı:** Ekleme, silme ve arama işlemleri O(log n) zaman karmaşıklığına sahiptir.
- **İteratör Desteği:** `std::set`, içerideki öğeler arasında gezinmek için iteratörler sağlar.

#### Detaylı Örnek
```cpp
#include <iostream>
#include <set>

int main() {
    std::set<int> uniqueNumbers = {5, 2, 8, 5, 1};

    // Eleman ekleme
    uniqueNumbers.insert(3);

    // Set içindeki elemanları yazdırma
    for (int num : uniqueNumbers) {
        std::cout << num << " ";  // Output: 1 2 3 5 8
    }
    std::cout << std::endl;

    // Eleman arama
    if (uniqueNumbers.find(5) != uniqueNumbers.end()) {
        std::cout << "5 found in the set" << std::endl;  // Output: 5 found in the set
    }

    return 0;
}
```

### 5. `std::queue`

`std::queue`, FIFO (First-In-First-Out) prensibine göre çalışan bir veri yapısıdır. Kuyruğa eleman ekleme, çıkarma gibi işlemler yapılabilir.

#### Detaylı Özellikler
- **FIFO Prensibi:** İlk eklenen eleman ilk çıkarılır.
- **Sınırlı Erişim:** Sadece ön (front) ve arka (back) elemanlara erişim mümkündür.
- **Verimli Ekleme/Çıkarma:** Kuyruğa ekleme ve çıkarma işlemleri O(1) zaman karmaşıklığına sahiptir.

#### Detaylı Örnek
```cpp
#include <iostream>
#include <queue>

int main()
{
	std::queue q;
	// Kuyruğa eleman ekleme
	q.push(1);
	q.push(2);
	q.push(3);

	// Eleman çıkarma ve gösterme
	while (!q.empty()) {
		std::cout << q.front() << " ";  // İlk eklenen elemanı gösterir
		q.pop();  // İlk eklenen elemanı çıkarır
	}
	std::cout << std::endl;  // Output: 1 2 3

	return 0;
}
```

### 6. `std::stack`

`std::stack`, LIFO (Last-In-First-Out) prensibine göre çalışan bir veri yapısıdır. Son eklenen eleman ilk çıkarılır.

#### Detaylı Özellikler
- **LIFO Prensibi:** Son eklenen eleman ilk çıkarılır.
- **Sınırlı Erişim:** Sadece en üstteki (top) eleman görülebilir.
- **Verimli Ekleme/Çıkarma:** Yığına ekleme ve çıkarma işlemleri O(1) zaman karmaşıklığına sahiptir.

#### Detaylı Örnek
```cpp
#include <iostream>
#include <stack>

int main() {
    std::stack<int> s;

    // Yığına eleman ekleme
    s.push(1);
    s.push(2);
    s.push(3);

    // Eleman çıkarma ve gösterme
    while (!s.empty()) {
        std::cout << s.top() << " ";  // Son eklenen elemanı gösterir
        s.pop();  // Son eklenen elemanı çıkarır
    }
    std::cout << std::endl;  // Output: 3 2 1

    return 0;
}
```
<br></br>

## Template Nedir?
C++ templateleri, belirli bir veri tipi yerine, bir tür veya değer parametresi ile çalışabilen, genel bir yapı sunan bir programlama özelliğidir. Bu özellik, aynı kodu farklı veri tipleriyle çalıştırmayı mümkün kılar ve genellikle "generic programming" (genel programlama) olarak adlandırılır.

### Temel Tanım
Bir C++ template, bir fonksiyon veya sınıfın çeşitli veri tipleriyle çalışmasını sağlayan genel bir taslaktır. Temel olarak, tek bir template yazarak, o template’i farklı veri tipleriyle kullanabilirsiniz. Bu, kod tekrarını azaltır ve esnekliği artırır.

### Temel Türleri
1. **Fonksiyon Templateleri**: Aynı işlevi yerine getiren, ancak farklı veri tipleriyle çalışan fonksiyonlar yazmanızı sağlar.
2. **Sınıf Templateleri**: Aynı işlemi gerçekleştiren ancak farklı veri tipleriyle çalışan sınıflar tanımlamanızı sağlar.

### Kullanım Alanları
Templateler genellikle aşağıdaki durumlarda kullanılır:
- **Veri Yapıları**: Farklı veri tipleriyle çalışabilen genel veri yapıları oluşturmak için kullanılır. Örneğin, `std::vector`, `std::list`, ve `std::map` gibi standart kütüphane konteynerleri template kullanılarak oluşturulmuştur.
- **Algoritmalar**: Bir algoritmayı farklı veri tipleriyle uygulamak için. Örneğin, `std::sort` fonksiyonu bir template olarak yazılmıştır, bu sayede farklı veri tipleri ile sıralama yapılabilir.
- **Kod Tekrarını Önleme**: Aynı işlemi farklı veri tipleri üzerinde tekrar tekrar uygulamanız gerektiğinde, template kullanarak kod tekrarını önleyebilirsiniz.

### Fonksiyon Templatelere Örnek
```cpp
#include <iostream>

template <typename T>
T maksimum(T a, T b)
{
    return (a > b) ? a : b;
}

int main()
{
    std::cout << maksimum(10, 20) << std::endl;      // int tipi için çalışır
    std::cout << maksimum(10.5, 3.5) << std::endl;   // double tipi için çalışır
    std::cout << maksimum('a', 'b') << std::endl;    // char tipi için çalışır
    return 0;
}
```
Bu örnekte `maksimum` fonksiyonu, iki değeri karşılaştırarak büyük olanı döndüren bir fonksiyondur. `int`, `double`, ve `char` gibi farklı veri tipleriyle kullanılabilir.

### Sınıf Templatelere Örnek
```cpp
#include <iostream>

template <typename T>
class Kutu
{
	private:
		T veri;
	public:
		Kutu(T veri) : veri(veri) {}
		T getir() {
			return veri;
		}
};

int main()
{
    Kutu<int> kutu1(10);
    Kutu<double> kutu2(10.5);

    std::cout << kutu1.getir() << std::endl;  // int tipi için çalışır
    std::cout << kutu2.getir() << std::endl;  // double tipi için çalışır

    return 0;
}
```
Bu örnekte `Kutu` sınıfı, herhangi bir veri tipini saklayabilen bir sınıftır. Farklı veri tipleri ile örneklendirilmiş `Kutu` nesneleri oluşturulabilir.

### Template Parametreleri
Templatelerde kullanılan tür parametreleri `typename` veya `class` anahtar kelimesi ile tanımlanır. Ayrıca, sabit değerler (örneğin bir tam sayı) de template parametresi olarak kullanılabilir.

```cpp
template <typename T, int boyut>
class Dizi
{
	private:
		T arr[boyut];
	public:
		void yazdir() {
			for (int i = 0; i < boyut; ++i) {
				std::cout << arr[i] << " ";
			}
			std::cout << std::endl;
		}
};
```
Yukarıdaki örnekte `Dizi` sınıfı hem bir tür parametresi (`T`) hem de bir sabit (`boyut`) parametresi alır.

### Derleme Zamanı ve Uzmanlaşma
Templateler, derleme zamanında genelleştirilmiş kodun özel veri tiplerine uygun olarak genişletilmesiyle çalışır. Bu, C++'ın güçlü statik tür denetimini korurken, esneklik ve performans sağlar.

**Template Uzmanlaşması**: Belirli bir veri tipi için template’in özelleştirilmesi anlamına gelir. Örneğin, belirli bir veri tipi için farklı bir algoritma veya işlem gerekliyse, bu veri tipi için özel bir template versiyonu yazılabilir.

```cpp
template<>
class Kutu<char>
{
	private:
		char veri;
	public:
		Kutu(char veri) : veri(veri) {}
		char getir() {
			return veri;
		}
		void yazdir() {
			std::cout << "Karakter: " << veri << std::endl;
		}
};
```
Bu örnekte, `char` türü için `Kutu` sınıfı özelleştirilmiştir.

<br></br>

## Implement Edilen Dosya Ne Demek?

**"Implement edilen header"** terimi bir programlama projesinde kullanılan bir başlık (header) dosyasının (`.h` uzantılı) o dosya içerisinde tanımlanan işlevlerin (fonksiyonların), veri yapılarının veya sınıfların `.c` veya `.cpp` dosyalarında gerçekleştirildiğini (implement edildiğini) ifade eder.

Bir header dosyası; fonksiyon prototiplerini, makro tanımlarını, değişken tanımlarını ve veri yapılarının tanımlarını içerir. Bu dosyalar, birden fazla kaynak dosyasında (source file) kullanılabilecek ortak tanımları sağlar. Implementasyon dosyaları (genellikle `.c` veya `.cpp` uzantılı) ise bu fonksiyonların veya sınıfların gerçek kodunu içerir.

Örneğin:

**`math_operations.hpp` (Header Dosyası):**
```cpp
#ifndef MATH_OPERATIONS_H
# define MATH_OPERATIONS_H

int add(int a, int b);
int subtract(int a, int b);

#endif
```

**`math_operations.cpp` (Implementasyon Dosyası):**
```cpp
#include "math_operations.h"

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}
```

Bu örnekte, `math_operations.hpp` header dosyasında iki fonksiyonun (`add` ve `subtract`) prototipleri tanımlanmıştır. Ancak bu fonksiyonların gerçek kodu `math_operations.cpp` dosyasında implement edilmiştir. Header dosyası, diğer dosyalarda bu fonksiyonları kullanabilmemiz için bir arayüz sağlar. Implement edilen dosya ise bu fonksiyonların işlevselliğini yerine getirir.

<br></br>

## Korunmayan Header Dosyası
Bir C++ başlık dosyasında korunmayan (unprotected) header, `#include` direktifi ile başka dosyalarda kullanılabilir, ancak koruma önlemleri almadan doğrudan dosya içinde tanımlama içerir. Bu tür bir header dosyası genellikle include guard kullanmaz veya `#pragma once` gibi mekanizmalarla korunmaz, bu da aynı header dosyasının birden fazla kez dahil edilmesine ve potansiyel olarak derleme hatalarına yol açabilir.

Koruma önlemleri almayan bir header dosyası, aşağıdaki gibi bir sorun oluşturabilir:

1. **Çift İçerik Sorunu:** Aynı dosyanın birden fazla kez dahil edilmesi, aynı tanımların tekrar edilmesine neden olabilir. Bu da derleyici hatalarına yol açar.
2. **Performans Sorunları:** Bir dosyanın birçok kez dahil edilmesi, derleme süresini uzatabilir ve performansı etkileyebilir.

Korunmayan header dosyalarının sorunlarını önlemek için genellikle `#include` guard kullanılır:

```cpp
#ifndef HEADER_FILE_NAME_H
#define HEADER_FILE_NAME_H

// Header dosyasının içeriği

#endif // HEADER_FILE_NAME_H
```

Bu makrolar, header dosyasının sadece bir kez dahil edilmesini sağlar. Alternatif olarak, `#pragma once` direktifi de kullanılabilir:

```cpp
#pragma once

// Header dosyasının içeriği
```

Bu iki yöntemden biri, header dosyasının yalnızca bir kez derlenmesini sağlar ve çift tanım hatalarını önler.

<br></br>

## `std::string` için Kütüphane Sorunu

C++98 standardında `string` sınıfı, Standart Şablon Kütüphanesi (STL) içinde yer alır ve `<string>` başlık dosyasında tanımlanmıştır. Kodda `<string>` başlık dosyasını dahil etmemiş olmanıza rağmen `std::string` kullanılabilir ve kodunuz çalışır. Bunun sebebi, `std::string` sınıfının `<iostream>` başlık dosyasının bir parçası olarak dolaylı yoldan dahil edilmesidir.

`<iostream>` başlık dosyası, `<istream>` ve `<ostream>` dosyalarını içerir. Bu dosyalar da `<ios>` ve sonunda string akışlarını işlemek için `<string>` dosyasını içerir. Yani, `<iostream>` dosyasını dahil ettiğinizde, dolaylı olarak `std::string` sınıfı da kullanılabilir hale gelir. Bu nedenle, `<string>` başlık dosyasını doğrudan dahil etmemiş olsanız bile kodunuz çalışır.

Ancak 42 projelerinin dışında bir öneri olarak, `std::string` ile çalışırken `<string>` başlık dosyasını doğrudan dahil etmek, kodunuzu daha anlaşılır kılmak ve ileride `<iostream>` başlık dosyasını kaldırırsanız oluşabilecek sorunlardan kaçınmak için iyi bir uygulamadır.

<br></br>

## Başlatma Listeleri (Initialization Lists)

**Initialization list** (başlatma listesi), C++'da sınıfın constructor (yapıcı) fonksiyonunda, üye değişkenlerini veya temel sınıfın constructor'ını başlatmak için kullanılan bir mekanizmadır. Başlatma listeleri, bir nesne oluşturulurken üye değişkenlerinin belirli bir değerle başlatılmasını sağlar. Ayrıca, temel sınıf constructor'ları veya sabit (const) üyeler gibi özel türdeki üyeleri başlatmak için de kullanılır.

### ➤ Başlatma Listesinin Kullanım Nedenleri

1. **Veri Üyelerini Başlatmak**
   - Bir üye değişkeni oluşturulurken belirli bir başlangıç değeri verilmesini sağlar.
   - `const` (sabit) değişkenleri veya referans üyelerini başlatmak için zorunludur çünkü bunlar yalnızca bir kez, constructor çağrılmadan önce başlatılabilir.

2. **Temel Sınıf Constructor'ını Çağırmak**
   - Bir sınıf türetilmiş bir sınıf (derived class) olduğunda, temel sınıfın (base class) constructor'ını başlatma listesi ile çağırmak gerekir.

### ➤ Başlatma Listesi Nasıl Kullanılır?

Başlatma listesi, constructor'ın gövdesi başlamadan önce `:` karakterinden sonra listelenir. Başlatma listesinde, üye değişkenlerin değerleri, `memberName(value)` şeklinde belirtilir.

#### Örnek: Başlatma Listesi Kullanımı

Aşağıda, başlatma listesinin nasıl kullanıldığını gösteren basit bir örnek bulunmaktadır. Bu örnekte, bir `Rectangle` (Dikdörtgen) sınıfı tanımlayacağız ve başlatma listesi ile genişlik ve yüksekliği başlatacağız.

```cpp
#include <iostream>

class Rectangle
{
	private:
		int width;
		int height;

	public:
		// Constructor - başlatma listesi ile genişlik ve yüksekliği başlatır
		Rectangle(int w, int h) : width(w), height(h) {
			// Constructor gövdesi
			std::cout << "Rectangle constructor called" << std::endl;
		}

		// Üye fonksiyonlar
		int calculateArea() const {
			return width * height;
		}

		int calculatePerimeter() const {
			return 2 * (width + height);
		}
};

int main()
{
    // Rectangle sınıfından bir nesne oluşturuyoruz
    Rectangle myRectangle(5, 3);

    // Dikdörtgenin alanını ve çevresini hesaplıyoruz
    std::cout << "Area: " << myRectangle.calculateArea() << std::endl;        // Area: 15
    std::cout << "Perimeter: " << myRectangle.calculatePerimeter() << std::endl; // Perimeter: 16

    return 0;
}
```

**Açıklamalar:**

1. **Başlatma Listesi:**
   - `Rectangle` sınıfının constructor'ında `Rectangle(int w, int h) : width(w), height(h)` şeklinde bir başlatma listesi kullanılmıştır.
   - `width(w)` ve `height(h)` ifadeleri, constructor'ın çağrıldığı anda `width` ve `height` üye değişkenlerini `w` ve `h` değerleri ile başlatır.

2. **Constructor Gövdesi:**
   - Başlatma listesi, constructor'ın gövdesi başlamadan önce çalışır. Constructor gövdesinde, `std::cout` ile bir mesaj yazdırılmıştır, ancak üye değişkenler başlatma listesi aracılığıyla daha önce başlatılmıştır.

<br></br>



## `static` ve `const` Anahtar Kelimeleri
C++'da **`static`** ve **`const`** anahtar kelimeleri, çeşitli programlama amaçları için kullanılan önemli özelliklerdir. Her biri belirli durumlarda belirli avantajlar sağlar. İşte bunların ne olduğunu ve nasıl kullanıldığını açıklayan bilgiler:

### ➤ `static` Anahtar Kelimesi

**`static`**, bir değişkenin veya fonksiyonun ömrünü ve erişim alanını kontrol eder. `static` anahtar kelimesinin kullanıldığı yerler ve anlamları şunlardır:

1. **Sınıf Üyeleri için `static`:**
   - Sınıf içinde tanımlanan bir `static` üye değişkeni veya fonksiyon, sınıfa ait olup tüm nesneler tarafından paylaşılır. Yani, tüm nesneler aynı `static` üye değişkenine erişir.
   - `static` üyeler, sınıfın bir örneği oluşturulmadan erişilebilir.

   ```cpp
   class MyClass
   {
		public:
			static int staticValue;  // Static üye değişken

			static void staticMethod() {  // Static üye fonksiyon
				std::cout << "Static method called" << std::endl;
			}
   };

   int MyClass::staticValue = 0;  // Static üye değişkeninin tanımlanması

   int main()
   {
		MyClass::staticMethod();  // Static metoda sınıf adıyla erişim
		MyClass::staticValue = 5;  // Static değişkene sınıf adıyla erişim
		std::cout << MyClass::staticValue << std::endl; // 5
		return 0;
   }
   ```

2. **Fonksiyonlar için `static`:**
   - Bir fonksiyon `static` olarak tanımlandığında, bu fonksiyon sadece tanımlandığı dosya içinde erişilebilir ve diğer dosyalardan çağrılamaz (dosya kapsamı sağlar).

   ```cpp
    // file1.cpp
    static void myStaticFunction()
    {
        std::cout << "This is a static function" << std::endl;
    }
   ```

3. **Yerel Değişkenler için `static`:**
   - Bir fonksiyon içinde `static` olarak tanımlanan yerel değişkenler, fonksiyon çağrıldığında ilk başta başlatılır ve tüm fonksiyon çağrıları arasında saklanır. Bu değişkenler fonksiyon her çağrıldığında yeniden oluşturulmaz.

   ```cpp
	void countCalls()
	{
		static int callCount = 0;  // İlk çağrıda 0 olarak başlatılır
		callCount++;
		std::cout << "Function called " << callCount << " times" << std::endl;
	}
   ```

### ➤ `const` Anahtar Kelimesi

**`const`**, bir değişkenin değerinin değiştirilemez olduğunu belirtir. `const` anahtar kelimesinin kullanıldığı yerler ve anlamları şunlardır:

1. **Sabit Değişkenler:**
   - Bir değişken `const` olarak tanımlandığında, bu değişkenin değeri bir kez atandıktan sonra değiştirilemez.

   ```cpp
   const int maxScore = 100;  // maxScore değeri değiştirilemez
   ```

2. **Fonksiyon Parametreleri:**
   - Fonksiyon parametrelerinin `const` olarak tanımlanması, fonksiyon içinde bu parametrelerin değiştirilmemesi gerektiğini belirtir.

   ```cpp
	void printValue(const int value)
	{
		std::cout << "Value: " << value << std::endl;
		// value = 10; // Bu satır hata verir çünkü value const olarak tanımlanmış
	}
   ```

3. **Üye Fonksiyonlar için `const`:**
   - Bir sınıfın üye fonksiyonu `const` olarak işaretlenmişse, bu fonksiyon sınıfın herhangi bir üye değişkenini değiştiremez ve sadece `const` üye fonksiyonları çağırabilir.

   ```cpp
	class MyClass
	{
		private:
			int value;

		public:
			MyClass(int v) : value(v) {}

			int getValue() const {  // Bu fonksiyon value değişkenini değiştiremez
				return value;
			}
	};
   ```

4. **Sabit İşaretçiler:**
   - `const` işaretçisi bir işaretçinin kendisinin değiştirilmez olduğunu ifade eder. Örneğin, `const int* ptr` ifadesi, `ptr` işaretçisinin işaret ettiği değerin değiştirilemez olduğunu belirtir.

   ```cpp
   const int num = 10;
   const int* ptr = &num;  // ptr işaretçisinin işaret ettiği değeri değiştiremeyiz
   ```

<br></br>

## `static_cast` Operatörü
`static_cast`, C++'ta bir tür dönüşümü gerçekleştirmek için kullanılan bir operatördür. `std::toupper` fonksiyonu, karakterlerin `unsigned char` türünde olmasını bekler. Bu nedenle, `char` türünden `unsigned char` türüne güvenli bir dönüşüm yapmamız gerekir. `static_cast` bu dönüşümü açık ve güvenli bir şekilde yapmamıza olanak tanır. Bu, özellikle karakter kodlamaları ve taşma durumlarından kaçınmak için önemlidir.

`static_cast`, derleme zamanında tür güvenliğini kontrol eder ve bu nedenle tür dönüşümünün mantıklı olup olmadığını denetler. Bu, C tarzı dönüşümlere göre daha güvenlidir ve daha açık bir niyet gösterir.

### ➤ Örnek ile `static_cast` Kullanımı ve Güvenliği
`std::toupper` fonksiyonu, bir `int` değeri alır ve bir `int` değeri döner. Bununla birlikte, `std::toupper` fonksiyonuna geçilen `int` değeri, `unsigned char` aralığında olmalıdır. Eğer doğrudan bir `char` değeri verilir ve bu değer negatifse, bu istenmeyen davranışlara yol açabilir. Bu nedenle, `char` türündeki bir değeri `unsigned char` türüne dönüştürmek için `static_cast` kullanılır.

### ➤ Neden `static_cast` Kullanmalıyız?
* **Tür Güvenliği:** `static_cast`, derleme zamanında tür dönüşümünün geçerli olup olmadığını kontrol eder. Yanlış tür dönüşümleri derleme hatasına yol açar.
* **Açık Niyet:** Kodunuzu okuyan biri, `static_cast` kullanımının açık ve belirli bir tür dönüşümünü gerçekleştirdiğini hemen anlar.
* **Negatif `char` Değerlerinden Kaçınma:** `char` türü işaretli (signed) olabilir ve negatif değerler içerebilir. Bu durumda, doğrudan `std::toupper` fonksiyonuna geçmek istenmeyen davranışlara yol açabilir. `static_cast<unsigned char>` kullanarak, `char` değerini `unsigned char` türüne dönüştürür ve bu tür sorunlardan kaçınırız.

<br></br>

## Nesneye Yönelimli Programlama (OOP)

Yazılım geliştirmede nesneler ve sınıflar kullanarak kodu organize etme ve yapılandırma yaklaşımıdır. Bu yaklaşım, programın daha anlaşılır, modüler ve bakımının daha kolay olmasını sağlar.

### ➤ Temel Kavramlar

1. **Nesne (Object):**
   - Nesne, veri (özellikler) ve davranışları (metotlar) bir arada tutan bir varlıktır. Nesneler sınıflardan türetilir ve gerçek dünyadaki varlıkları veya kavramları temsil edebilir.

   - Örneğin, bir `Araba` sınıfı olabilir ve bu sınıftan `araba1`, `araba2` gibi nesneler oluşturabilirsiniz. Her nesne, araba sınıfının özelliklerine ve davranışlarına sahip olacaktır.

2. **Sınıf (Class):**
   Sınıf, benzer nesneleri tanımlayan bir şablondur. İçinde veri üyeleri (özellikler) ve üye işlevler (metotlar) bulunur. Sınıflar, nesnelerin oluşturulacağı bir yapı sağlar.

   ```cpp
   class Araba
   {
		public:
			void setRenk(const std::string& renk) { this->renk = renk; }
			std::string getRenk() const { return renk; }

		private:
			std::string renk;
   };
   ```

3. **Kapsülleme (Encapsulation):**
   Kapsülleme, nesnenin veri üyelerinin (özelliklerinin) ve işlevlerinin (metotlarının) bir arada tutulmasını ve dışarıdan erişimin kontrol edilmesini sağlar. Bu, verilerin ve işlevlerin gizlenmesini ve sadece belirli yollarla erişilmesini sağlar.

4. **Kalıtım (Inheritance):**
   Kalıtım, bir sınıfın başka bir sınıftan türetilmesini sağlar. Bu, kodun yeniden kullanılabilirliğini ve genişletilebilirliğini artırır. Türetilen sınıf, temel sınıfın özelliklerini ve işlevlerini devralabilir.

   ```cpp
   class SporAraba : public Araba
   {
		public:
			void setHiz(int hiz) { this->hiz = hiz; }
			int getHiz() const { return hiz; }

		private:
			int hiz;
   };
   ```

5. **Polimorfizm (Polymorphism):**
   Polimorfizm, aynı işlev adının farklı nesnelerde farklı şekillerde çalışmasını sağlar. Bu, aynı arayüzün farklı implementasyonlarının kullanılmasını mümkün kılar.

   ```cpp
	class Hayvan
	{
		public:
			virtual void sesCikar() const = 0; // Saf sanal işlev
	};

	class Kedi : public Hayvan
	{
		public:
			void sesCikar() const override { std::cout << "Miyav!" << std::endl; }
	};

	class Kopek : public Hayvan
	{
		public:
			void sesCikar() const override { std::cout << "Hav!" << std::endl; }
	};
   ```

### ➤ OOP'nin Faydaları

1. **Modülerlik:**
   OOP, kodu sınıflara ve nesnelere bölerek modüler hale getirir. Bu, kodun daha okunabilir ve yönetilebilir olmasını sağlar.

2. **Yeniden Kullanılabilirlik:**
   Sınıflar ve nesneler, bir kez yazıldığında birçok farklı yer ve durumda tekrar kullanılabilir. Bu, yazılım geliştirmede verimliliği artırır.

3. **Bakım Kolaylığı:**
   OOP, kodun daha iyi yapılandırılmış olmasını sağlar, bu da hataların bulunmasını ve düzeltilmesini kolaylaştırır.

4. **Genişletilebilirlik:**
   Kalıtım ve polimorfizm sayesinde, mevcut kodu değiştirmeden yeni işlevler eklemek mümkündür. Bu, yazılımın genişletilmesini ve geliştirilmesini kolaylaştırır.

5. **Gerçek Dünya Modelleme:**
   OOP, gerçek dünya nesnelerini ve ilişkilerini modellemeyi kolaylaştırır. Bu, yazılımın tasarımını daha sezgisel ve anlaşılır hale getirebilir.

Nesneye yönelimli programlama, yazılım mühendisliğinde yaygın olarak kullanılan bir paradigmadır ve büyük ve karmaşık projelerin yönetilmesini kolaylaştırır. Başka bir konuda yardıma ihtiyacınız olursa, lütfen bana bildirin!

<br></br>

## Namespace (Ad Alanı)
 C++'da `namespace` (ad alanı), aynı isimdeki tanımlamaların (değişken, fonksiyon, sınıf vs.) birbiriyle çakışmasını engellemek için kullanılan bir yapıdır. Özellikle büyük projelerde, farklı kütüphaneler veya modüller aynı isimde fonksiyonlar, değişkenler tanımlayabilir. Bu durumda, isim çakışmalarını önlemek ve kodun daha organize bir şekilde yazılmasını sağlamak amacıyla `namespace` kullanılır.

### ➤ `namespace` Kullanımının Temel Faydaları
1. **İsim Çakışmalarını Önlemek:** Farklı modüllerde aynı isimde fonksiyonlar veya değişkenler tanımlandığında, `namespace` ile bu isimler birbirinden ayrılarak çakışma önlenir.
2. **Kod Organizasyonu:** Farklı bileşenleri mantıksal gruplara ayırarak, kodun daha anlaşılır ve yönetilebilir olmasını sağlar.
3. **Modülerlik:** Kendi ad alanlarınızı oluşturabilir ve bu sayede projelerinizi daha modüler hale getirebilirsiniz.

#### Örneklerle Açıklanması

**Örnek 1: İsim Çakışmasını Önlemek**

```cpp
#include <iostream>

namespace Matematik
{
	int topla(int a, int b) {
		return a + b;
	}
}

namespace Fizik
{
    int topla(int a, int b) {
        return a + b + 10;  // Farklı bir işlem yapıyor
    }
}

int main()
{
    int sonuc1 = Matematik::topla(3, 4); // Matematik namespace'indeki topla fonksiyonunu kullanır
    int sonuc2 = Fizik::topla(3, 4);     // Fizik namespace'indeki topla fonksiyonunu kullanır

    std::cout << "Matematik topla: " << sonuc1 << std::endl; // 7 çıktısını verir
    std::cout << "Fizik topla: " << sonuc2 << std::endl;     // 17 çıktısını verir

    return 0;
}
```

Bu örnekte, `Matematik` ve `Fizik` ad alanlarında aynı isimde `topla` fonksiyonları tanımlanmıştır, ancak farklı işlemler yapmaktadırlar. `namespace` sayesinde, bu fonksiyonlar arasında çakışma olmadan kullanılabilir.

**Örnek 2: Namespace İçindeki Elemanları Kullanmak**

```cpp
#include <iostream>

namespace AlanHesaplama
{
    double kareAlani(double kenar) {
        return kenar * kenar;
    }

    double daireAlani(double yaricap) {
        return 3.14159 * yaricap * yaricap;
    }
}

int main()
{
    using namespace AlanHesaplama; // AlanHesaplama namespace'indeki tüm öğeleri doğrudan kullanabiliriz

    double kare = kareAlani(5.0);
    double daire = daireAlani(3.0);

    std::cout << "Kare alanı: " << kare << std::endl;
    std::cout << "Daire alanı: " << daire << std::endl;

    return 0;
}
```

Bu örnekte, `using namespace AlanHesaplama;` ifadesi ile `AlanHesaplama` namespace'indeki fonksiyonları doğrudan kullanabiliyoruz. Artık `kareAlani` ve `daireAlani` fonksiyonlarını kullanırken namespace belirtmemize gerek kalmaz.

**Örnek 3: Namespace İçinde Namespace**

```cpp
#include <iostream>

namespace Proje
{
    namespace ModulA
	{
        void yazdir() {
            std::cout << "Modul A" << std::endl;
        }
    }

    namespace ModulB
	{
        void yazdir() {
            std::cout << "Modul B" << std::endl;
        }
    }
}

int main()
{
    Proje::ModulA::yazdir(); // "Modul A" çıktısını verir
    Proje::ModulB::yazdir(); // "Modul B" çıktısını verir

    return 0;
}
```

Bu örnekte, `Proje` namespace'i altında iki ayrı namespace daha tanımlanmıştır: `ModulA` ve `ModulB`. Bu yapı, projelerde daha detaylı bir organizasyon sağlar.

C++'da `namespace` kullanımı birçok avantaj sağlasa da, bazı dezavantajları da vardır. Bu dezavantajlar, projenizin büyüklüğüne ve karmaşıklığına bağlı olarak ortaya çıkabilir:

#### Dezavantajlar

1. **Kodun Okunabilirliğini Azaltabilir:**
   - Eğer çok fazla `namespace` kullanılırsa, özellikle karmaşık projelerde, kodun anlaşılması zorlaşabilir. Farklı ad alanları arasında geçiş yapmak ve hangi fonksiyonun veya değişkenin hangi ad alanında tanımlandığını takip etmek zor olabilir.
   - Örneğin, farklı modüllerde benzer fonksiyon isimleri kullanılabilir ve bu durumda kodun hangi `namespace`'e ait olduğunu anlamak zorlaşabilir.

2. **Kodun Karmaşıklaşması:**
   - `namespace`'ler iç içe kullanılabilir (nested namespaces), bu durum kodun gereksiz yere karmaşık hale gelmesine yol açabilir. İç içe ad alanları derinleştikçe, kodu izlemek ve anlamak daha da zorlaşabilir.
   - Özellikle, derin `namespace` hiyerarşileri olan projelerde, kodun içeriğini anlamak için sürekli olarak farklı dosyalara veya kod bölümlerine başvurmak gerekebilir.

3. **`using namespace` İfadesinin Yan Etkileri:**
   - `using namespace` ifadesi, belirli bir `namespace` altındaki tüm isimleri geçerli kapsamda (scope) kullanılabilir hale getirir. Bu durum, isim çakışmalarına neden olabilir ve beklenmedik sonuçlar doğurabilir.
   - Örneğin, iki farklı `namespace`'te aynı isimde bir fonksiyon varsa ve ikisi de `using namespace` ile kapsam içine alınmışsa, hangi fonksiyonun çağrıldığı belirsiz hale gelebilir. Bu da hata ayıklamayı zorlaştırır.

4. **Global Namespace Kirliliği:**
   - Eğer `using namespace` ifadesini global kapsamda kullanırsanız, bu durum tüm programın genelinde isim çakışmalarına neden olabilir. Bu da global ad alanını kirletir ve kodun yönetimini zorlaştırır.
   - Örneğin, büyük bir projede birden fazla kütüphane kullanıyorsanız ve hepsi için `using namespace` ifadesini globalde kullanırsanız, hangi fonksiyonun hangi kütüphaneye ait olduğunu takip etmek neredeyse imkansız hale gelir.

5. **Performans Üzerindeki Etkiler:**
   - Derleyicinin, hangi fonksiyonun veya değişkenin hangi `namespace`'te olduğunu belirlemesi daha uzun sürebilir. Özellikle çok fazla `namespace` kullanımı derleme süresini uzatabilir, ancak bu genellikle modern derleyicilerde çok belirgin bir sorun değildir.

### ➤ `namespace` Hatalı Kullanımı

C++'da `namespace` kullanımı, eğer dikkatli bir şekilde yapılmazsa hatalara yol açabilir.

#### 1. İsim Çakışmaları ve `using namespace` Hatası

```cpp
#include <iostream>

namespace Matematik
 {
    int topla(int a, int b) {
        return a + b;
    }
}

namespace Fizik
{
    int topla(int a, int b) {
        return a + b + 10;
    }
}

int main()
{
    using namespace Matematik;
    using namespace Fizik;

    int sonuc = topla(3, 4);  // Hangi "topla" fonksiyonu çağrılacak?

    std::cout << "Sonuç: " << sonuc << std::endl;

    return 0;
}
```

**Açıklama:**
Bu örnekte, hem `Matematik` hem de `Fizik` ad alanlarında `topla` isimli bir fonksiyon tanımlanmıştır. `using namespace` ifadeleri kullanılarak her iki ad alanı da geçerli kapsamda kullanılabilir hale getirilmiştir. Ancak, `sonuc = topla(3, 4);` ifadesi çalıştırıldığında derleyici hangi `topla` fonksiyonunun kullanılacağını belirleyemez ve bu durumda derleyici bir hata verir.

**Çözüm:**
`namespace`'ler arasında açık bir ayrım yapmak için fonksiyon çağrısında ad alanı belirtilmelidir.

```cpp
int sonuc = Matematik::topla(3, 4);
```

#### 2. Global Namespace Kirliliği

```cpp
#include <iostream>

namespace KutuphaneA
{
    void yazdir() {
        std::cout << "Kütüphane A'nın yazdir fonksiyonu" << std::endl;
    }
}

namespace KutuphaneB
{
    void yazdir() {
        std::cout << "Kütüphane B'nin yazdir fonksiyonu" << std::endl;
    }
}

using namespace KutuphaneA;
using namespace KutuphaneB;

int main()
{
    yazdir();  // Hangi yazdir fonksiyonu çalışacak?
    return 0;
}
```

**Açıklama:**
Bu örnekte, iki farklı kütüphanede (`KutuphaneA` ve `KutuphaneB`) aynı isimde `yazdir` fonksiyonları tanımlanmıştır. Global kapsamda her iki `namespace` de `using namespace` ile dahil edildiğinde, `yazdir();` fonksiyonu çağrıldığında derleyici hangi `yazdir` fonksiyonunun çağrılması gerektiğini bilemez ve derleme hatası oluşur.

**Çözüm:**
`using namespace` ifadesinden kaçınmak ve gerektiğinde `namespace` belirtmek daha güvenli olacaktır.

```cpp
KutuphaneA::yazdir();
```

#### 3. İç İçe (Nested) `namespace` Kullanımında Yanlış Yönlendirme

```cpp
#include <iostream>

namespace Proje
{
    namespace Modul
    {
        void yazdir() {
            std::cout << "Modül'ün yazdir fonksiyonu" << std::endl;
        }
    }

    void yazdir() {
        std::cout << "Proje'nin yazdir fonksiyonu" << std::endl;
    }
}

int main()
{
    Proje::Modul::yazdir();  // Doğru: Modül'ün yazdir fonksiyonu çağrılır
    Proje::yazdir();         // Doğru: Proje'nin yazdir fonksiyonu çağrılır

    using namespace Proje;
    yazdir();  // Hangi yazdir fonksiyonu çalışacak?

    return 0;
}
```

**Açıklama:**
Bu örnekte, `Proje` ad alanında hem `yazdir` fonksiyonu tanımlanmış hem de `Modul` isimli iç içe bir `namespace` içinde aynı isimde başka bir `yazdir` fonksiyonu tanımlanmıştır. `using namespace Proje;` ifadesi kullanıldıktan sonra `yazdir();` fonksiyonu çağrıldığında, `Proje` ad alanındaki `yazdir` fonksiyonu ile `Modul` içindeki `yazdir` fonksiyonu arasında bir belirsizlik yaşanabilir.

**Çözüm:**
Belirsizliği önlemek için her zaman `namespace`'i belirterek fonksiyon çağrıları yapılmalıdır.

```cpp
Proje::Modul::yazdir();
```

#### 4. Farklı Dosyalarda `namespace` İle Çakışma

```cpp
// dosya1.cpp
namespace A
{
    void yazdir() {
        std::cout << "dosya1'deki A::yazdir" << std::endl;
    }
}

// dosya2.cpp
namespace A
{
    void yazdir() {
        std::cout << "dosya2'deki A::yazdir" << std::endl;
    }
}

// main.cpp
int main()
{
    A::yazdir();  // Hangi dosyadaki yazdir fonksiyonu çağrılacak?
    return 0;
}
```

**Açıklama:**
Bu senaryoda, `A` ad alanı iki farklı dosyada tanımlanmış ve her iki dosyada da aynı isimde `yazdir` fonksiyonu bulunuyor. Bu, projeyi derlerken çakışmalara neden olabilir ve beklenmedik sonuçlar doğurabilir.

**Çözüm:**
Farklı dosyalarda aynı `namespace` içinde aynı isimde fonksiyon tanımlamaktan kaçınılmalı ya da fonksiyonların işlevlerini farklılaştırarak isim çakışmaları önlenmelidir.

#### 5. Kapsam Dışı Kalan `namespace` Elemanları

```cpp
#include <iostream>

namespace Ornek
{
    void fonksiyon() {
        std::cout << "Ornek namespace'inde fonksiyon" << std::endl;
    }
}

int main()
{
    {
        using namespace Ornek;
        fonksiyon();  // Çalışır: Ornek::fonksiyon çağrılır
    }

    fonksiyon();  // Hata: Ornek::fonksiyon'a erişilemez

    return 0;
}
```

**Açıklama:**
Bu örnekte, `using namespace Ornek;` ifadesi sadece belirli bir blok içinde kullanılıyor. Bu blok dışında `fonksiyon` çağrıldığında, `Ornek` ad alanı kapsam dışı kalmış olacağından derleme hatası meydana gelir.

**Çözüm:**
`namespace`'in kapsamını doğru belirlemek ve bu tür hatalardan kaçınmak için `namespace`'leri gerektiği yerde tanımlamak veya kullanmak önemlidir.

<br></br>

## `friend` Nedir?
C++'de `friend`, bir sınıfa erişim yetkisi verilen başka bir sınıf, fonksiyon veya sınıf üyelerini tanımlamak için kullanılan bir anahtar kelimedir. `friend` anahtar kelimesi, belirli bir sınıfın özel ve korumalı üyelerine erişim sağlamak için kullanılır.

Örneğin, bir sınıfın özel veri üyelerine veya fonksiyonlarına başka bir sınıf veya fonksiyon erişmek istediğinde `friend` anahtar kelimesi kullanılabilir. Bu, iki sınıf arasında özel bir ilişki kurmanıza ve doğrudan veri erişimi sağlamanıza olanak tanır.

Aşağıda basit bir örnek gösterilmektedir:

```cpp
#include <iostream>

class A
{
    private:
        int privateValue;

    public:
        A() : privateValue(10) {}

        // friend fonksiyon bildirimi
        friend void showValue(const A& obj);
};

// friend fonksiyon tanımı
void showValue(const A& obj)
{
    std::cout << "Private value: " << obj.privateValue << std::endl;
}

int main()
{
    A a;
    showValue(a); // friend fonksiyonu özel üyelere erişebilir
    return 0;
}
```

Bu örnekte `showValue` fonksiyonu `A` sınıfının özel üyesine (`privateValue`) erişebilir çünkü `showValue` fonksiyonu `A` sınıfının `friend` olarak tanımlanmıştır.

`friend` anahtar kelimesi genellikle şunlar için kullanılır:

1. **Friend Functions**: Bir fonksiyonun belirli bir sınıfın özel veya korumalı üyelerine erişmesini sağlamak için kullanılır.
2. **Friend Classes**: Bir sınıfın başka bir sınıfın özel ve korumalı üyelerine erişmesini sağlamak için kullanılır.

Bu özellikler, sınıflar arasında sıkı bir bağ kurulmasına ve kodun daha esnek bir şekilde yazılmasına yardımcı olabilir. Ancak, fazla kullanımı genellikle tasarımın karmaşıklığını artırabilir, bu yüzden dikkatli kullanılmalıdır.

<br></br>

