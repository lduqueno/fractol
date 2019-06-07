/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:00:25 by lduqueno          #+#    #+#             */
/*   Updated: 2018/11/06 16:00:27 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t size)
{
	while (*str1 && *str1 == *str2 && size)
	{
		str1++;
		str2++;
		size--;
	}
	return (size == 0 ? 0 : (unsigned char)*str1 - (unsigned char)*str2);
}
