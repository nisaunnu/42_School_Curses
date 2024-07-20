/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu     <nunnu@student.42kocaeli.c>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:25:37 by nunnu             #+#    #+#             */
/*   Updated: 2024/05/15 18:13:32 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../../inc/minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

int	minishell(char **envp)
{
	t_minishell	shell;
	char		*input;

	init_minishell(&shell, envp);
	while (1)
	{
		setup_signal_handlers();
		setup_signal(SIGQUIT, SIG_IGN, 0);
		input = readline("\033[34mminishell \033[32m$ \033[0m");
		if (g_sigint_recived)
			g_sigint_recived = SIGINT_NORMAL;
		if (!input)
		{
			free_shell(&shell);
			break ;
		}
		if (*input)
		{
			add_history(input);
			handle_input(&shell, input);
		}
		free(input);
	}
	return (0);
}
