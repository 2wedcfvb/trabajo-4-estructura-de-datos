#include "commands.h"
#include <stdio.h>

int pvv_start(int nodes) {
    FILE *Nodefile = fopen("nodos.txt", "w");
    if (Nodefile == NULL) {
        return 1; // Error al abrir el archivo
    }

    fprintf(Nodefile, "Numero de nodos: %d\n", nodes);
    fclose(Nodefile);
    return 0; // exito
}


int pvv_read(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("No existe el archivo especificado: %s\n", filename);
        return 1;
    }

    fclose(file);
    return 0;
}