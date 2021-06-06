#include "../includes/ft_printf.h"

void	ft_type_u(t_params *s_pf, unsigned int val)
{
	char	*out;
	int		out_l;

	out = ft_itoa(val);
	out_l = ft_strlen(out);
	ft_push_u(s_pf, out, out_l);
	free(out);
}

void	ft_push_u(t_params *s_pf, char *out, int out_l)
{
	if (s_pf->precision == 0 && s_pf->dot && *out == '0')
		ft_write_space(s_pf->width, s_pf);
	else if (s_pf->width > out_l && s_pf->precision > out_l)
		ft_wpbo_u(s_pf, out, out_l);
	else if (s_pf->width > out_l)
		ft_wbo_u(s_pf, out, out_l);
	else if (s_pf->precision > out_l)
		ft_pbo_u(s_pf, out, out_l);
	else
		ft_putstr_pf(out, s_pf);
}

void	ft_wpbo_u(t_params *s_pf, char *out, int out_l)
{
	int	cmpr;

	cmpr = 0;
	if (s_pf->flags.minus)
	{
		cmpr = s_pf->precision - out_l;
		ft_write_zero(cmpr, s_pf);
		ft_putstr_pf(out, s_pf);
		cmpr = s_pf->width - s_pf->precision;
		ft_write_space(cmpr, s_pf);
	}
	else
	{
		cmpr = s_pf->width - s_pf->precision;
		ft_write_space(cmpr, s_pf);
		cmpr = s_pf->precision - out_l;
		ft_write_zero(cmpr, s_pf);
		ft_putstr_pf(out, s_pf);
	}
}

void	ft_wbo_u(t_params *s_pf, char *out, int out_l)
{
	int	cmpr;

	cmpr = s_pf->width - out_l;
	if (s_pf->flags.minus)
	{
		ft_putstr_pf(out, s_pf);
		ft_write_space(cmpr, s_pf);
	}
	else if (!s_pf->flags.minus && s_pf->precision < 0 && s_pf->flags.zero)
	{
		ft_write_zero(cmpr, s_pf);
		ft_putstr_pf(out, s_pf);
	}
	else
	{
		ft_write_space(cmpr, s_pf);
		ft_putstr_pf(out, s_pf);
	}
}

void	ft_pbo_u(t_params *s_pf, char *out, int out_l)
{
	int	cmpr;

	cmpr = s_pf->precision - out_l;
	ft_write_zero(cmpr, s_pf);
	ft_putstr_pf(out, s_pf);
}
