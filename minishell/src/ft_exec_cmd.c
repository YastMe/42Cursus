/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:25:16 by fragarci          #+#    #+#             */
/*   Updated: 2023/07/19 17:58:28 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	redirect_init(t_data *data, pid_t pid, int pipefd[2],
t_redir *redir)
{
	if (!redir || !pipefd || !redir->file)
		return ;
	while (redir)
	{
		if (redir->type == R_OUT || redir->type == DR_OUT)
			ft_out_redir(pid, redir);
		else if (redir->type == R_IN || redir->type == DR_IN)
			ft_in_redir(data, pid, redir, pipefd);
		redir = redir->next;
	}
}

static void	pipe_init(t_data *data, pid_t pid, int pipefd[2], t_cmd *execute)
{
	if (!execute->next)
		return ;
	if (pid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		ft_exec_cmd(data, execute->next);
	}
}

int	ft_exec_builtin(t_data *data, t_cmd *execute, bool is_parent, bool is_raw)
{
	if (execute->path)
	{
		if (ft_strcmp(execute->path, "cd") && (is_parent || is_raw))
			ft_cd(execute->argv[1], data);
		else if (ft_strcmp(execute->path, "echo") && (!is_parent || is_raw))
			ft_echo(*data);
		else if (ft_strcmp(execute->path, "env") && (!is_parent || is_raw))
			ft_env(data->env_variables);
		else if (ft_strcmp(execute->path, "exit") && (is_parent || is_raw))
			ft_exit(data);
		else if (ft_strcmp(execute->path, "export") && (is_parent || is_raw))
			ft_export(data, execute->argv[1]);
		else if (ft_strcmp(execute->path, "pwd") && (!is_parent || is_raw))
			ft_pwd();
		else if (ft_strcmp(execute->path, "unset") && (is_parent || is_raw))
			ft_unset(data, execute->argv[1]);
		else
			return (0);
		if (!is_parent)
		{
			ft_clean_child(data);
			exit(EXIT_SUCCESS);
		}
	}
	return (1);
}

int	ft_exec_cmd(t_data *data, t_cmd *execute)
{
	int		status;
	int		stdin_fd;
	int		pipefd[2];
	pid_t	child_pid;

	status = 0;
	stdin_fd = dup(STDIN_FILENO);
	if (ft_check_heredoc(data, execute->redir) && pipe(pipefd) == -1)
		return (perror("pipe"), 1);
	child_pid = fork();
	if (child_pid == -1)
		return (perror("fork"), 1);
	else if (child_pid == 0)
	{
		pipe_init(data, child_pid, pipefd, execute);
		redirect_init(data, child_pid, pipefd, execute->redir);
		ft_exec_path(data, execute);
	}
	else
	{
		pipe_init(data, child_pid, pipefd, execute);
		redirect_init(data, child_pid, pipefd, execute->redir);
		waitpid(child_pid, &status, 0);
	}
	return (dup2(stdin_fd, STDIN_FILENO), status);
}
