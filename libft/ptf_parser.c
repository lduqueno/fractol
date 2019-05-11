/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <rlegan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:22:40 by rlegan            #+#    #+#             */
/*   Updated: 2019/04/01 16:04:49 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ptf_checkifvalid(t_arg *p)
{
	int i;

	i = 0;
	while (p->format[i])
	{
		if (p->format[i] == 'd' || p->format[i] == 'i' || p->format[i] == 'o'
		|| p->format[i] == 'u' || p->format[i] == 'x' || p->format[i] == 'f'
		|| p->format[i] == 'X' || p->format[i] == 'c' || p->format[i] == 's'
		|| p->format[i] == 'p' || p->format[i] == '%' || p->format[i] == 'b')
		{
			p->stop = i;
			return (1);
		}
		i++;
	}
	return (0);
}

static void		ptf_inittabtwo(t_arg *p)
{
	p->f[11].c = 'b';
	p->f[11].ptr = &ptf_handle_b;
	p->f[12].c = 0;
	p->f[12].ptr = NULL;
}

static void		ptf_inittab(t_arg *p)
{
	p->f[0].c = 'd';
	p->f[0].ptr = &ptf_handle_di;
	p->f[1].c = 'i';
	p->f[1].ptr = &ptf_handle_di;
	p->f[2].c = 'o';
	p->f[2].ptr = &ptf_handle_o;
	p->f[3].c = 'u';
	p->f[3].ptr = &ptf_handle_u;
	p->f[4].c = 'x';
	p->f[4].ptr = ptf_handle_xx;
	p->f[5].c = 'X';
	p->f[5].ptr = ptf_handle_xx;
	p->f[6].c = 'c';
	p->f[6].ptr = &ptf_handle_c;
	p->f[7].c = 's';
	p->f[7].ptr = &ptf_handle_s;
	p->f[8].c = 'p';
	p->f[8].ptr = &ptf_handle_p;
	p->f[9].c = 'f';
	p->f[9].ptr = &ptf_handle_f;
	p->f[10].c = '%';
	p->f[10].ptr = &ptf_handle_pourcent;
	ptf_inittabtwo(p);
}

int				ptf_parser(t_arg *p)
{
	int i;

	i = 0;
	if (ptf_checkifvalid(p) == 0)
		return (1);
	if (ptf_check(p) == -1)
		return (1);
	ptf_inittab(p);
	while (p->format[p->f_idx] != p->f[i].c && p->f[i].c != 0)
		i++;
	if (i == 5)
		p->maj = 1;
	p->f[i].ptr(p);
	p->f_idx++;
	return (0);
}
