/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyo <jpyo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 01:52:42 by jpyo              #+#    #+#             */
/*   Updated: 2021/06/11 18:26:05 by jpyo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*
	in = open("infile", O_RDONLY);
	if (in < 0)
	{
		perror("open");
		exit(1);
	}
	out = open("outfile", O_RDWR | O_CREAT | O_TRUNC);
	if (out < 0)
	{
		perror("open");
		exit(1);
	}
	dup2(in, 0);
	dup2(out, 1);
	//i = 0;
	//while (envp[i] != 0)
	//{
	//	printf("%s\n", envp[i]);
	//	i++;
	//}
	// wc
	// grep = /usr/bin/grep
	// ls = /bin/ls
*/

// execve(path, argv, envp);
// /bin/ls
// /usr/bin/grep

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	out;
	int	in;
	int	fd[2];
	int	pid;

	if (pipe(fd) < 0)
	{
		perror("pipe");
		exit(-1);
	}
	pid = fork();
	if (pid == 0)
		pipex_child(fd, argc, argv, envp);
	else if (pid > 0)
		pipex_parent(fd, argc, argv, envp);
	else
	{
		perror("fork");
		exit(-2);
	}
	return (0);
}
