#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "calculadora.h"

/**
* \brief El usuario ingresa dos operandos, se realizan las operaciones y se devuelven los resultados.
* \param Declaramos 4 variables llamadas flag para saber si se esta pasando por las diferentes case del Switch.
* \param Las variables Float numeroUno,numeroDos, y todas las de resultados son para guardar los datos de las operaciones.
* \param Se utiliza un "do" para que lo haga al menos una vez y si se cumple la condicion del "while" se repite.
* \param Dentro del "do" se utiliza un printf para que el usuario pueda ver las opciones del menu y se le pide que seleccione una.
* \param El scanf es para que se ingrese el numero de la opcion.
* \param Switch, una vez ingresada la opcion se entra en uno de los "case:" de este. Sino esta muestra un mensaje de error.
* \return 0 al terminar el programa.
*/

int main()
{
    int flag=1,flag1=0,flag2=0,flag3=0,opcion;
    float numeroUno=0,numeroDos=0,resultadoSuma,resultadoResta,resultadoDivision,resultadoMultiplicacion,resultadoFactorialUno;
    float resultadoFactorialDos;
    do{
        printf("1.Ingrese 1er operando: ""%.2f",numeroUno);
        printf("\n2.Ingrese 2do operando: ""%.2f",numeroDos);
        printf("\n3.Calcular operaciones\n");
        printf("4.Muestra resultado\n5.Para salir");
        printf("\nIngrese una opcion del menu: ");
        scanf("%d",&opcion);
        __fpurge(stdin); //Para limpiar el buffer.
        switch(opcion)
        {
            case 1:
                pedirNumero(&numeroUno);
                flag1++;
                break;
            case 2:
                pedirNumero(&numeroDos);
                flag2++;
                break;
            case 3:
                if(flag1>=1 && flag2>=1)
                {
                    printf("Calculando...");//Calcular las operaciones.
                    operacionSuma(&resultadoSuma,numeroUno,numeroDos);
                    operacionResta(&resultadoResta,numeroUno,numeroDos);
                    operacionDivision(&resultadoDivision,numeroUno,numeroDos);
                    operacionMultiplicacion(&resultadoMultiplicacion,numeroUno,numeroDos);
                    operacionFactorial(&resultadoFactorialUno,&resultadoFactorialDos,numeroUno,numeroDos);
                    flag3++;
                }
                else if(flag1==0 || flag2==0)
                {
                    printf("\nError.Faltan operandos.");
                }
                break;
            case 4:
                if(flag3>=1)
                {
                    printf("El resultado de numeroUno+numeroDos es: ""%.2f",resultadoSuma);//Dar resultado.
                    printf("\nEl resultado de numeroUno-numeroDos es: ""%.2f",resultadoResta);
                    if(operacionDivision(&resultadoDivision,numeroUno,numeroDos)==-1)
                    {
                        printf("\nNo se posible dividir por cero.");
                    }
                    else
                    {
                        printf("\nEl resultado de numeroUno/numeroDos es: ""%.2f",resultadoDivision);
                    }
                    printf("\nEl resultado de la numeroUno*numeroDos: ""%.2f",resultadoMultiplicacion);
                    printf("\nEl resultado de la factorial del numero uno es: ""%.2f",resultadoFactorialUno);
                    printf("\nEl resultado de la factorial del numero dos es: ""%.2f",resultadoFactorialDos);
                }
                else if(flag3==0)
                {
                    printf("\nError.Faltan operandos o calcular.");
                }
                break;
            case 5:
                flag=0;//salir
                printf("Nos vemos");
                break;
            default:
                printf("Ingrese una opción valida!\n");
                break;
            }
        __fpurge(stdin); //para limpiar el buffer.
        printf("\nIngrese ENTER para continuar");
        getchar(); //te freeza hasta que apretas una letra.
        system("clear"); //limpia la pantalla
        }
    while(flag!=0);
    return 0;
}
