#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h> // Delete!
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_args
{
	char			st_char;
	char			*st_string;
	unsigned int	st_pnt;
	int				st_dgt;
	int				st_int;
	unsigned int	st_unsint;
	unsigned int	st_hexxx;
	unsigned int	st_heXXX;
}					t_args;

typedef struct s_flags
{
	int		minus;
	int		plus;
	int		zero;
	int		space;
	int		sharp;
}			t_flags;

typedef struct s_params
{
	t_flags	flags;
	int		width;
	int		precision;
	int		length;
	char	type;
	int		dot;
	int		cnt;
	int		i;
}			t_params;

int		ft_printf(const char *str, ...);
int		ft_parse(char *str, t_params *s_pf, va_list arglst);
void	ft_parse_flag(char c, t_params *s_pf);
void	ft_parse_type(char *str, t_params *s_pf);
void	ft_parse_width(char *str, t_params *s_pf, va_list arglst);
void	ft_zero_struct(t_params *s_pf);
void	ft_parse_precision(char *str, t_params *s_pf, va_list arglst);

void	ft_write_space(int j, t_params *s_pf);
void	ft_write_zero(int j, t_params *s_pf);
void	ft_gethex_pf(unsigned long a, t_params *s_pf, char b);
void	ft_cntsizehex_p(unsigned long a, int *j);
void	ft_putstr_pf(char *a, t_params *s_pf);
void	ft_putchr_pf(char a, t_params *s_pf);

void	ft_do_type(t_params *s_pf, va_list arglst);

void	ft_type_d(t_params *s_pf, int val);
void	ft_push_d(t_params *s_pf, char *sign, char *out, int out_l);
void	ft_wpbo_d(t_params *s_pf, char *sign, char *out, int out_l);
void	ft_wbo_d(t_params *s_pf, char *sign, char *out, int out_l);
void	ft_pbo_d(t_params *s_pf, char *sign, char *out, int out_l);

void	ft_type_u(t_params *s_pf, unsigned int val);
void	ft_push_u(t_params *s_pf, char *out, int out_l);
void	ft_wpbo_u(t_params *s_pf, char *out, int out_l);
void	ft_wbo_u(t_params *s_pf, char *out, int out_l);
void	ft_pbo_u(t_params *s_pf, char *out, int out_l);

void	ft_type_p(t_params *s_pf, unsigned long val);
void	ft_wpbo_p(t_params *s_pf, unsigned long val, int out_l);
void	ft_wbo_p(t_params *s_pf, unsigned long val, int out_l);

void	ft_type_x(t_params *s_pf, unsigned int val);
void	ft_push_x(t_params *s_pf, unsigned int val, int out_l);
void	ft_wpbo_x(t_params *s_pf, unsigned int val, int out_l);
void	ft_wbo_x(t_params *s_pf, unsigned int val, int out_l);
void	ft_pbo_x(t_params *s_pf, unsigned int val, int out_l);

void	ft_type_c(t_params *s_pf, int val);

void	ft_type_s(t_params *s_pf, char *val);
void	ft_putless_pf(char *val, int j, t_params *s_pf);

void	ft_type_percent(t_params *s_pf);

#endif
