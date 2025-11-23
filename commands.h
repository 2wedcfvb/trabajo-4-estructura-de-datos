int pvv_start(int nodes){
    
    FILE *Nodefile = fopen("informacion de nodos.txt", "w");
    if (Nodefile == NULL) 
        return 1; // Error al abrir el archivo
    
    fprintf (Nodefile, "Numero de nodos: %d\n", nodes);
    fclose(Nodefile);
    return 0; //exito

}

// int pvv_read(char *filename){  // ***codigo completamente comentado para evitar errores de compilacion***
   // FILE *file = fopen(filename, "r");
   // if (file == NULL){
   //     printf ('No existe el archivo especificado\n');
   //     return 1; // Error al abrir el archivo
   // }
    
    //return 0;
//} 
