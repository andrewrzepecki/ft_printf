#include "../ft_printf.h"
#include <stdio.h>
#include <stdint.h>
#include <float.h>

int    main(void)
{
   /* printf("{%.*s}\n", -5, "42");
    ft_printf("{%.*s}\n", -5, "42");
    printf("{%.0d}'n", 42);
    ft_printf("{%.0d}\n", 42);*/

	int			nb;
	double		lf;

	/*lf = -1.424442;
	nb = (int)lf;
	ft_printf("%010.3f\n", lf);
	printf("%010.3f\n", lf);
	ft_printf("{%f}\n", 1.46464662);
	printf("{%f}\n", 1.46464662);
	ft_printf("{%.50f}\n", 1.46464662);
	printf("{%.50f}\n", 1.46464662);*/

	nb = printf("%.2s, %.f\n", 0, 1.499998);
	printf("Ret = %d\n", nb);
	nb = ft_printf("%.2s, %.f\n", 0, -0.499998);
	printf("Ret = %.4f\n", 0.0001);
	ft_printf("Ret = %.4f\n", 0.0001);
	printf("%.f\n", -0.00000001);
	ft_printf("%.f\n", -0.00000001);
	printf("%lf\n", 32135351335351351.3538435);
	ft_printf("%lf\n", 32135351335351351.3538435);

    return (0);
}
