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
    char* cadena4 = ",,abc,def";
    char sep_vacio = '\0';
    char coma = ',';

    char** subset1 = split(cadena1, sep_vacio);
    char** subset2 = split(cadena1, coma);
    char** subset3 = split(cadena2, coma);
    char** subset4 = split(cadena4, coma);

    // size_t tam_subset1 = 2;
    // size_t tam_subset2 = 2;
    // size_t tam_subset3 = 3;
    // size_t tam_subset4 = 5;



    /* Inicio de pruebas */
    print_test("CADENA NO VACIA con separador vacio es NULL ", strcmp(cadena1, subset1[0]) == 0);
    print_test("CADENA NO VACIA con separador no encontrado es Cadena ", ( (*cadena1 == *subset2[0]) && (NULL == subset2[1]) ) );
    print_test("CADENA NO VACIA con separador encontrado en subset1 es valido ", strcmp(cadena3, subset3[1]) == 0 );
    print_test("CADENA NO VACIA con separador encontrado es sub Sets de cadena  ", ( (strcmp(cadena1, subset3[0]) == 0) && (strcmp(cadena3, subset3[1]) == 0) && (subset3[2] == NULL) ) );
    print_test("CADENA NO VACIA con separador consecutivo es sub Sets de cadena  ", ( (strcmp(&sep_vacio, subset4[0]) == 0) && (strcmp(&sep_vacio, subset4[1]) == 0) ));
    
    free_strv(subset1);
    free_strv(subset2);
    free_strv(subset3);
    free_strv(subset4);
}


void pruebas_join(){
    printf("INICIO DE PRUEBAS CON FUNCION JOIN\n");

    char coma = ',';
    char* cadena0 = "";
    char* cadena1 = "abc,def";
    char* cadena2 = "abc";
    char** subset0 = split(cadena0, coma);
    char** subset1 = split(cadena1, coma);
    char** subset2 = split(cadena2, coma);
    char* j_cadena0 = join(subset0, coma);
    char* j_cadena1 = join(subset1, coma);
    char* j_cadena2 = join(subset2, coma);

    print_test("ARREGLO VACIO devuelve una cadena vacia", ( strcmp(cadena0, j_cadena0) == 0 ) );
    print_test("ARREGLO NO VACIO con cadenas no nulas devuelve una cadena concatenada a traves de separador ", ( strcmp(cadena1, j_cadena1) == 0 ) );
    print_test("ARREGLO NO VACIO con cadenas no nulas con separador no encontrado devuelve una cadena concatenada ", ( strcmp(cadena2, j_cadena2) == 0 ) );

    free_strv(subset0);
    free_strv(subset1);
    free_strv(subset2);

    free(j_cadena0);    
    free(j_cadena1);
    free(j_cadena2);
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
    pruebas_join();
    pruebas_free();
}