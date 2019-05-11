/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_handle2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <rlegan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 15:42:42 by rlegan            #+#    #+#             */
/*   Updated: 2019/01/29 23:54:07 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ptf_handle_f(t_arg *p)
{
	ptf_float(p);
}

void		ptf_handle_pourcent(t_arg *p)
{
	if (p->flag[F_WIDTH] && p->flag[F_LESS] == 0)
		ptf_putchar_repeat((p->flag[F_ZERO] ? '0' : ' '), p, p->width - 1);
	ptf_putchar('%', p);
	if (p->flag[F_WIDTH] && p->flag[F_LESS] == 1)
		ptf_putchar_repeat((p->flag[F_ZERO] ? '0' : ' '), p, p->width - 1);
}

void		ptf_flagspacezero(t_arg *p, int len)
{
	if (p->width > 0 && p->width > len)
		ptf_putchar_repeat((p->flag[F_ZERO] ? '0' : ' '), p, p->width - len);
}

void		ptf_flagspacezerodi(t_arg *p, int len)
{
	if (p->flag[F_WIDTH] && p->flag[F_PCS])
		ptf_putchar_repeat(' ', p, p->width - p->pcs);
	if (p->flag[F_PCS])
		ptf_putchar_repeat((p->flag[F_ZERO] ? '0' : ' '), p, p->pcs - len);
	ptf_flagspacezero(p, (p->flag[F_WIDTH] ? p->width : len));
}

void		ptf_handle_flagwithbaseless(t_arg *p, int base, char *tmp)
{
	size_t len;

	len = ft_strlen(tmp);
	if (p->flag[F_LESS] == 1 && base == 8)
		if (p->width > 0 && p->width > (int)len)
			ptf_putchar_repeat(' ', p, p->width - len);
	if (p->flag[F_LESS] == 1 && base == 16)
		ptf_flagspacezero(p, len);
}
