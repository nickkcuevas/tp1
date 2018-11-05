#define _POSIX_C_SOURCE 200809L
#include "strutil.h"
#include "string.h"
#include "stdbool.h"
#include <stdlib.h>
#include <stdio.h>


int contar_apariciones(const char* cadena, char sep, size_t tam){
    int apariciones = 0;
    for (int i=0; i < tam; i++){
        if (cadena[i] == sep){
            apariciones++;
        }
    }
    return apariciones;
}


char* concatenate(char* dest, char car){
    while (*dest) dest++;
    *dest = car;
    return dest--;
}



bool guardar_subset(const char* cadena, size_t tam_subset, int inicio, int fin, int pos_subset, char** subsets){
    char* subcadena = malloc ((sizeof(char) * (tam_subset + 1))); // + '\0'
    if (! subcadena) return false;
    int pivot = inicio;
    while (pivot != fin){
        concatenate(subcadena, cadena[pivot]);
        pivot++;
    }
    subcadena[pivot] = '\0'; // esta en la ultima posicion ???

    subsets[pos_subset] = subcadena;
    return true;
}

    
char** split(const char * cadena, char sep){
    if (sep == '\0') return NULL;
    size_t largo_cadena = strlen(cadena);
    size_t cant_subsets = contar_apariciones(cadena, sep, largo_cadena) + 1;

    char** subsets = malloc(sizeof(char*) * (cant_subsets + 1));

    if (! subsets) return NULL;
    int pos_subset = 0;
    int pivot_subset_ini = 0;
    int caracteres = 0;
    for (int i=0; i < largo_cadena; i++){
        if (cadena[i] == sep){
            bool guardo = guardar_subset(cadena, caracteres, pivot_subset_ini, i, pos_subset, subsets);
            if (! guardo){
                free(subsets);
                return NULL;
            }
            pivot_subset_ini = i + 1;
            caracteres = 0;
        }
        else{
            caracteres++;
        }
    }

    subsets[pos_subset + 1] = NULL;

    return subsets;
}


// char* join(char** strv, char sep){
//     if (! strv) return NULL;    
//     return NULL;
// }


// join
// un arreglo con cadenas. ["hola", "como estas"]
// strdup(array[0])      && OJO: strcopy memoria estatica.(NO USAR)
// strcat("hola", "como estas") -> "holacomo estas" MIRAR DOCUMENTACION MEM DINAMICA
// "hola, como estas"
