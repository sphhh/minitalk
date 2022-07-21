/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:40:09 by vipereir          #+#    #+#             */
/*   Updated: 2022/07/21 17:52:36 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "./ft_printf/ft_printf.h"
#include "./libft/libft.h"
#include <signal.h>

void sig_handler(int signum);

char	bit;

int	main(void)
{
	int		i;
	int		pid;
	char	byte[9];

	byte[8] = '\0';
	i = 0;
	signal(SIGUSR1, *sig_handler);
	signal(SIGUSR2, *sig_handler);
	pid = getpid();
	ft_printf("pid: %i\n", pid);
	while (1)
	{
		i = 0;
		while (i < 8)
		{
			pause();
			byte[i] = bit;
			i++;
		}
		ft_printf("%s", byte);
	}
	return (0);
}

void sig_handler(int signum)
{
	if (signum == SIGUSR1)
		bit = '1';
	else if (signum == SIGUSR2)
		bit = '0';
	return ;
}
