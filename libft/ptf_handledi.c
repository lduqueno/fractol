/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_handledi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <rlegan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:06:02 by rlegan            #+#    #+#             */
/*   Updated: 2019/04/01 16:03:48 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ptf_pcswidthspecial(t_arg *p, long long nb, size_t lentmp)
{
	int plus;

	plus = (p->flag[F_PLUS] || p->flag[F_SPACE] ? 1 : 0);
	if (nb < 0 && p->flag[F_ZERO] && !p->flag[F_WIDTH])
	{
		ptf_putchar('-', p);
		p->skip = 1;
		ptf_flagspacezero(p, (p->pcs + plus));
	}
	else if (p->flag[F_LESS] == 0 && p->pcs != -2)
	{
		if (nb < 0)
			p->pcs++;
		ptf_flagspacezerodi(p, (p->flag[F_PCS] ? p->pcs + plus : lentmp));
		if (nb < 0)
			p->pcs--;
	}
	else if (nb != 0 && p->pcs != -2)
		ptf_flagspacezero(p, (p->flag[F_PCS] ? p->pcs + plus : lentmp));
	else if (p->flag[F_PCS] && p->pcs == -2)
		ptf_flagspacezero(p, p->pcs + 2);
}

static void		ptf_flagdinext(t_arg *p, long long nb, size_t l, int plus)
{
	if (nb >= 0 && p->flag[F_WIDTH] && p->flag[F_PLUS] && p->flag[F_ZERO])
		ptf_putchar('+', p);
	if (p->pcs == -2 && p->flag[F_WIDTH])
		ptf_flagspacezero(p, p->pcs + 2);
	else
		ptf_flagspacezero(p, (p->flag[F_PCS] ? p->pcs + plus : l - plus));
}

static void		ptf_flagdi(t_arg *p, size_t l, long long nb, char *tmp)
{
	int plus;

	plus = (p->flag[F_PLUS] || p->flag[F_SPACE] ? 1 : 0);
	if (p->flag[F_PLUS] && p->flag[F_WIDTH] && nb >= 0)
		p->width--;
	if (nb < 0 && p->flag[F_ZERO] && p->flag[F_WIDTH]
		&& ((p->flag[F_PCS] == 0) || p->pcs - p->width == -1))
	{
		ptf_putchar('-', p);
		p->skip = 1;
		tmp[0] = '0';
		ptf_flagspacezero(p, (p->flag[F_PCS] ? p->pcs
			+ plus : l) - (p->flag[F_PLUS] && p->flag[F_PCS] == 0 ? 1 : 0));
	}
	else if (p->flag[F_WIDTH] && p->flag[F_PCS] && p->width > p->pcs)
	{
		if (nb >= 0 && p->flag[F_WIDTH] && p->flag[F_PLUS] && !(p->flag[F_PCS]))
			ptf_putchar('+', p);
		ptf_pcswidthspecial(p, nb, l);
		if (nb >= 0 && p->flag[F_PLUS] && p->flag[F_PCS] && p->flag[F_ZERO])
			ptf_putchar('+', p);
	}
	else
		ptf_flagdinext(p, nb, l, plus);
}

static void		ptf_handleplusspace(long long nb, t_arg *p, char *tmp, int *i)
{
	if (p->flag[F_PLUS] || p->flag[F_SPACE])
	{
		if (nb >= 0 && p->flag[F_SPACE] == 0 && p->flag[F_WIDTH] == 1
			&& p->flag[F_ZERO] == 0)
			ptf_putchar('+', p);
		else if (nb >= 0 && p->flag[F_WIDTH] == 0 && p->flag[F_PLUS])
			ptf_putchar('+', p);
		else if (nb >= 0 && p->flag[F_WIDTH] == 0 && p->flag[F_SPACE])
			ptf_putchar(' ', p);
	}
	if (p->flag[F_PCS] && (int)ft_strlen(tmp) < p->pcs)
	{
		if (nb < 0)
		{
			p->skip = 1;
			ptf_putchar('-', p);
			ptf_putchar_repeat('0', p, (p->pcs - ft_strlen(tmp)) + 1);
		}
		else
			ptf_putchar_repeat('0', p, (p->pcs - ft_strlen(tmp)));
	}
	if (p->skip)
		(*i)++;
}

void			ptf_putnbr_di(long long nb, t_arg *p)
{
	char	*tmp;
	int		i;
	int		plus;

	plus = (p->flag[F_PLUS] || p->flag[F_SPACE] ? 1 : 0);
	i = -1;
	tmp = ft_ltoa(nb);
	if (p->flag[F_LESS] == 0)
		ptf_flagdi(p, ft_strlen(tmp) + plus, nb, tmp);
	if (plus && p->flag[F_WIDTH] && !(p->flag[F_PCS]) && !(p->flag[F_ZERO]))
		if (nb >= 0)
		{
			if (!(p->flag[F_WIDTH] == 1 && p->flag[F_SPACE]))
				ptf_putchar(p->flag[F_PLUS] == 1 ? '+' : ' ', p);
			p->flag[F_PLUS] = 0;
		}
	ptf_handleplusspace(nb, p, tmp, &i);
	while (tmp[++i] && !(p->pcs == -2 && nb == 0))
		ptf_putchar(tmp[i], p);
	if (p->flag[F_LESS] == 1)
		ptf_flagspacezero(p, (p->flag[F_PCS] ? p->pcs : ft_strlen(tmp)) + plus);
	free(tmp);
}
