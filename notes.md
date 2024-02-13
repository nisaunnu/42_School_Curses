# 🍽️ Philosophers Notları
<br>

# 🖇️ İçerik
1. [Bilinmesi Gerekenler](#-bilinmesi-gerekenler)
2. [Kurallar](#-kurallar)
3. [Mandatory Part](#️-mandatory-part)
4. [Bellek Yönetimi ve Çeşitleri](#-bellek-yönetimi-ve-çeşitleri)
	- [Statik Bellek Yönetimi](#-statik-bellek-yönetimi)
	- [Dinamik Bellek Yönetimi](#-dinamik-bellek-yönetimi)
	- [Yerel ve Global Bellek Yönetimi](#-yerel-ve-global-bellek-yönetimi)
	- [Bellek Havuzları (Memory Pools)](#-bellek-havuzları-memory-pools)
5. [Paralel Programlama Nedir?](#-paralel-programlama-nedir)
6. [Process](#-process)
	- [Process (İşlem) Nedir?](#-process-i̇şlem-nedir)
	- [Process'in Temel Özellikleri](#-processin-temel-özellikleri)
	- [Process Durumları Nelerdir?](#-process-durumları-nelerdir)
7. [Thread](#-thread)
	- [Thread Nedir?](#-thread-nedir)
	- [Multithreading (Çoklu Thread) Nedir?](#-multithreading-çoklu-thread-nedir)
	- [Thread'lerin Temel Özellikleri](#-threadlerin-temel-özellikleri)
	- [Thread Neden Kullanılır?](#-thread-neden-kullanılır)
	- [Thread Nasıl Kullanılır?](#-thread-nasıl-kullanılır)
	- [Thread Fonksiyonları](#-thread-fonksiyonları)
	- [`pthread_join` Kullanılmazsa Ne Olur?](#-pthread_join-kullanılmazsa-ne-olur)
8. [Data Race](#-data-race)
	- [Data Race Nedir?](#-data-race-nedir)
	- [Data Race Hangi Durumlarda Çıkar?](#-data-race-hangi-durumlarda-çıkar)
	- [Data Race Durumu Nasıl Önlenir?](#-data-race-durumu-nasıl-önlenir)
9. [Mutex](#-mutex)
	- [Mutex Nedir ve Ne İşe Yarar?](#-mutex-nedir-ve-ne-i̇şe-yarar)
	- [Mutex'in Temel Görevleri](#-mutexin-temel-görevleri)
	- [Mutex Nasıl Kullanılır?](#-mutex-nasıl-kullanılır)
	- [Mutex Fonksiyonları](#-mutex-fonksiyonları)
10. [Semaphore](#-semaphore)
	- [Semaphore Nedir ve Ne işe Yarar?](#-semaphore-nedir-ve-ne-işe-yarar)
	- [Semaphore Nasıl Kullanılır?](#-semaphore-nasıl-kullanılır)
	- [Semaphore Fonksiyonları](#-semaphore-fonksiyonları)
11. [Semaphore ve Mutex Arasındaki Farklar](#-semaphore-ve-mutex-arasındaki-farklar)
12. [Fonksiyon Açıklamaları](#-fonksiyon-açıklamaları)
	- [`memset` fonksiyonu](#-memset-fonksiyonu)
	- [`printf` fonksiyonu](#-printf-fonksiyonu)
	- [`malloc` fonksiyonu](#-malloc-fonksiyonu)
	- [`free` fonksiyonu](#-free-fonksiyonu)
	- [`write` fonksiyonu](#-write-fonksiyonu)
	- [`usleep` fonksiyonu](#-usleep-fonksiyonu)
	- [`gettimeofday` fonksiyonu](#-gettimeofday-fonksiyonu)
	- [`pthread_create` fonksiyonu](#-pthread_create-fonksiyonu)
	- [`pthread_join` fonksiyonu](#-pthread_join-fonksiyonu)
	- [`pthread_detach` fonksiyonu](#-pthread_detach-fonksiyonu)
	- [`pthread_mutex_init` fonksiyonu](#-pthread_mutex_init-fonksiyonu)
	- [`pthread_mutex_destroy` fonksiyonu](#-pthread_mutex_destroy-fonksiyonu)
	- [`pthread_mutex_lock` ve `pthread_mutex_unlock` fonksiyonları](#-pthread_mutex_lock-ve-pthread_mutex_unlock-fonksiyonları)

<br></br>

## ¿ Bilinmesi Gerekenler

* Bir veya daha fazla filozof yuvarlak bir masada oturur. Masanın ortasında büyük bir kase spagetti vardır.
* Filozoflar alternatif olarak yemek yer, düşünür veya uyurlar. Yemek yerken ne düşünürler ne de uyurlar; düşünürken ne yemek yiyor ne de uyuyorlar; uyurken yemek yemiyorlar ve düşünmüyorlar.
* Masanın üzerinde çatallar bulunmaktadır. Filozofların sayısı kadar çatal vardır.
* Spagettiyi tek çatalla servis etmek ve yemek çok sakıncalı olduğundan, filozof yemek için sağ ve sol çatallarını her iki eline birer tane alır.
* Filozof yemeğini bitirdiğinde çatallarını tekrar masaya koyar ve uyumaya başlar. Uyandıklarında tekrar düşünmeye başlarlar. Bir filozof açlıktan öldüğünde simülasyon durur.
* Her filozofun yemek yemesi gerekir ve asla aç kalmamalıdır.
* Filozoflar birbirleriyle konuşmazlar.
* Filozoflar başka bir filozofun ölmek üzere olup olmadığını bilmiyorlar.
* Filozoflar ölmekten kaçınmalıdır.
<br></br>

## 📝 Kurallar

* Global değişkenler yasaktır!
* Program(lar)ınız aşağıdaki argümanları almalıdır:

	```rust
	[filozof_sayısı] [ölme_zamanı] [yeme_zamanı] [uyku_zamanı] [her_filozof_yeme_zamanı_sayısı]
	```
	* `[filozof_sayısı]`: Filozofların sayısı ve ayrıca çatalların sayısıdır.
	* `[ölme_zamanı] (milisaniye cinsinden)`: Eğer bir filozof, son yemeğinin başlangıcından veya simülasyonun başlangıcından bu yana milisaniye içinde ölme zamanı yemeye başlamamışsa ölür.
	* `[yeme_zamanı] (milisaniye cinsinden)`: Bir filozofun yemek yemesi için geçen süredir. Bu süre zarfında iki çatal tutmaları gerekecektir.
	* `[uyku_zamanı] (milisaniye cinsinden)`: Bir filozofun uykuda geçireceği süredir.
	* `[her_filozof_yeme_zamanı_sayısı] (isteğe bağlı argüman)`: Tüm filozoflar en az [her_filozof_yeme_zamanı_sayısı] kadar yemek yemişse simülasyon durur. Belirtilmemişse, bir filozof öldüğünde simülasyon durur.
* Her filozofun 1 ile filozof_sayısı arasında değişen bir numarası vardır.
* 1 numaralı Filozof, Filozof Sayılı Filozof'un yanında oturuyor. Diğer herhangi bir filozof numarası N, filozof numarası N - 1 ile filozof numarası N + 1 arasında yer alır.
* Programınızın günlükleri hakkında:
  * Bir filozofun herhangi bir durum değişikliği aşağıdaki gibi biçimlendirilmelidir:
    * timestamp_in_ms X çatal aldı
    * timestamp_in_ms X yemek yiyor
    * timestamp_in_ms X uyuyor
    * timestamp_in_ms X düşünüyor
    * timestamp_in_ms X öldü

	`Timestamp_in_ms` değerini milisaniye cinsinden geçerli zaman damgasıyla değiştirin ve `X`, filozof numarasıdır.

* Görüntülenen bir durum mesajı başka bir mesajla karıştırılmamalıdır.
* Bir filozofun öldüğünü bildiren mesaj, filozofun gerçek ölümünden en fazla 10 ms sonra görüntülenmelidir.
* Filozoflar yine ölmekten kaçınmalıdır.
* Programınızda herhangi bir **`veri yarışı (data race)`** olmamalıdır.
<br></br>

## ✏️ Mandatory Part

<br>
<html lang="en">
	<body>
		<table>
			<tr><td><b>Program adı</b></td><td>philo</td></tr>
			<tr><td><b>Teslim edilecek dosyalar</b></td><td>Makefile, *.h, *.c, in directory philo/</td></tr>
			<tr><td><b>Makefile</b></td><td>NAME, all, clean, fclean, re</td></tr>
			<tr><td><b>Argümanlar</b></td><td>[filozof_sayısı] [ölme_zamanı] [yeme_zamanı] [uyku_zamanı] [her_filozof_yeme_zamanı_sayısı]</td></tr>
			<tr><td><b>Harici fonksiyonlar</b></td><td>memset, printf, malloc, free, write, usleep, gettimeofday, pthread_create, pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock</td></tr>
			<tr><td><b>Libft kullanılabilir mi?</b></td><td>Hayır</td></tr>
			<tr><td><b>Açıklama</b></td><td>Thread ve mutex'leri olan filozoflar</td></tr>
		</table>
	</body>
</html><br></br>

* Her filozof bir **`iplik (thread)`** olmalıdır.
* Her filozof çifti arasında bir çatal bulunur. Dolayısıyla birden fazla filozof varsa her filozofun sol tarafında bir çatal, sağ tarafında ise bir çatal bulunur. Eğer tek bir filozof varsa, masada da tek bir çatal olmalıdır.
* Filozofların çatalları çoğaltmasını önlemek için, çatalların durumunu her biri için bir ,**`mutex`** ile korumalısınız.
<br></br>

## 🔹 Bellek Yönetimi ve Çeşitleri
Bellek yönetimi (memory management), bir bilgisayar sisteminde kullanılabilir belleğin etkili bir şekilde tahsis edilmesi, yönetilmesi ve serbest bırakılması sürecini içeren bir konsepttir. Bellek, bir bilgisayar programının çalıştığı sırada kullanılan verilerin depolandığı ve erişilebilir olduğu alandır. Bellek yönetimi, programların bellek ile etkileşimini düzenleyerek, bellek kullanımını optimize etmeyi ve bellek sızıntılarını önlemeyi amaçlar.

Bellek yönetimi genellikle şu temel işlevleri içerir:

1. **Bellek Tahsisi (Allocation):** Programlar çalışırken dinamik olarak bellek alanına ihtiyaç duyarlar. Bellek tahsisi, programın çalışması sırasında programın talep ettiği miktarda bellek alanının ayrılmasını içerir.

2. **Bellek Serbest Bırakma (Deallocation):** Artık kullanılmayan bellek alanının serbest bırakılması önemlidir. Aksi takdirde, bellek sızıntıları ortaya çıkabilir.

3. **Bellek İzleme (Memory Tracking):** Bellek yönetimi aynı zamanda bellek kullanımını izleyerek ve takip ederek performans ve güvenlik açısından değerlendirme yapmayı içerir. Bellek izleme araçları, programın bellek kullanımını analiz ederek sızıntıları veya bellek sorunlarını belirlemeye yardımcı olur.

4. **Fragmentasyon Yönetimi (Fragmentation Management):** Bellek alanındaki parçalanma (kullanılabilir bellek bloklarının küçük parçalara bölünmesi veya dağılması durumu), programların bellek kullanımını etkileyebilir. Fragmentasyon yönetimi, bellek alanındaki parçalanmayı azaltmak veya önlemek için çeşitli stratejileri içerir.

5. **Bellek Paylaşımı (Memory Sharing):** İki veya daha fazla program arasında bellek paylaşımı, bellek yönetimi sürecinin bir parçası olabilir. Özellikle işletim sistemleri, bellek paylaşımını kontrol ederek kaynakların daha etkili kullanılmasını sağlar.

Bellek yönetimi, bir programın performansını, güvenilirliğini ve güvenliğini önemli ölçüde etkileyebilir. Yanlış bellek yönetimi uygulamaları, bellek sızıntılarına, aşırı bellek tüketimine veya program çökmelerine yol açabilir. Bu nedenle, bellek yönetimi konseptleri, yazılım geliştiricileri ve sistem yöneticileri için kritik bir öneme sahiptir.
<br></br>

### 🔸 Statik Bellek Yönetimi
   - **Tanım:** Program derlendiğinde bellek alanları önceden belirlenir ve program çalıştığı süre boyunca değişmez.
   - **Örnek:**
     ```c
     int	main()
	 {
         int	array[100];  // Statik olarak bellek tahsisi
         int	staticVar = 10; // Statik bellek
         // (code)
         return 0;
     }
     ```
   - **Avantajlar:** Basit, hızlı ve öngörülebilir bellek kullanımı.
   - **Dezavantajlar:** Esneklik eksikliği, dinamik veri yapılarına uygun değil.

### 🔸 Dinamik Bellek Yönetimi
   - **Tanım:** Bellek alanları program çalışma zamanında tahsis edilir ve serbest bırakılabilir.
   - **Örnek:**
     ```c
     int	*dynamic_array = (int *)malloc(100 * sizeof(int));  // Dinamik bellek tahsisi
     // (code)
     free(dynamic_array);  // Belleği serbest bırakma
     ```
   - **Avantajlar:** Esneklik, dinamik veri yapılarına uygun, bellek kullanımında optimizasyon.
   - **Dezavantajlar:** Bellek sızıntıları veya hatalı bellek serbest bırakma riski.

### 🔸 Yerel ve Global Bellek Yönetimi
   - **Tanım:** Yerel bellek yönetimi, işlev çağrıları sırasında tanımlanan yerel değişkenlerin bellek yönetimini ifade eder. Global bellek yönetimi ise genellikle global değişkenlerin bellek yönetimini içerir.
   - **Örnek:**
     ```c
     int	global_variable;  // Global bellek yönetimi
     void	example_function()
	 {
         int	local_variable;  // Yerel (local) bellek yönetimi
         // (code)
     }
     ```

### 🔸 Bellek Havuzları (Memory Pools)
   - **Tanım:** Bellek havuzları, önceden belirlenmiş bir boyuttaki bellek bloklarının havuzunu oluşturur. Bu bloklar, ihtiyaç duyulan yerlerde kullanılır ve serbest bırakıldığında havuza geri döner.
<br></br>


## 🔹 Paralel Programlama Nedir?

Paralel programlama, bir bilgisayar programının aynı anda birden fazla işlemcide veya işlem biriminde çalışmasını sağlayan bir programlama yaklaşımıdır. Temelde, bir görevi daha hızlı ve verimli bir şekilde gerçekleştirmek veya büyük problemleri daha küçük parçalara bölerek çözmek amacıyla kullanılır.

>**Örnek 1:** bir yemek tarifi takip ediyorsunuz. Tarifin farklı adımları var, örneğin sebzeleri doğrama, eti pişirme ve sosu hazırlama. Paralel programlamada, her bir adımı farklı kişilere veya işlemcilere atayarak, her adımın aynı anda gerçekleştirilmesini sağlarsınız. Bu şekilde, yemeği daha hızlı ve daha etkili bir şekilde tamamlayabilirsiniz.

>**Örnek 2:** bir masaüstü bilgisayarın işlemcisinde birden fazla çekirdek olduğunu düşünün. Paralel programlama, bu çekirdekleri aynı anda farklı görevlerde kullanarak işlemleri hızlandırabilir. Bir öğrenci, bir görevi sırayla tamamlarken, paralel programlama kullanıldığında farklı öğrenciler aynı anda farklı görevleri yapabilir ve toplam süre azalır.

Kısacası, paralel programlama, işleri eşzamanlı olarak yürüterek işlem süresini azaltan bir stratejidir.

Paralel programlama, genellikle büyük veri setleri üzerinde veya karmaşık hesaplamalarda performansı artırmak, zaman alıcı işlemleri hızlandırmak veya genel sistem verimliliğini artırmak için kullanılır. Bilgisayarlar genellikle tek bir işlemci üzerinde çalışırken; paralel programlama, birden fazla işlemci, çekirdek veya bilgisayar düğümü üzerinde çalışarak performans avantajları elde etmeyi amaçlar.

Paralel programlama, bilgisayar donanımının evrimiyle birlikte daha yaygın hale gelmiştir çünkü günümüz bilgisayarları genellikle çoklu çekirdekli veya çoklu işlemci mimarilerine sahiptir. Paralel programlama, performans artışı sağlamak, enerji verimliliğini artırmak ve karmaşık problemleri daha etkili bir şekilde çözmek için yaygın olarak kullanılan bir tekniktir. Ancak paralel programlama, senkronizasyon ve veri tutarlılığı gibi zorlukları da içerir; dikkatli tasarım ve uygulama gerektirir.
<br></br>

## 🔹 Process

### 🔸 Process (İşlem) Nedir?
Bir işlem (process), bilgisayar sistemlerinde çalışan bir programın veya uygulamanın çalışma sırasında sahip olduğu çalışma ortamını ifade eder. Her process, kendi bellek alanına, çeşitli kaynaklara (CPU, giriş/çıkış aygıtları, dosya sistemleri vb.) ve process'i yöneten bir dizi özelliğe sahiptir. İşletim sistemleri, birden çok işlemi yönetme ve koordinasyon sağlama yeteneğine sahiptir.

### 🔸 Process'in Temel Özellikleri

1. **Bellek Alanı:** Her işlem, kendi adres alanına sahiptir. Bu adres alanı, process'in çalışma sırasında kullanabileceği bellek miktarını temsil eder.

3. **Kaynaklar:** İşlemler, CPU zamanı, dosya sistemleri, ağ bağlantıları gibi çeşitli kaynaklara ihtiyaç duyar. İşletim sistemi, bu kaynakları işlemler arasında adil bir şekilde dağıtarak yönetir.

4. **Çalışma Durumu:** İşlem, çalışma sırasında farklı durumlardan geçebilir. Bu durumlar arasında çalışan (running), bekleyen (waiting), hazır (ready) gibi durumlar bulunur.

>**Örnek :** Kullanıcı bir metin dosyasını açtığında, bu metin düzenleyici bir işlem (process) oluşturur. Bu işlem, kullanıcının metin üzerinde değişiklik yapmasına, kaydetmesine ve diğer işlemlerle etkileşimde bulunmasına olanak tanır. İşletim sistemi, bu işlemi diğer çalışan işlemlerle koordine eder ve gerekli kaynakları tahsis eder.

### 🔸 Process Durumları Nelerdir?
Bir işlemin çalışma durumları, işletim sistemi tarafından yönetilir ve işlemin hangi aşamada olduğunu gösterir. İşlemin durumu, işletim sistemi çekirdeği tarafından belirlenir ve sürekli olarak değişebilir. İşlemler, genellikle şu temel çalışma durumları arasında geçiş yapar:

1. **Başlatma (Start):** İşlem, başlatıldığında bu duruma girer. İşletim sistemi, işlemi oluşturur ve çalıştırmaya hazır hale getirir.

2. **Hazır (Ready):** İşlem, işlemci zamanını beklerken bu duruma geçer. İşletim sistemi, işlemi işlemciye atanmaya hazır durumda tutar. Birden çok işlem hazır durumda bekleyebilir, ve işletim sistemi işlemcilere adil bir şekilde zaman tahsis eder.

3. **Çalışan (Running):** İşlem, işlemci üzerinde çalışırken bu duruma girer. İşletim sistemi, işlemciyi işlemle ilişkilendirir ve işlem, talimatları gerçekleştirir.

4. **Bekleme (Waiting):** İşlem, bir olayın gerçekleşmesini beklerken bu duruma geçer. Bu olaylar genellikle giriş/çıkış işlemleri veya belirli bir koşulun sağlanması gibi durumları içerir.

5. **Sonlandırma (Termination):** İşlem, tamamlandığında veya sonlandırıldığında bu duruma geçer. İşletim sistemi, işlemin kaynakları serbest bırakır ve işlemi sonlandırır.

Bu durumlar, işlemin yaşam döngüsünü temsil eder. İşletim sistemi, işlemleri bu durumlar arasında geçiş yaparak etkili bir şekilde yönetir. İşletim sistemi, işlemleri adil bir şekilde sıralar, kaynakları etkili bir şekilde tahsis eder ve sistemdeki iş yükünü dengelemeye çalışır. Bu sayede çoklu görev (multitasking) ve paralel çalışma sağlanır.
<br></br>

## 🔹 Thread

### 🔸 Thread Nedir?
Thread (i̇ngilizce "thread" kelimesi "iplik" veya "iplikçik" anlamına gelir), bir program içindeki bağımsız çalışma birimlerini temsil eden işlemcilik yapılarıdır. Thread'ler, bir işlem içinde paralel olarak çalışan, kendi bağlamına sahip olan ve işlem kaynaklarını paylaşan küçük iş parçacıklarıdır. Thread'ler, bir program içindeki bağımsız çalışma birimlerini temsil eden ve aynı anda birden çok görevi yürüten işlemcilik yapılarıdır.

### 🔸 Multithreading (Çoklu Thread) Nedir?
Multithreading, bir bilgisayar programının veya bir işletim sisteminin, aynı anda birden çok iş parçacığını veya thread'i yürütme yeteneğidir. Bu, bir programın veya bir işlemcinin, aynı anda birden çok görevi eşzamanlı olarak gerçekleştirebilmesine olanak tanır. Multithreading, genellikle işlemci kaynaklarını daha etkili bir şekilde kullanma, daha hızlı tepki süreleri elde etme ve paralel programlama uygulama yeteneği sağlama amacıyla kullanılır.

### 🔸 Thread'lerin Temel Özellikleri
1. **Hafiflik:** Thread'ler, işlemlere göre daha hafif yapılardır. İşlemci zamanını daha etkili kullanmaya olanak tanır ve çoklu görev (multitasking) için idealdir.

2. **Paylaşılan Bellek:** Bir işlem içindeki thread'ler, aynı bellek alanını paylaşırlar. Bu, veri paylaşımını kolaylaştırır ancak dikkatli kullanım gerektirir, çünkü veri bütünlüğünü sağlamak önemlidir.

3. **Hızlı İletişim:** Thread'ler, aynı işlem içinde oldukları için iletişimleri genellikle daha hızlıdır. Bu, iş parçacıkları arasında veri paylaşımının ve senkronizasyonun daha etkili olmasını sağlar.

4. **Eşzamanlılık (Concurrency):** Thread'ler, aynı işlem içinde eşzamanlı olarak çalışabilirler. Bu, özellikle çoklu işlemlerin veya görevlerin aynı anda gerçekleştirilmesi gereken durumlarda faydalıdır.

### 🔸 Thread Neden Kullanılır?
1. **Paralel İşleme (Concurrency):** Thread'ler, aynı program içinde eşzamanlı olarak çalışabilirler. Bu, bir programın birden çok görevi aynı anda yürütmesine olanak tanır. Örneğin, bir web tarayıcısı aynı anda birden çok sekme üzerinde çalışabilir; her sekme farklı bir thread tarafından yönetilebilir.

2. **Daha Hızlı Tepki Süresi:** Thread'ler, kullanıcı arayüzü gibi etkileşimli uygulamalarda daha hızlı tepki süreleri sağlar. Ana program, kullanıcı girişine yanıt verirken, arka planda çalışan thread'ler diğer görevleri yürütebilir.

3. **Veri Paylaşımı:** Thread'ler, aynı program içinde paylaşılan bellek alanını kullanırlar. Bu sayede thread'ler arasında veri paylaşmak ve iletişim kurmak daha kolaydır. Ancak bu özellik dikkatlice yönetilmelidir, çünkü veri bütünlüğünü sağlamak önemlidir.

4. **İşlemci Zamanının Daha Etkin Kullanımı:** Thread'ler, işlemcilik kaynaklarını daha etkili bir şekilde kullanmaya yardımcı olur. Bir işlem içindeki farklı thread'ler, işlemci zamanını daha verimli kullanabilirler.

5. **İş Parçacığı (Thread) Havuzu:** Çoklu iş parçacığı havuzları, belirli bir görevi yerine getirmek üzere kullanılabilecek önceden oluşturulmuş thread'leri içerir. Bu havuzlar, thread oluşturma maliyetini azaltarak performansı artırabilir.

### 🔸 Thread Nasıl Kullanılır?

1. **İlgili Kütüphanenin Eklenmesi veya İçe Aktarılması:**
   İlk adım olarak, thread'leri kullanabilmek için programlama dilinizin veya kullanacağınız ortamın ilgili kütüphanesini eklemelisiniz. Örneğin: C dilinde `pthread` kütüphanesi.

   ```c
   #include <pthread.h>
   ```

2. **Thread Fonksiyonunu Tanımlama:**
   Bir thread, bir fonksiyonu yürüten bir iş parçacığıdır. Bu nedenle, thread'iniz tarafından çalıştırılacak fonksiyonu tanımlamalısınız. Bu fonksiyon, thread'in görevini gerçekleştirecek olan kodu içermelidir.

   ```c
   void	*myThreadFunction(void *arg) // Thread fonksiyonunu tanımlamak
   {
       // Thread'in yapacağı işlemleri burada tanımla
       return NULL;
   }
   ```

3. **Thread Oluşturma:**
   Thread oluşturmak için ilgili kütüphanenin sağladığı fonksiyonu kullanmalısınız. Bu fonksiyon yeni bir thread oluşturur ve başlatır. Örnekte, `pthread_create` fonksiyonu yeni bir thread oluşturur ve `myThreadFunction` fonksiyonunu başlatır. `result` değişkeni, thread oluşturmanın başarılı olup olmadığını kontrol etmek için kullanılır.

   ```c
   void	*myThreadFunction(void *arg) // Thread fonksiyonunu tanımlamak
   {
       // Thread'in yapacağı işlemleri burada tanımla
       return NULL;
   }

   pthread_t myThread; // Thread değişkenini tanımlamak

   int result = pthread_create(&myThread, NULL, myThreadFunction, NULL); // Thread oluşturmak

   if (result != 0)
   {
       // Thread oluşturma hatası
       // Hata kodunu kontrol et
   }
   ```

4. **Thread'in Tamamlanmasını Bekleme:**
   Eğer bir thread'in tamamlanmasını beklemek istiyorsanız, `pthread_join` fonksiyonunu kullanabilirsiniz. Bu, ana programın belirli bir thread'in tamamlanmasını beklemesini sağlar.

   ```c
   int joinResult = pthread_join(myThread, NULL); // Thread'in tamamlanmasını beklemek

   if (joinResult != 0)
   {
       // Thread'in tamamlanmasını beklerken bir hata oluştu
       // Hata kodunu kontrol et
   }
   ```

5. **Thread'i Sonlandırma:**
   Eğer bir thread'in işlevini tamamladıktan sonra sonlandırılmasını istiyorsanız, ilgili kütüphanenin sağladığı fonksiyonları kullanarak thread'i sonlandırabilirsiniz.

   ```c
   pthread_exit(NULL); // Thread'i sonlandırmak (pthread kütüphanesi ile)
   ```

### 🔸 Thread Fonksiyonları

1. **`pthread_create`**
   - **Amaç:** Yeni bir thread oluşturur ve belirtilen fonksiyonu çalıştırır.
   - **Prototip:** `int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);`
   - **Parametreler:**
     - `thread`: Oluşturulan thread'in tanımlayıcısı.
     - `attr`: Thread özelliklerini belirten bir yapı. Genellikle `NULL` kullanılır.
     - `start_routine`: Thread'in çalıştıracağı fonksiyonun işlev işaretcisi.
     - `arg`: `start_routine` fonksiyonuna geçirilecek argüman.
   - **Return Değeri:**
     - Başarı durumunda `0`, hata durumunda hata kodu.

   - **Örnek:**
     ```c
     #include <pthread.h>
     #include <stdio.h>

     void *threadFunction(void *arg)
	 {
         printf("Hello from the thread!\n");
         return NULL;
     }

     int main()
	 {
         pthread_t myThread;
         int result = pthread_create(&myThread, NULL, threadFunction, NULL);

         if (result != 0)
         {
             fprintf(stderr, "Thread creation failed: %d\n", result);
             return 1;
         }

         return 0;
     }
     ```

2. **`pthread_join`**
   - **Amaç:** Belirtilen thread'in tamamlanmasını bekler.
   - **Prototip:** `int pthread_join(pthread_t thread, void **retval);`
   - **Parametreler:**
     - `thread`: Beklenecek thread'in tanımlayıcısı.
     - `retval`: Thread'in dönüş değerini alacak bir işaretçi. (Opsiyonel, `NULL` olabilir)
   - **Return Değeri:**
     - Başarı durumunda `0`, hata durumunda hata kodu.

   - **Örnek:**
     ```c
     #include <pthread.h>
     #include <stdio.h>

     void *threadFunction(void *arg)
	 {
         printf("Hello from the thread!\n");
         return NULL;
     }

     int main()
	 {
         pthread_t myThread;
         int result = pthread_create(&myThread, NULL, threadFunction, NULL);

         if (result != 0)
		 {
             fprintf(stderr, "Thread creation failed: %d\n", result);
             return 1;
         }

         // Main thread devam ederken yeni thread çalışıyor

         pthread_join(myThread, NULL); // Yeni thread'in tamamlanmasını bekle

         return 0;
     }
     ```

3. **`pthread_exit`**
   - **Amaç:** Çalışan thread'i sonlandırır.
   - **Prototip:** `void pthread_exit(void *retval);`
   - **Parametreler:**
     - `retval`: Thread'in dönüş değeri.
   - **Return Değeri:**
     - Yok (Program sona erir).

   - **Örnek:**
     ```c
     #include <pthread.h>
     #include <stdio.h>

     void *threadFunction(void *arg)
	 {
         printf("Hello from the thread!\n");
         pthread_exit(NULL); // Thread'i sonlandır
     }

     int main()
	 {
         pthread_t myThread;
         int result = pthread_create(&myThread, NULL, threadFunction, NULL);

         if (result != 0)
		 {
             fprintf(stderr, "Thread creation failed: %d\n", result);
             return 1;
         }

         // Main thread devam ederken yeni thread çalışıyor

         pthread_join(myThread, NULL); // Yeni thread'in tamamlanmasını bekle

         return 0;
     }
     ```

4. **`pthread_detach`**
   - **Amaç:** Belirtilen thread'in başka bir thread tarafından beklenmeden kaynaklarını serbest bırakmasını sağlar. Bu işlev, bir thread'in sonlanması durumunda otomatik olarak kaynaklarını temizlemek için kullanılır.
   - **Prototip:** `int pthread_detach(pthread_t thread);`
   - **Parametreler:**
     - `thread`: Kaynakları serbest bırakılacak olan thread'in tanımlayıcısı.
   - **Return Değeri:**
     - Başarı durumunda `0`, hata durumunda hata kodu.

   - **Örnek:**
     ```c
     #include <pthread.h>
     #include <stdio.h>

     void *threadFunction(void *arg)
	 {
         printf("Thread is running...\n");
         return NULL;
     }

     int main()
	 {
         pthread_t myThread;
         int result = pthread_create(&myThread, NULL, threadFunction, NULL);

         if (result != 0)
		 {
             fprintf(stderr, "Thread creation failed: %d\n", result);
             return 1;
         }

         result = pthread_detach(myThread); // pthread_detach ile thread'i detached yap
         if (result != 0)
		 {
             fprintf(stderr, "Thread detachment failed: %d\n", result);
             return 1;
         }

         // Main thread devam ederken detached thread çalışıyor
         // pthread_join(myThread, NULL); // detached thread'i beklemeye gerek yok

         return 0;
     }
     ```

## 🔸 `pthread_join` Kullanılmazsa Ne Olur?
Eğer `pthread_join` kullanılmazsa; ana program devam edebilir, ana program sonlanabilir veya iş parçacığı (thread) tamamlanmadan önce sona erebilir. Bu durumda, iş parçacığı (thread) başlatılmış olabilir ancak ana program, iş parçacığının tamamlanmasını beklemeksizin devam eder veya sonlanır.

Bu durumun bazı olası etkileri şunlar olabilir:

1. **İş Parçacığı (Thread) Tamamlanmadan Kaynak Sorunları:** İş parçacığı, kaynakları (bellek, dosya kolları, vb.) kullanıyor olabilir. Eğer ana program, iş parçacığı tamamlanmadan sona erirse, iş parçacığı bu kaynakları serbest bırakma şansına sahip olmayabilir. Bu durumda kaynak sızıntıları oluşabilir.

2. **Veri Yarışları ve Beklenmeyen Davranışlar:** İş parçacığı ve ana program arasında paylaşılan veriler varsa ve senkronizasyon mekanizmaları kullanılmıyorsa, beklenmeyen davranışlar ve veri yarışları ortaya çıkabilir. İş parçacığı ve ana program arasındaki senkronizasyon olmadan paylaşılan verilere erişim, belirsiz sonuçlara yol açabilir.

3. **Programın Kapatılması Önce İş Parçacığının Tamamlanmaması:** İş parçacığı, belirli bir görevi yerine getirmek üzere başlatılmış olabilir. Eğer ana program iş parçacığının tamamlanmasını beklemeksizin sona erirse, iş parçacığı bu görevi tamamlamadan kapatılabilir, ve bu da programın beklendiği gibi çalışmamasına neden olabilir.

Böylelikle, iş parçacığı (thread) tamamlanana kadar beklemek için `pthread_join` kullanmak genel olarak iyi bir uygulama pratiğidir. Bu fonksiyon, iş parçacığının bitişini bekleyerek, kaynakların düzgün bir şekilde serbest bırakılmasını ve diğer temizleme işlemlerinin yapılmasını  ya da ana programın zamansız sonlanmamasını sağlar.

<br></br>

## 🔹 Data Race

### 🔸 Data Race Nedir?
Data Race (Veri Yarışı), çoklu iş parçacığı (thread) veya işlem (process) ortamlarında paylaşılan bir değişkenin eşzamansız (asenkron) erişimi sonucu ortaya çıkan bir durumdur. Bu durum, en az iki iş parçacığının aynı anda bir değişkeni okuması veya yazması sonucunda gerçekleşir. Data race, genellikle programın istikrarsız hale gelmesine, hatalı sonuçlara ve beklenmeyen davranışlara neden olan bir senkronizasyon hatası türüdür.

### 🔸 Data Race Hangi Durumlarda Çıkar?
Data race durumları, özellikle çoklu iş parçacığı programlaması veya paralel programlama bağlamında ortaya çıkar. Data race, şu durumlarda görülebilir:

1. **Yarış Koşulları (Race Conditions):** Birden çok iş parçacığı aynı veriye eşzamanlı eriştiğinde ve en az biri bu veriyi değiştiriyorsa, yarış koşulları meydana gelir. Bu durum, programın istenmeyen sonuçlar üretmesine yol açabilir.

2. **Atomic Olmayan İşlemler:** Bazı işlemler, tek bir adımda tamamlanmayabilir ve işlem aşamasında bir başka iş parçacığı tarafından kesilebilir. Bu durum, veriye eşzamanlı erişimde sorunlara yol açabilir.

### 🔸 Data Race Durumu Nasıl Önlenir?
Data race durumlarından kaçınmak için, paylaşılan veriye erişimi kontrol etmek için senkronizasyon mekanizmaları kullanılmalıdır. Mutex, semafor, kilit vb. gibi araçlarla uygun şekilde koruma sağlanmalıdır. Ayrıca, atomik işlemler ve senkronizasyon tekniklerinin doğru bir şekilde kullanılması önemlidir. Data race durumlarının önlenmesi, paralel programlamada güvenilir ve istikrarlı bir uygulama geliştirmenin önemli bir adımıdır.

<br></br>

## 🔹 Mutex

### 🔸 Mutex Nedir ve Ne İşe Yarar?
Mutex (MUTual EXclusion), paralel programlamada kullanılan bir senkronizasyon mekanizmasıdır. Aynı anda sadece bir thread'in belirli bir kaynağı (veriyi veya kod bloğunu) kullanmasını sağlar. Bu, aynı anda birden fazla thread'in aynı kaynağa müdahale etmesini önleyerek veri bütünlüğünü korur.

### 🔸 Mutex'in Temel Görevleri
1. **Kritik Bölgeyi Koruma:** Birden çok thread'in aynı anda erişimine uygun olan kritik bir bölgeyi korur. Kritik bölge, paylaşılan veri veya kaynaklara erişim gerektiren kod bloğunu ifade eder.

2. **Senkronizasyon Sağlama:** Thread'ler arasındaki işbirliğini sağlamak için kullanılır. Örneğin, bir thread'in tamamlanmasını beklemek veya belirli bir durumu diğer thread'lere bildirmek için mutex kullanılabilir.

### 🔸 Mutex Nasıl Kullanılır?
1. **Mutex Oluşturma:** `pthread_mutex_init` fonksiyonu ile bir mutex oluşturulur.

3. **Kritik Bölgeye Giriş:** `pthread_mutex_lock` fonksiyonu ile kritik bölgeye giriş yapılır. Eğer başka bir thread bu mutex'i kilitlediyse, bekler.

5. **Kritik Bölge İşlemleri:** Mutex kilitlendikten sonra kritik bölgedeki işlemler gerçekleştirilir.

7. **Kritik Bölgeden Çıkış:** `pthread_mutex_unlock` fonksiyonu ile kilit açılarak kritik bölgeden çıkılır.

9. **Mutex'i Yok Etme:** `pthread_mutex_destroy` fonksiyonu ile mutex yok edilir.

### 🔸 Mutex Fonksiyonları
1. **`pthread_mutex_init`**
   - **Amaç:** Mutex (Karşılıklı dışlama) tanımlar.
   - **Prototip:** `int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);`
   - **Parametreler:**
     - `mutex`: İlklenen mutex'in işaretçisi.
     - `attr`: Mutex özelliklerini belirten bir yapı. Genellikle `NULL` kullanılır.
   - **Return Değeri:**
     - Başarı durumunda `0`, hata durumunda hata kodu.

   - **Örnek:**
     ```c
     #include <pthread.h>
     #include <stdio.h>

     pthread_mutex_t myMutex;

     void *threadFunction(void *arg)
	 {
         pthread_mutex_lock(&myMutex); // Mutex'i kilitle
         printf("Thread locked the mutex.\n");
         pthread_mutex_unlock(&myMutex); // Mutex'i aç
         return NULL;
     }

     int main()
	 {
         pthread_t myThread;
         int result = pthread_create(&myThread, NULL, threadFunction, NULL);

         if (result != 0)
		 {
             fprintf(stderr, "Thread creation failed: %d\n", result);
             return 1;
         }

         pthread_mutex_init(&myMutex, NULL); // Mutex'i başlat

         // Main thread devam ederken yeni thread çalışıyor

         pthread_join(myThread, NULL); // Yeni thread'in tamamlanmasını bekle

         pthread_mutex_destroy(&myMutex); // Mutex'i yok et

         return 0;
     }
     ```

2. **`pthread_mutex_destroy`**
   - **Amaç:** Mutex'in bellekten serbest bırakılmasını sağlar. Mutex kullanımı sona erdiğinde, bu fonksiyonun çağrılması önerilir.
   - **Prototip:** `int pthread_mutex_destroy(pthread_mutex_t *mutex);`
   - **Parametreler:**
     - `mutex`: Yok edilecek mutex'in işaretçisi.
   - **Return Değeri:**
     - Başarı durumunda `0`, hata durumunda hata kodu.

   - **Örnek:**
     ```c
     #include <pthread.h>
     #include <stdio.h>

     pthread_mutex_t myMutex;

     int main()
	 {
         int result = pthread_mutex_init(&myMutex, NULL); // Mutex'i başlat

         if (result != 0)
		 {
             fprintf(stderr, "Mutex initialization failed: %d\n", result);
             return 1;
         }

         // Mutex'i kullan

         result = pthread_mutex_destroy(&myMutex); // Mutex'i yok et

         if (result != 0)
		 {
             fprintf(stderr, "Mutex destruction failed: %d\n", result);
             return 1;
         }

         return 0;
     }
     ```

3. **`pthread_mutex_lock` ve `pthread_mutex_unlock`**
   - **Amaç:** Mutex'i kilitleme (lock) ve kilidi açma (unlock) işlemlerini gerçekleştirir.
   - **Prototip (lock):** `int pthread_mutex_lock(pthread_mutex_t *mutex);`
   - **Prototip (unlock):** `int pthread_mutex_unlock(pthread_mutex_t *mutex);`
   - **Parametreler:**
     - `mutex`: İlgili mutex'in işaretçisi.
   - **Return Değeri:**
     - Başarı durumunda `0`, hata durumunda hata kodu.

   - **Örnek:**
     ```c
     #include <pthread.h>
     #include <stdio.h>

     pthread_mutex_t myMutex;

     void *threadFunction(void *arg)
	 {
         pthread_mutex_lock(&myMutex); // Mutex'i kilitle
         printf("Thread locked the mutex.\n");
         pthread_mutex_unlock(&myMutex); // Mutex'i aç
         return NULL;
     }

     int main()
	 {
         pthread_t myThread;
         int result = pthread_create(&myThread, NULL, threadFunction, NULL);

         if (result != 0)
		 {
             fprintf(stderr, "Thread creation failed: %d\n", result);
             return 1;
         }

         pthread_mutex_init(&myMutex, NULL); // Mutex'i başlat

         // Main thread devam ederken yeni thread çalışıyor

         pthread_join(myThread, NULL); // Yeni thread'in tamamlanmasını bekle

         pthread_mutex_destroy(&myMutex); // Mutex'i yok et

         return 0;
     }
     ```
<br></br>

## 🔹 Semaphore

### 🔸 Semaphore Nedir ve Ne işe Yarar?
Semaphore, paralel programlamada ve işletim sistemlerinde kullanılan bir senkronizasyon nesnesidir. Ana olarak, kaynaklara erişimi düzenlemek ve koordine etmek amacıyla kullanılır. Semaphore, bir sayıyı temsil eder ve bu sayı, belirli bir kaynağa aynı anda kaç thread'in erişebileceğini kontrol etmek için kullanılır. Semaphore'lar, özellikle çoklu thread'li (multithreading) ve paralel programlamanın olduğu ortamlarda, kaynakların güvenli bir şekilde paylaşılmasını ve senkronize edilmesini sağlar.

### 🔸 Semaphore Nasıl Kullanılır?
1. **Binary Semaphore (İkili Semaphore):** Yalnızca 0 ve 1 değerlerini alabilen bir semaphore türüdür. Bu tür bir semaphore genellikle bir kaynağın mevcudiyetini veya kullanılabilirliğini temsil eder. 0, kaynağın kullanımda olduğunu, 1 ise kaynağın boşta olduğunu gösterir.

    - **Semaphore Oluşturma:** `sem_init` fonksiyonu ile oluşturulur.
    - **Semaphore Bekleme (Wait):** `sem_wait` fonksiyonu ile gerçekleştirilir. Eğer semaphore değeri 0 ise, bekler.
    - **Semaphore Arttırma (Post):** `sem_post` fonksiyonu ile gerçekleştirilir. Semaphore değerini artırır.

2. **Counting Semaphore (Sayım Semaphore):** Belirli bir sayıya kadar değer alabilen bir semaphore türüdür. Bu tür semaphore, aynı anda belirli sayıda thread'in belirli bir kaynağa erişimini kontrol etmek için kullanılır. Semaphore kullanımı şu adımları içerir:

   - **Semaphore Oluşturma:** `sem_init` fonksiyonu ile bir semaphore oluşturulur.
   - **Kaynağa Erişim İçin Bekleme:** `sem_wait` fonksiyonu ile semaphore değeri kontrol edilir. Eğer 0 ise, beklenir ve değer azaltılır.
   - **Kaynağa Erişim:** Semaphore kontrolü sağlandıktan sonra belirli bir kaynağa erişim sağlanır.
   - **Semaphore Değerini Arttırma:** `sem_post` fonksiyonu ile semaphore değeri artırılır, kaynağın serbest olduğunu belirtir.
   - **Semaphore'i Yok Etme:** `sem_destroy` fonksiyonu ile semaphore yok edilir.

### 🔸 Semaphore Fonksiyonları
1. **`sem_init`**
   - **Amaç:** Bir semaforu başlatmak için kullanılır.
   - **Prototip:** `int sem_init(sem_t *sem, int pshared, unsigned int value);`
   - **Parametreler:**
     - `sem`: Başlatılacak semaforun işaretçisi.
     - `pshared`: Semaforun paylaşılıp paylaşılmayacağını belirten parametre. Eğer 0 ise, semafor sadece aynı süreç içindeki thread'ler arasında paylaşılır. 0'dan farklı bir değerse, semafor aynı süreç içindeki tüm thread'ler ve süreçler arasında paylaşılır.
     - `value`: Semaforun başlangıç değeri.
   - **Return Değeri:**
     - Başarı durumunda 0, hata durumunda -1 döner.

   - **Örnek:**
		```c
		#include <semaphore.h>
		#include <stdio.h>

		int main()
		{
			sem_t mySemaphore;
			int initValue = 1;

			if (sem_init(&mySemaphore, 0, initValue) == 0)
				printf("Semaphore initialized successfully.\n");
			else
				perror("Semaphore initialization failed");

			return 0;
		}
		```

2. **`sem_destroy`**
   - **Amaç:** Bir semaforu yok etmek için kullanılır.
   - **Prototip:** `int sem_destroy(sem_t *sem);`
   - **Parametreler:**
     - `sem`: Yok edilecek semaforun işaretçisi.
   - **Return Değeri:**
     - Başarı durumunda 0, hata durumunda -1 döner.

   - **Örnek:**
		```c
		#include <semaphore.h>
		#include <stdio.h>

		int main()
		{
			sem_t mySemaphore;

			// Semaforu başlat...

			if (sem_destroy(&mySemaphore) == 0)
				printf("Semaphore destroyed successfully.\n");
			else
				perror("Semaphore destruction failed");

			return 0;
		}
		```

3. **`sem_wait`**
   - **Amaç:** Semafor değerini azaltmak ve eğer 0 ise beklemek için kullanılır.
   - **Prototip:** `int sem_wait(sem_t *sem);`
   - **Parametreler:**
     - `sem`: Beklenen semaforun işaretçisi.
   - **Return Değeri:**
     - Başarı durumunda 0, hata durumunda -1 döner.

   - **Örnek:**
		```c
		#include <semaphore.h>
		#include <stdio.h>

		int main()
		{
			sem_t mySemaphore;

			// Semaforu başlat...

			if (sem_wait(&mySemaphore) == 0)
				printf("Semaphore value decremented successfully.\n");
			else
				perror("Semaphore wait failed");

			return 0;
		}
		```

4. **`sem_post`**
   - **Amaç:** Semafor değerini artırmak için kullanılır.
   - **Prototip:** `int sem_post(sem_t *sem);`
   - **Parametreler:**
     - `sem`: Artırılacak semaforun işaretçisi.
   - **Return Değeri:**
     - Başarı durumunda 0, hata durumunda -1 döner.

   - **Örnek:**
		```c
		#include <semaphore.h>
		#include <stdio.h>

		int main()
		{
			sem_t mySemaphore;

			// Semaforu başlat...

			if (sem_post(&mySemaphore) == 0)
				printf("Semaphore value incremented successfully.\n");
			else
				perror("Semaphore post failed");

			return 0;
		}
		```

5. **`sem_getvalue`**
   - **Amaç:** Semaforun mevcut değerini almak için kullanılır.
   - **Prototip:** `int sem_getvalue(sem_t *sem, int *sval);`
   - **Parametreler:**
     - `sem`: Değeri alınacak semaforun işaretçisi.
     - `sval`: Semaforun mevcut değerinin saklanacağı yer.
   - **Return Değeri:**
     - Başarı durumunda 0, hata durumunda -1 döner.

   - **Örnek:**
		```c
		#include <semaphore.h>
		#include <stdio.h>

		int main()
		{
			sem_t mySemaphore;
			int value;

			// Semaforu başlat...

			if (sem_getvalue(&mySemaphore, &value) == 0)
				printf("Semaphore value: %d\n", value);
			else
				perror("Semaphore value retrieval failed");

			return 0;
		}
		```
<br></br>

## 🔹 Semaphore ve Mutex Arasındaki Farklar

| Özellik               | Mutex (Muteks)                       | Semaphore (Semafor)                      |
|------------------------|-------------------------------------|-----------------------------------------|
| İşlev                  | Kritik bölgeye tek erişimi kontrol etmek için kullanılır. | Belirli bir kaynağa aynı anda birden fazla erişimi kontrol etmek veya kaynağın kullanılabilirliğini göstermek için kullanılır. |
| Değer                  | Tipik olarak, kilit açık (1) veya kilitli (0) olabilir. | Bir sayı değeri taşır ve bu değer belirli bir kaynağın aynı anda kaç thread tarafından kullanılabileceğini belirtir. |
| Kullanım               | Bir kaynağa tek bir thread'in erişimini kontrol etmek için kullanılır. | Genellikle belirli bir kaynağa aynı anda birden fazla thread'in erişimini kontrol etmek veya belirli bir kaynağın kullanılabilirliğini göstermek için kullanılır. |
| İşbirliği              | Daha basit bir yapıdır ve tipik olarak birinci gel, birinci al prensibini takip eder. | Daha karmaşık işbirliği senaryolarına izin verir ve bir kaynağın belli bir sayıda thread tarafından aynı anda kullanılmasına izin verir. |
| İsimlendirme           | Genellikle adlandırılmış bir kilit (named mutex) kullanılarak thread'ler arasında paylaşılır. | Genellikle adlandırılmış bir semafor (named semaphore) kullanılarak thread'ler arasında paylaşılır. |
| Fork Edilen Süreçlerle Kullanım | Genellikle tek bir süreç içindeki thread'ler arasında kullanılır, ancak fork edilen süreçler arasında da kullanılabilir. | Fork edilen süreçler arasında ve genellikle tek bir süreç içindeki thread'ler arasında kullanılabilir. |
<br></br>

## 🔹 Fonksiyon Açıklamaları
### 🔸 `memset` fonksiyonu
- **Amaç:** Belirtilen bellek bloğunu belirli bir değerle doldurur.
- **Prototip:** `void *memset(void *s, int c, size_t n);`
- **Parametreler:**
  - `s`: Bellek bloğunun başlangıç adresi.
  - `c`: Bellek bloğunu doldurmak için kullanılacak değer (int türünde olmalıdır, `unsigned char` olarak kabul edilir).
  - `n`: Doldurulacak bellek bloğunun byte cinsinden boyutu.
- **Return Değeri:**
  - `s`: Bellek bloğunun başlangıç adresi.

- **Örnek:**
  ```c
  #include <string.h>
  #include <stdio.h>

  int main()
  {
      char str[20];

      memset(str, 'A', sizeof(str)); // Bellek bloğunu 'A' karakteriyle doldur

      // str şu an "AAAAAAAAAAAAAAAAAAAA" içerir

      return 0;
  }
  ```

### 🔸 `printf` fonksiyonu
- **Amaç:** Ekrana belirtilen formatla yazdırma işlemi gerçekleştirir.
- **Prototip:** `int printf(const char *format, ...);`
- **Parametreler:**
  - `format`: Yazdırma formatı.
  - `...`: Yazdırma formatındaki değişken sayısına göre değişen argümanlar.
- **Return Değeri:**
  - Yazdırılan karakter sayısı.

- **Örnek:**
  ```c
  #include <stdio.h>

  int main()
  {
      int number = 42;
      char str[] = "Hello";

      printf("Number: %d, String: %s\n", number, str); // Ekrana "Number: 42, String: Hello" yazdır
      return 0;
  }
  ```

### 🔸 `malloc` fonksiyonu
- **Amaç:** Dinamik bellek tahsisi yapar, belirtilen boyutta bir bellek bloğu oluşturur.
- **Prototip:** `void *malloc(size_t size);`
- **Parametreler:**
  - `size`: Oluşturulacak bellek bloğunun boyutu (byte cinsinden).
- **Return Değeri:**
  - Başarı durumunda oluşturulan bellek bloğunun başlangıç adresi, başarısızlık durumunda `NULL`.

- **Örnek:**
  ```c
  #include <stdlib.h>

  int main()
  {
      int *arr;

      arr = (int *)malloc(10 * sizeof(int)); // 10 integer boyutunda bellek bloğu oluştur

      // Oluşturulan bellek bloğunu kullan

      free(arr); // Bellek bloğunu serbest bırak
      return 0;
  }
  ```

### 🔸 `free` fonksiyonu
- **Amaç:** Dinamik olarak tahsis edilmiş belleği serbest bırakır.
- **Prototip:** `void free(void *ptr);`
- **Parametreler:**
  - `ptr`: Serbest bırakılacak bellek bloğunun başlangıç adresi.
- **Return Değeri:**
  - Herhangi bir return değeri yok.

- **Örnek:**
  ```c
  #include <stdlib.h>

  int main()
  {
      int *arr;

      arr = (int *)malloc(10 * sizeof(int)); // Bellek bloğu tahsisi yap

      // Oluşturulan bellek bloğunu kullan

      free(arr); // Bellek bloğunu serbest bırak
      return 0;
  }
  ```

### 🔸 `write` fonksiyonu
- **Amaç:** Belirtilen dosya tanımlayıcısına belirtilen veriyi yazdırır.
- **Prototip:** `ssize_t write(int fd, const void *buf, size_t count);`
- **Parametreler:**
  - `fd`: Dosya tanımlayıcısı (örneğin, `STDOUT_FILENO` standart çıkışı temsil eder).
  - `buf`: Yazdırılacak verinin başlangıç adresi.
  - `count`: Yazdırılacak verinin byte cinsinden boyutu.
- **Return Değeri:**
  - Başarı durumunda yazılan byte sayısı, hata durumunda `-1`.

- **Örnek:**
  ```c
  #include <unistd.h>

  int main()
  {
      char str[] = "Hello, World!";

      write(STDOUT_FILENO, str, sizeof(str) - 1); // STDOUT_FILENO (standart çıkış) üzerine "Hello, World!" yazdır

      return 0;
  }
  ```

### 🔸 `usleep` fonksiyonu
- **Amaç:** Belirtilen mikro saniye süresince programın beklemesini sağlar.
- **Prototip:** `int usleep(useconds_t usec);`
- **Parametreler:**
  - `usec`: Bekleme süresi mikro saniye cinsinden.
- **Return Değeri:**
  - Başarı durumunda `0`, hata durumunda `-1`.

- **Örnek:**
  ```c
  #include <unistd.h>

  int main()
  {
      usleep(1000000); // 1 saniye (1000000 mikro saniye) beklet
      return 0;
  }
  ```

### 🔸 `gettimeofday` fonksiyonu
- **Amaç:** Sistem saatini ve zaman bilgilerini alır.
- **Prototip:** `int gettimeofday(struct timeval *tv, struct timezone *tz);`
- **Parametreler:**
  - `tv`: Zaman bilgilerinin saklanacağı timeval yapısı.
  - `tz`: Kullanılmayacak (genellikle NULL olarak belirtilir).
- **Return Değeri:**
  - Başarı durumunda `0`, hata durumunda `-1`.

- **Örnek:**
  ```c
  #include <sys/time.h>
  #include <stdio.h>

  int main()
  {
      struct timeval tv;

      int result = gettimeofday(&tv, NULL); // Sistem saatini al

      if (result == 0)
	  {
          printf("Seconds: %ld\n", tv.tv_sec);
          printf("Microseconds: %ld\n", tv.tv_usec);
      }
	  else
          fprintf(stderr, "Error getting time: %d\n", result);

      return 0;
  }
  ```

### 🔸 `pthread_create` fonksiyonu
   - **Amaç:** Yeni bir thread oluşturur ve belirtilen fonksiyonu çalıştırır.
   - **Prototip:** `int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);`
   - **Parametreler:**
     - `thread`: Oluşturulan thread'in tanımlayıcısı.
     - `attr`: Thread özelliklerini belirten bir yapı. Genellikle `NULL` kullanılır.
     - `start_routine`: Thread'in çalıştıracağı fonksiyonun işlev işaretcisi.
     - `arg`: `start_routine` fonksiyonuna geçirilecek argüman.
   - **Return Değeri:**
     - Başarı durumunda `0`, hata durumunda hata kodu.

   - **Örnek:**
     ```c
     #include <pthread.h>
     #include <stdio.h>

     void *threadFunction(void *arg)
	 {
         printf("Hello from the thread!\n");
         return NULL;
     }

     int main()
	 {
         pthread_t myThread;
         int result = pthread_create(&myThread, NULL, threadFunction, NULL);

         if (result != 0)
         {
             fprintf(stderr, "Thread creation failed: %d\n", result);
             return 1;
         }

         return 0;
     }
     ```

### 🔸 `pthread_join` fonksiyonu
   - **Amaç:** Belirtilen thread'in tamamlanmasını bekler.
   - **Prototip:** `int pthread_join(pthread_t thread, void **retval);`
   - **Parametreler:**
     - `thread`: Beklenecek thread'in tanımlayıcısı.
     - `retval`: Thread'in dönüş değerini alacak bir işaretçi. (Opsiyonel, `NULL` olabilir)
   - **Return Değeri:**
     - Başarı durumunda `0`, hata durumunda hata kodu.

   - **Örnek:**
     ```c
     #include <pthread.h>
     #include <stdio.h>

     void *threadFunction(void *arg)
	 {
         printf("Hello from the thread!\n");
         return NULL;
     }

     int main()
	 {
         pthread_t myThread;
         int result = pthread_create(&myThread, NULL, threadFunction, NULL);

         if (result != 0)
		 {
             fprintf(stderr, "Thread creation failed: %d\n", result);
             return 1;
         }

         // Main thread devam ederken yeni thread çalışıyor

         pthread_join(myThread, NULL); // Yeni thread'in tamamlanmasını bekle

         return 0;
     }
     ```

### 🔸 `pthread_detach` fonksiyonu
   - **Amaç:** Belirtilen thread'in başka bir thread tarafından beklenmeden kaynaklarını serbest bırakmasını sağlar. Bu işlev, bir thread'in sonlanması durumunda otomatik olarak kaynaklarını temizlemek için kullanılır.
   - **Prototip:** `int pthread_detach(pthread_t thread);`
   - **Parametreler:**
     - `thread`: Kaynakları serbest bırakılacak olan thread'in tanımlayıcısı.
   - **Return Değeri:**
     - Başarı durumunda `0`, hata durumunda hata kodu.

   - **Örnek:**
     ```c
     #include <pthread.h>
     #include <stdio.h>

     void *threadFunction(void *arg)
	 {
         printf("Thread is running...\n");
         return NULL;
     }

     int main()
	 {
         pthread_t myThread;
         int result = pthread_create(&myThread, NULL, threadFunction, NULL);

         if (result != 0)
		 {
             fprintf(stderr, "Thread creation failed: %d\n", result);
             return 1;
         }

         result = pthread_detach(myThread); // pthread_detach ile thread'i detached yap
         if (result != 0)
		 {
             fprintf(stderr, "Thread detachment failed: %d\n", result);
             return 1;
         }

         // Main thread devam ederken detached thread çalışıyor
         // pthread_join(myThread, NULL); // detached thread'i beklemeye gerek yok

         return 0;
     }
     ```

### 🔸 `pthread_mutex_init` fonksiyonu
   - **Amaç:** Mutex (Karşılıklı dışlama) tanımlar.
   - **Prototip:** `int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);`
   - **Parametreler:**
     - `mutex`: İlklenen mutex'in işaretçisi.
     - `attr`: Mutex özelliklerini belirten bir yapı. Genellikle `NULL` kullanılır.
   - **Return Değeri:**
     - Başarı durumunda `0`, hata durumunda hata kodu.

   - **Örnek:**
     ```c
     #include <pthread.h>
     #include <stdio.h>

     pthread_mutex_t myMutex;

     void *threadFunction(void *arg)
	 {
         pthread_mutex_lock(&myMutex); // Mutex'i kilitle
         printf("Thread locked the mutex.\n");
         pthread_mutex_unlock(&myMutex); // Mutex'i aç
         return NULL;
     }

     int main()
	 {
         pthread_t myThread;
         int result = pthread_create(&myThread, NULL, threadFunction, NULL);

         if (result != 0)
		 {
             fprintf(stderr, "Thread creation failed: %d\n", result);
             return 1;
         }

         pthread_mutex_init(&myMutex, NULL); // Mutex'i başlat

         // Main thread devam ederken yeni thread çalışıyor

         pthread_join(myThread, NULL); // Yeni thread'in tamamlanmasını bekle

         pthread_mutex_destroy(&myMutex); // Mutex'i yok et

         return 0;
     }
     ```

### 🔸 `pthread_mutex_destroy` fonksiyonu
   - **Amaç:** Mutex'in bellekten serbest bırakılmasını sağlar. Mutex kullanımı sona erdiğinde, bu fonksiyonun çağrılması önerilir.
   - **Prototip:** `int pthread_mutex_destroy(pthread_mutex_t *mutex);`
   - **Parametreler:**
     - `mutex`: Yok edilecek mutex'in işaretçisi.
   - **Return Değeri:**
     - Başarı durumunda `0`, hata durumunda hata kodu.

   - **Örnek:**
     ```c
     #include <pthread.h>
     #include <stdio.h>

     pthread_mutex_t myMutex;

     int main()
	 {
         int result = pthread_mutex_init(&myMutex, NULL); // Mutex'i başlat

         if (result != 0)
		 {
             fprintf(stderr, "Mutex initialization failed: %d\n", result);
             return 1;
         }

         // Mutex'i kullan

         result = pthread_mutex_destroy(&myMutex); // Mutex'i yok et

         if (result != 0)
		 {
             fprintf(stderr, "Mutex destruction failed: %d\n", result);
             return 1;
         }

         return 0;
     }
     ```

### 🔸 `pthread_mutex_lock` ve `pthread_mutex_unlock` fonksiyonları
   - **Amaç:** Mutex'i kilitleme (lock) ve kilidi açma (unlock) işlemlerini gerçekleştirir.
   - **Prototip (lock):** `int pthread_mutex_lock(pthread_mutex_t *mutex);`
   - **Prototip (unlock):** `int pthread_mutex_unlock(pthread_mutex_t *mutex);`
   - **Parametreler:**
     - `mutex`: İlgili mutex'in işaretçisi.
   - **Return Değeri:**
     - Başarı durumunda `0`, hata durumunda hata kodu.

   - **Örnek:**
     ```c
     #include <pthread.h>
     #include <stdio.h>

     pthread_mutex_t myMutex;

     void *threadFunction(void *arg)
	 {
         pthread_mutex_lock(&myMutex); // Mutex'i kilitle
         printf("Thread locked the mutex.\n");
         pthread_mutex_unlock(&myMutex); // Mutex'i aç
         return NULL;
     }

     int main()
	 {
         pthread_t myThread;
         int result = pthread_create(&myThread, NULL, threadFunction, NULL);

         if (result != 0)
		 {
             fprintf(stderr, "Thread creation failed: %d\n", result);
             return 1;
         }

         pthread_mutex_init(&myMutex, NULL); // Mutex'i başlat

         // Main thread devam ederken yeni thread çalışıyor

         pthread_join(myThread, NULL); // Yeni thread'in tamamlanmasını bekle

         pthread_mutex_destroy(&myMutex); // Mutex'i yok et

         return 0;
     }
     ```
