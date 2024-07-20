/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu     <nunnu@student.42kocaeli.c>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:29:56 by nunnu             #+#    #+#             */
/*   Updated: 2024/05/15 18:13:32 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "../../inc/minishell.h"
#include "../../inc/libft/inc/libft.h"

void	execute_and_sequence(t_minishell *shell, t_ast_node *node)
{
	execute_ast_command(shell, node->left);
	if (!shell->last_exit_status)
		execute_ast_command(shell, node->right);
}

void	add_pipe(t_ast_node **root, t_token *token)
{
	t_ast_node	*pipe;

	pipe = create_ast_node(token->type, token->value);
	pipe->right = (*root);
	(*root) = pipe;
}

void	execute_heredoc(t_minishell*shell, t_ast_node *node)
{
	if (!node->right)
	{
		printf("minishell: syntax error near unexpected token 'newline'\n");
		shell->last_exit_status = 2;
		return ;
	}
	process_heredoc(shell, node->right->value);
	if (shell->hd_pipes != 1)
		execute_ast_command(shell, node->left);
}

int	handle_signal(t_minishell *shell, char *value)
{
	if (g_sigint_recived == SIGINT_HD_RECIVED)
	{
		shell->last_exit_status = 130;
		return (-1);
	}
	g_sigint_recived = SIGINT_COMMAND;
	if (!value || !shell)
		return (-1);
	return (0);
}

void	single_cmd_process(t_minishell *shell, char **args, char *path)
{
	pid_t	pid;
	int		status;

	setup_signal_handlers();
	pid = fork();
	if (pid == -1)
		perror("Fork Error");
	else if (pid == 0)
	{
		if (args[1] && ft_strncmp(args[1], "$$", 3) == 0)
			exit (0);
		redirect_stdin(shell);
		if (execve(path, args, shell->envp) == -1)
			exit_status(shell, path, EXIT_FAILURE);
	}
	if (!shell->shell_pid)
		shell->shell_pid = ((int)pid - 1);
	if (args[1] && ft_strncmp(args[1], "$$", 3) == 0)
		printf("%d\n", shell->shell_pid);
	if (shell->fd_read != STDIN_FILENO)
		close(shell->fd_read);
	if (shell->hd_pipes_read)
		shell->fd_read = shell->hd_pipes_read;
	if (waitpid(pid, &status, 0) != -1 && WIFEXITED(status))
		shell->last_exit_status = WEXITSTATUS(status);
}
