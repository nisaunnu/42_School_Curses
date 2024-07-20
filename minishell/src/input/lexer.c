/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
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

static int	build_heredoc(char **input, int *i, t_token **tokens)
{
	if (add_token_back(tokens, create_token(AST_HEREDOC, input[*i])) == -1)
		return (-1);
	(*i)++;
	while (input[*i] != NULL && ft_strlen(input[*i]) == 0)
		(*i)++;
	if (input[*i] != NULL)
	{
		if (add_token_back(tokens, create_token(AST_HEREDOC_DELIM,
					input[*i])) == -1)
			return (-1);
		(*i)++;
	}
	(*i)--;
	return (1);
}

static t_token	*build_command_token(char **input, int *i)
{
	char		*temp;
	char		*command;
	t_token		*new_token;

	command = my_strdup(input[*i]);
	(*i)++;
	while (input[*i] != NULL && token_type(input[*i]) == AST_COMMAND)
	{
		temp = command;
		command = my_strjoin(command, " ");
		if (!command)
			return (NULL);
		free(temp);
		temp = command;
		command = my_strjoin(command, input[*i]);
		if (!command)
			return (NULL);
		free(temp);
		(*i)++;
	}
	new_token = create_token(AST_COMMAND, command);
	free (command);
	(*i)--;
	return (new_token);
}

static int	build_token(t_token **tokens, char **input, int *i, int *is_file)
{
	t_type	type;
	int		status;

	type = token_type(input[*i]);
	if (*is_file)
	{
		if (ft_strchr("|<>&()", *input[*i]) != NULL)
			return (-1);
		status = add_token_back(tokens, create_token(AST_FILE, input[*i]));
		*is_file = 0;
	}
	else if (type == AST_COMMAND)
		status = add_token_back(tokens, build_command_token(input, i));
	else if (type == AST_HEREDOC)
		status = build_heredoc(input, i, tokens);
	else if (type == AST_SUBSHELL_EX)
		status = add_token_back(tokens, create_token(type, input[*i]));
	else
	{
		if (type == AST_REDIRECT_IN || type == AST_REDIRECT_OUT)
			*is_file = 1;
		status = add_token_back(tokens, create_token(type, input[*i]));
	}
	return (status);
}

static void	build_collapsed_token(t_token **root, t_token *token)
{
	char	*value;
	char	*temp;

	while (token)
	{
		if (token->type == AST_COMMAND)
		{
			value = my_strdup(token->value);
			while (token->next && token->next->type == AST_COMMAND)
			{
				temp = my_strjoin(value, " ");
				free(value);
				value = my_strjoin(temp, token->next->value);
				free(temp);
				token = token->next;
			}
			add_token_back(root, create_token(AST_COMMAND, value));
			free(value);
		}
		else
			add_token_back(root, create_token(token->type, token->value));
		token = token->next;
	}
	token = *root;
}

t_token	*lexer(char **input)
{
	int		i;
	int		is_file;
	t_token	*tokens;
	t_token	*collapsed_tokens;

	i = -1;
	is_file = 0;
	tokens = NULL;
	collapsed_tokens = NULL;
	if (!input)
		return (NULL);
	while (input[++i])
	{
		if (build_token(&tokens, input, &i, &is_file) == -1)
		{
			printf("minishell: syntax error near unexpected token");
			printf(" `%s'\n", input[i]);
			return (ft_free_arrays(input), free_tokens(tokens), NULL);
		}
	}
	ft_free_arrays(input);
	if (!sort_tokens(&tokens))
		return (NULL);
	build_collapsed_token(&collapsed_tokens, tokens);
	return (free_tokens(tokens), collapsed_tokens);
}
