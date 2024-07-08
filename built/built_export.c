/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:23:29 by fibarros          #+#    #+#             */
/*   Updated: 2024/07/05 16:32:06 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// could also use the t_msh msh ?


void	ft_export(t_cmd command)
{
    /*
        tokens
        
    */
    
	/*
        * if no args, print all vars;
        * if there are args, each arg should be a potential env variable to be added 
        to the linked list
        * if var already exists, we have to update the list and only if it's assigned
        if the var doesnt exist, create a new node in the envp linked list 
    
    */
}

// print_all_exported_vars (t_env *env)

// update env var

// create env var

// get sorted list

