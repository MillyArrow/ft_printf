#include "includes/ft_printf.h"
#include "stdio.h"
#include <stdlib.h>
#include "unistd.h"

int main()
{
	int k;
	int j;

	k = printf("\033[00;31m");
	printf("abcdef");
	ft_printf("%d\n",k);
	j = ft_printf("\033[00;31m");
	ft_printf("%d", j);
    return(0);
}