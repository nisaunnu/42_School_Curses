## FT_IRC PROJESİ
Bu rapo'da ft_irc projesinin kodları içermemektedir. Grup projesi olduğundan dolayı kod konulmamıştır. İlerleyen zamanlarda kodların repo'ya konulma ihtimali vardır. Şuanlık sadece projeyi yaparken gerekli olan bilgileri içeren README.md dosyası mevcuttur. 

## İçerik
- [Port Numarasının Alabileceği Değerler](#port-numarasının-alabileceği-değerler)
	- [Maksimum Port Numarası: 65535](#maksimum-port-numarası-65535)
	- [Port Aralığı Genel Olarak](#port-aralığı-genel-olarak)
	- [IRC İçin Yaygın Kullanılan Portlar:](#irc-i̇çin-yaygın-kullanılan-portlar)
- [Singleton Tasarım Deseni](#singleton-tasarım-deseni)
	- [Neden Singleton Deseni Kullanılır?](#neden-singleton-deseni-kullanılır)
	- [Yapısal Mantık](#yapısal-mantık)
	- [Parça Parça Açıklama](#parça-parça-açıklama)
	- [Singleton Örneği (Minimal)](#singleton-örneği-minimal)
	- [Avantajları](#avantajları)
	- [Dikkat Edilmesi Gerekenler](#dikkat-edilmesi-gerekenler)
- [Soket Programlama ve TCP/IP ile İstemci-Sunucu İletişimi](#soket-programlama-ve-tcpip-ile-i̇stemci-sunucu-i̇letişimi)
	- [TCP/IP Protokol Kümesi](#tcpip-protokol-kümesi)
		- [IP (Internet Protocol)](#ip-internet-protocol)
		- [TCP (Transmission Control Protocol)](#tcp-transmission-control-protocol)
		- [TCP/IP İletişimi ve Soketler](#tcpip-i̇letişimi-ve-soketler)
		- [Bağlantı Kurulumu: Three-Way Handshake](#bağlantı-kurulumu-three-way-handshake)
	- [IPv4 ve IPv6 ile TCP/IP İletişimi](#ipv4-ve-ipv6-ile-tcpip-i̇letişimi)
		- [IPv4 İletişimi](#ipv4-i̇letişimi)
		- [IPv6 İletişimi](#ipv6-i̇letişimi)
	- [Soket Nedir?](#soket-nedir)
		- [Temel Bileşenler](#temel-bileşenler)
		- [Soket Tipleri](#soket-tipleri)
	- [Soket Programlama Adımları](#soket-programlama-adımları)
		- [Sunucu Tarafı Adımları](#sunucu-tarafı-adımları)
		- [İstemci Tarafı Adımları](#i̇stemci-tarafı-adımları)
- [Fonksiyon Açıklamaları](#fonksiyon-açıklamaları)

<br></br>

## Port Numarasının Alabileceği Değerler
IRC (Internet Relay Chat) sunucusu başlatırken kullanılabilecek maksimum port numarası, IRC’ye özgü değil, genel olarak TCP/IP protokolü ile belirlenen bir sınırdır.

### Maksimum Port Numarası: 65535
Bu, 16 bitlik unsigned bir tam sayının (2¹⁶ - 1) alabileceği en büyük değerdir.

### Port Aralığı Genel Olarak

|Aralık	|Açıklama|
|---|---|
|0 - 1023| Sistem (well-known) portları — root izni gerekir (örn: 80, 443, 22)|
|1024 - 49151| Kayıtlı portlar — IRC genellikle bu aralıkta çalışır|
|49152 - 65535| Geçici (dynamic/private) portlar|


### IRC İçin Yaygın Kullanılan Portlar:
- 6667 → En yaygın IRC portudur.
- 6660–6669 → IRC sunucuları genellikle bu aralığı dinler.
- 6697 → TLS/SSL destekli IRC bağlantıları için yaygın port.

>📌 Not :
>
> Uygulamada bir port numarasını kullanabilmek için;
>- O portun başka bir işlem tarafından kullanılmıyor olması gerekir.
>- Eğer sistem portu (0–1023) kullanılacaksa genellikle root yetkisi gerekir.

<br></br>

## Singleton Tasarım Deseni
Singleton tasarım deseni, bir sınıfın sadece tek bir örneğinin (instance’ının) oluşturulmasını garanti altına alan ve bu örneğe küresel (global) bir erişim noktası sağlayan bir tasarım desenidir.

### Neden Singleton Deseni Kullanılır?
1. Tek bir nesneye ihtiyaç varsa (örn: bir sunucu, konfigürasyon yöneticisi, logger, veritabanı bağlantısı).
2. Tüm sistemde aynı nesneye erişmek gerekirse.
3. Global değişkenlerden daha kontrollü ve güvenli bir yol sağlamak için.

⸻

### Yapısal Mantık

Bir Singleton sınıf şu özelliklere sahiptir:
1. Private constructor               : Dışarıdan yeni nesne yaratılmasını engeller.
2. Statik bir örnek (instance)       : Sınıfın kendisine ait tek bir örneği.
3. Statik bir getInstance fonksiyonu : O örneği geri döner, gerekirse yaratır.

⸻

📦 Örneği Kodla Açıklayalım:
```cpp
class Server
{
	private:
		static Server instance;          // 🔁 Tek örnek (singleton instance)
		static bool _initialized;        // ✅ Bir kere mi başlatıldı kontrolü
		Server();                        // 🔒 Constructor private/protected yapılır genelde
	public:
		static Server& getInstance();    // 🔓 Global erişim noktası
};
```

### Parça Parça Açıklama
⸻⸻⸻⸻⸻

🔹 `static Server instance;`

Bu satır:
- Server sınıfının kendisinden sadece bir tane nesne oluşturur.
- Bu nesne `Server::instance` şeklinde erişilir.
- static olduğu için tüm uygulama boyunca bellekte tek bir kopyası olur.

⸻

🔹 `static Server& getInstance();`

```cpp
Server& Server::getInstance() { return instance; }
```

- getInstance() metodu bu instance’ı geri döner.
- Başka bir nesne oluşturmaya izin vermez.
- Bu sayede herkes aynı nesne üzerinden işlem yapar.

⸻

🔹 `Server::Server()` constructor’ı

```cpp
Server::Server() : _pass("default"), _port(0), _bot(NULL) {}
```

Bu constructor:
- Server nesnesi ilk (ve tek) defa oluşturulurken çağrılır.
- Private/protected olmalıdır ki, başka yerde new Server() gibi çağrılamasın.

Kodumda Server() public ama init() içinde tek bir kez kullanılmasına dikkat ediliyor. İdeal olan constructor’ı private yapmaktır.

⸻

🔹 `static bool _initialized`

```cpp
bool Server::_initialized = false;
```

Bu değişken:
- Sunucunun bir kere mi başlatıldığını kontrol eder.
- init() fonksiyonunun birden fazla çalışmasını engeller:

```cpp
void Server::init(...)
{
	if (_initialized)
	{
		std::cout << "Server is already running" << std::endl;
		return;
	}

	// Kod //

	_initialized = true;
}
```

⸻

### Singleton Örneği (Minimal)

```cpp
class Singleton
{
	private:
		static Singleton* instance;
		Singleton() {} // private constructor

	public:
		static Singleton* getInstance()
		{
			if (!instance)
				instance = new Singleton;
			return instance;
		}
};

Singleton* Singleton::instance = NULL;
```

Bu örnekte:
- İlk çağrıda instance oluşturulur.
- Sonraki çağrılar hep aynı nesneyi döner.

⸻

### Avantajları
- Tek bir global nesne ile yönetim sağlar.
- Global değişkenlere göre daha güvenlidir.
- Kaynak yönetimini kolaylaştırır (örneğin tek bir bağlantı havuzu).

⸻

### Dikkat Edilmesi Gerekenler
- Çoklu iş parçacığında (multithreading) özel önlem alınmazsa iki nesne oluşabilir.
- Aşırı kullanımı kodu “tanrısal nesne” haline getirebilir (her şeyi yapan dev nesne).
- Test etmesi zorlaşabilir (özellikle bağımlılıklar yüksekse).

<br></br>

## Soket Programlama ve TCP/IP ile İstemci-Sunucu İletişimi

Soket programlama, ağ üzerinden veri iletimi yapabilmek için kullanılan temel bir tekniktir. Ağ tabanlı uygulamaların temelinde, istemci ve sunucu arasında bilgi alışverişi yatmaktadır. Bu iletişimi gerçekleştirmek için TCP/IP protokolleri ve soketler birlikte kullanılır. Bu kısımda; soket programlamanın temel bileşenlerini, TCP/IP iletişiminin yapısını ve bir istemci-sunucu modelinin nasıl geliştirileceğini ayrıntılarıyla incelenmektedir.

<br>

### TCP/IP Protokol Kümesi

TCP/IP, internet ve bilgisayar ağlarında iletişimi sağlayan bir protokol ailesidir. İki temel bileşeni TCP (Transmission Control Protocol) ve IP (Internet Protocol)’dir.

#### IP (Internet Protocol)

IP, verilerin bir ağ üzerinden doğru hedefe yönlendirilmesini sağlar. Ağdaki her cihazın kendine ait bir IP adresi vardır.
- IPv4: 32-bit adresleme yapar (örneğin: 192.168.1.1). Yaklaşık 4 milyar cihaz adreslenebilir.
- IPv6: 128-bit adresleme yapar. IPv4’ün adres yetersizliği nedeniyle geliştirilmiştir (örneğin: 2001:0db8::7334).

#### TCP (Transmission Control Protocol)

TCP, bağlantı tabanlı ve güvenilir veri iletimini sağlar.
- Bağlantı Kurulumu: TCP, istemci ile sunucu arasında üç aşamalı bir el sıkışma (three-way handshake) ile bağlantı başlatır.
- Veri İletimi: Verilerin sıralı ve kayıpsız bir şekilde ulaşmasını garanti eder.
- Bağlantı Kapatma: İletişim sonunda bağlantı düzgün bir şekilde sonlandırılır.

#### TCP/IP İletişimi ve Soketler

Soketler, istemci ve sunucu arasındaki bağlantıyı sağlayan araçlardır. Bir istemci ve bir sunucu arasında TCP/IP iletişimi kurarken, her iki taraf da bir soket kullanarak veriyi iletir. Soketler, IP adresi ve port numarası kullanılarak birbirine bağlanır.

#### Bağlantı Kurulumu: Three-Way Handshake

TCP, bağlantı kurarken `Three-Way Handshake` denilen bir süreç kullanır. Bu süreç, istemci ve sunucu arasında güvenli bir bağlantının kurulduğundan emin olmayı sağlar.
1. `SYN`     : İstemci, sunucuya bir bağlantı talebi gönderir.
2. `SYN-ACK` : Sunucu, istemciye bağlantı talebini kabul ettiğini belirten bir cevap gönderir.
3. `ACK`     : İstemci, sunucunun cevabını onaylar ve bağlantı kurulmuş olur.

<br>

### IPv4 ve IPv6 ile TCP/IP İletişimi

#### IPv4 İletişimi

IPv4, 32-bit adreslemeyi kullanır ve ağ üzerindeki her cihaza bir IP adresi atar. Örneğin, 192.168.1.1 gibi bir adres, IPv4 adreslerinden biridir. IPv4, yaygın olarak kullanılan adresleme formatıdır.
- IPv4 Adresi Formatı: xxx.xxx.xxx.xxx (örneğin, 192.168.1.1)
- Adres Boyutu: 32 bit (4 byte)
- Adres Sayısı: 4,294,967,296 adres

IPv4 Soket Programlama Örneği:
```cpp
struct sockaddr_in server_addr;
server_addr.sin_family = AF_INET;
server_addr.sin_addr.s_addr = INADDR_ANY;
server_addr.sin_port = htons(8080);
```

#### IPv6 İletişimi

IPv6, IPv4’ün sınırlı adres alanını aşabilmek için geliştirilmiş bir protokoldür. IPv6, 128-bit adreslemeyi kullanır ve bu, çok daha fazla cihazın interneti kullanabilmesini sağlar.
- IPv6 Adresi Formatı: xxxx:xxxx:xxxx:xxxx:xxxx:xxxx:xxxx:xxxx (örneğin, 2001:0db8:85a3:0000:0000:8a2e:0370:7334)
- Adres Boyutu: 128 bit (16 byte)
- Adres Sayısı: 340 undecillion (çok büyük bir sayı)

IPv6 Soket Programlama Örneği:
```cpp
struct sockaddr_in6 server_addr;
server_addr.sin6_family = AF_INET6;
server_addr.sin6_addr = in6addr_any;
server_addr.sin6_port = htons(8080);
```

<br>

### Soket Nedir?

Soket, bir istemci ile sunucu arasında ağ üzerinden veri alışverişi yapmak için kullanılan yazılım arabirimidir. Soketler, IP adresi ve port numarası ile tanımlanır.

#### Temel Bileşenler
- `Soketler (Sockets)`: Ağa veri göndermek ve almak için kullanılan yazılım arabirimleridir. Bir soket, bir istemci ile bir sunucu arasında bir bağlantı noktasıdır.
- `Portlar (Ports)`: İletişimin doğru hedefe yönlendirilmesini sağlar. Port numaraları, sunucunun belirli bir servise (örneğin web servisi, veritabanı servisi) yanıt vermesi için kullanılır.
- `Adresler (Addresses)`: Soketler genellikle bir IP adresi ile ilişkilendirilir. IPv4 veya IPv6 adresleri kullanılarak istemciler ve sunucular arasında bağlantı kurulur.

#### Soket Tipleri

Soketler iki ana türe ayrılır:
1.	Stream Soketleri (SOCK_STREAM):
  - TCP tabanlı iletişim için kullanılır.
  - Veriler sıralı ve güvenilir bir şekilde iletilir. Yani verinin sırası bozulmaz, her veri parçası karşı tarafa ulaşır.
  - İstemci ve sunucu arasında sürekli bir bağlantı gereklidir.
  - Bu soket, uygulama katmanındaki veriyi güvenli bir şekilde iletebilmek için bağlantı yönetimi yapar.
2.	Datagram Soketleri (SOCK_DGRAM):
  - UDP tabanlı iletişim için kullanılır.
  - Veri paketleri bağımsızdır ve sırasız iletilir. Her veri parçası ayrı bir paket olarak gönderilir.
  - Bağlantı kurulmaz, yani iletişim daha hafif ve hızlıdır, ancak veri kaybı ve sıralama hataları olabilir.

<br>

### Soket Programlama Adımları

#### Sunucu Tarafı Adımları
1. Soket Oluşturma (socket fonksiyonu ile)
2. Adres Yapılandırması ve Bağlama (bind fonskiyonu ile)
3. Bağlantı Dinleme (listen fonksiyonu ile)
4. Bağlantı Kabul Etme (accept fonskiyonu ile)
5. Veri Alışverişi (recv ve send fonksiyonları ile)
6. Bağlantıyı Kapatma (close fonksiyonu ile)

#### İstemci Tarafı Adımları
1. Soket Oluşturma (socket fonksiyonu ile)
2. Sunucuya Bağlanma (htons, inet_addr kullanarak connect fonskiyonu ile)
3. Veri Gönderme ve Alma (send ve recv fonksiyonu ile)
4. Bağlantıyı Kapatma (close fonksiyonu ile)

<br></br>

## Fonksiyon Açıklamaları

<details>
  <summary><span style="font-size:16px; font-weight:bold;"><code>c_str</code> (C++ string to C-style string)</span></summary>
C++98’de c_str() fonksiyonu, std::string sınıfının bir üyesidir ve C++ string’ini C tarzı (const char*) null-terminated karakter dizisine dönüştürmek için kullanılır. Bu dönüşüm, C kütüphanesi fonksiyonlarıyla (örneğin strtol, printf, fopen, strcpy) uyumlu hale getirmek için gereklidir.

**> Söz dizimi (Syntax)**

```cpp
const char* c_str() const;
```

**> Açıklama**
- c_str() fonksiyonu, std::string nesnesinin içeriğini null karakter (\0) ile biten bir C tarzı string olarak döner.
- Geriye dönen const char*, std::string nesnesinin iç belleğine işaret eder ve değiştirilemez.
- std::string değişirse veya yok edilirse, c_str() ile alınan gösterici (pointer) geçersiz olur.

**> Dönüş Değeri**
- const char*: std::string nesnesinin içeriğini C tarzı karakter dizisi olarak verir.

---

Örnek:
```cpp
#include <iostream>
#include <string>
#include <cstring>  // strcpy gibi C fonksiyonları için

int main() {
    std::string str = "Merhaba";
    const char* cstr = str.c_str();

    std::cout << "C tarzı string: " << cstr << std::endl;

    // Örnek: C fonksiyonu ile kopyalama
    char buffer[100];
    strcpy(buffer, cstr);
    std::cout << "Buffer içeriği: " << buffer << std::endl;

    return 0;
}
```

Çıktı:
```
C tarzı string: Merhaba
Buffer içeriği: Merhaba
```

Bu örnekte std::string türündeki str değişkeni, c_str() kullanılarak C tarzı string’e dönüştürülmüş ve strcpy fonksiyonu ile başka bir buffer’a kopyalanmıştır.

</details>
<br>
<details>
  <summary><span style="font-size:16px; font-weight:bold;"><code>strtol</code> (str to long int) </span></summary>
C++98’de strtol fonksiyonu, C standart kütüphanesinden gelen ve C++ içinde de kullanılabilen bir fonksiyondur. strtol, bir C-string (yani const char*) ifadesini uzun tamsayıya (long int) dönüştürmek için kullanılır.

**> Söz dizimi (Syntax)**
```cpp
long int strtol(const char *nptr, char **endptr, int base);
```

**> Parametreler**

- nptr: Dönüştürülmek istenen C tarzı string (örneğin "123abc").
- endptr: Fonksiyon, sayısal dönüşümün bittiği yeri bu işaretçiye yazar. Eğer bu bilgiye ihtiyacın yoksa NULL geçebilirsin.
- base: Sayının tabanı (örn. 10 onluk, 16 onaltılık, 8 sekizlik). 0 verirsen, C stili sayı sistemine göre otomatik algılar:
  - 0x veya 0X ile başlıyorsa 16 (hex),
  - 0 ile başlıyorsa 8 (octal),
  - aksi halde 10 (decimal) olarak yorumlanır.

**> Dönüş Değeri**

- Dönüştürülen uzun tamsayı (long int) olarak geri döner.
- Eğer dönüşüm yapılamazsa 0 döner.
- Eğer sayı long sınırlarını aşarsa, LONG_MAX veya LONG_MIN döner ve errno ERANGE olarak ayarlanır.

---

Örnek:
```cpp
#include <iostream>
#include <cstdlib>  // strtol burada tanımlı
#include <cerrno>   // errno kullanmak için
#include <climits>  // LONG_MAX, LONG_MIN

int main() {
    const char* str = "123abc";
    char* end;
    errno = 0; // Hata kontrolü için sıfırla

    long result = strtol(str, &end, 10);

    if (errno == ERANGE) {
        std::cerr << "Hata: Sayı çok büyük veya çok küçük!" << std::endl;
    } else if (str == end) {
        std::cerr << "Hata: Geçerli bir sayı bulunamadı!" << std::endl;
    } else {
        std::cout << "Dönüştürülen sayı: " << result << std::endl;
        std::cout << "Geriye kalan ifade: " << end << std::endl;
    }

    return 0;
}
```

Çıktı:
```
Dönüştürülen sayı: 123
Geriye kalan ifade: abc
```

Bu örnekte "123abc" stringinden sadece "123" kısmı sayıya dönüştürülür. Geri kalan "abc" kısmı end işaretçisiyle erişilebilir olur.

</details>
<br>
<details>
  <summary><span style="font-size:16px; font-weight:bold;"><code>socket()</code></span></summary>

**Tanım**: Yeni bir soket oluşturur. Soket, istemci ve sunucu arasında veri iletimi için kullanılan bir ağ arayüzüdür.

**Prototip**:
```cpp
int socket(int domain, int type, int protocol);
```

**Parametreler**:
- `domain`: İletişim için kullanılan adres aile türü.
  - `AF_INET`: IPv4 adres ailesi (en yaygın kullanılan).
  - `AF_INET6`: IPv6 adres ailesi.
  - `AF_UNIX`: Yerel ağ (Unix domain socket).
- `type`: Soket tipi, veri iletim yöntemini belirtir.
  - `SOCK_STREAM`: TCP (bağlantı tabanlı) iletişim sağlar.
  - `SOCK_DGRAM`: UDP (bağlantısız) iletişim sağlar.
  - `SOCK_RAW`: Ham IP paketleri için soket oluşturur.
- `protocol`: Kullanılacak protokolü belirtir. Genellikle `0` kullanılır, çünkü `type` parametresi zaten kullanılacak protokolü belirler.
  - `0`: Varsayılan protokolü kullanır (TCP için `0`).

**Örnek**:
```cpp
int server_fd = socket(AF_INET, SOCK_STREAM, 0);
```

**Geri Dönüş**:
- Başarılıysa: Pozitif bir dosya tanımlayıcı döner (`fd`).
- Hatalıysa: `-1` döner ve `errno` değişkeni hata hakkında bilgi verir.

</details>
<br>

<details>
  <summary><span style="font-size:16px; font-weight:bold;"><code>setsockopt()</code></span></summary>

**Tanım**: Bir soket üzerinde bazı opsiyonları ayarlamak için kullanılır. Bu opsiyonlar soketin davranışını değiştirebilir.

**Prototip**:
```cpp
int setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen);
```

**Parametreler**:
- `sockfd`: Ayar yapılacak soketin dosya tanımlayıcısı.
- `level`: Hangi seviyede ayar yapılacağını belirtir.
  - `SOL_SOCKET`: Soket seviyesinde ayar yapılır (en yaygın).
  - `IPPROTO_TCP`: TCP protokolü için ayarlar yapılır.
- `optname`: Yapılacak ayarın türünü belirtir.
  - `SO_REUSEADDR`: Bağlantı noktası yeniden kullanılabilir.
  - `SO_RCVBUF`: Alınacak veri tamponunun boyutu.
- `optval`: Ayar yapılacak değeri içerir.
  - Örneğin, `1` yazmak `SO_REUSEADDR` için adresin yeniden kullanılmasına izin verir.
- `optlen`: `optval`'ın boyutu.

**Örnek**:
```cpp
int opt = 1;
setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
```

**Geri Dönüş**:
- Başarılıysa: `0`.
- Hatalıysa: `-1` döner ve `errno` değişkeni hata hakkında bilgi verir.

</details>
<br>

<details>
  <summary><span style="font-size:16px; font-weight:bold;"><code>htons()</code></span></summary>

Tanım: “Host To Network Short” anlamına gelir. 16 bitlik (short) bir sayıyı yerel sistemin byte sırasından (endianness) ağ sırasına (big-endian) çevirir. Genellikle bind() fonksiyonu ile birlikte port numarasını ağ sırasına çevirmek için kullanılır.

**Prototip**:
```cpp
uint16_t htons(uint16_t hostshort);
```

**Parametreler**:
- `hostshort`: Yerel sistemdeki byte sırasına göre yazılmış 16 bitlik (2 byte) bir tamsayı. Genellikle port numarası olur.
- Örneğin: 6667 port numarası.

**Kullanım Amacı**:
- Farklı mimarilerde sistemlerin byte sıraları farklı olabilir (little-endian, big-endian). Ağ üzerinden veri gönderirken bu farklılıklar sorun yaratmaması için tüm makinelerin network byte order (big-endian) kullanması beklenir.
- `htons()`, bu dönüşümü sağlar.

**Örnek**:
```cpp
address.sin_port = htons(6667);  // 6667'yi ağ byte sırasına çevirir.
```

**Geri Dönüş**:
- Ağ sırasına çevrilmiş 16 bitlik bir tamsayı döner.

</details>
<br>

<details>
  <summary><span style="font-size:16px; font-weight:bold;"><code>bind()</code></span></summary>

**Tanım**: Bir soketi, belirli bir IP adresi ve port numarasına bağlar. Bu, sunucunun istemcilerden gelen bağlantıları dinleyebilmesi için gereklidir.

**Prototip**:
```cpp
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
```

**Parametreler**:
- `sockfd`: Bağlanacak olan soketin dosya tanımlayıcısı.
- `addr`: Bağlantı yapılacak adresi içeren yapı. Genellikle `sockaddr_in` (IPv4) kullanılır.
- `addrlen`: `addr` yapısının boyutu.

<br>
<details>
  <summary><span style="font-size:16px; font-weight:bold;"><code>sockaddr_in</code> yapısının içindeki alanların detaylı açıklaması</span></summary>

Kod:
```cpp
address.sin_family = AF_INET;
address.sin_addr.s_addr = INADDR_ANY;  // Tüm arayüzlerden bağlantıya izin verir.
address.sin_port = htons(6667);        // 6667 portunu kullan
```

⸻

Bu yapı `struct sockaddr_in` tipindedir:

```cpp
struct sockaddr_in
{
    sa_family_t    sin_family;  // Adres ailesi
    in_port_t      sin_port;    // Port numarası
    struct in_addr sin_addr;    // IP adresi
    char           sin_zero[8]; // Yapıyı struct sockaddr ile aynı boyutta tutmak için kullanılır (genelde sıfırlanır)
};
```

⸻

Alan Açıklamaları:

```cpp
address.sin_family = AF_INET;
```
- Ne işe yarar?
  - Bu alan, hangi adres ailesinin (IPv4 mü, IPv6 mı) kullanılacağını belirtir.
- Değerler:
  - AF_INET: IPv4 adresleri için.
  - AF_INET6: IPv6 adresleri için (IPv6 kullanıyorsan sockaddr_in6 yapısı gerekir).
- Neden önemlidir?
  - Soketin hangi protokol ile çalıştığını sistemin anlaması için bu bilgi gerekir. IPv4 tabanlı TCP/UDP için AF_INET kullanılır.

⸻

```cpp
address.sin_addr.s_addr = INADDR_ANY;
```
- Ne işe yarar?
  - Sunucunun tüm mevcut ağ arayüzlerinden gelen bağlantıları kabul etmesini sağlar.
- Detay:
  - sin_addr alanı, struct in_addr türündedir.

```cpp
struct in_addr
{
    in_addr_t s_addr;  // 32-bit IPv4 adresi (örneğin: 127.0.0.1)
};
```

- INADDR_ANY özel bir makro olup değeri 0.0.0.0’a karşılık gelir.
- INADDR_ANY, sunucunun hem localhost’tan (127.0.0.1) hem de diğer tüm IP’lerden gelen bağlantıları kabul etmesini sağlar.

- Alternatif:
  - Eğer sadece belirli bir IP üzerinden bağlantı almak istenirse,
  - Örneğin:
  `inet_pton(AF_INET, "192.168.1.100", &address.sin_addr);`

</details>

<br>

**Örnek**:
```cpp
struct sockaddr_in address;
address.sin_family = AF_INET;          // IPv4 adres ailesi
address.sin_addr.s_addr = INADDR_ANY;  // Tüm IP'lerden bağlantı kabul et
address.sin_port = htons(6667);        // 6667 portunu kullan

bind(server_fd, (struct sockaddr*)&address, sizeof(address));
```

**Geri Dönüş**:
- Başarılıysa: `0`.
- Hatalıysa: `-1` döner ve `errno` değişkeni hata hakkında bilgi verir.

</details>
<br>
<details>
  <summary><span style="font-size:16px; font-weight:bold;"><code>listen()</code></span></summary>

**Tanım**: Soketi "dinlemeye" alır. Yani sunucu, gelen bağlantıları kabul etmeye hazır hale gelir.

**Prototip**:
```cpp
int listen(int sockfd, int backlog);
```

**Parametreler**:
- `sockfd`: Dinlemeye alınacak soketin dosya tanımlayıcısı.
- `backlog`: Bağlantı kuyruğundaki maksimum bağlantı sayısı. Bu, istemcilerin sıraya girerek bekleyeceği maksimum bağlantı sayısını belirtir. `SOMAXCONN` genellikle yeterlidir.

**Örnek**:
```cpp
listen(server_fd, SOMAXCONN);
```

**Geri Dönüş**:
- Başarılıysa: `0`.
- Hatalıysa: `-1` döner ve `errno` değişkeni hata hakkında bilgi verir.

</details>
<br>

<details>
  <summary><span style="font-size:16px; font-weight:bold;"><code>inet_pton()</code></span></summary>

**Tanım**: Bir IP adresini (IPv4 ya da IPv6) string formatından ağ sırasına (network byte order) dönüştürür. Bu dönüşüm, verilerin doğru bir şekilde ağ üzerinde iletilmesini sağlar. IPv4 ve IPv6 adreslerini dönüştürebilir.

**Prototip**: `int inet_pton(int af, const char *src, void *dst);`

**Parametreler**:
- `af`: Adres ailesini belirtir.
- `AF_INET`: IPv4 adresi için.
- `AF_INET6`: IPv6 adresi için.
- `src`: Dönüştürmek istediğiniz IP adresini içeren karakter dizisi. Örneğin, "192.168.1.1" veya "2001:0db8:85a3:0000:0000:8a2e:0370:7334".
- `dst`: IP adresinin dönüştürüleceği hedef yapıdır. Bu, struct in_addr (IPv4) veya struct in6_addr (IPv6) türünde olmalıdır.

**Dönüş Değeri**:
- Başarılıysa: 1 döner.
- Hatalıysa: 0 döner ve errno değişkeni hata kodunu belirtir.

**Kullanım Örneği**:

1. IPv4 Adresi Dönüştürme:
	```cpp
	#include <stdio.h>
	#include <string.h>
	#include <arpa/inet.h>

	int main() {
		struct sockaddr_in sa;
		const char *ip_addr = "192.168.1.1";

		// inet_pton ile IP adresini dönüştürme
		if (inet_pton(AF_INET, ip_addr, &(sa.sin_addr)) == 1) {
			printf("IP adresi başarıyla dönüştürüldü.\n");
		} else {
			printf("IP adresi dönüştürülemedi.\n");
		}

		return 0;
	}
	```

- Burada inet_pton() fonksiyonu, "192.168.1.1" IP adresini sa.sin_addr yapısına dönüştürür.
- Eğer başarılı olursa, IP adresi ağ sırasına çevrilmiş olur ve bu, soketler aracılığıyla kullanılabilir.

2. IPv6 Adresi Dönüştürme:
	```cpp
	#include <stdio.h>
	#include <string.h>
	#include <arpa/inet.h>

	int main() {
		struct sockaddr_in6 sa;
		const char *ipv6_addr = "2001:0db8:85a3:0000:0000:8a2e:0370:7334";

		// inet_pton ile IPv6 adresini dönüştürme
		if (inet_pton(AF_INET6, ipv6_addr, &(sa.sin6_addr)) == 1) {
			printf("IPv6 adresi başarıyla dönüştürüldü.\n");
		} else {
			printf("IPv6 adresi dönüştürülemedi.\n");
		}

		return 0;
	}
	```

- Burada inet_pton() fonksiyonu, "2001:0db8:85a3:0000:0000:8a2e:0370:7334" IPv6 adresini sa.sin6_addr yapısına dönüştürür.

<br>

**Hangi Durumda Kullanılır**?
- IP adreslerinin ağ sırasına dönüştürülmesi gereken her durumda kullanılır. Bu, ağ tabanlı uygulamalarda (örneğin, sunucu ve istemci arasında bağlantı kurma) oldukça yaygındır.
- Genellikle inet_pton() fonksiyonu, IP adresinin karakter dizisi formatında (örneğin "192.168.1.1") verildiği yerlerde kullanılır ve bu adresin uygun ağ sırasına dönüştürülmesini sağlar.

<br>

**inet_pton() ve inet_ntop() Arasındaki Fark**:
- inet_pton(): Karakter dizisi (string) IP adresini, ağ sırasına (binary format) dönüştürür.
- inet_ntop(): Ağ sırasındaki (binary format) IP adresini, karakter dizisine (string) dönüştürür.

<br>

**Hata Durumu**:
- Eğer verilen IP adresi geçersizse (örneğin, format hatası varsa), inet_pton() fonksiyonu 0 döner.
- Ayrıca, hata hakkında bilgi almak için `errno` değişkeni kontrol edilebilir.
- `errno` değeri aşağıdaki gibi olabilir:
  - EINVAL: Geçersiz IP adresi formatı.
  - EAFNOSUPPORT: Belirtilen adres ailesi (örneğin AF_INET6) desteklenmiyor.

</details>
<br>
<details>
  <summary><span style="font-size:16px; font-weight:bold;"><code>accept()</code></span></summary>

**Tanım**: Bir istemciden gelen bağlantıyı kabul eder ve yeni bir dosya tanımlayıcı döner. Bu yeni dosya tanımlayıcı, istemciyle olan iletişimi sağlar.

**Prototip**:
```cpp
int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
```

**Parametreler**:
- `sockfd`: Dinlemeye alınmış soketin dosya tanımlayıcısı.
- `addr`: İstemcinin adres bilgilerini döndüren yapı. `NULL` olabilir.
- `addrlen`: `addr` yapısının boyutunu belirten değişken.

**Örnek**:
```cpp
int client_fd = accept(server_fd, NULL, NULL);
```

**Geri Dönüş**:
- Başarılıysa: Yeni bir dosya tanımlayıcı (`client_fd`).
- Hatalıysa: `-1` döner ve `errno` değişkeni hata hakkında bilgi verir.

</details>
<br>

<details>
  <summary><span style="font-size:16px; font-weight:bold;"><code>recv()</code></span></summary>

**Tanım**: Bir soketten veri alır. Bu fonksiyon, veriyi soketten okuyarak belleğe kopyalar.

**Prototip**:
```cpp
ssize_t recv(int sockfd, void *buf, size_t len, int flags);
```

**Parametreler**:
- `sockfd`: Veriyi alacağınız soketin dosya tanımlayıcısı.
- `buf`: Veriyi alacağınız bellek adresi.
- `len`: Alınacak veri miktarının boyutu (byte cinsinden).
- `flags`: İletim seçenekleri (genellikle `0`).

**Örnek**:
```cpp
char buffer[512];
int bytes_received = recv(client_fd, buffer, sizeof(buffer), 0);
```

**Geri Dönüş**:
- Başarılıysa: Alınan veri miktarını (byte olarak).
- Hatalıysa veya bağlantı kapanmışsa: `0` veya `-1` döner, `errno` hata hakkında bilgi verir.

</details>
<br>

<details>
  <summary><span style="font-size:16px; font-weight:bold;"><code>send()</code></span></summary>

**Tanım**: Bir soket üzerinden veri gönderir. Veriyi belirtilen sokete iletir.

**Prototip**:
```cpp
ssize_t send(int sockfd, const void *buf, size_t len, int flags);
```

**Parametreler**:
- `sockfd`: Veriyi göndereceğiniz soketin dosya tanımlayıcısı.
- `buf`: Gönderilecek veriyi içeren bellek adresi.
- `len`: Gönderilecek veri miktarının boyutu (byte cinsinden).
- `flags`: İletim seçenekleri (genellikle `0`).

**Örnek**:
```cpp
std::string response = "Hello from IRC server!
";
send(client_fd, response.c_str(), response.length(), 0);
```

**Geri Dönüş**:
- Başarılıysa: Gönderilen veri miktarını (byte olarak).
- Hatalıysa: `-1` döner, `errno` hata hakkında bilgi verir.

</details>
<br>
<details>
  <summary><span style="font-size:16px; font-weight:bold;"><code>close()</code></span></summary>

**Tanım**: Soketi kapatır ve kaynakları serbest bırakır.

**Prototip**:
```cpp
int close(int fd);
```

**Parametreler**:
- `fd`: Kapatılacak soketin dosya tanımlayıcısı.

**Örnek**:
```cpp
close(client_fd);
```

**Geri Dönüş**:
- Başarılıysa: `0`.
- Hatalıysa: `-1` döner ve `errno` hata hakkında bilgi verir.
</details>
<br>
<details>
  <summary><span style="font-size:16px; font-weight:bold;"><code>poll()</code></span></summary>

**Tanım**: Bir veya daha fazla dosya tanıtıcısının durumunu kontrol eder ve herhangi bir olay oluştuğunda geri dönüş yapar. Bu fonksiyon, ağ uygulamalarında birden fazla soketi izlemek için yaygın olarak kullanılır.

**Prototip**: `int poll(struct pollfd *fds, nfds_t nfds, int timeout);`

**Parametreler**:
- `fds`: Bir dizi pollfd yapısı. Bu yapılar, izlenecek dosya tanıtıcıları ve bu tanıtıcılarla ilgili olay türlerini belirtir.
- `fd`: İzlenecek dosya tanıtıcısı (örneğin, soket dosya tanıtıcısı).
- `events`: Bu dosya tanıtıcısı için izlenecek olaylar (örneğin, POLLIN (okuma), POLLOUT (yazma), POLLERR (hata)).
- `revents`: Fonksiyon döndükten sonra, hangi olayların meydana geldiğini belirtir.
- `nfds`: fds dizisinin uzunluğu (izlenecek dosya tanıtıcılarının sayısı).
- `timeout`: poll() fonksiyonunun ne kadar süreyle bekleyeceğini belirten zaman aşımı süresi (milisaniye cinsinden). Eğer negatifse, fonksiyon sonsuz süreyle bekler.

**Geri Dönüş**:
- Başarılıysa: İzlenen dosya tanıtıcılarında bir veya daha fazla olay meydana gelirse, geri dönen değer, bu olayların sayısını belirtir.
- Eğer hiç olay gerçekleşmediyse: 0 döner, yani zaman aşımı gerçekleşmiştir.
- Hata durumunda: -1 döner ve errno küresel hata kodu belirlenir.

**Örnek**:
```cpp
#include <iostream>
#include <vector>
#include <poll.h>
#include <unistd.h>

int main()
{
    // Bir dosya tanıtıcısı dizisi oluşturuluyor
    std::vector<struct pollfd> fds(1);

    // Standart giriş dosya tanıtıcısını izleme (fd 0, standart giriş)
    fds[0].fd = 0;
    fds[0].events = POLLIN;  // Okuma olayını izleme

    int timeout = 5000;  // 5 saniye

    // poll fonksiyonu ile soket izleme
    int ret = poll(fds.data(), fds.size(), timeout);

    if (ret == -1) {
        std::cerr << "poll() error" << std::endl;
    }
    else if (ret == 0) {
        std::cout << "Timeout, no events occurred" << std::endl;
    }
    else {
        // Eğer bir olay gerçekleşmişse
        if (fds[0].revents & POLLIN) {
            char buffer[1024];
            ssize_t bytesRead = read(0, buffer, sizeof(buffer));  // Standart girişten veri oku
            if (bytesRead > 0) {
                buffer[bytesRead] = '\0';
                std::cout << "Input: " << buffer << std::endl;
            }
        }
    }

    return 0;
}
```

**Açıklama**:
- pollfd dizisinde bir dosya tanıtıcısı (standart giriş, fd = 0) izleniyor.
- events parametresi POLLIN olarak ayarlanmış, yani girişte veri olup olmadığı izleniyor.
- timeout 5000 milisaniye olarak belirlenmiş, yani poll() fonksiyonu 5 saniye bekleyecek.
- Eğer veri okunabilirse (POLLIN durumu) standart girişten okuma yapılır ve okunan veri ekrana yazdırılır.
- Eğer süre dolarsa veya hata olursa, durum uygun mesajlarla bildirilir.

</details>
