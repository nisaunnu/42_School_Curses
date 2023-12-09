<br>

# Fract-ol Projesi
Proje kodlarının detaylı açıklamasına ulaşmak için [tıklayınız](https://github.com/nisaunnu/42_School_Curses/tree/fractol/fractol_with_code_explanations)
<br></br>

## ❓ Fract-ol Projesi Nedir?
"fract-ol" projesi, fraktal görselleştirme programı oluşturmasını amaçlayan bir bilgisayar grafiği projesidir. Proje, MiniLibX kütüphanesini kullanmayı ve belirli fraktal türlerini (Julia kümesi ve Mandelbrot kümesi) görselleştirmeyi içerir. Ayrıca, fare tekerleği kullanılarak yakınlaştırma ve uzaklaştırma özelliklerini içermelidir. Projenin bonus kısmında bir fraktal daha eklemek, gerçek farenin konumunu takip ederek yakınlaştırma, yön tuşlarıyla hareket etmek, renk değiştirme bulunmaktadır.

Projenin temel amacı, grafik programlama konusunda deneyim kazandırmak ve görselleştirmeyi kullanarak fraktal matematiğini keşfettirmektir. Bu proje, MiniLibX’i tanımayı, karmaşık sayıların matematiksel kavramını keşfetmeyi/kullanmayı, bilgisayar grafiklerinde optimizasyon kavramını göz atmaya ve olay işleme alıştırması yapmak için bir fırsat olacaktır.
<br></br>

## ⚡️ Projeyi Nasıl Çalıştırırım?
<br>

1. Projeyi indirin ve indirdiğiniz dosyadan "push" dosyasını terminalde açın. Aşağıdaki komutu terminale yazarak projenin derlemesini gerçekleştirin:

	```rust
	make
	```
<br>

1. Giriş Formatı : `./fractol <fractol_tipi> <parametreler>`

	|İsim                     |Açıklama                           |
	|---                      |---                                |
	|fractol_tipi             |Julia, Mandelbrot veya Burning_ship|
	|parametreler (julia için)| -2 ile 2 arasında iki sayı girin  |

	Örnek:
	```rust
	./fractol Julia 1.2 0.2
	```

<br>

3. Özellikler :

	|Komut                                |Açıklama                                      |
	|---                                  |---                                           |
	|pencereyi kapatma                    | `ESC` tuşuna basın                           |
	|hareket ettirme                      | `← ↑ → ↓` veya sol fare tıklaması            |
	|yakınlaştırma / uzaklaştırma         | fare scroll'unu kaydırma                     |
	|renk değişimi                        | `C` tuşuna basın                             |
	|fare konumunu takip etme (julia için)| boşluk tuşuna basın ve fareyi hareket ettirin|
<br>

## 💡 Terminalde `memory leaks` Kontrolü
<br>

```markdown
leaks -q --atExit -- ./fractol <arg>
```

* `leaks`: Bellek sızıntılarını kontrol etmek için kullanılan komut.
* `-q` : Sessiz modda çalıştırır. Bu, işlem başlıklarını ve altbilgileri bastırmayarak çıktıyı daha sadeleştirir.
* `--atExit` : Bu bayrak, programın çalışması sona erdiğinde leaks'in otomatik olarak çalıştırılmasını sağlar. Yani, program sona erdiğinde leaks komutu otomatik olarak çalışacak ve bellek sızıntılarını kontrol edecektir.
* `--` : Bu, komut satırındaki seçeneklerin ve argümanların ayrıldığı bir işaret. Bu, daha sonra gelen ifadelerin seçenekler veya bayraklar olmadığını ve argümanlar olduğunu belirtir.
* `./fractol` : Bu, kontrol etmek istediğiniz programın çalıştırılabilir dosyasının yolunu belirtir. `./` işareti, programın mevcut dizininde bulunduğunu belirtir. Programınızın gerçek adını ve yoluyla değiştirilmelidir.
* `<arg>` : Bu, programınıza geçirilmek istenen argümandır. Eğer programınız argüman alıyorsa, bunu geçirmeniz gerekir. Eğer programınız daha fazla argüman alıyorsa, onları da bu noktada ekleyebilirsiniz.

Örnek:
```rust
leaks -q --atExit -- ./fractol Mandelbrot
```
```rust
leaks -q --atExit -- ./fractol Julia 0.2 1.2
```
<br></br>

## 📚 Yararlanılan Kaynaklar

* Dokümanlar:
	* MiniLibX Komutları ve Açıklamaları: [42 Docs](https://harm-smits.github.io/42docs/libs/minilibx/prototypes.html)
	* Julia Seti Hakkında Bilgiler: [Wikipedia - Julia](https://en.wikipedia.org/wiki/Julia_set)
	* Mandelbrot Seti Hakkında Bilgiler: [Wikipedia - Mandelbrot](https://en.wikipedia.org/wiki/Mandelbrot_set)
* Videolar:
	* MiniLibX'e Giriş: [MiniLibX](https://www.youtube.com/watch?v=bYS93r6U0zg&list=PLm0eL6m0aMkV4C9SxaFLvCBgeF5tRIT6Z&index=2)
	* Fraktal: [Fraktalların Oluşumları](https://www.youtube.com/watch?v=wUlVFYJIUNA)
	* Mandelbrot Fraktalı Oynatma Listesi: [Mandelbrot](https://www.youtube.com/playlist?list=PLt5AfwLFPxWL7NpD_DKO28XhS0Ugctkpu)
	* MiniLibX Komutlarını Kullanmak: [MiniLibX ile Bir Resim Çizmek](https://www.youtube.com/watch?v=9eAPbNUQD1Y&list=PLm0eL6m0aMkV4C9SxaFLvCBgeF5tRIT6Z&index=3)
