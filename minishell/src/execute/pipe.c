/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:25:37 by nunnu             #+#    #+#             */
/*   Updated: 2024/05/20 15:00:37 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include <unistd.h>
#include <stdlib.h>

static void	wait_for_commands(t_minishell *shell, pid_t last_pid)
{
	int		status;
	pid_t	pid;

	shell->last_exit_status = 0;
	waitpid(last_pid, &status, 0);
	if (WIFEXITED(status))
		shell->last_exit_status = WEXITSTATUS(status);
	pid = waitpid(-1, &status, 0);
	while (pid > 0)
	{
		if (pid == last_pid)
			break ;
		pid = waitpid(-1, &status, 0);
	}
}

static pid_t	execute_command(t_minishell	*shell, char *value)
{
	pid_t	pid;
	char	**args;
	char	*path;

	pid = fork();
	if (pid == -1)
		handle_error ("Fork Error", 1, EXIT_FAILURE);
	else if (pid == 0)
	{
		if (handle_dup(shell) == -1)
			handle_error ("Dup error", 1, EXIT_FAILURE);
		args = handle_wildcards(value);
		if (!args)
			return (ft_free_arrays(args), -1);
		if (handle_builtin(shell, args) || special_builtin(shell, args))
			exit(0);
		path = get_path(args[0], my_getenv(shell->envp, "PATH"));
		if (!path)
			handle_error(args[0], 1, 127);
		signal(SIGQUIT, SIG_DFL);
		execve(path, args, shell->envp);
		handle_error ("Execve Error", 1, EXIT_FAILURE);
	}
	close_redirections(shell);
	return (pid);
}

static pid_t	execute_multiple_cmd(t_minishell *shell, t_ast_node *cmd_node)
{
	g_sigint_recived = SIGINT_COMMAND;
	if (cmd_node->type == AST_REDIRECT_IN || cmd_node->type == AST_REDIRECT_OUT)
	{
		if (handle_redirect(shell, cmd_node) == -1)
			return (-1);
		if (cmd_node->left)
			return (execute_multiple_cmd(shell, cmd_node->left));
	}
	else if (cmd_node->type == AST_SUBSHELL_EX)
		exec_subshell_ex(shell, cmd_node->value, 1);
	else if (cmd_node->type == AST_HEREDOC)
	{
		if (!cmd_node->right || !cmd_node->left)
			return (-1);
		process_heredoc(shell, cmd_node->right->value);
		return (0);
	}
	else
		return (execute_command(shell, cmd_node->value));
	return (1);
}

static pid_t	process_command(t_minishell *shell, t_ast_node *current_cmd,
				int *fd_in)
{
	pid_t	pid;

	pid = 0;
	if (current_cmd->type == AST_HEREDOC)
		shell->hd_pipes = 1;
	install_fd(shell, current_cmd, fd_in);
	pid = execute_multiple_cmd(shell, current_cmd);
	close_fds(&shell->pipes[1], fd_in);
	if (shell->fd_write != STDOUT_FILENO)
		close (shell->fd_write);
	if (current_cmd->next != NULL)
	{
		if (shell->hd_pipes)
		{
			*fd_in = shell->hd_pipes_read;
			shell->hd_pipes = 0;
		}
		else
			*fd_in = shell->pipes[0];
	}
	return (pid);
}

void	execute_pipe_cmd(t_minishell *shell, t_ast_node *cmd_node)
{
	int			fd_in;
	pid_t		last_pid;
	t_ast_node	*current_cmd;

	fd_in = 0;
	last_pid = 0;
	create_list(shell, cmd_node);
	current_cmd = shell->pipe_list;
	while (current_cmd != NULL)
	{
		last_pid = process_command(shell, current_cmd, &fd_in);
		current_cmd = current_cmd->next;
	}
	if (fd_in != 0)
		close(fd_in);
	wait_for_commands(shell, last_pid);
}
