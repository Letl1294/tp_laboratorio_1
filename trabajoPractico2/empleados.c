#include "empleados.h"
#include "utn.h"
#include <string.h>
#include <stdio_ext.h>
#include <stdlib.h>

static int getLugarLibre(Empleados* array, int len);
static int getNextId();
static int getIndice(Empleados* array,int len);

/** \brief obtiene un indice que este vacio.
 *
 * \param Con un if validamos que este vacio.
 * \return la posicion del array.
 *
 */

static int getLugarLibre(Empleados* array, int len)
{
    int retorno=-1;
    int i;
    if(array!= NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(array[i].isEmpty)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Inicializamos a los empleados.
 *
 * \param Utilizamos la funcion  getIndice para ingresar el indice.
 * \param Con un if validamos y le agregamos un 1 a cada posicion del array indicando que esta vacia.
 * \return retorno.
 *
 */

int empleados_Init(Empleados* array, int len)
{
    int retorno=-1;
    int i;
    if(array!= NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            array[i].isEmpty = 1;
        }
        retorno = 0;
    }
    return retorno;
}

/** \brief Damos de alta.
 *
 * \param Utilizamos la funcion  getLugarlibre para posicionarnos en un indice vacio.
 * \param Con un if validamos que los valores sean correctos.
 * \return 0 si esta bien.
 *
 */

int empleados_Alta(Empleados* array, int len)
{
    int retorno = -1;
    int indice;
    char name[NAME];
    char lastName[LASTNAME];
    float salary;
    int sector;

    indice = getLugarLibre(array,len);

    if(array != NULL && len > 0 &&
       indice >= 0 && indice < len)
       {
         if(!utn_getNombre(name,NAME,"Ingrese Nombre: ","Nombre invalido.",2) &&
            !utn_getNombre(lastName,LASTNAME,"ingrese Apellido: ","Apellido invalido.",2) &&
            !utn_getSoloFloat(&salary,SALARY,"Ingrese Salario: ","Salario Invalido.",2) &&
            !utn_getSoloInt(&sector,SECTOR,"Ingrese sector: ","Sector invalido.",2))
            {
                strncpy(array[indice].name,name,NAME);
                strncpy(array[indice].lastName,lastName,LASTNAME);
                array[indice].sector = sector;
                array[indice].salary = salary;
                array[indice].isEmpty = 0;
                array[indice].empleadoId = getNextId();
                retorno = 0;
            }
       }
    return retorno;
}

/** \brief Genera el ID.
 *
 * \param Utilizamos un static int para guardar el ID.
 * \return el ID.
 *
 */

static int getNextId()
{
    static int ultimoId=-1;
    ultimoId++;
    return ultimoId;
}

/** \brief Damos de baja.
 *
 * \param Utilizamos la funcion  getIndice para ingresar el indice.
 * \param Con un if validamos que este cargado y los damos de baja.sino nos muestra un mensaje.
 * \return retorno.
 *
 */

int empleados_Baja(Empleados* array, int len)
{
    int retorno = 1;
    int indice;
    indice=getIndice(array,len);

     if(array != NULL && len > 0 &&
        indice >= 0 && indice < len
        && array[indice].isEmpty==0)
        {
            array[indice].isEmpty=1;
            retorno = 0;
        }
        else
        {
            printf("No hay carga en el ID indicado");
            retorno = 1;
        }
return retorno;
}

/** \brief toma un indice.
 *
 * \param Utilizamos la funcion  getIndice para ingresar el indice.
 * \param Con un if validamos y utilizamos un switch para modificar un dato del array.
 * \return retorno.
 *
 */

int empleado_Modificar(Empleados* array, int len)
{
    int retorno = -1;
    int indice;
    int numero;
    char name[NAME];
    char lastName[LASTNAME];
    float salary;
    int sector;

    indice = getIndice(array,len);

    if( array != NULL && len > 0 &&
        indice >= 0 && indice < len &&
        (!array[indice].isEmpty))
    {
        printf("1.Nombre\n2.Apellido\n3.Salario\n4.Sector\n");
        utn_ScanInt("Ingrese una opcion: ",&numero);
        switch(numero)
        {
            case 1:
            utn_getNombre(name,NAME,"Ingrese Nombre: ","Nombre invalido.",2);
            strncpy(array[indice].name,name,NAME);
            break;
            case 2:
            utn_getNombre(lastName,LASTNAME,"Ingrese Nombre: ","Nombre invalido.",2);
            strncpy(array[indice].lastName,lastName,LASTNAME);
            break;
            case 3:
            utn_getSoloFloat(&salary,SALARY,"Ingrese Salario: ","Salario Invalido.",2);
            array[indice].salary = salary;
            break;
            case 4:
            utn_getSoloInt(&sector,SECTOR,"Ingrese sector: ","Sector invalido.",2);
            array[indice].sector = sector;
            break;
            retorno = 0;
        }
    }
        else if(array[indice].isEmpty)
        {
            printf("No hay carga en ese indice");
        }
        return retorno;
}

/** \brief toma un indice.
 *
 * \param se declaran las variables para almacenar los valores de promedio, salarios y salios que superan promedio.
 * \param Con un if utilizamos la funcion para cargar el ID con el for pasamos por los elementos del array.
 * \param Y con el if validamos que este cargado array en esa posicion.
 * \return la posicion del indice.
 *
 */

static int getIndice(Empleados* array,int len)
{
   int retorno=-1;
   int i;
   int id;

   if(utn_getSoloInt(&id,ID,"Ingrese el ID: ","ID invalido.",2)==0)
   {
       for(i=0;i<len;i++)
       {
           if(array[i].empleadoId==id)
            {
                retorno=i;
                break;
            }
       }
   }
   return retorno;
}

/** \brief Muestra los valores.
 *
 * \param se declaran las variables para almacenar los valores de promedio, salarios y salios que superan promedio.
 * \param Con un for pasamos por los elementos del array. Y con el if validamos que este cargado array en esa posicion.
 * \param Y los mostramos con un printf.
 * \return void
 *
 */

int empleados_Mostrar(Empleados* array, int len)
{
    int retorno = -1;
    int i;
    int salarios = empleados_contador(array,len);
    double promedio = empleados_Promedio(array,len);
    int supPromedio = empleados_SuperanPromedio(array,len);

    for(i=0;i<len;i++)
    {
         if(array[i].isEmpty==0)
         {
             printf("\nNombre: %s - Apellido: %s - Salario: %.2f - Sector: %d - ID: %d",array[i].name,array[i].lastName,array[i].salary,array[i].sector,array[i].empleadoId);
             retorno = 0;
         }
    }
    printf("\nTotal de salarios: %d - Promedio: %.2f - Salarios que superan promedio: %d",salarios,promedio,supPromedio);
    return retorno;
}

/** \brief ordena el array por apellidos y sector.
 *
 * \param Con un IF validamos que el array no este vacio.
 * \param y utilizamos dos for y un if adentro para validar que apellido va primero con el strcmp.
 * \param se realiza lo mismo con el segundo if dentro del for para validar tambien que sector es menor.
 * \return retorno.
 *
 */

int empleados_ordenar(Empleados* array, int len)
{
    Empleados auxiliar;
    int retorno = -1;
    int i,j;

    if(array != NULL && len > 0)
    {
        retorno = 0;

        for(i = 0; i < len; i++)
        {
            for(j=i+1;j<len;j++)
            {
                if (strcmp(array[i].lastName,array[j].lastName) > 0)
                {
                    auxiliar = array[i];
                    array[i] = array[j];
                    array[j] = auxiliar;
                }
                else if(!(strcmp(array[i].lastName,array[j].lastName)) && array[i].sector > array[j].sector)
                {
                    auxiliar = array[i];
                    array[i] = array[j];
                    array[j] = auxiliar;
                }
            }
        }
    }
    return retorno;
}

/** \brief Calcula el promedio.
 *
 * \param se declaran las variables double acumulador para almacenar el resultado el total.
 * \param Con el contador contamos los salarios y el resultado se divide por el contador.
 * \return promedio.
 *
 */

double empleados_Promedio(Empleados* array, int len)
{
    int i;
    double acumulador = 0;
    int contador = 0;
    double promedio;

    for(i=0;i<len;i++)
    {
        if(array[i].isEmpty==0)
        {
            acumulador = +array[i].salary;
            contador++;
        }
    }
    promedio = acumulador/contador;
    return promedio;
}

/** \brief Calcula el total de salarios.
 *
 * \param se declaran las variable entera contador para almacenar el resultado el total.
 * \param Con el contador contamos los salarios. Utilizando el If para validar que este cargado array en esa posicion.
 * \return contador
 *
 */

int empleados_contador(Empleados* array, int len)
{
    int i;
    int contador = 0;

    for(i=0;i<len;i++)
    {
        if(array[i].isEmpty==0)
        {
            contador++;
        }
    }
    return contador;
}

/** \brief Calcula los salarios que superan el promedio.
 *
 * \param se declaran las variable entera contador para almacenar el resultado el total.
 * \param Con el contador contamos los salarios. Con un if validamos que salario sea mayor a promedio.
 * \return el total de salarios que superan el promedio.
 *
 */

int empleados_SuperanPromedio(Empleados* array, int len)
{
    double promedio;
    int contador=0;
    int i;

    promedio = empleados_Promedio(array,len);

    for(i=0;i<len;i++)
    {
        if(array[i].isEmpty==0 && array[i].salary>promedio)
        {
            contador++;
        }
    }
    return contador;
}
