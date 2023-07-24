/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:42:32 by fragarci          #+#    #+#             */
/*   Updated: 2023/07/13 11:57:31 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	heredoc(t_data *data, pid_t pid, int pipefd[2])
{
	if (pid == 0)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
	}
	else
	{
		close(pipefd[0]);
		if (data->heredoc)
			write(pipefd[1], data->heredoc, ft_strlen(data->heredoc));
		close(pipefd[1]);
		free(data->heredoc);
	}
}

void	ft_in_redir(t_data *data, pid_t pid, t_redir *redir, int pipefd[2])
{
	int	fd;

	if (!pipefd)
		return ;
	if (pid == 0 && redir->type == R_IN)
	{
		fd = open(redir->file, O_RDONLY);
		if (fd == -1)
			return (perror("open"));
		dup2(fd, STDIN_FILENO);
	}
	else if (redir->type == DR_IN)
		heredoc(data, pid, pipefd);
}

void	ft_out_redir(pid_t pid, t_redir *redir)
{
	int	fd;

	if (pid != 0)
		return ;
	if (redir->type == R_OUT)
	{
		fd = open(redir->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			return (perror("open"));
		dup2(fd, STDOUT_FILENO);
	}
	else if (redir->type == DR_OUT)
	{
		fd = open(redir->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd == -1)
			return (perror("open"));
		dup2(fd, STDOUT_FILENO);
	}
}
