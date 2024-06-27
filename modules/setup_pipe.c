/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 14:35:09 by keramos-          #+#    #+#             */
/*   Updated: 2024/06/27 11:43:11 by fibarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Function to execute the command on both sides of the pipe.
 * Takes the command structure and the pipe file descriptor as arguments.
 */
void	execute_pipe(t_ast *root, t_msh *msh)
{
	int		pipefd[2];
	pid_t	p1;
	pid_t	p2;

	if (pipe(pipefd) == -1)
		ft_error("pipe");
	p1 = fork_first_child(root, msh, pipefd);
	p2 = fork_second_child(root, msh, pipefd);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(p1, NULL, 0);
	waitpid(p2, NULL, 0);
	return ;
}

pid_t	fork_first_child(t_ast *root, t_msh *msh, int pipefd[2])
{
	pid_t	p1;

	p1 = fork();
	if (p1 == -1)
		ft_error("fork p1");
	if (p1 == 0)
	{
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		execute_ast(root->left, msh);
		exit(msh->exit_status);
	}
	return (p1);
}

pid_t	fork_second_child(t_ast *root, t_msh *msh, int pipefd[2])
{
	pid_t	p2;

	p2 = fork();
	if (p2 == -1)
		ft_error("fork p2");
	if (p2 == 0)
	{
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		execute_ast(root->right, msh);
		exit(msh->exit_status);
	}
	return (p2);
}
