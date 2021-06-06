#include "../includes/ft_printf.h"

void	ft_type_x(t_params *s_pf, unsigned int val)
{
	int		out_l;

	out_l = 0;
	ft_cntsizehex_p(val, &out_l);
	ft_push_x(s_pf, val, out_l);
}

void	ft_push_x(t_params *s_pf, unsigned int val, int out_l)
{
	if (s_pf->precision == 0 && s_pf->dot && val == 0)
		ft_write_space(s_pf->width, s_pf);
	else if (s_pf->width > out_l && s_pf->precision > out_l)
		ft_wpbo_x(s_pf, val, out_l);
	else if (s_pf->width > out_l)
		ft_wbo_x(s_pf, val, out_l);
	else if (s_pf->precision > out_l)
		ft_pbo_x(s_pf, val, out_l);
	else
		ft_gethex_pf(val, s_pf, s_pf->type);
}

void	ft_wpbo_x(t_params *s_pf, unsigned int val, int out_l)
{
	int	cmpr;

	cmpr = 0;
	if (s_pf->flags.minus)
	{
		cmpr = s_pf->precision - out_l;
		ft_write_zero(cmpr, s_pf);
		ft_gethex_pf(val, s_pf, s_pf->type);
		cmpr = s_pf->width - s_pf->precision;
		ft_write_space(cmpr, s_pf);
	}
	else
	{
		cmpr = s_pf->width - s_pf->precision;
		ft_write_space(cmpr, s_pf);
		cmpr = s_pf->precision - out_l;
		ft_write_zero(cmpr, s_pf);
		ft_gethex_pf(val, s_pf, s_pf->type);
	}
}

void	ft_wbo_x(t_params *s_pf, unsigned int val, int out_l)
{
	int	cmpr;

	cmpr = s_pf->width - out_l;
	if (s_pf->flags.minus)
	{
		ft_gethex_pf(val, s_pf, s_pf->type);
		ft_write_space(cmpr, s_pf);
	}
	else if (!s_pf->flags.minus && s_pf->precision < 0 && s_pf->flags.zero)
	{
		ft_write_zero(cmpr, s_pf);
		ft_gethex_pf(val, s_pf, s_pf->type);
	}
	else
	{
		ft_write_space(cmpr, s_pf);
		ft_gethex_pf(val, s_pf, s_pf->type);
	}
}

void	ft_pbo_x(t_params *s_pf, unsigned int val, int out_l)
{
	int	cmpr;

	cmpr = s_pf->precision - out_l;
	ft_write_zero(cmpr, s_pf);
	ft_gethex_pf(val, s_pf, s_pf->type);
}
