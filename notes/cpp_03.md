## Polimorfizm (Çok Biçimlilik)

**Polimorfizm** (çok biçimlilik), nesne yönelimli programlamanın (OOP) temel prensiplerinden biridir ve **aynı işlemi farklı şekillerde gerçekleştirebilme** yeteneğini ifade eder. C++ dilinde polimorfizm, bir sınıfın birden fazla farklı biçimde davranabilmesi anlamına gelir. Bu, özellikle kalıtım (inheritance) ve işlev aşırı yükleme (overloading) gibi kavramlarla ilişkili olarak kullanılır.

### Polimorfizmin Türleri

C++ dilinde polimorfizm iki ana türe ayrılır:
1. **Derleme Zamanı Polimorfizmi** (Compile-Time Polymorphism)
2. **Çalışma Zamanı Polimorfizmi** (Run-Time Polymorphism)

#### 1. Derleme Zamanı Polimorfizmi (Compile-Time Polymorphism)
Derleme zamanında karar verilen polimorfizm, **işlev aşırı yükleme** (function overloading), **operatör aşırı yükleme** (operator overloading), ve **şablonlar** (templates) ile gerçekleştirilir. Burada, bir fonksiyonun veya operatörün aynı isimle birden fazla tanımlaması yapılır ve derleyici, hangi sürümün çağrılacağını derleme zamanında belirler.

##### İşlev Aşırı Yükleme (Function Overloading)
İşlev aşırı yükleme, aynı isimde birden fazla fonksiyonun farklı parametre listeleri ile tanımlanmasıdır. Derleyici, çağrı sırasında parametre türlerine bakarak hangi fonksiyonun çağrılacağına karar verir.

Örneğin:

```cpp
#include <iostream>

class Calculator
{
	public:
		int add(int a, int b) { return a + b; }
		double add(double a, double b) { return a + b; }
};

int main()
{
	Calculator calc;

	std::cout << calc.add(5, 3) << std::endl;       // int sürümü
	std::cout << calc.add(5.5, 3.3) << std::endl;   // double sürümü

	return 0;
}
```

Burada `add` fonksiyonu iki farklı parametre türüyle tanımlanmış ve çağrı sırasında parametrelerin türüne göre uygun sürüm çağrılmaktadır.

##### Operatör Aşırı Yükleme (Operator Overloading)
Operatör aşırı yükleme, C++'taki operatörlerin özel anlamlar kazanması için yeniden tanımlanmasıdır. Bu sayede kendi sınıfınız için operatörlerin davranışını değiştirebilirsiniz.

Örneğin:

```cpp
#include <iostream>

class Complex
{
	public:
		int real, imag;

		Complex(int r = 0, int i = 0) : real(r), imag(i) {}

		Complex operator+(const Complex& other) { return Complex(real + other.real, imag + other.imag); }
};

int main()
{
	Complex c1(3, 4), c2(1, 2);

	Complex c3 = c1 + c2;  // '+' operatörü aşırı yüklendi
	std::cout << "Real: " << c3.real << ", Imag: " << c3.imag << std::endl;

	return 0;
}
```

Bu örnekte `+` operatörü aşırı yüklenmiş ve `Complex` sınıfı için toplama işlemi özelleştirilmiştir.

##### Şablonlar (Templates)
Şablonlar, derleme zamanında veri türüne bağlı olarak farklı işlemler gerçekleştiren yapılar sağlar. İşlev ve sınıf şablonları, kodun farklı veri türleriyle tekrar yazılmasını önleyerek polimorfizmi genişletir.

Örneğin:

```cpp
#include <iostream>

template <typename T>
T add(T a, T b)
{
	return (a + b);
}

int main()
{
	std::cout << add(5, 3) << std::endl;       // int sürümü
	std::cout << add(5.5, 3.3) << std::endl;   // double sürümü

	return 0;
}
```

Burada `add` fonksiyonu, hem `int` hem de `double` türleriyle çalışabilecek şekilde şablonlanmıştır.

#### 2. Çalışma Zamanı Polimorfizmi (Run-Time Polymorphism)
Çalışma zamanı polimorfizmi, **sanallık** (virtual) mekanizmasıyla gerçekleştirilir. Temel sınıfların fonksiyonları türetilen sınıflarda geçersiz kılınarak (override) farklı davranışlar sergilenebilir. Bu tür polimorfizmde hangi fonksiyonun çağrılacağı çalışma zamanında (runtime) belirlenir.

##### Sanal Fonksiyonlar (Virtual Functions)
Sanal fonksiyonlar, temel sınıfta tanımlanan ve türetilen sınıflarda farklı biçimde uygulanabilen fonksiyonlardır. Bir temel sınıfın pointer veya referansı üzerinden türetilen sınıfların fonksiyonları çağrılabilir.

Örneğin:

```cpp
#include <iostream>

class Animal
{
	public:
		virtual void sound()
		{
			std::cout << "Animal makes a sound" << std::endl;
		}
};

class Dog : public Animal
{
	public:
		void sound() override
		{
			std::cout << "Dog barks" << std::endl;
		}
};

class Cat : public Animal
{
	public:
		void sound() override
		{
			std::cout << "Cat meows" << std::endl;
		}
};

int main()
{
	Animal* animal1 = new Dog();
	Animal* animal2 = new Cat();

	animal1->sound();  // Dog barks
	animal2->sound();  // Cat meows

	delete animal1;
	delete animal2;

	return 0;
}
```

Bu örnekte, `sound` fonksiyonu `Animal` sınıfında sanal olarak tanımlanmıştır ve `Dog` ve `Cat` sınıflarında bu fonksiyon farklı biçimlerde uygulanmıştır. Polimorfizm sayesinde, `Animal*` türündeki bir pointer üzerinden doğru fonksiyon çağrılmaktadır.

##### Saf Sanal Fonksiyonlar ve Soyut Sınıflar
Eğer bir fonksiyonun tüm türetilen sınıflarda yeniden uygulanması gerekiyorsa, bu fonksiyon **saf sanal fonksiyon** (pure virtual function) olarak tanımlanır. Bu tür fonksiyonlar, `= 0` ile gösterilir ve sınıf **soyut sınıf** (abstract class) haline gelir.

Örneğin:

```cpp
#include <iostream>

class Shape
{
public:
    virtual void draw() = 0;  // Saf sanal fonksiyon
};

class Circle : public Shape
{
	public:
		void draw() override
		{
			std::cout << "Drawing a circle" << std::endl;
		}
};

class Rectangle : public Shape
{
	public:
		void draw() override
		{
			std::cout << "Drawing a rectangle" << std::endl;
		}
};

int main()
{
	Shape* shape1 = new Circle();
	Shape* shape2 = new Rectangle();

	shape1->draw();  // Drawing a circle
	shape2->draw();  // Drawing a rectangle

	delete shape1;
	delete shape2;

	return 0;
}
```

Bu örnekte `Shape` sınıfı soyut bir sınıf olup, `draw` fonksiyonu tüm türetilen sınıflarda uygulanmak zorundadır.

### Polimorfizmin Avantajları
- **Kodun genişletilebilirliğini artırır:** Temel sınıflara dayalı bir kod yazdığınızda, türetilen sınıfların daha sonra ekleneceğini düşünerek daha esnek yapılar oluşturabilirsiniz.
- **Bakım kolaylığı sağlar:** Ortak bir arayüzle çalışarak sınıfları bağımsız olarak geliştirebilir ve genişletebilirsiniz.
- **Dinamik yapıların yönetimini kolaylaştırır:** Özellikle büyük projelerde, nesneleri dinamik olarak yönetmek ve farklı davranışları tek bir arayüzle gerçekleştirmek kolaylaşır.

<br></br>

## Inheritance (Kalıtım)

C++ dilinde **inheritance** (kalıtım), bir sınıfın (class) başka bir sınıftan özelliklerini ve davranışlarını devralmasını sağlayan bir **nesne yönelimli programlama** (OOP) kavramıdır. Bu sayede bir sınıf, başka bir sınıfın üyelerini (veri üyeleri ve üye fonksiyonlar) kullanabilir ve genişletebilir. Kalıtım, kodun yeniden kullanılabilirliğini artırır, hiyerarşik sınıf yapıları kurar ve nesne yönelimli programlamanın temel taşlarından biri olan **polimorfizm**'in (çok biçimlilik) temelini oluşturur.

### Kalıtımın Amacı
Kalıtımın amacı, yeni sınıflar türetirken mevcut sınıfların özelliklerini tekrar yazmak zorunda kalmadan kullanmaktır. Örneğin, bir "Hayvan" sınıfı temel özelliklere sahipse, bir "Kedi" sınıfı "Hayvan" sınıfından türetilerek hem genel hayvan özelliklerine sahip olabilir hem de kediye özgü özellikler ekleyebilir.

### Kalıtımın Faydaları
1. **Kodun Yeniden Kullanılabilirliği:** Aynı işlevselliği birçok sınıfta tekrar yazmak yerine, bir kere yazılmış olan kodu farklı sınıflarda tekrar kullanabilirsiniz.
2. **Bakımı Kolaylaştırır:** Kodun merkezi bir sınıfta tutulması, bakımı ve güncellemeyi kolaylaştırır. Örneğin, temel sınıfta bir değişiklik yapıldığında, bu değişiklik türetilen sınıflar tarafından da kullanılabilir.
3. **Genişletilebilirlik:** Mevcut sınıfların üzerine yeni özellikler ve davranışlar eklenebilir.
4. **Polimorfizm:** Türeyen sınıflar, taban sınıfın yerine kullanılabilir ve dinamik bağlama (runtime polymorphism) sayesinde esnek ve genişletilebilir programlar yazılabilir.

### Kalıtımın Türleri
C++ dilinde birkaç farklı kalıtım türü bulunur:

1. **Tekil Kalıtım (Single Inheritance):**
   Bir sınıf, sadece bir sınıftan türetilir. Örneğin:

	```cpp
	class Base
	{
		public:
			void show()
			{
				std::cout << "Base class" << std::endl;
			}
	};

	class Derived : public Base
	{
		public:
			void display()
			{
				std::cout << "Derived class" << std::endl;
			}
	};
	```

   Burada, `Derived` sınıfı `Base` sınıfından türemiştir ve `Base` sınıfındaki `show()` fonksiyonuna erişebilir.

2. **Çoklu Kalıtım (Multiple Inheritance):**
   Bir sınıf, birden fazla sınıftan özellik devralabilir. Örneğin:

	```cpp
	class Base1
	{
		public:
			void show()
			{
				std::cout << "Base1 class" << std::endl;
			}
	};

	class Base2
	{
		public:
			void display()
			{
				std::cout << "Base2 class" << std::endl;
			}
	};

	class Derived : public Base1, public Base2
	{
		public:
			void print()
			{
				std::cout << "Derived class" << std::endl;
			}
	};
	```

   Burada `Derived` sınıfı, hem `Base1` hem de `Base2` sınıflarının fonksiyonlarını miras almıştır.

3. **Hiyerarşik Kalıtım (Hierarchical Inheritance):**
   Bir sınıfın birden fazla sınıf tarafından türetilmesi durumudur. Örneğin:

	```cpp
	class Base
	{
		public:
			void show()
			{
				std::cout << "Base class" << std::endl;
			}
	};

	class Derived1 : public Base {
	};

	class Derived2 : public Base {
	};
	```

   Burada hem `Derived1` hem de `Derived2` sınıfları, `Base` sınıfından türemiştir.

4. **Çok Seviyeli Kalıtım (Multilevel Inheritance):**
   Bir sınıf başka bir sınıftan türetilir, ve bu sınıf da başka bir sınıftan türetilir. Örneğin:

	```cpp
	class Base
	{
		public:
			void show()
			{
				std::cout << "Base class" << std::endl;
			}
	};

	class Derived1 : public Base
	{
		public:
			void display()
			{
				std::cout << "Derived1 class" << std::endl;
			}
	};

	class Derived2 : public Derived1
	{
		public:
			void print()
			{
				std::cout << "Derived2 class" << std::endl;
			}
	};
	```

   Burada `Derived2` sınıfı, `Derived1`'den, `Derived1` de `Base` sınıfından türemiştir.

5. **Hibrit Kalıtım (Hybrid Inheritance):**
   Kalıtımın birden fazla türünün birlikte kullanılmasıyla oluşan bir kalıtım şeklidir. Çoklu ve hiyerarşik kalıtımların bir karışımı olabilir. Bu tür kalıtımda **diamond problem** denilen bir sorunla karşılaşabilirsiniz. Örneğin:

	```cpp
	class Base
	{
		public:
			void show()
			{
				std::cout << "Base class" << std::endl;
			}
	};

	class Derived1 : public Base {
	};

	class Derived2 : public Base {
	};

	class Derived3 : public Derived1, public Derived2 {
	};
	```

   Burada `Derived3` sınıfı, `Derived1` ve `Derived2` sınıflarından türemekte, fakat her iki sınıf da aynı `Base` sınıfından türediği için `Base` sınıfının iki farklı kopyası oluşmaktadır. Bu problemi çözmek için **virtual inheritance** (sanal kalıtım) kullanılabilir.

### Sanal Kalıtım (Virtual Inheritance)
**Virtual inheritance**, çoklu kalıtımda bir sınıfın bir taban sınıfın birden fazla kopyasını almasını önlemek için kullanılır. Özellikle hibrit kalıtımda diamond problemine karşı çözüm sağlar.

Örneğin:

```cpp
class Base
{
	public:
		void show()
		{
			std::cout << "Base class" << std::endl;
		}
};

class Derived1 : virtual public Base {
};

class Derived2 : virtual public Base {
};

class Derived3 : public Derived1, public Derived2 {
};
```

Burada `Derived3` sınıfı, `Derived1` ve `Derived2`'den türemiş olmasına rağmen `Base` sınıfından sadece bir tane kopya alır.

### Kalıtımın Kullanımı

Kalıtım C++'ta üç erişim şekli ile yapılabilir:

1. **Public inheritance:** Taban sınıfın public ve protected üyeleri türetilen sınıfta aynı erişim seviyesine sahip olur.
	```cpp
	class Base
	{
		public:
			void publicMethod() {}
		protected:
			void protectedMethod() {}
	};

	class Derived : public Base
	{
		public:
			void accessMethods()
		{
				publicMethod();  // Erişilebilir
				protectedMethod(); // Erişilebilir
			}
	};
   ```

2. **Protected inheritance:** Taban sınıfın public üyeleri protected olarak miras alınır.
	```cpp
	class Derived : protected Base {
	};
	```

3. **Private inheritance:** Taban sınıfın tüm üyeleri private olarak miras alınır.
	```cpp
	class Derived : private Base {
	};
	```

<br></br>

## Inheritance Detaylı Örnek

**Inheritance** (kalıtım) kavramını daha iyi anlamak için aşağıdaki örnek üzerinden detaylı bir inceleme yapalım. Bu örnekte, kalıtımın nasıl çalıştığını, sınıfların birbirinden nasıl özellikler aldığını ve bu süreçte ne gibi davranışlar sergilediğini göreceğiz.

### Örnek: Hayvanlar Hiyerarşisi (Animal Hierarchy)

Amacımız, temel bir `Animal` sınıfı oluşturup, bu sınıftan `Dog` (Köpek) ve `Cat` (Kedi) sınıflarını türetmek. `Animal` sınıfı, hayvanların genel özelliklerini içerecek; `Dog` ve `Cat` sınıfları ise hayvan türlerine özgü özellikler ekleyecek.

#### 1. Temel `Animal` Sınıfı
İlk olarak, tüm hayvanlar için ortak olan bazı özellikleri ve davranışları tanımlayan bir `Animal` sınıfı oluşturuyoruz. Bu sınıf, her hayvanın ismi ve bir ses çıkarma yeteneği olduğunu varsayalım.

```cpp
#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string name;

	public:
		// Constructor
		Animal(std::string animalName) : name(animalName) {}

		// Hayvanın ses çıkarma davranışı
		virtual void makeSound() const
		{
			std::cout << "Some generic animal sound" << std::endl;
		}

		// Hayvanın adını döndüren fonksiyon
		std::string getName() const
		{
			return name;
		}
};
```

##### Açıklamalar:
- `name` üye değişkeni her hayvanın ismini saklamak için kullanılır. `protected` erişim belirleyicisiyle tanımlanmıştır. Bu, `name`'in yalnızca bu sınıf ve bu sınıftan türetilen sınıflar tarafından erişilebilir olduğu anlamına gelir.
- `Animal` sınıfının bir **yapıcı fonksiyonu** (constructor) var. Bu yapıcı, hayvanın ismini alır ve `name` değişkenine atar.
- `makeSound` fonksiyonu bir hayvanın ses çıkarma davranışını tanımlar, ancak bu noktada genel bir hayvan sesi üretir.
- `getName` fonksiyonu hayvanın adını döndürür.

#### 2. `Dog` (Köpek) Sınıfı
`Dog` sınıfını `Animal` sınıfından türeteceğiz ve köpeğe özgü özellikleri ekleyeceğiz. Köpekler havlar, bu nedenle `makeSound` fonksiyonunu köpeklere uygun şekilde yeniden tanımlayacağız.

```cpp
class Dog : public Animal
{
	public:
		// Dog sınıfının yapıcı fonksiyonu
		Dog(std::string dogName) : Animal(dogName) {}

		// Köpeğin ses çıkarma davranışı
		void makeSound() const override
		{
			std::cout << name << " says: Woof! Woof!" << std::endl;
		}
};
```

##### Açıklamalar:
- `Dog` sınıfı, `Animal` sınıfından **public** olarak miras alır. Bu, `Animal` sınıfındaki tüm public ve protected üyelerin `Dog` sınıfında aynı erişim seviyeleriyle kullanılabilir olduğu anlamına gelir.
- `makeSound` fonksiyonu, köpekler için özel bir ses çıkarma davranışı eklemek üzere **override** edilmiştir (C++11 version). `override` (C++11 version) anahtar kelimesi, bu fonksiyonun taban sınıfta tanımlı olan bir fonksiyonu geçersiz kılacağını belirtir.
- `name` değişkenine `protected` olduğu için türetilen sınıf tarafından doğrudan erişilebilmektedir.

#### 3. `Cat` (Kedi) Sınıfı
Benzer şekilde, `Cat` sınıfı da `Animal` sınıfından türetilecek ve kedilere özgü bir ses çıkarma davranışı tanımlayacaktır.

```cpp
class Cat : public Animal
{
	public:
		// Cat sınıfının yapıcı fonksiyonu
		Cat(std::string catName) : Animal(catName) {}

		// Kedinin ses çıkarma davranışı
		void makeSound() const override
		{
			std::cout << name << " says: Meow! Meow!" << std::endl;
		}
};
```

##### Açıklamalar:
- `Cat` sınıfı da `Animal` sınıfından **public** olarak miras alır.
- `makeSound` fonksiyonu, kedilere özgü şekilde yeniden tanımlanmıştır.
- Bu sınıf da `Animal` sınıfının `name` değişkenini doğrudan kullanabilir.

#### 4. Kullanım Örneği
Şimdi `main` fonksiyonunda bu sınıfları nasıl kullanacağımızı görelim:

```cpp
int main()
{
	// Hayvanlar yaratılıyor
	Dog dog1("Buddy");
	Cat cat1("Whiskers");

	// Ses çıkarma davranışları
	dog1.makeSound();  // Buddy says: Woof! Woof!
	cat1.makeSound();  // Whiskers says: Meow! Meow!

	// Hayvanların isimlerini döndürme
	std::cout << "Dog's name is: " << dog1.getName() << std::endl;
	std::cout << "Cat's name is: " << cat1.getName() << std::endl;

	return 0;
}
```

##### Çıktı:
```
Buddy says: Woof! Woof!
Whiskers says: Meow! Meow!
Dog's name is: Buddy
Cat's name is: Whiskers
```

### Örnek Üzerinden Detaylı Açıklama

1. **Kalıtım ve Davranış Devralma:**
   - `Dog` ve `Cat` sınıfları, `Animal` sınıfından türetilmiştir. Bu sayede her iki sınıf da `Animal` sınıfındaki özellikleri ve fonksiyonları (örneğin, `name` ve `getName()`) miras alır.
   - `Dog` ve `Cat` sınıfları, kendi türlerine özgü ses çıkarma davranışlarını `makeSound()` fonksiyonunu geçersiz kılarak (override) sağlar.

2. **Sanal Fonksiyon (Virtual Function):**
   - `makeSound()` fonksiyonu `Animal` sınıfında sanal olarak tanımlanmıştır. Bu, türetilen sınıfların kendi versiyonlarını tanımlayabilmesi ve doğru versiyonun çalışma zamanında çağrılabilmesi için gereklidir.
   - Eğer `makeSound()` fonksiyonu sanal olmasaydı, `Animal` türünden bir nesne üzerinden çağrıldığında her zaman `Animal` sınıfındaki genel fonksiyon çalıştırılırdı. Sanallık sayesinde türetilen sınıfın kendi fonksiyonu çağrılır.

3. **Kapsülleme (Encapsulation):**
   - `name` değişkeni `protected` olarak tanımlandığı için `Animal` sınıfının dışından doğrudan erişilemez, ancak bu sınıftan türeyen sınıflar tarafından erişilebilir.
   - `getName()` fonksiyonu, kapsülleme prensibine uygun olarak `name` değişkenine dışarıdan erişim sağlamak için kullanılır.

4. **Polimorfizm (Çok Biçimlilik):**
   - Türetilen sınıfların her biri `makeSound()` fonksiyonunu kendi ihtiyaçlarına göre yeniden tanımlamıştır. Bu, çalışma zamanında hangi sınıfın nesnesi kullanılıyorsa o sınıfın versiyonunun çağrılmasını sağlar. Bu polimorfizmin temel örneklerinden biridir.

5. **Kodun Yeniden Kullanılabilirliği:**
   - `Dog` ve `Cat` sınıfları, `Animal` sınıfından miras aldığı özellikler sayesinde yeniden kullanılabilir kod sağlar. Her hayvan türü için ortak olan kod, `Animal` sınıfında bir kere yazılmıştır ve `Dog` ve `Cat` sınıfları bu kodu tekrar yazmak zorunda kalmadan kullanabilir.
