/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:40:09 by vipereir          #+#    #+#             */
/*   Updated: 2022/07/21 12:15:51 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "./ft_printf/ft_printf.h"
#include "./libft/libft.h"
#include <signal.h>
/*
void sig_handler(int signum)
{
	ft_printf("signum: %i\n", signum);
}

int	main(void)
{
	int	pid;

	signal(SIGUSR1, *sig_handler);
	pid = getpid();
	ft_printf("pid: %i\n", pid);
	pause();
	return (0);
}
*/


static void sig_usr(int); /* o mesmo handler para os 2 sinais */
int main(void)
{
	pid_t	pid;
	pid = getpid();
	ft_printf("pid: %i\n", pid);
	if (signal(SIGUSR1, sig_usr) == SIG_ERR) 
	{
		fprintf(stderr, "can't catch SIGUSR1\n");
		exit(1);
	}
	if (signal(SIGUSR2, sig_usr) == SIG_ERR) 
	{
		fprintf(stderr, "can't catch SIGUSR2\n");
		exit(1);
	}
	for(;;)
		pause();
}
static void sig_usr(int signo) /* o argumento indica o sinal recebido */
{
	if (signo == SIGUSR1)
		printf("received SIGUSR1\n");
	else if (signo == SIGUSR2)
		printf("received SIGUSR2\n");
	else
	{
		fprintf(stderr, "received signal %d\n", signo);
		exit(2);
	}
	return;
}
