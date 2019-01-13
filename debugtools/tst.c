#include "ft_printf.h"
#include <stdio.h>

int    main(void)
{
   /* printf("{%.*s}\n", -5, "42");
    ft_printf("{%.*s}\n", -5, "42");
    printf("{%.0d}'n", 42);
    ft_printf("{%.0d}\n", 42);*/

    ft_printf("%.p, %.0p\n", 0, 0);
    printf("%.p, %.0p\n", 0, 0);
    return (0);
}
