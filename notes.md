# minitalk Projesi Notları
<br></br>

# İçerik
- [Executable dosya nedir?](#executable-dosya-nedir)
- [PID (Process Identifier - Süreç Tanımlayıcı) nedir?](#pid-process-identifier---süreç-tanımlayıcı-nedir)
	- [PID'ler nasıl oluşmaktadır?](#pidler-nasıl-oluşmaktadır)
- [SIGUSR1 ve SIGUSR2 nedir?](#sigusr1-ve-sigusr2-nedir)
- [Binary sisteminde operatörlerin kullanımı](#binary-sisteminde-operatörlerin-kullanımı)
	- [AND ( `&` ) Operatörü](#and----operatörü)
	- [OR ( `|` ) Operatörü](#or----operatörü)
	- [NOT ( `~` ) Operatörü](#not----operatörü)
	- [Bit kaydırma (Shift) nedir?](#bit-kaydırma-shift-nedir)
		- [Sağa kaydırma (Right Shift - `>>`)](#sağa-kaydırma-right-shift---)
		- [Sola kaydırma (Left Shift - `<<`)](#sola-kaydırma-left-shift---)
- [Bit maskeleme nedir?](#bit-maskeleme-nedir)
- [`data << i & 0b10000000` ifadesinin açıklaması](#data--i--0b10000000-ifadesinin-açıklaması)
- [`kill` fonksiyonunda `PID` girilmezse ne olur?](#kill-fonksiyonunda-pid-girilmezse-ne-olur)
- [Projenin örnek ile birlikte baştan sona açıklaması](#projenin-örnek-ile-birlikte-baştan-sona-açıklaması)
- [Kullanılması serbest fonksiyonlar ve açıklamaları](#kullanılması-serbest-fonksiyonlar-ve-açıklamaları)
	- [1. `write`](#1-write)
	- [2. `ft_printf`](#2-ft_printf)
	- [3. `signal`](#3-signal)
	- [4. `sigemptyset`](#4-sigemptyset)
	- [5. `sigaddset`](#5-sigaddset)
	- [6. `sigaction`](#6-sigaction)
	- [7. `kill`](#7-kill)
	- [8. `getpid`](#8-getpid)
	- [9. `malloc`](#9-malloc)
	- [10. `free`](#10-free)
	- [11. `pause`](#11-pause)
	- [12. `sleep`](#12-sleep)
	- [13. `usleep`](#13-usleep)
	- [14. `exit`](#14-exit)

<br></br>

# Executable dosya nedir?
Executable dosya, bir bilgisayar programının çalıştırılabilir bir kopyasıdır. Bu dosyalar, bir bilgisayarın işlemcisinin anlayabileceği makine kodundan oluşur.
<br></br>
Executable dosyalar, bir bilgisayarın işletim sistemi tarafından başlatılır. İşletim sistemi, dosyanın makine kodunu işler ve bilgisayarın donanımına talimatlar gönderir. Bu talimatlar, programın kullanıcı arayüzü, işlevleri ve diğer özelliklerini çalıştırır.
<br></br>
Executable dosyalar, çeşitli amaçlar için kullanılabilir. Örneğin, bilgisayar oyunları, uygulamalar, araçlar ve sistem yazılımları gibi programları çalıştırmak için kullanılırlar.
<br></br>
Farklı işetim sistemine göre executable dosya uzantıları değişmektedir. İşletim sistemlerinde kullanılan yaygın executable dosya uzantıları:

* Windows: .exe , .bat
* MacOS: .app
* Linux: .sh
* Android: .apk
<br></br>

Executable dosyalar, bilgisayar sisteminin güvenliği için bir risk oluşturabilir. Kötü amaçlı yazılımlar, executable dosyaların içine gizlenebilir ve kullanıcıların bilgisayarlarına zarar verebilir. Bu nedenle, executable dosyaları indirmeden önce dikkatli olunmalıdır.

Executable dosyaları çalıştırmak için, genellikle bir dosya gezgini veya komut satırı kullanılarak bilgisayarın işletim sistemine sunulur. İşletim sistemi, dosyanın dosya uzantısını kontrol ederek dosyanın executable olup olmadığını belirler. Dosya executable ise, işletim sistemi dosyanın makine kodunu işler ve programın başlatılmasına izin verir.

<br></br>

# PID (Process Identifier - Süreç Tanımlayıcı) nedir?
PID, **"Process ID"** veya **"Process Identifier"** kelimelerinin kısaltmasıdır ve bir işletim sistemi sürecinin benzersiz tanımlayıcısıdır. Her çalışan program veya işlem, işletim sistemi tarafından bir PID ile tanımlanır. PID, işletim sistemi tarafından kullanılan bir tam sayıdır ve genellikle süreçlerin yönetimi, kontrolü ve izlenmesi için kullanılır.

Her PID, sistemde çalışan herhangi bir işlem veya program için benzersiz olmalıdır. Yani iki farklı işlem aynı PID'yi kullanamaz. PID'ler işletim sistemi tarafından otomatik olarak atanır ve her işlem başladığında yeni bir PID alır. Bir işlem sona erdiğinde, o PID yeniden kullanılabilir hale gelir.

PID'lerin işletim sistemi görevlerinde kullanım alanları:
- işletim sistemi kaynaklarını izlemek
- işlemleri sonlandırmak
- işlem hata ayıklamak
- işlemi yönlendirmek

Her işlem, işletim sistemi tarafından kendi PID'siyle izlenir ve bu, işletim sisteminin çoklu görev yönetimi için kritik bir bileşeni oluşturur.

<br></br>

## PID'ler nasıl oluşmaktadır?

PID'ler rastgele oluşturulmaz, bunun yerine işletim sistemi tarafından belirli kurallara göre atanır. Her yeni süreç, bir üst süreçten miras alınan bir PID'ye sahip olur ve bu PID'ler genellikle ardışık olarak artar. Bu nedenle PID'ler rastgele değildir ve süreçlerin yönetimi ve tanımlanması için kullanılır. PID'lerin nasıl oluşturulduğu işletim sistemine ve kullanılan algoritmaya bağlı olarak değişebilir, ancak genellikle aşağıdaki şekillerde oluşturulur:

- `Sıralı PID Ataması:` Birçok işletim sistemi, süreçleri başlatırken PID'leri sıralı olarak atar. İlk süreç (genellikle init veya systemd gibi sistem başlatma süreçleri) genellikle PID 1 alır ve ardışık olarak artan PID'ler diğer süreçlere atanır. Yani, bir sürecin PID'si bir önceki sürecin PID'sinin bir artı değeridir.
- `Döngüsel PID Ataması:` Bazı işletim sistemleri, belirli bir sınırın üzerine çıktığında PID'yi sıfırlayan veya başka bir değere geri dönen bir döngüsel PID atama yöntemi kullanır. Bu, PID'nin aşırı büyümesini önlemek için kullanılabilir.
- `Rastgele PID Ataması:` Bazı modern işletim sistemleri, rastgele PID atamasını destekleyebilir. Ancak, bu rastgelelik, belirli bir PID aralığı içinde gerçekleşir ve genellikle sürecin özel bir PID talep etmesiyle tetiklenir.

PID'ler, bir sürecin işletim sistemi tarafından tanımlandığı ve yönetildiği bir sistemde benzersiz bir kimlik sağlamak amacıyla kullanılır. Bu nedenle, her PID yalnızca bir sürece atanır ve PID'ler tekrar kullanılmaz. Yani bir süreç sona erdiğinde veya sonlandırıldığında, bu PID daha sonra başka bir sürece atanabilir. Bu, süreçlerin izlenmesi, tanımlanması ve yönetilmesi için kritik bir öneme sahiptir.

<br></br>

# SIGUSR1 ve SIGUSR2 nedir?
`SIGUSR1` ve `SIGUSR2`, Unix tabanlı işletim sistemlerinde kullanıcı tanımlı sinyal türlerini temsil eder. Bu sinyal türleri, sistem tarafından özel işlevlerle ilişkilendirilmemiş, kullanıcı tarafından kendi uygulamalarında tanımlanabilen sinyal türleridir. Bu sinyaller, özellikle işlem iletişimi ve işlem kontrolü için kullanışlıdır.

* `SIGUSR1` (User Signal 1): Genellikle, bu sinyal özel bir görevin veya işlemin başlatılması için kullanılır.
* `SIGUSR2` (User Signal 2): Bu sinyal, farklı bir özel görevi veya işlemi başlatmak veya kontrol etmek için kullanılabilir. SIGUSR2 genellikle SIGUSR1 ile benzer kullanım alanlarına sahiptir ve kullanıcı tarafından tanımlanan işlevlerin tetiklenmesi için kullanılır.

SIGUSR1 ve SIGUSR2 sinyalleri 1 veya 0 sinyali göndermez. Sadece iletim gerçekleşir. Bu sinyallere anlamlar yükleyebilen kodlardır. Örnek olarak: SIGUSR1 sinyali tetiklendiğinde 1 biti gelmiş olsun, SIGUSR2 sinyali tetiklendiğinde ise 0 biti gelmiş olsun diye kodda veri işlemesi yapılabilir.

Bu sinyaller, özellikle kullanıcı tarafından belirli işlemlerin yönetilmesi ve iletişimi için kullanışlıdır. Uygulama geliştiricileri bu sinyalleri kendi yazılımlarında belirli görevleri gerçekleştirmek için özelleştirebilirler.

Bu sinyaller, işletim sistemi tarafından yönetilen ve yazılım yoluyla tetiklenen yazılım düzeyinde olaylardır. Bu sinyaller, işletim sistemi düzeyinde yazılım tarafından oluşturulur ve işletim sistemi içindeki işlemciler tarafından işlenir. Özel bir işlem yapmak için yazılım tarafından kullanılan sinyallerdir.

SIGUSR1 ve SIGUSR2 sinyalleri, işletim sistemi içinde süreçler arasında iletişim sağlamak ve özel işlemleri başlatmak için kullanılır. Örneğin, bir süreç diğer bir sürece bir sinyal göndererek, belirli bir eylemi gerçekleştirmesini sağlayabilir. Bu sinyaller, yazılım düzeyinde işletim sistemi tarafından yönetilir.

<br></br>

# Binary sisteminde operatörlerin kullanımı
| Operatör              | Açıklama                                 |
| ---                   | ---                                      |
| **AND (&)**           | İki değişkenin karşılık gelen bitleri birbiriyle AND işlemine tabi tutulur. Sonuç olarak, her iki değişkenin de 1 olduğu bitler 1 olur, diğer bitler ise 0 olur. |
|**OR**                 | İki değişkenin karşılık gelen bitleri birbiriyle OR işlemine tabi tutulur. Sonuç olarak, en az bir değişkenin 1 olduğu bitler 1 olur, diğer bitler ise 0 olur.    |
|**NOT (~)**            | Bir değişkenin tüm bitlerinin değeri tersine çevrilir. 1'ler 0 olur, 0'lar 1 olur. |
|**Sola kaydırma (<<)** | Bir değişkenin her bir biti sola doğru bir birim kaydırılır. Sonuç olarak, en soldaki bit kaydırma miktarı kadar kaybolur.                                   |
|**Sağa kaydırma (>>)** | Bir değişkenin her bir biti sağa doğru bir birim kaydırılır. Sonuç olarak, en sağdaki bit kaydırma miktarı kadar kaybolur.                                   |

<br></br>

## AND ( `&` ) Operatörü

**`&`** operatörü, iki değişkenin karşılık gelen bitlerini birbiriyle **AND** işlemine tabi tutar. **AND** işleminde, iki bitin 1 olması durumunda sonuç 1 olur. Aksi halde sonuç 0 olur.

**Örnek:**

```c
int a = 10;		// 1010
int b = 15;		// 1111

int c = a & b;	// 1010
```

Bu örnekte, `a` değişkeni 10 değerine, `b` değişkeni ise 15 değerine ayarlanır. `c` değişkeni, `a` ve `b` değişkenlerinin **AND** işlemine tabi tutularak elde edilir. Sonuç olarak, `c` değişkeninin değeri 10 olur.

<br></br>

## OR ( `|` ) Operatörü

**`|`** operatörü, iki değişkenin karşılık gelen bitlerini birbiriyle **OR** işlemine tabi tutar. **OR** işleminde, iki bitten en az birinin 1 olması durumunda sonuç 1 olur. Aksi halde sonuç 0 olur.

**Örnek:**

```c
int a = 10;		// 1010
int b = 15;		// 1111

int c = a | b;	// 1111
```

Bu örnekte, `a` değişkeni 10 değerine, `b` değişkeni ise 15 değerine ayarlanır. `c` değişkeni, `a` ve `b` değişkenlerinin **OR** işlemine tabi tutularak elde edilir. Sonuç olarak, `c` değişkeninin değeri 15 olur.

<br></br>

## NOT ( `~` ) Operatörü

**`~`** operatörü, bir değişkenin tüm bitlerinin değerini tersine çevirir. 1'ler 0 olur, 0'lar 1 olur.

**Örnek:**

```c
int a = 10;		// 1010
int b = ~a;		// 0101
```

Bu örnekte, `a` değişkeni 10 değerine ayarlanır. `b` değişkeni, `a` değişkeninin NOT işlemine tabi tutularak elde edilir. Sonuç olarak, `b` değişkeninin değeri 5 olur.

<br></br>

## Bit kaydırma (Shift) nedir?
Bit kaydırma, bir sayının bitlerini sağa veya sola doğru kaydırmak için kullanılan bir işlemdir. Sağa kaydırma, sayının değerini azaltırken, sola kaydırma sayının değerini artırır.

Bit kaydırma operatörleri:
-  kaydırılacak sayı
-  kaydırma miktarı (0 ile sayının bit sayısı arasında bir tam sayı)

<br></br>

### Sağa kaydırma (Right Shift - `>>`)
Sağa kaydırma operatörü (>>), bir sayının her bir bitini sağa doğru bir birim kaydırır.Kaydırma miktarı, operatörün sağındaki operand tarafından belirtilir.

Örnek: Sayı 1101'yi (13 ondalık olarak) sağa 1 pozisyon kaydırdığınızda, sonuç 0110 (6 ondalık olarak) olur.
Yazılımsal gösterimi:
```c
int a = 13;		// 1101		a = 13
int b = a >> 1;	// 0110		b = 6
```
Bu örnekte, a değişkeni 13 değerine ayarlanır. b değişkeni, a değişkeninin sağa 1 birim kaydırılmış değerine ayarlanır. Bu işlem, a değişkeninin değerini 6'ya düşürür.

Sağa kaydırma işlemi, bir sayıdaki tüm bitleri belirtilen sayıda pozisyon sağa kaydırmayı içerir. Kaydırma işlemi, kaydırılan bitlerin sağ tarafına sıfır ekler. Kaydırılan bitler kaybolur.

Sağa kaydırma işlemi, tamsayıların bölünmesi veya 2'nin üssü olan sayıları bölmek için kullanılabilir.

<br></br>

### Sola kaydırma (Left Shift - `<<`)
Sola kaydırma operatörü (<<), bir sayının her bir bitini sola doğru bir birim kaydırır. Kaydırma miktarı, operatörün sağındaki operand tarafından belirtilir.


Örnek: Sayı 1101'yi (13 ondalık olarak) sola 2 pozisyon kaydırdığınızda, sonuç 0100 (4 ondalık olarak) olur.
Yazılımsal gösterimi:
```c
int a = 13;		// 1101		a = 13
int b = a << 2;	// 0100		b = 4
```
Bu örnekte, a değişkeni 13 değerine ayarlanır. b değişkeni, a değişkeninin sola 2 birim kaydırılmış değerine ayarlanır.

Sola kaydırma işlemi, bir sayıdaki tüm bitleri belirtilen sayıda pozisyon sola kaydırmayı içerir. Kaydırma işlemi, kaydırılan bitlerin sol tarafına sıfır ekler. Kaydırılan bitler kaybolur.

<br></br>

# Bit maskeleme nedir?
Bit maskeleme (bit masking), özellikle bit düzeyinde işlem yapmak için kullanılan bir tekniktir. Bu teknik, belirli bitleri veya bit gruplarını ayıklamak, kontrol etmek veya değiştirmek amacıyla kullanılır. Bit maskeleme, özellikle veri işleme, işlemciler arası iletişim ve donanım düzenlemeleri gibi birçok uygulamada kullanışlıdır.

Bit maskeleme işlemi adımları:

* `Bir bit maskesi oluşturmak:` İlk adım, belirli bir işlemi gerçekleştirmek istediğiniz bitleri temsil eden bir **"bit maskesi"** oluşturmaktır. Bit maskesi, belirli bitlerin değerlerini korurken diğerlerini "0" yapar.
  Örneğin, belirli bir biti kontrol etmek için 0b10000000 (128) gibi bir bit maskesi oluşturabilirsiniz. Bu maske, yalnızca en sol taraftaki biti (en yüksek sıradaki bit) kontrol etmenize yardımcı olur.
* `Bit maskesiyle işlem yapmak:` Oluşturduğunuz bit maskesini hedef veriye (örneğin, bir bayt veya bir kelime) uygularsınız. Bu, bitwise "ve (&)" veya bitwise "veya (|)" operatörleri kullanılarak yapılır. Bit maskeleme işlemi, verinin belirli bitlerini kontrol etmek veya belirli bir değeri korumak için kullanılabilir.
* `Sonuçları değerlendirmek:` Bit maskesini hedef veriye uyguladıktan sonra, sonucu inceleyerek istediğiniz bitlerin durumunu belirleyebilirsiniz. Bu işlem sonucunda, belirli bitler 1 veya 0 olarak belirlenir.

Bit maskeleme, özellikle veri işleme, veri paketleme ve ayrıştırma, sıkıştırma ve işlemciler arası iletişim gibi uygulamalarda kullanışlıdır. Aynı zamanda donanım sürücülerinin yazılması ve düşük seviye işlemlerin gerçekleştirilmesi sırasında da yaygın olarak kullanılır.

<br></br>

# `data << i & 0b10000000` ifadesinin açıklaması

`data << i & 0b10000000` ifadesi, C programlama dilinde kullanılan bit düzeyinde işlem operatörlerini kullanarak veriyi bit bit işler. İfade aşağıdaki gibi adım adım açıklanabilir:

* `data << i`: data değişkeni, i kadar sola bit kaydırılır. Burada i, bir döngü içerisinde 0 ile 7 arasında bir değer alır çünkü i döngünün bir sayacıdır ve her bir biti işlemek için kullanılır. Yani, data değişkeninin bitleri sırayla kontrol etmek için sola kaydırılır.

  Örnek: Eğer data 00001101 ise ve i 2 ise, `data << i` işlemi sonucunda 00110100 elde edilir.

* `& 0b10000000`: Burada `&` operatörü, bitwise (bit düzeyinde) "ve" işlemi yapar. Yani, `data << i` sonucu ile 0b10000000 arasında her bir bitin karşılıklı "ve" işlemi uygulanır. Bu işlem, yalnızca belirli bir bitin kontrol edilmesini sağlar.

  Örnek: Eğer `data << i` sonucu 00110100 ve 0b10000000 (128) ile "ve" işlemi yapılırsa sonuç 00000000 olur. Eğer `data << i` sonucu 10110100 ve 0b10000000 (128) ile "ve" işlemi yapılırsa sonuç 10000000 olur.

Sonuç olarak, `data << i & 0b10000000` ifadesi, data değişkeninin belirli bir bitini kontrol etmek için kullanılır. Her bir döngü adımında, data değişkeni sola kaydırılır ve 0b10000000 ile "ve" işlemine tabi tutulur. Bu işlem, belirli bir bitin 1 veya 0 olup olmadığını kontrol etmek için kullanılır.

<br></br>

# `kill` fonksiyonunda `PID` girilmezse ne olur?

`kill(pid, SIGUSR1)` ifadesi, UNIX tabanlı işletim sistemlerinde kullanılan bir sistem çağrısıdır. Bu ifade, belirli bir işlemi hedef alarak belirli bir sinyal gönderme amacını taşır.

Açıklamalar:
* `kill`: Bir işlemi hedef alarak sinyal göndermeyi sağlayan sistem çağrısı.
* `pid`: Hedef alınacak işlemin PID'sini (Process ID) belirtir. PID, hedef işlemi benzersiz bir şekilde tanımlar.
* `SIGUSR1`: Gönderilecek sinyali belirtir. Bu durumda SIGUSR1 sinyali gönderilir. Bu sinyal, özel bir anlam taşımaz ve projenin tasarımına bağlı olarak kullanılır.

Eğer PID belirtilmezse (yani `kill(SIGUSR1)` olarak kullanılırsa), sistem, sinyali mevcut işlemi yani kodu çalıştıran işlemi hedef alır. Bu, genellikle kendi işlem içinde sinyal gönderme amacıyla kullanılır. Ancak, bu kod parçası istemci tarafından kullanıldığında, istemcinin sunucu işlemini hedef alması gerektiği için belirli bir sunucu PID'si gereklidir.

Bu nedenle PID parametresi belirtilmezse, kod hedef işlemi belirleyemez ve işlem başarısız olur. İstemcinin, sunucu PID'sini bilmesi ve bu PID'yi `kill` fonksiyonuna ileterek sunucuyu hedef alması gerekir.

<br></br>

# Projenin örnek ile birlikte baştan sona açıklaması

1. Terminale `make` yazın. Bu, bütün dosyaların derlemesi gerçekleştirilir.
2. Dosyalar derlendikten sonra `server` ve `client` adında (dosya uzantısı olmadan) iki tane dosya oluşur. Bu dosyalar, `server.c` ve `client.c` dosyalarından oluşturulmaktadır. Detaylı bakmak için makefile dosyasını inceleyebilirsiniz.
3. Terminale `./server` yazın. Burada derlenmiş `server.c` dosyasını çalıştırmış oluyoruz. Çıktı olarak bize `server` dosyasının PID'sini verecektir. Önek üzerinden gittiğimiz için terminalin PID olarak `1212` çıktısını verdiğini varsayalım. Peki, bu PID nasıl elde ediliyor:
   * Adım 1: `server.c` dosyasındaki `int main(void)` kısmını inceliyoruz. Çünkü dosyadaki ana döngünün başladığı yer orasıdır.
   * Adım 2: `getpid()` komutu ile dosyasının PID'sine erişiyoruz.
   * Adım 3: Bu PID, sayısal bir değerdir. Bu yüzden ekrana yazdırmak için `ft_putnbr` fonksiyonunu kullanıyoruz. Bu fonksiyona `minitalk_utils.c` dosyasından ulaşabilirsiniz. Böylelikle PID'yi ekrana yazdırmış oluyoruz.
4. Başka bir terminal açıp oraya `./client <PID numarası> <gönderilecek string>` 'i yazıyoruz. Örnek üzerinden gittiğimiz için bu kod satırına `./client 1212 "ab"` yazdığımızı varsayalım. `Enter` tuşuna bastıktan sonra arka planda gerçekleşen adımlara beraber bakalım:
   * Adım 1: `./client` dosyasını çalıştırdığımız için `client.c` dosyasının kodlarına gidin ve `int main(int ac, char **av)` kısmına bakın. `client.c` dosyasının argüman aldığını göreceksiniz. Alınan argümanlardan birisi PID numarası, diğeri ise `server` 'ın terminaline yazdırmak istediğimiz string/mesajdır.
   * Adım 2: Yeterli sayıda argüman girilip girilmediğini kontrol ediyoruz. Girilmediyse `ft_putstr` ile yazılan hata mesajları, `./client` dosyasını çalıştırdığımız terminal ekranına hata mesajı olarak iletilecektir. `ft_putstr` fonksiyonuna `minitalk_utils.c` doyasından ulaşabilirsiniz.
   * Adım 3: Argüman sayısının yeterli yani 3 olduğu zaman `server` 'ın çalıştırıldığı terminale mesajı iletebilmesi adına gerçekleştirmesi gereken işlemleri vardır.
   * Adım 4: Alınan ilk argüman PID numarısıdır. Fakat argüman olarak alındığı için string şeklindedir. PID'yi sayıya çevirmek için `ft_atoi` fonksiyonunu kullanıyoruz. `ft_atoi` fonksiyonuna `minitalk_utils.c` dosyasından erişebilirsiniz.
   * Adım 5: Her karakter teker teker `server` 'ın terminaline çıktı olarak iletileceği için bu karakterlerin veri işlemesini başka bir fonksiyonda gerçekleştirme kararı aldım. Bütün karakterleri tek tek `data_transmission` fonksiyonuna göndererek veri gönderimini gerçekleştirebiliyorum.
   * Adım 6: İkinci argüman olarak `abc` stringi girildiğinden ve başta `i = 0` olduğundan `a` karakterini `data_transmission` fonksiyonuna gönderiyorum. Ayriyeten PID numarasını da `data_transmission` fonksiyonuna gönderiyorum. PID numarasını gönderme sebebim ise `a` karakteri işlendikten sonra diğer terminale o an aktarımı gerekmektedir ve bu veri gönderimini ortak bir PID üzerinden gerçekleştirebilmekteyiz. Neden o an iletimin gerçekleşmesi gerektiği ilerleyen adımlarda açıklanmıştır.
   * Adım 7: Karakterler bellekte 1 byte'lık alan kaplar, yani 8 bitlik bir alandır bu. Bu yüzden `i` 'yi 0'dan başlatıp `while` döngüsünün koşulunda 8'e kadar ilerlettik. Bu döngüyü detaylı inceleyelim:
     * `if` koşulunda yer alan koşulu detaylı inceleyelim.
     * İlk olarak `data = 'a'` 'dır. `a` karakteri ASCII tabloda 97 sayısına denk düşmektedir. Bu 97 sayısını veri işlemesi için binary'ye çevirdiğimizde `01100001` sonucunu elde ederiz.
     * `data << i` karşılaştırılması artık `01100001 << 0` karşılaştırmasına dönmüş olur. Bu da demek oluyor ki `01100001` sayısını `0` bit sola kaydır, yani kaydırma yapma.
     * `0b10000000` bu ifade de `0b` kısmı, bu sayının binary sayı olduğunu göstermektedir. Karşılatırmayı `10000000` yapma nedenimiz ise bit kaydırma olarak sola kaydırma yapıyoruz. Bu da demek oluyor ki 1 bit bile sola kaydığında en soldaki sayı yok olacak. Yok olmadan önce sayıyı işliyoruz, ardından sola kaydırarak yok ediyoruz.
     * Ardından `01100001 & 0b10000000` ifadesini karşılaştıracağız. Bu ifade de 1.basamaktaki sayı 1.basamaktaki sayı ile karşılaştırılarak devam eder. Bunun sonucunda cevap `00000000` olur. Yani 0'dır.
     * Sonuç sıfır olduğu için `else` 'e gidilir ve oradaki işlem gerçekleştirilir.
     * `kill(pid, SIGUSR2)` komutu çalıştırılmış olunur. Bu komut şunu ifade etmektedir, hedef alınacak işlem olarak `server` 'ın PID'sini girerek SIGUSR2 sinyalini `server.c` kodunda tetiklemiş oluyoruz. `server.c` kod dosyasında SIGUSR2 sinyali algılandığında biti 0 olarak `c` karakterine kaydeder. Bu kısmın detaylarına değineceğiz, şimdilik döngüyü anlayalım.
     * `kill` fonksiyonunun return ettiği iki farklı değer var. Başarılı olması durumunda 0, başarısız olması durumunda -1. Başarısız olursa `error` değeri -1, başarılı olursa `error` değeri 0 olur.
     * Ardından `i` 'yi 1 artırıyoruz. `i = 1` oluyor. `usleep(250)` diyerekte 250 mikrosaniye bekleyerek veri çakışmasını önlüyoruz. Bu mikrosaniyeyi değiştirebilirsiniz. Tekrardan döngü başa dönüyor.
     * Bu sefer tekrardan `if` koşuna geldiğimizde `data << i` karşılaştırılması artık `01100001 << 1` oluyor. Bu da demek oluyor ki `01100001` sayısını `1` bit sola kaydır demek, yani `11000010` sayısını elde ediyoruz.
     * `11000010 & 0b10000000` ifadesinin karşılatırmasını yapıyoruz. Bunun sonucunda cevap `10000000` olur. Yani 0'dır. İki sayıda da en yüksek bit (en soldaki bit) 1 olduğundan sonuç 1 olur. Bu durum aslında verinin en yüksek bitini maskelemektir.
     * Koşulun sonucu 1 olduğundan `kill(pid, SIGUSR1)` kod satırı çalıştırılır. Bu seferde `server` dosyasının PIS'sini girmiş olduğumuzdan `server.c` dosyasında SIGUSR1 sinyali tetiklenmiş olur.
     * Ardından `i` tekrardan 1 artırılır. Bu sefer `i = 3` olur ve döngü tekrar başa sararak bu şekilde devam eder. Taki `i = 8` olana kadar. `i = 8` olduğunda döngüdeki koşul artık sağlanmayacağından döngüden çıkılır.
     * Bir sonraki `if` koşuluna gelindiğinde ise `error` değerin `kill` fonksiyonundan dolayı -1 ise hata mesajı `client` 'ı çalıştırdığımız terminalde görüntülenir.
   * Adım 8: SIGUSR1 ve SIGUSR2 sinyalleri ve PID ile `server.c` kod dosyasının tetiklendiğini söyledik. `server.c` dosyasında `int main(void)` içerisinde `signal(SIGUSR1, handler)` ve `signal(SIGUSR2, handler)` kod satırlarını göreceksiniz. SIGUSR1 ve SIGUSR2 sinyalleri tetiklendiğinde bu `signal` komutu ile tetiklendikleri anlaşılır. Burada yer alan kod, SIGUSR1 ve SIGUSR2 sinyali tetiklendiğinde `handler` fonksiyonunu çalıştıracağını söylemektedir. Sinyaller tetiklendiği için `handler` fonksiyonunu inceleyelim.
   * Adım 9: `handler` fonksiyonu, fonksiyon girdiisi olarak sinyal ismi alır. `client.c` dosyasındayken ve `i = 0` iken SIGUSR2 sinyali tetiklenmişti ilk olarak. Bu yüzden ilkin bu fonksiyona `signal` değişkeni olarak SIGUSR2 atanacaktır. Fonksiyon detayları şu şekildedir:
     * `i`, her çağrıda gelen sinyalin kaçıncı bit olduğunu izlemek için kullanılır. `static int i` olarak tanımlamamızın nedeni ise, bu değişkenin değeri `handler` işlevi her çağrıldığında sıfırlanmaz ve doğru sayım yapılabilir. Eğer `i` static olarak tanımlanmazsa, her çağrıda sıfırlanır ve doğru sayım yapılamaz.
     * `c`, gelen sinyalleri bit bit işleyerek karakterlere dönüştüren bir işlemde kullanılır. Her yeni sinyal alındığında, `c` değişkeni uygun şekilde güncellenir. Eğer `c` static olarak tanımlanmazsa, her `handler` çağrısında `c` sıfırlanır ve karakterlerin doğru şekilde bir araya gelmesi engellenir. static olarak tanımlandığında, `c` bir çağrıdan diğerine korunur ve veriler doğru şekilde birleştirilir.
     * `signal` olarak SIGUSR2 alındığından `else if` koşuluna girilir. `c = (c << 1)` işlemi gerçekleştirilir. `c` ve `i` 'nin başlangıç değerleri tanımlanmadığından otomatik olarak 0 (sıfır) atanır. Ama `c` karakterini bit bit işlediğimizden dolayı bit şeklinde yazıyoruz `c` 'yi, zaten arka planda da bu şekilde işlemler yürümektedir. Bu durumda işlem şu şekilde olmaktadır `c = (00000000 << 1)`. Bu da `00000000` bitini 1 bit sola kaydır demektir. Yani `c` değeri `00000000` iken, `0000000` olur. Yani değişmez.
     * `i` bir artırılır ve `i = 1` olur. Bu tetiklemede başka iş kalmamıştır.
     * Hatırlanacağı üzere SIGUSR2'den sonra SIGUSR1 tetiklenmişti. `signal(SIGUSR1, handler)` komutu SIGUSR1 sinyalinin tetiklendiğini anlayıp `handler` fonksiyonuna yönlendirir. Bu sefer `signal = SIGUSR1` olur.
     * 1.`if` koşulu sağlandığından, o koşula girilir ve `c = (c << 1) | 1` işlemi gerçekleştirilir. `c` dediğim en son `00000000` idi. Kod satırını düzenlediğimizde `c = (00000000 << 1) | 1` elde edilir. `0000000` bir bit sola kaydırıldığında `00000000` olur. `c = 00000000 | 1` işlemi, `c = 00000000 | 00000001` şeklindedir. Yani, son biti 1 ile toplarız. Böylelikle yeni `c` değerimiz `00000001` olur.
     * Ardından `i` bir artırılır ve `i = 2` olur. İşlemler SIGUSR1 ve SIGUSR2 tetiklendiği, program sonlandırılmadığı ve karakterlerin yazdırılması bitene kadar devam eder.
     * Bu işlemlerde de görüldüğü üzere SIGUSR1 sinyali tetiklendiğinde 1 biti, SIGUSR2 sinyali tetiklendiğinde ise 0 bitinin karaktere yazdırıldığını görmekteyiz. Yani, businyallerin kazandığı anlamları kendimiz belirlemiş oluyoruz.
     * `i = 8` olduğunda `c` karakterinin bellekte kaplayacağı yer dolacağından dolayı `c` karakteri, yani `a` yazdırılır. Başka karakterin yazdırılması için `i` ve `c` değişkenleri sıfırlanır.
     * `a` karakteri yazdırıldıktan sonra `client.c` dosyasındaki `int main(int ac, char **av)` kısmına geri gidilir, string'teki bir sonraki karakteri yazdırmak için gerekli olan `while` döngüsünde `i` 1 artırılarak bu sefer `b` karakteri için aynı işlemler gerçekleştirilir.
5. `server.c` dosyasında `int main(void)` kısmında yer alan `pause()` komutu sayesinde programın bitirilmemesi sağlanır. Böylelikle `./sever` komutunu çalıştırdığımız terminal, birden fazla `./client <PID numarası> <gönderilecek string>` fonksiyonunu `client` 'ın çalıştığı terminale yazdığımızda kapanmamış olmaktadır. Birden fazla kez string girip `server` terminaline yazdırabilmekteyiz.

<br></br>

# Kullanılması serbest fonksiyonlar ve açıklamaları

|Fonksiyon İsmi|Fonksiyon Açıklaması|
|---|---|
|write|bir karakter dizisini veya veriyi bir dosyaya veya bir standart çıkışa yazar|
|ft_printf|printf fonksiyonunun bir eşdeğeridir|
|signal|bir sinyal yakalamak için kullanılır|
|sigemptyset|bir sinyal maskesini boşaltır|
|sigaddset|bir sinyal maskesine bir sinyal ekler|
|sigaction|bir sinyal için işlemciyi ayarlamak için kullanılır|
|kill|bir işleme sinyal göndermek için kullanılır|
|getpid|geçerli işlemin kimliğini döndürür|
|malloc|bellekten bir blok tahsis etmek için kullanılır|
|free|önceden malloc ile tahsis edilmiş bir bellek bloğunu serbest bırakmak için kullanılır|
|pause|programın durdurulmasını sağlar|
|sleep|programın belirtilen süre boyunca durdurulmasını sağlar (saniye cinsinden)|
|usleep|programın belirtilen süre boyunca durdurulmasını sağlar (mikrosaniye cinsinden)|
|exit|programın sonlandırılmasını sağlar|

<br></br>

## 1. `write`

**Tanım:** `write` fonksiyonu, bir karakter dizisini veya veriyi bir dosyaya veya bir standart çıkışa yazar.

**İşlev yazımı:**
```c
int write(int fd, const void *buf, size_t count);
```

**Parametreler:**
* **fd:** Standart hata (0), standart çıkış (1), standart giriş (2) ve dosya (2'den büyük sayılar) değerlerini alır.
* **buf:** Yazılacak karakter dizisi veya veridir.
* **count:** Yazılacak karakter veya veri sayısıdır/byte sayısıdır.

**Dönüş değeri:**
* Başarılıysa, yazılan bayt sayısını döndürür.
* Hata durumunda, -1 döndürür ve errno değişkenini bir hata koduyla ayarlar.

**Örnek:**
```c
#include <unistd.h>

int main()
{
	char *str = "Merhaba, Dünya!";
	int len = strlen(str);

	write(1, str, len); // Standart çıktıya yazıyor

	return (0);
}
```

<br></br>

## 2. `ft_printf`

**Tanım:** `ft_printf`, printf fonksiyonunun bir eşdeğeridir. printf fonksiyonu gibi, formatlı metin yazdırmak için kullanılır.

**İşlev yazımı:**
```c
int ft_printf(const char *format, ...);
```

**Parametreler:**
* **format:** Yazılacak formatlı metin.
* **... :** Format'tan sonra alınacak sınırsız sayıda argüman olduğunu belirtir.

**Dönüş değeri:**
* Başarılıysa, yazılan bayt sayısını döndürür.
* Hata durumunda, -1 döndürür ve errno değişkenini bir hata koduyla ayarlar.

**Örnek:**
```c
#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int a = 12;
	char *str = "Merhaba, Dünya!";

	// printf fonksiyonunu kullanıyor
	printf("a = %d\n", a);

	// ft_printf fonksiyonunu kullanıyor
	ft_printf("a = %d\n", a);

	return (0);
}
```
<br></br>

## 3. `signal`

**Tanım:** `signal` fonksiyonu, bir sinyal yakalamak için kullanılır.

**İşlev yazımı:**
```c
void (*signal(int sig, void (*handler)(int)))(int);
```

**Parametreler:**
* **sig:** Yakalanacak sinyal.
* **handler:** Sinyal yakalandığında çağrılacak işlev.

**Dönüş değeri:**
* Eğer bir hata oluşursa (örneğin, belirtilen sinyal geçersizse veya işlem sinyali atanamazsa), signal işlemi `SIG_ERR` makro değerini döndürecektir. Bu durumda, işlem sinyali atanamadı ve hata kontrolü yapılmalıdır.
* Eğer işlem sinyali zaten ayarlıysa, signal işlemi önceki işlem sinyalini (önceki sinyal işlemcisini) döndürecektir.

**Örnek:**
```c
#include <signal.h>

void handler(int sig)
{
	// Sinyal yakalandığında yapılacak işlemler
}

int main()
{
	// SIGINT sinyalini yakalıyor ve handler'a (yapılacak işlemlere) gidiyor
	signal(SIGINT, handler);

	// İşlemci döngüsünü başlatıyor
	while (/* koşul */)
	{
		/* code */
	}

  return (0);
}
```

<br></br>

## 4. `sigemptyset`

**Tanım:** `sigemptyset` fonksiyonu, bir sinyal maskesini boşaltır.

**İşlev yazımı:**
```c
void sigemptyset(sigset_t *set);
```

**Parametreler:**
* **set:** Boşaltılacak sinyal maskesi.

**Dönüş değeri:**
* Yok.

**Örnek:**
```c
#include <signal.h>

int main()
{
	// Sinyal maskesini boşaltıyor
	sigemptyset(&sigmask);

	// code

	return (0);
}
```
<br></br>

## 5. `sigaddset`

**Tanım:** `sigaddset` fonksiyonu, bir sinyal maskesine bir sinyal ekler.

**İşlev yazımı:**
```c
void sigaddset(sigset_t *set, int sig);
```

**Parametreler:**
* **set:** Sinyal maskesi.
* **sig:** Eklenecek sinyal.

**Dönüş değeri:**
* Yok.

**Örnek:**
```c
#include <signal.h>

int main()
{
	// Sinyal maskesini boşaltıyor
	sigemptyset(&sigmask);

	// SIGINT sinyalini ekliyor
	sigaddset(&sigmask, SIGINT);

	// code

	return (0);
}
```
<br></br>

## 6. `sigaction`

**Tanım:** `sigaction` fonksiyonu, bir sinyal için işlemciyi ayarlamak için kullanılır.

**İşlev yazımı:**
```c
int sigaction(int sig, const struct sigaction *act, struct sigaction *oldact);
```

**Parametreler:**
* **sig:** İşlenecek sinyal.
* **act:** Yeni sinyal işlemcisi.
* **oldact:** Eski sinyal işlemcisi.

**Dönüş değeri:**
* Başarılıysa 0, başarısızsa -1 döndürür.

**Örnek:**
```c
#include <signal.h>

struct sigaction act;

int main()
{
	// Sinyal işlemcisini sıfırlıyor
	memset(&act, 0, sizeof(struct sigaction));

	// SIGINT sinyali için yeni bir işlemci ayarlıyor
	act.sa_handler = handler;

	// Sinyal işlemcisini ayarlıyor
	sigaction(SIGINT, &act, NULL);

	// ...

	return (0);
}

void handler(int sig)
{
	// Sinyal yakalandığında yapılacak işlemler
}
```
<br></br>

## 7. `kill`

**Tanım:** `kill` fonksiyonu, bir işleme sinyal göndermek için kullanılır.

**İşlev yazımı:**
```c
int kill(pid_t pid, int sig);
```

**Parametreler:**
* **pid:** Sinyal gönderilecek işlemin kimliği.
* **sig:** Gönderilecek sinyal.

**Dönüş değeri:**
* Başarılıysa 0, başarısızsa -1 döndürür.

**Örnek:**
```c
#include <signal.h>

int main()
{
	// 100 numaralı işleme SIGINT sinyali gönderiyor
	kill(100, SIGINT);

	return (0);
}
```

<br></br>

## 8. `getpid`

**Tanım:** `getpid` fonksiyonu, geçerli işlemin kimliğini döndürür.

**İşlev yazımı:**
```c
pid_t getpid(void);
```

**Parametreler:**
* Yok.

**Dönüş değeri:**
* Geçerli işlemin kimliği (çağıran işlemin PID'sini döndürür).

**Örnek:**
```c
#include <unistd.h>
#include <stdio.h>

int main()
{
	// Geçerli işlemin kimliğini yazdırıyor
	printf("PID: %d\n", getpid());

	return (0);
}
```

<br></br>

## 9. `malloc`

**Tanım:** `malloc` fonksiyonu, bellekten bir blok tahsis etmek için kullanılır.

**İşlev yazımı:**
```c
void *malloc(size_t size);
```

**Parametreler:**
* **size:** Tahsis edilecek bellek bloğunun boyutu.

**Dönüş değeri:**
* Başarılıysa tahsis edilen bellek bloğunun adresi, başarısızsa NULL döndürür.

**Örnek:**
```c
#include <stdlib.h>
#include <stdio.h>

int main()
{
	// 100 baytlık bir bellek bloğu tahsis ediyor
	void *ptr = malloc(100);

	// Bellek bloğunu yazdırıyor
	printf("ptr: %p\n", ptr);

	// Bellek bloğunu serbest bırakıyor
	free(ptr);

	return (0);
}
```

<br></br>

## 10. `free`

**Tanım:** `free` fonksiyonu, önceden malloc ile tahsis edilmiş bir bellek bloğunu serbest bırakmak için kullanılır.

**İşlev yazımı:**
```c
void free(void *ptr);
```

**Parametreler:**
* **ptr:** Serbest bırakılacak bellek bloğunun adresi.

**Dönüş değeri:**
* Yok.

**Örnek:**
```c
#include <stdlib.h>
#include <stdio.h>

int main()
{
	// 100 baytlık bir bellek bloğu tahsis ediyor
	void *ptr = malloc(100);

	// Bellek bloğunu yazdırıyor
	printf("ptr: %p\n", ptr);

	// Bellek bloğunu serbest bırakıyor
	free(ptr);

	return (0);
}
```
**Not:** `free` fonksiyonu, `malloc` ile tahsis edilmiş bir bellek bloğunu serbest bırakmak için kullanılır. Bu fonksiyonu kullanmadan önce, bellek bloğunun artık kullanılmadığını doğrulamak önemlidir. Aksi takdirde, bellek sızıntısı meydana gelebilir.

<br></br>

## 11. `pause`

**Tanım:** `pause` fonksiyonu, programın durdurulmasını sağlar.

**İşlev yazımı:**
```c
int pause(void);
```

**Parametreler:**
* Yok.

**Dönüş değeri:**
* Bir sinyal yakalandığında 0, yakalanmadığında -1 döndürür.

**Örnek:**
```c
#include <unistd.h>

int main()
{
	// Programı durduruyor
	pause();

	return (0);
}
```

<br></br>

## 12. `sleep`

**Tanım:** `sleep` fonksiyonu, programın belirtilen süre boyunca durdurulmasını sağlar.

**İşlev yazımı:**
```c
unsigned int sleep(unsigned int seconds);
```

**Parametreler:**
* **seconds:** Beklemesi gereken süre (saniye).

**Dönüş değeri:**
* Başarılıysa 0, başarısızsa -1 döndürür.

**Örnek:**
```c
#include <unistd.h>

int main()
{
	// 5 saniye bekliyor
	sleep(5);

	return (0);
}
```

<br></br>

## 13. `usleep`

**Tanım:** `usleep` fonksiyonu, programın belirtilen süre boyunca durdurulmasını sağlar.

**İşlev yazımı:**
```c
int usleep(useconds_t microseconds);
```

**Parametreler:**
* **microseconds:** Beklemesi gereken süre (mikrosaniye).

**Dönüş değeri:**
* Başarılıysa 0, başarısızsa -1 döndürür.

**Örnek:**
```c
#include <unistd.h>

int main()
{
	// 5000 mikrosaniye (0.005 saniye) bekliyor
	usleep(5000);

	return (0);
}
```

<br></br>

## 14. `exit`

**Tanım:** `exit` fonksiyonu, programın sonlandırılmasını sağlar.

**İşlev yazımı:**
```c
void exit(int status);
```

**Parametreler:**
* **status:** Çıkış kodu.
  * Çıkış kodu 0 ise ( `exit(0)` ): program normal bir şekilde sonlandı demektir.
  * Çıkış kodu 1 ise ( `exit(1)` ): program bir hata ile sonlandırıldı demektir.

**Dönüş değeri:**
* Yok.

**Örnek:**
```c
#include <stdlib.h>

int main()
{
	 // Programı 0 ile sonlandırıyor
	exit(0);

	// Bu kod asla çalıştırılmayacak
	printf("Merhaba, Dünya!");

	return (0);
}
```

<br></br>
