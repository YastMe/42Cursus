/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:41:58 by fragarci          #+#    #+#             */
/*   Updated: 2023/07/19 23:23:27 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static char	*heredoc_join(char *s1, char *s2, bool free_s1)
{
	char	*ret;
	char	*aux;

	aux = ft_strjoin(s1, s2);
	ret = ft_strjoin(aux, "\n");
	free(aux);
	free(s2);
	if (free_s1)
		free(s1);
	return (ret);
}

static void	read_heredoc(t_data *data, t_redir *redir)
{
	int		fd;
	char	*aux;

	data->heredoc = 0;
	aux = 0;
	while (1)
	{
		aux = readline("> ");
		if (!aux || ft_strcmp(aux, redir->file))
			break ;
		if (!data->heredoc)
			data->heredoc = heredoc_join("", aux, false);
		else
			data->heredoc = heredoc_join(data->heredoc, aux, true);
	}
	fd = open(".heredoc-tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(fd, data->heredoc, ft_strlen(data->heredoc));
	close(fd);
	free(redir->file);
	free(data->heredoc);
	redir->file = ft_strdup(".heredoc-tmp");
	redir->type = R_IN;
}

int	ft_check_heredoc(t_data *data, t_redir *redir)
{
	if (!redir || !redir->file)
		return (1);
	while (redir)
	{
		if (redir->type == DR_IN)
			read_heredoc(data, redir);
		redir = redir->next;
	}
	return (1);
}
