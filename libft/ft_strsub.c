/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:48:18 by rlegan            #+#    #+#             */
/*   Updated: 2018/11/08 10:57:30 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;

	if (s)
	{
		if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		if (len == 0)
		{
			ft_bzero(result, len + 1);
			return (result);
		}
		ft_strncpy(result, &s[start], len);
		result[len] = '\0';
		return (result);
	}
	return (NULL);
}
