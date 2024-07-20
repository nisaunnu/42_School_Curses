/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu     <nunnu@student.42kocaeli.c>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:25:37 by nunnu             #+#    #+#             */
/*   Updated: 2024/05/15 18:13:32 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../inc/libft/inc/libft.h"

static int	newline_checker(char **cmd_args, int *i)
{
	int	j;
	int	nl_checker;
	int	newline;

	nl_checker = 0;
	newline = 1;
	while (cmd_args[*i] && ft_strncmp(cmd_args[*i], "-n", 2) == 0)
	{
		newline = 0;
		j = 1;
		while (cmd_args[*i][j] != '\0')
		{
			if (cmd_args[*i][j] != 'n')
			{
				if (nl_checker)
					return (0);
				return (1);
			}
			j++;
		}
		(*i)++;
		nl_checker = 1;
	}
	return (newline);
}

void	echo_command(char **cmd_args)
{
	int	newline;
	int	i;

	i = 1;
	newline = newline_checker(cmd_args, &i);
	while (cmd_args[i])
	{
		printf("%s", cmd_args[i]);
		if (cmd_args[i + 1])
			printf(" ");
		i++;
	}
	if (newline)
		printf("\n");
}
