/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
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

t_token	*create_token(t_type type, char *value)
{
	t_token	*new_token;

	new_token = (t_token *)malloc(sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->type = type;
	new_token->next = NULL;
	new_token->prev = NULL;
	new_token->value = my_strdup(value);
	if (open_quotes(value) == -1)
	{
		free(new_token->value);
		free(new_token);
		return (NULL);
	}
	return (new_token);
}

t_type	token_type(char *value)
{
	if (ft_strncmp(value, "||", 2) == 0)
		return (AST_OR);
	else if (ft_strncmp(value, "|", 1) == 0)
		return (AST_PIPE);
	else if (ft_strncmp(value, "&&", 2) == 0)
		return (AST_AND);
	else if (ft_strncmp(value, "<<", 2) == 0)
		return (AST_HEREDOC);
	else if (ft_strncmp(value, "<", 1) == 0)
		return (AST_REDIRECT_IN);
	else if (ft_strncmp(value, ">", 1) == 0)
		return (AST_REDIRECT_OUT);
	else if (ft_strncmp(value, "(", 1) == 0)
		return (AST_SUBSHELL_EX);
	return (AST_COMMAND);
}

void	free_tokens(t_token *tokens)
{
	t_token	*next;

	while (tokens)
	{
		next = tokens->next;
		free(tokens->value);
		free(tokens);
		tokens = next;
	}
}

static int	is_type(t_token *token)
{
	if (token->type == AST_COMMAND)
		return (0);
	if (token->type == AST_PIPE)
		return (0);
	if (token->type == AST_AND)
		return (0);
	if (token->type == AST_OR)
		return (0);
	if (token->type == AST_SUBSHELL_EX)
		return (0);
	return (1);
}

t_token	*sort_tokens(t_token **root)
{
	t_token	*token;

	token = *root;
	while (token)
	{
		if (token->type == AST_COMMAND && token->prev && is_type(token->prev))
		{
			if (token->next)
				token->next->prev = token->prev;
			if (token->prev)
				token->prev->next = token->next;
			if (token->prev && token->prev->prev)
				token->prev->prev->next = token;
			token->next = token->prev;
			token->prev = token->next->prev;
			if (token->next)
				token->next->prev = token;
		}
		else
			token = token->next;
	}
	token = *root;
	return (check_pipes(root));
}
