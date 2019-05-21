/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:21:58 by lduqueno          #+#    #+#             */
/*   Updated: 2019/05/21 14:28:03 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_strreplace(char *str, const char *find, const char *replace)
{
	char	*cursor;
	size_t	find_len;
	size_t	replace_len;
	int		i;

	cursor = str;
	find_len = ft_strlen(find);
	replace_len = ft_strlen(replace);
	while ((cursor = ft_strstr(cursor, find)))
	{
		ft_memmove(cursor + replace_len, cursor + ft_strlen(find),
			ft_strlen(cursor) - ft_strlen(find) + 1);
		i = -1;
		while (replace[++i])
			cursor[i] = replace[i];
		cursor += replace_len;
	}
}
