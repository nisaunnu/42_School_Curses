/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu     <nunnu@student.42kocaeli.c>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:25:37 by nunnu             #+#    #+#             */
/*   Updated: 2024/05/15 18:13:32 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include <sys/_types/_null.h>

void	add_cmd(t_ast_node **root, t_token *token)
{
	t_ast_node	*cmd;
	t_ast_node	*node;

	cmd = create_ast_node(token->type, token->value);
	node = *root;
	if (!node)
		(*root) = cmd;
	else
	{
		while (node->left)
			node = node->left;
		node->left = cmd;
	}
}

void	add_red_out(t_ast_node **root, t_token *token, t_ast_node **file)
{
	t_ast_node	*redirect;
	t_ast_node	*node;

	node = *root;
	redirect = create_ast_node(token->type, token->value);
	if (*file)
		redirect->right = (*file);
	*file = NULL;
	if (!node)
		*root = redirect;
	else if (node->type == AST_COMMAND || node->type == AST_REDIRECT_OUT)
	{
		redirect->left = (*root);
		(*root) = redirect;
	}
	else
	{
		while (node->left && node->left->type != AST_COMMAND
			&& node->left->type != AST_REDIRECT_OUT)
			node = node->left;
		redirect->left = node->left;
		node->left = redirect;
	}
}

void	add_hd(t_ast_node **root, t_token *token, t_ast_node **delim)
{
	t_ast_node	*hd;

	hd = create_ast_node(token->type, token->value);
	if (*delim)
		hd->right = (*delim);
	*delim = NULL;
	if (!(*root))
		(*root) = hd;
	else if ((*root)->type == AST_PIPE)
	{
		hd->left = (*root)->left;
		(*root)->left = hd;
	}
	else
	{
		hd->left = (*root);
		(*root) = hd;
	}
}

void	add_red_in(t_ast_node **root, t_token *token, t_ast_node **file)
{
	(*root) = create_ast_node(token->type, token->value);
	if (*file)
		(*root)->right = (*file);
	*file = NULL;
}

void	add_sequence(t_tree *tree, t_token *token)
{
	t_ast_node	*node;
	t_ast_node	*iter;

	node = create_ast_node(token->type, token->value);
	iter = tree->root;
	insert_redirection(&tree->branch, &tree->red_in);
	node->right = tree->branch;
	tree->branch = NULL;
	if (!tree->root)
		tree->root = node;
	else
	{
		while (iter->left)
			iter = iter->left;
		iter->left = node;
	}
}
