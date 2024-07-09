/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erro.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:19:54 by keramos-          #+#    #+#             */
/*   Updated: 2024/07/09 14:59:51 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Function to print an error message and exit the program.
 * Takes an error message as an argument and prints it before exiting.
 */
void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	// ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}
