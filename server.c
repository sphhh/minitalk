/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:40:09 by vipereir          #+#    #+#             */
/*   Updated: 2022/07/23 21:29:26 by sphh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "./ft_printf/ft_printf.h"
#include "./libft/libft.h"
#include <signal.h>

void sig_handler(int signum);
int	bin_to_dec(const char *bin);
char	*bin_to_dec_str(const char *bin);

int	main(void)
{
	int		pid;
//	struct	sigaction act;

	//o plano é criar a struct, para pegar o pid e dps modificar ela para printar;

	signal(SIGUSR1, *sig_handler);
	signal(SIGUSR2, *sig_handler);
	pid = getpid();
	ft_printf("pid: %i\n", pid);

	//primeiro ler o pid do client
//	while(1)
//		pause()
	//dps printar a msg;
	while (1)
		pause();
	return (0);
}

void sig_handler(int signum)
{
	static char	byte[9];
	static int	i;
	static int	key;
	static char	*client_pid;

	byte[8] = '\0';
	if (!client_pid)
		client_pid = ft_strdup("\0");
	if (signum == SIGUSR1)
		byte[i++] = '1';
	else if (signum == SIGUSR2)
		byte[i++] = '0';
	if (i == 8 && key == 1)
	{
		i = 0;	
		ft_putchar_fd(bin_to_dec(byte), 1);
	}
	else if (i == 8 && key == 0)
	{
		i = 0;
		if (bin_to_dec(byte) == '$')
		{
			key = 1;
			kill(ft_atoi(client_pid), SIGUSR1);
			return ;
		}
		client_pid = ft_strjoin(client_pid, bin_to_dec_str(byte));
	}
	return ;
}

char	*bin_to_dec_str(const char *bin)
{
	int	dec;
	int	i;
	int	rem;
	int	pow;
	char	*str;

	str = malloc(sizeof(char) * 2);
	str[1] = '\0';
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
	str[0] = dec;
	return (str);
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
