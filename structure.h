#ifndef STRUCTURE_H
#define STRUCTURE_H

typedef struct{
    int n;
    int **cost; // Matriz de costos
} Graph;

extern Graph *g_graph; //puntero global al grafo actual

//operaciones con grafos
Graph *create_graph(int n);
void free_graph(Graph *g);
int graph_add_edge(Graph *g, int from, int to, int cost);
void print_graph(const Graph *g);

#endif 

