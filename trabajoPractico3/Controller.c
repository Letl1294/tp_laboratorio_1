#include <stdio_ext.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"
#include <ctype.h>
#include "utn.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param le pasamos el patch del archivo, y un puntero de LinkedList.
 * \param Declaramos un puntero a FILE llamado pArchivo y le asignamos la funcion fopen(que abre el archivo en modo lectura).
 * \param validamos que no sea NULL y llamamos a la funcion parser para cargar los datos a empleado.
 * \param Con la funcion fclose lo cierra.
 * \return 0
 *
 */

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno = -1;
    pArchivo = fopen(path,"r");
    if(pArchivo!=NULL)
    {
        parser_EmployeeFromText(pArchivo,pArrayListEmployee);
        retorno = 0;
    }
    fclose(pArchivo);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo databin.csv (modo binario).
 *
 * \param le pasamos el patch del archivo, y un puntero de LinkedList.
 * \param Declaramos un puntero a FILE llamado pArchivo y le asignamos la funcion fopen(que abre el archivo en modo lectura).
 * \param validamos que no sea NULL y llamamos a la funcion parser para cargar los datos a empleado.
 * \param Con la funcion fclose lo cierra.
 * \return 0
 *
 */

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno = -1;
    pArchivo = fopen(path,"rb");
    if(pArchivo!= NULL)
    {
        parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);
        retorno = 0;
    }
    fclose(pArchivo);
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param le pasamos un puntero de LinkedList.
 * \param llama a la funcion para agregar empleados y valida con un if que se haya realizado correctamente.
 * \return 0 si esta bien
 *
 */

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(!employee_alta(pArrayListEmployee))
    {
      retorno = 0;
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param le pasamos un puntero de LinkedList.
 * \param llama a la funcion para editar empleados y valida con un if que se haya realizado correctamente.
 * \return int
 *
 */

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(!employee_edit(pArrayListEmployee))
    {
        retorno = 0;
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param llama a la funcion para eliminar empleado y valida que haya salido bien.
 * \return 0 si esta bien.
 *
 */

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(!Employee_remove(pArrayListEmployee))
    {
        retorno = 0;
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param Con un for recorremos toda la linkedList de empleados.
 * \param Utilizamos la funcion ll_get y la asignamos a un puntero de empleado.
 * \param Validamos con un if que sea distinta a null y llamamos a la funcion controller_show para mostrarla.
 * \return int
 *
 */

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    Employee* pEmpleado;

    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        pEmpleado = ll_get(pArrayListEmployee,i);
        if(pEmpleado != NULL)
        {
            controller_show(pEmpleado);
            retorno = 0;
        }
    }
    printf("\nSize de la lista: %d", ll_len(pArrayListEmployee));
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param con un if valida que la linked lista no sea NULL.
 * \param Se llama a la funcion ordenar y si retorna 0 se muestra un mensaje.
 * \return 0 Si esta bien.
 *
 */

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        if(!employee_SortNombre(pArrayListEmployee))
        {
            retorno = 0;
            printf("\nLista de empleados ordenada.");
        }
        else
        {
            printf("\nNo se pudo ordenar.");
        }
    }
return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv(modo texto).
 *
 * \param con un if validamos que el archivo no sea null.
 * \param llamamos a la funcion parser_saveEmployeeToText para guardar los datos en texto.
 * \return 0 si esta bien.
 *
 */

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno = -1;
    pArchivo = fopen(path,"w");
    if(pArchivo!= NULL)
    {
        parser_saveEmployeeToText(pArchivo,pArrayListEmployee);
        printf("\nEmpleados guardados correctamente\n");
        retorno = 0;
    }
    fclose(pArchivo);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo databin.csv (modo binario).
 *
 * \param con un if validamos que el archivo no sea null.
 * \param llamamos a la funcion parser_saveEmployeeToBinary para guardar los datos en binario.
 * \return 0 si esta bien.
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno = -1;
    pArchivo = fopen(path,"wb");
    if(pArchivo!= NULL)
    {
        parser_saveEmployeeToBinary(pArchivo,pArrayListEmployee);
        printf("\nEmpleados guardados correctamente\n");
        retorno = 0;
    }
    fclose(pArchivo);
    return retorno;
}

/**
* \brief Muestra los datos de los empleados.
* \param utilizamos los get para obtener los datos y los mostramos con un printf.
*/

void controller_show(void* empleado)
{
    int id;
    char nombre[LEN];
    int horasTrabajadas;
    int sueldo;
    Employee_getId(empleado,&id);
    Employee_getNombre(empleado,nombre);
    Employee_getHorasTrabajadas(empleado,&horasTrabajadas);
    Employee_getSueldo(empleado,&sueldo);
    printf("ID: %d - Nombre: %s - horas Trabajadas: %d - Sueldo: %d\n",id,nombre,horasTrabajadas,sueldo);
}

/**
* \brief ABM, se realizan altas, bajas y modificaciones y se muestran a los empleados.
* \param Declaramos la variable flag para saber si se esta pasando por la carga desde un archivo.
* \param usamos los if en los diferentes case para validar.
* \param Se utiliza un "do" para que lo haga al menos una vez y si se cumple la condicion del "while" se repite.
* \param Dentro del "do" se utiliza un printf para que el usuario pueda ver las opciones del menu y se le pide que seleccione una.
* \param La funcion scanInt es para que se ingrese el numero de la opcion.
* \param Switch, una vez ingresada la opcion se entra en uno de los "case:" de este. Sino esta muestra un mensaje de error.
* \return 0 al terminar el programa.
*/

int controller_init()
{
    LinkedList* listaEmpleados = ll_newLinkedList();
    int opcion,flag1=0;

    do{

        printf("MENU:\n\n");
        printf("1.Cargar los datos de los empleados desde el archivo dataText.csv (modo texto)\n");
        printf("2.Cargar los datos de los empleados desde el archivo dataBin.csv (modo binario)\n");
        printf("3.Alta empleado\n");
        printf("4.Modificar empleado\n");
        printf("5.Borrar empleado\n");
        printf("6.Mostrar empleados\n");
        printf("7.Ordenar empleados\n");
        printf("8.Guardar los datos de los empleados en el archivo dataText.csv (modo texto)\n");
        printf("9.Guardar los datos de los empleados en el archivo dataBin.csv (modo binario)\n");
        printf("10.Salir\n");
        utn_ScanInt("Ingrese una opcion: ",&opcion);

        switch (opcion)
        {
            case 1:
                if(flag1)
                {
                    printf("\nLa carga ya se habia realizado");
                }
                else
                {
                    controller_loadFromText("data.csv",listaEmpleados);
                    printf("Carga realizada.");
                    flag1 = 1;
                }
                break;
            case 2:
                if(flag1)
                {
                    printf("\nLa carga ya se habia realizado");
                }
                else
                {
                    controller_loadFromBinary("databin.csv",listaEmpleados);
                    printf("Carga realizada.");
                    flag1 = 1;
                }
                break;
            case 3:
                if(flag1)
                {
                    controller_addEmployee(listaEmpleados);
                    break;
                }
                else
                {
                    printf("\nPrimero debe cargar los empleados desde texto.");
                }
                break;
            case 4:
                if(flag1)
                {
                    controller_editEmployee(listaEmpleados);
                }
                else
                {
                    printf("\nPrimero debe cargar los empleados desde texto.");
                }
                break;
            case 5:
                if(flag1)
                {
                    controller_removeEmployee(listaEmpleados);
                }
                else
                {
                    printf("\nPrimero debe cargar los empleados desde texto.");
                }
                break;
            case 6:
                if(flag1)
                {
                    controller_ListEmployee(listaEmpleados);
                }
                else
                {
                    printf("\nPrimero debe cargar los empleados.");
                }
                break;
            case 7:
                if(flag1)
                {
                    controller_sortEmployee(listaEmpleados);
                }
                else
                {
                    printf("\nPrimero debe cargar los empleados desde texto.");
                }
                break;
            case 8:
                if(flag1)
                {
                    controller_saveAsText("data.csv",listaEmpleados);
                }
                else
                {
                    printf("\nPrimero debe cargar los empleados.");
                }
                break;
            case 9:
                if(flag1)
                {
                    controller_saveAsBinary("databin.csv",listaEmpleados);
                }
                else
                {
                    printf("\nPrimero debe cargar los empleados.");
                }
                break;
            case 10:
                printf("\nHasta Luego\n");
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
    while(opcion!=10);
    return 0;
}
