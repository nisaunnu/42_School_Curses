## Exam Rank 05 - Konu Anlatımı
- [Exam Rank 05 - Konu Anlatımı](#exam-rank-05---konu-anlatımı)
- [Coplien Form Nedir?](#coplien-form-nedir)
- [Abstract Class (Soyut Sınıf) Nedir?](#abstract-class-soyut-sınıf-nedir)
	- [Pure Virtual (Saf Sanal) Fonksiyon Nedir?](#pure-virtual-saf-sanal-fonksiyon-nedir)
		- [Tanım](#tanım)
		- [Örnek Üzerinden Anlatım](#örnek-üzerinden-anlatım)
		- [Kullanım Örneği](#kullanım-örneği)
		- [Neden Kullanılır?](#neden-kullanılır)
	- [Temel Sözdizimi](#temel-sözdizimi)
	- [Soyut Sınıftan Kalıtım ve Kullanım](#soyut-sınıftan-kalıtım-ve-kullanım)
	- [Kullanım Örneği](#kullanım-örneği-1)
- [`std::map` Nedir?](#stdmap-nedir)
	- [Genel Yapısı](#genel-yapısı)
	- [Map’e Eleman Ekleme](#mape-eleman-ekleme)
	- [Map’ten Değer Alma](#mapten-değer-alma)
	- [Eleman Varsa mı Diye Kontrol Etme](#eleman-varsa-mı-diye-kontrol-etme)
	- [Map’ten Eleman Silme](#mapten-eleman-silme)
	- [Tüm Map’i Gezmek (döngü ile)](#tüm-mapi-gezmek-döngü-ile)
	- [Map Bellek Yönetimi (Pointerlarla Çalışıyorsan)](#map-bellek-yönetimi-pointerlarla-çalışıyorsan)
	- [Map’in Özellikleri](#mapin-özellikleri)
	- [Sık Kullanılan Fonksiyonlar](#sık-kullanılan-fonksiyonlar)
	- [Uygulamalı Örnek](#uygulamalı-örnek)
	- [`std::map` Ne Zaman Kullanılmalı?](#stdmap-ne-zaman-kullanılmalı)

<br></br>

## Coplien Form Nedir?

C++‘de Coplien’s Form veya Ortodoks Kanonik Form (Orthodox Canonical Form), bir sınıfın doğru şekilde kaynak yönetimini sağlaması ve C++’in temel prensipleriyle uyumlu olması için gereken özel üye fonksiyonları tanımlama pratiğidir. Bu form, özellikle dinamik bellek kullanan sınıflarda önemlidir.

Coplien’s Form kapsamında aşağıdaki özel üye fonksiyonlar yer alır:

1. Default Constructor (Varsayılan Yapıcı)
	•	Sınıfın bir örneğini argüman vermeden oluşturmak için kullanılır.
	•	Eğer herhangi bir kurucu yazmazsanız, derleyici varsayılan bir tane sağlar.

	```cpp
	class Example
	{
		public:
			Example()
			{
				// Varsayılan işlemler
			}
	};
	```

2. Copy Constructor (Kopya Yapıcı)
	•	Bir nesneyi başka bir nesneden kopyalamak için kullanılır.
	•	Özellikle sınıfta dinamik bellek kullanılıyorsa, derin kopyalama yapmak için önemlidir.

	```cpp
	class Example
	{
		public:
			Example(const Example& other)
			{
				// 'other' nesnesinden kopyalama işlemleri
			}
	};
	```

3. Copy Assignment Operator (Kopya Atama Operatörü)
	•	Bir nesneyi başka bir nesneye kopyayla atamak için kullanılır.
	•	Mevcut nesnenin içeriğini temizlemeyi ve derin kopyayı düzgün bir şekilde yapmayı gerektirir.

	```cpp
	class Example
	{
		public:
			Example& operator=(const Example& other)
			{
				if (this != &other)
				{
					// Mevcut kaynakları temizle
					// 'other' nesnesinden kopyalama işlemleri
				}
				return *this;
			}
	};
	```

4. Destructor (Yıkıcı)
	•	Nesne ömrü sona erdiğinde çağrılır.
	•	Dinamik olarak tahsis edilen kaynakları serbest bırakmak için önemlidir.

	```cpp
	class Example
	{
		public:
			~Example()
			{
				// Kaynakları serbest bırak
			}
	};
	```

<br></br>

## Abstract Class (Soyut Sınıf) Nedir?

C++’de bir abstract class, en az bir pure virtual function (saf sanal fonksiyon) içeren sınıftır.

Soyut sınıflardan nesne oluşturulamaz. Sadece kalıtım (inheritance) yoluyla kullanılabilirler.

<br></br>

### Pure Virtual (Saf Sanal) Fonksiyon Nedir?

C++’de pure virtual function, bir abstract (soyut) fonksiyondur. Bu fonksiyonun gövdesi (içi) yoktur ve alt sınıflar tarafından mutlaka yeniden tanımlanması (override) gerekir.

#### Tanım

Saf sanal fonksiyon şu şekilde tanımlanır:
```cpp
virtual void fonksiyonAdi() = 0;
```

- `virtual` : Bu fonksiyonun sanal (virtual) olduğunu belirtir.
- `= 0`     : Bu fonksiyonun saf (pure) olduğunu belirtir.
- Fonksiyonun gövdesi yoktur.

#### Örnek Üzerinden Anlatım

```cpp
class Sekil
{
	public:
		// saf sanal fonksiyon
		virtual void ciz() = 0;
};
```

Yukarıda:
- `ciz()` fonksiyonu saf sanal fonksiyondur.
- `Sekil` sınıfı da bu yüzden soyut sınıftır.
- Bu fonksiyonun nasıl çalışacağını `alt sınıf (child class)` belirlemek zorundadır.

#### Kullanım Örneği
```cpp
class Sekil
{
	public:
		virtual void ciz() = 0; // pure virtual
};

class Daire : public Sekil
{
	public:
		void ciz()
		{
			std::cout << "Daire ciziliyor.\n";
		}
};

int main()
{
	Sekil* s = new Daire();

	s->ciz(); // "Daire ciziliyor."

	delete s;
	return 0;
}
```

- `Daire` sınıfı `Sekil`’i miras alıyor ve `ciz()` fonksiyonunu `override` ediyor.
- Bu sayede `Sekil* sekil = new Daire();` polimorfik kullanım mümkün oluyor.

#### Neden Kullanılır?

- Taban sınıf (base class) sadece bir arayüz (interface) sağlar.
- Türeyen sınıflar kendi özel davranışlarını tanımlar.
- Bu, polimorfizm için temel oluşturur.

<br></br>

### Temel Sözdizimi
```cpp
class Sekil
{
	public:
		// saf sanal fonksiyon
		virtual void ciz() = 0;

		// normal fonksiyon olabilir
		void bilgi()
		{
			std::cout << "Bu bir sekildir.\n";
		}
};
```

Yukarıdaki örnekte `Sekil` soyut bir sınıftır çünkü `ciz()` fonksiyonu saf sanaldır.

<br>

### Soyut Sınıftan Kalıtım ve Kullanım
```cpp
class Daire : public Sekil
{
	public:
		void ciz()
		{
			std::cout << "Daire ciziliyor.\n";
		}
};

class Kare : public Sekil
{
	public:
		void ciz()
		{
			std::cout << "Kare ciziliyor.\n";
		}
};
```
<br>

### Kullanım Örneği
```cpp
int main()
{
	// Sekil s; // HATA! Soyut sınıftan nesne olusturulamaz.

	Sekil* sekil1 = new Daire();
	Sekil* sekil2 = new Kare();

	sekil1->ciz(); // Daire ciziliyor.
	sekil2->ciz(); // Kare ciziliyor.

	delete sekil1;
	delete sekil2;
	return 0;
}
```

<br></br>

## `std::map` Nedir?

`std::map`, anahtar-değer (key-value) eşleşmesi yapan bir kapsayıcıdır.

Gerçek hayattan örnek:

Bir telefon rehberi düşün:
- İsim (anahtar)          : “Ali”
- Telefon numarası (değer): “0533”

İşte map tam olarak böyle çalışır:
```cpp
std::map<std::string, std::string> rehber;
rehber["Ali"] = "0533";
```

<br>

### Genel Yapısı
```cpp
std::map<KeyType, ValueType> isim;
```

Örnekler:
```cpp
std::map<std::string, int> yaslar;        // İsim → yaş
std::map<std::string, ASpell*> buyuler;   // Büyü ismi → büyü nesnesi
```

<br>

### Map’e Eleman Ekleme
```cpp
yaslar["Ahmet"] = 25;
yaslar["Ayşe"] = 30;
```
Eğer aynı anahtarla tekrar eklersen, eski değerin üzerine yazar.

<br>

### Map’ten Değer Alma
```cpp
std::cout << yaslar["Ayşe"];  // 30 yazar
```

<br>

### Eleman Varsa mı Diye Kontrol Etme
```cpp
if (yaslar.find("Ahmet") != yaslar.end())
	std::cout << "Ahmet bulundu!\n";
```

- `.find(key)` : anahtarı bulursa iterator döner
- Bulamazsa `.end()` döner (yani “yok” demek)

<br>

### Map’ten Eleman Silme
```cpp
yaslar.erase("Ayşe");  // Ayşe'yi map'ten siler
```
Silerken önce `find` ile var mı diye kontrol edebilirsin.

<br>

### Tüm Map’i Gezmek (döngü ile)
```cpp
std::map<std::string, int>::iterator it;

for (it = yaslar.begin(); it != yaslar.end(); ++it)
	std::cout << it->first << ": " << it->second << std::endl;
```

- `it->first`  : Anahtar
- `it->second` : Değer

<br>

### Map Bellek Yönetimi (Pointerlarla Çalışıyorsan)

Eğer map’in içindeki değerler işaretçi (pointer) ise, onları `delete` etmek gerekir:
```cpp
for (it = buyuler.begin(); it != buyuler.end(); ++it)
{
	delete it->second;
}
buyuler.clear();
```

<br>

### Map’in Özellikleri

|Özellik             |Açıklama                                                   |
|--------------------|-----------------------------------------------------------|
|Sıralıdır           | Anahtarlar küçükten büyüğe sıralı tutulur (operator< ile) |
|Anahtarlar eşsizdir | Aynı anahtardan bir tane olabilir                         |
|Erişim hızı         | Ortalama O(log n), yani çok hızlı                         |

<br>

### Sık Kullanılan Fonksiyonlar

| Fonksiyon    | Ne işe yarar                          |
|--------------|---------------------------------------|
| `map[key]`   | Anahtara göre değer ekler/alır        |
| `find(key)`  | Anahtarı arar, bulursa iterator döner |
| `erase(key)` | Anahtara göre siler                   |
| `begin()`    | İlk elemana işaret eden iterator      |
| `end()`      | Sonraki elemana işaret eden iterator  |
| `clear()`    | Tüm map’i temizler                    |

<br>

### Uygulamalı Örnek
```cpp
#include <iostream>
#include <map>
#include <string>

int main()
{
	std::map<std::string, int> skor;

	skor["Ali"] = 10;
	skor["Ayşe"] = 20;

	// Eleman yazdır
	std::cout << "Ali: " << skor["Ali"] << std::endl;

	// Güncelle
	skor["Ali"] = 15;

	// Varsa yazdır
	if (skor.find("Ayşe") != skor.end())
		std::cout << "Ayşe: " << skor["Ayşe"] << std::endl;

	// Sil
	skor.erase("Ayşe");

	// Gez
	for (std::map<std::string, int>::iterator it = skor.begin(); it != skor.end(); ++it)
		std::cout << it->first << ": " << it->second << std::endl;

	return 0;
}
```

<br>

### `std::map` Ne Zaman Kullanılmalı?
- Anahtar-değer eşlemesi yapacaksan
- Anahtarla hızlı erişim istiyorsan
- Anahtarlar otomatik sıralansın istiyorsan

<br></br>
