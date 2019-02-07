#include "../ft_printf.h"
#include <stdio.h>
#include <stdint.h>
#include <float.h>

int    main(void)
{
   printf("{%.*s}\n", -5, "42");
    ft_printf("{%.*s}\n", -5, "42");
    printf("{%.0d}\n", 42);
    ft_printf("{%.0d}\n", 42);

	int			nb;
	double		lf;

	lf = 42.4242424298;

	ft_printf("%010f\n", lf);
	printf("%010f\n", lf);
	ft_printf("{%.f}\n", 1.46464662);
	printf("{%.f}\n", 1.46464662);
	ft_printf("{%.50f}\n", 1.46464662);
	printf("{%.50f}\n", 1.46464662);

	nb = printf("%.2s, %.f\n", 0, 0.499998);
	nb = ft_printf("%.2s, %.f\n", 0, 0.499998);
	printf("Ret = %.4f\n", 0.0001);
	ft_printf("Ret = %.4f\n", 0.0001);
	printf("%.f\n", -0.00000001);
	ft_printf("%.f\n", -0.00000001);
	printf("%.38Lf\n", 656599993213535133535139999.353843599L);
	ft_printf("%.38Lf\n", 656599993213535133535139999.353843599L);
	printf("%-10s", "Hello");
	ft_printf("%-10s", "Hello");
	
    ft_printf("%10s is a string", "this");

    return (0);
}
