/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_handle1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <rlegan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:50:50 by rlegan            #+#    #+#             */
/*   Updated: 2019/01/27 15:48:29 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ptf_handle_c(t_arg *p)
{
	char	c;

	c = va_arg(p->ap, int);
	if (p->flag[F_WIDTH] && p->flag[F_LESS] == 0)
		ptf_putchar_repeat((p->flag[F_ZERO] ? '0' : ' '), p, p->width - 1);
	ptf_putchar(c, p);
	if (p->flag[F_WIDTH] && p->flag[F_LESS] == 1)
		ptf_putchar_repeat((p->flag[F_ZERO] ? '0' : ' '), p, p->width - 1);
}

void			ptf_handle_s(t_arg *p)
{
	char	*str;

	str = va_arg(p->ap, char *);
	if (str)
		ptf_putstr(str, p, (p->pcs == -1 ? ft_strlen(str) : p->pcs));
	else if (!str)
		ptf_putstr("(null)", p, (p->pcs == -1 ? 6 : p->pcs));
}

void			ptf_handle_b(t_arg *p)
{
	unsigned long long int	nb;
	size_t					len;

	len = (p->pcs == -1 ? PF_BF_SZ * 100 : p->pcs);
	nb = (unsigned long long int)va_arg(p->ap, unsigned long long int);
	ptf_putnbr_base(nb, 2, p);
}

static void		ptf_handle_dinext(t_arg *p)
{
	long long nb2;

	nb2 = (long long)va_arg(p->ap, int);
	ptf_putnbr_di((long long)nb2, p);
}

void			ptf_handle_di(t_arg *p)
{
	unsigned long long int	nb;
	long long				nb2;

	if (p->flag[F_LL])
	{
		nb = (long long int)va_arg(p->ap, long long int);
		ptf_putnbr_di(nb, p);
	}
	else if (p->flag[F_L])
	{
		nb = (long int)va_arg(p->ap, long int);
		ptf_putnbr_di((long long)nb, p);
	}
	else if (p->flag[F_HH])
	{
		nb2 = (signed char)va_arg(p->ap, int);
		ptf_putnbr_di(nb2, p);
	}
	else if (p->flag[F_H])
	{
		nb2 = (short)va_arg(p->ap, int);
		ptf_putnbr_di(nb2, p);
	}
	else
		ptf_handle_dinext(p);
}
