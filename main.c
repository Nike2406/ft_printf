#include <stdio.h>
// #include <math.h>
#include "./includes/ft_printf.h"
// #include "libft.a"

int main()
{
	// char	*a = "asdfgh";
	// int		s = -234;
	// double  pi = 3.14;
	// int i = 10;

	// ft_printf("|1 a%%|\t|%-23.45d|\t|%*.*d|\n", -2147483648, 62, 51, 14);
	// printf("%d\n",printf("1 a%%d%%-\n"));
	// printf("%5%\t%6.5d", s);
	// printf("%-5.d", 0);
	// printf("Hi! \t | %.5d = %-*.*d |\n", s, 10, 5, 13);
	// ft_printf("Hi! \t | %.5s = %0*.*f |\n", s, 10, 5, M_PI);
//	ft_printf("ghjk", 100000, 20);
	printf("s|%% *.5i 42 == |% *.5i|\n", 4, 42);
	ft_printf("m|%% *.5i 42 == |% *.5i|\n", 4, 42);
	fflush(stdout);
	return (0);
}
