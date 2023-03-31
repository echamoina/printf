#include "main.h"

/**
 * handle_precision - handles the precision for non-custom conversion specifiers
 * @specifier: the conversion specifier
 * @precision: the precision specified in the format string
 * @arg: the argument to be formatted
 *
 * Return: the formatted string
 */
char *handle_precision(char specifier, int precision, va_list arg)
{
    char *str;

    if (specifier == 's') // handle precision for string specifier
    {
        str = va_arg(arg, char *);
        if (precision >= 0 && precision < (int)strlen(str))
            str[precision] = '\0';
    }
    else if (specifier == 'f') // handle precision for float specifier
    {
        float f = va_arg(arg, double);
        char *temp = ft_ftoa(f, precision);
        str = ft_strdup(temp);
        free(temp);
    }
    else
    {
        // handle precision for other non-custom specifiers
    }

    return (str);
}
