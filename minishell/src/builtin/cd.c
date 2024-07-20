/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:25:37 by nunnu             #+#    #+#             */
/*   Updated: 2024/05/15 18:37:33 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../inc/minishell.h"

void	cd_command(t_minishell *shell, char **cmd_args)
{
	char	new_cwd[MAX_PATH];
	char	old_path[MAX_PATH];
	char	*new_path;

	getcwd(old_path, sizeof(old_path));
	new_path = cmd_args[1];
	if (!new_path)
		new_path = getenv("HOME");
	if (chdir(new_path) == 0)
	{
		getcwd(new_cwd, sizeof(new_cwd));
		update_env_var(&(shell->envp), "OLDPWD", old_path);
		update_env_var(&(shell->envp), "PWD", new_cwd);
		shell->flag_oldpwd = 1;
		shell->last_exit_status = 0;
	}
	else
	{
		printf("cd: %s: No such file or directory\n", new_path);
		shell->last_exit_status = 1;
	}
}
