#include "../includes/ft_printf.h"

void	ft_type_c(t_params *s_pf, int val)
{
	int	cmpr;

	cmpr = 0;
	if (s_pf->width > 1)
		cmpr = s_pf->width - 1;
	if (!s_pf->flags.minus)
		ft_write_space(cmpr, s_pf);
	ft_putchr_pf((char)val, s_pf);
	if (s_pf->flags.minus)
		ft_write_space(cmpr, s_pf);
}
