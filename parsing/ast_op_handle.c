/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_op_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:33:38 by fibarros          #+#    #+#             */
/*   Updated: 2024/06/25 14:52:32 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast	*create_operator_node(t_token **current_token, t_ast *ast_node)
{
	t_ast	*new_node;

	new_node = create_ast_node((*current_token)->value, (*current_token)->op);
	new_node->left = ast_node;
	*current_token = (*current_token)->next;
	return (new_node);
}

t_ast	*handle_right_child(t_token **current_token)
{
	t_ast	*current_right;

	current_right = create_ast_node((*current_token)->value, \
	(*current_token)->op);
	*current_token = (*current_token)->next;
	if (current_right->op == NONE && (*current_token)->op == NONE)
	{
		current_right->left = create_ast_node((*current_token)->value, \
		(*current_token)->op);
		*current_token = (*current_token)->next;
	}
	return (current_right);
}

void	handle_remaining_tokens(t_token **token, t_ast *right)
{
	t_ast	*arg_node;
	t_ast	*temp;

	while (*token) 
	{
		if ((*token)->op != NONE) 
		{
			right->right = handle_operator_ast(token, right->right);
			break ;
		}
		else
		{
			arg_node = create_ast_node((*token)->value, (*token)->op);
			if (!right->left)
				right->left = arg_node;
			else
			{
				temp = right->left;
				while (temp->right)
					temp = temp->right;
				temp->right = arg_node;
			}
			*token = (*token)->next;
		}
	}
}

/*
 * Function to handle operator tokens and update the AST.
 * Takes the current token and the root of the AST as arguments.
 * Returns the updated root of the AST.
 * 
 * Check if there's no need to handle more redirection in the else statement
 */
t_ast	*handle_operator_ast(t_token **current_token, t_ast *root)
{
	t_ast	*new_node;
	t_ast	*current_right;

	new_node = create_operator_node(current_token, root);
	if (*current_token) 
	{
		if (is_redirection((*current_token)->op))
			handle_redirection(current_token, new_node);
		else
		{
			current_right = handle_right_child(current_token);
			// new_node->right = handle_right_child(current_token);
			handle_remaining_tokens(current_token, current_right);
		}
	}
	return (new_node);
}
