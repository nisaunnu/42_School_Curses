## Inception Projesi

Projeyi yaparken yapılması gereken adımlar aşağıda yer almaktadır. Yazıların yazıldığı sıra ile devam ederseniz projeyi daha kolay bir şekilde tamamlayabilirsiniz.

<br>

## İçerik

- [Virtual Machine Oluşturma](#virtual-machine-oluşturma)
- [Virtual Machine'ni VS Code ile Kendi Bilgisayarınıza Bağlama](#virtual-machineni-vs-code-ile-kendi-bilgisayarınıza-bağlama)
- [Docker](#docker)
	- [Docker Nedir?](#docker-nedir)
	- [Docker Ne Sunar?](#docker-ne-sunar)
	- [Temel Kavramlar](#temel-kavramlar)
	- [Docker Nasıl Çalışır?](#docker-nasıl-çalışır)
	- [Docker ile Neler Yapabilirsin?](#docker-ile-neler-yapabilirsin)
	- [Sanal Makine ile Farkı](#sanal-makine-ile-farkı)
	- [Güvenlik ve İzolasyon](#güvenlik-ve-i̇zolasyon)
	- [Gerçek Hayattan Örnek](#gerçek-hayattan-örnek)
	- [Docker Compose](#docker-compose)
- [Docker Image](#docker-image)
	- [Docker Image Nedir?](#docker-image-nedir)
	- [Image = Layers (Katmanlar)](#image--layers-katmanlar)
	- [Image Ne İşe Yarar?](#image-ne-i̇şe-yarar)
	- [Bir Docker Image Neleri İçerir?](#bir-docker-image-neleri-i̇çerir)
	- [Image Nasıl Oluşturulur?](#image-nasıl-oluşturulur)
	- [Image’lar Nerede Tutulur?](#imagelar-nerede-tutulur)
	- [Katmanların Önemi (Caching)](#katmanların-önemi-caching)
	- [Docker Image’ın Özellikleri](#docker-imageın-özellikleri)
	- [Docker Image Özeti](#docker-image-özeti)
- [Docker Container](#docker-container)
	- [Docker Container Nedir?](#docker-container-nedir)
	- [Image vs Container](#image-vs-container)
	- [Bir Docker Container İçeriğinde Neler Vardır?](#bir-docker-container-i̇çeriğinde-neler-vardır)
	- [Container Nasıl Oluşur?](#container-nasıl-oluşur)
	- [İzolasyon Nedir?](#i̇zolasyon-nedir)
	- [Container ile Ne Yapabilirsin?](#container-ile-ne-yapabilirsin)
	- [Container’lar Neden Tercih Ediliyor?](#containerlar-neden-tercih-ediliyor)
	- [Docker Container Örneği](#docker-container-örneği)
	- [Container Yönetimi için Gerekli Komutlar](#container-yönetimi-için-gerekli-komutlar)
	- [Docker Container Özeti](#docker-container-özeti)
- [Docker Compose](#docker-compose-1)
	- [Docker Compose Nedir?](#docker-compose-nedir)
	- [`docker-compose.yml` Dosyası Nedir?](#docker-composeyml-dosyası-nedir)
	- [Açıklamalar](#açıklamalar)
	- [Tam Örnek: NGINX + MySQL Projesi](#tam-örnek-nginx--mysql-projesi)
	- [Docker Compose Özeti](#docker-compose-özeti)
- [Docker Secrets](#docker-secrets)
	- [`.env` Dosyası Nedir?](#env-dosyası-nedir)
	- [Örnek `.env` Dosyası](#örnek-env-dosyası)
	- [`docker-compose.yml` İçinde `.env` Dosyası Kullanımı](#docker-composeyml-i̇çinde-env-dosyası-kullanımı)
	- [Docker Secrets Nedir?](#docker-secrets-nedir)
	- [Docker Secrets Nasıl Kullanılır?](#docker-secrets-nasıl-kullanılır)
	- [.env ve Docker Secrets Farkları](#env-ve-docker-secrets-farkları)
	- [Docker Secret ve .env Özeti](#docker-secret-ve-env-özeti)
- [Docker Komutları](#docker-komutları)
	- [Temel Docker Komutları](#temel-docker-komutları)
	- [Docker Image Komutları](#docker-image-komutları)
	- [Container Komutları (Docker Container)](#container-komutları-docker-container)
	- [Volume (Veri Saklama) Komutları](#volume-veri-saklama-komutları)
	- [Network (Ağ) Komutları](#network-ağ-komutları)
	- [Docker Compose (Çoklu Servis)](#docker-compose-çoklu-servis)
	- [Docker System Yönetimi](#docker-system-yönetimi)
	- [Dockerfile Komutları (Yazım Kuralları)](#dockerfile-komutları-yazım-kuralları)
- [NGINX](#nginx)
	- [Nginx Nedir?](#nginx-nedir)
	- [Nginx’in Temel Kullanım Amaçları](#nginxin-temel-kullanım-amaçları)
	- [Nginx’in Avantajları:](#nginxin-avantajları)
	- [443 Portu Nedir?](#443-portu-nedir)
	- [SSL ve TLS Nedir?](#ssl-ve-tls-nedir)
	- [SSL / TLS Sertifikaları Nedir?](#ssl--tls-sertifikaları-nedir)
	- [Sertifika Türleri:](#sertifika-türleri)
	- [SSL ve TLS Arasındaki Farklar](#ssl-ve-tls-arasındaki-farklar)
	- [HTTPS Bağlantısı Nasıl Çalışır?](#https-bağlantısı-nasıl-çalışır)
- [WordPress](#wordpress)
	- [WordPress Nedir?](#wordpress-nedir)
	- [WordPress Nasıl Çalışır?](#wordpress-nasıl-çalışır)
	- [WordPress’in Yapısı](#wordpressin-yapısı)
	- [WordPress Veritabanı Ne İşe Yarar?](#wordpress-veritabanı-ne-i̇şe-yarar)
	- [WordPress ile HTTPS ve SSL](#wordpress-ile-https-ve-ssl)
	- [WordPress Kurulumu (Kısaca)](#wordpress-kurulumu-kısaca)
	- [WordPress Admin Paneli](#wordpress-admin-paneli)
- [MariaDB](#mariadb)
	- [MariaDB Nedir?](#mariadb-nedir)
	- [MariaDB Ne İşe Yarar?](#mariadb-ne-i̇şe-yarar)
	- [MariaDB Nasıl Çalışır?](#mariadb-nasıl-çalışır)
	- [Temel MariaDB Komutları](#temel-mariadb-komutları)
	- [MariaDB Güvenlik (Kullanıcı ve Şifre)](#mariadb-güvenlik-kullanıcı-ve-şifre)
	- [MariaDB Docker Ortamında](#mariadb-docker-ortamında)
	- [MariaDB vs MySQL](#mariadb-vs-mysql)
	- [MariaDB Güvenliği](#mariadb-güvenliği)
	- [WordPress ile Nasıl Entegre Olur?](#wordpress-ile-nasıl-entegre-olur)

<br></br>

## Virtual Machine Oluşturma

İlk olarak debian'ı yükleyebilmek için .iso dosyasını debian'ın sitesinden indirmemiz gerekli. Debian'ın resmi sitesine gitmek için [tıklayınız](https://www.debian.org/).

Debian yükleme adımlarını gösteren videoya erişmek için [tıklayınız](https://www.youtube.com/watch?v=BjbhxtUjkhg).

Doküman üzerinden sanal makinenizi kurmak isterseniz [tıklayınız](https://github.com/Bakr-1/inceptionVm-guide).

Not 1: Video içerisinde virtual machine'e docker gibi özellikler yükleniyor olacaktır. Video sonunda örnek bir inception projesi çalışması gösterilmektedir. Adımları takip ederek doğru bir şekilde kurulum yapıp yapmadığınızı görebilirsiniz.

Not 2: Debian'ı 42 bilgisayarlarınıza yüklerken folder kısmında virtual machine'i kendi kullanıcı adınıza değil, goinfre'ye yüklemeyi unutmayın. Yoksa hafıza alanı yetersiz diye hata mesajı ile karşılaşırsınız.

<br></br>

## Virtual Machine'ni VS Code ile Kendi Bilgisayarınıza Bağlama
<details>
<summary><span style="font-size:16px; font-weight:bold;"> Virtual Machine'de Yapılacak Adımlar</span></summary><br>

1. Yüklediğiniz virtual machine'de aşağıdaki kod satırlarını çalıştırın.
	```bash
	sudo apt update
	sudo apt install openssh-server
	sudo systemctl enable ssh
	sudo systemctl start ssh
	```
2. Kullanıcı adına verilen izinleri/ayrıcalıkları belirlemek için aşağıdaki komutu çalıştırın.
	```bash
	sudo visudo
	```
3. `root` kullanıcısının altına `(bilgisayarınızın ismi)	ALL=(ALL) ALL` yazın. Bilgisayar kullanıcısına tüm izinleri vermiş olacaksınız. Bilgisayarınızın ismini bilmiyorsanız terminale `hostname` yazarak öğrenebilirsiniz. Ardından dosyayı kaydederek çıkın.
	![img_1](img/sudo_visudo.png)
4. SSH'tan bağlanacağımız için portu değiştirelim. Terminalinize aşağıdaki komutu yazın.
	```bash
	sudo nano /etc/ssh/sshd_config
	```
6. Portu `4242` olarak değiştirin.
	![img_2](img/port.png)
7. SSH servisini yeniden başlatmak için aşağıdaki komut satırını terminale girin.
	```bash
	sudo service ssh restart
	```
</details>
<br>
<details>
<summary><span style="font-size:16px; font-weight:bold;"> Normal Bilgisayarınızda Yapılacak Adımlar</span></summary><br>

1. VS Code'u açın.
2. Microsoft'un "Remote - SSH" eklentisini indirin. Eklentinin indirme linkine ulaşmak için [tıklayınız](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-ssh).
3. VS Code'da sol alt kısımda yer alan ikona tıklayın.
	![img_3](img/ssh_icon.png)
4. Çıkan pencereden `Connect Current Window to Host...` seçeneğine tıklayın.
	![img_4](img/ssh_current_window.png)
5. Yeni ssh bağlantısı oluşturmak için `+ Add New SSH Host...` butonuna tıklayın.
	![img_5](img/ssh_add_new_host.png)
6. SSH'ı eklemek için `(bilgisayar_ismi)@(bilgisayar_ip) -p 4242` formatında girin.
	- Bilgisayarınızın ip adresini bilmiyorsanız `ip a` komutu ile öğrenebilirsiniz.
	- Bilgisayarınızın adını bilmiyorsanız `hostname` komutu ile öğrenebilirsiniz.
	![img_6](img/shh_cmd_line.png)
7. Config dosyasını seçmeniz için ekran çıkacaktır. Aşağıdaki gibi seçin.
	![img_7](img/ssh_config_file.png)
8. Bağlanmak için sağ alt köşede çıkan pop-up'tan `Connect` butonuna tıklayın.
	![img_8](img/ssh_connect.png)
9. Bilgisayarınızın kullanıcısının şifresi sorulacak. Şifrenizi girin ve enter'a basın. Şifresi yoksa direkt olarak enter'a basın.
10. Tebrikler! Virtual Machine'e kendi bilgisayarınızdan bağlandınız. Bağlandığınızı test etmek için open folder diyerek klasör açın, oluşturun, silin.
</details>
<br></br>

## Docker

### Docker Nedir?

Docker, uygulamaları ve onların tüm bağımlılıklarını (kütüphaneler, sistem araçları, kodlar vs.) bir araya getirerek taşınabilir, izole ve tutarlı bir ortamda çalıştırmanı sağlayan bir konteyner platformudur.

- Sorun Ne?
  - Eskiden yazılımcılar şunu çok yaşardı: “Kod benim bilgisayarımda çalışıyor ama seninkinde çalışmıyor!”
- Neden?
  - Farklı işletim sistemleri
  - Farklı yazılım sürümleri
  - Eksik kütüphaneler
  - Farklı sistem ayarları

<br>

### Docker Ne Sunar?

Docker, bu sorunları ortadan kaldırır. Çünkü uygulamanı kendi ortamıyla birlikte paketleyip taşınabilir hale getirir.

Bu pakete **`container (konteyner)`** denir.

<br>

### Temel Kavramlar

1. Docker Image (İmaj):
	- Uygulamanın çalışması için gereken her şeyi içinde barındıran şablon.
	- Dosya sistemi, bağımlılıklar, yapılandırmalar burada tanımlanır.
	- Değişmez, tekrar kullanılabilir.

2. Docker Container (Konteyner):
	- Docker image’tan oluşturulan çalışan ortam.
	- Gerçekten çalışan uygulama buradadır.
	- Hafif, izole, birbirinden bağımsızdır.

3. Dockerfile:
	- Image oluşturmak için yazdığın talimatlar listesi.
	- “Şunu kur, bunu kopyala, şunu çalıştır” dersin.

4. Docker Engine:
	-	Docker’ın arka planda çalışan sistemi. Konteynerleri çalıştırır ve yönetir.

💡💡 Bir Dockerfile kullanarak image oluşturursun. 💡💡

<br>

### Docker Nasıl Çalışır?
1.	Sen bir Dockerfile yazarsın:
	```docker
	FROM python:3.10
	COPY . /app
	WORKDIR /app
	RUN pip install -r requirements.txt
	CMD ["python", "main.py"]
	```

2.	Bu dosya ile bir Docker Image oluşturursun:
	```docker
	docker build -t my-app .
	```

3.	Bu image’tan bir Container çalıştırırsın:
	```docker
	docker run myapp
	```

Ve bu uygulama artık:
- Hangi bilgisayarda olursa olsun
- Hangi işletim sistemi olursa olsun
Aynı şekilde çalışır.

<br>

### Docker ile Neler Yapabilirsin?
- Web uygulamaları, veritabanları, test ortamları kurmak
- Mikrosistem mimarileri geliştirmek (microservices)
- Sürekli entegrasyon/sürekli dağıtım (CI/CD)
- Otomatik testler
- Sunucusuz çalışan yazılımlar

<br>

### Sanal Makine ile Farkı

| Özellik            | Docker                       | Sanal Makine (VM)     |
|--------------------|------------------------------|-----------------------|
| Başlatma süresi    | Saniyeler                    | Dakikalar             |
| Kaynak kullanımı   | Az                           | Çok                   |
| İçinde ne çalışır? | Uygulama + bağımlılıklar     | Tüm işletim sistemi   |
| Performans         | Hızlı                        | Göreceli olarak yavaş |
| Yalıtım            | Orta düzeyde (shared kernel) | Tam yalıtım           |

<br>

### Güvenlik ve İzolasyon

Her container, izole çalışır. Yani biri çökerse diğerlerini etkilemez. Bu, sistem kararlılığı ve güvenlik açısından önemlidir.

<br>

### Gerçek Hayattan Örnek

Diyelim ki bir Node.js + MongoDB projen var. Docker ile:
- MongoDB’yi kurmaya gerek kalmaz.
- Node.js sürüm uyumsuzluğu yaşamazsın.
- Docker Compose ile 2 konteyner (uygulama + veritabanı) birlikte çalışır.
- Projeni başkasına gönderdiğinde “tek komutla” çalışır.

<br>

### Docker Compose

Birden fazla servisi (örneğin: web + veritabanı + redis) aynı anda ve yapılandırılmış biçimde çalıştırmanı sağlar.

`docker-compose.yml` dosyası ile yönetilir.

<br></br>

## Docker Image

### Docker Image Nedir?

Docker Image, bir Docker container’ı oluşturmak için kullanılan hazır bir şablondur (template).

> 🧠 Şöyle düşün:
>
> Docker Image = Uygulamanın donmuş, sabit, tekrarlanabilir bir hali
>
> Bir Docker container çalıştırmak istiyorsan, önce bir Docker Image’a ihtiyacın vardır.

<br>

### Image = Layers (Katmanlar)

Docker Image, katmanlı (layered) bir yapıya sahiptir.

Her katman:
- Dockerfile içinde yazdığın bir satıra karşılık gelir.
- Üst üste eklenir.
- Önceki katmanları tekrar kullanır (önbellekleme, hızlılık sağlar).

Örnek:
```docker
FROM python:3.10                     # 1. katman: Python ortamı
COPY . /app                          # 2. katman: Kodları kopyala
WORKDIR /app                         # 3. katman: Çalışma dizinini ayarla
RUN pip install -r requirements.txt  # 4. katman: Kütüphaneleri yükle
CMD ["python", "main.py"]            # 5. katman: Çalıştırılacak komut
```

Bu komutlar birleştirilir ve tek bir Docker Image oluşturur.

<br>

### Image Ne İşe Yarar?
- Uygulamanı tek bir dosya gibi düşünebilirsin.
- Herkes bu image’i indirip aynı uygulamayı çalıştırabilir.
- Kod, ortam, bağımlılıklar, işletim sistemi araçları — hepsi image’in içinde olur.

<br>

### Bir Docker Image Neleri İçerir?
- İşletim sistemi dosyaları (örn. Alpine, Debian)
- Uygulama dosyaları (örn. Python dosyaları, HTML dosyaları)
- Kütüphaneler ve bağımlılıklar (örn. pip, npm, apt paketleri)
- Ortam değişkenleri
- Başlatma komutları (CMD veya ENTRYPOINT)

<br>

### Image Nasıl Oluşturulur?

1. Adım: Dockerfile oluştur
	```docker
	FROM node:20
	WORKDIR /app
	COPY . .
	RUN npm install
	CMD ["node", "index.js"]
	```

2. Adım: Image oluştur
	```bash
	docker build -t my-node-app .
	```

3. Adım: Image’i kullanarak container başlat
	```bash
	docker run my-node-app
	```

<br>

### Image’lar Nerede Tutulur?
- Bilgisayarında `docker images` komutuyla görebilirsin.
- İnternette `Docker Hub` gibi kayıtlı yerlerde (cloud registry) saklanabilir.

<br>

### Katmanların Önemi (Caching)

Her katman ayrı ayrı kaydedildiği için:
- Değişiklik yapmadığın katmanlar önbellekten alınır.
- Bu sayede image oluşturma işlemi çok daha hızlı olur.

<br>

### Docker Image’ın Özellikleri

| Özellik                | Açıklama                                      |
|------------------------|-----------------------------------------------|
| Sabit                  | İçeriği değiştirilemez                        |
| Yeniden kullanılabilir | Aynı image’den birçok container çıkarılabilir |
| Taşınabilir            | Her yerde çalışabilir (Linux, Windows, Mac)   |
| Küçük ve hızlı         | VM’lere göre çok daha hafif ve hızlı          |

<br>

### Docker Image Özeti
- Docker Image, uygulamanın çalışması için gereken her şeyi (işletim sistemi, kod, kütüphaneler, ayarlar) içeren sabit bir dosyadır.
- Bu image’tan Docker container oluşturulur.
- Image’lar katman katmandır, önbelleklenir, paylaşılabilir ve taşınabilir.
- Dockerfile kullanılarak oluşturulur.
- Docker Hub gibi yerlerde saklanabilir ve dağıtılabilir.

<br></br>

## Docker Container

### Docker Container Nedir?

Docker Container, bir Docker Image’dan oluşturulmuş, çalışan ve izole bir uygulama ortamıdır.

> 🔧 Bir image: sabit, çalışmayan bir şablondur.
>
> 🚀 Bir container: bu image’in çalışan halidir.

<br>

Basit Tanım: Docker Container, bir uygulamanın kendi bağımsız ortamında çalışan canlı bir kopyasıdır. İçinde işletim sistemi dosyaları, uygulama kodları, bağımlılıklar vardır. Bu ortam sisteminden tamamen izole çalışır.

<br>

### Image vs Container

| Özellik             | Docker Image               | Docker Container                      |
|---------------------|----------------------------|---------------------------------------|
| Durum               | Sabit, çalışmaz            | Çalışan ortam                         |
| Tip                 | Şablon                     | Bu şablondan oluşturulan canlı örnek  |
| Değiştirilebilirlik | Değiştirilemez (read-only) | Değiştirilebilir (runtime’da)         |
| İşlev               | Kaynak                     | Çalışma ortamı                        |
| Benzetme            | Tarif (Kalıp)              | Yemeğin kendisi (Kalıptan çıkan ürün) |

<br>

### Bir Docker Container İçeriğinde Neler Vardır?
- Mini işletim sistemi dosyaları (örneğin: Alpine Linux, Debian)
- Uygulama dosyaları (örneğin: Python, Node.js dosyaları)
- Uygulamanın ihtiyaç duyduğu kütüphaneler (örn. pip, npm modülleri)
- Ortam değişkenleri
- Gerekirse konfigürasyon dosyaları

<br>

### Container Nasıl Oluşur?

1. Dockerfile’den bir image oluşturursun:
	```docker
	FROM node:20
	COPY . /app
	WORKDIR /app
	RUN npm install
	CMD ["node", "index.js"]
	```

2. Image oluştur:
	```bash
	docker build -t my-app .
	```

3. Container başlat:
	```bash
	docker run my-app
	```

Artık bir container çalışıyor! İçinde:
- Node.js yüklü
- Kodun var
- npm install yapılmış
- node index.js çalışıyor

<br>

### İzolasyon Nedir?

Docker Container:
- Host sistemden izole çalışır.
- Kendi ağ ayarları, dosya sistemi, işlem listesi (process list) vardır.
- Diğer container’lardan ve host’tan izoledir.

Bunun sonucu:
- Daha güvenli
- Çakışma olmaz
- Kararlı çalışır

<br>

### Container ile Ne Yapabilirsin?
- Web sunucuları çalıştırabilirsin (NGINX, Apache)
- Uygulamalarını test edebilirsin
- Veritabanları kurabilirsin (MySQL, PostgreSQL)
- Mikroservisleri izole çalıştırabilirsin
- CI/CD (Otomatik test/deploy) sistemleri kurabilirsin

<br>

### Container’lar Neden Tercih Ediliyor?

| Avantaj           | Açıklama                                         |
|-------------------|--------------------------------------------------|
| Hızlı             | Saniyeler içinde başlar                          |
| Hafif             | Sanal makineye göre çok az kaynak tüketir        |
| Taşınabilir       | Her yerde aynı şekilde çalışır                   |
| İzole             | Diğer sistemlerle karışmaz                       |
| Tekrar Edilebilir | Aynı image’den binlerce container çıkarabilirsin |

<br>

### Docker Container Örneği

Senin `myapp` adlı bir `image`’in var.
```bash
docker run -d --name benim-uygulamam -p 8080:80 myapp
```

Bu komut:
- myapp image’inden bir container başlatır
- Adı: benim-uygulamam
- 8080 portunu host’a bağlar
- Arka planda (daemon mode) çalışır

<br>

### Container Yönetimi için Gerekli Komutlar

| Komut                       | Açıklama                                     |
|-----------------------------|----------------------------------------------|
| `docker ps`                 | Çalışan container’ları listeler              |
| `docker stop <id>`          | Container’ı durdurur                         |
| `docker start <id>`         | Durdurulmuş bir container’ı yeniden başlatır |
| `docker exec -it <id> bash` | Container içinde terminal açar               |
| `docker rm <id>`            | Container’ı siler                            |

<br>

### Docker Container Özeti
- Docker Container, bir uygulamanın izole, taşınabilir, hafif ve çalışır hali.
- Image, bir tarif gibidir. Container, o tariften yapılan yemek.
- Kaynak tüketimi azdır, hızla çalışır, kolayca kopyalanabilir.
- Modern yazılım geliştirme ve dağıtım süreçlerinin vazgeçilmezidir.

<br></br>

## Docker Compose

### Docker Compose Nedir?

Docker Compose, birden fazla servisi (örneğin: web sunucusu, veritabanı) tanımlayıp tek bir komutla ayağa kaldırmanı sağlar.

Normal olarak çalıştırma:
```docker
docker run ...
docker run ...
docker network create ...
```

Ama Compose ile:
```docker
docker-compose up
```
ve her şey otomatik olur.

<br>

### `docker-compose.yml` Dosyası Nedir?

Bu dosya, Compose’un servisleri (services), ağları (networks), hacimleri (volumes) nasıl oluşturacağını tanımladığın YAML formatlı bir yapılandırma dosyasıdır.

Temel Yapı:
```docker
version: '3.9'

services:
  servis-adi:
    image: kullanilacak-image
    build: .
    ports:
      - "hostPort:containerPort"
    volumes:
      - ./local_dosya:/container_dosya
    environment:
      - VAR1=deger
    depends_on:
      - diger-servis
    networks:
      - ag-adi

volumes:
  volume_adi:

networks:
  ag-adi:
```
<br>

### Açıklamalar

1. `version`
	- Compose dosyasının sürümünü belirtir.
	- Genellikle '3.9' veya '3' kullanılır.
	- Sürüm, kullanılabilecek özellikleri belirler.
		```docker
		version: '3.9'
		```

2. `services`
	- Projede kullanılacak tüm container’lar buraya yazılır.
	- Her services altındaki anahtar, bir container (servis) anlamına gelir.
		```docker
		services:
			web:
				image: nginx
			db:
				image: mysql
		```

3. `volumes`
	- Kalıcı veri saklamak için kullanılır.
	- Servis içinde mount edilir, ayrıca en altta tanımlanır.
		```docker
		volumes:
			db-data:

		# Serviste nasıl kullanılır:

		services:
			db:
				image: mysql
				volumes:
					- db-data:/var/lib/mysql
		```

4. `networks`
	- Container’ların birbirleriyle iletişimini sağlayan özel ağlardır.
	- Özel bir network tanımlayabilir veya varsayılanı kullanabilirsin.
		```docker
		networks:
			backend:

		# Kullanımı:

		services:
			web:
				networks:
					- backend
		```

<br>

### Tam Örnek: NGINX + MySQL Projesi

```docker
version: '3.9'

services:
	web:
		image: nginx:alpine
		ports:
			- "8080:80"
		volumes:
			- ./html:/usr/share/nginx/html
		networks:
			- backend

	db:
		image: mysql:5.7
		environment:
			- MYSQL_ROOT_PASSWORD=1234
			- MYSQL_DATABASE=ornekdb
		volumes:
			- db-data:/var/lib/mysql
		networks:
			- backend

volumes:
	db-data:

networks:
	backend:
```

Açıklamalar:
- web servisi nginx çalıştırır ve 8080 portunu açar.
- db servisi mysql çalıştırır ve root şifresini tanımlar.
- db-data volume ile mysql verisi saklanır.
- İkisi de backend adlı ağa bağlıdır.

<br>

### Docker Compose Özeti

| Bölüm      | Görevi                                        |
|------------|-----------------------------------------------|
| `version`  | Compose dosyasının sürümünü belirtir          |
| `services` | Hangi container’lar çalışacak onu belirtir    |
| `volumes`  | Kalıcı veri saklamayı sağlar                  |
| `networks` | Container’ların birbiriyle konuşmasını sağlar |

<br></br>

## Docker Secrets

### `.env` Dosyası Nedir?

.env dosyası, ortam değişkenlerini (environment variables) merkezi ve okunabilir bir şekilde tanımlamanı sağlar. Özellikle şunlar için kullanılır:

- Parolalar
- API anahtarları
- Port bilgileri
- Versiyonlar
- Config ayarları


- Neden Kullanılır?
	- Ayrı bir yapılandırma katmanı sağlar (koddan bağımsız)
	- Kodun her yerde aynı kalır, ama .env içeriği farklı olabilir
	- Gizli bilgileri Dockerfile ya da docker-compose.yml içine gömmekten kurtarır

<br>

### Örnek `.env` Dosyası
```text
MYSQL_ROOT_PASSWORD=supersecret123
MYSQL_DATABASE=blog
MYSQL_USER=admin
MYSQL_PASSWORD=adminpass
PORT=8080
```

<br>

### `docker-compose.yml` İçinde `.env` Dosyası Kullanımı

```docker
version: '3.9'

services:
	db:
		image: mysql:5.7
		environment:
			- MYSQL_ROOT_PASSWORD=${MYSQL_ROOT_PASSWORD}
			- MYSQL_DATABASE=${MYSQL_DATABASE}
			- MYSQL_USER=${MYSQL_USER}
			- MYSQL_PASSWORD=${MYSQL_PASSWORD}
		ports:
			- "${PORT}:3306"
```

🟡 Not: `.env` dosyası `docker-compose.yml` dosyasıyla aynı dizinde olmalıdır.
🟢 Değişkenler `${VAR_ADI}` şeklinde çağrılır.

<br>

### Docker Secrets Nedir?

.env dosyası basittir ama güvenli değildir — çünkü dosya düz metin olarak sistemde durur. Bu nedenle gizli bilgiler için daha güvenli bir çözüm olan Docker Secrets kullanılır. Docker Secrets, özellikle Docker Swarm (clustering) ortamlarında şifreleri, API anahtarlarını güvenli bir şekilde saklamanı sağlar.

Not : Docker Swarm, birden fazla makineyi bir araya getirip tek bir birleşik yapı (cluster) gibi çalıştırmanı sağlar.

Avantajları
- Şifreler RAM’de tutulur –> disk üzerinde kalmaz
- Salt okunur şekilde container’a ulaşır
- .env dosyasına göre çok daha güvenlidir

<br>

### Docker Secrets Nasıl Kullanılır?

1. Secret Klasörü Oluştur
	```bash
	echo "my_secure_password" > db_password.txt
	```

2. Secret Olarak Tanıt
	```docker
	docker secret create db_password db_password.txt
	```

3. docker-compose.yml ile Kullanım (Docker Swarm’da çalışır)
	```docker
	version: '3.9'

	services:
	db:
		image: mysql:5.7
		secrets:
			- db_password
		environment:
			- MYSQL_ROOT_PASSWORD_FILE=/run/secrets/db_password

	secrets:
		db_password:
			external: true
	```

Açıklama:
- `secrets:` altında tanımlanıyor.
- Docker, bu dosyayı container içinde `/run/secrets/<secret_name>` altında mount eder.
- `_FILE` uzantılı environment değişkeniyle bu dosya okunur.

<br>

### .env ve Docker Secrets Farkları

| Özellik                 | `.env`                         | `Docker Secrets`                     |
|-------------------------|--------------------------------|--------------------------------------|
| Güvenlik                | Düşük (düz metin)              | Yüksek (RAM’de tutulur)              |
| Kullanım Alanı          | Her yerde                      | Sadece Docker Swarm                  |
| Ortam Değişkeni Desteği | Doğrudan                       | Dosya olarak verilir (_FILE)         |
| Erişim                  | Container başlarken env olarak | Container içinden salt okunur dosya  |
| Versiyon kontrolünde    | Dışlanmalı (.gitignore)        | Secret yöneticisi ile kontrol edilir |

<br>

### Docker Secret ve .env Özeti

`.env`
- Ortam değişkenlerini merkezi tutar.
- Kodun dışında yapılandırma sağlar.
- Geliştirme ortamlarında çok kullanışlı.

`Docker Secrets`
- Şifreleri ve gizli verileri güvenli saklar.
- Üretim (production) ortamlarında tercih edilir.
- Sadece Docker Swarm modunda çalışır.


<br></br>

## Docker Komutları

### Temel Docker Komutları

| Komut              | Açıklama                                                      |
|--------------------|---------------------------------------------------------------|
| `docker --version` | Docker’ın yüklü sürümünü gösterir.                            |
| `docker version`   | Client ve Server bilgilerini detaylı gösterir.                |
| `docker info`      | Sistem hakkında bilgi (container sayısı, storage driver, vs.) |
| `docker help`      | Tüm Docker komutlarını listeler.                              |


<br>

### Docker Image Komutları

- Image Oluşturma ve Listeleme
	| Komut                         | Açıklama                                              |
	|-------------------------------|-------------------------------------------------------|
	| `docker build -t image_adi .` | Bulunduğun klasördeki Dockerfile ile image oluşturur. |
	| `docker images`               | Sistemdeki tüm image’leri listeler.                   |
	| `docker rmi image_adi`        | Bir image’i siler.                                    |

<br>

- Image Detayları
	| Komut                      | Açıklama                                               |
	|----------------------------|--------------------------------------------------------|
	| `docker inspect image_adi` | Image hakkında detaylı JSON verisi verir.              |
	| `docker history image_adi` | Image’ın nasıl oluşturulduğunu katman katman gösterir. |

<br>

### Container Komutları (Docker Container)

- Container Oluşturma ve Çalıştırma
	| Komut                                        | Açıklama                             |
	|----------------------------------------------|--------------------------------------|
	| `docker run image_adi`                       | Image’tan container başlatır.        |
	| `docker run -it image_adi /bin/bash`         | Etkileşimli terminal ile çalıştırır. |
	| `docker run -d image_adi`                    | Arka planda container çalıştırır.    |
	| `docker run -p 8080:80 image_adi`            | Port yönlendirme yapar.              |
	| `docker run --name benimcontainer image_adi` | Container’a özel isim verir.         |

<br>

- Container Görüntüleme ve Yönetim
	| Komut                                | Açıklama                                             |
	|--------------------------------------|------------------------------------------------------|
	| `docker ps`                          | Çalışan container’ları listeler.                     |
	| `docker ps -a`                       | Tüm (çalışan + durdurulmuş) container’ları listeler. |
	| `docker start container_adi`         | Durdurulmuş container’ı başlatır.                    |
	| `docker stop container_adi`          | Çalışan container’ı durdurur.                        |
	| `docker restart container_adi`       | Yeniden başlatır.                                    |
	| `docker rm container_adi`            | Container’ı siler.                                   |
	| `docker logs container_adi`          | Container çıktısını gösterir.                        |
	| `docker exec -it container_adi bash` | Container içine terminal açar.                       |

<br>

### Volume (Veri Saklama) Komutları

| Komut                                          | Açıklama                             |
|------------------------------------------------|--------------------------------------|
| `docker volume create volume_adi`              | Yeni volume oluşturur.               |
| `docker volume ls`                             | Tüm volume’leri listeler.            |
| `docker volume inspect volume_adi`             | Volume hakkında detaylı bilgi verir. |
| `docker volume rm volume_adi`                  | Volume siler.                        |
| `docker run -v volume_adi:/path container_adi` | Container’a volume bağlar.           |

<br>

### Network (Ağ) Komutları

| Komut                                            | Açıklama                    |
|--------------------------------------------------|-----------------------------|
| `docker network ls`                              | Docker ağlarını listeler.   |
| `docker network create ag_adi`                   | Yeni bir ağ oluşturur.      |
| `docker network inspect ag_adi`                  | Ağı detaylı gösterir.       |
| `docker network connect ag_adi container_adi`    | Bir container’ı ağa bağlar. |
| `docker network disconnect ag_adi container_adi` | Container’ı ağdan çıkarır.  |

<br>

### Docker Compose (Çoklu Servis)

| Komut                  | Açıklama                                         |
|------------------------|--------------------------------------------------|
| `docker-compose up`    | Tüm servisleri başlatır.                         |
| `docker-compose up -d` | Arka planda başlatır.                            |
| `docker-compose down`  | Tüm servisleri durdurur ve container’ları siler. |
| `docker-compose build` | Dockerfile’lardan image oluşturur.               |
| `docker-compose logs`  | Servis loglarını gösterir.                       |

<br>

### Docker System Yönetimi

| Komut                    | Açıklama                                                  |
|--------------------------|-----------------------------------------------------------|
| `docker system df`       | Docker’ın ne kadar alan kullandığını gösterir.            |
| `docker system prune`    | Kullanılmayan her şeyi (image, container, network) siler. |
| `docker image prune`     | Boşta kalan image’leri siler.                             |
| `docker container prune` | Boşta kalan container’ları siler.                         |

<br>

### Dockerfile Komutları (Yazım Kuralları)

| Komut        | Açıklama                                      |
|--------------|-----------------------------------------------|
| `FROM`       | Hangi base image kullanılacak                 |
| `COPY`       | Dosya kopyalama                               |
| `ADD`        | Dosya veya URL’den ekleme                     |
| `WORKDIR`    | Çalışma klasörü ayarı                         |
| `RUN`        | Komut çalıştırma (örn. `RUN apt-get install`) |
| `CMD`        | Container başlarken çalışacak komut           |
| `ENTRYPOINT` | Container’a özel giriş noktası                |
| `EXPOSE`     | Hangi port açılacak                           |
| `ENV`        | Ortam değişkeni tanımı                        |
| `VOLUME`     | Kalıcı veri alanı tanımı                      |

<br></br>

## NGINX

### Nginx Nedir?

Nginx (engine-x), yüksek performanslı, açık kaynaklı bir web sunucusu, ters proxy (reverse proxy), yük dengeleyici (load balancer) ve HTTP cache’dir.

<br>

### Nginx’in Temel Kullanım Amaçları

| Amaç                | Açıklama                                                       |
|---------------------|----------------------------------------------------------------|
| Web Sunucusu        | Statik dosyaları (HTML, CSS, JS, resim vb.) sunar.             |
| Reverse Proxy       | İstekleri arka uçtaki sunuculara yönlendirir.                  |
| Load Balancer       | Trafiği birden fazla sunucuya dağıtarak yükü dengeler.         |
| SSL/TLS Termination | HTTPS trafiğini yönetir, sertifika ile şifreli bağlantı kurar. |

<br>

### Nginx’in Avantajları:
- Düşük kaynak tüketimi
- Yüksek eşzamanlı bağlantı desteği
- Kolay yapılandırma (nginx.conf)
- Event-driven mimari (Apache’den farklı olarak thread yerine event’leri kullanır)

<br>

### 443 Portu Nedir?

443 numaralı port, HTTPS (HTTP Secure) trafiği için kullanılan standart porttur.
- HTTP (port 80): Şifrelenmemiş trafiktir.
- HTTPS (port 443): SSL/TLS kullanarak verileri şifreler.

Web siteleri, kullanıcı ile sunucu arasındaki iletişimi güvenli hale getirmek için HTTPS (ve dolayısıyla 443 portu) kullanır.

<br>

### SSL ve TLS Nedir?

✅ SSL (Secure Sockets Layer)
- İnternet üzerindeki veri iletimini şifrelemek için geliştirilen ilk protokoldür.
- Netscape tarafından 1995’te geliştirilmiştir.
- Artık günümüzde kullanımı önerilmez çünkü eski ve güvenlik açıkları var.

✅ TLS (Transport Layer Security)
- SSL’in geliştirilmiş ve daha güvenli halidir.
- Günümüzde neredeyse tüm HTTPS bağlantıları TLS (özellikle TLS 1.2 ve 1.3) kullanır.
- Ama halk arasında hâlâ “SSL sertifikası” denir, aslında bu TLS sertifikasıdır.

<br>

### SSL / TLS Sertifikaları Nedir?

- Amaçları:
	- Kimlik doğrulaması sağlar (web sitesinin gerçekten o domaine ait olduğunu gösterir).
	- Sunucu ile istemci (tarayıcı) arasındaki iletişimi şifreler.
- Sertifika İçeriği:
	- Alan adı (domain)
	- Sertifika sahibi (organization)
	- Geçerlilik süresi
	- İmzalayan sertifika otoritesi (CA)
	- Anahtar bilgileri (public key)

<br>

### Sertifika Türleri:

| Tür                         | Açıklama                                   |
|-----------------------------|--------------------------------------------|
| DV (Domain Validated)       | Sadece alan adı doğrulanır (en yaygını).   |
| OV (Organization Validated) | Alan adı ve şirket doğrulanır.             |
| EV (Extended Validation)    | En yüksek güvenlik; yeşil adres çubuğu vb. |

<br>

### SSL ve TLS Arasındaki Farklar

| Özellik                | SSL                           | TLS                       |
|------------------------|-------------------------------|---------------------------|
| Geliştirici            | Netscape                      | IETF                      |
| En son sürüm           | SSL 3.0                       | TLS 1.3                   |
| Güvenlik durumu        | Eski ve kırılmıştır           | Modern ve güvenlidir      |
| Kullanım               | Artık önerilmez               | Güncel ve yaygın          |
| El sıkışma (handshake) | Daha yavaş, eski algoritmalar | Daha hızlı ve güvenli     |
| Desteklediği şifreleme | Zayıf algoritmalar içerir     | Güçlü algoritmalar içerir |

<br>

### HTTPS Bağlantısı Nasıl Çalışır?
1.	Tarayıcı https://example.com adresine istek gönderir.
2.	Sunucu sertifikasını gönderir.
3.	Tarayıcı sertifikayı kontrol eder (CA tarafından imzalanmış mı? Güvenilir mi?).
4.	TLS el sıkışması (handshake) yapılır:
	- Şifreleme algoritması ve anahtarlar belirlenir.
5.	Tarayıcı ile sunucu arasında güvenli (şifreli) bağlantı kurulur.

<br></br>

## WordPress

### WordPress Nedir?

WordPress, açık kaynak kodlu, PHP tabanlı, dünyanın en popüler içerik yönetim sistemi (CMS – Content Management System)’dir.

<br>

### WordPress Nasıl Çalışır?

Temel Bileşenler:

| Bileşen                       | Açıklama                                                                 |
|-------------------------------|--------------------------------------------------------------------------|
| PHP                           | WordPress’in yazıldığı dildir. Sunucu tarafında çalışır.                 |
| MySQL/MariaDB                 | WordPress veritabanıdır. Yazılar, kullanıcılar, ayarlar burada saklanır. |
| HTML + CSS + JS               | Tarayıcıya gönderilen sayfa içeriğidir.                                  |
| Web Sunucusu (Nginx / Apache) | PHP dosyalarını işler ve kullanıcıya sayfayı sunar.                      |

> Kısaca: Kullanıcı bir sayfa ister → Web sunucusu PHP dosyasını çalıştırır → Veritabanından veri çekilir → HTML sayfası oluşturulur → Tarayıcıya gönderilir.

<br>

### WordPress’in Yapısı

Dosya ve Klasörler:

| Dosya/Klasör              | Görevi                                                  |
|---------------------------|---------------------------------------------------------|
| wp-config.php             | Veritabanı bağlantı ayarları içerir.                    |
| wp-content/               | Temalar, eklentiler ve medya dosyaları burada yer alır. |
| wp-admin/                 | Yönetim paneli dosyaları.                               |
| wp-includes/              | Çekirdek WordPress fonksiyonları.                       |
| .htaccess veya nginx.conf | URL yönlendirme ve güvenlik ayarları yapılır.           |

<br>

### WordPress Veritabanı Ne İşe Yarar?

WordPress, MariaDB veya MySQL veritabanı kullanır. Veritabanı, web sitesine ait dinamik verileri depolar:

Örnek Tablolar:

| Tablo       | İçerik Türü                       |
|-------------|-----------------------------------|
| wp_posts    | Yazılar, sayfalar, özel içerikler |
| wp_users    | Kullanıcı hesapları               |
| wp_comments | Yorumlar                          |
| wp_options  | Site ayarları                     |
| wp_terms    | Kategoriler, etiketler            |

<br>

### WordPress ile HTTPS ve SSL

WordPress siteni güvenli hale getirmek için HTTPS kullanılır. Bu da SSL/TLS sertifikası gerektirir.

Nginx ile WordPress’te SSL:
- listen 443 ssl;
- ssl_certificate ve ssl_certificate_key
- WordPress ayarlarından site adresini https:// olarak ayarlamak gerekir.

Not: Eğer SSL yüklenmemişse, kullanıcılar uyarı alır (“Güvenli değil”).

<br>

### WordPress Kurulumu (Kısaca)

Kurulum sürecinde WordPress şu bilgileri ister:
1. Veritabanı adı
2. Veritabanı kullanıcı adı
3. Şifre
4. Veritabanı sunucusu (localhost ya da docker’da mariadb)

Sonrasında:
- Yönetici hesabı oluşturulur.
- Site adı ve dili belirlenir.
- Giriş yapılır ve site hazır olur.

<br>

### WordPress Admin Paneli

URL: https://seninsiten.com/wp-admin

Yapabileceklerin bazıları:
- Yazı/Sayfa oluşturmak
- Menü ve tema değiştirmek
- Eklenti kurmak
- Kullanıcı yönetimi
- Site ayarlarını değiştirmek

<br></br>

## MariaDB

### MariaDB Nedir?

MariaDB, açık kaynak kodlu, yüksek performanslı bir veritabanı yönetim sistemidir (DBMS).
MySQL’in özgür bir alternatifi olarak geliştirilmiştir ve WordPress gibi PHP uygulamalarıyla sıkça kullanılır.

<br>

### MariaDB Ne İşe Yarar?
MariaDB, web uygulamalarındaki verileri saklamak, düzenlemek ve sorgulamak için kullanılır.

MariaDB neyi saklar?
- Kullanıcı bilgileri
- Yazılar / içerikler (örneğin WordPress yazıları)
- Yorumlar
- Ayarlar
- Siparişler (E-ticaret sitelerinde)
- Log kayıtları

<br>

### MariaDB Nasıl Çalışır?

Yapısı:

| Bileşen               | Açıklama                                                              |
|-----------------------|-----------------------------------------------------------------------|
| Veritabanı (Database) | Bir uygulamaya ait tüm tablo, veri ve ilişkilerin toplandığı yapıdır. |
| Tablo (Table)         | Verilerin satır-sütun formatında saklandığı yapılardır.               |
| Satır (Row)           | Her satır bir kaydı temsil eder (örneğin bir kullanıcı).              |
| Sütun (Column)        | Verinin alan adıdır (ad, soyad, email vb.).                           |

<br>

### Temel MariaDB Komutları

```sql
-- Veritabanı oluştur
CREATE DATABASE ornek;

-- Veritabanı seç
USE ornek;

-- Tablo oluştur
CREATE TABLE kullanicilar
(
	id INT AUTO_INCREMENT PRIMARY KEY,
	isim VARCHAR(50),
	email VARCHAR(100)
);

-- Veri ekle
INSERT INTO kullanicilar (isim, email) VALUES ('Nisa', 'nisa@example.com');

-- Verileri listele
SELECT * FROM kullanicilar;
```

<br>

### MariaDB Güvenlik (Kullanıcı ve Şifre)

MariaDB, her bağlantı için kullanıcı adı ve şifre ister.
Veritabanına bağlanırken WordPress gibi sistemler şu bilgileri kullanır:
```conf
DB_HOST = mariadb
DB_NAME = wordpress
DB_USER = wp_user
DB_PASSWORD = wp_password
```

Bu bilgiler wp-config.php dosyasına veya .env dosyasına yazılır.

<br>

### MariaDB Docker Ortamında

Docker ile örnek kullanım (docker-compose.yml):
```yaml
services:
  mariadb:
    image: mariadb:latest
    restart: always
    environment:
      MYSQL_ROOT_PASSWORD: rootpass
      MYSQL_DATABASE: wordpress
      MYSQL_USER: wp_user
      MYSQL_PASSWORD: wp_pass
    volumes:
      - db_data:/var/lib/mysql

volumes:
  db_data:
```

Bu yapılandırma, MariaDB’yi çalıştırır ve veri kaybını önlemek için volume kullanır.

<br>

### MariaDB vs MySQL

| Özellik    | MariaDB                     | MySQL                          |
|------------|-----------------------------|--------------------------------|
| Lisans     | GPL (özgür)                 | Oracle (bazı sürümleri kapalı) |
| Performans | Genelde daha hızlı          | Biraz daha yavaş               |
| Topluluk   | Geniş açık kaynak topluluğu | Oracle merkezli                |
| Uyumluluk  | %100 MySQL uyumlu           | MariaDB ile uyumlu değil       |

<br>

### MariaDB Güvenliği

Güvenlik açısından MariaDB’de şunlara dikkat edilir:
- Root kullanıcısına şifre verilmelidir.
- Veritabanı kullanıcıları sadece ihtiyaç duyduğu veritabanına erişim iznine sahip olmalıdır.
- Veritabanı dışarıya açılmamalıdır (bind-address = 127.0.0.1 veya sadece docker network içinde erişim).
- Yedekleme ve şifreleme yapılmalıdır (mysqldump ile).

<br>

### WordPress ile Nasıl Entegre Olur?

1.	WordPress setup sırasında bu bilgileri ister:
	- DB_NAME
	- DB_USER
	- DB_PASSWORD
	- DB_HOST
2.	wp-config.php dosyasında bunlar kullanılır:
	```php
	define( 'DB_NAME', 'wordpress' );
	define( 'DB_USER', 'wp_user' );
	define( 'DB_PASSWORD', 'wp_pass' );
	define( 'DB_HOST', 'mariadb:3306' );
	```
3.	PHP uygulaması, MariaDB’ye mysqli veya PDO üzerinden bağlanır.

<br></br>
