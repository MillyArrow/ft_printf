/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 20:35:53 by marrow            #+#    #+#             */
/*   Updated: 2020/05/09 17:09:09 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/includes/libft.h"
# include <limits.h>

# define black		"\e[00;30m"
# define red		"\e[00;31m"
# define green		"\e[00;32m"
# define yellow		"\e[01;33m"
# define blue		"\e[00;34m"
# define purple		"\e[00;35m"
# define cyan		"\e[00;36m"
# define white		"\e[01;37m"
# define eoc		"\e[m"

typedef struct		s_spec
{
	char			flag[5];
	size_t			width;
	int				accuracy;
	char			length[3];
	char			type;
	char			minus;
	int				iszero;
	size_t			len;
	size_t			len_f;
	int				inf_nan;
	int				plus;
	__uint128_t		int_part;
	size_t			l_int_part;
	char			chk;
	char			color[8];
}					t_spec;
void				ft_putch(char c, t_spec *spec);
void				initialization(t_spec *specifier);
void				ft_putstrs(char const *s, t_spec *spec);
int					ft_dota(va_list parameters,\
const char		*restrict format);
int					ft_printf(const char *restrict format, ...);
void				ft_type(t_spec *specifier, va_list args);
t_spec				*ft_format_specifier(char *str, size_t *i,\
					t_spec *specifier);
void				ft_set_flag(char *str, size_t *i, t_spec *specifier);
void				ft_set_width(char *str, size_t *i, t_spec *specifier);
void				ft_set_accuracy(char *str, size_t *i, t_spec *specifier);
void				ft_set_length(char *str, size_t *i, \
					t_spec *specifier);
void				display_base_big(unsigned long long value,\
					int base, t_spec *spec);
int					check_for_x(unsigned long long number,\
					int length, t_spec *specifier);
void				ft_x(t_spec *specifier, va_list args);
int					check_for_big_x(unsigned long long number,\
					int length, t_spec *specifier);
void				ft_big_x(t_spec *specifier, va_list args);
int					print_str(t_spec *specifier, size_t *i, \
					size_t *len, char **length);
void				ft_s(t_spec *specifier, va_list args);
void				ft_c(t_spec *specifaer, va_list args);
__int64_t			get_number(t_spec *specifier, va_list args);
void				ft_putnbrs(__int64_t n, int base, t_spec *spec);
void				ft_accuracy(t_spec *specifier, int length);
void				display_d(t_spec *specifier, __int64_t *number, \
					int *length);
void				ft_d(t_spec *specifier, va_list args);
size_t				ft_l_num(long double number);
void				div_digit(t_spec *specifier, long double *number,\
					__uint128_t *t_number, char *check);
int					inf_nan(long double *number, t_spec *specifier);
long	double		ft_real_part(t_spec *specifier, long double number);
void				ft_round(t_spec *specifier, long double number);
void				ft_f_precision(t_spec *specifier, long double number);
void				ft_putnbr_f(t_spec *specifier, long double number, \
					size_t int_part);
void				display_f(t_spec *specifier, long double number, \
					size_t int_part);
int					display_minus_f(t_spec *specifier, long double number,\
					size_t int_part);
void				ft_f(t_spec *specifier, va_list args);
unsigned long long	get_number_u(t_spec *specifier, va_list args);
void				display_base(unsigned long long value, \
					int base, t_spec *spec);
int					ft_number_length_u(unsigned long long number, int base);
int					check_for_o(unsigned long long number, \
					int length, t_spec *specifier);
void				ft_o(t_spec *specifier, va_list args);
void				display_u(t_spec *specifier, \
					unsigned long long *number, int *length);
void				ft_putnbrs_u(unsigned long long n, \
					unsigned long long base, t_spec *spec);
void				ft_u(t_spec *specifier, va_list args);
int					check_for_p(unsigned long long number, \
					int length, t_spec *specifier);
void				ft_p(t_spec *specifier, va_list args);
void				ft_width_pct(t_spec *specifier, int length);
void				ft_pct(t_spec *specifier);
void				ft_len_width(t_spec *specifier, int *length, int *tmp);
void				print_width(t_spec *specifier, int *length, int *check);
void				ft_width(t_spec *specifier, int length);
void				print_width_f(t_spec *specifier);
void				ft_width_f(t_spec *specifier);
void				ft_e(t_spec *specifier, va_list args);
int     			ft_setcolor(char *str, size_t *i, t_spec *specifier);
#endif
