# 🍽️ Philosophers Projesi

Projenin notlarına ulaşmak için [tıklayınız](https://github.com/nisaunnu/42_School_Curses/blob/philosophers/notes.md)
<br></br>

## 💡 Philosophers Projesi Nedir?
Philosophers projesi, "Dining Philosophers" adlı klasik bir senkronizasyon problemini temsil etmektedir. Bu projede, bir grup filozofun bir masada oturup yemek yemesi, düşünmesi ve uyuması simüle edilmeye çalışılır. Bir program tasarlamak için verilen argümanlar:

- **[filozof_sayısı]**: Filozof sayısıdır (aynı zamanda çatal sayısıdır).
- **[ölme_zamanı]** (milisaniye cinsinden): Eğer bir filozof, son yemeğinin başlangıcından veya simülasyonun başlangıcından bu yana belirtilen sürede yemeye başlamamışsa ölür.
- **[yeme_zamanı]** (milisaniye cinsinden): Bir filozofun yemek yemesi için geçen süredir. Bu süre zarfında iki çatalı tutması gerekmektedir.
- **[uyku_zamanı]** (milisaniye cinsinden): Bir filozofun uykuda geçireceği süredir.
- **[her_filozof_yeme_zamanı_sayısı]** (isteğe bağlı argüman): Tüm filozoflar ***en az*** belirtilen sayıda yemek yemişse simülasyon durur.

Her filozofun bir numarası vardır ve 1 numaralı filozof, n.(filozof sayısı) filozofun yanında oturur. Diğer filozoflar birbirleriyle konuşmazlar. Çatallar, filozoflar arasında paylaşılan kaynaklar olduğu için çatal durumları (çatal sayısı, çatalı alma ve bırakma durumları) mutex ile korunur. Programın günlükleri şu durumları içerir:

- Filozofun çatal aldığı an.
- Filozofun yemek yediği an.
- Filozofun uyuduğu an.
- Filozofun düşündüğü an.
- Filozofun öldüğü an.

Filozoflar arasında veri yarışı (data race) olmamalıdır ve bir filozofun ölümü, gerçek ölümünden en fazla 10 ms sonra bildirilmelidir. Filozoflar, ölümden kaçınmalıdır ve simülasyon, belirtilen koşullar sağlandığında durmalıdır. Her filozof bir iplik (thread) olarak temsil edilir.
<br></br>

## ✨ Projeyi Nasıl Çalıştırırım?
1. Projeyi indirin ve indirdiğiniz dosyadan "philo" dosyasını terminalde açın. Aşağıdaki komutu terminale yazarak projenin derlemesini gerçekleştirin:

	```rust
	make
	```
<br>

2. Giriş Formatı : `./philo <filozof_sayısı> <ölme_zamanı> <yeme_zamanı> <uyku_zamanı> <her_filozof_yeme_zamanı_sayısı>`

   Örnek:
	```rust
	./philo 4 600 200 300 3
	```
<br></br>

## 🔍 Kontrol Yapılması için Gerekli Komutlar
1. `leaks` komutu ile leaks kontrolü:
	```rust
	leaks -q --atExit -- ./philo <filozof_sayısı> <ölme_zamanı> <yeme_zamanı> <uyku_zamanı> <her_filozof_yeme_zamanı_sayısı>
	```
2. `valgrind` ile leaks kontrolü:
	```rust
	valgrind --leaks-check=full ./philo <filozof_sayısı> <ölme_zamanı> <yeme_zamanı> <uyku_zamanı> <her_filozof_yeme_zamanı_sayısı>
	```
3. `ThreadSanitizer` ile data race kontrolü: Makefile'da CFLAG'inizin devamına aşağıdaki bayrakları ekleyin.
	```rust
	-fsanitize=thread -pthread
	```
