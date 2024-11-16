## CPP Module 04 Notları

- [`virtual` Anahtar Kelimesi](#virtual-anahtar-kelimesi)
	- [Temel Kavramlar](#temel-kavramlar)
	- [Virtual Kullanımı](#virtual-kullanımı)
	- [Virtual Destructor (Sanal Yıkıcılar)](#virtual-destructor-sanal-yıkıcılar)
	- [Pure Virtual (Soyut Fonksiyonlar)](#pure-virtual-soyut-fonksiyonlar)
	- [Virtual Table (vtable) Mekanizması](#virtual-table-vtable-mekanizması)
	- [Virtual’in Avantaj ve Dezavantajları](#virtualin-avantaj-ve-dezavantajları)
- [`Interface`](#interface)
	- [`Interface` Nedir?](#interface-nedir)
	- [`Interface`’in Tanımı ve Örnek Kullanımı](#interfacein-tanımı-ve-örnek-kullanımı)
	- [`Interface`’in Özellikleri](#interfacein-özellikleri)
	- [`Interface` ve `Soyut Sınıf` Farkı](#interface-ve-soyut-sınıf-farkı)
	- [`Interface` ile `Polimorfizm`](#interface-ile-polimorfizm)
	- [Birden Fazla `Interface` ile Çalışma](#birden-fazla-interface-ile-çalışma)
	- [`Interface` Kullanımı için En İyi Uygulamalar](#interface-kullanımı-için-en-i̇yi-uygulamalar)
	- [C++’da `Interface` vs Diğer Diller](#cda-interface-vs-diğer-diller)
- [`Abstract Class`](#abstract-class)
	- [Soyut Sınıfların Tanımı](#soyut-sınıfların-tanımı)
	- [Soyut Sınıf Kullanımı](#soyut-sınıf-kullanımı)
	- [Soyut Sınıfların Özellikleri](#soyut-sınıfların-özellikleri)
	- [Soyut Sınıfların Avantajları](#soyut-sınıfların-avantajları)
	- [`Soyut Sınıf` ile `Arayüz (Interface)` Farkı](#soyut-sınıf-ile-arayüz-interface-farkı)
	- [`Çok Biçimlilik (Polymorphism)` ve `Soyut Sınıflar`](#çok-biçimlilik-polymorphism-ve-soyut-sınıflar)
	- [`Soyut Sınıflar` ve `Miras`](#soyut-sınıflar-ve-miras)
- [Kopyalama İşlemleri : `Deep Copy` ve `Shallow Copy`](#kopyalama-i̇şlemleri--deep-copy-ve-shallow-copy)
	- [`Shallow Copy` (Yüzeysel Kopya)](#shallow-copy-yüzeysel-kopya)
	- [`Deep Copy` (Derin Kopya)](#deep-copy-derin-kopya)
	- [`Shallow Copy` ve `Deep Copy` Karşılaştırması](#shallow-copy-ve-deep-copy-karşılaştırması)
	- [Kopyalama İşlemlerini Kontrol Etmek](#kopyalama-i̇şlemlerini-kontrol-etmek)
	- [C++11 ve Sonrası: `Move Semantics`](#c11-ve-sonrası-move-semantics)
	- [`Shallow Copy` ve `Deep Copy` Seçimi](#shallow-copy-ve-deep-copy-seçimi)
	- [Özet](#özet)

<br></br>

## `virtual` Anahtar Kelimesi

C++’de virtual anahtar kelimesi, **polimorfizm** ve **dinamik bağlama (runtime binding)** sağlamak için kullanılır. Genellikle türemiş sınıfların türediği temel sınıfların işlevlerini yeniden tanımlamasını sağlamak için kullanılır. Bu özellik, özellikle bir sınıf hiyerarşisi içinde davranışların türetilmiş sınıflar tarafından özelleştirilmesini mümkün kılar. Aşağıda detaylı bir açıklama bulabilirsiniz:

### Temel Kavramlar

- **Statik Bağlama (Compile-time Binding) :**
Normal bir üye fonksiyonu çağrıldığında, fonksiyonun hangi sınıfa ait olduğu derleme zamanında belirlenir.

- **Dinamik Bağlama (Runtime Binding) :**
`virtual` anahtar kelimesi kullanıldığında, çağrılan fonksiyonun hangi sınıfa ait olduğu çalışma zamanında belirlenir. Bu, bir `pointer` ya da `referans` üzerinden çağrı yapıldığında kullanılır.

### Virtual Kullanımı

`virtual` anahtar kelimesi, genellikle **temel sınıflarda (base class)** üye fonksiyonların başına yazılır. Bu, **türemiş sınıfların (derived class)** aynı fonksiyonu yeniden tanımlayabileceğini belirtir.

Örnek:
```cpp
	#include <iostream>

	// Temel sınıf
	class Base
	{
		public:
			virtual void display() const	// virtual ile işaretlendi
			{
				std::cout << "Base sınıfı" << std::endl;
			}
			virtual ~Base() {}	// Sanal bir yıkıcı (memory leaks önlemek için iyi bir pratik)
	};

	// Türemiş sınıf
	class Derived : public Base
	{
		public:
			void display() const // c++11'de override kelimesi ile kullanılır ama c++98 standartlarında kullanılmadan gerçekleşir.
			{
				std::cout << "Derived sınıfı" << std::endl;
			}
	};

	int main()
	{
		Base* basePtr;
		Derived derivedObj;

		basePtr = &derivedObj;

		// Dinamik bağlama, derived sınıfın display() fonksiyonu çağrılır
		basePtr->display();

		return 0;
	}
```

Çıktı:
```
Derived sınıfı
```

Burada `display()` fonksiyonu `virtual` olduğundan, çalışma zamanında hangi fonksiyonun çağrılacağına karar verilmiştir.

### Virtual Destructor (Sanal Yıkıcılar)

Eğer bir temel sınıfın yıkıcı fonksiyonu `virtual` olarak işaretlenmemişse, türemiş sınıfın dinamik olarak oluşturulan nesneleri tam olarak yok edilemez ve **bellek sızıntılarına (memory leaks)** neden olabilir.

Örnek:
```cpp
#include <iostream>
using namespace std;

class Base {
public:
    ~Base() { cout << "Base yıkıcı" << endl; }
};

class Derived : public Base {
public:
    ~Derived() { cout << "Derived yıkıcı" << endl; }
};

int main() {
    Base* basePtr = new Derived();
    delete basePtr; // Sadece Base'in yıkıcısı çağrılır, Derived çağrılmaz
    return 0;
}
```

Çıktı:
```
Base yıkıcı
```

Yıkıcıyı `virtual` yaparak bunu düzeltebilirsiniz:

```cpp
class Base
{
	public:
		virtual ~Base() { std::cout << "Base yıkıcı" << std::endl; }
};
```

Çıktı:
```
Derived yıkıcı
Base yıkıcı
```

### Pure Virtual (Soyut Fonksiyonlar)

Bir fonksiyonu `saf sanal fonksiyon` yapmak için `= 0` ile işaretlenir. Bu, sınıfın **`soyut sınıf (abstract class)`** olmasını sağlar ve bu sınıftan ***nesne oluşturulamaz***.

Örnek:
```cpp
#include <iostream>

class Shape
{
	public:
		virtual void draw() const = 0; // Pure virtual tanımlanması
		virtual ~Shape() {}
};

class Circle : public Shape
{
	public:
		void draw() const
		{
			std::cout << "Daire çiziliyor" << std::endl;
		}
};

int main()
{
	Shape* shape = new Circle();

	shape->draw(); // Circle'ın draw() fonksiyonu çağrılır

	delete shape;

	return 0;
}
```

Çıktı:
```
Daire çiziliyor
```

### Virtual Table (vtable) Mekanizması

C++’de sanal fonksiyonlar, bir `vtable (sanal tablo)` ve `vptr (sanal tablo işaretçisi)` kullanılarak uygulanır:
- Her sınıf için bir `vtable` oluşturulur ve sanal fonksiyonların adreslerini tutar.
- Nesne oluşturulduğunda, sınıfın `vtable` işaretçisi olan `vptr` ayarlanır.
- Bir sanal fonksiyon çağrıldığında, `vtable`’daki uygun fonksiyon çağrılır.

### Virtual’in Avantaj ve Dezavantajları

- **Avantajlar :**
  - Polimorfizm ve dinamik bağlama ile esneklik sağlar.
  - Bir nesneye temel sınıf pointer/referansı ile erişirken doğru türemiş sınıf fonksiyonu çağrılır.
- **Dezavantajlar :**
  - Performans maliyeti: Her sanal fonksiyon çağrısı, vtable üzerinden bir dolaylı çağrı gerektirir.
  - Hafıza maliyeti: Vtable ve vptr ek alan kullanır.

<br></br>

## `Interface`

C++’da `interface` terimi, bir sınıfın yalnızca bir arayüz olarak davranması anlamına gelir. Bu, **bir sınıfın sadece `saf sanal fonksiyonlar (pure virtual functions)` içerdiği ve genellikle başka herhangi bir işlevsellik sağlamadığı durumdur**. C++ dilinde `interface` için özel bir anahtar kelime bulunmaz, ancak bir sınıfı tüm üyeleri saf sanal olacak şekilde tasarlayarak bir interface oluşturabiliriz.

### `Interface` Nedir?

Bir `interface`, bir sınıfın diğer sınıflar tarafından uygulanması gereken işlevlerin bir tanımını (sözleşmesini) içerir. `Interface`, bir sınıfın ne yapabileceğini tanımlar ama nasıl yapacağını değil.

C++’da bir `interface` şu şekilde ifade edilir:
- Sadece pure `virtual` fonksiyonlardan oluşur.
- Genellikle veri üyeleri içermez (istisnalar olabilir ama nadiren kullanılır).
- Doğrudan nesne oluşturulamaz.
- Bir sınıf birden fazla `interface`’i implemente edebilir (çoklu kalıtım desteği).

### `Interface`’in Tanımı ve Örnek Kullanımı

Örnek:
```cpp
#include <iostream>

// Interface tanımı
class IShape
{
	public:
		virtual void draw() const = 0;	// Saf sanal fonksiyon
		virtual double area() const = 0;

		virtual ~IShape() {}	// Sanal yıkıcı
};

// Bir interface'i uygulayan sınıflar
class Circle : public IShape
{
	private:
		double radius;

	public:
		Circle(double r) : radius(r) {}

		void draw() const
		{
			std::cout << "Daire çiziliyor." << std::endl;
		}

		double area() const
		{
			return 3.14 * radius * radius;
		}
};

class Rectangle : public IShape
{
	private:
		double width, height;

	public:
		Rectangle(double w, double h) : width(w), height(h) {}

		void draw() const
		{
			std::cout << "Dikdörtgen çiziliyor." << std::endl;
		}

		double area() const
		{
			return width * height;
		}
};

int main()
{
	IShape* shapes[2];  // Interface pointer'ı

	shapes[0] = new Circle(5.0);          // Circle nesnesi
	shapes[1] = new Rectangle(4.0, 6.0);  // Rectangle nesnesi

	for (int i = 0; i < 2; ++i)
	{
		shapes[i]->draw();
		std::cout << "Alan: " << shapes[i]->area() << std::endl;
		delete shapes[i];
	}

	return 0;
}
```

Çıktı:
```
Daire çiziliyor.
Alan: 78.5
Dikdörtgen çiziliyor.
Alan: 24
```

### `Interface`’in Özellikleri

- ***Saf Sanal Fonksiyonlar:*** Bir `interface` yalnızca `saf sanal fonksiyonlardan` oluşur. Bu fonksiyonlar `= 0` ile işaretlenir ve türetilmiş sınıflar tarafından uygulanmalıdır.
- ***Sanal Yıkıcı (Virtual Destructor):*** `Interface`’ler genellikle bir `sanal yıkıcı` içerir. Bu, bir `interface pointer`’ı aracılığıyla türetilmiş sınıf nesnesi silindiğinde belleğin doğru bir şekilde yönetilmesini sağlar.
- ***Doğrudan Nesne Oluşturulamaz:*** `Soyut sınıflar` gibi, `interface`’lerin doğrudan bir nesnesi yaratılamaz.
- ***Çoklu Kalıtım Desteği:*** C++‘da bir sınıf birden fazla `interface`’i implemente edebilir.

### `Interface` ve `Soyut Sınıf` Farkı

C++‘da bir `interface`, aslında tamamen `saf sanal fonksiyonlardan` oluşan bir `soyut sınıftır`. Ancak, `interface`’ler ile `soyut sınıflar` arasında bazı tasarım farklılıkları vardır:

| Özellik       | Interface                                   | Soyut Sınıf                                            |
|---------------|---------------------------------------------|--------------------------------------------------------|
| Fonksiyonlar  | Sadece saf sanal fonksiyonlardan oluşur.    | Hem saf sanal hem de normal fonksiyonlar içerebilir.   |
| Veri Üyeleri  | Genellikle veri üyesi içermez.              | Veri üyeleri içerebilir.                               |
| Amaç          | Yalnızca arayüz tanımlamak için kullanılır. | Ortak davranışları paylaşmak için kullanılabilir.      |
| Çoklu Kalıtım | Çoklu kalıtım için uygundur.                | Çoklu kalıtım kullanılabilir ama dikkatli olunmalıdır. |

### `Interface` ile `Polimorfizm`

`Interface`’ler, `polimorfizm` sağlamak için güçlü bir araçtır. Bir `interface pointer`’ı veya `referansı` üzerinden türetilmiş sınıfların davranışlarına erişilebilir.

Örnek: Bu örnekte, `printShapeInfo` fonksiyonu herhangi bir `IShape` türevi ile çalışabilir.
```cpp
void printShapeInfo(const IShape& shape)
{
	shape.draw();
	std::cout << "Alan: " << shape.area() << std::endl;
}

int main()
{
	Circle c(5.0);
	Rectangle r(4.0, 6.0);

	printShapeInfo(c);
	printShapeInfo(r);

	return 0;
}
```

Çıktı:
```
Daire çiziliyor.
Alan: 78.5
Dikdörtgen çiziliyor.
Alan: 24
```

### Birden Fazla `Interface` ile Çalışma

C++‘da bir sınıf birden fazla `interface`’den türeyebilir. Bu, daha modüler ve esnek tasarımlar sağlar.

Örnek:
```cpp
class IDrawable
{
	public:
		virtual void draw() const = 0;
		virtual ~IDrawable() {}
};

class IScalable
{
	public:
		virtual void scale(double factor) = 0;
		virtual ~IScalable() {}
};

class Circle : public IDrawable, public IScalable
{
	private:
		double radius;

	public:
		Circle(double r) : radius(r) {}

		void draw() const
		{
			std::cout << "Daire çiziliyor." << std::endl;
		}

		void scale(double factor)
		{
			radius *= factor;
			std::cout << "Daire ölçeklendi: Yeni yarıçap = " << radius << std::endl;
		}
};
```

### `Interface` Kullanımı için En İyi Uygulamalar

- ***Minimal Tutun:*** `Interface`’ler yalnızca gerekli işlevleri tanımlamalıdır. Gereksiz veri üyeleri veya fonksiyonlar eklemekten kaçının.
- ***Sanal Yıkıcı Ekleyin:*** Bellek yönetiminde sorun yaşamamak için bir `interface`’e ***her zaman*** `sanal bir yıkıcı` ekleyin.
- ***Adlandırma Kuralları:*** `Interface`’leri tanımlarken genellikle `I` ile başlayan bir adlandırma kullanılır (`IShape`, `IDrawable` gibi).
- ***Modülerliği Artırın:*** Kodun modülerliğini ve test edilebilirliğini artırmak için `interface`’leri kullanın.

### C++’da `Interface` vs Diğer Diller

C++‘da `interface`’ler `soyut sınıflar` kullanılarak gerçekleştirilirken, diğer diller (örneğin Java ve C#) doğrudan `interface` anahtar kelimesi kullanır. Ancak temel kavramlar aynıdır.

<br></br>

## `Abstract Class`

C++’de `abstract class (soyut sınıf)`, yalnızca diğer sınıfların türetilmesi için tasarlanan ve doğrudan nesne oluşturulamayan bir sınıftır. `Soyut sınıflar` genellikle polimorfizm ve soyutlama sağlamak amacıyla kullanılır.

**!!!  Bir sınıfı soyut yapmak için en az bir `pure virtual (saf sanal)` fonksiyona sahip olması gerekir  !!!**

### Soyut Sınıfların Tanımı

- `Pure Virtual Function (Saf Sanal Fonksiyon):` Bir sınıfın fonksiyonunun tanımını değil, yalnızca prototipini içeren ve `= 0` ile işaretlenen fonksiyonlardır.
- `Abstract Class:` En az bir saf sanal fonksiyon içeren bir sınıf, soyut sınıf olur.

### Soyut Sınıf Kullanımı

Bir soyut sınıf, temel bir sınıf olarak tanımlanır ve ortak davranışları belirtir. Türetilmiş sınıflar bu davranışları override ederek/geçersiz kılarak kendi özel işlevlerini sağlar. Ancak `override` özelliği C++98 standartlarında mevcut değildir. C++11 ile birlikte bu anahtar kelime C++ diline kazandırılmıştır. C++98'de `override` ifadesini kullanmadan geçersiz kılma işlemini gerçekleştirebiliyoruz.

Örnek:
```cpp
#include <iostream>
using namespace std;

class Shape
{
	public:
		// Saf sanal fonksiyonlar
		virtual void draw() const = 0;
		virtual double area() const = 0;

		virtual ~Shape() {} // Sanal yıkıcı
};

class Circle : public Shape
{
	private:
		double radius;

	public:
		Circle(double r) : radius(r) {}

		void draw() const
		{
			std::cout << "Daire çiziliyor." << std::endl;
		}

		double area() const
		{
			return 3.14 * radius * radius;
		}
};

class Rectangle : public Shape
{
	private:
		double width, height;

	public:
		Rectangle(double w, double h) : width(w), height(h) {}

		void draw() const
		{
			std::cout << "Dikdörtgen çiziliyor." << std::endl;
		}

		double area() const
		{
			return width * height;
		}
};

int main()
{
	Shape* shapes[2];
	shapes[0] = new Circle(5.0);
	shapes[1] = new Rectangle(4.0, 6.0);

	for (int i = 0; i < 2; ++i)
	{
		shapes[i]->draw();
		cout << "Alan: " << shapes[i]->area() << endl;
		delete shapes[i];
	}

	return 0;
}
```

Çıktı:
```
Daire çiziliyor.
Alan: 78.5
Dikdörtgen çiziliyor.
Alan: 24
```

### Soyut Sınıfların Özellikleri

- ***Nesne Oluşturulamaz:***
  - `Soyut sınıfın` doğrudan nesnesi yaratılamaz:
  - Örnek:
	```cpp
	Shape shape; // Hata: Soyut sınıfın nesnesi yaratılamaz
	```
- ***Türetilmiş Sınıflar `Override` Etmelidir:*** Eğer `türetilmiş sınıflar`, `saf sanal` fonksiyonları `override` etmezse, türetilmiş sınıf da `soyut` olur.
- ***Birden Fazla Saf Sanal Fonksiyon:*** Bir sınıf **birden fazla** saf sanal fonksiyon içerebilir ve türetilmiş sınıflar bunları `override` etmelidir.
- ***Partial Implementation (Kısmi Uygulama):*** `Soyut sınıf`, saf sanal olmayan normal üye fonksiyonlar içerebilir. Bu, türetilmiş sınıflar için ortak kod sağlar.

Örnek:
```cpp
class Base
{
	public:
		virtual void pureVirtual() const = 0; // Saf sanal

		void normalFunction() const	// Normal üye fonksiyonu
		{
			std::cout << "Bu bir normal üye fonksiyon." << std::endl;
		}
};
```

### Soyut Sınıfların Avantajları

- ***Ortak Davranışların Paylaşılması:*** `Soyut sınıflar`, türetilmiş sınıflar arasında ortak davranışları belirleyebilir.
- ***`Polimorfizm`:*** Bir temel sınıf `pointer` veya `referansı` üzerinden `türetilmiş sınıfın` doğru fonksiyonlarının çağrılmasını sağlar.
- ***Kodun Genelleştirilmesi:*** Aynı arayüzü paylaşan farklı türden sınıflarla çalışmaya olanak tanır.

Örnek: Bu fonksiyon, herhangi bir `Shape` türevinin davranışını işleyebilir.
```cpp
void	displayShapeInfo(const Shape& shape)
{
	shape.draw();
	std::cout << "Alan: " << shape.area() << std::endl;
}
```

### `Soyut Sınıf` ile `Arayüz (Interface)` Farkı

C++’da saf sanal fonksiyonları olan bir soyut sınıf, bir arayüz gibi davranabilir. Ancak, C++’da `saf bir arayüz` için genellikle sadece `saf sanal fonksiyonlar` bulunur ve **veri üyeleri olmaz**.

Arayüz Örneği:
```cpp
class Interface
{
	public:
		virtual void function1() const = 0;
		virtual void function2() const = 0;

		virtual ~Interface() {}
};
```

### `Çok Biçimlilik (Polymorphism)` ve `Soyut Sınıflar`

Soyut sınıflar, çok biçimlilik için temel bir yapı taşıdır. Örneğin, bir temel sınıf pointer’ı veya referansı üzerinden farklı türetilmiş sınıf davranışlarını çağırabilirsiniz:

Örnek:
```cpp
Shape* s = new Circle(5.0);
s->draw(); // Circle'ın draw() fonksiyonu çağrılır
delete s;
```

### `Soyut Sınıflar` ve `Miras`

Eğer türetilmiş sınıf saf sanal bir fonksiyonu `override` etmezse, türetilmiş sınıf da soyut olmaya devam eder:

```cpp
class Derived : public Shape
{
	// draw() ve area() fonksiyonları override edilmez
	// Bu yüzden Derived da soyut bir sınıf
};
```

<br></br>

## Kopyalama İşlemleri : `Deep Copy` ve `Shallow Copy`

C++’da `deep copy` ve `shallow copy`, bir nesnenin başka bir nesneye kopyalanması sırasında kullanılan iki farklı yaklaşımı ifade eder. Bu kavramlar özellikle dinamik bellek yönetimiyle çalışırken önem kazanır.

### `Shallow Copy` (Yüzeysel Kopya)

#### Tanım

`Shallow copy`, bir nesnenin kopyalanması sırasında yalnızca nesnenin bellekteki adreslerinin kopyalanması anlamına gelir. Bu durumda, orijinal nesne ve kopya nesne aynı dinamik belleği paylaşır.

#### Özellikler
- Sadece veri üyelerinin adresleri kopyalanır.
- İki nesne de aynı kaynağı (bellek alanını) işaret eder.
- Eğer bir nesne üzerinde değişiklik yapılırsa, diğer nesne de etkilenir.
- Bellek yönetimiyle ilgili çift serbest bırakma (double free) gibi sorunlara yol açabilir.

Örnek:
```cpp
#include <iostream>

class Example
{
	public:
		int* ptr;

		Example(int value)
		{
			ptr = new int(value);
		}

		// Shallow copy (default copy constructor)
		Example(const Example& other)
		{
			ptr = other.ptr;
		}

		void print() const
		{
			std::cout << "Value: " << *ptr << std::endl;
		}

		~Example()
		{
			delete ptr;  // Belleği serbest bırak
		}
};

int main()
{
	Example obj1(42);
	Example obj2 = obj1; // Shallow copy gerçekleşir

	obj1.print();
	obj2.print();

	*obj1.ptr = 100; // Bir nesne üzerinde değişiklik yap
	obj2.print();    // Diğer nesne de etkilenir

	return 0;
}
```

Çıktı:
```
Value: 42
Value: 42
Value: 100
```

***Sorun:***
- `obj1` ve `obj2` aynı belleği paylaşır. Program sonlandığında `~Example()` çağrıldığında aynı bellek iki kez serbest bırakılmaya çalışılır, bu da çift serbest bırakma hatasına neden olur.

### `Deep Copy` (Derin Kopya)

#### Tanım

`Deep copy`, bir nesnenin kopyalanması sırasında dinamik bellekteki verilerin tamamen kopyalanması anlamına gelir. Her nesne, kendi bağımsız belleğini kullanır.

#### Özellikler

- Veri üyeleri için yeni bir bellek alanı ayrılır ve veriler bu alana kopyalanır.
- Orijinal nesne ve kopya nesne birbirinden bağımsızdır.
- Bellek yönetimi sorunlarını engeller.
- Daha güvenli ama performans açısından daha maliyetli olabilir.

Örnek:
```cpp
#include <iostream>

class Example
{
	public:
		int*	ptr;

		Example(int value)
		{
			ptr = new int(value);
		}

		// Deep copy constructor
		Example(const Example& other)
		{
			ptr = new int(*other.ptr); // Yeni bellek ayrılır ve değer kopyalanır
		}

		void print() const
		{
			std::cout << "Value: " << *ptr << std::endl;
		}

		~Example()
		{
			delete ptr;  // Belleği serbest bırak
		}
};

int main()
{
	Example obj1(42);
	Example obj2 = obj1; // Deep copy gerçekleşir

	obj1.print();
	obj2.print();

	*obj1.ptr = 100;  // Bir nesne üzerinde değişiklik yap
	obj2.print();     // Diğer nesne etkilenmez

	return 0;
}
```

Çıktı:
```
Value: 42
Value: 42
Value: 42
```

***Avantaj:***
- `obj1` ve `obj2` bağımsızdır. `obj1`’de yapılan değişiklikler `obj2`’yi etkilemez.

### `Shallow Copy` ve `Deep Copy` Karşılaştırması

| Özellik          | Shallow Copy                                       |  Deep Copy                                       |
|------------------|----------------------------------------------------|--------------------------------------------------|
| Bellek Kullanımı | Sadece adres kopyalanır, daha az bellek kullanır.  | Yeni bellek ayrılır, daha fazla bellek kullanır. |
| Bağımsızlık      | Nesneler aynı belleği paylaşır, bağımsız değildir. | Nesneler bağımsızdır, biri diğerini etkilemez.   |
| Performans       | Daha hızlıdır.                                     | Daha yavaştır (kopyalama maliyeti nedeniyle).    |
| Riskler          | Çift serbest bırakma veya veri çakışması olabilir. | Shallow Copy'deki riskler yoktur.                |

### Kopyalama İşlemlerini Kontrol Etmek

- `Kopya Yapıcı (Copy Constructor) :` C++’da bir sınıf, kopyalama yaparken `kopya yapıcıyı (copy constructor)` kullanır. Kendi kopya yapıcınızı tanımlayarak `shallow copy` veya `deep copy` işlemi gerçekleştirebilirsiniz.

- `Kopya Atama Operatörü (Copy Assignment Operator) :` Bir nesneye başka bir nesne atandığında `kopya atama operatörü` kullanılır. `Deep copy` işlemi yapmak için bunu da özelleştirebilirsiniz.

Örnek:
```cpp
Example& operator=(const Example& other)
{
	if (this != &other)   // Kendine atamayı engelle
	{
		delete ptr;   // Eski belleği serbest bırak
		ptr = new int(*other.ptr);   // Yeni bellek ayır ve kopyala
	}
	return (*this);
}
```

### C++11 ve Sonrası: `Move Semantics`

C++11 ile birlikte `move semantics (taşıma işlemleri)` geldi. `Deep copy`’nin maliyetli olduğu durumlarda `taşıma semantiği` kullanılarak belleği yeniden tahsis etmek yerine sahiplik devri yapılabilir.

Örnek:
```cpp
Example(Example&& other) noexcept
{
	ptr = other.ptr;      // Bellek sahipliğini devret
	other.ptr = nullptr;  // Diğer nesneyi sıfırla
}
```

### `Shallow Copy` ve `Deep Copy` Seçimi

- `Shallow Copy` Kullanımı:
  - Bellek yönetimi önemli değilse.
  - Nesneler arasında veri paylaşımı gerekiyorsa.
  - Veri çakışma riskini önceden biliyorsanız.
- `Deep Copy` Kullanımı:
  - Nesnelerin bağımsız çalışması gerekiyorsa.
  - Dinamik bellek kullanılıyorsa.
  - Bellek yönetimi hatalarından kaçınmak istiyorsanız.

### Özet

- `Shallow Copy:` Bellek adreslerini kopyalar, hızlı ama risklidir.
- `Deep Copy:` Veriyi kopyalar, güvenli ama maliyetlidir.
- Dinamik bellekle çalışıyorsanız, genellikle deep copy tercih edilir. Bellek yönetimini doğru yapmak için hem kopya yapıcıyı hem de kopya atama operatörünü doğru bir şekilde tanımlamalısınız.

<br></br>
