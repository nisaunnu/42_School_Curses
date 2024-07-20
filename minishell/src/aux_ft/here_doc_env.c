/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:25:37 by nunnu             #+#    #+#             */
/*   Updated: 2024/05/15 18:31:47 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include "../../inc/libft/inc/libft.h"
#include <stdlib.h>

static char	*doc_switch(t_minishell *shell, char *src, int i, int cnt)
{
	int		j;
	char	*value;

	j = -1;
	value = NULL;
	while (shell->envp[++j])
	{
		if (!ft_strncmp(&src[i + 1], shell->envp[j], cnt - i - 1))
		{
			value = (char *)my_calloc(1, ft_strlen(src)
					+ ft_strlen(shell->envp[j]) - 2 * (cnt - i) + 1);
			ft_strncpy(value, src, i);
			ft_strncpy(value, &(shell->envp[j][cnt - i]),
				ft_strlen(&(shell->envp[j][cnt - i])));
			ft_strncpy(value, &src[cnt], ft_strlen(&src[cnt]));
			if (!value)
				return (NULL);
			break ;
		}
	}
	return (value);
}

char	*empty_env_switch(t_minishell *shell, char *src, int i, int cnt)
{
	char	*value;

	(void)shell;
	value = NULL;
	value = (char *)my_calloc(1, ft_strlen(src) - (cnt - i) + 1);
	if (!value)
		return (NULL);
	ft_strncpy(value, src, i);
	ft_strncpy(value, "", 0);
	ft_strncpy(value, &src[cnt], ft_strlen(&src[cnt]));
	return (value);
}

char	*ft_double(t_minishell *shell, char *src, int i)
{
	char	*line;
	char	*pid;
	int		cnt;

	cnt = i + 2;
	if (src[i + 1] == '$')
		pid = my_itoa(shell->shell_pid);
	else
		pid = my_itoa(shell->last_exit_status);
	line = NULL;
	line = (char *)my_calloc(1, ft_strlen(src) + ft_strlen(pid) - 1);
	ft_strncpy(line, src, i);
	ft_strncpy(line, pid, (int)ft_strlen(pid));
	ft_strncpy(line, &src[cnt], ft_strlen(&src[cnt]));
	free(pid);
	return (line);
}

char	*doc_envp(t_minishell *shell, char *src)
{
	char	*line;
	int		cnt;
	int		i;

	i = 0;
	line = NULL;
	while (src[i] && src[i] != '$' && src[i] != '\n')
		i++;
	cnt = i + 1;
	if (!src[i] || src[i] == '\n')
		return (NULL);
	if (src[cnt] == '$' || src[cnt] == '?')
		line = ft_double(shell, src, i);
	while (ft_isalpha(src[cnt]) || ft_isdigit(src[cnt]))
		cnt++;
	if (!line)
		line = doc_switch(shell, src, i, cnt);
	if (!line)
		line = empty_env_switch(shell, src, i, cnt);
	free(src);
	return (line);
}
