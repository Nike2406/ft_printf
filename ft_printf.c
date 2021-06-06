#include "./includes/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		arglst;
	long long	i;
	t_params	s_pf;

	i = 1;
	s_pf.cnt = 0;
	s_pf.i = 0;
	va_start(arglst, str);
	while (str[s_pf.i])
	{
		if (str[s_pf.i] != '%' && str[s_pf.i])
		{
			write(1, &str[s_pf.i], 1);
			s_pf.cnt++;
		}
		if (str[s_pf.i] == '%')
		{
			ft_zero_struct(&s_pf);
			s_pf.i++;
			ft_parse((char *)str, &s_pf, arglst);
		}
		s_pf.i++;
	}
	va_end(arglst);
	return (s_pf.cnt);
}
