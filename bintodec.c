/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bintodec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:24:35 by vipereir          #+#    #+#             */
/*   Updated: 2022/07/26 16:00:57 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	static int	byte;
	char		*str;

	str = "00000011";
//	byte = byte | 1;
//	byte = byte << 1;
	printf("%i\n", byte);
	while (*str)
	{
		if (*str == '1')
		{
			byte = byte << 1;
			byte = byte | 1;
		}
		else
			byte = byte << 1;
		str++;
	}
	printf("%i\n", byte);
	return (0);
}
