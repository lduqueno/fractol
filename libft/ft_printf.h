/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegan <rlegan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:22:33 by rlegan            #+#    #+#             */
/*   Updated: 2019/01/29 21:56:20 by rlegan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

# define F_HASH 0
# define F_ZERO 1
# define F_LESS 2
# define F_PLUS 3
# define F_SPACE 4
# define F_PCS 5
# define F_WIDTH 6
# define F_HH 7
# define F_H 8
# define F_L 9
# define F_LL 10
# define F_LMAJ 11

# define HEX 16
# define OCTAL 8
# define TNY 0
# define MAJS 1

# define PF_BF_SZ 4096

typedef struct		s_infzero
{
	unsigned long long	fraction:52;
	unsigned short		exponent:11;
	unsigned char		sign:1;
}					t_infozero;

typedef union		u_zeroinf
{
	double				nb;
	t_infozero			s;
}					t_zeroinf;

typedef struct		s_fonc
{
	char			c;
	void			(*ptr)();
}					t_fonc;

typedef struct		s_arg
{
	size_t			len;
	int				flag[12];
	va_list			ap;
	char			buff[PF_BF_SZ];
	size_t			buff_index;
	const char		*format;
	int				width;
	int				pcs;
	size_t			f_idx;
	size_t			maj;
	int				stop;
	int				start;
	t_fonc			f[13];
	int				printed;
	int				skip;
	int				fd;
}					t_arg;

int					ft_printf(const char *format, ...);
void				ptf_putchar(char c, t_arg *p);
int					ptf_putstr(char *str, t_arg *p, size_t len);
int					ptf_putnbr_base(unsigned long long int nb, int b, t_arg *p);
int					ptf_check(t_arg *p);
int					ptf_parser(t_arg *p);
void				ptf_handle_c(t_arg *p);
void				ptf_handle_s(t_arg *p);
void				ptf_handle_di(t_arg *p);
void				ptf_handle_o(t_arg *p);
void				ptf_handle_xx(t_arg *p);
void				ptf_handle_p(t_arg *p);
void				ptf_handle_b(t_arg *p);
void				ptf_handle_pourcent(t_arg *p);
void				ptf_flagspacezero(t_arg *p, int len);
void				ptf_flagspacezerodi(t_arg *p, int len);
int					ptf_putchar_repeat(char c, t_arg *p, int repeat);
void				ptf_flagwbase(t_arg *p, int base, char *tmp,
				unsigned long long int nb);
void				ptf_handle_flagwithbaseless(t_arg *p, int base, char *tmp);
void				ptf_buffdisplay(t_arg *p);
void				ptf_print_f(t_arg *p, long double nb);
void				ptf_handle_u(t_arg *p);
void				ptf_putnbr_di(long long nb, t_arg *p);
int					ft_dprintf(int fd, const char *format, ...);
int					ft_sprintf(char *str, const char *format, ...);
int					ft_snprintf(char *s, size_t sz, const char *format, ...);
void				ptf_handle_f(t_arg *p);
int					ptf_putstr_wf(char *str, t_arg *p);
void				ptf_doubleflag(t_arg *p);
void				ptf_sign(t_arg *p, long double *n, int *sign);
int					ptf_float_inf(t_arg *p, double nb);
int					ptf_float(t_arg *p);
#endif
