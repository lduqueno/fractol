/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <rlegan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:43:41 by rlegan            #+#    #+#             */
/*   Updated: 2019/06/05 17:49:52 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char	*result;
	int		count;

	if (s1 && s2)
	{
		count = ft_strlen(s1) + ft_strlen(s2);
		if (!(result = (char *)malloc(sizeof(char) * count + 1)))
		{
			free((char *)s1);
			return (NULL);
		}
		ft_strcpy(result, s1);
		ft_strcat(result, s2);
		free((char *)s1);
		return (result);
	}
	if (!s1)
		return ((char *)s2);
	return ((char *)s1);
}
