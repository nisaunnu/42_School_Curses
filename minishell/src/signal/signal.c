/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:25:37 by nunnu             #+#    #+#             */
/*   Updated: 2024/07/20 17:32:09 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/ioctl.h>
#include <readline/readline.h>
#include "../../inc/minishell.h"
#include "../../inc/libft/inc/libft.h"

volatile sig_atomic_t	g_sigint_recived = SIGINT_NORMAL;

void	setup_signal(int signal, void (*handler)(int), int flags)
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = flags;
	sigaction(signal, &sa, NULL);
}

static void	handle_sigchild(int signal)
{
	int	save_err;

	(void)signal;
	save_err = waitpid(-1, NULL, WNOHANG);
	while (save_err > 0)
		;
}

void	handle_sigint(int sig)
{
	(void)sig;
	if (g_sigint_recived == SIGINT_HD)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		ioctl(0, TIOCSTI, "\n");
	}
	else
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		if (g_sigint_recived != SIGINT_COMMAND)
			rl_redisplay();
	}
	g_sigint_recived = SIGINT_RECIVED;
}

void	handle_sigquit(int signal)
{
	struct sigaction	sa;

	(void)signal;
	ft_memset(&sa, 0, sizeof(sa));
	if (g_sigint_recived == SIGINT_COMMAND)
		g_sigint_recived = SIGQUIT_COMMAND;
	else if (g_sigint_recived == SIGINT_HD)
		setup_signal(SIGQUIT, SIG_IGN, 0);
}

void	setup_signal_handlers(void)
{
	setup_signal(SIGINT, handle_sigint, SA_RESTART);
	setup_signal(SIGQUIT, handle_sigquit, SA_RESTART);
	if (g_sigint_recived == SIGINT_SUBSHELL)
		setup_signal(SIGCHLD, handle_sigchild, SA_NOCLDSTOP | SA_RESTART);
}
