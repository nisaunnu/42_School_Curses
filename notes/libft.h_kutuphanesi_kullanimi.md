# `libft.h` kütüphanesini başka dosyalarda nasıl kullanırız ve çalıştırırız?

## Başka Dosyalarda Kullanımı
`libft.h` kütüphanesini .c uzantılı dosyasınıza eklemeniz gerekmektedir. Aşağıdaki kod satırı ile bunu gerçekleştirebilirsiniz.
```c
#include "libft.h"
```
<br>

## Argüman Girdisi Olmadan Kullanımı

Aşağıdaki komutu kendinize uyarlayarak kütüphanenizi dahil edebilirsiniz. `main.c` yerine kendi .c uzantılı dosyanızın ismini girin. `main` yerine .c uzantılı dosyanızın .c uzantısını kaldırarak sadece ismini yazın.

```
gcc -o main main.c -L. -lft
```

Komut satırı açıklaması:
* `gcc`, bir C programını derlemek için kullanılan komuttur.
* `-o main`, çıkış dosyasının adını belirtir.
* `main.c`, derlemek istediğiniz C kaynak dosyasının adıdır.
* `-L.` bayrağı, derleyiciye kitaplığı geçerli dizinde aramasını söyler.
* `-lft` bayrağı, derleyiciye kitaplığı programa bağlamasını söyler.

`-L.` ve `-lft` bayrakları, `libft.h` kitaplığını programa bağlamak için kullanılır. `libft.h` kitaplığı statik bir kitaplıktır, yani birbirine bağlanmış nesne dosyalarının bir koleksiyonudur.

Derleyici programı derlediğinde, `libft.h` kütüphanesini programa bağlar. Bu, programın kitaplıktaki işlevlere erişmesine izin verecektir.

Yukarıda yazılan komut satırına göre derlemenin çıktısı, `main`  adlı yürütülebilir bir dosya olacaktır. Daha sonra aşağıdaki komutu yazarak `main` programını çalıştırabilirsiniz:
```
./main
```
Komut satırında yazan `main` yerine kendi dosyanızın ismini giriniz.
<br></br>

## Argüman Girdisi ile Kullanımı

Programı derlerken bir veya birden fazla argüman girmek istiyorsanız, `-D` bayrağını kullanabilirsiniz. Örneğin, programı derlerken `arg1` ve `arg2` bağımsız değişkenlerini girmek istiyorsanız, aşağıdaki komutu kullanırsınız:

```
gcc -o main main.c -L. -lft -Darg1 -Darg2
```

Komut satırı açıklaması:
* `gcc`, bir C programını derlemek için kullanılan komuttur.
* `-o main`, çıkış dosyasının adını belirtir.
* `main.c`, derlemek istediğiniz C kaynak dosyasının adıdır.
* `-L.` bayrağı, derleyiciye kitaplığı geçerli dizinde aramasını söyler.
* `-lft` bayrağı, derleyiciye kitaplığı programa bağlamasını söyler.
* `-D` bayrağı, bir önişlemci makrosu tanımlamak için kullanılır. Önişlemci makrosu, program derlendiğinde argümanla değiştirilecektir.

Yukarıda yazılan komut satırına göre derlemenin çıktısı, `main`  adlı yürütülebilir bir dosya olacaktır. Daha sonra aşağıdaki komutu yazarak `main` programını çalıştırabilirsiniz:
```
./main
```
Komut satırında yazan `main` yerine kendi dosyanızın ismini giriniz.
<br></br>

## Makefile

Uzun bir şekilde komut satırı yazmak istemiyorsanız başka dosyalarınızı derlerken `makefile` dosyası kullanabilirsiniz. Kendi derleyici komutlarınızı aynı `makefile` içerisine yazabilirsiniz.
<br></br>

### Argüman Olmadan Makefile
Tek bir kelimede derleme işlemini gerçekleştirmek için aşağıda yer alan makefile komutlarını kullanabilirsiniz.

```makefile
NAME = $(shell basename $(CURDIR))
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

all: $(NAME)

$(NAME): $(NAME).o
	gcc -o $(NAME) $(NAME).o -L. -lft

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(NAME) $(NAME).o
```

Derleme yapmak için aşağıdaki komutu girmeniz yeterli olacaktır.
```
make
```
<br>

### Argüman ile Makefile

Argüman olmadan makefile başlığı altında yer alan `Makefile` dosyası komutlarında tek bir değişiklik vardır.

```makefile
$(NAME): $(NAME).o
	gcc -o $(NAME) $(NAME).o -L. -lft $(ARGS)
```
`$(ARGS)` komutu eklenmiştir. Dışarıdan alınan argümanın derleyici sırasındaki yerini belirtmek gerekmektedir.

Derleme yapmak için aşağıdaki komutu girmeniz yeterli olacaktır.
```
make -a arg1 arg2
```
`make` komutu ile birlikte `-a` bayrağını kullanarak argüman girişi sağlanabilmektedir. `arg1` ve `arg2` yerine istediğiniz argümanı girebilirsiniz.

