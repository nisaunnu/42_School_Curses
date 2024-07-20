/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu     <nunnu@student.42kocaeli.c>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:13:14 by nunnu             #+#    #+#             */
/*   Updated: 2024/05/15 18:13:32 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include "../../inc/libft/inc/libft.h"
#include <stdlib.h>

static char	*join_cmd_to_dir(const char *dir, const char *cmd)
{
	char	*full_path;
	size_t	len;

	len = ft_strlen(dir) + ft_strlen(cmd) + 2;
	full_path = (char *)malloc(len);
	if (!full_path)
		return (NULL);
	ft_strlcpy(full_path, dir, len);
	ft_strlcat(full_path, "/", len);
	ft_strlcat(full_path, cmd, len);
	return (full_path);
}

char	*get_path(char *cmd, const char *env_path)
{
	char	**dirs;
	char	*cmd_path;
	int		i;

	i = 0;
	if (cmd[0] == '/' && access(cmd, X_OK) == 0)
		return (my_strdup(cmd));
	if (!env_path)
		return (NULL);
	dirs = ft_split(env_path, ':');
	if (!dirs)
		return (NULL);
	cmd_path = NULL;
	while (dirs[i] && cmd_path == NULL)
	{
		cmd_path = join_cmd_to_dir(dirs[i], cmd);
		if (cmd_path && access(cmd_path, X_OK) == 0)
			break ;
		free (cmd_path);
		cmd_path = NULL;
		i++;
	}
	ft_free_arrays(dirs);
	return (cmd_path);
}
