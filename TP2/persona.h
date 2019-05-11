#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int dni;
    int isEmpty;
    char nombre[TEXT_SIZE];
    int edad;

}Persona;


#endif // PERSONA_H_INCLUDED

int persona_Inicializar(Persona array[], int size);
int persona_buscarEmpty(Persona array[], int size, int* posicion);
int persona_buscarDni(Persona array[], int size, int valorBuscado, int* posicion);
int persona_buscarInt(Persona array[], int size, int valorBuscado, int* posicion);
int persona_buscarString(Persona array[], int size, char* valorBuscado, int* indice);
int persona_alta(Persona array[], int size,int *contadorId);
int persona_baja(Persona array[], int sizeArray);
int persona_bajaValorRepetidoInt(Persona array[], int sizeArray, int valorBuscado);
int persona_modificar(Persona array[], int sizeArray);
int persona_ordenarPorDobleCriterio(Persona array[],int size, int orderFirst, int orderSecond);
int persona_listar(Persona array[], int size);
void rangoEdad (int edad,int size);
char imprimirRangos(char Rangos [],int size);

