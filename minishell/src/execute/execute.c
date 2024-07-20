/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:04:28 by nunnu             #+#    #+#             */
/*   Updated: 2024/05/20 15:00:39 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../../inc/minishell.h"
#include "../../inc/libft/inc/libft.h"
#include <fcntl.h>

void	execute_single_command(t_minishell *shell, char *value)
{
	char	**args;
	char	*path;

	if (handle_signal(shell, value))
		return ;
	args = handle_wildcards(value);
	if (!args || !*args)
		return ;
	if (ft_strncmp(args[0], "./", 2) == 0)
		select_exec(shell, args);
	else if (!special_builtin(shell, args) && !handle_builtin(shell, args))
	{
		path = get_path(args[0], my_getenv(shell->envp, "PATH"));
		if (!path)
			exit_status(shell, args[0], 127);
		else
		{
			single_cmd_process(shell, args, path);
			free(path);
		}
	}
	if (g_sigint_recived >= SIGINT_RECIVED)
		shell->last_exit_status = SIGNAL_CODE + g_sigint_recived;
	g_sigint_recived = SIGINT_NORMAL;
	ft_free_arrays(args);
}

static int	execute_output_redirect(t_minishell *shell, t_ast_node *node)
{
	pid_t	pid;
	int		fd_out;

	if (!node->right)
		return (printf(MSG), shell->last_exit_status = 258, -1);
	node->right->value = strip_quotes(node->right->value);
	pid = fork();
	if (!pid)
	{
		if (ft_strncmp(node->value, ">>", 2) == 0)
			fd_out = open(node->right->value, O_WRONLY | O_CREAT
					| O_APPEND, 0777);
		else
			fd_out = open(node->right->value, O_WRONLY | O_CREAT
					| O_TRUNC, 0777);
		dup2(fd_out, STDOUT_FILENO);
		if (node->left && node->left->type == AST_REDIRECT_OUT)
			close(fd_out);
		if (node->left)
			execute_ast_command(shell, node->left);
		close(fd_out);
		exit(0);
	}
	return (waitpid(pid, 0, 0), 0);
}

static int	execute_input_redirect(t_minishell *shell, t_ast_node *node)
{
	pid_t	pid;
	int		fd_in;

	if (!node->right)
	{
		printf("minishell: syntax error near unexpected token `newline'\n");
		return (shell->last_exit_status = 258, -1);
	}
	node->right->value = strip_quotes(node->right->value);
	pid = fork();
	if (!pid)
	{
		fd_in = open(node->right->value, O_RDONLY, 0777);
		if (fd_in == -1)
			handle_error("Read Error", 1, EXIT_FAILURE);
		dup2(fd_in, STDIN_FILENO);
		if (node->left)
			execute_ast_command(shell, node->left);
		close(fd_in);
		exit(0);
	}
	waitpid(pid, 0, 0);
	return (0);
}

static void	execute_or_sequence(t_minishell *shell, t_ast_node *node)
{
	execute_ast_command(shell, node->left);
	if (shell->last_exit_status)
		execute_ast_command(shell, node->right);
}

void	execute_ast_command(t_minishell *shell, t_ast_node *node)
{
	int	status;

	status = 0;
	if (node == NULL || shell == NULL)
		return ;
	if (node->type == AST_OR)
		execute_or_sequence(shell, node);
	else if (node->type == AST_AND)
		execute_and_sequence(shell, node);
	else if (node->type == AST_SUBSHELL_EX)
		exec_subshell_ex(shell, node->value, 0);
	else if (node->type == AST_COMMAND)
		execute_single_command(shell, node->value);
	else if (node->type == AST_REDIRECT_OUT)
		status = execute_output_redirect(shell, node);
	else if (node->type == AST_REDIRECT_IN)
		status = execute_input_redirect(shell, node);
	else if (node->type == AST_HEREDOC)
		execute_heredoc(shell, node);
	else
		execute_pipe_cmd(shell, node);
	if (status == -1)
		return ;
}
