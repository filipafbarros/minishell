/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:23:29 by fibarros          #+#    #+#             */
/*   Updated: 2024/07/01 11:09:16 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export(t_cmd command)
{
	
}

// should we do a quit_minishell function or something?

t_list	*sort_env(t_list *env)
{
	t_list	*sorted_list;

	sorted_list = ft_lstdup(env);
	if (!sorted_list)
		return (EXIT_FAILURE);
	
}
