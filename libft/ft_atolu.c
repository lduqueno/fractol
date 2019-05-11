/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atolu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <rlegan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:48:18 by rlegan            #+#    #+#             */
/*   Updated: 2019/04/03 11:01:33 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_atolu(const char *nptr)
{
	unsigned long	ret;

	ret = 0;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n' || *nptr == '\v'
			|| *nptr == '\f' || *nptr == '\r' || *nptr == '+')
		nptr++;
	if (*nptr == '-')
		return (0);
	while (*nptr >= '0' && *nptr <= '9')
	{
		ret = ret * 10 + *nptr - '0';
		nptr++;
	}
	return (ret);
}
