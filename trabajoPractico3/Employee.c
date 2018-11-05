#include "Employee.h"
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

/** \brief Valida el nombre.
 *
 * \param Con un if validamos que solo haya letras. Con el For pasamos por los diferentes elementos del array.
 * \return return 1 si esta bien.
 *
 */

static int isValidNombre(char* pBuffer,int limite)
{
    int retorno = 0;
    int i;
    if(pBuffer != NULL && limite > 0 && strlen(pBuffer)>0)
    {
        retorno = 1;
        for(i=0;i < limite && pBuffer[i] != '\0';i++)
        {
            if(tolower(pBuffer[i]) < 'a' || tolower(pBuffer[i]) > 'z')
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Valida el int.
 *
 * \param Con un if validamos que solo haya numeros. Con el For pasamos por los diferentes elementos del array.
 * \return return 1 si esta bien.
 *
 */

static int isValidInt(char* pBuffer,int limite)
{
    int retorno = 0;
    int i;
    if(pBuffer != NULL && limite > 0 && strlen(pBuffer)>0)
    {
        retorno = 1;
        for(i=0;i < limite && pBuffer[i] != '\0';i++)
        {
            if(pBuffer[i] < '0' || pBuffer[i] > '9')
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Reservo memoria para un nuevo empleado
 *
 * \param Declaro un puntero de empleado con la palabra reservada this.
 * \param a this le asigno la funcion malloc que nos dara una posicion de memoria para empleado.
 * \return this
 *
 */

Employee* Employee_new()
{
    Employee* this;
    this = malloc(sizeof(Employee));
    return this;
}

/** \brief libera memoria
 *
 * \param utilizo un if para validar que this no este vacio.
 * \param si no esta vacio se libera la memoria.
 * \return 0
 *
 */

int Employee_delete(Employee* this)
{
    int retorno = 1;
    if(this != NULL)
    {
         free(this);
         retorno = 0;
    }
    return retorno;
}

/** \brief Cargo un empleado con sus parametros
 *
 * \param Les pasamos a la funcion string para el id, nombre, horastrabajas y sueldo.
 * \param Declaro un puntero de empleado con la palabra reservada this.
 * \param a this le asigno la funcion employee_new que no dara una posicion de memoria.
 * \param con un if valido que las funciones esten bien. En caso de no estarlo se libera la posicion de memoria.
 * \return this(el empleado con parametros). O NULL si esta mal.
 *
 */

Employee* employee_newConParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)//le ponemos Str porque son todos string.
{
    Employee* this;
    this = Employee_new();

    if((isValidNombre(nombreStr,LEN)) &&
        isValidInt(horasTrabajadasStr,LEN)&&
        isValidInt(sueldoStr,LEN))
    {
        Employee_setId(this,atoi(idStr));
        Employee_setNombre(this,nombreStr);
        Employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr));
        Employee_setSueldo(this,atoi(sueldoStr));
        return this;
    }
    Employee_delete(this);
    return NULL;
}

/** \brief Genera un ID
 *
 * \param Declaro un variable estatica del tipo int llamado proximoId.
 * \param Con if y un else if valido que no sea NULL y el valor de id.
 * \return 0 si esta bien.
 *
 */

int Employee_setId(Employee* this,int id)
{
    int retorno=-1;
    static int proximoId=0;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->id = proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->id=proximoId;
        retorno=0;
    }
    else if(id==0)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    return retorno;
}

/** \brief Nos entrega el ID
 *
 * \param valida que el puntero de empleado que le pasamos no sea NULL.
 * \param y la direccion de memoria de id le asigna el valor de el id del empleado.
 * \return el id.
 *
 */

int Employee_getId(Employee* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id = this->id;
        retorno=0;
    }
    return retorno;
}

/** \brief Le setea un nombre al empleado
 *
 * \param le pasamos un puntero de empleado y un nombre.
 * \param con un if validamos que no sea NULL ni el puntero a empleado ni el nombre.
 * \param le pasamos con la funcion strcpy el nombre al puntero empleado.
 * \return 0 si esta bien.
 *
 */

int Employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

/** \brief Obtenemos el nombre
 *
 * \param con un if validamos que empleado y nombre no sean NULL
 * \param con la funcion strcpy le pasamos el nombre de empleado a el string nombre.
 * \return 0 si esta bien.
 *
 */

int Employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno = 0;
    }
    return retorno;
}

/** \brief Le setea las horas trabajadas al empleado.
 *
 * \param le pasamos un puntero de empleado y un int.
 * \param con un if validamos que no sea NULL el puntero a empleado.
 * \param le pasamos las horas al puntero empleado.
 * \return 0 si esta bien.
 *
 */

int Employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

/** \brief obtenemos las horas del empleado
 *
 * \param le pasamos un puntero de empleado y un int.
 * \param con un if validamos que no sea NULL empleado.
 * \param le pasamos al puntero de int las horas trabajas del empleado.
 * \return 0 si esta bien.
 *
 */

int Employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {

        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

/** \brief Seteamos el sueldo del empleado
 *
 * \param le pasamos un puntero de empleado y un float.
 * \param con un if validamos que no sea NULL empleado.
 * \param le pasamos al puntero de empleado el sueldo.
 * \return 0 si esta bien.
 *
 */

int Employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

/** \brief Obtenemos el sueldo del empleado
 *
 * \param le pasamos un puntero de empleado y un int.
 * \param con un if validamos que no sea NULL empleado.
 * \param le pasamos al int el sueldo de empleado.
 * \return 0 si esta bien.
 *
 */

int Employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo = this->sueldo;
        retorno=0;
    }
    return retorno;
}

/** \brief Ordenamos nombres.
 *
 * \param le pasamos dos punteros de empleado.
 * \param con un if y strcmp comprobamos que los nombres sean igual o el primero mas chico que el segundo.
 * \param dependiendo el caso le paso a retorno un valor.
 * \return retorno.
 *
 */

int employee_SortNombre(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployeeUno;
    Employee* auxEmployeeDos;
    int retorno = -1;
    int i;

    if(pArrayListEmployee!=NULL)
    {
        retorno = 0;
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            auxEmployeeUno = ll_get(pArrayListEmployee,i);
            auxEmployeeDos = ll_get(pArrayListEmployee,i+1);
            if(auxEmployeeUno!= NULL && auxEmployeeDos !=NULL)
            {
                ll_sort(pArrayListEmployee,employee_criterioSortNombre,1);
            }
        }
    }
    return retorno;
}

int employee_criterioSortNombre(void* thisA,void* thisB)
{
    char nombreA[LEN];
    char nombreB[LEN];
    int retorno = 0;
    Employee_getNombre(thisA,nombreA);
    Employee_getNombre(thisB,nombreB);

    if(strcmp(nombreA,nombreB)>0)
    {
        retorno = 1;
    }
    else if(strcmp(nombreA,nombreB)<0)
    {
        retorno = -1;
    }
    return retorno;
}

/** \brief Genera un empleado Nuevo.
 *
 * \param Con un if validamos que lo que ingrese el usuario este bien.
 * \param declaramos un puntero a empleado y le asignamos la funcion employee_newConParametros para cargar al empleado.
 * \param con un if validamos que este cargado.
 * \return return this.
 *
 */

Employee* employee_alta(LinkedList* pArrayListEmployee)//le ponemos Str porque son todos string.
{
    Employee* this = NULL;
    char idStr[LEN] = "0";
    char nombreStr[LEN];
    char sueldoStr[LEN];
    char horasTrabajadasStr[LEN];

    if( !utn_getNombre(nombreStr,LEN,"\nIngrese el nombre: "," Nombre invalido.",2) &&
        !utn_getSoloInt(sueldoStr,LEN,"\nIngrese el sueldo: "," Sueldo Invalido.",2) &&
        !utn_getSoloInt(horasTrabajadasStr,LEN,"\nIngrese las horas trabajadas: "," Horas invalidas.",2))
    {
        this = employee_newConParametros(idStr,nombreStr,horasTrabajadasStr,sueldoStr);
    }
    if(this != NULL)
    {
        ll_add(pArrayListEmployee,this);
        printf("\nEmpleado cargado correctamente");
        return this;
    }
    Employee_delete(this);
    printf("\nFallo la carga del empleado");
    return NULL;
}

/** \brief Modifica los datos del empleado.
 *
 * \param pedimos un id al usuario y recorremos con un for toda la lista de empleados y los vamos obteniendo con un ll_get.
 * \param Si coincide el id del usuario con el del empleado entra al switch para elegir alguna modificacion.
 * \return 0 si esta bien.
 *
 */

int employee_edit(LinkedList* pArrayListEmployee)
{
    int option;
    char auxId[LEN];
    int auxId2;
    char sueldo[LEN];
    char horasTrabajadas[LEN];
    char nombre[LEN];
    int retorno = -1;
    int i;
    int id;
    Employee* this;

    utn_getSoloInt(auxId,LEN,"Ingrese un ID: ","ID invalido. ",2);
    auxId2 = atoi(auxId);

    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
      this = ll_get(pArrayListEmployee,i);
      Employee_getId(this,&id);
      if(id == auxId2)
      {
        break;
      }
    }
    if(id != auxId2)
    {
        printf("Empleado no encontrado");
        return retorno;
    }

    do{
        printf("MENU:\n");
        printf("\n1.Modificar nombre\n");
        printf("2.Modificar sueldo\n");
        printf("3.Modificar horas\n");
        printf("4.Salir\n");
        utn_ScanInt("Ingrese una opcion: ",&option);

        switch(option)
        {
            case 1:
                if(!utn_getNombre(nombre,LEN,"Ingrese nombre: "," Nombre invalido.",2))
                {
                    Employee_setNombre(this,nombre);
                    printf("\nDatos del empleado modificados.");
                    retorno = 0;
                }
                else
                {
                    printf("\nDatos mal ingresados no se puede hacer la modificacion");
                }
                break;
            case 2:
                if(!utn_getSoloInt(sueldo,LEN,"Ingrese sueldo: "," Sueldo invalido.",2))
                {
                    Employee_setSueldo(this,atoi(sueldo));
                    printf("\nDatos del empleado modificados.");
                    retorno = 0;
                }
                else
                {
                    printf("\nDatos mal ingresados no se puede hacer la modificacion");
                }
                break;
            case 3:
                if(!utn_getSoloInt(horasTrabajadas,LEN,"Ingrese horas: ","horas invalidas.",2))
                {
                    Employee_setHorasTrabajadas(this,atoi(horasTrabajadas));
                    printf("\nDatos del empleado modificados.");
                    retorno = 0;
                }
                else
                {
                    printf("\nDatos mal ingresados no se puede hacer la modificacion");
                }
                break;
            case 4:
                printf("Hasta Luego");
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
    while(option!=4);
    return retorno;
}

/** \brief Da de baja al empleado.
 *
 * \param pedimos un id al usuario y recorremos con un for toda la lista de empleados y los vamos obteniendo con un ll_get.
 * \param Si coincide el id del usuario con el del empleado se sale del for a this se le asigna el empleado.
 * \param con la funcion ll_indexOf obtenemos el indice y se lo pasamos a ll_pop para eliminar al empleado.
 * \return 0 si esta bien.
 *
 */

int Employee_remove(LinkedList* pArrayListEmployee)
{
    char auxId[LEN];
    char option[LEN];
    int auxId2;
    int retorno = -1;
    int i;
    int id;
    int indice;
    Employee* this = NULL;
    utn_getSoloInt(auxId,LEN,"Ingrese un ID: "," ID invalido. ",2);
    auxId2 = atoi(auxId);

    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        this = ll_get(pArrayListEmployee,i);
        Employee_getId(this,&id);
        if(id == auxId2)
        {
            utn_getNombre(option,LEN,"\nEsta seguro que desea realizar la baja. Escriba si o no: ","\nopcion invalida.",2);
            if(strcmp(option,"si") == 0)
            {
                indice = ll_indexOf(pArrayListEmployee,this);
                ll_pop(pArrayListEmployee,indice);
                printf("\nEmpleado dado de baja.");
                retorno = 0;
                break;
            }
            else
            {
                printf("Baja no realizada");
            }
        }
    }
    if(id != auxId2)
    {
        printf("\nEmpleado no encontrado.");
    }
    return retorno;
}
