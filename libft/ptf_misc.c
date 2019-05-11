/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_misc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <rlegan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 21:58:46 by rlegan            #+#    #+#             */
/*   Updated: 2019/01/09 02:34:37 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ptf_buffdisplay(t_arg *p)
{
	ft_putnstr_fd(p->buff, p->buff_index, p->fd);
	ft_bzero(p->buff, PF_BF_SZ);
	p->buff_index = 0;
}

void		ptf_doubleflag(t_arg *p)
{
	if (p->flag[F_H] && p->flag[F_L])
	{
		p->flag[F_H] = 0;
		p->flag[F_L] = 0;
	}
	if (p->flag[F_HH] && p->flag[F_LL])
	{
		p->flag[F_HH] = 0;
		p->flag[F_LL] = 0;
	}
	if (p->flag[F_H] && p->flag[F_LL])
	{
		p->flag[F_H] = 0;
		p->flag[F_LL] = 0;
	}
	if (p->flag[F_HH] && p->flag[F_L])
	{
		p->flag[F_HH] = 0;
		p->flag[F_L] = 0;
	}
	if (p->flag[F_LMAJ] && p->flag[F_L])
	{
		p->flag[F_LMAJ] = 0;
		p->flag[F_L] = 0;
	}
}
