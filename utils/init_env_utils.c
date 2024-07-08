/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:30:43 by fibarros          #+#    #+#             */
/*   Updated: 2024/07/08 11:34:29 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	array_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	free_env(t_msh *msh)
{
	int	i;

	i = 0;
	while (msh->env[i])
	{
		free(msh->env[i]);
		i++;
	}
	free(msh->env);
	free_env_list(msh->env_list);
}

void	free_env_list(t_env *env_list)
{
	t_env	*current;

	current = env_list;
	while (current)
	{
		free(current->name);
		free(current->value);
		free(current);
		current = current->next;
	}
}
