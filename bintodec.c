/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bintodec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:24:35 by vipereir          #+#    #+#             */
/*   Updated: 2022/07/26 16:48:35 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	static int	byte;
	char		*str;
	int static	i;

		str = "0000000101000010";
//	byte = byte | 1;
//	byte = byte << 1;
	printf("%i\n", byte);
	while (*str)
	{
		if (*str == '1')
		{
			byte = byte << 1;
			byte = byte | 1;
			i++;
		}
		else if (*str == '0')
		{
			byte = byte << 1;
			i++;
		}
		str++;
		if (i == 8)
		{
			i = 0;
			printf("%i\n", byte);
			byte = 0;
		}
	}
	return (0);
}
