#define _POSIX_C_SOURCE 200809L
#include "strutil.h"
#include "string.h"
#include "stdbool.h"
#include <stdlib.h>
#include <stdio.h>


void printer_elementos(char** arreglo){
    for (int i=0; arreglo[i] != NULL; i++){
            printf("ELEMENTO DE POSICION: %d :  %s \n", i, arreglo[i]);
    };
}


int contar_apariciones(const char* cadena, char sep, size_t tam){
    int apariciones = 0;
    for (int i=0; i < tam; i++){
        if (cadena[i] == sep){
            apariciones++;
        }
    }
    return apariciones;
}


char* mystrcat( char* dest, char* src){
    while (*dest) dest++;
    while ( (*dest++ = *src++) );
    return --dest;
}


bool guardar_subset(const char* cadena, size_t tam_subset, int inicio, int fin, int pos_subset, char** subsets){
    size_t largo_subcadena = fin - inicio;
    char* subcadena = malloc ((sizeof(char) * (largo_subcadena + 1))); // + '\0'
    if (! subcadena) return false;
    strncpy(subcadena, &cadena[inicio], largo_subcadena);
    subcadena[largo_subcadena] = '\0';
    subsets[pos_subset] = subcadena;
    return true;
}

    
char** split(const char * cadena, char sep){
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
                free_strv(subsets);
                return NULL;
            }
            pivot_subset_ini = i + 1;
            caracteres = 0;
            pos_subset++;
        }
        else{
            caracteres++;
        }
    }
    if (caracteres > 0){
        bool guardo = guardar_subset(cadena, caracteres, pivot_subset_ini, pivot_subset_ini + caracteres, pos_subset, subsets);
        if (! guardo){
            free_strv(subsets);
            return NULL; 
        }
    }
    subsets[pos_subset + 1] = NULL;
    return subsets;
}


char* join(char** subset, char sep){
    if (! subset) return NULL;
    char** pivot_subset1 = subset;
    size_t tam_subset = 1; // + NULL
    size_t tam_cadena = 0;
    while (*subset != NULL){
        tam_cadena = tam_cadena + strlen( *(subset++) );
        tam_subset++;
    }
    char* cadena = malloc( sizeof(char) * (tam_cadena + tam_subset + 1) ); // + '\0'
    if (! cadena) return NULL;
    char* puntero_cadena = cadena;
    while (*pivot_subset1 != NULL){
        puntero_cadena = mystrcat(puntero_cadena, *(pivot_subset1++));
        if (*pivot_subset1){
            strncpy(puntero_cadena, &sep, 1);
        }
    }
    *(puntero_cadena + 1) = '\0';
    return cadena;
}


void free_strv(char* arreglo[]){
    for (int i=0; arreglo[i] != NULL; i++){
        free(arreglo[i]);
    }
    free(arreglo);
}
