/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:30:38 by vipereir          #+#    #+#             */
/*   Updated: 2022/07/21 18:38:15 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	bin_to_dec(char *bin);

int	main(void)
{
	printf("|%i|\n", bin_to_dec("01100001"));
	return (0);
}

int	bin_to_dec(char *bin)
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
		printf("%i\n", rem);
		dec = dec + rem * pow;
		pow = pow * 2;
		i--;
	}
	return (dec);
}
