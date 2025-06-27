#include <cstring>
#include <signal.h>
#include "Server.hpp"

void	ctrlc(int signal)
{
	(void)signal;

	std::string	art =
	"               ...\n"
	"             ;::::;\n"
	"           ;::::; :;\n"
	"         ;:::::'   :;\n"
	"        ;:::::;     ;.\n"
	"       ,:::::'       ;           OOO\\\n"
	"       ::::::;       ;          OOOOO\\\n"
	"       ;:::::;       ;         OOOOOOOO\n"
	"      ,;::::::;     ;'         / OOOOOOO\n"
	"    ;:::::::::`. ,,,;.        /  / DOOOOOO\n"
	"  .';:::::::::::::::::;,     /  /     DOOOO\n"
	" ,::::::;::::::;;;;::::;,   /  /        DOOO\n"
	";`::::::`'::::::;;;::::: ,#/  /          DOOO\n"
	":`:::::::`;::::::;;::: ;::#  /            DOOO\n"
	"::`:::::::`;:::::::: ;::::# /              DOO\n"
	"`:`:::::::`;:::::: ;::::::#/               DOO\n"
	" :::`:::::::`;; ;:::::::::##                OO\n"
	" ::::`:::::::`;::::::::;:::#                OO\n"
	" `:::::`::::::::::::;'`:;::#                O\n"
	"  `:::::`::::::::;' /  / `:#\n"
	"   ::::::`:::::;'  /  /   `#\"\n";

	std::cout << std::endl << art << std::endl;
}

void	ctrlz(int signal)
{
	(void)signal;
	std::cout << std::endl << "Ctrl+Z (SIGTSTP) signal caught, but the process was not suspended!" << std::endl;
}

void	signals(void)
{
	struct sigaction	sa;

	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = ctrlc;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGINT, &sa, NULL) < 0)
		exit(56);

	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = ctrlz;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGTSTP, &sa, NULL) < 0)
		exit(57);
}
