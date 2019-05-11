/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_digit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <rlegan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:52:37 by lduqueno          #+#    #+#             */
/*   Updated: 2019/03/20 15:13:27 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_digit(const char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	if (str[i] == '\0' && str[0] == '-' && i == 1)
		return (0);
	return (1);
}
