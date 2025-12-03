//programa prinicipal pvv.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"commands.h"
#include"functions.h"


//prototipos de funciones 
int CharToInt(const char *str);

int main(int argc, char *argv[]){

    // Ningun comando ingresado
    if (argc <= 1){
        printf ("Escriba: ./pvv help para ver los comandos disponibles\n");
    }

    // Comando help
    else if (strcmp(argv[1], "help")==0){
        printf ("Comandos disponibles:\n");
        printf ("./pvv start <numero> : Crea un grafo con el numero de nodos especificado\n");
        printf ("./pvv generate file : Genera un archivo ruta\n");
    }

    // Comando start
    else if (strcmp(argv[1], "start") == 0 && argv[2] != NULL) {

        int nodes = CharToInt(argv[2]);
        if (nodes < 1) {
            printf("Numero de nodos invalido.\n");
            return 1;
        }

        if (pvv_start(nodes) != 0) {
            printf("Error al crear el grafo.\n");
            return 1;
        }

        printf("Grafo creado con %d nodos\n", nodes);
    }

    else if (strcmp(argv[1], "read")==0){
        if (argv[2]==NULL){
            printf ("Indique el nombre de un archivo a leer, (./pvv read <nombre_archivo.txt>)\n");
            return 1;
        }

        // Codigo incompleto para leer archivos
        pvv_read(argv[2]);
    }

    // Comandos invalidos o no reconocidos
    else {
        printf ("Comando no reconocido, escriba: ./pvv help para ver los comandos disponibles\n");
        return 1;
    }

    return 0;
}

// Funcion que convierte un string a entero
int CharToInt(const char *str){
    int valor = atoi(str);
    if (valor < 0){
        return -1; //valor invalido
    }
    return valor;
}

