#define NAME 51
#define LASTNAME 51
#define SECTOR 2
#define SALARY 8
#define ID 4

typedef struct
{
    int id;
    char name[NAME];
    char lastName[LASTNAME];
    float salary;
    int sector;
    int empleadoId;
    int isEmpty;
}Empleados;

int empleados_Alta(Empleados* array, int len);
int empleados_Init(Empleados* array, int len);
int empleados_Baja(Empleados* array, int len);
int empleado_Modificar(Empleados* array, int len);
int empleados_Mostrar(Empleados* array, int len);
int empleados_ordenar(Empleados* array, int len);
double empleados_Promedio(Empleados* array, int len);
int empleados_contador(Empleados* array, int len);
int empleados_SuperanPromedio(Empleados* array, int len);
