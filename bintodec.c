/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bintodec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 08:53:24 by vipereir          #+#    #+#             */
/*   Updated: 2022/07/26 10:01:45 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	static int	c;
	static int	i;
	char		*bin;

	bin = "00000001";
	i = 7;
	while(*bin)
	{
		if (*bin == '1')
			c = c | 1 << i;
		i--;
		bin++;
	}
	printf("%i\n", c);
	return (0);
}
