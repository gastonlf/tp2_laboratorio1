#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#define EMPL 3


/**
 * \brief Rellena con -1 los lugares vacios del array
 * \param recibe la estructutura
 * \param recibe la cantidad de personas en el array
 * \param recibe el valor que será asignado en los lugares vacios
 * \return Vacio/void
 *
 */

void initEmployees (eEmployee emptyInput[], int sizeArray, int value)
{
    int i;
        for (i = 0; i < sizeArray; i++)
        {
            emptyInput[i].isEmpty = value;
        }
}
/**
 * \brief Busca un espacio libre
 * \param recibe la estructutura
 * \param recibe el tamaño del array
 * \param valor que debe buscar
 * \return la posicion si hay lugar libre. -1 si esta ocupado.
 *
 */

int buscarEspacio (eEmployee emptyInput[],int tamanio,int valor)
{
        int i;

        for (i=0;i<tamanio;i++)
        {
                if (emptyInput[i].isEmpty == valor)
                {
                return i;
                }
        }
        return -1;
}
/**
 * \brief Rellena los campos en la posicion libre.
 * \param mensaje a ser mostrado.
 * \param recibe la estructura.
 * \param recibe el tamaño del array
 * \return void.
 *
 */

void altas(char msg[],eEmployee employees[],int tam)
{
    char auxNombre  [51];
    char auxApe     [51];

    char auxSectorString[51];
    char auxSalaryString[51];

    int auxSector;
    int auxSalario;

    int lugarLibre;

    lugarLibre = buscarEspacio(employees,tam,-1);
                    do{
                        if (lugarLibre==-1)
                        {
                            printf("No hay espacio libre.\n");
                            break;
                        }
                        printf("ALTA\n");


                        if (!getStringLetras("Ingrese Nombre: ",auxNombre))
                        {
                            printf("No es valido.\n");
                            break;
                        }
                        if (!getStringLetras("Ingrese Apellido: ",auxApe))
                        {
                            printf("No es valido.\n");
                            break;
                        }

                        if (!getStringSalario("Ingrese Salario: ",auxSalaryString))
                        {
                            printf("No es valido.\n");
                            break;
                        }

                        auxSalario = atof (auxSalaryString);

                        if (!getStringNumeros("Sector 1- MANTENIMIENTO 2- RR.HH 3- IT 4- LIMPIEZA: ",auxSectorString))
                        {
                            printf("No es valido.\n");
                            break;
                        }

                        auxSector = atoi (auxSectorString);

                        strcpy(employees[lugarLibre].name,auxNombre);
                        strcpy(employees[lugarLibre].lastName,auxApe);

                        employees[lugarLibre].sector  = auxSector;
                        employees[lugarLibre].salary  = auxSalario;

                        employees[lugarLibre].id = lugarLibre;
                        employees[lugarLibre].isEmpty = 0;
}while(lugarLibre==-1);
}
/**
 * \brief Modifica una posicion del array de estructuras.
 * \param mensaje Es el mensaje a ser mostrado
 * \param recibe el array de estructuras
 * \param recibe la cantidad de personas
 * \return Devuelve 0 si se pudo modificar, 1 si no se encontró.
 *
 */

int modificar (char msg[],eEmployee employees [],int tam)
{
    int auxID;
    char auxNombre  [51];
    char auxApe     [51];

    char auxSectorString[51];
    char auxSalaryString[51];

    int auxSector;
    int auxSalario;
    int i;
                auxID = getInt("Indique su ID para modificar datos: ");

                for (i=0;i<tam;i++)
                {
                    if (employees[i].id==auxID)
                    {
                        printf("ALTA\n");
                        if (!getStringLetras("Ingrese Nombre: ",auxNombre))
                        {
                            printf("No es valido.\n");
                            break;
                        }
                        if (!getStringLetras("Ingrese Apellido: ",auxApe))
                        {
                            printf("No es valido.\n");
                            break;
                        }

                        if (!getStringSalario("Ingrese Salario: ",auxSalaryString))
                        {
                            printf("No es valido.\n");
                            break;
                        }

                        auxSalario = atof (auxSalaryString);

                        if (!getStringNumeros("Sector 1- MANTENIMIENTO 2- RR.HH 3- IT 4- LIMPIEZA: ",auxSectorString))
                        {
                            printf("No es valido.\n");
                            break;
                        }
                        auxSector = atoi (auxSectorString);

                        strcpy(employees[i].name,auxNombre);
                        strcpy(employees[i].lastName,auxApe);
                        employees[i].sector = auxSector;

                        employees[i].salary  = auxSalario;
                        employees[i].id = i;
                        employees[i].isEmpty = 0;

                        return 0;
                        break;

                    }
                    }
                return 1;
}
/**
 * \brief Borra de manera lógica una posicion del array
 * \param mensaje a ser mostrado
 * \param recibe el array de estructuras
 * \param el tamaño del array
 * \return retorna 0 si se pudo dar de baja, 1 si no se encuentra.
 *
 */

int baja (char msg [],eEmployee employees [],int tam)
{
    int auxID;
    auxID = getInt("Indique ID a dar de baja.:  ");
        for (int i=0;i<tam;i++)
            {      if(employees[i].id==auxID)
                    {
                        employees[i].isEmpty = -1;
                        return 0;
                    }
            }
            return 1;
}
/**
 * \brief Muestra los datos guardados
 * \param mensaje a ser mostrado
 * \param recibe el array de estructuras
 * \param cantidad de personas del array
 * \return vacio/void
 *
 */
void mostrar (char msg [],eEmployee employees[], int tam)
{
    int i;
    printf("\n*** NOMBRE\t *** APELLIDO\t *** SALARIO\t *** SECTOR\t *** ID\t \n");
    for (i=0; i<tam;i++)
    {
        if(employees[i].isEmpty>-1)
            {
    printf("\n \t %s \t %s \t %.2f \t %i \t %i",employees[i].name,employees[i].lastName,employees[i].salary,employees[i].sector,employees[i].id);
            }
    }
}
/**
 * \brief Obtiene una cadena de caracteres
 * \param mensaje Es el mensaje a ser mostrado
 * \param el dato de la cadena de caracteres.
 * \return void/vacio
 *
 */

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf ("%s", input);

}
/**
 * \brief obtiene un numero entero
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */

int getInt (char mensaje [])
{
    int auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%i",&auxiliar);
    return auxiliar;
}
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param donde se cargará el texto ingresado
 * \return 1 si el texto ingresado contiene solo letras. 0 por el contrario
 */
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
/**
 * \brief Comrpueba que el texto ingresado contenga solo letras
 * \param recibe la cadena
 * \return 0 si son letras. 1 Si contiene mas caracteres
 *
 */

int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}
/**
 * \brief devuelve un flotante
 * \param mensaje a ser mostrado
 * \return El numero ingresado por el usuario
 *
 */

float getFloat(char msg[])
{
    float auxiliar;
    printf("%s",msg);
    scanf("%f",&auxiliar);
    return auxiliar;
}
/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */

int getStringSalario(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(isSalary(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param recibe la cadena
 * \return 0 si es numerico, 1 en caso contrario
 */

int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '1' || str[i] > '4')
           return 0;
       i++;
   }
   return 1;
}
/**
 * \brief Si el salario es flotante y tiene punto
 * \param mensaje Es el mensaje a ser mostrado
 * \return 1 si es un numero con .
 *
 */

int isSalary(char str[])
{
   int i=0;
   int tienePunto=0;
   while(str[i] != '\0')
   {
       if((str[i] != '.') && (str[i] < '0' || str[i] > '9'))
       {

          return 0;
       }
       if(str[i] == '.')
        {
            tienePunto++;
        }
        i++;

       }
   if(tienePunto==1) // debe tener un guion
     {
         return 1;
     }

    return 1;
}
