#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"
#include "utn.h"
#define CANTIDAD_DE_EMPLEADOS 1000


/**
* \brief ABM, se realizan altas, bajas y modificaciones y se muestran a los empleados.
* \param Declaramos la variable flag para saber si se esta pasando por el alta. Y varios if en los diferentes case para validar.
* \param Se utiliza un "do" para que lo haga al menos una vez y si se cumple la condicion del "while" se repite.
* \param Dentro del "do" se utiliza un printf para que el usuario pueda ver las opciones del menu y se le pide que seleccione una.
* \param La funcion scanInt es para que se ingrese el numero de la opcion.
* \param Switch, una vez ingresada la opcion se entra en uno de los "case:" de este. Sino esta muestra un mensaje de error.
* \return 0 al terminar el programa.
*/

int main()
{
    Empleados array[CANTIDAD_DE_EMPLEADOS];
    empleados_Init(array,CANTIDAD_DE_EMPLEADOS);
    int opcion,flag1=0;

    do{

        printf("MENU:\n");
        printf("\n1.Alta de empleado\n");
        printf("2.Baja de empleado\n");
        printf("3.Modificar empleado\n");
        printf("4.Mostrar empleados\n");
        printf("5.Salir\n");
        utn_ScanInt("Ingrese una opcion: ",&opcion);

        switch (opcion)
        {
            case 1:
                    if(!empleados_Alta(array,CANTIDAD_DE_EMPLEADOS))
                    {
                    flag1++;
                    printf("\nEmpleado dado de alta");
                    }
                    else
                    {
                        printf("Datos erroneos para cargar empleado.");
                    }
                    break;
            case 2:
                if(flag1)
                {
                    if(!empleados_Baja(array,CANTIDAD_DE_EMPLEADOS))
                    {
                            flag1--;
                            printf("\nEmpleado dado de baja");
                    }
                }
                else
                {
                    printf("\nNo hay empleados para dar de baja");
                }
                break;
            case 3:
                if(flag1)
                {
                    if(empleado_Modificar(array,CANTIDAD_DE_EMPLEADOS)==0)
                       {
                            printf("\nDatos del Empleado Modificados");
                       }
                }
                else
                {
                    printf("\nFaltan empleados para modificar");
                }
                break;
            case 4:
                if(flag1)
                {
                    empleados_ordenar(array,CANTIDAD_DE_EMPLEADOS);
                    empleados_Mostrar(array,CANTIDAD_DE_EMPLEADOS);
                }
                else
                {
                    printf("\nFaltan datos");
                }
                break;
            case 5:
                printf("\nHasta Luego");
                break;
            default:
                printf("Opcion invalida.");
                break;
        }
        __fpurge(stdin); //para limpiar el buffer.
        printf("\nIngrese ENTER para continuar");
        getchar(); //te freeza hasta que apretas una letra.
        system("clear"); //limpia la pantalla
    }
    while(opcion!=5);
    return 0;
}
