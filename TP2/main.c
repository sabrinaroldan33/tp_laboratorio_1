#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"
#include "persona.h"

#define QTY_ARRAY_PERSONA 20
#define SORT_UP 1
#define SORT_DOWN 0

int main()
{
    char seguir='s';
    int opcion=0;
    int contadorId=0;

    Persona arrayPersona[QTY_ARRAY_PERSONA];
    persona_Inicializar(arrayPersona,QTY_ARRAY_PERSONA);
    persona_ordenarPorDobleCriterio(arrayPersona,QTY_ARRAY_PERSONA, SORT_UP, SORT_DOWN);

    char rangos[3][QTY_ARRAY_PERSONA];

    while(seguir=='s')
    {
        printf( "Ingrese una opcion:\n\n\t1: Agregar persona\n\t2: "
                "Borrar persona\n\t3: Imprimir lista ordenada por"
                " nombre\n\t4: Imprimir grafico de edades\n\n"
                "\t5: Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                persona_alta(arrayPersona,QTY_ARRAY_PERSONA,&contadorId);
                break;
            case 2:
                persona_baja(arrayPersona,QTY_ARRAY_PERSONA);
                break;
            case 3:
                persona_listar(arrayPersona,QTY_ARRAY_PERSONA);
                break;
            case 4:
                imprimirRangos(rangos,QTY_ARRAY_PERSONA);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
