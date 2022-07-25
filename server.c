/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:40:09 by vipereir          #+#    #+#             */
/*   Updated: 2022/07/25 16:39:08 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "./ft_printf/ft_printf.h"
#include "./libft/libft.h"
#include <signal.h>

void sig_handler(int signum, siginfo_t *info);
int	bin_to_dec(const char *bin);

int	main(void)
{
	pid_t	pid;
	struct	sigaction action;

	action.sa_handler = (void *)sig_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	pid = getpid();
	ft_printf("pid: %i\n", pid);
	while (1)
		pause();
	return (0);
}

void sig_handler(int signum, siginfo_t *info)
{
	static char	*byte;
	static int	i;

	if(info)
	if (i == 0)
	{
		byte = malloc(sizeof(char) * 9);
		byte[8] = '\0';
	}
	if (signum == SIGUSR1)
		byte[i++] = '1';
	else if (signum == SIGUSR2)
		byte[i++] = '0';
	if (i == 8)
	{
		ft_putchar_fd(bin_to_dec(byte), 1);
		free(byte);
		i = 0;
	}
	usleep(100);
	kill(info->si_pid, SIGUSR1);
	return ;
}

int	bin_to_dec(const char *bin)
{
	int	dec;
	int	i;
	int	pow;

	pow = 1;
	dec = 0;
	i = 7;
	while (i >= 0)
	{
		dec = dec + (bin[i] - 48) * pow;
		pow = pow * 2;
		i--;
	}
	return (dec);
}
