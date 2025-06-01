## CPP Module 07 Notları

- [`Templates`](#templates)
	- [`template` Nedir? Ne İşe Yarar?](#template-nedir-ne-i̇şe-yarar)
	- [`typename` Ne İşe Yarar?](#typename-ne-i̇şe-yarar)
	- [`T` Ne Demek?](#t-ne-demek)
	- [Tüm Değişkenler Birlikteyken Çıkan Anlam](#tüm-değişkenler-birlikteyken-çıkan-anlam)
	- [Neden Template'ler Bu Kadar Faydalı?](#neden-templateler-bu-kadar-faydalı)
	- [Function Templates (Fonksiyon Şablonları)](#function-templates-fonksiyon-şablonları)
	- [Class Templates (Sınıf Şablonları)](#class-templates-sınıf-şablonları)
	- [Template Specialization (Şablon Özelleştirme)](#template-specialization-şablon-özelleştirme)
	- [Non-Type Template Parameters (Sabit Parametreli Şablonlar)](#non-type-template-parameters-sabit-parametreli-şablonlar)
	- [C++98 Sınırlamaları](#c98-sınırlamaları)
	- [Derleyiciye Yardımcı Olma: Template Explicit Instantiation](#derleyiciye-yardımcı-olma-template-explicit-instantiation)
	- [Template’lerin .cpp ve .h Dosyalarına Ayrılması](#templatelerin-cpp-ve-h-dosyalarına-ayrılması)
	- [.tpp Dosyası Nedir?](#tpp-dosyası-nedir)
	- [C++’da Şablon Derleme Kısıtlaması](#cda-şablon-derleme-kısıtlaması)
	- [tpp Dosyası .hpp’ye Nasıl Bağlanır?](#tpp-dosyası-hppye-nasıl-bağlanır)
	- [Template'lerde `&` Kullanımı](#templatelerde--kullanımı)
	- [`&` Kullanımında Olası Senaryolar](#-kullanımında-olası-senaryolar)
	- [Ölçümsel Karşılaştırma](#ölçümsel-karşılaştırma)
	- [Özet](#özet)
- [`Scope`](#scope)
	- [`Scope` (Kapsam) Nedir?](#scope-kapsam-nedir)
	- [C++’da Başlıca Scope Türleri](#cda-başlıca-scope-türleri)
	- [Neden Scope Önemlidir?](#neden-scope-önemlidir)
	- [`::` Operatörü ve Scope](#-operatörü-ve-scope)
- [`::swap(a, b)` Açıklaması](#swapa-b-açıklaması)
	- [`::` Nedir?](#-nedir)
	- [Neden böyle yazıldı?](#neden-böyle-yazıldı)
	- [Neden `::swap` yazıldı?](#neden-swap-yazıldı)
- [Kod Açıklamaları](#kod-açıklamaları)
	- [`[]` operatörünü overload etme işlemi](#-operatörünü-overload-etme-işlemi)
		- [Fonksiyon: `T& operator[](unsigned int index);`](#fonksiyon-t-operatorunsigned-int-index)
		- [Fonksiyon: `const T& operator[](unsigned int index) const;`](#fonksiyon-const-t-operatorunsigned-int-index-const)
	- [Class Templates](#class-templates)
		- [`Array<T>`](#arrayt)
		- [Template Parametresinin Tanımlanması](#template-parametresinin-tanımlanması)

<br></br>

## `Templates`

C++98 standartlarında template konusu, özellikle **generic programming (genel programlama)** açısından çok önemlidir. C++’ta **şablonlar (templates)**, aynı kodun farklı veri tipleriyle çalışmasını sağlar. Bu, kod tekrarını azaltır ve daha esnek, yeniden kullanılabilir yapılar oluşturmanı sağlar.

<br>

### `template` Nedir? Ne İşe Yarar?

- Anlamı: `template`, Türkçesiyle şablon demektir.
- Ne işe yarar: `template`, farklı veri tipleriyle aynı işlemi yapabilen fonksiyonlar veya sınıflar yazmamıza olanak sağlar.
- Neden kullanılır: Aynı işlemi `int`, `double`, `string` gibi türlerle yapmak için ayrı ayrı kod yazmak yerine bir kez yazıp her türde kullanabilmek için.
- Örnek:
	```cpp
	template	<typename T>
	T	add(T a, T b)
	{
		return a + b;
	}
	```

Bu fonksiyon hem int, hem float, hem double, hem char ile çalışabilir. Hepsi için ayrı ayrı yazmana gerek kalmaz.

<br>

### `typename` Ne İşe Yarar?

- Anlamı: `typename`, bir tür (type) geleceğini söyler. Yani `T`, bir veri tipi olacak diyoruz.
- Alternatifi: C++98’de typename yerine class da yazılaarakta kullanılabilir (ilerleyen yazıda örnek kullanım mevcuttur):
	```cpp
	template	<class T>
	```
- Ne işe yarar: Derleyiciye diyoruz ki “Burada bir tür parametresi var. Bu tür, fonksiyon/sınıf kullanılırken belli olacak.”
- Örnek:
	```cpp
	template	<typename T>
	T multiply(T x, T y)
	{
		return x * y;
	}
	```

Buradaki T, bir türdür (int, double, string, vs.) ve bunu typename ile belirttik.

<br>

### `T` Ne Demek?

- Anlamı: `T`, template içinde kullanılan tür adı için bir değişken gibi düşünebilirsin.

>❗ Önemli Not:
>	- T özel bir sözcük değildir.
>	- İstediğin ismi verebilirsin: typename X, typename MyType, typename Banana da olabilir.

Ama C++ dünyasında alışkanlık olarak genelde T, U, V gibi harfler kullanılır.

- Örnek:
	```cpp
	template	<typename T>
	T square(T value)
	{
		return value * value;
	}
	```

Burada:
- `T` yerine `int` geçerse, fonksiyon `int square(int value)` gibi olur.
- `T` yerine `double` geçerse, `double square(double value)` olur.

<br>

### Tüm Değişkenler Birlikteyken Çıkan Anlam

- Tam cümleyle:
	```cpp
	template	<typename T>
	T add(T a, T b)
	```
- Şunu söyler:
	- `template`: Bu bir şablondur (farklı türlerle çalışabilir).
	- `<typename T>`: Bu şablon bir tür parametresi alır. O türün adı T.
	- `T add(...)`: Bu fonksiyonun dönüş tipi ve parametreleri, T türündedir.

<br>

### Neden Template'ler Bu Kadar Faydalı?

Diyelim ki aynı işlevi 3 farklı tür için yazman gerekiyor:
```cpp
int		add(int a, int b)        { return a + b; }
double	add(double a, double b)  { return a + b; }
float	add(float a, float b)    { return a + b; }
```

Bunları yazmak yerine, bir tane template yazarsın:
```cpp
template	<typename T>
T	add(T a, T b)
{
    return a + b;
}
```

Ve böyle kullanırsın:
```cpp
add(3, 4);               // int
add(3.5, 2.2);           // double
add<float>(1.1f, 2.2f);  // float (açıkça belirtilmiş)
```

<br></br>

### Function Templates (Fonksiyon Şablonları)

- Amaç: Aynı işlevi farklı türlerle (int, float, double, vb.) gerçekleştirmek.

- Sözdizimi:
	```cpp
	template <typename T>
	T max(T a, T b)
	{
		return (a > b) ? a : b;
	}
	```

- Açıklama:
	- `template <typename T>`: Bu satır, T adında bir tür parametresi tanımlar.
	- Fonksiyonun içinde T türü kullanılır, derleyici, fonksiyon çağrılırken türü otomatik belirler.

- Kullanım:
	```cpp
	int main()
	{
		std::cout << max(3, 7) << std::endl;         // int
		std::cout << max(3.5, 2.1) << std::endl;     // double
		std::cout << max('a', 'z') << std::endl;     // char
	}
	```

<br>

### Class Templates (Sınıf Şablonları)

- Amaç: Farklı veri türleriyle çalışan sınıflar tanımlamak.

- Sözdizimi:
	```cpp
	template <typename T>
	class Box
	{
		private:
			T	value;

		public:
			Box(T v) : value(v) {}
			T	getValue() const { return value; }
	};
	```

- Kullanım:
	```cpp
	int main()
	{
		Box<int>	intBox(5);
		Box<string>	strBox("Hello");

		std::cout << intBox.getValue() << std::endl;
		std::cout << strBox.getValue() << std::endl;
	}
	```

<br>

### Template Specialization (Şablon Özelleştirme)

Bazen bir tür için farklı davranış sergilemek istersin. Bu durumda template specialization kullanılır.

- Örnek:
	```cpp
	template <typename T>
	class Printer
	{
		public:
			void	print(T data)
			{
				cout << "Generic: " << data << endl;
			}
	};

	// string için özel hali
	template <>
	class Printer<string>
	{
		public:
			void	print(string data)
			{
				cout << "String: " << data << endl;
			}
	};
	```

- Kullanım:
	```cpp
	Printer<int>	pi;
	pi.print(10); // Generic: 10

	Printer<string>	ps;
	ps.print("Hello"); // String: Hello
	```

<br>

### Non-Type Template Parameters (Sabit Parametreli Şablonlar)

Template parametreleri sadece tür değil, sabit değerler de olabilir.

- Örnek:
	```cpp
	template <typename T, int size>
	class Array
	{
		private:
			T	arr[size];
		public:
			int	getSize() const { return size; }
	};
	```

- Kullanım:
	```cpp
	Array<int, 10>	myArray;
	std::cout << myArray.getSize(); // 10
	```

<br>

### C++98 Sınırlamaları
- `typename` yerine `class` da yazılabilir: `template<class T>`
- C++98’d,e `variadic templates` (değişken sayıda argüman alan şablonlar) yoktur. (Bu özellik C++11 ile geldi.)
- `auto`, `decltype`, `constexpr` gibi modern özellikler yoktur.
- Template’lerin `SFINAE`, `concepts` gibi daha ileri özellikleri C++98’de mevcut değildir.

<br>

### Derleyiciye Yardımcı Olma: Template Explicit Instantiation
```cpp
template	class Box<int>;  // Derleyiciye, int için Box<T>'yi oluşturmasını söylersin
```

<br>

### Template’lerin .cpp ve .h Dosyalarına Ayrılması

C++98’de template fonksiyonlar ve sınıflar header dosyasında tanımlanmalıdır. Çünkü derleyici, instantiation (örnekleme) sırasında template’in tanımını bilmek zorundadır.

⛔ Bu olmaz:
```cpp
// Box.h
template <typename T>
class Box {
    T value;
    Box(T val);
    T get();
};

// Box.cpp
// Tanımlar buradaysa -> Link hatası verir!
```

✅ Bu olmalı:

Tüm tanımları .h dosyasına koyarsın ya da .cpp dosyasını .tpp gibi ayrı bir dosyada include edersin.

<br>

### .tpp Dosyası Nedir?

.tpp dosyası (template implementation file), C++’ta template (şablon) sınıf ve fonksiyonların tanımlarını (gövdesini) içeren dosyadır.

📌 .tpp, “template implementation” anlamına gelir ve genelde .cpp yerine kullanılır çünkü template’ler özel bir kurala uyar (derleyici tüm tanımı header’da görmek ister).

<br>

### C++’da Şablon Derleme Kısıtlaması

Şablonlar derleyici tarafından kullanıldığı yerde türüne göre derlenir.

Bu nedenle:
- Sadece .hpp dosyasında bildirimi (declaration) olan bir şablon, tanımı olmadan derlenemez.
- Bu yüzden tanımı da (.tpp dosyası) .hpp dosyasına dahil edilmek zorundadır.

<br>

### tpp Dosyası .hpp’ye Nasıl Bağlanır?

```cpp
// Array.hpp
#ifndef ARRAY_HPP
# define ARRAY_HPP

template	<typename T>
class Array
{
	public:
		Array();
		T&	operator[](unsigned int index);
		// ...
};

#include "Array.tpp" // 📌 Tanımlar buradan çağrılır

#endif
```

.tpp dosyası genellikle .hpp dosyasının en altına eklenir. Böylece, Array.hpp dosyasını include eden bir dosya, şablonun hem bildirimine hem de tanımına erişmiş olur.

<br>

| Nerede include etmeliyim?           | Neden?                                                                               |
|-------------------------------------|--------------------------------------------------------------------------------------|
| .hpp dosyasının en altında          | Şablon sınıfın tanımı, bildirimden sonra gelmeli. En güvenli ve yaygın yer burasıdır.|
| Başka bir dosyada (örneğin main.cpp)| Önerilmez. .tpp tanımı .hpp dosyasından ayrı düşerse derleme sorunları çıkar.        |
| #include sadece bir kez yapılmalı   | Aksi halde multiple definition hatası alırsın.                                       |

<br>

> 📌 Neden Böyle Yapmak Zorundayız, Yapmazsak Ne Olur?
>
> C++ derleyicisi şablonların tanımına ihtiyaç duyar, aksi takdirde aşağıdaki gibi hatalar alırsın. .tpp dosyası .hpp dosyasının başında include edilirse fonksiyon ve sınıf tanımlamadan fonksiyon ve sınıf implement edilmeye çalışılır, bu da hata almaya sebep olur. .tpp dosyasının .hpp dosyasında en alt satırda include edilerek bu hata engellenir.
```cpp
./Array.tpp: error: unknown type name 'Array'
	Array<T> &Array<T>::operator=(Array const &rhs)
```

<br>

### Template'lerde `&` Kullanımı

- Soru: min ve max fonksiyonlarında neden & (referans) kullanıyoruz?
```cpp
const T&	min(const T& a, const T& b);
```

- Cevap: Çünkü performans, gereksiz kopyalamayı önleme ve doğrudan orijinal nesneyle çalışma sağlıyor.

<br>

### `&` Kullanımında Olası Senaryolar

1. **Referans (&) Kullanmazsan Ne Olur?**

	Eğer böyle yazarsan:
	```cpp
	template	<typename T>
	T	min(T a, T b)
	{
		return (a < b) ? a : b;
	}
	```

	Bu durumda:
	- a ve b fonksiyona kopyalanarak gelir.
	- Dönüş değeri de yeni bir kopya olur.

	- Sorunlar:
		- Büyük veri tiplerinde (std::string, std::vector gibi) gereksiz performans kaybı yaşarsın.
		- const nesneleri bu fonksiyona gönderemezsin.
		- Olası yan etkiler doğar (örneğin: kopya yapıldığında destructor, copy constructor çağrılır).

2. **Referans (&) Kullanırsan Ne Olur?**

	```cpp
	template	<typename T>
	const T&	min(const T& a, const T& b);
	```

	- Avantajlar:
		- a ve b kopyalanmaz, doğrudan orijinal nesnelerle çalışılır.
		- Dönüş değeri de orijinal nesneye referanstır, ekstra kopya oluşmaz.
		- Büyük nesnelerde çok daha hızlıdır.
		- const kullanımı sayesinde güvenlidir (değiştirme riski yoktur).

	- Basit Karşılaştırmalı Örnek:
		```cpp
		std::string	x = "hello";
		std::string	y = "world";

		// Referanssız min()
		auto result1 = min_no_ref(x, y);  // x ve y KOPYALANIR, sonra biri daha döndürülür => TOPLAM 3 KOPYA

		// Referanslı min()
		auto result2 = min_with_ref(x, y); // Hiç kopyalama yok, direkt referans döner => SIFIR KOPYA
		```

<br>

### Ölçümsel Karşılaştırma

| Kullanım Türü       | Kopya Sayısı | Performans Etkisi |
|---------------------|--------------|-------------------|
| `T min(T a, T b)`   | 2-3 kopya    | Yavaş             |
| `T const& min(...)` | 0 kopya      | Hızlı             |

<br>

### Özet

| Ne?           | Neden Kullanılır?                                |
|---------------|--------------------------------------------------|
|& (Referans)   | Kopyalamamak için (verimlilik)                   |
|const          | Değiştirilmesin diye (güvenlik)                  |
|T const& dönüşü| Orijinal nesneyi döndürmek, kopyadan kaçmak için |

<br></br>

## `Scope`

C++ (ve diğer programlama dillerinde) scope (alan/kapsam) çok temel ve çok önemli bir kavramdır. Anlayınca birçok karışıklık ortadan kalkar.

<br>

### `Scope` (Kapsam) Nedir?

Scope, bir değişkenin, fonksiyonun veya tanımın nerede geçerli olduğunu belirler.

Yani, bir isim (değişken, fonksiyon, sınıf vs.) nerede görülebilir, nerede kullanılabilir? Bu alan “scope” olarak adlandırılır.

- Örnek:
	```cpp
	int	x = 10; // global scope

	void	myFunction()
	{
		int	y = 20; // local scope

		std::cout << x << std::endl; // erişebilir (global)
		std::cout << y << std::endl; // erişebilir (local)
	}

	int	main()
	{
		myFunction();
		std::cout << x << std::endl;    // erişebilir çünkü global scope
		// std::cout << y << std::endl; // erişemez (y sadece myFunction içinde erişilebilir)
	}
	```
- Açıklama:
	- `x`: Global scope – her yerden erişilebilir.
	- `y`: Local scope – sadece `myFunction` içinde geçerlidir.

<br>

### C++’da Başlıca Scope Türleri

|Scope Türü|	Açıklama|
|---|---|
|`Global scope`|	Dosyanın en dışında tanımlanan isimler. Her yerden erişilebilir.|
|`Local scope`|	Bir fonksiyon, döngü, blok {} içinde tanımlanan isimler. Sadece o blok içinde geçerlidir.|
|`Function scope`|	Sadece fonksiyon içinde geçerli olan isimler.|
|`Class/struct scope`|	Sınıf veya struct içindeki üyeler. Sadece sınıf içinden veya sınıfın nesnesiyle erişilir.|
|`Namespace scope`|	namespace içinde tanımlı isimler. Erişmek için isim:: şeklinde yazılır.|

<br>

### Neden Scope Önemlidir?
	1. Çakışmaları önler: Aynı isimde iki değişken olabilir ama farklı scope’larda.
	2. Kodun okunabilirliğini artırır: Değişken nerede tanımlıysa, nerede kullanıldığını bilirsin.
	3. Hata riskini azaltır: Yanlışlıkla başka bir yerdeki aynı isimli değişkeni kullanmazsın.

<br>

### `::` Operatörü ve Scope
`::` operatörü sayesinde bir ismin hangi scope’ta olduğunu açıkça belirtiriz.

Örnek:
```cpp
int	value = 5; // global

void func()
{
	int	value = 10; // local

	std::cout << value << std::endl;   // 10 (local)
	std::cout << ::value << std::endl; // 5 (global, :: ile belirtilmiş)
}
```

<br>

## `::swap(a, b)` Açıklaması

### `::` Nedir?
- `::` operatörü C++’ta scope resolution operator (alan çözümleme operatörü) olarak adlandırılır.
- `::swap(...)` ifadesi, global scope’ta tanımlı olan swap fonksiyonunu çağır anlamına gelir.

<br>

### Neden böyle yazıldı?

C++’ta `std::swap` gibi standart kütüphane fonksiyonları da vardır. Ancak burada kendi swap fonksiyonumuzu yazdığımızı varsayıyoruz.

Eğer sadece `swap(a, b)` yazarsan, aşağıdaki sırayla şu yerlerde bu fonksiyon aranır:
1. Aynı scope’taki (örneğin sınıf içinde veya namespace içinde tanımlanmış) swap fonksiyonu.
2. `std::swap` (eğer `using namespace std;` varsa ya da elle `std::swap` yazarsan).
3. Global scope ( `::swap` ).

<br>

### Neden `::swap` yazıldı?

Çünkü bu programda amaç:
- Kendi tanımladığımız (global scope’ta yazdığımız) swap, min ve max fonksiyonlarını çağırmak.
- std::swap, std::min, std::max gibi STL versiyonları değil.

<br>

🧠 Akılda Kalması İçin:

| Yazım Şekli     | Anlamı                           |
|-----------------|----------------------------------|
|`swap(a, b)`     | En yakın scope’taki swap         |
|`std::swap(a, b)`| STL’deki swap fonksiyonu         |
|`::swap(a, b)`   | Global scope’taki swap fonksiyonu|

<br></br>

## Kod Açıklamaları

### `[]` operatörünü overload etme işlemi

#### Fonksiyon: `T& operator[](unsigned int index);`

- Non-const (değiştirilebilir) nesneler için kullanılır.
- `T& Array<T>::operator[](unsigned int index) { ... }`
  - `operator[]` fonksiyonunun bildirimi ve tanımıdır.
  - `Array<T>::` : Bu fonksiyon, Array sınıfının bir üyesidir.
  - `T&` : Dönen değer, T türünden bir referanstır. Bu, dizideki öğeyi değiştirilebilir şekilde döndürür (örneğin arr[2] = 10; yapılabilir).
  - `unsigned int index` : Erişilmek istenen dizin (indeks). Negatif sayı kabul edilmez çünkü `unsigned`.
- `if (index >= _size)`
  - `_size` : Bu, Array sınıfının bir üyesi olan, dizi boyutunu tutan değişkendir.
  - Bu satır, erişilmek istenen index’in dizinin boyutundan büyük olup olmadığını kontrol eder.
  - Örneğin `_size == 5` ise geçerli indeksler 0–4 arasıdır. `index == 5` veya daha büyükse bu satır `true` döner.
- `throw std::exception();`
  - Eğer `index` geçersizse (sınırların dışındaysa), `std::exception` fırlatılır.
  - Bu, `#include <exception>` başlığı altında bulunan standart bir hata türüdür.
  - Bu şekilde kullanıcıya `“Geçersiz dizin erişimi”` olduğunu belirtmiş oluruz.
  - Bu satırdan sonra fonksiyon çalışmayı durdurur, çağrıldığı yerde hata yakalanmazsa program çöker.
- `return _array[index];`
  - `this->_array` : Array sınıfının tuttuğu dinamik diziye (heap’te) işaret eder.
  - Belirtilen index’teki öğeye referansla erişilir ve döndürülür.
  - `T&` döndürüldüğü için kullanıcı bu öğeyi değiştirebilir.

<br>

#### Fonksiyon: `const T& operator[](unsigned int index) const;`

- const (değiştirilemez) nesneler için kullanılır.
- Aynı açıklamalar const versiyon için de geçerlidir. Tek farkları:

  - `const T& Array<T>::operator[](unsigned int index) const { ... }`
    - `const T&` : Bu kez dönen referans, değiştirilemezdir.
    - Fonksiyonun sonunda da const anahtar kelimesi vardır:
      - Bu, fonksiyonun sınıfın hiçbir üye verisini değiştirmeyeceğini garanti eder.
    - Bu sürüm, const Array<int> arr; gibi sabit nesnelerle çağrıldığında devreye girer.

  - `if (index >= _size) throw std::exception(); return _array[index];`
    - Yukarıda açıklandığı gibi, sınır kontrolü yapılır.
    - Değiştirilemez bir referans (`const T&`) döndürülür, yani kullanıcı bu veriyi sadece okuyabilir.

<br></br>

### Class Templates

#### `Array<T>`

- Genel Tanım: `Array<T>` bir şablon (template) sınıf tanımıdır.
- Bu şu demek:
  - `T`, veri tipi için bir yer tutucudur.
  - Bu sınıf ile farklı veri türleri için (int, float, std::string, vs.) aynı yapıyı kullanarak dizi oluşturabiliriz.
- Örnek:
	```cpp
	Array<int> intArray;
	Array<std::string> strArray;
	Array<Point> pointArray;
	```

Her biri aynı `Array<T>` yapısını kullanır ama `T` yerine kendi türlerini koyar. Böylece tekrar kod yazmaya gerek kalmaz.

<br>

#### Template Parametresinin Tanımlanması

Derleyici, şablon sınıfının dışında tanımlanan her fonksiyonda T’nin bir şablon parametresi olduğunu kendiliğinden anlayamaz. Ona bunu açıkça söylemek zorundasın çünkü T normal bir tür de olabilir. Bunu belirtmediğin sürece T’nin bir “şablon parametresi” olduğunu varsaymaz.

<br>

**> Teknik Açıklama**

1. Şablon sınıf bildirimi
	```cpp
	template	<typename T>
	class Array
	{
		public:
			void	doSomething();
	};
	```
	Burada T bir template parametresi. Sınıf tanımının içinde derleyici zaten T’yi biliyor.

<br>

2. Üye fonksiyon sınıf dışında tanımlandığında:
	```cpp
	void	Array<T>::doSomething() { ... }
	```

	Bu kod hatalıdır çünkü:
	- Derleyici burada `T`’nin nereden geldiğini bilmez.
	- Belki bu sadece `Array<int>` gibi önceden tanımlı bir türdür diye düşünür.
	- C++’ta `Array<T>` gibi bir tür, hem şablon türü olabilir, hem de (teorik olarak) gerçek bir sınıf adı olabilir.

	Bu yüzden template<typename T> yazmalısın:
	```cpp
	template	<typename T>
	void	Array<T>::doSomething()
	{
		// now it's okay, compiler knows T is a template parameter
	}
	```


⸻

🧠 Kıyaslamak için:

Diyelim ki aşağıdaki gibi bir normal sınıfın dışarıda fonksiyon tanımını yapıyorsun:

class MyClass {
	void show();
};

void MyClass::show() {
	// no problem, because compiler knows what MyClass is
}

Ama şablonlar farklıdır: tür parametresi olan T’nin anlamı şablon tanımı dışında belirsizdir, ta ki template<typename T> ile açıklanana kadar.

⸻

📌 Olası Sorun:

void Array<T>::foo() // ❌ HATA: ‘T’ tanımsız

Derleyici şu soruyu sorar:

“T diye bir şey var mı burada? Belki bir tipti ama ben bilmiyorum.”

⸻

🎓 Bu Kuralın Mantığı

C++’ın şablonları erteleme (delayed instantiation) ilkesine göre işler. Derleyici şablonun gövdesine genellikle sadece o şablon gerçekten kullanıldığında bakar. Bu yüzden, tanım sırasında her şeyin açıkça belirtilmesini ister.

⸻

✅ Kısacası

Nerede?	template<typename T> gerekli mi?
Sınıf tanımı içinde (inline tanım)	❌ Hayır
Sınıf dışında fonksiyon tanımı	✅ Evet


⸻

İstersen bu kuralın örneklerle gösterildiği bir .cpp ve .hpp dosyası yapabilirim. Hazır mısın?
