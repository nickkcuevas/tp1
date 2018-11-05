#include "strutil.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/* *****************************************************************
 *                    FUNCIONES AUXILIARES
 * *****************************************************************/



// /* ******************************************************************
//  *                   PRUEBAS UNITARIAS ALUMNO
//  * *****************************************************************/



void pruebas_split() {
    printf("INICIO DE PRUEBAS CON FUNCION SPLIT\n");

    /* Declaro las variables a utilizar*/
    
    char* cadena1 = "abc";
    char* sep_vacio = '\0'; 
    char** array1 = split(cadena1, *sep_vacio);
    printf("TU NO HAS CODEADO NADA \n");
    print_test("Cadena no vacia con serparador vacio es NULL ", NULL == array1);

    /* Inicio de pruebas */

    

}



void pruebas_alumno(){
    pruebas_split();
}