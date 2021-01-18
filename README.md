# ft_printf
# ft_printf
ft_printf project reproduces behavior of standard function printf.
### ft_printf must achieve the following mandatory requirements:
- manage the following conversions: ```s, p, d, i, o, u, x, X, c, f ```;
- manage ```%%```;
- manage the flags: ```0, -, + & space```;
- manage the *minimum field-width*;
- manage the *precision*;
- manage the modifiers: ```hh, h, l, ll```.

Allowed functions are *write, malloc, free, exit and the three functions of stdarg*.
Others one are forbidden.

### Example

```ft_printf("this is %s%c it took %+d days, probability of bugs is %.10f", "ft_printf", ',', 15, 0.00001);```

output: ```"this is ft_printf, it took +15 days, probability of bugs is 0.0000100000"```

### Usage
To compile run **make**. it will create libft.a and libftprintf.a files. Create a main.c file, don't forget to include header file "ft_printf.h".

Then run ```gcc -Wall -Wextra -Werror main.c libftprintf.a libft/libft.a -I includes/ -I libft/includes```
