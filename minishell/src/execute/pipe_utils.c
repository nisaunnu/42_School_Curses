/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:25:37 by nunnu             #+#    #+#             */
/*   Updated: 2024/05/15 18:42:45 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include <stdlib.h>
#include <unistd.h>

void	install_fd(t_minishell *shell, t_ast_node *node, int *fd_in)
{
	if (node->next != NULL)
	{
		if (pipe(shell->pipes) == -1)
			handle_error("Error creating pipe", 1, EXIT_FAILURE);
		if (!shell->output_redirect)
			shell->fd_write = shell->pipes[1];
		if (shell->hd_pipes)
			shell->fd_read = shell->pipes[0];
		else
			shell->fd_read = *fd_in;
	}
	else
	{
		shell->fd_write = STDOUT_FILENO;
		shell->fd_read = *fd_in;
	}
}

void	close_fds(int *pipe_fds, int *fd_in)
{
	if (*pipe_fds != -1)
	{
		close(*pipe_fds);
		*pipe_fds = -1;
	}
	if (*fd_in != 0)
	{
		close(*fd_in);
		*fd_in = STDIN_FILENO;
	}
}

int	handle_dup(t_minishell *shell)
{
	if (shell->fd_read != STDIN_FILENO)
	{
		if (dup2(shell->fd_read, STDIN_FILENO) == -1)
			return (-1);
		close(shell->fd_read);
	}
	close(shell->pipes[0]);
	if (shell->fd_write != STDOUT_FILENO)
	{
		if (dup2(shell->fd_write, STDOUT_FILENO) == -1)
			return (-1);
		close(shell->fd_write);
	}
	return (1);
}

void	create_list(t_minishell *shell, t_ast_node *cmd_node)
{
	t_ast_node	*cmd_list;
	t_ast_node	*current_node;

	cmd_list = NULL;
	current_node = cmd_node;
	while (current_node && current_node->type == AST_PIPE)
	{
		if (current_node->left && current_node->left->type != AST_PIPE)
			add_ast_back(&cmd_list, current_node->left);
		if (current_node->right && current_node->right->type != AST_PIPE)
			add_ast_back(&cmd_list, current_node->right);
		current_node = current_node->right;
	}
	shell->pipe_list = cmd_list;
}

char	**handle_wildcards(char *value)
{
	char	**args;
	char	**files;

	args = split_cmd(value, " ");
	if (!args)
		return (NULL);
	files = expand_wildcards(args);
	if (files && *files)
		args = command(args, files);
	else if (files)
		ft_free_arrays(files);
	return (args);
}
