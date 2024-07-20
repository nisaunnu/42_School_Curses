/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:25:37 by nunnu             #+#    #+#             */
/*   Updated: 2024/05/15 18:34:32 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../../inc/minishell.h"
#include "../../inc/libft/inc/libft.h"

void	handle_error(const char *msg, int use_perror, int error_code)
{
	if (use_perror)
		perror(msg);
	else
		ft_printf("%s\n", msg);
	exit(error_code);
}

void	free_shell(t_minishell *shell)
{
	if (shell->input_line)
		free(shell->input_line);
	if (shell->envp)
		free_env(&(shell->envp));
	free_ast(shell->ast);
}

static void	copy_envp(t_minishell *shell, char **envp)
{
	int	i;
	int	envp_len;

	i = 0;
	envp_len = 0;
	while (envp[envp_len])
		envp_len++;
	shell->envp = (char **)malloc(sizeof(char *) * (envp_len + 1));
	if (!shell->envp)
		return ;
	while (i < envp_len)
	{
		shell->envp[i] = my_strdup(envp[i]);
		i++;
	}
	shell->envp[envp_len] = NULL;
	shell->og_envp = shell->envp;
}

void	init_minishell(t_minishell *shell, char **envp)
{
	if (!shell)
		return ;
	ft_memset(shell, 0, sizeof(t_minishell));
	copy_envp(shell, envp);
	shell->fd_read = 0;
	shell->fd_write = 1;
	shell->input_redirect = 0;
	shell->output_redirect = 0;
	shell->input_line = NULL;
	shell->ast = NULL;
	shell->pipe_list = NULL;
	shell->last_cmd = 0;
	shell->hd_pipes = 0;
	shell->hd_pipes_read = 0;
	shell->last_exit_status = 0;
	shell->shell_pid = 0;
	shell->flag_oldpwd = 0;
}

void	reset_minishell(t_minishell *shell)
{
	if (shell->fd_read != 0)
		close(shell->fd_read);
	shell->fd_read = 0;
	shell->fd_write = 1;
	shell->input_redirect = 0;
	shell->output_redirect = 0;
	shell->ast = NULL;
}
