//programa prinicipal pvv.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"commands.h"
#include"functions.h"
#include"structure.h"

//prototipos de funciones 
int CharToInt(const char *str);

int main(char argc, char *argv[]){

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
    else if (strcmp(argv[1], "start")==0 && argv[2]!=NULL){
        
        int nodes = CharToInt(argv[2]);
        
        pvv_start(nodes); //comando start <numero> 
        
        printf ("Grafo creado con %d nodos\n", CharToInt(argv[2]));
    }

    // comando generate file
    else if (strcmp(argv[1], "generate")==0){
        
        // Si el segundo argumento es nulo se le notifica al usuario terminar el comando
        if (argv[2]==NULL){
            printf ("Comando incompleto, escriba: ./pvv generate file para crear archivo ruta\n");
            return 1;
        }
        
        else if (strcmp(argv[2], "file")==0){
            generar_archivos(); //comando generate file
        }
    }

    else if (strcmp(argv[1], "read")==0){
        if (argv[2]==NULL){
            printf ("Indique el nombre de un archivo a leer, (./pvv read <nombre_archivo.txt>)\n");
            return 1;
        }

        // Codigo incompleto para leer archivos
    }

    // Comandos invalidos o no reconocidos
    else {
        printf ("Comando no reconocido, escriba: ./pvv help para ver los comandos disponibles\n");
    }

    return 0;
}

// Funcion que convierte un string a entero
int CharToInt(const char *str){
    int valor = atoi(str);
    if (valor < 0){
        valor = valor * -1; //en caso de ingresar positivo se transforma a positivo 
    }
    return valor;
}

