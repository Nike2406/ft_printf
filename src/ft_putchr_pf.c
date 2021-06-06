#include "../includes/ft_printf.h"

void	ft_putchr_pf(char a, t_params *s_pf)
{
	write(1, &a, 1);
	s_pf->cnt++;
}
