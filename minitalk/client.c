/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:33:21 by nunnu             #+#    #+#             */
/*   Updated: 2023/10/19 17:29:33 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <stdlib.h>

static void	data_transmission(char data, int pid)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (i < 8)
	{
		if (data << i & 0b10000000)
			error = kill(pid, SIGUSR1);
		else
			error = kill(pid, SIGUSR2);
		i++;
		usleep(250);
	}
	if (error == -1)
	{
		ft_putstr("\n\033[31mCLIENT PID error : ");
		ft_putstr("Incorrect PID entered\033[0\n\n");
		exit(1);
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (av[2][i])
			data_transmission(av[2][i++], pid);
	}
	else
	{
		ft_putstr("\n\033[31mCLIENT format error : invalid arguments\033[0m\n");
		ft_putstr("\n\033[33mCorrect format : ./client <PID> <STRING_TO_SEND>");
		ft_putstr("\033[0m\n\n");
	}
}
