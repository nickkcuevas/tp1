#include "testing.h"
#include <stdio.h>

void pruebas_alumno(void);

/* ******************************************************************
 *                        PROGRAMA PRINCIPAL
 * *****************************************************************/

int main(void) {
    /* Ejecuta todas las pruebas unitarias. */
    printf("~~~ PRUEBAS DEL ALUMNO ~~~\n");
    pruebas_alumno();

    return failure_count() > 0;
}
