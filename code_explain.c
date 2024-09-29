#include "microshell.h"

// Bir hata mesajını standart hata akışına (stderr) yazdıran fonksiyon
int err(const char *s)
{
	while(*s)
		write(2, s++, 1);
	return (1);
}

// Kullanıcının dizin değiştirme (cd) komutunu işleyen fonksiyon
int	cd(char **argv, int i)
{
	if (i != 2) // Eğer cd komutu yanlış sayıda argümanla çağrıldıysa,
		return (err("error: cd: bad arguments\n")); // hata mesajı yazdır ve 1 değerini döndür
	else if (chdir(argv[1]) == -1) // Eğer chdir fonksiyonu, belirtilen dizine gidemiyorsa
		return (err("error: cd: cannot change directory to "), err(argv[1]), err("\n")); // hata mesajı yazdır ve 1 değerini döndür
	return (0);
}

// Komutları yürütmek için kullanılan fonksiyon
int	exec(char **argv, char **envp, int i)
{
	int		pipefd[2]; // boru (pipe) için dosya tanımlayıcılarını tutar
	int		status;    // işlem durumunu tutar
	int	has_pipe = argv[i] && !strcmp(argv[i], "|"); // komutta bir boru (pipe) varsa true değeri alır

	// Eğer komutta bir boru varsa, bir boru oluşturulur.
	// Boru oluşturulamazsa, program sonlandırılır ve "error: fatal" şeklinde bir hata mesajı yazdırılır.
	if (has_pipe && pipe(pipefd) == -1)
		return (err("error: fatal\n"));

	// Yeni bir işlem oluşturmak için fork fonksiyonu çağrılır.
	// Çocuk işlem, 0 döndürür, ebeveyn işlem ise çocuğun PID'sini döndürür.
	int	pid = fork();

	if (!pid) // Eğer çocuk işlemdeysek, içerideki kod parçacığı yürütülür.
	{
		argv[i] = 0;

		// Eğer bir boru varsa, boruyla ilişkilendirilen dosya tanımlayıcıları dup2 fonksiyonu aracılığıyla standart giriş ve çıkışa yönlendirilir.
		// Eğer dosya tanımlayıcılarının yönlendirilmesi başarısız olursa, program sonlandırılır ve "error: fatal" şeklinde bir hata mesajı yazdırılır.
		if (has_pipe && (dup2(pipefd[1], 1) == -1 || close(pipefd[0]) == -1 || close(pipefd[1]) == -1))
			return (err("error: fatal\n"));

		execve(*argv, argv, envp); // Çocuk işlem, execve çağrısı ile komutu yürütür.
		return (err("error: cannot execute "), err(*argv), err("\n")); // Eğer execve çağrısı başarısız olursa, "error: cannot execute [komut]" şeklinde bir hata mesajı yazdırılır.
	}

	waitpid(pid, &status, 0); // Ebeveyn işlem, çocuk işleminin tamamlanmasını bekler ve işlem durumunu alır.

	// Eğer bir boru varsa ve giriş yönlendirmesi yapılıyorsa, giriş yönlendirmesi yapılır ve boruyla ilişkilendirilen dosya tanımlayıcıları kapatılır.
	// Eğer dosya tanımlayıcılarının kapatılması başarısız olursa, program sonlandırılır ve "error: fatal" şeklinde bir hata mesajı yazdırılır.
	if (has_pipe && (dup2(pipefd[0], 0) == -1 || close(pipefd[0]) == -1 || close(pipefd[1]) == -1))
		return (err("error: fatal\n"));

	return (WIFEXITED(status) && WEXITSTATUS(status)); // İşlem başarıyla tamamlandıysa ve çocuk işlem bir çıkış durumu döndürdüyse, çıkış durumu döndürülür.
}

int main(int argc, char *argv[], char *envp[])
{
	int i = 0; // döngüde kullanılacak indis değeri ve komutları parçalamak için kullanılacak bir kontrol değişkeni
	int status = 0; // programın son durumunu (başarılı mı yoksa hata mı olduğunu) belirleyen değişken

	if (argc > 1) // Eğer komut satırında en az bir argüman varsa, işleme devam et
	{
		// Komut satırındaki argümanlar üzerinde bir döngü başlatılır
		// Döngü, argv dizisini tarar ve ardışık olarak argümanları ele alır
		while (argv[i] && argv[++i])
		{
			argv += i; // Argüman dizisi, i indisinden itibaren güncellenir. Bu, önceki işlenmiş argümanların dizi dışına çıkartılması anlamına gelir.
			i = 0; // Kontrol indis değeri sıfırlanır.
			while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";")) // Argümanlar taranır ve "|" veya ";" karakterleri bulunana kadar devam edilir
				i++;
			if (!strcmp(*argv, "cd")) // Eğer komut "cd" ise, cd fonksiyonu çağrılır.
				status = cd(argv, i);
			else if (i) // Eğer i değeri sıfırdan farklıysa, yani "|" veya ";" karakteri bulunmuşsa
				status = exec(argv, envp, i); // exec fonksiyonu çağrılır ve status değişkenine işlemin son durumu atanır
		}
	}
	return (status); // Programın son durumu döndürülür
}

