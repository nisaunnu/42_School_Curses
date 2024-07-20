/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu     <nunnu@student.42kocaeli.c>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:25:37 by nunnu             #+#    #+#             */
/*   Updated: 2024/05/15 18:13:32 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/_types/_null.h>
#include "../../inc/minishell.h"
#include "../../inc/libft/inc/libft.h"

static int	is_valid_varname(const char *name)
{
	if (!name || !*name || (!ft_isalpha(*name) && *name != '_'))
		return (0);
	while (*name)
	{
		if (!ft_isalnum(*name) && *name != '=' && *name != '_' && *name != '/')
			return (0);
		name++;
	}
	return (1);
}

static int	process_export(t_minishell *shell, const char *arg)
{
	char		**tokens;
	int			status;

	status = 0;
	if (!is_valid_varname(arg))
	{
		printf("minishell: export: `%s': not a valid identifier\n", arg);
		shell->last_exit_status = 1;
		return (-1);
	}
	tokens = ft_split(arg, '=');
	if (tokens == NULL)
		return (perror("Error in split_cmd"), -1);
	if (tokens[0])
	{
		unset_command(shell, tokens);
		if (arg)
			add_var_envp(&(shell->envp), arg);
		else
		{
			perror("Invalid export argument");
			status = -1;
		}
	}
	return (ft_free_arrays(tokens), status);
}

static	void	export_dequote(t_minishell *shell)
{
	int		i;
	int		j;
	char	**a;

	i = -1;
	a = copy_and_sort_envp(shell);
	if (!a)
		return ;
	while (a[++i] != NULL)
	{
		j = -1;
		printf("declare -x ");
		while (a[i][++j] != '\0')
		{
			if (a[i][j] == '=')
				printf("=\"");
			else if (a[i][j] != '\0')
				printf("%c", a[i][j]);
		}
		if (ft_strnstr(a[i], "=", ft_strlen(a[i])) != NULL)
			printf("\"");
		printf("\n");
	}
	free_env(&a);
}

int	export_command(t_minishell *shell, char **args)
{
	int			i;
	int			ret;
	int			status;

	ret = 0;
	i = 0;
	status = 0;
	if (args[0] == NULL)
		export_dequote(shell);
	else
	{
		while (args[i])
		{
			ret = process_export(shell, args[i]);
			if (ret != 0)
				status = ret;
			i++;
		}
	}
	return (status);
}
