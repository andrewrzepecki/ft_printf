#include "../ft_printf.h"
#include <stdio.h>
#include <stdint.h>

int    main(void)
{
   /* printf("{%.*s}\n", -5, "42");
    ft_printf("{%.*s}\n", -5, "42");
    printf("{%.0d}'n", 42);
    ft_printf("{%.0d}\n", 42);*/

    ft_printf("%o, %ho, %hho\n", -42, -42, -42);
    printf("%o, %ho, %hho\n", -42, -42, -42);
    return (0);
}
