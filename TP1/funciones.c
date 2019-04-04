#include <stdio.h>
#include <stdlib.h>

int numeroValido (int a)
{
    if((a==NULL) || (a=='\n') || (a==' '))
    {
        printf("Numero ingresado no valido, ingrese otro numero\n");
    }
    return 0;
}
int sumaNumerosIngresados (int a, int b)
{
    int suma;
    suma=a+b;
    return suma;
}

int restaNumerosIngresados (int a, int b)
{
    int resta;
    resta=a-b;
    return resta;
}

int divisionNumerosIngresados (int a, int b)
{
    int division;
    division=a/b;
    return division;
}

int multiplicacionNumerosIngresados (int a, int b)
{
    int multiplicacion;
    multiplicacion=a*b;
    return multiplicacion;
}

int factorialNumerosIngresados (int a)
{
    int factorial=1;
    for (int i=1; i<=a; i++)
    {
    factorial=factorial*i;
    }
    return factorial;
}
