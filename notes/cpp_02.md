## İçerik

- [İçerik](#i̇çerik)
- [Ortodoks Kanonik Form](#ortodoks-kanonik-form)
	- [Tanımlanması Gereken Altı Üye İşlev](#tanımlanması-gereken-altı-üye-i̇şlev)
	- [Neden Kullanılır?](#neden-kullanılır)
	- [Rule of Three / Rule of Five / Rule of Zero](#rule-of-three--rule-of-five--rule-of-zero)
- [Floating Point Numbers (Kayan Noktalı Sayılar)](#floating-point-numbers-kayan-noktalı-sayılar)
	- [Floating Point Sayı Nedir?](#floating-point-sayı-nedir)
	- [Avantajları](#avantajları)
	- [Dezavantajları](#dezavantajları)
	- [Ne Zaman Kullanılır?](#ne-zaman-kullanılır)
- [Fixed Point Numbers (Sabit Noktalı Sayılar)](#fixed-point-numbers-sabit-noktalı-sayılar)
	- [Fixed Point Sayılar Nedir?](#fixed-point-sayılar-nedir)
	- [Avantajları](#avantajları-1)
	- [Dezavantajları](#dezavantajları-1)
	- [Ne Zaman Kullanılır?](#ne-zaman-kullanılır-1)
- [Karşılaştırmalar](#karşılaştırmalar)
	- [Floating Point vs Integers](#floating-point-vs-integers)
	- [Floating Point vs Fixed Point](#floating-point-vs-fixed-point)
		- [Sonuç](#sonuç)
- [`roundf` fonksiyonu](#roundf-fonksiyonu)
	- [`roundf` Fonksiyonunun Söz Dizimi ve Kullanımı](#roundf-fonksiyonunun-söz-dizimi-ve-kullanımı)
	- [`roundf` Fonksiyonunun Çalışma Mantığı](#roundf-fonksiyonunun-çalışma-mantığı)
	- [Yuvarlama Kuralı](#yuvarlama-kuralı)
	- [`roundf` ile Diğer Yuvarlama Fonksiyonları Arasındaki Farklar](#roundf-ile-diğer-yuvarlama-fonksiyonları-arasındaki-farklar)
- [`std::ostream` Sınıfı](#stdostream-sınıfı)
	- [`std::ostream` Sınıfında `operator` Aşırı Yüklemesi](#stdostream-sınıfında-operator-aşırı-yüklemesi)
		- [Operatör Aşırı Yüklemesi Nasıl Yapılır?](#operatör-aşırı-yüklemesi-nasıl-yapılır)
		- [Operatör Aşırı Yüklenmenin Çağırıldığını Nasıl Anlarız?](#operatör-aşırı-yüklenmenin-çağırıldığını-nasıl-anlarız)
		- [Operatör Aşırı Yüklemenin Avantajları](#operatör-aşırı-yüklemenin-avantajları)
		- [Dikkat Edilmesi Gerekenler](#dikkat-edilmesi-gerekenler)
- [Polimorfizm](#polimorfizm)

<br></br>

## Ortodoks Kanonik Form

C++'da "Ortodoks Kanonik Form" (Orthodox Canonical Form), bir sınıfın (class) uygun şekilde kopyalanabilir ve atanabilir olmasını sağlamak için kullanılan kurallar bütünüdür. Bu form, özellikle kopyalama işlemlerinin doğru ve güvenli şekilde yapılabilmesi için sınıfın beş temel üyesinin doğru şekilde tanımlanmasını önerir. Bu üyelere ***[Rule of Five (Beşin Kuralı)]()*** denir. Bu modülde ***[Rule of Three]()*** kuralı kullanılmaktadır.

### Tanımlanması Gereken Altı Üye İşlev

1. **Yapıcı** (Constructor): Varsayılan yapıcı, bir sınıftan yeni bir nesne oluşturulurken herhangi bir parametre verilmediğinde çağrılır. Bu işlev genellikle sınıfın üyelerinin varsayılan başlangıç değerlerini ayarlamak için kullanılır.
   ```cpp
   class ClassName
   {
	public:
		ClassName()
		{
			// Varsayılan yapıcı
			// Üyeleri varsayılan değerlere ayarla
		}
	};
   ```

2. **Kopya yapıcı** (Copy Constructor): Kopya yapıcı, bir sınıfın yeni bir nesnesini oluştururken, var olan bir nesneden (genellikle başka bir nesne) kopyalama işlemi yapar. Kopya yapıcı, bir nesnenin kopyalandığı durumlarda otomatik olarak çağrılır.

- Kullanım Durumları:
  - Fonksiyon Parametreleri: Bir nesne başka bir nesne ile fonksiyon parametresi olarak geçirildiğinde, kopya yapıcı çağrılır.
  - Nesne Atama: Bir nesne, başka bir nesneye atandığında kopya yapıcı kullanılır.
- Neden Kullanırız:
  - Derin Kopyalama: Eğer sınıfın içinde dinamik bellek tahsisi (örneğin, new ile) yapılmışsa, kopya yapıcı ile derin kopyalama yapılması gerekebilir. Bu, kaynakların doğru yönetilmesini sağlar; aksi takdirde, her iki nesne de aynı bellek alanına işaret eder ve birinin yok edilmesi diğerinin işlevselliğini etkileyebilir.

> Örnek:

```cpp
#include <iostream>

class MyClass
{
	public:
		int*	data;

		// Kopya yapıcı
		MyClass(const MyClass& other)
		{
			data = new int; // Yeni bellek tahsis et
			*data = *(other.data); // Değeri kopyala
		}

		// Yıkıcı
		~MyClass()
		{
			delete data; // Belleği serbest bırak
		}
};

int main()
{
	MyClass obj1;
	obj1.data = new int(42); // obj1 için bellek tahsis et

	MyClass obj2 = obj1; // Kopya yapıcı çağrılır
	std::cout << *obj2.data << std::endl; // 42

	return 0;
}
```

3. **Kopya atama operatörü** (Copy Assignment Operator): Kopyalama atama operatörü, bir nesnenin başka bir nesneye atandığı durumlarda çağrılır. Atama operatöründe, mevcut bir nesneye başka bir nesnenin değerlerini atamak için kullanılır. Bu operatör, = operatörü ile birlikte tanımlanır. Bellek sızıntılarını ve hataları önlemek için doğru şekilde yazılmalıdır.

- Kullanım Durumları:
  - Nesne Ataması: Var olan bir nesneye başka bir nesne atandığında çağrılır.
- Neden Kullanırız:
  - Kaynak Yönetimi: Kopya atama operatörü, mevcut nesnelerin içindeki dinamik kaynakların doğru bir şekilde yönetilmesini sağlar. Eğer kopya atama operatörü tanımlanmazsa, varsayılan (default) bir operatör kullanılır ve bu, sadece bellek adresini kopyalar (shallow copy) ve bu durum bellek sızıntılarına yol açabilir.

```cpp
class ClassName
{
	public:
		ClassName& operator=(const ClassName& other);
		{
			if (this != &other)
			{
				// Bu satır, kendi kendine atama durumunu kontrol eder
				// Eğer *this (atama yapılan nesne) ile other aynı nesne ise, kendine atama yapılmış olur

				// Örneğin, a = a gibi bir durumda:
				//    - a nesnesi kendisine atanır ve bir işlem yapılmaması gereklidir

				// Bu satır olmadan:
				//    - kendine atama durumunda nesne verileri tekrar işlenir
				//    - verilerin tekrar işlenmesi gereksiz işlemlere veya hata durumlarına yol açabilir
			}

			// operator= işlevi, kendisine (*this) bir referans döndürür.
			// Bu, aşağıda bahsettiğimiz zincirleme atama işlemlerine olanak sağlar.
			return *this;
		}
};
```

Koddaki her ifadenin anlamları:

1. `ClassName&`: Bu kısım, operatörün dönüş tipini ifade eder.
	- ClassName&, kopya atama operatörünün, atanmış olan nesnenin referansını döndürdüğünü belirtir.
	- Döndürdüğümüz referans, *this nesnesinin (kendisine atama yapılan nesnenin) referansıdır.
	- Bu sayede, aşağıdaki gibi zincirleme atama işlemlerini destekleriz:
		```cpp
		ClassName a, b, c;
		a = b = c;
		```
		Bu tür bir zincirleme atamada b = c ifadesi, b nesnesinin c nesnesi ile aynı hale gelmesini sağlar ve ardından a = b ifadesi işlenir. Kopya atama operatörünün kendini (*this) döndürmesi, zincirleme işlemlerinde kolaylık sağlar.
2. `operator=`: Bu, özel bir C++ operatör işlevi olup atama operatörünü (=) yeniden tanımlar.
	- Atama operatörü, iki nesne arasında eşitlik ilişkisi kurmak için kullanılır
	- Böylece sağ taraftaki nesne (parametre olarak gönderilen nesne), sol taraftaki nesneye kopyalanır.
	- Bu operatör fonksiyonu aşırı yüklendiğinde, bir nesnenin başka bir nesneyle aynı hale getirilmesi sağlanır.
	- Atama operatörü, nesnenin iç durumunu (örneğin, verilerini) güncellerken dikkat edilmesi gereken önemli bir işlevdir.

3. `const ClassName& other`: Bu ifade, operator= işlevinin aldığı parametreyi temsil eder:
	- `const`: other parametresinin sabit olduğunun garantisidir. Yani, bu parametre üzerinde hiçbir değişiklik yapılmayacağını belirtir. Bu, atama işleminde yalnızca kaynak nesneyi okuyacağımız için uygundur.
	- `ClassName&`: other parametresi bir ClassName sınıfının referansıdır. Referans kullanarak, nesnenin tamamını kopyalamak yerine yalnızca adresini göndeririz. Bu sayede kopya maliyetini önleriz.
	- Bu şekilde, operator= işlevine geçilen other parametresi, kopyalama yapılmadan (daha verimli bir şekilde) işlev içinde kullanılabilir.

> Örnek:

```cpp
#include <iostream>

class MyClass
{
	public:
		int*	data;

		// Kopya atama operatörü
		MyClass& operator=(const MyClass& other)
		{
			if (this != &other) // Kendini kopyalamaktan kaçın
			{
				delete data; // Eski veriyi temizle
				data = new int; // Yeni bellek tahsis et
				*data = *(other.data); // Değeri kopyala
			}
			return *this; // Kendini döndür
		}

		// Yıkıcı
		~MyClass()
		{
			delete data; // Belleği serbest bırak
		}
};

int main()
{
	MyClass obj1;
	obj1.data = new int(42); // obj1 için bellek tahsis et

	MyClass obj2;
	obj2 = obj1; // Kopya atama operatörü çağrılır
	std::cout << *obj2.data << std::endl; // 42

	return 0;
}
```

4. **Yıkıcı** (Destructor): Yıkıcı, bir nesne işini bitirdiğinde ve bellekten kaldırıldığında çağrılır. Yıkıcı genellikle dinamik olarak tahsis edilen belleği serbest bırakmak veya sınıfın üyelerinin yaşam döngüsünü düzgün bir şekilde sonlandırmak için kullanılır.
   ```cpp
   class ClassName
   {
	public:
		~ClassName()
		{
			// Yıkıcı
			// Dinamik bellek veya kaynakları serbest bırak
		}
	};
   ```

5. **Taşıma yapıcı** (Move Constructor): Bir nesnenin başka bir nesneye taşınmasını sağlar. C++11 ile gelmiştir.
   ```cpp
   ClassName(ClassName&& other) noexcept;
   ```

6. **Taşıma atama operatörü** (Move Assignment Operator): Var olan bir nesneye başka bir nesnenin kaynaklarının taşınmasını sağlar. (C++11)
   ```cpp
   ClassName& operator=(ClassName&& other) noexcept;
   ```

### Neden Kullanılır?

C++’da bir sınıfın kaynak yönetimi (bellek, dosya, soket gibi dış kaynaklar) söz konusu olduğunda, kaynakların düzgünce serbest bırakılması ve taşınması önemlidir. Bu formların kullanım nedenleri şunlardır:

1.	Bellek sızıntılarını önlemek: Eğer bir sınıf dinamik belleğe sahipse (örneğin, new ile ayrılan bellek), doğru bir yıkıcı (destructor) tanımlanmazsa bu bellek serbest bırakılmadan kaybolabilir.
2.	Kopyalama ve atama hatalarını önlemek: Eğer bir nesnenin bir başka nesne ile kopyalanması veya ona atanması gerektiğinde doğru kopya yapıcı veya kopya atama operatörü tanımlanmazsa, kopyalama sırasında derin kopya yerine yüzeysel kopya olabilir. Bu durum bellek sızıntılarına veya aynı belleğe birden fazla gösterici tarafından erişilmesi gibi sorunlara yol açabilir.
3.	Verimli taşınabilirlik: C++11 ile gelen taşıma yapıcısı ve taşıma atama operatörü, büyük nesnelerin kopyalanması yerine daha verimli bir şekilde kaynakların “taşınmasını” sağlar. Bu sayede, özellikle dinamik belleğe sahip nesneler taşınırken kopyalama yerine kaynak taşınır ve performans iyileştirilir.

### Rule of Three / Rule of Five / Rule of Zero

- **Rule of Three (Üç Kuralı):** Eğer bir sınıfta yıkıcı, kopya yapıcı, veya kopya atama operatörü gerekiyorsa, diğer ikisinin de tanımlanması gerektiğini söyler.
- **Rule of Five (Beş Kuralı):** C++11 ile gelen taşıma yapıcısı ve taşıma atama operatörü de eklenerek, eğer birini tanımlıyorsanız, hepsini tanımlamanız gerektiğini söyler.
- **Rule of Zero (Sıfır Kuralı):** Eğer sınıf kaynak yönetimi yapmıyorsa, hiçbir özel üye fonksiyonu tanımlamayın ve varsayılan olanları kullanın.

<br></br>

## Floating Point Numbers (Kayan Noktalı Sayılar)

### Floating Point Sayı Nedir?

C++’de floating point sayılar (floating-point numbers), virgülden sonra da değer alabilen, kesirli sayıları temsil eden veri türleridir. Genellikle bilimsel ve finansal hesaplamalar gibi hassas hesaplamalar için kullanılırlar. Floating point sayılar, taban (mantissa), üs (exponent) ve işaret biti olmak üzere üç bileşenden oluşur. Bu sayede çok geniş bir aralıkta sayısal değerler temsil edilebilir.

C++’de floating point sayıları temsil eden üç temel veri türü vardır:

1.	float: Tek duyarlıklı floating point sayı, genellikle 4 byte yer kaplar ve yaklaşık 7 basamak hassasiyete sahiptir.

	```cpp
	float a = 3.14f;
	```

2.	double: Çift duyarlıklı floating point sayı, genellikle 8 byte yer kaplar ve yaklaşık 15 basamak hassasiyete sahiptir.

	```cpp
	double b = 3.141592653589793;
	```

3.	long double: Daha yüksek hassasiyet gerektiren hesaplamalar için kullanılır, sistemden sisteme değişen boyutlarda olabilir. Genellikle 10 byte veya daha fazla yer kaplayabilir.

	```cpp
	long double c = 3.14159265358979323846L;
	```

Bu veri türleri ondalık değerler içerebilir ve matematiksel işlemler için kullanılabilir. Örneğin:

```cpp
float x = 1.5f;
double y = 2.3;
double result = x + y;
```
Hassasiyet gerektiren işlemlerde double kullanmak genellikle tercih edilir.

### Avantajları

- Çok geniş bir sayı aralığında değerler temsil edilebilir (çok büyük ya da çok küçük sayılar).
- Ondalıklı sayılar için uygundur.

### Dezavantajları

- Sayısal doğruluk sınırlıdır; bu nedenle küçük sayısal hatalar oluşabilir (örneğin, 0.1 + 0.2 tam olarak 0.3 değil).
- İşlemler diğer veri tiplerine göre daha yavaştır çünkü sayıların normalize edilmesi gibi ekstra işlemler gerektirir.

### Ne Zaman Kullanılır?

Floating point sayılar ise, geniş sayı aralıklarıyla çalışmayı gerektiren bilimsel hesaplamalar, finansal işlemler ve genel amaçlı matematiksel problemler için kullanılır. Çünkü daha büyük doğruluk ve dinamik aralık sağlar.

<br></br>

## Fixed Point Numbers (Sabit Noktalı Sayılar)

### Fixed Point Sayılar Nedir?

Fixed-point sayılar, ondalıklı sayıları temsil etmenin daha basit ama sınırlı bir yoludur. Hareketli virgül yerine, sabit bir ondalık nokta pozisyonu kullanılarak sayılar temsil edilir. Bu sayede belli bir aralıkta sabit doğrulukla sayılar temsil edilebilir. C++’da standart olarak sabit virgüllü bir veri tipi yoktur, ancak genellikle tamsayı veri tipleri (int, short, long) kullanılarak sabit virgüllü hesaplamalar elle uygulanır.

Sabit virgüllü sayılarda, belirli bir bölüm tamsayı ve diğer bir bölüm ondalıklı kısmı temsil eder. Örneğin, 16 bitlik bir fixed point sayı formatında ilk 8 bit tamsayı kısmı, son 8 bit ise kesirli kısmı temsil edebilir.

### Avantajları

- Daha az bellek ve işlemci kaynağı kullanır.
- Floating point sayılara göre daha basit bir hesaplama gerektirir.
- Daha hızlıdır çünkü hareketli virgüllü sayılardaki gibi normalize işlemleri gerekmez.
- Sabit bir sayısal doğruluk sağlar, dolayısıyla sayısal hatalar çok daha azdır.
- Özellikle gömülü sistemlerde ve donanıma yakın programlamada kullanılır (örn. mikrodenetleyicilerde).

### Dezavantajları

- Sayı aralığı ve hassasiyet sınırlıdır.
- Daha düşük esneklik sunar, çünkü ondalık noktanın pozisyonu sabittir ve büyük veya küçük sayılar üzerinde çalışmak zor olabilir.

### Ne Zaman Kullanılır?

Fixed-point sayılar, genellikle sınırlı donanım kaynaklarıyla çalışan gömülü sistemlerde ve hassasiyetin çok önemli olduğu uygulamalarda kullanılır. Örneğin, bir sensörden okunan analog sinyalleri dijitalleştirirken sabit virgüllü sayı kullanmak mantıklı olabilir.

<br></br>

## Karşılaştırmalar

### Floating Point vs Integers

Floating point sayılar ve tam sayılarla yapılan karşılaştırmalarda, veri tiplerinin doğruluğu ve hassasiyeti önemlidir. Floating point sayılar, tam sayılara göre belirli bir doğrulukla saklanırken, yuvarlama hataları meydana gelebilir. Aşağıdaki tablo, floating point sayılar ve tam sayılar arasındaki karşılaştırmaları yer alır.

| Veri Tipi   | Tam Sayı mı? | Floating Point Sayı mı? | Doğruluk (Precision) | Hassasiyet (Accuracy) |
|-------------|--------------|-------------------------|----------------------|-----------------------|
| int		  | Evet         | Hayır                   | Yüksek               | Yüksek                |
| long		  | Evet         | Hayır                   | Yüksek               | Yüksek                |
| float		  | Hayır        | Evet                    | Düşük                | Orta                  |
| double	  | Hayır        | Evet                    | Orta                 | Yüksek                |
| long double | Hayır        | Evet                    | Yüksek               | Çok Yüksek            |

Açıklamalar:

 • **Doğruluk (Precision):** Bir sayının, bellek içinde ne kadar hassas saklandığını belirtir. Floating point sayılar bu konuda yuvarlama hatalarıyla karşılaşabilir. float, en düşük doğruluğa sahipken, long double en yüksek doğruluğu sağlar.

 • **Hassasiyet (Accuracy):** Gerçek değere ne kadar yakın olduğunun bir ölçüsüdür. Tam sayılar genellikle hassasiyeti en yüksek veri tipleridir çünkü kesin değerler kullanırlar. Floating point sayılar yuvarlama hataları sebebiyle daha düşük hassasiyete sahip olabilirler, ancak double ve long double gibi veri tipleri yüksek hassasiyet sağlar.

Tam sayılar genellikle daha yüksek doğruluk ve hassasiyet sunarken, floating point sayılar işlem aralığını genişletir, ancak yuvarlama hataları yüzünden hassasiyet ve doğrulukta düşüş olabilir.

### Floating Point vs Fixed Point

Floating-point ve fixed-point veri türleri, sayısal hesaplamalarda yaygın olarak kullanılır ve her ikisinin de avantajları ve dezavantajları vardır.

**1. Virgülün Konumu**

- **Fixed-Point:** Virgül sabittir ve sayı tamsayı ve ondalık kısımlar olarak ayrılır. Örneğin, 16 bitlik bir sayıda 8 bit tamsayı, 8 bit kesirli kısmı temsil edebilir. Sabit bir doğruluk sağlar.
	> Örnek: 00001111.11110000 -> 15 + 0.9375.
- **Floating-Point:** Virgül kayabilir ve sayı mantissa ve üs ile temsil edilir, geniş bir dinamik aralık sunar. IEEE 754 standardına göre 32 bitlik bir sayı, 1 bit işaret, 8 bit üs ve 23 bit mantissa içerir.
	> Örnek: 1.23456789 × 10^4 -> 12345.6789.

**2. Dinamik Aralık**

- **Fixed-Point:** Sabit bir aralığa sahiptir. Temsil edebileceği sayı aralığı, kullanılan bit sayısına bağlıdır.
	> Örnek: 16 bitlik fixed-point sayılar -32768 ile 32767 arasında değer alabilir.
- **Floating-Point:** Çok geniş bir aralığı destekler. Üs sayesinde küçük ve büyük sayılar temsil edilebilir.
	> Örnek: IEEE 754 ile -10^38 ile +10^38 aralığında sayılar depolanabilir.

**3. Hassasiyet**

- **Fixed-Point:** Sabit hassasiyet sunar, sayılar sabit bir doğrulukla temsil edilir. Ancak büyük sayılarda doğruluk kaybı olabilir.
- **Floating-Point:** Dinamik bir hassasiyete sahiptir. Büyük sayılar için doğruluk azalabilir, ancak küçük sayılarda yüksek hassasiyet sağlar.

**4. Hesaplama Hızı ve Karmaşıklığı**

- **Fixed-Point:** Daha basit ve hızlıdır, çünkü işlemler tamsayı aritmetiğine dayanır.
- **Floating-Point:** Daha karmaşıktır ve daha fazla işlemci gücü gerektirir. Modern işlemcilerde donanım desteği (FPU) ile hızlandırılabilir.

**5. Kullanım Alanları**

- **Fixed-Point:** Kaynakların sınırlı olduğu gömülü sistemlerde, kontrol sistemlerinde ve dijital sinyal işleme gibi alanlarda tercih edilir. Bellek ve hız açısından avantaj sağlar.
- **Floating-Point:** Bilimsel hesaplamalar, grafik işlemleri ve finansal analiz gibi geniş dinamik aralık ve yüksek hassasiyet gerektiren uygulamalarda kullanılır.

#### Sonuç

Floating-point, geniş sayı aralıklarında yüksek doğruluk sağlarken, fixed-point hız ve bellek tasarrufu açısından daha avantajlıdır. Uygulamanızın gereksinimlerine göre doğru veri türünü seçmek önemlidir.

| Özellik           | Floating-Point                            | Fixed-Point                                    |
|-------------------|-------------------------------------------|------------------------------------------------|
| Virgülün Konumu   | Kayar virgül (mantissa ve üs)             | Sabit virgül (tamsayı ve kesirli kısım)        |
| Dinamik Aralık    | Çok geniş aralık (10^-38 ile 10^38)       | Sınırlı aralık (-32768 ile 32767, 16 bit için) |
| Hassasiyet        | Dinamik (küçük sayılarda daha yüksek)     | Sabit doğruluk                                 |
| Hesaplama Hızı    | Daha yavaş (FPU ile hızlandırılabilir)    | Daha hızlı, tamsayı aritmetiği kullanır        |
| Kullanım Alanları | Bilimsel, grafik ve finansal hesaplamalar | Gömülü sistemler, dijital sinyal işleme        |

<br></br>

## `roundf` fonksiyonu

C++’de `roundf` fonksiyonu, float veri türündeki bir sayıyı en yakın tam sayıya yuvarlamak için kullanılır. Bu fonksiyon cmath (veya math.h) kütüphanesinde tanımlıdır ve özellikle float veri tipinde çalışmak üzere optimize edilmiştir. İşlev olarak, IEEE 754 standardına göre **kayan noktalı sayıları** en yakın tam sayıya yuvarlar.

### `roundf` Fonksiyonunun Söz Dizimi ve Kullanımı

```cpp
#include <cmath>

float roundf(float x);
```

- Parametreler
  - x: Yuvarlanmak istenen float türünde sayı.

- Dönüş Değeri
  - `roundf` fonksiyonu, x değerini en yakın tam sayıya yuvarlanmış olarak döndürür, ancak dönüş türü yine float’tır.

### `roundf` Fonksiyonunun Çalışma Mantığı

roundf, tam yarıya denk gelen sayıları (örneğin 2.5, -3.5) ***“en yakın çift tam sayıya”*** yuvarlar. Bu strateji ***“bankers’ rounding”*** olarak bilinir ve yuvarlama hatalarını minimize etmeye yardımcı olur.

| x Değeri | ``roundf`(x)` Sonucu | Açıklama.                                          |
|----------|--------------------|----------------------------------------------------|
| 2.3      | 2.0                | 2.3 en yakın tam sayı olan 2’ye yuvarlanır.        |
| 2.5      | 2.0                | 2.5 en yakın çift tam sayı olan 2’ye yuvarlanır.   |
| 3.5      | 4.0                | 3.5 en yakın çift tam sayı olan 4’e yuvarlanır.    |
| -2.3     | -2.0               | -2.3 en yakın tam sayı olan -2’ye yuvarlanır.      |
| -2.5     | -2.0               | -2.5 en yakın çift tam sayı olan -2’ye yuvarlanır. |
| -3.5     | -4.0               | -3.5 en yakın çift tam sayı olan -4’e yuvarlanır.  |


### Yuvarlama Kuralı**

- **En yakın tam sayıya yuvarlama:** `roundf`, en yakın tam sayıya yuvarlama yapar.
- **Eğer tam yarıya denkse çift tam sayıya yuvarlar:** Bu özellik yuvarlama hatalarını minimize etmeyi amaçlar. Örneğin, 0.5, 1.5 gibi tam yarım değerlere denk gelen sayılar, en yakın çift tam sayıya yuvarlanır. Bu, özellikle tekrarlanan toplama işlemlerinde veya istatistiksel hesaplamalarda yuvarlama hatalarını azaltır.


	```cpp
	#include <iostream>
	#include <cmath>

	int main()
	{
		float num1 = 2.3f;
		float num2 = 2.5f;
		float num3 = 3.5f;
		float num4 = -2.3f;
		float num5 = -2.5f;
		float num6 = -3.5f;

		std::cout << "roundf(2.3)  = " << roundf(num1) << std::endl;
		std::cout << "roundf(2.5)  = " << roundf(num2) << std::endl;
		std::cout << "roundf(3.5)  = " << roundf(num3) << std::endl;
		std::cout << "roundf(-2.3) = " << roundf(num4) << std::endl;
		std::cout << "roundf(-2.5) = " << roundf(num5) << std::endl;
		std::cout << "roundf(-3.5) = " << roundf(num6) << std::endl;

		return 0;
	}
	```

	Örnek Çıktı:
	```r
	roundf(2.3)  = 2
	roundf(2.5)  = 2
	roundf(3.5)  = 4
	roundf(-2.3) = -2
	roundf(-2.5) = -2
	roundf(-3.5) = -4
	```

### `roundf` ile Diğer Yuvarlama Fonksiyonları Arasındaki Farklar

C++’da `roundf` dışında ceil, floor, ve trunc gibi diğer yuvarlama fonksiyonları da bulunur. İşte bunlar arasındaki farklar:

- `ceil(x)`: Her zaman yukarı yuvarlar.
  - `ceil(2.3)` = 3
  - `ceil(-2.3)` = -2
- `floor(x)`: Her zaman aşağı yuvarlar.
  - `floor(2.3)` = 2
  - `floor(-2.3)` = -3
- `trunc(x)`: Ondalık kısmı keserek tam sayı kısmını alır.
  - `trunc(2.7)` = 2
  - `trunc(-2.7)` = -2

`roundf`, en yakın tam sayıya yuvarlayarak ondalık hassasiyeti kaybetmeden en doğru sonucu sağlar ve yuvarlama hatalarının azaltılmasına katkıda bulunur.

<br></br>

## `std::ostream` Sınıfı

`std::ostream`, C++‘da çıktı akışı (output stream) için kullanılan bir sınıftır ve C++ Standart Kütüphanesi’nde tanımlıdır. Bu sınıf, karakter tabanlı verilerin çeşitli çıktı cihazlarına (örneğin, konsol, dosya veya ağ bağlantısı) gönderilmesini sağlar. `std::ostream`, `iostream` başlık dosyasında tanımlanır ve `std::cout` gibi standart çıktı nesneleriyle kullanılır.

1. `std::ostream` Sınıfının Genel Yapısı

`std::ostream` sınıfı, C++’da veri akışı kavramını desteklemek için tasarlanmıştır. Akış (stream), bir veri kaynağından verilerin sürekli ve sıralı olarak alınıp bir hedefe yönlendirilmesini ifade eder. `std::ostream`, verileri karakter karakter veya belirli veri türlerine göre biçimlendirilmiş halde çıktıya iletebilir.

2. Kullanım: `std::cout` --> Hatırlatma ! <--

En bilinen `std::ostream` nesnesi olan `std::cout`, konsola (standart çıktıya) veri göndermek için kullanılır:

```cpp
#include <iostream>

int main()
{
    std::cout << "Merhaba, dünya!" << std::endl;
    return 0;
}
```

Yukarıdaki kodda, `std::cout`, `std::ostream` sınıfının bir nesnesidir ve `<<` operatörü ile `"Merhaba, dünya!"` ifadesini konsola yazar. `std::endl`, satır sonu karakteridir ve ayrıca çıktı tamponunu (buffer) boşaltır.

3. `std::ostream` Operatörleri

`std::ostream`, `<<` operatörünün aşırı yüklenmiş haliyle bilinir. Bu operatör, veri türüne göre otomatik olarak uygun işleme tabi tutar.

Örneğin:
```cpp
int sayi = 42;
double kesirliSayi = 3.14;

std::string metin = "Merhaba";

std::cout << sayi << " " << kesirliSayi << " " << metin << std::endl;
```

Bu örnekte, `std::ostream::operator<<` fonksiyonu farklı veri türleri için uygun aşırı yüklemeleri çağırarak verileri çıktı akışına yönlendirir.

4. `std::ostream` ve Akış Durumları

`std::ostream`, bir akışın durumu hakkında bilgi edinmek için bazı durum bayraklarına sahiptir.

Örneğin:

- `good()`: Akış düzgün çalışıyorsa `true` döner.
- `fail()`: Akışta bir hata oluştuysa `true` döner (örn. geçersiz veri türü girişi).
- `bad()`: Akış ciddi bir hata yaşadıysa `true` döner (örn. akışın kapanması).
- `eof()`: Akışın sonuna ulaşıldıysa `true` döner.

Örneğin, bir dosyaya yazma işlemi sırasında bu bayrakları kullanarak yazma işleminin başarısını kontrol edebilirsiniz.

5. `std::ostream`’i Özel Türler için Kullanma   ***--> !! Detaylı Anlatım için Aşağıya İnin !! <--***

`std::ostream`, **sınıfları** veya **kullanıcı tanımlı veri türlerini** yazmak için de kullanılabilir. Bu durumda, `operator<<` işlevini **kendi sınıfınız için** aşırı yüklemeniz gerekir:

```cpp
#include <iostream>

class Nokta
{
	public:
		int x, y;
		Nokta(int x, int y) : x(x), y(y) {}

		// "operator<<" fonksiyonunu aşırı yükleyerek `Nokta` türü için çıktı tanımlıyoruz.
		std::ostream &operator<<(std::ostream &os, const Nokta &n)
		{
			os << "(" << n.x << ", " << n.y << ")";
			return os;
		}
};

int main()
{
	Nokta n(10, 20);

	std::cout << n << std::endl; // "(10, 20)" olarak çıktılar

	return 0;
}
```

Bu örnekte, `operator<<` aşırı yüklemesi Nokta nesnesinin içeriğini biçimlendirilmiş şekilde konsola yazdırır.

6. `std::ostream` Sınıfında Biçimlendirme Manipülatörleri

`std::ostream`, çıktıyı daha okunabilir veya belirli bir düzende biçimlendirmek için manipülatörler sağlar:

- `std::endl`: Yeni satıra geçer ve tamponu boşaltır.
- `std::hex` / `std::dec` / `std::oct`: Sayıları sırasıyla onaltılık, ondalık ve sekizlik olarak yazar.
- `std::setw`: Çıktı genişliğini ayarlar.
- `std::setprecision`: Kayan noktalı sayılar için gösterilecek hassasiyeti ayarlar.

Örneğin:

```cpp
#include <iostream>
#include <iomanip>

int main()
{
	double pi = 3.1415926535;

	std::cout << "Pi: " << std::setprecision(4) << pi << std::endl;	// Pi: 3.142

	return 0;
}
```

### `std::ostream` Sınıfında `operator` Aşırı Yüklemesi

C++ dilinde **operatör aşırı yüklemesi (operator overloading)**, sınıflar için standart operatörlerin (örneğin +, -, *, = gibi) işleyişini değiştirme veya özelleştirme imkanı sağlar. Bu sayede kullanıcı tanımlı sınıflar üzerinde matematiksel, mantıksal veya diğer operatörleri uygularken, bu operatörlerin doğal bir kullanım sunması mümkün olur.

Örneğin, bir `Complex` sınıfınız olduğunu düşünelim; bu sınıf karmaşık sayıları temsil etsin. `+ operatörünü` aşırı yükleyerek iki karmaşık sayının toplama işlemini gerçekleştirebiliriz. Böylece `c1 + c2` ifadesi, karmaşık sayıların toplama işlemini gerçekleştirir.

#### Operatör Aşırı Yüklemesi Nasıl Yapılır?

Operatör aşırı yükleme, `operator` anahtar kelimesi ve ***aşırı yüklemek istediğimiz operatörle*** gerçekleştirilir.

```cpp
#include <iostream>
#include <string>

class Kitap
{
	private:
		std::string ad;

	public:
		Kitap(const std::string &isim) : ad(isim) {}

		// Kitap adını döndüren bir "getter" işlevi
		std::string getAd() const
		{
			return ad;
		}
};

// << operatörünün sınıf dışı aşırı yüklenmesi
// operator<< işlevini tanımladık. Bu işlev Kitap sınıfını std::cout ile doğrudan yazdırmak için kullanılır.

// * İşlevin İmzası:
// 		•	std::ostream& operator<<(std::ostream &os, const Kitap &kitap)
// 		•	os: Çıktıyı tutan std::ostream nesnesi (genelde std::cout olarak kullanılır).
// 		•	kitap: Kitap sınıfından bir nesneyi referans olarak alır. const yaparak değiştirilemez hale getirdik.
// * İşlevin gövdesinde os << "Kitap Adı: " << kitap.getAd(); ile ad değerini getAd() işlevi aracılığıyla alıyoruz ve os çıktısına ekliyoruz.
// * return os; ile std::ostream nesnesini döndürerek << operatörünün zincirleme kullanılmasına olanak tanıyoruz (örneğin, std::cout << k1 << k2 gibi).
std::ostream& operator<<(std::ostream &os, const Kitap &kitap)
{
	os << "Kitap Adı: " << kitap.getAd();
	return os;
}

int main()
{
	Kitap k("Savaş ve Barış");

	// 	•	std::cout << k << std::endl; ile k nesnesini doğrudan yazdırıyoruz.
	// 	•	Bu noktada << operatörünün aşırı yüklenmiş versiyonu devreye giriyor:
	//			•	operator<< işlevi çağrılıyor ve os << "Kitap Adı: " << kitap.getAd(); ifadesi çalışıyor.
	//			•	"Kitap Adı: Savaş ve Barış" ifadesi std::cout ile ekrana yazdırılıyor.
	//	•	İşlev, std::ostream referansını (os) döndürdüğü için std::endl ile birlikte zincirleme kullanım yapılabiliyor ve çıktı akışı düzgün tamamlanıyor.

	std::cout << k << std::endl; // "Kitap Adı: Savaş ve Barış" çıktısını verir

	return 0;
}
```

Bu örnekte:

1. Getter İşlevi: Kitap sınıfında getAd() adlı bir işlev ekledik. Bu işlev ad değerini döndürür ve ad’a doğrudan erişime ihtiyaç bırakmaz.
2. Sınıf Dışı Operatör Aşırı Yükleme: operator<< işlevi sınıf dışında tanımlanmıştır. Kitap nesnesinin ad değerine erişmek için getAd() işlevi kullanılmıştır.
3. Çıktı: Bu işlev Kitap nesnesini doğrudan yazdırmamıza olanak sağlar, böylece "Kitap Adı: Savaş ve Barış" çıktısını alırız.

#### Operatör Aşırı Yüklenmenin Çağırıldığını Nasıl Anlarız?

Bir önceki başlıkta yer alan "Kitap" örneğinden örnek vererk ilerleyelim.

`<<` operatörünün aşırı yüklenmiş versiyonunun çağrıldığını birkaç nedenden dolayı anlıyoruz. Bunlar:

* **std::cout << k; İfadesiyle Kapsamlı Arama**

	Kodda `std::cout << k;` ifadesini yazdığımızda, C++ derleyicisi önce standart `<<` operatörünün (`ostream` için tanımlı olan) bu durumda uygun olup olmadığını kontrol eder. Ancak `Kitap` sınıfı `std::ostream` ile doğrudan yazdırılamayacağı için (çünkü `std::ostream` Kitap sınıfını tanımaz), derleyici aşırı yüklenmiş bir `<<` operatörünü aramaya başlar.

* **operator<< İşlevinin Tanımlanması**

	Kodda `operator<<` işlevini Kitap sınıfı ile özel olarak aşırı yüklediğimiz için, derleyici `std::ostream` ile `Kitap` sınıfının nasıl yazdırılacağını bu işlevden anlar:

	`std::ostream& operator<<(std::ostream &os, const Kitap &kitap)`

	Bu işlevin amacı Kitap nesnesini `std::cout` veya başka bir `std::ostream` nesnesine doğrudan yazdırabilmektir. İşlevin ilk parametresi bir `std::ostream referansı (os)` olduğundan, derleyici `std::cout << k;` ifadesinde `std::cout` ile birlikte kullanılacak uygun bir `operator<<` işlevi olarak bu aşırı yüklenmiş versiyonu bulur ve kullanır.

* **Aşırı Yüklenmiş İşlevin Parametre Uyumu**

	Aşırı yüklenmiş `operator<<` işlevi `std::ostream&` türünde bir referans ve `Kitap` sınıfının sabit bir referansını (`const Kitap&`) parametre olarak alır. `std::cout << k;` ifadesindeki `std::cout` bir `std::ostream` nesnesi olduğundan ve k de bir Kitap nesnesi olduğundan, bu işlev parametre uyumu sağlar. Dolayısıyla, `operator<<` ifadesinin bu versiyonu geçerli kabul edilir ve çağrılır.

* **İşlevin Çalışma Şekli**

	Bu işlev çalıştırıldığında `os << "Kitap Adı: " << kitap.getAd();` satırında `os` nesnesine `"Kitap Adı: "` ve `kitap.getAd()` değeri eklenir. Bu, `<<` operatörünün `std::ostream` için özel olarak tanımlanmış davranışıdır ve `os` (bu durumda `std::cout`) ile ekrana yazdırılır.

* **Örnek Olarak Başka Bir Durum**

	Eğer bu operatör aşırı yüklenmiş olmasaydı, yani `operator<<` işlevini tanımlamamış olsaydık, derleyici `std::cout << k;` ifadesiyle Kitap nesnesini doğrudan yazdırmayı nasıl yapacağını bilemez ve şu gibi bir hata verirdi:

	`error: no match for 'operator<<' in 'std::cout << k'`

	Bu hata, `<<` operatörünün `Kitap` nesnesi için aşırı yüklenmiş bir versiyonu olmadığı durumlarda ortaya çıkar. Ancak, `operator<<` işlevini tanımlayarak `Kitap` sınıfını `std::cout` ile uyumlu hale getirdiğimiz için bu hata oluşmaz ve `<<` operatörünün aşırı yüklenmiş versiyonunun kullanıldığını biliriz.

#### Operatör Aşırı Yüklemenin Avantajları

- **Anlaşılır Kod:** Operatör aşırı yükleme, kodun doğal ve anlaşılır bir yapıda yazılmasına olanak tanır.
- **Kullanıcı Tanımlı Tiplerle Kolay Kullanım:** Sınıflarla matematiksel ve mantıksal işlemleri kolayca yapabilirsiniz.

#### Dikkat Edilmesi Gerekenler

- Her operatör aşırı yüklenemez (örneğin ::, .*, . ve ?: operatörleri).
- Anlam kaybı olmaması için aşırı yüklemeyi mantıklı bir şekilde kullanmak önemlidir.

<br></br>

## Polimorfizm

C++’de polimorfizm, bir nesnenin veya bir işlevin farklı türlerdeki veri veya nesnelerle aynı arayüzü kullanarak farklı şekillerde davranmasını sağlayan bir programlama kavramıdır. Bu, C++’da özellikle nesne yönelimli programlamanın temel özelliklerinden biridir ve yazılımda esneklik, genişletilebilirlik ve kod yeniden kullanılabilirliği sağlar.

C++’da polimorfizm iki ana türe ayrılır:

**1. Çalışma Zamanı (Runtime) Polimorfizmi**

Çalışma zamanı polimorfizmi, program çalışırken hangi işlevin çağrılacağını belirler. C++’da bu tür polimorfizm genellikle **sanal işlevler (virtual functions)** ile gerçekleştirilir. Bu, genellikle **taban sınıf (base class)** ve **türetilmiş sınıflar (derived class)** arasında bir ilişki gerektirir.

- **Sanal İşlevler ve Sanal Tablolar:** Çalışma zamanı polimorfizmi için taban sınıfta sanal bir işlev tanımlanır ve türetilmiş sınıflarda bu işlevler kendi sınıflarına uygun şekilde yeniden tanımlanır (override edilir). C++’da bu özellik, sanal işlev tablosu (vtable) aracılığıyla gerçekleştirilir.
  - Örnek:
	```cpp
	#include <iostream>

	class Hayvan
	{
		public:
			virtual void sesCikar() const { // Sanal işlev
				std::cout << "Bilinmeyen bir ses!" << std::endl;
			}
	};

	class Kedi : public Hayvan
	{
		public:
			void sesCikar() const override { // Yeniden tanımlama
				std::cout << "Miyav!" << std::endl;
			}
	};

	class Kopek : public Hayvan
	{
		public:
			void sesCikar() const override { // Yeniden tanımlama
				std::cout << "Hav!" << std::endl;
			}
	};

	int main()
	{
		Hayvan* h1 = new Kedi(); // Taban sınıf işaretçisi, türetilmiş sınıfa işaret eder
		Hayvan* h2 = new Kopek();

		h1->sesCikar(); // Çıktı: Miyav!
		h2->sesCikar(); // Çıktı: Hav!

		delete h1;
		delete h2;
		return 0;
	}
	```
  - Bu örnekte:
    - Hayvan taban sınıfında sesCikar adlı sanal bir işlev tanımlandı.
    - Kedi ve Kopek sınıfları Hayvan sınıfından türedi ve kendi sesCikar işlevlerini yeniden tanımladı.
    - Program çalışırken sesCikar işlevi çağrıldığında, hangi sınıfın sesCikar işlevinin çalıştırılacağına karar verilir. Taban sınıf işaretçisi hangi türetilmiş sınıfı işaret ediyorsa o sınıfın sesCikar işlevi çalıştırılır.

**2. Derleme Zamanı (Compile Time) Polimorfizmi**

Derleme zamanı polimorfizmi, derleme sırasında hangi işlevin veya işlemin kullanılacağının belirlenmesidir. Fonksiyon **aşırı yükleme (function overloading)** ve **şablonlar (templates)** ile sağlanır.

- **Fonksiyon Aşırı Yükleme:** Aynı isme sahip birden fazla fonksiyonun farklı parametre türleri veya sayıları ile tanımlanmasıdır.
	```cpp
	#include <iostream>

	void yaz(int x)
	{
		std::cout << "int: " << x << std::endl;
	}

	void yaz(double x)
	{
		std::cout << "double: " << x << std::endl;
	}

	int main()
	{
		yaz(10);     // int sürümünü çağırır
		yaz(3.14);   // double sürümünü çağırır
		return 0;
	}
	```
- **Şablonlar (Templates):** Aynı işlevin veya sınıfın farklı türlerle çalışabilmesi için tanımlanmasıdır.
	```cpp
	#include <iostream>

	template <typename T>
	T kare(T sayi)
	{
		return sayi * sayi;
	}

	int main()
	{
		std::cout << "kare(5): " << kare(5) << std::endl;       // int olarak çağırır
		std::cout << "kare(3.14): " << kare(3.14) << std::endl; // double olarak çağırır
		return 0;
	}
	```

- **Derleme Zamanı Polimorfizminin Özellikleri**
	- **Hızlıdır:** Derleme zamanı polimorfizmi çalışma zamanında değil, derleme esnasında çözülür
	- **Esneklik:** Kodun aynı fonksiyon ile birden fazla türde çalışabilmesine olanak tanır.

- **Polimorfizmin Avantajları**
	- **Esneklik ve Genişletilebilirlik:** Aynı arayüz ile farklı davranışlar tanımlanabilir, bu da kodun genişletilebilirliğini artırır.
	- **Bakım Kolaylığı:** Polimorfizm ile tek bir arayüz altında birçok sınıf için ortak bir davranış belirlenebilir, böylece kod bakımı kolaylaşır.

<br></br>
