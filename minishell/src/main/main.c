/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu     <nunnu@student.42kocaeli.c>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:25:37 by nunnu             #+#    #+#             */
/*   Updated: 2024/05/15 18:13:32 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../inc/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	(void)argv;
	if (envp[0] == NULL)
	{
		envp[0] = "SHLVL=1";
		envp[1] = "_=/usr/bin/env";
		envp[2] = NULL;
	}
	if (argc == 1)
		minishell(envp);
	else
	{
		printf("\033[31;1m");
		printf("\n\tInput Error: Write only ./minishell\n\n");
		printf("\033[0m");
	}
	return (0);
}
