/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:08:36 by fibarros          #+#    #+#             */
/*   Updated: 2024/06/27 15:01:19 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirection_exec(t_ast *root, t_msh msh)
{
    

    if (root->op == REDIR_APPEND)
    {
        exec_append_redir();
    }
    else if (root->op == REDIR_REPLACE )
    {
        exec_replace_redir();
    }
    else if (root->op == REDIR_INPUT)
	{
        exec_input_redir();   
    }
}
