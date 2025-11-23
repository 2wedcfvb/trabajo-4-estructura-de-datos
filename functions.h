#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <limits.h>
#include <stdbool.h>
#include "structure.h"
#define archivos_max 20 // Maximo de archivos permitidos

void generar_archivos(){
    
    int num_archivo=1;
    char nombre_archivo[20]; 

    // Ciclo que busca al primer: archivo_%d sin numero existente y lo asigna
    for (num_archivo; num_archivo<=archivos_max; num_archivo++){
        
        sprintf(nombre_archivo, "archivo_%d.txt", num_archivo); 

        FILE *existente = fopen(nombre_archivo, "r"); 
        if (existente == NULL){
            break; // el archivo_%d no existe por lo tanto se rompe el ciclo y se le asigna numero
        }
        // Si el ciclo se completa (num_archivo >= archivos_max) no se podran crear mas
    } 

    if (num_archivo > archivos_max){ // no hay archivos disponibles para crear
        printf ("Se ha alcanzado el numero maximo de archivos, elimine archivos \n");
        return;
    }

    // Se crea el archivo e imprime mensaje en el mismo
    FILE *archivo = fopen(nombre_archivo, "w");
    fprintf (archivo, "Mensaje de prueba");
    fclose (archivo);
    printf ("archivo %d generado\n", num_archivo);
}