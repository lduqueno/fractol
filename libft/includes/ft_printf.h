/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduqueno <lduqueno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:33:17 by lduqueno          #+#    #+#             */
/*   Updated: 2018/12/18 15:33:41 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>

# define FORMAT_COUNT				14
# define FLAG_COUNT					11
# define FLAGS						"hh_h_l_ll_L_#_-_+_._ _0"

struct								s_double_num_struct
{
	unsigned long long				fraction:52;
	unsigned short					exponent:11;
	unsigned char					sign:1;
};

struct								s_l_double_num_struct
{
	__uint128_t						fraction:112;
	unsigned short					exponent:15;
	unsigned char					sign:1;
};

typedef union						u_double_num
{
	double							number;
	struct s_double_num_struct		s;
}									t_double_num;

typedef union						u_l_double_num
{
	long double						number;
	struct s_l_double_num_struct	s;
}									t_l_double_num;

typedef struct						s_output
{
	char							*buffer;
	int								print_count;
}									t_output;

typedef struct						s_context
{
	int								pad_count;
	int								precision;
	int								*flags;
	char							**def_flags;
	va_list							*arg;
}									t_context;

typedef struct						s_type
{
	char							*format;
	char							*(*execute)(va_list ap, t_context *context);
}									t_type;

char								*from_char(va_list ap, t_context *context);
char								*from_str(va_list ap, t_context *context);
char								*from_ptr(va_list ap, t_context *context);
char								*from_int(va_list ap, t_context *context);
char								*from_double(va_list ap,
										t_context *context);
char								*from_uint_to_octal(va_list ap,
										t_context *context);
char								*from_uint_to_uint(va_list ap,
										t_context *context);
char								*from_uint_to_uhex_low(va_list ap,
										t_context *context);
char								*from_uint_to_uhex_upp(va_list ap,
										t_context *context);
char								*from_binary(va_list ap,
										t_context *context);
char								*from_boolean(va_list ap,
										t_context *context);
char								*from_default(va_list ap,
										t_context *context);
char								*append_flags_int(long long int i,
										t_context *context);
char								*append_flags_double(char *r,
										long double i, t_context *c, int neg);
int									has_flag(t_context *context, char *flag);
void								free_context(t_context *context);
int									get_next_number(char *format, int *i,
										t_context *context);
t_context							*make_context(char *format,
										int *start_index, va_list ap);
int									get_flag_index(t_context *context,
										char *flag);
void								handle_flag(char *format, char *flag,
										t_context *context, int *i);
char								*search_next_flag(char **flags,
										const char *format, int *start_index);
char								*ft_ltoa_base(unsigned long int i,
										char *base, int precision, char *arg);
char								*ft_ltoa(long long int n,
										t_context *context, int pre_flag_len);
t_output							*parse_string(const char *format,
										va_list ap);
void								write_to_buf_len(int a_len, int b_len,
										char **buf, const char *arg);
void								write_to_buf(char **buffer,
										const char *to_write);
char								*pad_with_zeros(char *str,
										t_context *context, int str_len);
int									ft_printf(const char *format, ...);
int									ft_sprintf(char *buf,
										const char *format, ...);
int									ft_vprintf(const char *format,
										va_list ap);
int									ft_snprintf(char *buf, size_t size,
	const char *format, ...);
int									ft_vsprintf(char *buf, const char *format,
										va_list ap);
int									ft_vsnprintf(char *buf, size_t size,
										const char *format, va_list ap);
int									ft_dprintf(int fd, const char *format, ...);
int									ft_vdprintf(int fd, const char *format,
										va_list ap);
char								*ft_strncpy_c(char *dest, const char *src,
										size_t size);

#endif
