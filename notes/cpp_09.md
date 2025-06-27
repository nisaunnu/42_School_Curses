## CPP Module 09 Notları

- [`std::ifstream`](#stdifstream)
	- [Temel Kullanımı](#temel-kullanımı)
- [`std::istringstream`](#stdistringstream)
	- [Temel Kullanımı](#temel-kullanımı-1)
- [`clock_t` ve `clock()` Fonksiyonu](#clock_t-ve-clock-fonksiyonu)
	- [Temel Kullanımı](#temel-kullanımı-2)
- [Kod Açıklamaları](#kod-açıklamaları)
	- [\> ex00 \<](#-ex00-)
	- [\> ex01 \<](#-ex01-)

## `std::ifstream`

std::ifstream, C++ Standard Library içinde bulunan bir giriş dosya akımı (input file stream) sınıfıdır. Dosyadan veri okumak için kullanılır. ifstream ile bir dosya açarsın ve içeriğini satır satır veya kelime kelime okuyabilirsin.

### Temel Kullanımı
```cpp
#include <fstream>
#include <string>

std::string		line;
std::ifstream	file("data.txt"); // "data.txt" adlı dosyayı okuma modunda açar

if (file.is_open())
{
	while (std::getline(file, line))
	{
		// Dosyadan satır satır okur
	}
	file.close();
}
```

⚠️ Notlar:
- ifstream sadece okuma içindir. Yazmak için ofstream, hem okuma hem yazma için fstream kullanılır.
- file.is_open() dosyanın gerçekten açılıp açılmadığını kontrol eder.
- std::getline() fonksiyonu ile satır satır okuma yapılabilir.

<br></br>

## `std::istringstream`

std::istringstream, bir string içerisindeki verileri okuma amacıyla kullanılan akım sınıfıdır. Yani dosyadan değil, bir std::string ifadesinden veri okuyabilmeni sağlar.

Bu sınıf, bir string’i sanki bir dosya gibi işleyip parça parça analiz etmene olanak tanır.

### Temel Kullanımı
```cpp
#include <sstream>
#include <string>
#include <iostream>

std::string			text = "2025-06-28";
std::istringstream	ss(text);

int		year, month, day;
char	dash1, dash2;

ss >> year >> dash1 >> month >> dash2 >> day;
```

Yukarıdaki kodda:
- "2025-06-28" string’i içinden year = 2025, month = 6, day = 28 olarak ayrıştırılır.
- dash1 ve dash2 değişkenleri "-" karakterlerini tutar.

<br></br>

## `clock_t` ve `clock()` Fonksiyonu

`clock_t`, zaman ölçümlerinde kullanılan bir veri tipidir. Zamanı CPU saat çevrimleri (clock ticks) cinsinden ölçmek için kullanılır.

Kullanım Amaçları:
- Genellikle bir işlemin ne kadar sürede tamamlandığını ölçmek için kullanılır.

### Temel Kullanımı
```cpp
#include <ctime>
#include <iostream>

clock_t	start = clock(); // Başlangıç zamanı
for (int i = 0; i < 1000000; ++i); // Ölçülmek istenen işlem
clock_t	end = clock(); // Bitiş zamanı

double	duration = double(end - start) / CLOCKS_PER_SEC; // Saniye cinsinden süre
std::cout << "Süre: " << duration << " saniye" << std::endl;
```

- `clock()` → o anki CPU saat sayısını döndürür.
- `CLOCKS_PER_SEC` → saniyedeki clock tick sayısını temsil eder.
- `end - start` → işlem süresini ölçer.
- `/ CLOCKS_PER_SEC` ile bunu saniyeye çeviririz.

<br></br>

## Kod Açıklamaları

### > ex00 <

- Kod:
	```cpp
	std::istringstream	ss(date);
	ss >> year >> dash1 >> month >> dash2 >> day;
	```
- Detaylı Açıklama:
	- Bu kod parçası, "YYYY-MM-DD" (örneğin "2025-06-28") biçimindeki bir tarih string’ini yıl, ay ve gün bileşenlerine parçalamak için kullanılır.
	- Adım Adım:
		1. `std::istringstream ss(date);`
			* `date` adlı `std::string` türündeki değişkenin içeriği bir `istringstream` nesnesine aktarılır. Artık bu string’i tıpkı bir dosya gibi okuyabiliriz.
		2. `ss >> year >> dash1 >> month >> dash2 >> day;`
			* year  → yıl bilgisini alır (örneğin: 2025)
			* dash1 → ilk - karakterini alır (örneğin: ‘-’)
			* month → ay bilgisini alır (örneğin: 6)
			* dash2 → ikinci - karakterini alır
			* day   → gün bilgisini alır (örneğin: 28)

Örnek:
```cpp
std::string date = "2025-06-28";
int year, month, day;
char dash1, dash2;

std::istringstream ss(date);
ss >> year >> dash1 >> month >> dash2 >> day;
// year = 2025, month = 6, day = 28
```

<br>

### > ex01 <

- Kod:
	```cpp
	std::string			token;
	std::istringstream	iss(expression);

	while (iss >> token) {
		// ...
	}
	```
- Detaylı Açıklama:
  - Bu kod parçası, bir string’i boşluklara göre kelimelere ayırmak için kullanılır.
  - Adım Adım:
	1. `std::istringstream iss(expression);`
		* `expression` adındaki bir `std::string`, örneğin "3 4 + 5 *" gibi bir ifade olabilir. Bu string `iss` adlı akıma aktarılır.
	2. `while (iss >> token)`
		* `iss` akımından kelime kelime (token denir buna) veri alınır.
		* `>>` operatörü boşlukla ayrılmış her bir parçayı sırayla çeker.
		* Döngü, tüm kelimeler işlenene kadar devam eder.

Örnek:
```cpp
std::string			token;
std::string			expression = "3 4 + 5 *";
std::istringstream	iss(expression);

while (iss >> token)
	std::cout << "Token: " << token << std::endl;
```

Çıktı:
```
Token: 3
Token: 4
Token: +
Token: 5
Token: *
```

Yani bu yapı, bir matematiksel ifadeyi veya komutları parçalayıp analiz etmek için çok kullanışlıdır.

<br>
