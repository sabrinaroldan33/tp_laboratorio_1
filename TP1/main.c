#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int x=0;
    int y=0;
    int z;
    int error;

    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=%d)\n",x);
        printf("2- Ingresar 2do operando (B=%d)\n",y);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingrese el primer operando: \n");
                scanf("%d",&x);
                error=numeroValido (x);
                printf("%d",error);
                break;
            case 2:
                printf("Ingrese el segundo operando: \n");
                scanf("%d",&y);
                error=numeroValido (y);
                break;
            case 3:
                z=sumaNumerosIngresados (x,y);
                printf("\nLa suma de los numeros %d y %d es: %d \n\n",x,y,z);
                break;
            case 4:
                z=restaNumerosIngresados (x,y);
                printf("\nLa resta de los numeros %d y %d es: %d \n\n",x,y,z);
                break;
            case 5:
                z=divisionNumerosIngresados (x,y);
                printf("\nLa division de los numeros %d y %d es: %d \n\n",x,y,z);
                break;
            case 6:
                z=multiplicacionNumerosIngresados (x,y);
                printf("\nLa multiplicacion de los numeros %d y %d es: %d \n\n",x,y,z);
                break;
            case 7:
                z=factorialNumerosIngresados (x);
                printf("\nEl factorial del numero %d es: %d \n\n",x,z);
                break;
            case 8:
                z=sumaNumerosIngresados (x,y);
                printf("\nLa suma de los numeros %d y %d es: %d \n",x,y,z);
                z=restaNumerosIngresados (x,y);
                printf("La resta de los numeros %d y %d es: %d \n",x,y,z);
                z=divisionNumerosIngresados (x,y);
                printf("La division de los numeros %d y %d es: %d \n",x,y,z);
                z=multiplicacionNumerosIngresados (x,y);
                printf("La multiplicacion de los numeros %d y %d es: %d \n",x,y,z);
                z=factorialNumerosIngresados (x);
                printf("El factorial del numero %d es: %d \n\n",x,z);
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }
        return 0;

}
