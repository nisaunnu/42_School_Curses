## CPP Module 08 Notları

- [Containers](#containers)
	- [STL Containers Nedir?](#stl-containers-nedir)
	- [C++98’de STL Container Türleri](#c98de-stl-container-türleri)
	- [Template Container Nedir?](#template-container-nedir)
	- [Neden Template Kullanılır?](#neden-template-kullanılır)
	- [Templated Container’lar Derleme Sürecinde Nasıl Davranır?](#templated-containerlar-derleme-sürecinde-nasıl-davranır)
- [Container Çeşitleri](#container-çeşitleri)
	- [`vector<T>`](#vectort)
	- [`list<T>`](#listt)
	- [`deque<T>`](#dequet)
	- [`set<T>`](#sett)
	- [`map<Key, Value>`](#mapkey-value)
	- [`multiset<T>` ve `multimap<Key, Value>`](#multisett-ve-multimapkey-value)
	- [Container Adapters: `stack<T>`, `queue<T>`, `priority_queue<T>`](#container-adapters-stackt-queuet-priority_queuet)
	- [Container Karşılaştırma Tablosu](#container-karşılaştırma-tablosu)
- [Iterator](#iterator)
	- [Iterator Nedir?](#iterator-nedir)
	- [Neden Iterator Kullanılır?](#neden-iterator-kullanılır)
	- [Iterator Türleri (C++98)](#iterator-türleri-c98)
	- [Genel Kullanım Şekli (Syntax)](#genel-kullanım-şekli-syntax)
	- [Sık Kullanılan Iterator Fonksiyonları](#sık-kullanılan-iterator-fonksiyonları)
	- [Örneklerle Açıklama](#örneklerle-açıklama)
	- [Özel Iterator: `const_iterator`](#özel-iterator-const_iterator)
	- [Özel Iterator: `reverse_iterator`](#özel-iterator-reverse_iterator)
	- [Özel Iterator: `const_reverse_iterator`](#özel-iterator-const_reverse_iterator)
	- [Özel Iterator: `insert_iterator`](#özel-iterator-insert_iterator)
	- [Özel Iterator: `back_insert_iterator`](#özel-iterator-back_insert_iterator)
	- [Özel Iterator: `front_insert_iterator`](#özel-iterator-front_insert_iterator)
	- [Özel Iterator Tiplerinin Karşılaştırma Tablosu](#özel-iterator-tiplerinin-karşılaştırma-tablosu)
- [Container Fonkiyonları/Metodları](#container-fonkiyonlarımetodları)
	- [`vector<T>`](#vectort-1)
	- [`list<T>`](#listt-1)
	- [`deque<T>`](#dequet-1)
	- [`set<T>`](#sett-1)
	- [`map<Key, Value>`](#mapkey-value-1)
	- [`multiset<T>`](#multisett)
	- [`multimap<Key, Value>`](#multimapkey-value)
	- [`stack<T>` (Adapter: default container = deque)](#stackt-adapter-default-container--deque)
	- [`queue<T>` (Adapter: default container = deque)](#queuet-adapter-default-container--deque)
	- [`priority_queue<T>` (Adapter: default container = vector + heap)](#priority_queuet-adapter-default-container--vector--heap)

<br></br>

## Containers

### STL Containers Nedir?

Container (Kapsayıcı): Verileri belli bir düzende saklamaya yarayan yapılardır. STL (Standard Template Library), veri yapıları sunar ve bu yapılar template (şablon) olarak tasarlanmıştır.

<br>

### C++98’de STL Container Türleri

STL’de 3 ana container türü vardır:

1. Sequence Containers (Sıralı Kapsayıcılar)
	- vector → Dinamik dizi
	- deque → Çift uçlu kuyruk
	- list → Doubly linked list (çift yönlü bağlı liste)

2. Associative Containers (Anahtar-değer bazlı)
	- set → Benzersiz ve sıralı öğeler
	- map → Benzersiz anahtarlar, her anahtar bir değere eşleşmiş
	- multiset → Tekrar eden öğelere izin verir
	- multimap → Aynı anahtardan birden fazla olabilir

3. Container Adapters (Özelleştirilmiş konteynerler)

Başka konteynerler üzerine inşa edilmiş yapılar:
- stack          → LIFO (Last-In First-Out)
- queue          → FIFO (First-In First-Out)
- priority_queue → Öncelik sırasına göre işler

<br>

### Template Container Nedir?

Templated container, veri tipi fark etmeksizin kullanılabilen, şablon yapıda yazılmış kapsayıcıdır.

Örnek:
```cpp
#include <vector>
#include <iostream>

int main()
{
	std::vector<int>			numbers;   // int tipinde vektör
	std::vector<std::string>	words;     // string tipinde vektör

	numbers.push_back(10);
	words.push_back("Merhaba");

	std::cout << numbers[0] << " - " << words[0] << std::endl;

	return 0;
}
```

vector burada bir template class’tir. İçine int, double, std::string gibi herhangi bir tür verilebilir.

<br>

### Neden Template Kullanılır?

- Kod tekrarını azaltır.
- Farklı veri türleriyle çalışabilir.
- Generic programming (genel programlama) sağlar.

Kendi template container’ını bile yazabilirsin:
```cpp
#include <iostream>

template <typename T>
class SimpleBox
{
	private:
		T item;
	public:
		void set(const T& value) { item = value; }
		T get() const { return item; }
};

int main()
{
	SimpleBox<int>	box;

	box.set(42);

	std::cout << box.get() << std::endl;
}
```

<br>

### Templated Container’lar Derleme Sürecinde Nasıl Davranır?

Templated sınıflar derleme zamanında “instantiate” edilir. Yani şu kod:

```cpp
std::vector<int> v1;
std::vector<double> v2;
```

derleyici tarafından şuna benzer şekilde çevrilir:
- vector<int> için ayrı bir sınıf
- vector<double> için ayrı bir sınıf

<br></br>

## Container Çeşitleri

### `vector<T>`

- Nedir?
  - Dinamik boyutlu dizi gibidir. array gibi ama boyutu çalışma zamanında artabilir.
- Ne işe yarar?
  - Sürekli veri eklemek ve onlara hızlıca indeksle erişmek için.
- Syntax:
	```cpp
	std::vector<int> myVector;
	```
- Nasıl çalışır?
	- Bellekte arka arkaya yer ayırır.
	- push_back ile sona eleman eklenir.
	- [] veya .at() ile erişilir.
- Ne zaman kullanılır?
	- Sıralı veri saklayacaksan.
	- Rastgele erişime ihtiyacın varsa.
- Örnek:
	```cpp
	#include <iostream>
	#include <vector> // vector kullanmak için

	int main()
	{
		std::vector<int>	nums; // int türünde dinamik bir dizi tanımladık

		nums.push_back(10); // Dizinin sonuna 10 ekledik
		nums.push_back(20); // Sonuna 20 ekledik

		// Elemanları yazdır
		for (size_t i = 0; i < nums.size(); ++i)
			std::cout << nums[i] << std::endl; // i. elemanı yazdır

		return 0;
	}
	```

<br>

### `list<T>`

- Nedir?
  - Çift yönlü bağlı listedir (doubly linked list).
- Ne işe yarar?
  - Başından ve sonundan hızlıca ekleme/silme yapmak için.
- Syntax:
	```cpp
	std::list<std::string> names;
	```
- Nasıl çalışır?
	- Elemanlar bağlantılarla tutulur, rastgele erişim yavaştır.
	- push_back, push_front ile eklenir.
- Ne zaman kullanılır?
	- Elemanları sıkça ekleyip çıkaracaksan (baş/sondan).
	- Ortadaki elemanları sıkça değiştireceksen.
- Örnek:
	```cpp
	#include <iostream>
	#include <list> // list kapsayıcısı

	int main()
	{
		std::list<std::string>	fruits; // string listesi

		fruits.push_back("Elma");  // Sona ekle
		fruits.push_front("Armut"); // Başa ekle

		// Elemanları sırayla yazdır
		for (std::list<std::string>::iterator it = fruits.begin(); it != fruits.end(); ++it)
			std::cout << *it << std::endl;

		return 0;
	}
	```

<br>

### `deque<T>`

- Nedir?
  - Çift uçlu dizi. Hem baştan hem sondan hızlı erişim sunar.
- Ne işe yarar?
  - Hem baştan hem sondan ekleme/silme gerekiyorsa.
- Syntax:
	```cpp
	std::deque<int> dq;
	```
- Nasıl çalışır?
	- push_back, push_front, pop_back, pop_front gibi fonksiyonlarla çalışır.
- Ne zaman kullanılır?
	- Stack + Queue özelliklerini birlikte istiyorsan.
- Basit Örnek:
	```cpp
	#include <iostream>
	#include <deque>

	int main()
	{
		std::deque<int>	d;

		d.push_back(1);  // Sona 1 ekle
		d.push_front(2); // Başa 2 ekle

		std::cout << d.front() << std::endl; // İlk eleman: 2
		std::cout << d.back() << std::endl;  // Son eleman: 1

		return 0;
	}
	```

<br>

### `set<T>`

- Nedir?
  - Benzersiz ve sıralı öğeleri saklar.
- Ne işe yarar?
  - Tekrar etmeyen verileri sıralı biçimde tutmak için.
- Syntax:
	```cpp
	std::set<int> mySet;
	```
- Nasıl çalışır?
	- Otomatik sıralar.
	- Aynı değer 2 kere eklenemez.
- Ne zaman kullanılır?
	- Benzersiz ve sıralı veri gerekiyorsa (örn: etiketler, sayılar).
- Basit Örnek:
	```cpp
	#include <iostream>
	#include <set>

	int main()
	{
		std::set<int>	s;

		s.insert(5); // 5'i ekle
		s.insert(3); // 3'ü ekle
		s.insert(5); // 5 zaten var, eklenmez

		for (std::set<int>::iterator it = s.begin(); it != s.end(); ++it)
			std::cout << *it << std::endl;

		return 0;
	}
	```

<br>

### `map<Key, Value>`

- Nedir?
  - Anahtar-değer (key-value) eşleşmesini tutan yapıdır.
- Ne işe yarar?
  - Bir anahtarla ilişkili değeri hızlıca bulmak için.
- Syntax:
	```cpp
	std::map<std::string, int> phoneBook;
	```
- Nasıl çalışır?
	- Her key bir değerle eşleşir.
	- Otomatik sıralanır.
	- Aynı key sadece bir kez olabilir.
- Ne zaman kullanılır?
	- Telefon rehberi, sözlük, eşleştirme gibi durumlar.
- Basit Örnek:
	```cpp
	#include <iostream>
	#include <map>

	int main()
	{
		std::map<std::string, int>	ages;

		ages["Ali"] = 25;   // "Ali" anahtarına 25 değeri atanır
		ages["Ayşe"] = 30;

		std::cout << "Ali'nin yaşı: " << ages["Ali"] << std::endl;

		return 0;
	}
	```

<br>

### `multiset<T>` ve `multimap<Key, Value>`

- Farkları:
	- multiset: Aynı değerden birden fazla olabilir.
	- multimap: Aynı key’den birden fazla olabilir.
- Ne zaman kullanılır?
	- set veya map’in tekrar eden verileri saklamasına izin verilmesi gereken durumlarda.

<br>

### Container Adapters: `stack<T>`, `queue<T>`, `priority_queue<T>`

1. `stack<T>`

	LIFO yapısı (Last In First Out)
	```cpp
	#include <stack>
	#include <iostream>

	int main()
	{
		std::stack<int>	s;

		s.push(10); // 10 ekle
		s.push(20); // 20 ekle

		std::cout << s.top() << std::endl; // Son eklenen 20
		s.pop(); // 20 çıkarılır

		std::cout << s.top() << std::endl; // Artık 10 var

		return 0;
	}
	```

<br>

2. `queue<T>`

	FIFO yapısı (First In First Out)
	```cpp
	#include <queue>
	#include <iostream>

	int main()
	{
		std::queue<int>	q;

		q.push(1); // Kuyruğa ekle
		q.push(2);

		std::cout << q.front() << std::endl; // İlk gelen: 1
		q.pop(); // 1 çıkar

		std::cout << q.front() << std::endl; // Artık 2 var

		return 0;
	}
	```

<br>

3. `priority_queue<T>`

	En büyük öncelikli elemanı öne alır
	```cpp
	#include <queue>
	#include <iostream>

	int main()
	{
		std::priority_queue<int>	pq;

		pq.push(5);
		pq.push(10);
		pq.push(1);

		std::cout << pq.top() << std::endl; // En büyük: 10

		return 0;
	}
	```

<br>

### Container Karşılaştırma Tablosu

| Container      | Sıralı | Anahtar | Tekrar İzin | Rastgele Erişim | Ekleme/Silme | Özel             |
|----------------|:------:|:-------:|:-----------:|:---------------:|:------------:|:----------------:|
| vector         | ✔      | ❌      | ✔           | ✔               | Orta         | Dinamik dizi     |
| list           | ✔      | ❌      | ✔           | ❌              | Hızlı        | Bağlı liste      |
| deque          | ✔      | ❌      | ✔           | ✔               | Hızlı        | Çift uç          |
| set            | ✔      | ✔       | ❌          | ❌              | Orta         | Benzersiz        |
| multiset       | ✔      | ✔       | ✔           | ❌              | Orta         | Tekrar izinli    |
| map            | ✔      | ✔       | ❌          | ❌              | Orta         | Anahtar-değer    |
| multimap       | ✔      | ✔       | ✔           | ❌              | Orta         | Aynı key tekrar |
| stack          | ❌     | ❌       | ✔           | ❌              | Hızlı        | LIFO            |
| queue          | ❌     | ❌       | ✔           | ❌              | Hızlı        | FIFO            |
| priority_queue | ❌     | ❌       | ✔           | ❌              | Hızlı        | Max öncelik     |

<br></br>

## Iterator

### Iterator Nedir?
- Iterator, STL kapsayıcıları (vector, list, map, vs.) üzerinde başlangıçtan sona kadar dolaşmanı sağlar.
- Pointer gibi çalışır: `*it` ile değeri alırsın, `++it` ile bir sonraki elemana gidersin.
- Her STL kapsayıcıya özel iterator tipi vardır: `std::vector<int>::iterator`, `std::list<std::string>::iterator` gibi.

<br>

### Neden Iterator Kullanılır?

- Container elemanlarına erişmek
- Tüm container’lar üzerinde ortak bir şekilde gezinmek
- for döngüsünde pointer gibi işlem yapmak
- Algoritmalarla (sort, find, etc.) birlikte çalışmak

<br>

### Iterator Türleri (C++98)

| Iterator Türü    | Açıklama                                                         |
|------------------|------------------------------------------------------------------|
| Input Iterator   | Sadece okumak için (okuma yönü tek)                              |
| Output Iterator  | Sadece yazmak için                                               |
| Forward Iterator | İleri doğru gezinme (tek yönlü)                                  |
| Bidirectional    | Hem ileri hem geri (list, set, map)                              |
| Random Access    | Rastgele erişim (vector, deque gibi) – it + 2, it[i], it < other |

> vector → Random Access
>
> list, set, map → Bidirectional
>
> stack, queue → iterator desteklemez

<br>

### Genel Kullanım Şekli (Syntax)

```cpp
std::vector<int>::iterator it;  // vector için iterator

for (it = v.begin(); it != v.end(); ++it)
{
	std::cout << *it << std::endl;
}
```

<br>

### Sık Kullanılan Iterator Fonksiyonları

| Fonksiyon | Açıklama                             |
|-----------|--------------------------------------|
| begin()   | İlk elemanı işaret eden iterator     |
| end()     | Son elemandan bir sonraki konum      |
| *it       | Iterator’ın gösterdiği değeri alır   |
| ++it      | Bir sonraki elemana geçer            |
| --it      | Önceki elemana geçer (bidirectional) |
| it == it2 | İki iterator karşılaştırılır         |
| rbegin()  | Ters iterator başı                   |
| rend()    | Ters iterator sonu                   |

<br>

### Örneklerle Açıklama

* Vector Iterator (Random Access)
	```cpp
	#include <iostream>
	#include <vector>

	int main()
	{
		std::vector<int>	v;

		v.push_back(10);
		v.push_back(20);
		v.push_back(30);

		// Iterator tanımla
		std::vector<int>::iterator	it;

		// Başlangıçtan sona kadar gezin
		for (it = v.begin(); it != v.end(); ++it)
			std::cout << *it << std::endl; // Iterator’un işaret ettiği değeri yazdır

		return 0;
	}
	```

* List Iterator (Bidirectional)
	```cpp
	#include <iostream>
	#include <list>

	int main()
	{
		std::list<std::string>	names;

		names.push_back("Ali");
		names.push_back("Ayşe");

		std::list<std::string>::iterator	it;

		for (it = names.begin(); it != names.end(); ++it)
			std::cout << *it << std::endl;

		return 0;
	}
	```

* Map Iterator (Anahtar-değer)
	```cpp
	#include <iostream>
	#include <map>

	int main()
	{
		std::map<std::string, int>	ages;

		ages["Ali"] = 25;
		ages["Ayşe"] = 30;

		std::map<std::string, int>::iterator	it;

		for (it = ages.begin(); it != ages.end(); ++it)
			std::cout << it->first << " => " << it->second << std::endl;

		return 0;
	}
	```

	>
	> it->first: Anahtar
	>
	> it->second: Değer
	>

<br>

### Özel Iterator: `const_iterator`

- Nedir?
  - Container içindeki verileri yalnızca okumak için kullanılan iterator türüdür. Değer değiştirilemez.
- Ne işe yarar?
	- Container verilerine okuma amacıyla güvenli erişim sağlar.
	- Kodun yanlışlıkla container’ı değiştirmesini önler.
- Syntax:
```cpp
std::vector<int>::const_iterator	it;
```
- Örnek:
	```cpp
	#include <iostream>
	#include <vector>

	int main()
	{
		std::vector<int>	v;

		v.push_back(1);
		v.push_back(2);

		std::vector<int>::const_iterator	it;

		for (it = v.begin(); it != v.end(); ++it)
		{
			std::cout << *it << std::endl; // sadece okunabilir
			// *it = 10; // ❌ Değeri değiştirmek yasak
		}

		return 0;
	}
	```

<br>

### Özel Iterator: `reverse_iterator`

- Nedir?
  - Container üzerinde sondan başa doğru dolaşmak için kullanılır.

- Ne işe yarar?
	- Elemanları tersten yazdırmak için.
	- Geriye doğru gezinme gerektiğinde daha kolaydır.
- Syntax:
	```cpp
	std::vector<int>::reverse_iterator rit;
	```
- Örnek:
	```cpp
	#include <iostream>
	#include <vector>

	int main()
	{
		std::vector<int>	v;

		v.push_back(10);
		v.push_back(20);
		v.push_back(30);

		std::vector<int>::reverse_iterator	rit;

		for (rit = v.rbegin(); rit != v.rend(); ++rit)  // rbegin() son elemanı işaret eder, rend() ise ilk elemandan bir öncesini.
			std::cout << *rit << std::endl; // 30, 20, 10

		return 0;
	}
	```

<br>

### Özel Iterator: `const_reverse_iterator`

- Nedir?
  - Hem ters yönlü hem de salt okunur iterator’dır.
- Kullanımı:
	```cpp
	std::vector<int>::const_reverse_iterator	crit;

	for (crit = v.rbegin(); crit != v.rend(); ++crit)
	{
		std::cout << *crit << std::endl; // Okuma OK
		// *crit = 99; // ❌ Yazma yok
	}
	```

<br>

### Özel Iterator: `insert_iterator`

- Nedir?
  - Bir container’a iterator ile eleman eklemeye izin verir.
- Nerede kullanılır?
  - STL algoritmaları ile birlikte eleman eklemek istiyorsan.
- Gerekli başlık:
	```cpp
	#include <iterator>
	```
- Örnek:
	```cpp
	#include <iostream>
	#include <vector>
	#include <iterator>
	#include <algorithm>

	int main()
	{
		std::vector<int>	src;

		src.push_back(1);
		src.push_back(2);

		std::vector<int>	dest;
		std::insert_iterator<std::vector<int> >	it(dest, dest.begin());

		std::copy(src.begin(), src.end(), it);  // std::copy ile src’den dest’e elemanları aktarıyoruz

		for (size_t i = 0; i < dest.size(); ++i) {
			std::cout << dest[i] << std::endl; // 1, 2
		}

		return 0;
	}
	```

<br>

### Özel Iterator: `back_insert_iterator`

- Nedir?
  - push_back fonksiyonunu kullanarak container’ın sonuna eleman ekler.
- Kullanımı:
	```cpp
	#include <iterator>
	std::back_insert_iterator<std::vector<int> > it(v);
	*it = 5; // push_back(5)
	```
- STL algoritmalarıyla:
	```cpp
	std::copy(src.begin(), src.end(), std::back_inserter(dest));
	```

<br>

### Özel Iterator: `front_insert_iterator`

- Nedir?
  - push_front() kullanarak başına eleman eklemek için (sadece list ve deque destekler).
- Örnek:
	```cpp
	std::list<int>		l;
	std::front_insert_iterator<std::list<int> >	fit(l);

	*fit = 3; // l.push_front(3);
	```

<br>

### Özel Iterator Tiplerinin Karşılaştırma Tablosu

| Iterator Türü            | Yön     | Yazma | Okuma | Kullanıldığı Durum              |
|--------------------------|---------|-------|-------|----------------------------------|
| `iterator`               | ileri   | ✔     | ✔     | Genel kullanım                   |
| `const_iterator`         | ileri   | ❌    | ✔     | Salt okunur erişim               |
| `reverse_iterator`       | geri    | ✔     | ✔     | Tersten gezinme                  |
| `const_reverse_iterator` | geri    | ❌    | ✔     | Tersten ama sadece okuma         |
| `insert_iterator`        | -       | ✔     | ❌    | Algoritmalarla araya ekleme      |
| `back_insert_iterator`   | -       | ✔     | ❌    | Sona eleman ekleme (push_back)   |
| `front_insert_iterator`  | -       | ✔     | ❌    | Başa eleman ekleme (push_front)  |


<br></br>

## Container Fonkiyonları/Metodları

### `vector<T>`
```cpp
v.empty();            // Boş mu?
v.size();             // Eleman sayısı
v.capacity();         // Kapasite (ayrılan yer)
v.max_size();         // Maksimum alabileceği eleman
v.resize(n);          // Boyutu n yap
v.reserve(n);         // En az n kapasite ayır

v.push_back(val);     // Sona eleman ekle
v.pop_back();         // Sondaki elemanı çıkar
v.clear();            // Tüm elemanları sil

v.front();            // İlk eleman
v.back();             // Son eleman
v[i];                 // i. elemanı getir
v.at(i);              // i. elemanı sınır kontrolüyle getir

v.begin();            // İlk elemanı işaret eden iterator
v.end();              // Sonraki konumu işaret eden iterator
```
<br>

### `list<T>`
```cpp
l.empty();            // Boş mu?
l.size();             // Eleman sayısı
l.max_size();         // Maksimum kapasite

l.push_back(val);     // Sona eleman ekle
l.push_front(val);    // Başa eleman ekle
l.pop_back();         // Sondan eleman çıkar
l.pop_front();        // Baştan eleman çıkar
l.clear();            // Tüm elemanları sil

l.front();            // İlk eleman
l.back();             // Son eleman

l.begin();            // Baş iterator
l.end();              // Son iterator

l.insert(pos, val);   // Belirtilen konuma ekle
l.erase(pos);         // Belirtilen konumdaki elemanı sil

l.sort();             // Listeyi sırala
l.reverse();          // Listeyi ters çevir
l.remove(val);        // Belirtilen değerdeki elemanları sil
```

<br>

### `deque<T>`
```cpp
d.empty();
d.size();
d.max_size();

d.push_back(val);     // Sona ekle
d.push_front(val);    // Başa ekle
d.pop_back();         // Sondan çıkar
d.pop_front();        // Baştan çıkar
d.clear();

d.front();
d.back();
d[i];
d.at(i);

d.begin();
d.end();

d.insert(pos, val);   // Araya ekle
d.erase(pos);         // Aradan sil
```

<br>

### `set<T>`
```cpp
s.empty();
s.size();
s.max_size();

s.insert(val);           // Değer ekle (eğer yoksa)
s.erase(val);            // Belirtilen değeri sil
s.clear();

s.find(val);             // Değer var mı? Iterator döner
s.count(val);            // Değerin kaç defa geçtiğini döner (0 veya 1)

s.begin();
s.end();
s.lower_bound(val);      // val ≥ olan ilk elemanı döner
s.upper_bound(val);      // val > olan ilk elemanı döner
```

<br>

### `map<Key, Value>`
```cpp
m.empty();
m.size();
m.max_size();

m.insert(std::pair<Key, Value>(key, value)); // Anahtar-değer çifti ekle
m[key] = value;                              // Anahtara doğrudan değer ata
m.erase(key);                                // Anahtarı sil
m.clear();

m.find(key);              // Anahtar var mı? Iterator döner
m.count(key);             // 0 veya 1 döner

m.begin();
m.end();
m.lower_bound(key);
m.upper_bound(key);
```

<br>

### `multiset<T>`
```cpp
ms.insert(val);           // Değer ekle (tekrar eden olabilir)
ms.erase(val);            // Tüm kopyaları siler
ms.count(val);            // Aynı değerden kaç tane var?
ms.find(val);             // İlk geçen iterator
ms.clear();
```

<br>

### `multimap<Key, Value>`
```cpp
mm.insert(std::pair<Key, Value>(key, value)); // Aynı key'den birden fazla olabilir
mm.erase(key);                                // Tüm aynı key'leri siler
mm.count(key);                                // Aynı key'den kaç tane var?
mm.find(key);                                  // İlk eşleşen key iterator
mm.equal_range(key);                          // Aynı key'e ait tüm değerleri döner (pair<iterator, iterator>)
mm.clear();
```

<br>

### `stack<T>` (Adapter: default container = deque)
```cpp
s.empty();
s.size();

s.push(val);     // Eleman ekle
s.pop();         // En üsttekini çıkar
s.top();         // En üstteki elemanı getir
```

<br>

### `queue<T>` (Adapter: default container = deque)
```cpp
q.empty();
q.size();

q.push(val);     // Kuyruğa ekle
q.pop();         // İlk geleni çıkar
q.front();       // İlk geleni getir
q.back();        // Son ekleneni getir
```

<br>

### `priority_queue<T>` (Adapter: default container = vector + heap)
```cpp
pq.empty();
pq.size();

pq.push(val);     // Eleman ekle
pq.pop();         // En öncelikli olanı çıkar
pq.top();         // En öncelikli olanı getir (varsayılan: en büyük)
```

<br></br>
