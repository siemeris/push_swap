#include "push_swap.h"


//CONTROL DE ERRORES:
//Si hay algún error, el programa deberá mostrar "Error" seguido de un salto de línea y
// devolver el control al sistema operativo (return (1)).
//Los errores pueden ser de dos tipos:
//• Formato de entrada: los parámetros no son números enteros, hay duplicados, hay
// algún parámetro que no es un número, etc. 
// Puede admitir a la vez numeros string y numeros int.
// Puede admitir negativos.


int check_arg(int argc, char **arg)
{
    int i;
    int j;
    int len;

    i = 1;
    j = i + 1;

    while(arg[i])
    {
        //comprobamos que sea numero
        len = ft_strlen(arg[i]);
        // ft_printf("len %i", len );
        while(len >= 1)
        {
            // ft_printf("caracter %c", arg[i][len-1]);
            if (!((arg[i][len-1] >= 48 && arg[i][len-1] <= 57) || (arg[i][len-1] == 45) || (arg[i][len-1] == 43)))
            {
                ft_printf("estoy awuí, caracter no valido %c", arg[i][len-1]);
                return(0);
            }
            len--; 
        }
        i++;
    }

    //comprobamos que no hay número repetidos
    i = 1;

    //ft_printf("i %i atoi %i", i, ft_atoi(arg[j]));
    while (i < argc - 1)
    {
        j = i + 1;
        while(arg[j])
        {
            if (ft_atoi(arg[i])==ft_atoi(arg[j]))
            {
                ft_printf("Números repes %i %i", ft_atoi(arg[i]), ft_atoi(arg[j]));
                return (0);
            }
            j++;
        }
        i++;
    }
    return(1);
}