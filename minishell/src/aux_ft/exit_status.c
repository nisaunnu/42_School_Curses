/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu     <nunnu@student.42kocaeli.c>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:25:37 by nunnu             #+#    #+#             */
/*   Updated: 2024/05/15 18:13:32 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../inc/minishell.h"
#include "../../inc/libft/inc/libft.h"

void	exit_status(t_minishell *shell, const char *msg, int status)
{
	if (ft_strchr(msg, '/') != NULL)
		printf("minishell: %s: No such file or directory\n", msg);
	else
		printf("minishell: %s: command not found\n", msg);
	shell->last_exit_status = status;
}
