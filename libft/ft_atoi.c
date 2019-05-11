/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <rlegan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:48:18 by rlegan            #+#    #+#             */
/*   Updated: 2019/04/01 16:25:08 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	unsigned int	ret;
	int				neg;

	ret = 0;
	neg = 1;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n' || *nptr == '\v'
			|| *nptr == '\f' || *nptr == '\r')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		neg = (*(nptr++) == '-') ? -1 : 1;
	while (*nptr >= '0' && *nptr <= '9')
	{
		ret = ret * 10 + *nptr - '0';
		nptr++;
	}
	if (ret > 2147483647 && neg == 1)
		return (-2147483648 + ret - 2147483647 - 1);
	if (ret > 2147483648 && neg == -1)
		return (2147483647 - ret + -2147483648 + 1);
	return (ret * neg);
}
