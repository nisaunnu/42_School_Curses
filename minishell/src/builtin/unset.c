/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu     <nunnu@student.42kocaeli.c>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:25:37 by nunnu             #+#    #+#             */
/*   Updated: 2024/05/15 18:13:32 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include "../../inc/libft/inc/libft.h"
#include <stdlib.h>

static int	find_env_var(t_minishell *shell, const char *var_name, int var_len)
{
	int	j;

	j = 0;
	while (shell->envp[j])
	{
		if (ft_strncmp(shell->envp[j], var_name, var_len) == 0
			&& shell->envp[j][var_len] == '=')
			return (j);
		j++;
	}
	return (-1);
}

static void	remove_env_var(t_minishell *shell, int index)
{
	int	k;

	k = 0;
	free (shell->envp[index]);
	k = index;
	while (shell->envp[k])
	{
		shell->envp[k] = shell->envp[k + 1];
		k++;
	}
}

int	unset_command(t_minishell *shell, char **args)
{
	int	i;
	int	index;
	int	var_len;

	i = 0;
	if (!args[0])
		return (1);
	while (args[i])
	{
		var_len = ft_strlen(args[i]);
		index = find_env_var(shell, args[i], var_len);
		if (index != -1)
			remove_env_var(shell, index);
		i++;
	}
	return (0);
}
