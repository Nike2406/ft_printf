#include "../includes/ft_printf.h"

void	ft_zero_struct(t_params *s_pf)
{
	s_pf->flags.minus = 0;
	s_pf->flags.plus = 0;
	s_pf->flags.zero = 0;
	s_pf->flags.space = 0;
	s_pf->flags.sharp = 0;
	s_pf->width = 0;
	s_pf->precision = -1;
	s_pf->length = 0;
	s_pf->type = 0;
	s_pf->dot = 0;
}
