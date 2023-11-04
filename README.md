# Exam Rank 02

Bütün exam_rank_02 sorularının işlevleriyle birlikte kodları bu repository'de yer almaktadır.

<br>

## Level 0 Fonksiyonları
|İsim               |Açıklaması                                    |
|:---               |:---                                          |
|first_word         |Programdır. Girilen argümanın ilk kelimesini yazdırır.|
|fizzbuzz           |Programdır. 1'den 100'e kadar olan sayıları yazdırır. Eğer sayı 3'e bölünüyorsa "fizz", 5'e bölünüyorsa "buzz", 3 ve 5'e bölünüyorsa "fizzbuzz" yazdırır.|
|ft_putstr          |Fonksiyondur. String yazdırmak için kullanılan bir fonksiyondur.|
|ft_strcpy          |Fonksiyondur. s1, başka bir diziye atanır, return olarak o atanan dizi döndürülüt. s2, s1'e kopyalanır.|
|ft_strlen          |Fonksiyondur. String'in uzunluğunu return eden fonksiyondur.|
|ft_swap            |Fonksiyondur. Fonksiyona girilen iki değerin yerini değiştiren fonksiyondur.|
|repeat_alpha       |Programdır. Girilen argümandaki harfleri, alfabedeki sıra numarası kadar ekrana yazdırır.|
|rev_print          |Programdır. Girilen argümanı tersten yazdırır.|
|rot_13             |Programdır. Girilen argümandaki harfleri 13 boşluk ileri taşır.|
|rotone             |Programdır. Girilen argümandaki harfleri 1 boşluk ileri taşır.|
|search_and_replace |Programdır. Girilen 1.argümandaki string'te 2.argümandaki harfi bulur ve 3.argümandaki harf ile yer değiştirerek ekrana yazdırır.|
|ulstr              |Programdır. Girilen argümandaki harfleri büyük ise küçük, küçük ise büyük harfe çevirerek yazdırır.|

<br>

## Level 1 Fonksiyonları
|İsim           |Açıklaması                                    |
|:---           |:---                                          |
|alpha_mirror   |Programdır. Girilen argümandaki her alfabetik karakteri karşıt alfabetik karakterle değiştirdikten sonra yazdırır.|
|camel_to_snake |Programdır. Girilen argüman "lowerCamelCase" biçimindedir, bunu "snake_case" biçimine dönüştürür.|
|do_op          |Programdır. Girilen 3 argüman vardır. 2.argümana göre 1 ve 3.argümanlar arasında matematiksel işlemler yapılır ve sonuç ekrana yazdırılır.|
|ft_atoi        |Fonksiyondur. ASCII değerleri integer'a çeviren fonksiyondur.|
|ft_strcmp      |Fonksiyondur. İki string'in ASCII olarak karşılaştırmasını (farkını) yapıp return eden fonksiyondur.|
|ft_strcspn     |Fonksiyondur. Verilen iki karakter dizisi (s ve reject) arasında bulunan bir alt dize içindeki karakterlerin ilk oluştuğu dizinin indeksini bulur. "s" dizisindeki karakterler, "reject" dizisindeki karakterlerle karşılaştırılır. Eğer bir karakter "reject" dizisinde bulunursa, bu karakterin bulunduğu dizinin indeksi döndürülür. Eğer hiçbir karakter "reject" dizisinde bulunmazsa, "s" dizisinin sonuna kadar kontrol edildikten sonra, "s" dizisinin uzunluğu döndürülür.|
|ft_strdup      |Fonksiyondur. Verilen karakter dizisinin hafızada ayrı bir kopyasını oluşturan ve bu kopyanın adresini döndüren bir fonksiyondur.|
|ft_strrev      |Fonksiyondur. Fonksiyon girdisi olan string'i tersine çevirir, return olarak ters çevrilmiş string'i döndürür.|
|inter          |Programdır. Girdi olarak 2 argüman alan ve her iki argümanda da geçen karakterleri 1.argümanda görünen sırayla çift kat olmadan yazdıran (iki kere yazdırmayan) bir program yazın.|
|is_power_of_2  |Fonksiyondur. Verilen bir sayının 2'nin kuvveti olup olmadığını belirleyen bir fonksiyondur. Return değerleri: verilen sayı 2'nin katıysa 1, aksi takdirde 0 döndürür.|
|last_word      |Programdır. Girilen argümandaki son kelimeyi yazdırır.|
|max            |Fonksiyondur. Foksiyon girdisi olan int dizisindeki en büyük sayıyı return eder; dizi boş ise return, 0 döndürür.|
|print_bits     |Fonksiyondur. Girdi olarak bir bayt alan ve onu sonunda yeni satır olmadan ikilik sistem (binary) olarak yazdıran bir fonksiyondur.|
|reverse_bits   |Fonksiyondur. Bir bayt alan, onu tersine çeviren bir fonksiyondur ve sonucu döndürür.|
|snake_to_camel |Programdır. "snake_case" formatında tek bir dizi alan ve onu "lowerCamelCase" biçiminde bir dizgeye dönüştüren bir program yazınız.|
|swap_bits      |Fonksiyondur. 4 bitlik bir yer değiştirme işlemi yaparak yeni bir değer döndüren bir fonksiyondur.|
|union          |Programdır. İki argüman alan ve argümanlardan herhangi birinde görünen karakterleri çift olmadan görüntüleyen bir program yazın. 1.argümandaki karakterler (çift olmadan) yazdırılır ardından 2.argümanda yazdırılmayan karakterler (çift olmadan) yazdırılır.|
|wdmatch        |Programdır. İki argüman alır. 1.argümandaki karakterlerin 2.argümandaki yazılma sırasına uyarak 1.argümanı 2.argümandaki karakterlerle yazmanın mümkün olup olmadığını kontrol eden bir program yazın.|

<br>

## Level 2 Fonksiyonları
|İsim             |Açıklaması                                    |
|:---             |:---                                          |
|add_prime_sum    |Programdır. Girilen pozitif tam sayıdan küçük veya eşit olan tüm asal sayıların toplamını yazdıran bir program yazın.|
|epur_str         |Programdır. Bir argüman alan ve bu argümanın sözcükleri arasında tam olarak 1 boşluk olacak şekilde, başında/sonunda boşluk veya sekme olmadan ve ardından bir \n gelecek şekilde görüntüleyen bir program yazın.|
|expand_str       |Programdır. Bir argüman alan ve bu argümanın sözcükleri arasında tam olarak 3 boşluk olacak şekilde, başında/sonunda boşluk veya sekme olmadan ve ardından bir \n gelecek şekilde görüntüleyen bir program yazın.|
|ft_atoi_base     |Fonksiyondur. Fonksiyona girilen tabanı kullanarak verilen karakter dizisini tamsayıya dönüştüren bir fonksiyondur.|
|ft_list_size     |Fonksiyondur. Kendisine iletilen bağlantılı listedeki öğelerin sayısını döndüren bir fonksiyon yazın. Oluşturulacak dosyalar: ft_list_size.c ve ft_list.h|
|ft_range         |Fonksiyondur. Fonksiyon girdisi olan bir başlangıç ve bitiş değeri arasındaki tamsayıları içeren bir tamsayı dizisi oluşturur.|
|ft_rrange        |Fonksiyondur. Fonksiyon girdisi olan iki tamsayı arasındaki değerleri büyükten küçüğe doğru bir dizi içerisinde saklayarak bu dizinin adresini döndürür.|
|hidenp           |Programdır. 2.argümanda 1.argümandaki her karakteri 1.argümandaki sırayla bulunuyorsa (1.argüman, 2.argümanda gizliyse) ekrana 1 yazdırılır, aksi halde 0 yazdırılır ve ardından yeni bir satır görüntülenir.|
|lcm              |Fonksiyondur. Verilen iki veya daha fazla sayının en küçük ortak katını hesaplayan bir matematiksel işlevdir. En küçük ortak kat, verilen sayıların her ikisini de tam bölen olduğu en küçük pozitif sayıdır.|
|paramsum         |Programdır. Girilen argüman sayısını yazdıran programdır.|
|pgcd             |Fonksiyondur. Verilen iki veya daha fazla sayının en büyük ortak bölenini (EBOB) hesaplayan bir matematiksel işlevdir. En büyük ortak bölen, verilen sayıların ortak bölenlerinden en büyük olanıdır.|
|print_hex        |Programdır. Argüman olarak 10 tabanında ifade edilen pozitif (veya sıfır) bir sayıyı alan ve bunu 16 tabanında (küçük harfler) yazdıran programdır.|
|rstr_capitalizer |Programdır. Bir veya daha fazla argüman alan ve her bağımsız argüman için, her kelimenin "son" karakteri büyük geri kalanını küçük harf olarak yazdıran ve ardından bir \n gösteren bir program yazın.|
|str_capitalizer  |Programdır. Bir veya daha fazla argüman alan ve her bağımsız argüman için, her kelimenin "ilk" karakteri büyük geri kalanını küçük harf olarak yazdıran ve ardından bir \n gösteren bir program yazın.|
|tab_mult         |Programdır. Argüman olarak girilen sayının 1'den 9'a kadar olan çarpım tablosunu ekrana yazdıran programı yazın.|

<br>

## Level 3 Fonksiyonları
|İsim              |Açıklaması                                    |
|:---              |:---                                          |
|flood_fill        |Fonksiyondur. Verilen "begin" t_noktasından başlayarak, bu işlev içindeki karakterleri 'F' karakteriyle değiştirerek tüm bölgeyi doldurur. Bölge, diğer karakterlerle veya dizi sınırıyla yatay ve dikey olarak sınırlandırılmış aynı karaktere sahip bir gruptur.|
|fprime            |Programdır. Pozitif bir int argümanı alır. Sayının asal çarpanlarını ve ardından yeni bir satır görüntüleyen bir program yazın. Faktörlerin artan sırada ve '*' ile ayrılarak gösterilmesi gerekir.|
|ft_itoa           |Fonksiyondur. Integer değerleri sonu null olan bir diziye çeviren fonksiyondur.|
|ft_list_foreach   |Fonksiyondur. Bir liste ve bir fonksiyon işaretçisi alan ve bu fonksiyonu listenin her öğesine uygulayan bir fonksiyon yazın.|
|ft_list_remove_if |Fonksiyondur. Verileri referans verilerine "eşit" olan herhangi bir öğeyi geçirilen listeden kaldıran bir fonksiyon yazın.|
|ft_split          |Programdır. Bir argüman alan, onu sözcüklere bölen ve bunları NULL ile sonlandırılmış bir dizi dizisi olarak döndüren bir fonksiyon yazın.|
|rev_wstr          |Programdır. Bir diziyi argüman olarak alan ve sözcüklerini ters sırada yazdıran bir program yazınız.|
|rostring          |Programdır. Bir diziyi argüman olarak alan ve bu dizinin ilk sözcüğünü sona taşıdıktan sonra görüntüleyen bir program yazınız.|
|sort_int_tab      |Fonksiyondur. Tamsayılardan oluşan bir diziyi sıralayarak küçükten büyüğe doğru düzenleyen bir fonksiyondur.|
|sort_list         |Fonksiyondur. Bağlı listedeki düğümleri belirli bir kritere göre sıralar.|
