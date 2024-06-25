/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:30:09 by fibarros          #+#    #+#             */
/*   Updated: 2024/06/25 11:53:56 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Handle redirection tokens and update the AST

t_ast	*handle_redirection(t_token **current_token, t_ast *current_node)
{
	t_ast	*redir_node;
	t_ast	*file_node;
	t_ast	*temp;

	redir_node = create_ast_node((*current_token)->value, (*current_token)->op);
	*current_token = (*current_token)->next;
	if (*current_token)
	{
		file_node = create_ast_node((*current_token)->value, NONE);
		redir_node->left = file_node;
		*current_token = (*current_token)->next;
	}
	if (!current_node->right)
		current_node->right = redir_node;
	else
	{
		temp = current_node->right;
		while (temp->right)
			temp = temp->right;
		temp->right = redir_node;
	}
	return (current_node);
}

// Check if the current token is a redirection operator

int	is_redirection(t_op op)
{
	return (op == REDIR_APPEND || op == REDIR_REPLACE || \
	op == REDIR_HERE_DOC || op == REDIR_INPUT);
}

