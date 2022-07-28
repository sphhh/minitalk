/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:23:36 by vipereir          #+#    #+#             */
/*   Updated: 2022/07/28 14:36:34 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "./ft_printf/ft_printf.h"
#include "./libft/libft.h"
#include <signal.h>

void	sig_handler(int signum)
{
	if (signum == SIGUSR1)
		return ;
	else if (signum == SIGUSR2)
		write(1, "Received\n", 9);
	return ;
}

int	*ft_chartobin(int pid, int c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		pause();
		usleep(250);
		i--;
	}
	return (0);
}

int	ft_check(int argc, char *pid_check)
{
	if (argc == 1)
	{
		ft_printf("You forgot the server PID!\n");
		return (0);
	}
	else if (argc == 2)
	{
		ft_printf("You forgot the MESSAGE!\n");
		return (0);
	}
	while (*pid_check)
	{
		if (ft_isdigit(*pid_check) == 0)
		{
			ft_printf("The PID should only have DIGITS!\n");
			return (0);
		}
		pid_check++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	pid_t				serv_pid;
	char				*pid_check;
	struct sigaction	action;

	action.sa_handler = (void *)sig_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	if (ft_check(argc, argv[1]) == 0)
		return (0);
	signal(SIGUSR1, *sig_handler);
	pid_check = argv[1];
	serv_pid = ft_atoi(argv[1]);
	while (*argv[2])
		ft_chartobin(serv_pid, *argv[2]++);
	if (*argv[2] == '\0')
		ft_chartobin(serv_pid, *argv[2]);
	return (0);
}
