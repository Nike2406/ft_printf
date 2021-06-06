#include "../includes/ft_printf.h"

void	ft_type_percent(t_params *s_pf)
{
	int	cmpr;

	cmpr = 0;
	if (s_pf->width > 1)
		cmpr = s_pf->width - 1;
	if (!s_pf->flags.minus)
	{
		if (s_pf->flags.zero)
			ft_write_zero(cmpr, s_pf);
		else
			ft_write_space(cmpr, s_pf);
	}
	ft_putchr_pf('%', s_pf);
	if (s_pf->flags.minus)
		ft_write_space(cmpr, s_pf);
}
