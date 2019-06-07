/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 00:01:38 by lduqueno          #+#    #+#             */
/*   Updated: 2018/12/16 13:52:53 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*search_next_flag(char **flags, const char *format, int *s_i)
{
	int		i;
	int		j;
	char	*found;
	char	*sub;

	i = 0;
	found = NULL;
	while (flags[i])
	{
		j = 2;
		while (j > 0)
		{
			if (!(sub = ft_strsub(format, *s_i, j--)))
				continue ;
			found = (ft_strequ(sub, flags[i]) ? flags[i] : found);
			free(sub);
			if (found)
				break ;
		}
		i++;
	}
	return (found);
}

int				get_flag_index(t_context *context, char *flag)
{
	int		i;

	i = 0;
	while (context->def_flags[i])
	{
		if (ft_strequ(flag, context->def_flags[i]))
			return (i);
		i++;
	}
	return (-1);
}

int				has_flag(t_context *context, char *flag)
{
	int		index;

	if (!flag || !context)
		return (0);
	index = get_flag_index(context, flag);
	if (index == -1)
		return (0);
	return (context->flags[index] == 1);
}

void			free_context(t_context *context)
{
	int		i;

	i = 0;
	if (context)
	{
		while (context->def_flags[i])
			free(context->def_flags[i++]);
		free(context->def_flags);
		free(context->flags);
		free(context);
		context = NULL;
	}
}
