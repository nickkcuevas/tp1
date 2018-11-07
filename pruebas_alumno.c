#define _POSIX_C_SOURCE 200809L
#include "strutil.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
    char* cadena2 = "abc,def";
    char* cadena3 = "def";
    // char* cadena4 = ",abc,def";
    char sep_vacio = '\0'; 
    char coma = ',';
    char** subset1 = split(cadena1, sep_vacio);
    char** subset2 = split(cadena1, coma);
    char** subset3 = split(cadena2, coma);

    /* Inicio de pruebas */
    print_test("CADENA NO VACIA con separador vacio es NULL ", NULL == subset1);
    print_test("CADENA NO VACIA con separador no encontrado es Cadena ", ( (*cadena1 == *subset2[0]) && (NULL == subset2[1]) ) );
    print_test("CADENA NO VACIA con separador encontrado en subset1 es valido ", strcmp(cadena3, subset3[1]) == 0 );
    print_test("CADENA NO VACIA con separador encontrado es sub Sets de cadena  ", ( (strcmp(cadena1, subset3[0]) == 0) && (strcmp(cadena3, subset3[1]) == 0) ));
    free_strv(subset2);
    free_strv(subset3);
}


void pruebas_join(){

}


void pruebas_free() {
    /* Declaro las variables a utilizar*/

    char** cadena = malloc(sizeof(char*) * 4);
    char* sub1 = strdup("abc");
    char* sub2 = strdup("def");
    char* sub3 = strdup("ghi");
    char* sub4 = NULL;
    
    /* Inicio de pruebas */

    cadena[0] = sub1;
    cadena[1] = sub2;
    cadena[2] = sub3;
    cadena[3] = sub4;
    
    free_strv(cadena);
    print_test("Free de un arreglo de cadenas es true ", true);
}



void pruebas_alumno(){
    pruebas_split();
    pruebas_free();
}