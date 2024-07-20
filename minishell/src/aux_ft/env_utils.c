/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
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

char	*my_getenv(char **envp, const char *name)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(name);
	if (name == NULL || envp == NULL)
		return (NULL);
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], name, len) == 0 && envp[i][len] == '=')
			return (envp[i] + len + 1);
		i++;
	}
	return (NULL);
}

void	free_env(char ***env)
{
	int	i;

	i = 0;
	if (env && *env)
	{
		while ((*env)[i] != NULL)
		{
			free((*env)[i]);
			(*env)[i] = NULL;
			i++;
		}
		if (*env)
			free(*env);
		*env = NULL;
	}
}

void	add_var_envp(char ***envp, const char *new_var)
{
	int		i;
	char	**new_envp;

	i = 0;
	while ((*envp)[i] != NULL)
		i++;
	new_envp = (char **)malloc(sizeof(char *) * (i + 2));
	if (!new_envp)
		return ;
	i = 0;
	while ((*envp)[i] != NULL)
	{
		new_envp[i] = my_strdup((*envp)[i]);
		if (!new_envp)
			return ;
		i++;
	}
	new_envp[i] = my_strdup(new_var);
	if (!new_envp[i])
		return ;
	new_envp[i + 1] = NULL;
	ft_free_arrays(*envp);
	*envp = new_envp;
}

void	update_env_var(char ***envp, const char *key, const char *value)
{
	char	*new_var;
	char	*temp;
	int		i;
	size_t	key_len;

	i = 0;
	key_len = ft_strlen(key);
	temp = my_strjoin(key, "=");
	new_var = my_strjoin(temp, value);
	free(temp);
	while ((*envp)[i] != NULL)
	{
		if (ft_strncmp((*envp)[i], key, key_len) == 0
			&& (*envp)[i][key_len] == '=')
		{
			free((*envp)[i]);
			(*envp)[i] = new_var;
			return ;
		}
		i++;
	}
	add_var_envp(envp, new_var);
}

void	increment_shlvl(t_minishell *shell)
{
	char	*value_str;
	int		value;
	char	*new_str;

	value_str = getenv("SHLVL");
	if (value_str != NULL)
	{
		value = ft_atoi(value_str);
		value++;
	}
	else
		value = 1;
	new_str = my_itoa(value);
	update_env_var(&(shell->og_envp), "SHLVL", new_str);
	free(new_str);
}
