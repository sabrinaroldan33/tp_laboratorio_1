#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "persona.h"

/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array persona Array of persona
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int persona_Inicializar(Persona array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array persona Array de persona
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int persona_buscarEmpty(Persona array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array persona Array de persona
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int persona_buscarDni(Persona array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].dni==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array persona Array de persona
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int persona_buscarInt(Persona array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].edad==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//String
/** \brief Busca un string en un array
* \param array persona Array de persona
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int persona_buscarString(Persona array[], int size, char* valorBuscado, int* indice)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].nombre,valorBuscado)==0)
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array persona Array de persona
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int persona_alta(Persona array[], int size, int* contadorId)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorId!=NULL)
    {
        if(persona_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorId)++;
            array[posicion].isEmpty=0;
            printf("Ingrese los datos de la persona:");
            utn_getUnsignedInt("\nDNI: ","\nError",1,11,0,10,2,&array[posicion].dni);
            utn_getUnsignedInt("\nEdad: ","",1,sizeof(int),0,10,1,&array[posicion].edad);
            utn_getName("\nName: ","",1,TEXT_SIZE,1,array[posicion].nombre);
            //rangoEdad (array[posicion].edad,size);
            printf("\nPosicion: %d\nDNI: %d\nEdad: %d\nNombre: %s\n\n",
                   posicion, array[posicion].dni,array[posicion].edad,array[posicion].nombre);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array persona Array de persona
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int persona_baja(Persona array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nDNI a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,array[posicion].dni);
        if(persona_buscarDni(array,sizeArray,array[posicion].dni,&posicion)==-1)
        {
            printf("\nNo existe este DNI");
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].dni=0;
            array[posicion].edad=0;
            strcpy(array[posicion].nombre,"");
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array persona Array de persona
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int persona_bajaValorRepetidoInt(Persona array[], int sizeArray, int valorBuscado)
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].dni==valorBuscado)
            {
                array[i].isEmpty=1;
                array[i].dni=0;
                array[i].edad=0;
                strcpy(array[i].nombre,"");
            }
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array ante la igualdad de estos ordena por el campo ZZZZZZ
* \param array persona Array de persona
* \param size int Tamaño del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int persona_ordenarPorDobleCriterio(Persona array[],int size, int orderFirst, int orderSecond)                              //cambiar persona
{
    int retorno=-1;
    int i;
    Persona buffer;
    int flagSwap;

    if(array!=NULL && size>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 1; i < size-1; i++)
            {
                if( ((strcmp(array[i].nombre,array[i+1].nombre) < 0) && orderFirst) ||
                    ((strcmp(array[i].nombre,array[i+1].nombre) > 0) && !orderFirst) )
                {
                    flagSwap=1;
                    buffer = array[i];
                    array[i] = array[i+1];
                    array[i+1] = buffer;
                }
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array persona Array de persona
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int persona_listar(Persona array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\nDNI: %d\nEdad: %d\nNombre: %s\n\n",
                   array[i].dni,array[i].edad,array[i].nombre);
        }
        retorno=0;
    }
    return retorno;
}

/*void persona_mock(Persona arrayPersona[], int size,int *contadorId)
{
    arrayPersona[0].dni=0;
    arrayPersona[0].isEmpty=0;
    arrayPersona[0].edad=0;
    strcpy(arrayPersona[0].nombre,"CCCCC");
    *contadorId++;

    arrayPersona[1].dni=1;
    arrayPersona[1].isEmpty=0;
    arrayPersona[1].edad=0;
    strcpy(arrayPersona[1].nombre,"AAAAA");
    *contadorId++;

    arrayPersona[2].dni=2;
    arrayPersona[2].isEmpty=0;
    arrayPersona[2].edad=0;
    strcpy(arrayPersona[2].nombre,"BBBBBB");
    *contadorId++;

    arrayPersona[3].dni=3;
    arrayPersona[3].isEmpty=0;
    arrayPersona[3].edad=0;
    strcpy(arrayPersona[3].nombre,"BBBBBB");
    contadorId++;
}*/

void rangoEdad (int edad,int size)
{
    int retorno=-1;
    int i;
    char rangos[3][size];

    if(edad>=0)
    {
        if(edad<=18)
        {
            for(i=0;i<size;i++)
            {
                rangos[0][i]='*';
            }
        if(edad>=19 && edad<=35)
        {
            for(i=0;i<size;i++)
            {
                rangos[1][i]='*';
            }
        }
        if(edad>35)
        {
            for(i=0;i<size;i++)
            {
                rangos[2][i]='*';
            }
        }
        }
        retorno=0;
    }
    return retorno;
}

char imprimirRangos(char Rangos [],int size)
{
    int retorno=-1;
    int i;
    if(Rangos!=NULL && size>=0)
    {
       for(i=0;i<size;i++)
       {
           printf("%c",Rangos[i]);
       }



            retorno=0;
    }
    return retorno;
}
