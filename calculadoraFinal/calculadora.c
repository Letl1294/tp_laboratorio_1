#include <stdio_ext.h>
#include <stdlib.h>

/**
* \brief Declaro la funcion pedirNumero para poder pedirle al usuario un numero.
* \param Mediante un scanf dentro de un "while" el usuario ingresa un dato y comprueba que no sea float.
* \param Sino es float muestra un mensaje de error.
* \param Si es float no entra al while.
* \param El puntero numero para guardar el valor.
* \return numero al terminar el programa si esta bien, sino el return es -1.
*/

int pedirNumero(float* numero)
{
    printf("Ingrese un numero: ");
    __fpurge(stdin); //para limpiar el buffer.
    while(scanf("%f",numero)==0)
    {
        printf("\nError.Dato erroneo.");
        return -1;
    }
    return *numero;
}

/**
* \brief Declaro la funcion resultadoSuma para poder realizar la operacion de suma.
* \param el puntero resultadoSuma para guardar el valor. Las variables numeroUno y numeroDos para los operandos.
* \return 0 al terminar el programa si esta bien.
*/

int operacionSuma(float* resultadoSuma,float numeroUno,float numeroDos)

{
    *resultadoSuma=numeroUno+numeroDos;
    return 0;
}

/**
* \brief Declaro la funcion resultadoResta para poder realizar la operacion de resta.
* \param el puntero resultadoResta para guardar el resultado. Las varialbes numeroUno y numeroDos para los operandos.
* \return 0 al terminar el programa si esta bien.
*/

int operacionResta(float* resultadoResta,float numeroUno,float numeroDos)

{
    *resultadoResta=numeroUno-numeroDos;
    return 0;
}

/**
* \brief Declaro la funcion resultaDivision para poder realizar la operacion de division.
* \param El puntero resultadoDivision para guardar el resultado. Las variables numeroUno y numeroDos para los operandos.
* \param Compruebo con un if que ningun operando tenga el valor 0.
* \return 0 al terminar el programa si esta bien. Sino -1.
*/

int operacionDivision(float* resultadoDivison,float numeroUno,float numeroDos)
{
    if(numeroUno!=0 && numeroDos!=0)
    {
        *resultadoDivison=numeroUno/numeroDos;
        return 0;
    }
    return -1;
}

/**
* \brief Declaro la funcion resultaMultiplicacion para poder realizar la operacion de multiplicacion.
* \param El puntero resultadoMultiplicacion para guardar el resultado.
* \param numeroUno y numeroDos para los operandos.
* \return 0 al terminar el programa si esta bien.
*/

int operacionMultiplicacion(float* resultadoMultiplicacion,float numeroUno,float numeroDos)
{
    *resultadoMultiplicacion=numeroUno*numeroDos;
    return 0;
}

/**
* \brief Declaro la funcion resultadoFactorial para poder realizar la operacion de factorial del numero uno y dos.
* \param el puntero resultadoFactorialUno y resultadoFactorialDos para guardar los resultados.
* \param numeroUno y numeroDos para los dos operandos.
* \param utilizo un "for" para hacer los calculos.
* \return 0 al terminar el programa si esta bien.
*/

int operacionFactorial(float* resultadoFactorialUno,float *resultadoFactorialDos,float numeroUno,float numeroDos)
{
int factorial=1,factorial1=1,i;
    for(i=1;i<=numeroUno;i++)
    {
        factorial*=i;
    }
    *resultadoFactorialUno=factorial;
    for(i=1;i<=numeroDos;i++)
    {
        factorial1*=i;
    }
    *resultadoFactorialDos=factorial1;
    return 0;
}
