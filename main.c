#include "ft_printf.h"
#include "stdio.h"
int main()
{
    ft_printf("%10.1f\n", 11.99);
    printf("%.2e\n", 11.99);
    return(0);
}