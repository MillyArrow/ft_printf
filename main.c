#include "includes/ft_printf.h"
#include "stdio.h"
#include <stdlib.h>
#include "unistd.h"

int main()
{
    ft_printf("%10.1f\n", 11.99);
    printf("%.2e\n", 11.99);
    ft_printf("{blue}%s", "World\n");
    printf("\033[1;31m");
    printf("Hello world\n");
    printf("\033[0m;");
    return(0);
}