/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:23:36 by vipereir          #+#    #+#             */
/*   Updated: 2022/07/23 21:23:26 by sphh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "./ft_printf/ft_printf.h"
#include "./libft/libft.h"
#include <signal.h> 
#include <stdlib.h>

void sig_handler(int signum)
{
	if (signum == SIGUSR1)
		return ;
	return ;
}

int *ft_chartobin(int pid, int c)
{
	int		i;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		i--;
	}
	return (0);
}
int *ft_chartobin_pause(int pid, int c)
{
	int		i;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
		{
			kill(pid, SIGUSR1);
			pause();
		}
		else
		{
			kill(pid, SIGUSR2);
			pause();
		}
		usleep(200);
		i--;
		//	usleep(200);
	}
	return (0);
}



int	main(int argc, char **argv)
{
	int		serv_pid;
	char		*pid_check;
	char		*client_pid;

	// coditions check;
	// criar uma ft_check conditions
	signal(SIGUSR1, *sig_handler);
	pid_check = argv[1];	
	if (argc == 1)
	{
		ft_printf("You forgot the server PID!\n");
		return(0);
	}
	else if (argc == 2)
	{
		ft_printf("You forgot the MESSAGE!\n");
	       	return (0);	
	}
	while(*pid_check)	
	{
		if (ft_isdigit(*pid_check) == 0)
		{
			ft_printf("The PID should only have DIGITS!\n");
			return (0);
		}
		pid_check++;
	}	
	client_pid = ft_itoa(getpid());
	ft_printf("%s", client_pid);	
	serv_pid = ft_atoi(argv[1]);
	while(*client_pid)
		ft_chartobin(serv_pid, *client_pid++);
	ft_chartobin(serv_pid, '$');
	while (*argv[2])
		ft_chartobin_pause(serv_pid, *argv[2]++);
	return (0);
}



