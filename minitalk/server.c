/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:47:52 by nunnu             #+#    #+#             */
/*   Updated: 2023/10/15 20:20:54 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>

static void	handler(int signal)
{
	static int	i;
	static char	c;

	if (signal == SIGUSR1)
		c = (c << 1) | 1;
	else if (signal == SIGUSR2)
		c = (c << 1);
	i++;
	if (i == 8)
	{
		ft_putchar(c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putstr("\n\033[32mServer started\n\nServer PID : \033[0m");
	ft_putnbr(pid);
	ft_putstr("\n\n");
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
