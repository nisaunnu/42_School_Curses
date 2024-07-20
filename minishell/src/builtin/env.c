/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu     <nunnu@student.42kocaeli.c>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:25:37 by nunnu             #+#    #+#             */
/*   Updated: 2024/05/15 18:13:32 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../inc/minishell.h"
#include "../../inc/libft/inc/libft.h"

static int	find_string_in_array(char **arr, char *search_str)
{
	int	i;

	i = 0;
	if (!search_str)
		return (0);
	while (arr[i] != NULL)
	{
		if (ft_strnstr(arr[i], search_str, ft_strlen(search_str)) != NULL)
			return (i);
		i++;
	}
	return (-1);
}

static void	env_loop(t_minishell *shell, int i)
{
	if (ft_strnstr(shell->envp[i], "OLDPWD", ft_strlen(shell->envp[i]))
		&& shell->flag_oldpwd == 0)
		i++;
	else
	{
		if (ft_strnstr(shell->envp[i], "=", ft_strlen(shell->envp[i])) != NULL)
			printf("%s\n", shell->envp[i]);
		i++;
	}
}

void	env_command(t_minishell *shell, char **cmd_args)
{
	int	i;
	int	re_func;

	i = -1;
	re_func = find_string_in_array(shell->envp, cmd_args[1]);
	if (re_func == -1)
	{
		ft_putstr_fd("env: ", 2);
		ft_putstr_fd(cmd_args[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		shell->last_exit_status = 127;
	}
	else if (re_func)
		printf("%s\n", shell->envp[re_func]);
	else
	{
		i = -1;
		while (shell->envp[++i] != NULL)
			env_loop(shell, i);
	}
}
