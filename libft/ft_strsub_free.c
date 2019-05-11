/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <rlegan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:48:18 by rlegan            #+#    #+#             */
/*   Updated: 2019/04/17 11:38:29 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub_free(char *s, unsigned int start, size_t len)
{
	char	*result;

	if (s)
	{
		if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		{
			free(s);
			return (NULL);
		}
		if (len == 0)
		{
			free(s);
			ft_bzero(result, len + 1);
			return (result);
		}
		ft_strncpy(result, &s[start], len);
		result[len] = '\0';
		free(s);
		return (result);
	}
	return (NULL);
}
