/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
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

static char	*ft_switch(t_minishell *shell, t_token *token, int i, int cnt)
{
	int		j;
	char	*value;

	j = -1;
	value = NULL;
	while (shell->envp[++j])
	{
		if (!ft_strncmp(&token->value[i + 1], shell->envp[j], cnt - i - 1))
		{
			value = (char *)my_calloc(1, ft_strlen(token->value)
					+ ft_strlen(shell->envp[j]) - 2 * (cnt - i) + 1);
			ft_strncpy(value, token->value, i);
			ft_strncpy(value, &(shell->envp[j][cnt - i]),
				ft_strlen(&(shell->envp[j][cnt - i])));
			ft_strncpy(value, &token->value[cnt],
				ft_strlen(&token->value[cnt]));
			return (value);
		}
	}
	return (value);
}

static void	switch_envp(t_minishell *shell, t_token *token, int *i, int *quote)
{
	char	*new_value;
	int		cnt;

	cnt = *i + 1;
	new_value = NULL;
	if (token->type == AST_HEREDOC_DELIM)
		return ;
	if (!token->value[cnt] || ft_isspace(token->value[cnt]))
		new_value = empty_env_switch(shell, token->value, *i, cnt);
	if (!token->value[1] || token->value[1] == '?' || token->value[1] == '$')
	{
		free(new_value);
		return ;
	}
	while (ft_isalpha(token->value[cnt]) || ft_isdigit(token->value[cnt]))
		cnt++;
	if (!new_value)
		new_value = ft_switch(shell, token, *i, cnt);
	if (!new_value)
		new_value = empty_env_switch(shell, token->value, *i, cnt);
	free(token->value);
	token->value = new_value;
	*i = -1;
	*quote = 0;
}

static void	echo_double(t_minishell *shell, t_token *token, int *i, int *quote)
{
	char	*aux;

	aux = token->value;
	token->value = ft_double(shell, token->value, *i);
	*i = -1;
	*quote = 0;
	free(aux);
}

void	handle_envp(t_minishell *shell, t_token *node)
{
	t_token	*token;
	int		quote;
	int		i;

	token = node;
	while (token)
	{
		i = -1;
		quote = 0;
		while (token->type != AST_FILE && token->value[++i])
		{
			if (!quote && (token->value[i] == '\'' || token->value[i] == '\"'))
				quote = token->value[i];
			else if (token->value[i] == quote)
				quote = 0;
			if (quote != '\'' && token->value[i] == '$')
			{
				if (token->value[i + 1] == '$' || token->value[i + 1] == '?')
					echo_double(shell, token, &i, &quote);
				else if (ft_isalpha(token->value[i + 1]))
					switch_envp(shell, token, &i, &quote);
			}
		}
		token = token->next;
	}
}
