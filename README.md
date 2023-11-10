# Minitalk Projesi
<br>

Projenin notlarına ulaşmak için [tıklayınız](https://github.com/nisaunnu/42_School_Curses/blob/minitalk/notes.md).

<br></br>

# Minitalk Projesi Nedir?
minitalk projesi, UNIX sinyallerini kullanarak veri değişim programını yazmayı amaçlar.

<br></br>

# Minitalk'ın Çalışma Mantığı
Projenin zorunlu bölümünde, "Client" ve "Server" olarak adlandırılan iki iletişim programı oluşturulmalıdır. Server başlatıldıktan sonra kendi PID'sini yazdırmalıdır. Client ise Server PID'si ve gönderilecek bir string alarak bu string'i server'a iletmelidir. Server, aldığı string'i hızlı bir şekilde görüntülemelidir. İletişim sadece UNIX sinyalleri (SIGUSR1 ve SIGUSR2) kullanılarak yapılmalıdır.

Proje, bonus bölümde UNICODE karakter desteği ve server'ın her mesajı onaylamak için client'a bir sinyal gönderme gibi ek özelliklere de olanak tanımaktadır.

<br></br>

# Projeyi Nasıl Çalıştırırım?
1.  İki terminal açın ve iki terminalde de `cd` komutu ile klasörün içerisine gidin.
2.  1.terminale `make` yazarak projenin derlemesini gerçekleştirin.
3.  `./server` yazın ve enter'a basın. Ekrana server'in PID'si yazdırılacaktır.
4.  2.terminale `./client <server_PID> <string>` yazın. server PID olarak 1.terminalde aldığınız PID numarasını girin. string olarak ise server'a göndermek istediğiniz metini girin. Ardından enter'a basın. Örnek: `./client 1212 "minitalk project"`
5.  2.terminale yazdığınız metini 1.terminalde artık görebilirsiniz.
