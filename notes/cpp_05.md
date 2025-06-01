## CPP Module 05 Notları

- [Repetition (Tekrar)](#repetition-tekrar)
- [Exceptions (İstisnalar)](#exceptions-i̇stisnalar)
	- [Temel Yapı](#temel-yapı)
	- [Birden Fazla `catch` Bloku](#birden-fazla-catch-bloku)
	- [`std::exception`](#stdexception)
	- [Custom Exceptions (Özel İstisnalar)](#custom-exceptions-özel-i̇stisnalar)
- [Özel İstisna Sınıflarının Kodda Açıklanması (ex00)](#özel-i̇stisna-sınıflarının-kodda-açıklanması-ex00)
	- [Özel İstisna Sınıfları (`GradeTooHighException` ve `GradeTooLowException`)](#özel-i̇stisna-sınıfları-gradetoohighexception-ve-gradetoolowexception)
	- [`std::exception` Nedir?](#stdexception-nedir)
	- [`GradeTooHighException` ve `GradeTooLowException`](#gradetoohighexception-ve-gradetoolowexception)
	- [Kodun Parça Parça Açıklaması](#kodun-parça-parça-açıklaması)
	- [Hataların Yakalanması (Exception Handling)](#hataların-yakalanması-exception-handling)

<br></br>

## Repetition (Tekrar)

C++’de tekrar, genellikle döngüler kullanılarak gerçekleştirilir. Döngüler, bir kod bloğunu birden fazla kez çalıştırmak için kullanılır. Döngü türleri şunlardır:
<br></br>

<details>
<summary><span style="font-size:16px; font-weight:bold;"><code>for</code> Döngüsü</span></summary>

Belirli bir sayıda tekrarlanacak işlemler için kullanılır.

```cpp
#include <iostream>

int main()
{
	for (int i = 0; i < 5; i++)
		std::cout << "Merhaba, dünya! " << i + 1 << " kez.\n";
	return 0;
}
```

Çalışma prensibi:
- `i = 0:` Başlangıç durumu.
- `i < 5:` Döngü devam şartı.
- `i++:` Her tekrar sonunda i değeri bir artırılır.
</details><br>
<details><summary><span style="font-size:16px; font-weight:bold;"><code>while</code> Döngüsü</span></summary>

Şart doğru olduğu sürece çalışır. Şart baştan kontrol edilir.

```cpp
#include <iostream>

int main()
{
	int i = 0;

	while (i < 5)
	{
		std::cout << "i değeri: " << i << "\n";
		i++;
	}
	return 0;
}
```
</details><br>
<details><summary><span style="font-size:16px; font-weight:bold;"><code>do-while</code> Döngüsü</span></summary>

En az bir kez çalışması garanti edilir. Şart sondan kontrol edilir.

```cpp
#include <iostream>

int main()
{
	int i = 0;

	do
	{
		std::cout << "i değeri: " << i << "\n";
		i++;
	} while (i < 5);

	return 0;
}
```
</details><br>
<details><summary><span style="font-size:16px; font-weight:bold;"><code>break</code> ve <code>continue</code></span></summary>

- `break:` Döngüyü tamamen sonlandırır.
- `continue:` Döngünün o anki iterasyonunu atlayarak bir sonrakine geçer.

```cpp
#include <iostream>

int main()
{
	for (int i = 0; i < 10; i++)
	{
		if (i == 5)     // 5'e gelince döngü sona erer.
			break;
		if (i % 2 == 0) // Çift sayılar atlanır.
			continue;
		std::cout << i << " ";
	}
	return 0;
}
```
</details>

<br></br>

## Exceptions (İstisnalar)

C++’de istisnalar, programın normal akışını bozabilecek hataları yakalamak ve yönetmek için kullanılır. Bu sistem, `try-catch` bloklarıyla gerçekleştirilir.

### Temel Yapı

```cpp
#include <iostream>

int main()
{
	try
	{
		throw 42; // İstisna oluştur.
	}
	catch (int e)
	{
		std::cout << "Hata yakalandı: " << e << "\n";
	}
	return 0;
}
```

- `try:` Hata meydana gelebilecek kod buraya yazılır.
- `throw:` Bir istisna fırlatır.
- `catch:` İstisnayı yakalar ve işler.

### Birden Fazla `catch` Bloku

Farklı türde istisnaları yakalamak için birden fazla catch kullanılabilir.

```cpp
#include <iostream>

int main()
{
	try
	{
		throw std::string("Bir hata oluştu!");
	}
	catch (int e)
	{
		std::cout << "Tam sayı hatası: " << e << "\n";
	}
	catch (std::string &e)
	{
		std::cout << "Dize hatası: " << e << "\n";
	}
	catch (...)  // Genel catch (her şeyi yakalar)
	{
		std::cout << "Bilinmeyen bir hata yakalandı.\n";
	}

	return 0;
}
```

### `std::exception`

C++ standart kütüphanesi, tüm istisnaların temel sınıfı olan `std::exception` sınıfını sunar.

```cpp
#include <iostream>
#include <exception>

int main()
{
	try
	{
		throw std::runtime_error("Beklenmeyen bir hata!");
	}
	catch (std::exception &e)
	{
		std::cout << "Hata: " << e.what() << "\n";
	}

	return 0;
}
```

- `e.what():` Hata mesajını döndürür.

### Custom Exceptions (Özel İstisnalar)

Kendi istisna sınıflarınızı yazabilirsiniz:

```cpp
#include <iostream>
#include <exception>

class MyException : public std::exception
{
	public:
		const char* what() const noexcept override
		{
			return "Benim özel hatam!";
		}
};

int main()
{
	try
	{
		throw MyException();
	}
	catch (MyException &e)
	{
		std::cout << e.what() << "\n";
	}

	return 0;
}
```
<br></br>

## Özel İstisna Sınıflarının Kodda Açıklanması (ex00)

Bu kısım, Bureaucrat sınıfında derecelerin sınırlarını aşması durumunda özel `hata (exception)` sınıflarını tanımlar. C++ dilinde `exception handling (hata yönetimi)` için standart bir mekanizma bulunur ve bu mekanizmayı kullanarak, sınıfa özgü özel hataları tanımlayabiliriz.

### Özel İstisna Sınıfları (`GradeTooHighException` ve `GradeTooLowException`)

Bu iki sınıf, `std::exception` sınıfından türetilmiştir. Yani, bu sınıflar standart bir C++ `exception` türü gibi davranır. Ancak bu sınıfları kullanarak Bureaucrat sınıfına özel hatalar yaratabiliriz.

### `std::exception` Nedir?

`std::exception` C++’ın standart kütüphanesinde bulunan bir temel sınıftır ve `hata yönetimi (exception handling)` için kullanılır. Bu sınıfı türeterek kendi özel hata türlerimizi tanımlayabiliriz.

`std::exception` sınıfında, hata mesajını döndürmek için `what()` isimli bir `sanal (virtual) fonksiyon` tanımlıdır:

```cpp
virtual const char* what() const throw();
```

Bu fonksiyon, hatayı tanımlayan bir mesaj döndürmek için kullanılır. Biz de kendi hata sınıflarımızda bu fonksiyonu aşırı yükleyerek, her hataya özel mesajlar sağlayabiliriz.

### `GradeTooHighException` ve `GradeTooLowException`

Bu sınıflar, Bureaucrat sınıfına özgü iki hata durumunu temsil eder:
- `GradeTooHighException:` Derece 1’in altına düşerse fırlatılır.
- `GradeTooLowException:` Derece 150’nin üstüne çıkarsa fırlatılır.

Her iki sınıf da `std::exception` sınıfından türetilmiştir ve `what()` fonksiyonunu kendilerine özel hata mesajlarını döndürecek şekilde aşırı yüklemiştir.

### Kodun Parça Parça Açıklaması

**1. Sınıf Tanımları**

```cpp
class GradeTooHighException : public std::exception
{
	public:
		virtual const char* what() const throw();
};
```

- `class GradeTooHighException:`
	- GradeTooHighException adında bir sınıf tanımlanır.
	- Bu sınıf, `std::exception` sınıfından türetilmiştir. Yani, standart bir `exception` gibi davranır.
	- Bu sınıfın yalnızca bir fonksiyonu vardır: `what()`.
- `public:`
	- `what()` : fonksiyonu genel erişime açıktır.
- `virtual const char* what() const throw();` :
    - `virtual`     : virtual burada, what() fonksiyonunun polimorfik (çok biçimli) olmasını sağlar.Yani bir GradeTooHighException nesnesi, bir std::exception pointer veya referansı ile yakalansa bile doğru what() fonksiyonu çağrılır. what() fonksiyonu Eğer what() fonksiyonu virtual olmasaydı, bu durumda std::exception::what() çağrılırdı, .cpp'de tanımlanılan "Grade is too high!" mesajı değil. virtual olduğu için, runtime’da gerçek nesnenin (GradeTooHighException) versiyonu çağrılır ve doğru çalşır.
	- `what()`      : Bu, std::exception sınıfında sanal (virtual) olarak tanımlanmış bir fonksiyondur. Bu yüzden burada override edilmiştir.
	- `const char*` : Fonksiyon bir C tarzı sabit string (const char*) döndürür.
	- `const`       : Bu fonksiyon sınıfın verilerini değiştirmez.
	- `throw()`     : Bu, exception-specification olarak bilinir. Yani bu fonksiyonun hiçbir istisna (exception) fırlatmayacağını belirtir. std::exception::what() fonksiyonunda throw() kullanılarak virtual tanımlanmıştır. O yüzden thorw() kullanmama gibi bir durum olmamalıdır. Aksi halde what() fonksiyonu override edilmez ve normal fonksiyon gibi davranır. Düzgün override edilmezse std::exception tarafından what() fonksiyonu çağrıldığında fonksiyon içerisinde ne yapmaya çalışıyorsam o yapılmaz. (C++11’den itibaren `noexcept` kullanılır, ancak burada C++98 standartları kullanıldığından `throw()` tercih edilmiştir.)

**2. `what()` Fonksiyonunun Uygulaması**

```cpp
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}
```

- `const char* Bureaucrat::GradeTooHighException::what() const throw()` :
  - Bu, `GradeTooHighException` sınıfının `what()` fonksiyonunun gövdesidir.
  - Bu fonksiyon, hata durumunda bir string döndürür: ***"Grade is too high!"***.
  - Bu mesaj, hata oluştuğunda kullanıcıya bilgi verir.

Aynı şekilde, `GradeTooLowException` için de bir `what()` fonksiyonu tanımlanır:

```cpp
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}
```

Bu fonksiyon ***"Grade is too low!"*** mesajını döndürür.

**3. Ne Zaman ve Nasıl Kullanılır?**

Bu özel istisna sınıfları, Bureaucrat sınıfında aşağıdaki durumlarda kullanılır:

- Constructor -> Bureaucrat oluşturulurken derecenin sınırların dışında olup olmadığında:

	```cpp
	Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade)
	{
		if (_grade < 1)
			throw GradeTooHighException(); // Derece çok yüksekse hata fırlatılır
		if (_grade > 150)
			throw GradeTooLowException(); // Derece çok düşükse hata fırlatılır
	}
	```

- Dereceyi Artırma -> Eğer dereceyi artırmaya çalışırken 1’in altına düşerse:

	```cpp
	void Bureaucrat::incrementGrade()
	{
		if (_grade <= 1)
			throw GradeTooHighException(); // Hata fırlatılır
		_grade--;
	}
	```

- Dereceyi Azaltma -> Eğer dereceyi azaltmaya çalışırken 150’nin üstüne çıkarsa:

	```cpp
	void Bureaucrat::decrementGrade()
	{
		if (_grade >= 150)
			throw GradeTooLowException(); // Hata fırlatılır
		_grade++;
	}
	```

### Hataların Yakalanması (Exception Handling)

Bir hata fırlatıldığında, `try-catch` blokları ile bu hataları yakalayabiliriz:

```cpp
try
{
	Bureaucrat b("Alice", 0); // Geçersiz derece (0) hata fırlatır
}
catch (const Bureaucrat::GradeTooHighException& e)
{
	std::cerr << "Exception: " << e.what() << std::endl; // "Grade is too high!"
}
catch (const Bureaucrat::GradeTooLowException& e)
{
	std::cerr << "Exception: " << e.what() << std::endl; // "Grade is too low!"
}
```
