/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_handle_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <rlegan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:40:00 by rlegan            #+#    #+#             */
/*   Updated: 2019/04/01 16:05:22 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ptf_cntnbsz(unsigned long long int nb)
{
	int i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static int			ptf_sizezerofloat(long double nb, t_arg *p)
{
	int count;

	count = 0;
	if (nb < 0)
	{
		count++;
		nb = -nb;
	}
	count += ptf_cntnbsz(nb);
	if (p->pcs == -2)
	{
		if (p->flag[F_HASH])
			count++;
	}
	else if (p->pcs > 0)
		count += p->pcs + 1;
	else
		count += 7;
	return (count);
}

static long double	ptf_preci_prob(long double *nb, t_arg *p)
{
	int			i;
	long double	result;
	int			prec;
	char		*tmp;

	i = 0;
	result = 0.5;
	if (p->flag[F_PCS])
		prec = (p->pcs == -2 ? 1 : p->pcs);
	else
		prec = 6;
	while (i < prec)
	{
		result /= 10;
		i++;
	}
	i = -1;
	(*nb) += result;
	tmp = ft_ltoa_base((*nb), 10, p->maj);
	while (tmp[++i])
		ptf_putchar(tmp[i], p);
	free(tmp);
	return (*nb);
}

void				ptf_float_decimals(t_arg *p, long double n, int *count)
{
	int		i;
	char	*tmp;

	i = -1;
	if (p->pcs != -2)
		ptf_putchar('.', p);
	while (n > 0 && ++(*count) < (p->pcs == -1 ? 6 : p->pcs))
	{
		n = (long double)((long double)n - (unsigned long long int)n) * 10;
		tmp = ft_ltoa_base((unsigned long long int)n, 10, p->maj);
		i = -1;
		while (tmp[++i])
			ptf_putchar(tmp[i], p);
		free(tmp);
	}
	if (p->pcs == -2 && p->flag[F_HASH])
		ptf_putchar('.', p);
}

void				ptf_print_f(t_arg *p, long double nb)
{
	int			count;
	int			i;
	int			sign;

	count = -1;
	i = -1;
	sign = 0;
	if (p->flag[F_PLUS] && p->flag[F_WIDTH])
		ptf_sign(p, &nb, &sign);
	if (nb < 0 && p->flag[F_WIDTH] && p->flag[F_SPACE] == 0)
		ptf_sign(p, &nb, &sign);
	if (!p->flag[F_LESS])
		ptf_flagspacezero(p, ptf_sizezerofloat(nb, p) + sign);
	if (p->flag[F_PLUS] && sign == 0)
		ptf_sign(p, &nb, &sign);
	if (nb < 0)
		ptf_sign(p, &nb, &sign);
	nb = ptf_preci_prob(&nb, p);
	ptf_float_decimals(p, nb, &count);
	if (p->flag[F_LESS])
		ptf_flagspacezero(p, (p->flag[F_PCS]
			? p->pcs : ptf_sizezerofloat(nb, p)));
	if (count < 6 || (count < p->pcs && p->flag[F_PCS]))
		ptf_putchar_repeat('0', p, (p->flag[F_PCS]
			? p->pcs - count - 1 : 5 - count));
}
