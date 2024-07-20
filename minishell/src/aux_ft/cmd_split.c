/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu     <nunnu@student.42kocaeli.c>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:25:37 by nunnu             #+#    #+#             */
/*   Updated: 2024/05/15 18:13:32 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include <sys/_types/_null.h>

char	**split_cmd(const char *s, char *delim)
{
	char	**tab;
	int		i;

	i = -1;
	tab = split_input(s, delim);
	if (!tab)
		return (NULL);
	while (tab[++i])
		tab[i] = strip_quotes(tab[i]);
	return (tab);
}
