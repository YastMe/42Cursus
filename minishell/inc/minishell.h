/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:15:24 by abeltran          #+#    #+#             */
/*   Updated: 2023/07/19 19:38:24 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define _XOPEN_SOURCE 500

# include "../Libft/include/libft.h"
# include "../inc/colors.h"

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <stdbool.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <limits.h>
# include <signal.h>
# include <fcntl.h>

// t_redir types //

# define R_IN 1		// Redirect in	(<)
# define R_OUT 2	// Redirect out	(>)
# define DR_IN 3	// Double redirect in		(<<)
# define DR_OUT 4	// Double redirect out	(>>)

typedef struct s_redir
{
	int				type;
	char			*file;
	struct s_redir	*next;
}	t_redir;

typedef struct s_cmd
{
	char			*path;
	char			**argv;
	t_redir			*redir;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_data
{
	t_env	*env_variables;
	char	*raw_input;
	char	*heredoc;
	char	**envp;
	t_cmd	*cmd;
	int		last;
	bool	exit;
}	t_data;

// Minishell initialization

/**
 * @brief Initializes the main struct for the shell.
 *
 * @param data
 * @param envp
 * @return int
 */
int		ft_init_data(t_data *data, char **envp);

// Read user user input

/**
 * @brief Reads the user input and checks its validity.
 *
 * @param data
 * @return int
 */
int		ft_read_input(t_data *data);

// Parse user input

/**
 * @brief Replaces environment variable names with
 * 		  their corresponding value if applicable.
 *
 * @param data
 * @param argv
 */
void	ft_parse_env(t_data *data, char	**argv);

/**
 * @brief Parses the raw input from the user into a t_cmd list.
 *
 * @param data
 * @return t_cmd*
 */
t_cmd	*ft_parsecmd(t_data *data);

/**
 * @brief Adds a cmd struct at the end of the list.
 *
 * @param cmd
 * @param argv
 */
void	ft_add_cmd(t_cmd *cmd, char **argv);

/**
 * @brief Mallocs a cmd and sets its internal values to NULL.
 *
 * @return t_cmd*
 */
t_cmd	*ft_new_cmd(void);

/**
 * @brief Splits the raw input from the user into an argv format.
 *
 * @param str
 * @return char**
 */
char	**ft_minisplit(char *str);

/**
 * @brief Splits the raw input from the user by pipes.
 *
 * @param str
 * @return char**
 */
char	**ft_pipesplit(char *str);

/**
 * @brief Removes innecesary quotes from input.
 *
 * @param argv
 * @return char**
 */
char	**ft_delete_quotes(char **argv);

// Builtins

/**
 * @brief Sets the data->exit value to true and cleans up the allocated memory.
 *
 * @param data
 * @return int
 */
int		ft_exit(t_data *data);

/**
 * @brief Creates a new node onto the t_env list.
 *
 * @param data
 * @param raw_string
 * @return int
 */
int		ft_export(t_data *data, char *raw_string);

/**
 * @brief Deletes a node from the t_env list.
 *
 * @param data
 * @param raw_string
 * @return int
 */
int		ft_unset(t_data *data, char *raw_string);

/**
 * @brief Prints the given argv onto the screen,
 * 		  taking into account the -n option.
 *
 * @param args
 * @return int
 */
int		ft_echo(t_data data);

/**
 * @brief Lists all the nodes from the t_env list.
 *
 * @param env
 * @return int
 */
int		ft_env(t_env *env);

/**
 * @brief Prints the current working directory.
 *
 * @return int
 */
int		ft_pwd(void);

/**
 * @brief Changes the working directory to the one given on path.
 * 		  If path is NULL, returns to the HOME directory.
 *
 * @param path
 * @param data
 * @return int
 */
int		ft_cd(char *path, t_data *data);

//Enviroment Utils

/**
 * @brief Fetches a t_env node from the list with the given name.
 *
 * @param data
 * @param name
 * @return t_env*
 */
t_env	*ft_get_env(t_data *data, char *name);

/**
 * @brief Measures the environment variable's name length.
 *
 * @param name
 * @return size_t
 */
size_t	ft_env_name_len(char *name);

/**
 * @brief Checks if a variable name is valid.
 *
 * @param name
 * @return true
 * @return false
 */
bool	ft_valid_env_name(char *name);

/**
 * @brief Parses the whole t_env linked list into a char**
 *
 * @param data
 */
void	ft_parse_list(t_data *data);

/**
 * @brief Checks if the current char is a single quote. That's it.
 *
 * @param c
 * @param quote
 * @return char
 */
char	ft_check_quote(char c, char quote);

// Command Execution

/**
 * @brief Tries to execute the builtins commands,
 * 		  taking into account whether is a fork call or a raw one.
 *
 * @param data
 * @param execute
 * @param is_parent
 * @param is_raw
 * @return int
 */
int		ft_exec_builtin(t_data *data, t_cmd *execute,
			bool is_parent, bool is_raw);

/**
 * @brief Search a binary to execute in the current working directory
 * 		  and the PATH variable
 *
 * @param data
 * @param execute
 */
void	ft_exec_path(t_data *data, t_cmd *execute);

/**
 * @brief Executes the given cmd.
 *
 * @param data
 * @param execute
 * @return int
 */
int		ft_exec_cmd(t_data *data, t_cmd *execute);

// Redirections

/**
 * @brief Handles the output redirections. (> / >>)
 *
 * @param pid
 * @param redir
 */
void	ft_out_redir(pid_t pid, t_redir *redir);

/**
 * @brief Handles the input redirections. (< / <<)
 *
 * @param pid
 * @param redir
 * @param pipefd
 * @param ft_stdin
 */
void	ft_in_redir(t_data *data, pid_t pid, t_redir *redir, int pipefd[2]);

// HEREDOC

int		ft_check_heredoc(t_data *data, t_redir *redir);

// Error Handling

/**
 * @brief Prints the given error onto STDERROR.
 *
 * @param err_msg
 */
void	ft_puterr(char *err_msg);

// Signals

/**
 * @brief Creates the correct handler for each signal (^C, ^D, ^\)
 *
 */
void	ft_init_signals(void);

/**
 * @brief Sets the active process flag.
 * 
*/
void	ft_set_flag(int i);

//Cleanup

/**
 * @brief Frees the t_env list stored in data, with its contents.
 *
 * @param data
 */
void	ft_clean_env(t_data *data);

/**
 * @brief Completely frees a char** array and its contents.
 *
 * @param array
 */
void	ft_arrcln(char	**array);

/**
 * @brief Frees the current command stored in data, with its contents.
 *
 * @param data
 */
void	ft_clean_cmd(t_data *data);

/**
 * @brief Calls ft_clean_cmd and ft_clean_env on a child process to save lines.
 *
 * @param data
 */
void	ft_clean_child(t_data *data);

#endif
