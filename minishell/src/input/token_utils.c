/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu     <nunnu@student.42kocaeli.c>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:25:37 by nunnu             #+#    #+#             */
/*   Updated: 2024/05/15 18:13:32 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../inc/minishell.h"

static int	check_type(t_token *token)
{
	if (token->type == AST_PIPE)
		return (1);
	if (token->type == AST_AND)
		return (1);
	if (token->type == AST_OR)
		return (1);
	return (0);
}

t_token	*check_pipes(t_token **root)
{
	t_token	*token;

	token = *root;
	while (token && token->prev)
		token = token->prev;
	*root = token;
	while (token)
	{
		if (token->type == AST_PIPE)
		{
			if (!token->prev || !token->next || check_type(token->prev)
				|| check_type(token->next))
			{
				printf("minishell: syntax error near unexpected token %s\n",
					token->value);
				free_tokens(*root);
				return (NULL);
			}
		}
		token = token->next;
	}
	return (*root);
}
