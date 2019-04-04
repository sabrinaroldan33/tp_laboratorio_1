#include <stdio.h>
#include <stdlib.h>

/*
* \brief Verifica si el numero obtenido es valido.
* \param Toma el valor del numero dado por el usuario.
* \return Devuelve el mensaje de error o 0 si es correcto.
*
*/
int numeroValido (int a)
{
   if((a==NULL) || (a!='\0') || (a==EOF) || (a!='\ '))
    {
        printf("Caracter ingresado no valido, ingrese otro numero\n");
    }
    return 0;
}

/*
* \brief Suma dos valores.
* \param Toma el valor de los numeros ingresados por el usuario.
* \return Devuelve la suma de los numeros ingresados.
*
*/
int sumaNumerosIngresados (int a, int b)
{
    int suma;
    suma=a+b;
    return suma;
}

/*
* \brief Resta dos valores.
* \param Toma el valor de los numeros ingresados por el usuario.
* \return Devuelve la resta de los numeros ingresados.
*
*/
int restaNumerosIngresados (int a, int b)
{
    int resta;
    resta=a-b;
    return resta;
}

/*
* \brief Divide dos valores.
* \param Toma el valor de los numeros ingresados por el usuario.
* \return Devuelve la division de los numeros ingresados.
*
*/
int divisionNumerosIngresados (int a, int b)
{
    int division;
    division=a/b;
    return division;
}

/*
* \brief Multiplica dos valores.
* \param Toma el valor de los numeros ingresados por el usuario.
* \return Devuelve la multiplicacion de los numeros ingresados.
*
*/
int multiplicacionNumerosIngresados (int a, int b)
{
    int multiplicacion;
    multiplicacion=a*b;
    return multiplicacion;
}

/*
* \brief Factoriza un valor.
* \param Toma el valor del numero ingresado por el usuario.
* \return Devuelve la factorizacion del numero ingresado.
*
*/
int factorialNumerosIngresados (int a)
{
    int factorial=1;
    for (int i=1; i<=a; i++)
    {
    factorial=factorial*i;
    }
    return factorial;
}
