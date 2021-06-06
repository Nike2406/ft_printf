#include "../includes/ft_printf.h"

int	ft_parse(char *str, t_params *s_pf, va_list arglst)
{
	while (str[s_pf->i] == '-' || str[s_pf->i] == '0')
		ft_parse_flag(str[s_pf->i], s_pf);
	if ((str[s_pf->i] >= '0' && str[s_pf->i] <= '9') || str[s_pf->i] == '*')
		ft_parse_width(str, s_pf, arglst);
	if (str[s_pf->i] == '.')
	{
		s_pf->dot = 1;
		s_pf->i++;
		ft_parse_precision(str, s_pf, arglst);
	}
	ft_parse_type(str, s_pf);
	ft_do_type(s_pf, arglst);
	return (s_pf->cnt);
}

void	ft_parse_type(char *str, t_params *s_pf)
{
	if (str[s_pf->i] == 'd' || str[s_pf->i] == 'i')
		s_pf->type = 'd';
	else if (str[s_pf->i] == 'u')
		s_pf->type = 'u';
	else if (str[s_pf->i] == 'p')
		s_pf->type = 'p';
	else if (str[s_pf->i] == 'x')
		s_pf->type = 'x';
	else if (str[s_pf->i] == 'X')
		s_pf->type = 'X';
	else if (str[s_pf->i] == 'c')
		s_pf->type = 'c';
	else if (str[s_pf->i] == 's')
		s_pf->type = 's';
	else if (str[s_pf->i] == '%')
		s_pf->type = '%';
}

void	ft_parse_flag(char c, t_params *s_pf)
{
	if (c == '-')
		s_pf->flags.minus = 1;
	if (c == '+')
		s_pf->flags.plus = 1;
	if (c == '0')
		s_pf->flags.zero = 1;
	if (c == ' ')
		s_pf->flags.space = 1;
	if (c == '#')
		s_pf->flags.sharp = 1;
	s_pf->i++;
}

void	ft_parse_width(char *str, t_params *s_pf, va_list arglst)
{
	if (str[s_pf->i] == '*')
	{
		s_pf->width = va_arg(arglst, int);
		if (s_pf->width < 0)
		{
			s_pf->flags.minus = 1;
			s_pf->width = -s_pf->width;
		}
		s_pf->i++;
		return ;
	}
	while (str[s_pf->i] >= '0' && str[s_pf->i] <= '9')
	{
		s_pf->width = (s_pf->width * 10) + (str[s_pf->i] - '0');
		s_pf->i++;
	}
}

void	ft_parse_precision(char *str, t_params *s_pf, va_list arglst)
{
	if (str[s_pf->i] == '*')
	{
		s_pf->precision = va_arg(arglst, int);
		if (s_pf->precision < 0)
			s_pf->precision = -1;
		s_pf->i++;
		return ;
	}
	s_pf->precision = 0;
	while (str[s_pf->i] >= '0' && str[s_pf->i] <= '9')
	{
		s_pf->precision = (s_pf->precision * 10) + (str[s_pf->i] - '0');
		s_pf->i++;
	}
}
