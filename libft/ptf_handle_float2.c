/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_handle_float2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:29:58 by rlegan            #+#    #+#             */
/*   Updated: 2019/01/30 12:29:58 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ptf_float(t_arg *p)
{
	long double nb;
	double		nb2;
	int			ret;

	if (p->flag[F_LMAJ])
	{
		nb = (long double)va_arg(p->ap, long double);
		ptf_print_f(p, nb);
	}
	else
	{
		nb2 = (double)va_arg(p->ap, double);
		ret = ptf_float_inf(p, nb2);
		if (ret == 3)
			return (0);
		ptf_print_f(p, nb2);
	}
	return (0);
}

void		ptf_sign(t_arg *p, long double *n, int *sign)
{
	if ((*n) > 0)
	{
		ptf_putchar('+', p);
		(*sign) = 1;
		p->flag[F_PLUS] = 0;
	}
	if ((*n) < 0)
	{
		ptf_putchar('-', p);
		(*n) = -(*n);
		(*sign) = 1;
	}
}

static void	ptf_handle_floatinf(t_arg *p, char *tmp, int sign)
{
	int len;

	len = (sign == 4 ? ft_strlen(tmp) : ft_strlen(tmp) + 1);
	if (p->flag[F_PCS] && sign != 4)
		len += p->pcs;
	if (!p->flag[F_LESS])
		ptf_flagspacezero(p, (sign == 4 ? len : len + 6));
	ptf_putstr_wf(tmp, p);
	if (p->pcs != -2 && sign != 4)
	{
		ptf_putchar('.', p);
		ptf_putchar_repeat('0', p, (p->flag[F_PCS] ? p->pcs : 6));
	}
}

int			ptf_float_inf(t_arg *p, double nb)
{
	t_zeroinf	bit;

	bit.nb = nb;
	if (bit.s.exponent == 0x7ff)
	{
		if (bit.s.fraction == 0)
		{
			if (bit.s.sign)
				ptf_handle_floatinf(p, "-inf", 4);
			else
				ptf_handle_floatinf(p, "inf", 4);
		}
		else
			ptf_handle_floatinf(p, "nan", 4);
		return (3);
	}
	else if (bit.s.exponent == 0x000 && bit.s.fraction == 0 && bit.s.sign)
	{
		ptf_handle_floatinf(p, "-0", -1);
		return (3);
	}
	return (0);
}
