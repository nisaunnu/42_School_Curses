## CPP Module 06 Notları

- [`static` Nedir?](#static-nedir)
	- [`static` Fonksiyonlar Ne Anlama Geliyor?](#static-fonksiyonlar-ne-anlama-geliyor)
	- [Neden `static` Kullanılıyor?](#neden-static-kullanılıyor)
- [Özel Değerler (Special Values / Pseudo Literal)](#özel-değerler-special-values--pseudo-literal)
	- [+inf, -inf, +inff, -inff → Infinity (Sonsuzluk)](#inf--inf-inff--inff--infinity-sonsuzluk)
	- [nan, nanf → Not a Number (Sayı Değil)](#nan-nanf--not-a-number-sayı-değil)
	- [`float` ve `double` farkı](#float-ve-double-farkı)
	- [Özet](#özet)
- [`static_cast`](#static_cast)
	- [Temel Sözdizimi](#temel-sözdizimi)
	- [Hangi Durumlarda Kullanılır?](#hangi-durumlarda-kullanılır)
	- [`static_cast` Ne Zaman Kullanılmamalı](#static_cast-ne-zaman-kullanılmamalı)
	- [ScalarConverter Örneği Üzerinden Açıklama](#scalarconverter-örneği-üzerinden-açıklama)
	- [`static_cast` VS C-style `cast`](#static_cast-vs-c-style-cast)
- [`std::numeric_limits`](#stdnumeric_limits)
	- [Amaç Nedir?](#amaç-nedir)
	- [Örnek Kullanımlar](#örnek-kullanımlar)
	- [Kullanışlı Üyeler](#kullanışlı-üyeler)
	- [ScalarConverter Örneği](#scalarconverter-örneği)
	- [Desteklenen Türler](#desteklenen-türler)
- [`std::fixed` ve `std::setprecision`](#stdfixed-ve-stdsetprecision)
	- [`std::fixed` Nedir?](#stdfixed-nedir)
	- [`std::setprecision(n)` Nedir?](#stdsetprecisionn-nedir)
	- [Karşılaştırmalı Örnek](#karşılaştırmalı-örnek)
- [`reinterpret_cast`](#reinterpret_cast)
	- [Neden tehlikeli?](#neden-tehlikeli)
	- [Söz Dizimi (Syntax)](#söz-dizimi-syntax)
	- [Örnekler](#örnekler)
	- [Ne zaman kullanılmalı?](#ne-zaman-kullanılmalı)
	- [Kullanılmaması gereken durumlar](#kullanılmaması-gereken-durumlar)
- [`rand()` ve `srand()`](#rand-ve-srand)
	- [`rand()`](#rand)
	- [`srand()`](#srand)
	- [Neden `srand()` kullanılır?](#neden-srand-kullanılır)
	- [`rand() % N` Kullanımı](#rand--n-kullanımı)
- [`dynamic_cast`](#dynamic_cast)
	- [Kullanım Şekli](#kullanım-şekli)
	- [Ne Zaman Kullanılır?](#ne-zaman-kullanılır)

<br></br>

## `static` Nedir?

C++ dilinde static anahtar kelimesi, bir sınıf üyesinin (değişken veya fonksiyon) sınıfın bir örneğine (instance) değil, doğrudan sınıfa ait olduğunu belirtmek için kullanılır. Bu, fonksiyonların veya değişkenlerin nesne oluşturmadan da kullanılabilmesini sağlar.

<br>

### `static` Fonksiyonlar Ne Anlama Geliyor?
```cpp
static bool isChar(const std::string& literal);
static bool isInt(const std::string& literal);
static bool isFloat(const std::string& literal);
static bool isDouble(const std::string& literal);

static void convertChar(const std::string& literal);
static void convertInt(const std::string& literal);
static void convertFloat(const std::string& literal);
static void convertDouble(const std::string& literal);
```

Bu fonksiyonların static olarak tanımlanması şu anlama gelir:
- Bu fonksiyonlar, ScalarConverter sınıfının bir örneği (instance) oluşturmadan doğrudan sınıf adıyla çağrılabilir:
	```cpp
	ScalarConverter::convert("42");
	```

- static fonksiyonların içinde, sınıfın statik olmayan (normal) üyelerine erişilemez. Çünkü bu fonksiyonlar herhangi bir nesneye bağlı değildir.

<br>

### Neden `static` Kullanılıyor?

Bu sınıfın genel yapısına baktığımızda:
- Kurucu (constructor) ve kopya kurucu (copy constructor) private yapıldı. Bu durum, ScalarConverter sınıfından nesne oluşturulmasını engeller.
- Sınıf sadece bir araç (utility) sınıfı gibi davranacak şekilde tasarlandı. Yani sadece bir girdi alıp, uygun türe göre dönüşüm yapacak fonksiyonlar barındırıyor, örneğin:
	```cpp
	ScalarConverter::convert("123.0f");
	```

Bu durumda static fonksiyonlar kullanmak mantıklıdır çünkü sınıftan örnek oluşturmaya gerek kalmaz.

<br></br>

## Özel Değerler (Special Values / Pseudo Literal)

C++’ta özel değerler (special values), float ve double gibi kayan noktalı sayılar için kullanılan bazı özel tanımlı durumlardır. Bunlar, sayı gibi görünmelerine rağmen aslında matematiksel olarak geçersiz veya uç durumlar için kullanılırlar.

<br>

### +inf, -inf, +inff, -inff → Infinity (Sonsuzluk)

Bu değerler, bir sayının sonsuz büyüklükte ya da sonsuz küçüklükte olduğunu belirtir.

|Değer	|Açıklama|	Tür|
|---|---|---|
|+inf|	Pozitif| sonsuzluk| (double)|	double|
|-inf|	Negatif| sonsuzluk| (double)|	double|
|+inff|	Pozitif| sonsuzluk| (float)|	float|
|-inff|	Negatif| sonsuzluk| (float)|	float|

- Nasıl oluşur?

	```cpp
	#include <iostream>

	int main()
	{
		float x = 1.0f / 0.0f;
		std::cout << x << std::endl; // +inf

		float y = -1.0f / 0.0f;
		std::cout << y << std::endl; // -inf
	}
	```

- Kullanım amacı:
	- Bir işlem sonucu sınırların dışına çıkıldığında, çökmek yerine “sonsuz” değer döndürmek için kullanılır.
	- Programın çökmeden çalışmaya devam etmesini sağlar.

<br>

### nan, nanf → Not a Number (Sayı Değil)

Bu değer, bir işlemin sonucu matematiksel olarak tanımsız ise oluşur.

|Değer|	Açıklama	|Tür|
|---|---|---|
|nan|	Not a Number (double)	|double|
|nanf|	Not a Number (float)	|float|

- Nasıl oluşur?
	```cpp
	#include <iostream>

	int main()
	{
		float z = 0.0f / 0.0f;
		std::cout << z << std::endl; // nan
	}
	```

- Diğer örnekler:
	- `sqrt(-1)` gibi negatif bir sayının karekökünü almaya çalışmak.
	- `inf - inf` gibi sonsuzlukları birbirinden çıkarmak.

- Kullanım amacı:
	- Tanımsız veya geçersiz işlemleri işaretler.
	- Matematiksel doğruluk sağlanır.
	- Bu değere özel kontroller yapılabilir:
		```cpp
		if (std::isnan(z))
			std::cout << "z is not a number" << std::endl;
		```

<br>

### `float` ve `double` farkı
- nanf, +inff, -inff → float türünde (sonunda f var)
- nan, +inf, -inf    → double türünde (sonunda f yok)

<br>

### Özet

|Değer	|Anlamı	|Tip|
|---|---|---|
|+inf	|Pozitif sonsuz	|double|
|-inf	|Negatif sonsuz	|double|
|+inff	|Pozitif sonsuz	|float|
|-inff	|Negatif sonsuz	|float|
|nan	|Sayı değil (Not a Number)	|double|
|nanf	|Sayı değil (Not a Number)	|float|


<br></br>

## `static_cast`

`static_cast`, C++’ta derleme zamanında (compile time) yapılan açık ve güvenli tip dönüşümleri için kullanılır. Bu dönüşüm türü, mantıklı ve izin verilen türler arasında yapılır.

<br>

### Temel Sözdizimi
```cpp
static_cast<hedef_tür>(ifade);
```

Örnek:
```cpp
int		x = 42;
double	y = static_cast<double>(x); // int → double dönüşümü
```

<br>

### Hangi Durumlarda Kullanılır?

- Sayısal türler (int → float, float → double, vs.)
	```cpp
	int		i = 10;
	float	f = static_cast<float>(i); // OK
	```

- Pointer türleri arasında (base → derived ya da void)*
	```cpp
	void* ptr = &i;
	int* intPtr = static_cast<int*>(ptr); // Güvenli değildir ama derlenir
	```
	Not: Bu durumda reinterpret_cast veya dynamic_cast daha uygun olabilir. static_cast, burada dikkatli kullanılmalı.

- Enum ↔ int dönüşümleri
	```cpp
	enum Color { RED, GREEN, BLUE };

	int		a = static_cast<int>(RED);    // 0
	Color	c = static_cast<Color>(2);  // BLUE
	```

- Class inheritance (Base ↔ Derived)
	```cpp
	class	Base {};
	class	Derived : public Base {};

	Base*		b = new Derived();
	Derived*	d = static_cast<Derived*>(b); // Derleyici izin verir ama dikkatli olunmalı
	```
	Burada static_cast, RTTI (Run-Time Type Information) kullanmaz, bu yüzden tür yanlışsa çökme olabilir.

   void* ile dönüşüm
	```cpp
	void*	ptr = &x;
	int*	iptr = static_cast<int*>(ptr); // Cast yapılır, ama dikkatli ol
	```

<br>

### `static_cast` Ne Zaman Kullanılmamalı
- Runtime kontrolü gerekliyse                         → dynamic_cast daha güvenlidir.
- Tamamen ilgisiz türler arasında dönüşüm gerekiyorsa → reinterpret_cast gerekir.
- const’ı kaldırmak istiyorsan                        → const_cast gerekir.

<br>

### ScalarConverter Örneği Üzerinden Açıklama

Koddan bir örnek:
```cpp
std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
```

Burada:
- c: bir char
- static_cast<float>(c): char’ı float türüne dönüştürür

Neden static_cast kullanıldı?
- Bu dönüşüm güvenlidir (örneğin 'A' → 65.0).
- Derleyici zaten bu dönüşüme izin verir, ama static_cast kullanmak açıkça ve güvenli şekilde dönüştürme yapıldığını gösterir.

<br>

### `static_cast` VS C-style `cast`

- C-style `cast`:
	```c
	float f = (float)i;
	```
	Bu dönüşüm:
	- `static_cast`, `reinterpret_cast`, hatta `const_cast` gibi davranabilir.
	- Güvensizdir, ne yaptığını tam olarak bilemezsin.
	- Kodun okunabilirliğini ve hataların bulunabilirliğini azaltır.

- `static_cast`:
	```cpp
	float f = static_cast<float>(i);
	```
	- Daha okunaklı ve ne yaptığını açıkça gösterir.
	- C++’ta önerilen yoldur.

<br></br>

## `std::numeric_limits`

`std::numeric_limits` C++’ta bir veri türünün sayısal sınırlarını (minimum, maksimum, epsilon, vs.) öğrenmek için kullanılan bir şablon (template) sınıftır. Bu sınıf <limits> başlık dosyasında (header) tanımlanmıştır.

<br>

### Amaç Nedir?

`std::numeric_limits<T>` :
- Tür T için sayısal özellikleri sağlar.
- Derleyiciye sormadan int, float, double, vs. gibi türlerin taşma sınırlarını, en küçük/büyük değerlerini verir.

<br>

### Örnek Kullanımlar
```cpp
#include <iostream>
#include <limits>

int main()
{
	std::cout << "int min: " << std::numeric_limits<int>::min() << std::endl;
	std::cout << "int max: " << std::numeric_limits<int>::max() << std::endl;

	std::cout << "float min: " << std::numeric_limits<float>::min() << std::endl;
	std::cout << "float max: " << std::numeric_limits<float>::max() << std::endl;

	std::cout << "double epsilon: " << std::numeric_limits<double>::epsilon() << std::endl;

	return 0;
}
```

<br>

###  Kullanışlı Üyeler

|Üye İsmi|	Açıklama|
|---|---|
|`min()`|	Pozitif sayılar için en küçük temsil edilebilir değer (float için ≠ negatif max)|
|`max()`|	En büyük temsil edilebilir değer|
|`lowest()`|	Temsil edilebilir en küçük (negatif) sayı|
|`epsilon()`|	1.0 ile temsil edilebilen en küçük fark (kayan nokta türleri için)|
|`is_signed`|	Türün işaretli (signed) olup olmadığını belirtir (true/false)|
|`is_integer`|	Tam sayı mı değil mi (true/false)|
|`digits`|	Bit cinsinden hassasiyet|


<br>

### ScalarConverter Örneği

Koddan alıntı:
```cpp
if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
```

Bu satır:
- value değişkeninin `int` türünün alabileceği sınırların dışında olup olmadığını kontrol eder.
- Böylece taşma (overflow) engellenmiş olur.

<br>

### Desteklenen Türler

`std::numeric_limits<T>` şu türler için çalışır:
- int, short, long, long long
- float, double, long double
- unsigned türler
- char, bool gibi türler de desteklenir ama bazı üyeler anlamlı değildir.

<br></br>

## `std::fixed` ve `std::setprecision`

`std::fixed` ve `std::setprecision` özellikle ondalıklı sayıların (float, double) `std::cout` ile çıktı formatını kontrol etmek için kullanılır. Bunlar` <iomanip>` kütüphanesi içinde yer alır.

<br>

### `std::fixed` Nedir?

`std::fixed`, `std::cout` çıktısında ondalıklı sayıları sabit ondalık (decimal) gösterimle yazdırır.

- Özellikleri:
	- Sayıların bilimsel (e.g., 1.23e+03) formatta değil, normal ondalık biçimde yazılmasını sağlar.
	- Tek başına sadece formatı değiştirir, kaç basamak gösterileceğini belirlemez.

- Örnek:
	```cpp
	#include <iostream>
	#include <iomanip>

	int main()
	{
		double x = 123.456789;

		std::cout << std::fixed;
		std::cout << x << std::endl;  // Çıktı: 123.456789 (default precision)
	}
	```

<br>

### `std::setprecision(n)` Nedir?

`std::setprecision(n)` ise çıktıda kaç basamak gösterileceğini belirler.

- Özellikleri:
	- std::fixed ile birlikte kullanıldığında, virgülden sonra n basamak gösterir.
	- std::fixed OLMADAN kullanılırsa, toplam önemli basamak sayısını ayarlar (bilimsel gösterim dahil).

- Örnek:
	```cpp
	#include <iostream>
	#include <iomanip>

	int main()
	{
		double x = 3.14159265;

		// Sabit ondalıklı gösterim ve 3 basamak
		std::cout << std::fixed << std::setprecision(3);
		std::cout << x << std::endl;  // Çıktı: 3.142
	}
	```

<br>

### Karşılaştırmalı Örnek
```cpp
#include <iostream>
#include <iomanip>

int main()
{
	double	x = 123.456789;

	std::cout << "Varsayilan   : " << x << std::endl;
	std::cout << "Precision(3) : " << std::setprecision(3) << x << std::endl;
	std::cout << "Fixed + Precision(3): " << std::fixed << std::setprecision(3) << x << std::endl;
}
```

Çıktı:
```markdown
Varsayilan   : 123.457
Precision(3) : 123
Fixed + Precision(3): 123.457
```

<br></br>

## `reinterpret_cast`

`reinterpret_cast` C++’ta yer alan dört temel tür dönüşüm (type casting) aracından biridir. Diğerleri `static_cast`, `const_cast`, `dynamic_cast`’tir. `reinterpret_cast`, en tehlikeli ve düşük seviyeli dönüşüm türüdür.

`reinterpret_cast` bir veri tipini tamamen farklı bir tipmiş gibi yorumlamak (reinterpret etmek) için kullanılır. Derleyiciye, “Bu bellek adresindeki veriyi şu türmüş gibi değerlendir” dersin.

> Genellikle adresler (işaretçiler) üzerinde kullanılır. Uygunsuz kullanımı undefined behavior’a yol açabilir.

<br>

### Neden tehlikeli?
- Derleyiciye tip güvenliğini (type safety) bypass etmesini söylersin.
- Bellekteki bitler aynı kalır ama nasıl yorumlanacağı değişir.
- Bu, yanlış yorumlama sonucu beklenmedik davranışlara veya çökme (segfault) gibi hatalara yol açabilir.

<br>

### Söz Dizimi (Syntax)
```cpp
reinterpret_cast<hedef_tür>(ifade);
```

<br>

### Örnekler

* Örnek 1 – int adresini char*’a dönüştürmek
	```cpp
	#include <iostream>

	int main()
	{
		int		num = 65;
		char*	ptr = reinterpret_cast<char *>(&num);

		std::cout << *ptr << std::endl; // 'A' → ASCII 65
	}
	```

	num bir int, ama bellekteki ilk byte’ı char gibi okuduk.

* Örnek 2 – İşaretçileri farklı türlerde yorumlamak
	```cpp
	#include <iostream>

	struct A
	{
		int	x;
	};

	struct B
	{
		double	y;
	};

	int main()
	{
		A	a = {10};
		B*	bPtr = reinterpret_cast<B*>(&a);

		std::cout << bPtr->y << std::endl;  // Undefined behavior!
	}
	```

	Bu dönüşüm teknik olarak mümkündür ama davranışı tanımsızdır (undefined).

<br>

### Ne zaman kullanılmalı?
- Sistem seviyesi programlamada (örn: donanım adresleriyle çalışırken),
- Low-level optimizasyonlarda,
- C kütüphaneleri ile entegrasyonlarda (örn: raw memory handling),

gibi çok özel durumlarda kullanılmalıdır.

<br>

### Kullanılmaması gereken durumlar
- Sınıf hiyerarşisinde (base ↔ derived) dönüşüm yapmak.
- Tip güvenliğinin önemli olduğu yerlerde.
- Normal tip dönüşümleri için (int ↔ double gibi) → static_cast kullanmalısın.

<br></br>

## `rand()` ve `srand()`

`rand()` ve `srand()` fonksiyonları, C ve C++’ta rastgele sayı üretmek için kullanılan fonksiyonlardır. Bunlar `<cstdlib`> başlık dosyasında tanımlıdır.

<br>

### `rand()`

- Tanım:
	```cpp
	int	rand();
	```

- Ne yapar?
	- 0 ile RAND_MAX arasında (genellikle 32,767) rastgele bir tamsayı döndürür.
	- Aynı programı her çalıştırdığında aynı sayı dizisini üretir (deterministik).

-  Örnek:
	```cpp
	#include <iostream>
	#include <cstdlib>

	int main()
	{
		std::cout << rand() << std::endl;  // Örnek çıktı: 1804289383
		std::cout << rand() << std::endl;  // Örnek çıktı: 846930886
	}
	```

<br>

### `srand()`

-Tanım:
	```cpp
	void	srand(unsigned int seed);
	```

- Ne yapar?
	- rand() fonksiyonunun üreteceği sayıların başlangıç noktasını (seed) ayarlar.
	- Aynı seed değeri ile hep aynı rastgele sayı dizisi elde edilir.
	- Eğer farklı rastgele sayılar isteniyorsa srand() sadece bir kez, genellikle program başında çağrılır.

- Genellikle time(0) ile birlikte kullanılır:
	```cpp
	#include <iostream>
	#include <cstdlib>
	#include <ctime>

	int main()
	{
		srand(time(0));  // zaman tabanlı seed
		std::cout << rand() % 100 << std::endl;  // 0-99 arası rastgele sayı
	}
	```

<br>

### Neden `srand()` kullanılır?

Eğer `srand()` kullanmazsan:
```cpp
// Her çalıştırmada aynı sonuç:
std::cout << rand() << std::endl;
```

Ama `srand(time(0))` ile farklı çalıştırmalarda farklı sayılar üretirsin:
```cpp
srand(time(0));
std::cout << rand() << std::endl;
```

<br>

###	`rand() % N` Kullanımı

Rastgele sayı aralığı belirlemek için:
```cpp
int	r = rand() % 10;  // 0 ile 9 arası
```
Ama bu yöntem çok büyük hassasiyet gerektiren durumlarda dengeli dağılım sağlamaz. Daha doğru yöntemler için C++11 ile gelen `std::uniform_int_distribution` önerilir.

<br></br>

## `dynamic_cast`

C++’ta özellikle polimorfik sınıflar arasında güvenli tip dönüşümleri yapmak için kullanılan bir tür dönüştürme operatörüdür. En çok kalıtım ilişkisi olan sınıflar arasında kullanılır.

`dynamic_cast` aşağıdaki durumlar için kullanılır:
- Base (üst sınıf) → Derived (alt sınıf) dönüşümleri için.
- `dynamic_cast` ile yapılacak dönüşüm runtime’da kontrol edilir.
- Bu dönüşüm yalnızca en az bir sanal fonksiyonu olan (yani polimorfik) sınıflar için çalışır.

<br>

### Kullanım Şekli

1. Pointer (işaretçi) ile kullanımı:
	```cpp
	Base*	basePtr = new Derived();
	Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
	```

	- Eğer basePtr gerçekten Derived türündeyse, derivedPtr null olmayan geçerli bir işaretçi olur.
	- Eğer değilse derivedPtr == nullptr olur.

	> Null kontrolü yapılmalıdır!

2. Reference (referans) ile kullanımı:
	```cpp
	Base&	baseRef = ...;

	try
	{
		Derived&	derivedRef = dynamic_cast<Derived &>(baseRef);
		// Başarılıysa buraya gelir
	} catch (const std::bad_cast& e) {
		// Tür uyumsuzsa buraya düşer
	}
	```

	- Referans dönüşüm başarısız olursa `std::bad_cast` istisnası fırlatılır.
	- Bu yüzden try-catch içinde kullanılmalıdır.

<br>

### Ne Zaman Kullanılır?
- Çok biçimlilik (polymorphism) içeren yapılarda.
- Aynı hiyerarşideki sınıflar arasında güvenli aşağı dönüşüm (downcasting) yapmak istediğimizde.
- Hangi türe ait olduğunu runtime’da bilmediğimiz nesnelerde.

<br>

- Örnek:
	```cpp
	class Base { public: virtual ~Base() {} };
	class A : public Base {};
	class B : public Base {};

	void identify(Base* p)
	{
		if (dynamic_cast<A *>(p))
			std::cout << "A" << std::endl;
		else if (dynamic_cast<B *>(p))
			std::cout << "B" << std::endl;
		else
			std::cout << "Unknown" << std::endl;
	}
	```

<br></br>
