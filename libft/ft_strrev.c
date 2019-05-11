/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 14:48:59 by rlegan            #+#    #+#             */
/*   Updated: 2018/11/18 14:49:00 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *str)
{
	int	count;
	int	i;

	count = ft_strlen(str);
	i = 0;
	while (i < count / 2)
	{
		ft_swap(&(str[i]), &(str[count - i - 1]));
		i++;
	}
	str[count] = '\0';
	return (&(*str));
}
