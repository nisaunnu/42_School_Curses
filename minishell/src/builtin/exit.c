/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
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
#include "../../inc/libft/inc/libft.h"

static int	continue_function(t_minishell *shell, char **cmd_args)
{
	if (!cmd_args[2])
	{
		printf("minishell: exit: %s: numeric argument required\n",
			cmd_args[1]);
		shell->last_exit_status = 255;
		return (255);
	}
	else
	{
		printf("minishell: exit: too many arguments\n");
		shell->last_exit_status = 1;
		return (1);
	}
	return (0);
}

int	exit_command(t_minishell *shell, char **cmd_args)
{
	int	exit_code;

	exit_code = shell->last_exit_status;
	free_shell(shell);
	printf("exit\n");
	if (cmd_args[1] == NULL)
		exit_code = shell->last_exit_status;
	else if (!ft_isnumeric(cmd_args[1]) || cmd_args[2])
		exit_code = continue_function(shell, cmd_args);
	else
	{
		if (ft_strlen(cmd_args[1]) > 18)
			exit_code = 255;
		else if (cmd_args[1])
			exit_code = ft_atoi(cmd_args[1]);
	}
	ft_free_arrays(cmd_args);
	exit(exit_code % 256);
}
