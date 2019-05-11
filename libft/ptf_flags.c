/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <rlegan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:51:19 by rlegan            #+#    #+#             */
/*   Updated: 2019/04/01 16:02:57 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ptf_check_flags(t_arg *p)
{
	while (p->format[p->f_idx] == '#' || p->format[p->f_idx] == '0'
		|| p->format[p->f_idx] == '-' || p->format[p->f_idx] == '+'
		|| p->format[p->f_idx] == ' ')
	{
		if (p->format[p->f_idx] == '#')
			p->flag[F_HASH] = 1;
		if (p->format[p->f_idx] == '-')
		{
			p->flag[F_ZERO] = 0;
			p->flag[F_LESS] = 1;
		}
		if (p->format[p->f_idx] == '0' && p->flag[F_LESS] == 0)
			p->flag[F_ZERO] = 1;
		if (p->format[p->f_idx] == '+')
		{
			p->flag[F_SPACE] = 0;
			p->flag[F_PLUS] = 1;
		}
		if (p->format[p->f_idx] == ' ' && p->flag[F_PLUS] == 0)
			p->flag[F_SPACE] = 1;
		p->f_idx++;
	}
}

static void		ptf_check_modifier(t_arg *p)
{
	if (p->format[p->f_idx] == 'h' || p->format[p->f_idx] == 'l'
			|| p->format[p->f_idx] == 'L' || (p->format[p->f_idx] == 'h'
			&& p->format[p->f_idx + 1] == 'h') || (p->format[p->f_idx] == 'l'
			&& p->format[p->f_idx + 1] == 'l'))
	{
		if (p->format[p->f_idx] == 'h' && p->format[p->f_idx + 1] == 'h')
		{
			p->flag[F_HH] = 1;
			p->f_idx++;
		}
		if (p->format[p->f_idx] == 'l' && p->format[p->f_idx + 1] == 'l')
		{
			p->flag[F_LL] = 1;
			p->f_idx++;
		}
		if (p->format[p->f_idx] == 'h')
			p->flag[F_H] = 1;
		if (p->format[p->f_idx] == 'l')
			p->flag[F_L] = 1;
		if (p->format[p->f_idx] == 'L')
			p->flag[F_LMAJ] = 1;
		ptf_doubleflag(p);
		p->f_idx++;
	}
}

static int		ptf_check_width(t_arg *p)
{
	int		i;
	char	*str;

	if (ft_isdigit(p->format[p->f_idx]))
	{
		i = p->f_idx;
		while (ft_isdigit(p->format[p->f_idx]))
			p->f_idx++;
		if (p->f_idx - i > 0)
		{
			p->flag[F_WIDTH] = 1;
			if (!(str = ft_strsub(p->format, i, p->f_idx - i)))
				return (-1);
			p->width = ft_atoi(str);
			if (p->width == 0)
			{
				p->flag[F_ZERO] = 1;
				return (0);
			}
			free(str);
		}
	}
	return (0);
}

static int		ptf_check_precision(t_arg *p)
{
	int		i;
	char	*str;

	if (p->format[p->f_idx] == '.')
	{
		i = p->f_idx + 1;
		p->f_idx++;
		while (ft_isdigit(p->format[p->f_idx]))
			p->f_idx++;
		if (p->f_idx - i > 0)
		{
			p->flag[F_PCS] = 1;
			if (!(str = ft_strsub(p->format, i, p->f_idx - i)))
				return (-1);
			p->pcs = ft_atoi(str);
			if (p->pcs == 0)
				p->pcs = -2;
			free(str);
		}
		else
			p->pcs = -2;
	}
	return (0);
}

int				ptf_check(t_arg *p)
{
	int	stop;

	stop = 0;
	while ((p->format[p->f_idx] == '#' || p->format[p->f_idx] == '0'
		|| p->format[p->f_idx] == '-' || p->format[p->f_idx] == '+'
		|| p->format[p->f_idx] == 'l' || p->format[p->f_idx] == 'h'
		|| (p->format[p->f_idx] == 'h' && p->format[p->f_idx + 1] == 'h')
		|| (p->format[p->f_idx] == 'l' || p->format[p->f_idx + 1] == 'l')
		|| p->format[p->f_idx] == 'L' || ft_isdigit(p->format[p->f_idx])
		|| p->format[p->f_idx] == '.' || p->format[p->f_idx] == ' ')
		&& stop < p->stop)
	{
		ptf_check_flags(p);
		if (ptf_check_width(p) == -1)
			return (-1);
		if (ptf_check_precision(p) == -1)
			return (-1);
		ptf_check_modifier(p);
		stop++;
	}
	return (1);
}
