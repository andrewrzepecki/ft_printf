#include "../ft_printf.h"
#include <stdio.h>
#include <stdint.h>

int    main(void)
{
   /* printf("{%.*s}\n", -5, "42");
    ft_printf("{%.*s}\n", -5, "42");
    printf("{%.0d}'n", 42);
    ft_printf("{%.0d}\n", 42);*/

	long double lf;

	lf = 1.42444252;
	printf("%.16Lf\n %.0f\n", lf, 1.42424242);
    return (0);
}
