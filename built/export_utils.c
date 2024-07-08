/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:40:57 by fibarros          #+#    #+#             */
/*   Updated: 2024/07/01 14:11:05 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void	swap(char **env, int i, int j)
// {
// 	char	*temp;

// 	temp = env[i];
// 	env[i] = env[j];
// 	env[j] = temp;
// }

// void	sort_env(t_cmd *cmd)
// {
// 	int	swapped;
// 	int	i;
// 	int	j;
// 	int	size;

// 	size = 0;
// 	while (cmd->env[size] != NULL)
// 		size++;
// 	i = 0;
// 	while (i < size - 1)
// 	{
// 		swapped = 0;
// 		j = 0;
// 		while (j < (size - i - 1))
// 		{
// 			if (ft_strcmp(cmd->env[j], cmd->env[j + 1]) > 0)
// 			{
// 				swap(cmd->env, j, j + 1);
// 				swapped = 1;
// 			}
// 			j++;
// 		}
// 		if (!swapped)
// 			break ;
// 		i++;
// 	}
// }
