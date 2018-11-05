#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param le pasamos a la funcion el path del archivo. Y un puntero de LinkedList.
 * \param con un if validamos que el archivo no sea NULL y con while y la funcion feof que salga cuando se llegue al final.
 * \param el fscanf se utiliza para la cabecera el que esta fuera del if valida las siguientes lineas.
 * \param llamamos a la funcion para cargar empleados y le pasamos los datos que sacamos del texto y...
 * \param Se la asignamos a pEmpleado con un if se valida si es distinta a NULL y se agrega a la linkedlist.
 * \return 0
 *
 */

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char bufferInt[LEN];
    char bufferNombre[LEN];
    char bufferHorasTrabajadas[LEN];
    char bufferSueldo[LEN];
    int retorno = -1;
    int flagOnce = 1;
    Employee* pEmpleado;

    if(pFile!= NULL)
    {
        while(!feof(pFile))
        {
            if(flagOnce)
            {
               flagOnce = 0;
               fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]n",
                                                bufferInt,
                                                bufferNombre,
                                                bufferHorasTrabajadas,
                                                bufferSueldo);
            }
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
                                                bufferInt,
                                                bufferNombre,
                                                bufferHorasTrabajadas,
                                                bufferSueldo);

            pEmpleado = employee_newConParametros(bufferInt,
                                                bufferNombre,
                                                bufferHorasTrabajadas,
                                                bufferSueldo);
            if(pEmpleado != NULL)
            {
                retorno = 0;
                ll_add(pArrayListEmployee,pEmpleado);
            }
        }
    }
    return retorno;
}

/** \brief Parsea los datos de los empleados desde el archivo databin.csv (modo binario).
 *
 * \param le pasamos a la funcion el path del archivo. Y un puntero de LinkedList.
 * \param con un if validamos que el archivo no sea NULL y con while y la funcion feof que salga cuando se llegue al final.
 * \param usamos la funcion fread para leer el archivo binario. Con un if validamos que el puntero a empleado no sea null.
 * \param Y se agrega a la linkedlist.
 * \return 0
 *
 */

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int totalLeido;
    Employee* pEmpleado;
    Employee* auxEmpleado = Employee_new();
    int id = 0;
    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            pEmpleado = Employee_new();
            totalLeido = fread(pEmpleado,sizeof(Employee),1,pFile);
            if(pEmpleado != NULL && totalLeido == 1)
            {
                retorno = 0;
                Employee_setId(auxEmpleado,id);
                ll_add(pArrayListEmployee,pEmpleado);
            }
        }
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param le pasamos a la funcion el path del archivo. Y un puntero de LinkedList.
 * \param con un if validamos que el archivo y la linkedlist no sean NULL y con for recorremos la linkedlist.
 * \param con la funcion "ll_get" obtenemos a cada empleado y despues con los get obtenemos sus datos.
 * \param con fprintf imprimimos en el texto a todos los empleados.
 * \return 0
 *
 */

int parser_saveEmployeeToText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* pEmployee;
    int len;
    int indice;
    int bufferId;
    char bufferName[LEN];
    int bufferHorasTrabajadas;
    int bufferSueldo;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);
        fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
        for(indice=0;indice<len;indice++)//Recorro todo el array hasta el LEN
        {
            pEmployee = ll_get(pArrayListEmployee,indice);
            if(pEmployee!=NULL)//Obtengo el elemento del array en posicion index
            {
                Employee_getNombre(pEmployee,bufferName);
                Employee_getHorasTrabajadas(pEmployee,&bufferHorasTrabajadas);
                Employee_getSueldo(pEmployee,&bufferSueldo);
                Employee_getId(pEmployee,&bufferId);
                fprintf(pFile,"%d,%s,%d,%d\n",bufferId,bufferName,bufferHorasTrabajadas,bufferSueldo);
                retorno = 0;
            }
        }
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo databin.csv (modo binario).
 *
 * \param le pasamos a la funcion el path del archivo. Y un puntero de LinkedList.
 * \param con un if validamos que el archivo y la linkedlist no sean NULL y con for recorremos la linkedlist.
 * \param con la funcion "ll_get" obtenemos a cada empleado.
 * \param con fwrite imprimimos en el texto a todos los empleados.
 * \return 0
 *
 */

int parser_saveEmployeeToBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    Employee* pEmpleado;

    if(pFile!=NULL && pArrayListEmployee != NULL)
    {
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            pEmpleado = ll_get(pArrayListEmployee,i);
            if(pEmpleado!=NULL)
            {
                fwrite(pEmpleado,sizeof(Employee),1,pFile);
                retorno = 0;
            }
        }
    }
    return retorno;
}
