/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:07:43 by keramos-          #+#    #+#             */
/*   Updated: 2024/07/08 10:39:21 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* this function to continuously receive and process user input */
void	receive_msg(t_msh *msh)
{
	char	*prompt;

	while (1)
	{
		prompt = read_input();
		if (!prompt)
		{
			ft_printf("Exit\n");
			break ;
		}
		process_cmd(prompt, msh);
	}
}

/*
	added init_env function
*/

int	main(int argc, char **argv, char **env)
{
	t_msh	msh;

	(void)argv;
	if (argc != 1)
	{
		ft_printf(P_R"💢\tThis program doesn't need arguments\n"RT);
		exit(0);
	}
	init_env(&msh, env);
	ft_intro_art();
	receive_msg(&msh);
	return (0);
}

/*

Structure t_msh:

If t_msh contains fields that are arrays or pointers, and their sizes are not known 
at compile time or they need to grow/shrink dynamically, you should allocate memory 
dynamically for those fields.
If t_msh only contains simple data types (like integers or fixed-size arrays) and 
pointers to memory that is already managed elsewhere (like env), then you don't 
necessarily need to allocate memory dynamically for the t_msh structure itself.
Sub-Structures or Arrays in t_msh:

If t_msh contains sub-structures or arrays that need dynamic memory, you should 
allocate memory for them. For example, if t_msh has a field char **env that you
 need to copy from the env parameter, then you need to allocate memory for 
 the array and each string.
 
 */
