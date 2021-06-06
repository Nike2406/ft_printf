#include "../includes/ft_printf.h"

void	ft_do_type(t_params *s_pf, va_list arglst)
{
	if (s_pf->type == 'd')
		ft_type_d(s_pf, va_arg(arglst, int));
	else if (s_pf->type == 'u')
		ft_type_u(s_pf, va_arg(arglst, unsigned int));
	else if (s_pf->type == 'p')
		ft_type_p(s_pf, va_arg(arglst, unsigned long));
	else if (s_pf->type == 'x' || s_pf->type == 'X')
		ft_type_x(s_pf, va_arg(arglst, unsigned int));
	else if (s_pf->type == 'c')
		ft_type_c(s_pf, va_arg(arglst, int));
	else if (s_pf->type == 's')
		ft_type_s(s_pf, va_arg(arglst, char *));
	else if (s_pf->type == '%')
		ft_type_percent(s_pf);
}
