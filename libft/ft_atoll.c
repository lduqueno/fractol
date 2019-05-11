/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <rlegan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:48:18 by rlegan            #+#    #+#             */
/*   Updated: 2019/04/01 16:01:34 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(const char *nptr)
{
	long long		ret;
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
	return (ret * neg);
}
