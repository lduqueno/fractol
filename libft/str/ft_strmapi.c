/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:48:08 by lduqueno          #+#    #+#             */
/*   Updated: 2018/11/06 18:48:09 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	i = 0;
	if (!s || !(result = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[i])
	{
		result[i] = (*f)(i, s[i]);
		i++;
	}
	return (result);
}
