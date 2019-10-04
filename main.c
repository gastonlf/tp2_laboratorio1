#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#define EMPL 3

int main()
{   eEmployee employees [EMPL];
    int menu = 0;
    int res;

    initEmployees (employees,EMPL,-1);
    do{
        menu = getInt("\n1- ALTA \n2- MODIFICAR \n3- BAJA \n4- INFORMAR \n5- SALIR\n ");
        switch (menu)
        {
            case 1:system ("cls");
                altas("ALTAS\n",employees,EMPL);
                break;
            case 2:
                system ("cls");
                for (int i=0; i<EMPL;i++)
                {       if (employees[i].isEmpty>-1)
                    {
                   res = modificar("MODIFICAR\n",employees,EMPL);
                    if (res==0)
                    {
                        printf("Se modifico correctamente.\n");
                        break;
                    }
                    else
                    {
                        printf("No hay resultados.\n");
                    }
                    break;
                    }
                        else
                        {
                            printf("No se puede ingresar porque no hay datos cargados.\n");
                            break;
                        }
                }

                break;
            case 3:system("cls");
                    for (int i=0; i<EMPL;i++)
                {       if (employees[i].isEmpty>-1)
                    {
                            res = baja("BAJA: \n",employees,EMPL);
                            if (res==0)
                            {
                                printf("Se borro correctamente.\n");
                            }
                            else
                            {
                                printf("No hay resultados.\n");
                            }
                            break;
                    }
                        else
                    {
                        printf("No se puede ingresar porque no hay datos cargados.\n");
                        break;
                    }
                }
                break;
            case 4:system("cls");
                    for (int i=0; i<EMPL;i++)
                {     if (employees[i].isEmpty>-1)
                    {
                        mostrar("MOSTRAR: \n",employees,EMPL);
                        break;
                    }
                    else
                    {
                        printf("No se puede ingresar porque no hay datos cargados.\n");
                        break;
                    }
                }
            }
        }while(menu!=5);

          return 0;

     }


