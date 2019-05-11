/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequignorecase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 17:15:47 by lduqueno          #+#    #+#             */
/*   Updated: 2019/05/11 17:24:42 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequignorecase(char *s1, char *s2)
{
	unsigned int i;

	i = 0;
	while (s1[i] != '\0' && ft_tolower(s1[i]) == ft_tolower(s2[i]))
		i++;
	return ((unsigned char)(ft_tolower(s1[i]))
		- (unsigned char)(ft_tolower(s2[i])) == 0);
}
