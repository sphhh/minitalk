/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:40:09 by vipereir          #+#    #+#             */
/*   Updated: 2022/08/03 11:57:35 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "./libft/libft.h"
#include <signal.h>

void	sig_handler(int signum, siginfo_t *info);
int		ft_bin_to_dec(const char *bin);

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	action.sa_handler = (void *)sig_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	pid = getpid();
	ft_printf("pid: %i\n", pid);
	while (1)
		pause();
	return (0);
}

void	sig_handler(int signum, siginfo_t *info)
{
	static int	byte;
	static int	i;

	if (signum == SIGUSR2 || signum == SIGUSR1)
		byte <<= 1;
	if (signum == SIGUSR1)
		byte |= 1;
	i++;
	if (i == 8)
	{
		write(1, &byte, 1);
		if (byte == 0)
			kill(info->si_pid, SIGUSR2);
		i = 0;
		byte = 0;
	}
	usleep(200);
	kill(info->si_pid, SIGUSR1);
	return ;
}
