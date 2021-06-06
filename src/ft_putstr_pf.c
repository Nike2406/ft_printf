#include "../includes/ft_printf.h"

void	ft_putstr_pf(char *a, t_params *s_pf)
{
	int	i;

	if (!a)
		return ;
	i = 0;
	while (a[i])
	{
		write(1, &a[i], 1);
		i++;
		s_pf->cnt++;
	}
}
