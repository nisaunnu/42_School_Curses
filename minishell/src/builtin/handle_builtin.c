/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu     <nunnu@student.42kocaeli.c>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:25:37 by nunnu             #+#    #+#             */
/*   Updated: 2024/05/15 18:13:32 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include "../../inc/libft/inc/libft.h"

int	special_builtin(t_minishell *shell, char **cmd_args)
{
	if (ft_strncmp(cmd_args[0], "cd", 3) == 0)
	{
		cd_command(shell, cmd_args);
		return (1);
	}
	else if (ft_strncmp(cmd_args[0], "export", 7) == 0)
	{
		export_command(shell, &cmd_args[1]);
		return (1);
	}
	else if (ft_strncmp(cmd_args[0], "unset", 6) == 0)
	{
		unset_command(shell, &cmd_args[1]);
		return (1);
	}
	else if (ft_strncmp(cmd_args[0], "exit", 5) == 0)
		exit_command(shell, cmd_args);
	return (0);
}

int	handle_builtin(t_minishell *shell, char **cmd_args)
{
	if (ft_strncmp(cmd_args[0], "echo", 5) == 0)
	{
		echo_command(cmd_args);
		return (1);
	}
	else if (ft_strncmp(cmd_args[0], "pwd", 4) == 0)
	{
		pwd_command();
		return (1);
	}
	else if (ft_strncmp(cmd_args[0], "env", 4) == 0)
	{
		env_command(shell, cmd_args);
		return (1);
	}
	return (0);
}
