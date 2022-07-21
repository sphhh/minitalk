/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:40:09 by vipereir          #+#    #+#             */
/*   Updated: 2022/07/21 19:20:47 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "./ft_printf/ft_printf.h"
#include "./libft/libft.h"
#include <signal.h>

void sig_handler(int signum);
int	bin_to_dec(const char *bin);

char	bit;

int	main(void)
{
	int		i;
	int		pid;
	char	*byte;


	i = 0;
	signal(SIGUSR1, *sig_handler);
	signal(SIGUSR2, *sig_handler);
	pid = getpid();
	ft_printf("pid: %i\n", pid);
	while (1)
	{
		byte = malloc(sizeof(char) * 9);
		byte[8] = '\0';
		i = 0;
		while (i < 8)
		{
			pause();
			byte[i] = bit;
			i++;
		}
		ft_putchar_fd(bin_to_dec(byte), 1);
		free(byte);
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

int	bin_to_dec(const char *bin)
{
	int	dec;
	int	i;
	int	rem;
	int	pow;

	pow = 1;
	rem = 0;
	dec = 0;
	i = 7;
	while (i >= 0)
	{
		rem = bin[i] - 48;
		dec = dec + rem * pow;
		pow = pow * 2;
		i--;
	}
	return (dec);
}
