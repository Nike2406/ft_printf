#include "../includes/ft_printf.h"

void	ft_type_p(t_params *s_pf, unsigned long val)
{
	int		out_l;

	out_l = 0;
	ft_cntsizehex_p(val, &out_l);
	if (s_pf->precision == 0 && s_pf->dot && !val)
	{
		if (!s_pf->flags.minus)
			ft_write_space(s_pf->width - 2, s_pf);
		ft_putstr_pf("0x", s_pf);
		if (s_pf->flags.minus)
			ft_write_space(s_pf->width - 2, s_pf);
	}
	else if (s_pf->width > out_l && s_pf->precision > out_l)
		ft_wpbo_p(s_pf, val, out_l);
	else if (s_pf->width > out_l || s_pf->precision > out_l)
		ft_wbo_p(s_pf, val, out_l);
	else
	{
		ft_putstr_pf("0x", s_pf);
		ft_gethex_pf(val, s_pf, '0');
	}
}

void	ft_wpbo_p(t_params *s_pf, unsigned long val, int out_l)
{
	int	cmpr;

	cmpr = 0;
	if (s_pf->precision < 0)
		s_pf->precision = 0;
	if (s_pf->flags.minus)
	{
		cmpr = s_pf->precision - out_l;
		ft_putstr_pf("0x", s_pf);
		ft_write_zero(cmpr, s_pf);
		ft_gethex_pf(val, s_pf, '0');
		cmpr = s_pf->width - s_pf->precision - 2;
		ft_write_space(cmpr, s_pf);
	}
	else
	{
		cmpr = s_pf->width - s_pf->precision - 2;
		ft_write_space(cmpr, s_pf);
		if (s_pf->precision)
			cmpr = s_pf->precision - out_l;
		ft_putstr_pf("0x", s_pf);
		ft_write_zero(cmpr, s_pf);
		ft_gethex_pf(val, s_pf, '0');
	}
}

void	ft_wbo_p(t_params *s_pf, unsigned long val, int out_l)
{
	int	cmpr;

	cmpr = s_pf->width - out_l - 2;
	if (s_pf->flags.minus)
	{
		ft_putstr_pf("0x", s_pf);
		ft_gethex_pf(val, s_pf, '0');
		ft_write_space(cmpr, s_pf);
	}
	else if (!s_pf->flags.minus && s_pf->precision < 0 && s_pf->flags.zero)
	{
		ft_putstr_pf("0x", s_pf);
		ft_write_zero(cmpr, s_pf);
		ft_gethex_pf(val, s_pf, '0');
	}
	else
	{
		ft_write_space(cmpr, s_pf);
		ft_putstr_pf("0x", s_pf);
		ft_gethex_pf(val, s_pf, '0');
	}
}
