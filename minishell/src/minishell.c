/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:34:31 by abeltran          #+#    #+#             */
/*   Updated: 2023/07/19 20:10:13 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// void	ft_void(void)
// {
// 	system("leaks -q minishell");
// }

static void	delete_heredoc(void)
{
	id_t	fd;

	fd = open(".heredoc-tmp", O_RDONLY);
	if (fd > 0)
		unlink(".heredoc-tmp");
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	ft_init_data(&data, envp);
	(void) argc;
	(void) argv;
	while (!data.exit)
	{
		if (ft_read_input(&data))
		{
			if (*data.raw_input)
			{
				data.cmd = ft_parsecmd(&data);
				if (data.cmd)
				{
					ft_set_flag(1);
					if (!ft_exec_builtin(&data, data.cmd, true, false))
						data.last = ft_exec_cmd(&data, data.cmd);
					delete_heredoc();
					ft_clean_cmd(&data);
				}
			}
		}
		ft_set_flag(0);
	}
	return (free(data.raw_input), 0);
}

// int	main(int argc, char **argv, char **envp)
// {
// 	t_data			data;
//  	static char		*wc_args[] = {"wc", "-l", NULL};
// 	static char		*ls_args[] = {"ls", "-lA", NULL};
// 	static t_cmd	wc_exec = {"wc", wc_args, NULL, NULL};
// 	static t_cmd	ls_exec = {"ls", ls_args, NULL, &wc_exec};

// 	(void) argc;
// 	(void) argv;
// 	atexit(ft_void);
// 	ft_init_data(&data, envp);
// 	ft_read_input(&data);
// 	data.cmd = ft_parsecmd(&data);
// 	ft_exec_cmd(&data, data.cmd);
// 	free(data.raw_input);
// 	ft_clean_env(&data);
// }

// int	main(void)
// {
// 	char	*args[] = {"/bin/ls", "-lA", NULL};

// 	execv("/bin/ls", args);
// }

/* int	main(int argc, char **argv, char **envp)
{
	static t_redir	out_redir = {R_OUT, "out", NULL};
	static char		*wc_args[] = {"wc", "-l"};
	static char		*ls_args[] = {"ls", "-lA"};
	static t_cmd	wc_exec = {"wc", wc_args, &out_redir, NULL};
	static t_cmd	ls_exec = {"ls", ls_args, NULL, &wc_exec};
	t_data			data;

	(void) argc;
	(void) argv;
	ft_init_data(&data, envp);
	ft_exec_cmd(&data, &ls_exec);
	ft_clean_env(&data);
} */

/* int	main(void)
{
	static char	*args[] = {"ls", "-lA", NULL};

	execve("/usr/bin/ls", args, NULL);
}
 */
