#include "../includes/ft_printf.h"

void	ft_type_s(t_params *s_pf, char *val)
{
	int	out_l;
	int	cmpr;
	int	chk;

	chk = 0;
	cmpr = 0;
	if (!val)
		val = "(null)";
	out_l = ft_strlen(val);
	if ((out_l > s_pf->precision) && !(s_pf->precision < 0))
	{
		cmpr = s_pf->width - s_pf->precision;
		out_l = s_pf->precision;
		chk = 1;
	}
	if (out_l < s_pf->width)
		cmpr = s_pf->width - out_l;
	if (!s_pf->flags.minus)
		ft_write_space(cmpr, s_pf);
	if (chk)
		ft_putless_pf(val, s_pf->precision, s_pf);
	else
		ft_putstr_pf(val, s_pf);
	if (s_pf->flags.minus)
		ft_write_space(cmpr, s_pf);
}

void	ft_putless_pf(char *val, int j, t_params *s_pf)
{
	int	i;

	i = 0;
	while (j > i)
		ft_putchr_pf(val[i++], s_pf);
}
