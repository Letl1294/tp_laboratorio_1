#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
#define LEN 1024

typedef struct
{
    int id;
    char nombre[LEN];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* Employee_new();
int Employee_delete(Employee* this);

Employee* employee_newConParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);

int Employee_setId(Employee* this,int id);
int Employee_getId(Employee* this,int* id);

int Employee_setNombre(Employee* this,char* nombre);
int Employee_getNombre(Employee* this,char* nombre);

int Employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int Employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int Employee_setSueldo(Employee* this,int sueldo);
int Employee_getSueldo(Employee* this,int* sueldo);

int employee_SortNombre(LinkedList* pArrayListEmployee);
int employee_criterioSortNombre(void* thisA,void* thisB);
Employee* employee_alta(LinkedList* pArrayListEmployee);
int employee_edit(LinkedList* pArrayListEmployee);
int Employee_remove(LinkedList* pArrayListEmployee, LinkedList* pArraylistEmployee2);
int Employee_deleteLinkedList(LinkedList* pArrayLinkedList);
Employee* Employee_getById(LinkedList* pArrayListEmployee,int idIngresado);
void* Employee_subList(LinkedList* pArrayLinkedList);
Employee* employee_clone(Employee* source);
int employee_reincorporar(void* pArrayListEmployee, void* pArrayListEmployee1);
#endif // EMPLOYEE_H_IN
