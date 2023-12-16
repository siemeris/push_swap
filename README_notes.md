Diferencia entre bash y zsh
En Bash, cuando expandes $ARG sin comillas dobles en la variable, se divide en palabras por espacios en blanco, y estas palabras se pasan como argumentos a los programas, por lo que la linea:
ARG="1 2 3" ; ./Push_swap $ARG | ./checker_Mac $ARG
es interpretada como:
./Push_swap "1"  "2"  "3" | ./checker_Mac "1" "2" "3"
En zsh, la expansión es un poco diferente ya no divide automáticamente las palabras en espacios en blanco cuando se expanden variables sin comillas dobles, por lo que la misma linea la interpreta como:
"./Push_swap", "1 2 3"

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
