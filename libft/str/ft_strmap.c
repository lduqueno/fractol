/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:40:51 by lduqueno          #+#    #+#             */
/*   Updated: 2018/11/06 18:40:53 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*result;

	i = 0;
	if (!s || !(result = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[i])
	{
		result[i] = (*f)(s[i]);
		i++;
	}
	return (result);
}
