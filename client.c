/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:23:36 by vipereir          #+#    #+#             */
/*   Updated: 2022/07/21 14:37:38 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "./ft_printf/ft_printf.h"
#include "./libft/libft.h"
#include <signal.h> 
#include <stdlib.h>

char *conversor(int c)
{
	int		i;
	int		j;
	char	*bin;

	bin = malloc(sizeof(char) * 9);
	bin[8] = '\0';

	j = 0;
	i = 7;
	while (i >= 0)
	{
		bin[j] = ((c & (1 << i)) ? '1' : '0');
		i--;
		j++;
	}
	return(bin);
}

int	main(int argc, char **argv)
{
	int		serv_pid;
	char	*mesg;

	if (argc == 0)
		return(0);
	(void) argc;
	serv_pid = ft_atoi(argv[1]);
	mesg = argv[2];
	printf("%s\n", argv[2]);
	while (*argv[2])
		ft_printf("%s", conversor(*argv[2]++));
	return (0);
}


