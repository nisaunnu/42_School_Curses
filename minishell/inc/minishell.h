/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:05:38 by nunnu             #+#    #+#             */
/*   Updated: 2024/05/20 15:00:45 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define MAX_PATH				260
# define SIGINT_NORMAL			0
# define SIGINT_COMMAND			1
# define SIGINT_RECIVED			2
# define SIGQUIT_COMMAND		3
# define SIGINT_HD				4
# define SIGINT_HD_RECIVED		5
# define SIGINT_SUBSHELL		6
# define SIGNAL_CODE			128

# define MSG "minishell: syntax error near unexpected token `newline'\n"

# include <signal.h>
# include <dirent.h>

extern volatile sig_atomic_t	g_sigint_recived;

typedef enum e_type
{
	AST_COMMAND,
	AST_PIPE,
	AST_SUBSHELL,
	AST_REDIRECT_IN,
	AST_REDIRECT_OUT,
	AST_FILE,
	AST_HEREDOC,
	AST_HEREDOC_DELIM,
	AST_AND,
	AST_OR,
	AST_SUBSHELL_EX,
}	t_type;

typedef struct s_wildcard
{
	DIR				*dir;
	struct dirent	*entry;
	char			*pat;
	char			*f_pat;
	char			*dir_path;
	char			**files;
}	t_wildcard;

typedef struct s_token
{
	t_type			type;
	char			*value;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

typedef struct s_ast_node
{
	t_type				type;
	char				*value;
	char				*delimiter;
	struct s_ast_node	*left;
	struct s_ast_node	*right;
	struct s_ast_node	*next;
	struct s_ast_node	*prev;
}	t_ast_node;

typedef struct s_tree
{
	t_ast_node	*root;
	t_ast_node	*branch;
	t_ast_node	*file;
	t_ast_node	*red_in;
	t_ast_node	*delim;
}	t_tree;

typedef struct s_minishell
{
	char		**envp;
	char		**og_envp;
	char		*executable_path;
	int			pipes[2];
	int			hd_pipes;
	int			hd_pipes_read;
	int			fd_read;
	int			fd_write;
	int			input_redirect;
	int			output_redirect;
	char		*input_line;
	t_ast_node	*ast;
	t_ast_node	*pipe_list;
	int			last_cmd;
	int			last_exit_status;
	int			shell_pid;
	int			flag_oldpwd;
}	t_minishell;

// AUX_FT
int			count_elem(char **array);
void		*check_malloc(size_t size);
char		**split_cmd(const char *s, char *delim);
char		*my_getenv(char **envp, const char *name);
void		free_env(char ***env);
void		add_var_envp(char ***envp, const char *new_var);
void		update_env_var(char ***envp, const char *key, const char *value);
void		increment_shlvl(t_minishell *shell);
void		exit_status(t_minishell *shell, const char *msg, int status);
void		ft_free_arrays(char **array);
int			ft_isnumeric(const char *str);
int			ft_isspace(int c);
int			ft_strcmp(const char *s1, const char *s2);
void		ft_strncpy(char *dst, const char *src, int n);
char		*get_path(char *cmd, const char *env_path);
char		*empty_env_switch(t_minishell *shell, char *src, int i, int cnt);
char		*ft_double(t_minishell *shell, char *src, int i);
char		*doc_envp(t_minishell *shell, char *src);
char		**split_input(const char *cmd, const char *delimiters);
void		*my_calloc(size_t count, size_t size);
char		*my_itoa(int n);
char		*my_strdup(const char *s1);
char		*my_strjoin(char const *s1, char const *s2);
char		*my_strndup(const char *src, int n);
char		*strip_quotes(char *input);
int			open_quotes(char *str);
void		handle_error(const char *msg, int use_perror, int error_code);
void		free_shell(t_minishell *shell);
void		init_minishell(t_minishell *shell, char **env);
void		reset_minishell(t_minishell *shell);

// BONUS
char		*merge_path(const char *dir_path, const char *filename);
void		split_pattern(const char *pat, char **dir_path, char **file_pat);
int			match_pattern(const char *filename, const char *pattern);
int			count_files(char *pattern, char *dir_path);
char		**command(char **args, char **files);
char		**expand_wildcards(char **args);

// BUILTIN
void		cd_command(t_minishell *shell, char **cmd_args);
void		echo_command(char **cmd_args);
void		env_command(t_minishell *shell, char **cmd_args);
int			exit_command(t_minishell *shell, char **cmd_args);
char		**copy_and_sort_envp(t_minishell *shell);
int			export_command(t_minishell *shell, char **cmd_args);
int			special_builtin(t_minishell *shell, char **cmd_args);
int			handle_builtin(t_minishell *shell, char **cmd_args);
void		pwd_command(void);
int			unset_command(t_minishell *shell, char **args);

// EXECUTE
void		execute_and_sequence(t_minishell *shell, t_ast_node *node);
void		add_pipe(t_ast_node **root, t_token *token);
void		execute_heredoc(t_minishell*shell, t_ast_node *node);
int			handle_signal(t_minishell *shell, char *value);
void		single_cmd_process(t_minishell *shell, char **args, char *path);
void		execute_single_command(t_minishell *shell, char *value);
void		execute_ast_command(t_minishell *shell, t_ast_node *node);
void		process_heredoc(t_minishell *shell, char *delimiter);
void		close_redirections(t_minishell *shell);
void		install_fd(t_minishell *shell, t_ast_node *node, int *fd_in);
void		close_fds(int *pipe_fds, int *fd_in);
int			handle_dup(t_minishell *shell);
void		create_list(t_minishell *shell, t_ast_node *cmd_node);
char		**handle_wildcards(char *value);
void		execute_pipe_cmd(t_minishell *shell, t_ast_node *cmd_node);
void		exec_subshell_ex(t_minishell *shell, char *sub_expr, int is_pipe);
void		select_exec(t_minishell *shell, char **command);
void		redirect_stdin(t_minishell *shell);
int			handle_redirect(t_minishell *shell, t_ast_node *cmd_node);

// INPUT
void		add_cmd(t_ast_node **root, t_token *token);
void		add_red_out(t_ast_node **root, t_token *token, t_ast_node **file);
void		add_hd(t_ast_node **root, t_token *token, t_ast_node **delim);
void		add_red_in(t_ast_node **root, t_token *token, t_ast_node **file);
void		add_sequence(t_tree *tree, t_token *token);
t_ast_node	*create_ast_node(t_type type, char *value);
t_token		*get_last_token(t_token *token);
int			add_token_back(t_token **head, t_token *new_token);
int			add_ast_back(t_ast_node **head, t_ast_node *new_node);
t_ast_node	*free_ast(t_ast_node *node);
void		insert_redirection(t_ast_node **root, t_ast_node **redirect_in);
t_ast_node	*build_ast(t_token *tokens);
void		handle_envp(t_minishell *shell, t_token *node);
int			handle_input(t_minishell *shell, char *input);
t_token		*lexer(char **input);
t_token		*check_pipes(t_token **root);
t_token		*create_token(t_type type, char *value);
t_type		token_type(char *value);
void		free_tokens(t_token *token);
t_token		*sort_tokens(t_token **root);

// MINISHELL
int			minishell(char **envp);

// SIGNAL
void		setup_signal(int signal, void (*handler)(int), int flags);
void		handle_sigint(int sig);
void		handle_sigquit(int sig);
void		setup_signal_handlers(void);

#endif
