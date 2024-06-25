/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 13:40:58 by keramos-          #+#    #+#             */
/*   Updated: 2024/06/25 12:32:38 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Function to create a new AST node.
 * Takes the value of the node as an argument.
 * Returns a pointer to the new AST node.
 */
t_ast	*create_ast_node(char *value, t_op op)
{
	t_ast	*node;

	node = (t_ast *)malloc(sizeof(t_ast));
	if (!node)
		return (NULL);
	node->value = ft_strdup(value);
	node->op = op;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

/*
 * Function to initialize the AST with the first token.
 * Takes the head of the token list as an argument.
 * Returns the root of the AST and advances the token pointer.
 */
t_ast	*init_ast(t_token **tokens)
{
	t_ast	*root;

	if (!tokens || !*tokens)
		return (NULL);
	root = create_ast_node((*tokens)->value, (*tokens)->op);
	*tokens = (*tokens)->next;
	return (root);
}

/*
 * Function to handle non-operator tokens and update the AST.
 * Takes the current token and the current AST node as arguments.
 * Returns the updated current AST node.
 */
t_ast	*handle_non_operator(t_token **current_token, t_ast *current_node)
{
	t_ast	*new_node;
	t_ast	*temp;

	if (is_redirection((*current_token)->op))
		current_node = handle_redirection(current_token, current_node);
	else
	{
		new_node = create_ast_node((*current_token)->value, \
		(*current_token)->op);
		if (!current_node->left)
			current_node->left = new_node;
		else if (!current_node->right)
			current_node->right = new_node;
		else
		{
			temp = current_node->right;
			while (temp->right)
				temp = temp->right;
			temp->right = new_node;
		}
		*current_token = (*current_token)->next;
	}
	return (current_node);
}

/*
 * Function to parse tokens into an AST.
 * Takes the head of the token list as an argument.
 * Returns the root of the AST.
 */

t_ast	*parse_tokens_to_ast(t_token *tokens)
{
	t_ast	*root;
	t_ast	*current_node;
	t_token	*current_token;

	root = init_ast(&tokens);
	current_node = root;
	current_token = tokens;
	while (current_token)
	{
		if (is_redirection(current_token->op))
			current_node = handle_redirection(&current_token, current_node);
		else if (current_token->op != NONE)
			root = handle_operator_ast(&current_token, root);
		else
			current_node = handle_non_operator(&current_token, current_node);
	}
	return (root);
}
