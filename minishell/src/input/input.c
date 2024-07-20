/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
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

static int	count_op(char *input, char *operators)
{
	int	i;
	int	flag;
	int	counter;
	int	last_quote;

	flag = 0;
	counter = 0;
	last_quote = 0;
	i = -1;
	while (input[++i])
	{
		if (input[i] == last_quote)
			last_quote = 0;
		if (!last_quote && (input[i] == 34 || input[i] == 39))
			last_quote = input[i];
		if (ft_strchr(operators, input[i]) && !last_quote && !flag)
		{
			flag++;
			counter++;
		}
		else if (!ft_strchr(operators, input[i]))
			flag = 0;
	}
	return (counter);
}

static void	handle_operators(char *input, char *p_input, char *op)
{
	int	i;
	int	j;
	int	flag;
	int	last_quote;

	i = 0;
	j = 0;
	flag = 0;
	last_quote = 0;
	while (input[i])
	{
		if (input[i] == last_quote)
			last_quote = 0;
		if (!last_quote && (input[i] == 34 || input[i] == 39))
			last_quote = input[i];
		if ((ft_strchr(op, input[i]) && !flag && !last_quote)
			|| (!ft_strchr(op, input[i]) && flag))
		{
			p_input[j++] = ' ';
			flag = 1;
			if (!ft_strchr(op, input[i]))
				flag = 0;
		}
		p_input[j++] = input[i++];
	}
}

int	handle_input(t_minishell *shell, char *input)
{
	size_t		size;
	t_token		*tokens;
	char		*p_input;

	size = ft_strlen(input) + count_op(input, "<>|&") * 2 + 1;
	p_input = (char *)my_calloc(1, size);
	handle_operators(input, p_input, "<>|&");
	tokens = lexer(split_input(p_input, " "));
	free(p_input);
	handle_envp(shell, tokens);
	if (!tokens)
		return (-1);
	shell->ast = build_ast(tokens);
	free_tokens(tokens);
	if (!shell->ast)
		return (-1);
	execute_ast_command(shell, shell->ast);
	free_ast(shell->ast);
	reset_minishell(shell);
	return (1);
}
