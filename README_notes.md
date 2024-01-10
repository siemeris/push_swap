### Diferencia entre bash y zsh
En Bash, cuando expandes $ARG sin comillas dobles en la variable, se divide en palabras por espacios en blanco, y estas palabras se pasan como argumentos a los programas, por lo que la linea:
ARG="1 2 3" ; ./Push_swap $ARG | ./checker_Mac $ARG
es interpretada como:
./Push_swap "1"  "2"  "3" | ./checker_Mac "1" "2" "3"
En zsh, la expansión es un poco diferente ya no divide automáticamente las palabras en espacios en blanco cuando se expanden variables sin comillas dobles, por lo que la misma linea la interpreta como:
"./Push_swap", "1 2 3"

### movimientos
El objetivo es ordenar los números del stack a en orden ascendente. Para hacerlo
tienes las siguientes operaciones a tu disposición:
sa swap a: Intercambia los dos primeros elementos del stack a. No hace nada si
hay uno o menos elementos.
sb swap b: Intercambia los dos primeros elementos del stack b. No hace nada si
hay uno o menos elementos.
ss swap a y swap b a la vez.
pa push a: Toma el primer elemento del stack b y lo pone el primero en el stack
a. No hace nada si b está vacío.
pb push b: Toma el primer elemento del stack a y lo pone el primero en el stack
b. No hace nada si a está vacío.
ra rotate a: Desplaza hacia arriba todos los elementos del stack a una posición,
de forma que el primer elemento se convierte en el último.
rb rotate b: Desplaza hacia arriba todos los elementos del stack b una posición,
de forma que el primer elemento se convierte en el último.
rr ra y rb al mismo tiempo.
rra reverse rotate a: Desplaza hacia abajo todos los elementos del stack a una
posición, de forma que el último elemento se convierte en el primero.
rrb reverse rotate b: Desplaza hacia abajo todos los elementos del stack b una
posición, de forma que el último elemento se convierte en el primero.
rrr rra y rrb al mismo tiempo.

### Ejemplo 500 números:
./push_swap -320 329 547 -351 82 -352 -673 -826 507 -770 815 -617 710 435 403 897 -25 238 -381 485 -537 126 778 -127 -935 647 -232 -486 -664 -818 104 777 -353 336 -703 666 -648 169 803 348 -466 -77 520 -938 92 -575 638 -808 84 108 209 808 -681 -556 -410 -518 -823 6 521 -601 -422 -548 -38 340 -603 -495 338 876 111 -229 854 35 851 598 -787 357 878 -328 -176 -345 53 183 -860 974 566 293 405 -993 -807 654 672 -474 317 -538 955 -765 948 12 -88 -584 -11 -892 432 704 422 153 -679 290 237 214 -916 656 467 -314 -878 -698 85 390 510 300 -413 -873 -198 563 -202 499 -298 663 -849 93 518 645 244 -587 684 754 -221 787 454 492 -551 -554 -563 -448 557 -810 -178 -46 -128 302 -572 414 -583 431 -880 634 459 198 685 -768 -263 343 -361 -329 243 -804 761 398 792 -225 342 -92 -542 -592 -866 106 893 594 -175 924 -131 122 756 481 -252 833 444 255 -28 372 850 321 -159 741 -47 174 -530 -514 319 877 -145 653 -146 694 753 -908 -856 820 -378 179 571 -595 26 -40 211 265 769 -544 -718 331 471 77 49 648 15 110 667 -457 602 -956 522 228 325 732 718 -635 904 361 -573 -407 154 -87 963 -109 -985 76 -379 456 351 633 173 -625 628 -482 -712 -604 -715 899 -622 -463 -63 101 969 80 -828 277 13 874 531 -281 260 477 -602 -79 -882 782 -889 -981 -858 511 506 567 927 512 -580 -317 3 -469 913 -954 304 -120 -649 59 832 -745 766 -960 870 -894 -798 -612 253 534 698 -41 417 915 -350 157 -806 -458 -9 -2 91 479 -942 308 -794 -838 -947 908 376 215 -540 724 -967 -22 759 -106 538 -872 -57 -99 574 601 593 -732 827 -133 -20 -7 -166 44 -743 483 -618 988 -958 -124 696 909 -596 466 962 625 -382 -84 490 -710 575 -970 -81 688 680 -468 326 -450 393 588 -283 -851 -729 387 613 -661 339 709 828 72 125 781 -102 -887 -231 860 -426 -686 888 -217 929 395 -734 615 229 130 462 814 120 -778 245 -642 266 375 385 -528 -793 -670 425 -401 -666 -161 821 -949 -493 -555 410 871 584 -974 719 -850 323 -179 -78 69 -871 -107 -820 184 -30 -126 40 494 -987 845 945 240 -3 -73 416 428 -443 89 364 -392 687 19 -697 -326 723 344 662 -432 -208 -940 629 -423 674 -767 -447 -577 -922 -589 934 -336 320 783 933 -650 -444 -754 -403 -282 -459 -898 75 436 -680 322 623 -285 763 434 564 280 -557 -111 -943 -265 -833 103 -566 316 970 676 402 624 185 -44 | wc -l
    5245


https://42born2code.slack.com/archives/CN9RHKQHW/p1678967571416329


### Pseudocódigo:
//PASOS PARA ORDENAR STACK DE MAS DE 3 NÚMEROS:
//1. Crear stack B
// Si en A hay más de 3 elementos empujamos un elemento a B y ordenamos los 3 restantes.
//2. Mientras stack A tenga más de 3 números:
// 2.1. Calcular nodo objetivo (el cercano más pequeño, 
// si no hay cercano más pequeño entonces el objetivo es el más grande)
// 2.2. Análisis de Costes. 
// 2.3. Movemos el de menor coste a B.
// 2.4 2.2 y 2.3 hasta que queden 3 números.
//3. Ordenamos los 3 números de A.
//4. Mientras no queden números en B:
// 4.1. Calcular nodo objetivo de B a A(el cercano más grande
// si no hay cercano más grande entonces el objetivo es el más pequeño)
// 4.3. Movemos el objetivo en A al índice cero.
// 4.4 4.2 y 4.3 hasta que no queden números en B.


### Funciones para debuguear:
```C
void imprimir_lista(t_stack *A)
{
    t_stack *aux;

    aux = A;
    while (aux)
    {
        ft_printf("%i", aux->nbr);
        aux = aux->next;
    }
    ft_printf("\n");
}
````

```C
//para debuguear e imprimir todos los datos
void imprimir_lista_all(t_stack *A)
{
    t_stack *aux;

    aux = A;
    while (aux)
    {
        ft_printf("nbr:%i idx:%i cost:%i ab_medium:%i cheapest:%i\n", aux->nbr, aux->idx, aux->cost, aux->ab_medium, aux->cheapest);
        aux = aux->next;
    }
    ft_printf("\n");
}
``````

Para leaks:

```C
void	leaks(void)
{
	system("leaks -q push_swap");
}
````

```C
atexit(leaks);
``````