#include "../includes/ft_printf.h"

void	ft_write_space(int j, t_params *s_pf)
{
	while (j-- > 0)
	{
		write(1, " ", 1);
		s_pf->cnt++;
	}
}

void	ft_write_zero(int j, t_params *s_pf)
{
	while (j-- > 0)
	{
		write(1, "0", 1);
		s_pf->cnt++;
	}
}

void	ft_gethex_pf(unsigned long a, t_params *s_pf, char b)
{
	unsigned int	k;

	if (a % 16 < 10)
		k = 48;
	else
	{
		if (b == 'X')
			k = 55;
		else
			k = 87;
	}
	if (a < 16)
		ft_putchr_pf(a + k, s_pf);
	else
	{
		ft_gethex_pf(a / 16, s_pf, b);
		ft_putchr_pf(a % 16 + k, s_pf);
	}
}

void	ft_cntsizehex_p(unsigned long a, int *j)
{
	if (a < 16)
		(*j)++;
	else
	{
		(*j)++;
		a /= 16;
		ft_cntsizehex_p(a, j);
	}
}
