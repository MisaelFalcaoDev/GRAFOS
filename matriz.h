#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int v1, v2, arestas = 0, vertice,q;

typedef struct {
    int matriz[MAX][MAX];
    int num_vertices;
    int grau[MAX];
} Grafo;

//Método para criar um grafo com um determinado número de vértices
Grafo* criarGrafo(int num_vertices) {
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->num_vertices = num_vertices;

    // Inicializa a matriz de adjacência com zeros
    for (int i = 0; i < num_vertices; i++) {
        grafo->grau[i] = 0;
        for (int j = 0; j < num_vertices; j++) {
            grafo->matriz[i][j] = 0;
        }
    }
    return grafo;
}

//Método para adicionar uma vértice à matriz
Grafo* adicionar_vertice(Grafo* grafo) {
    int add, i, j;
    printf("Voce pode adicionar mais %d vertices. Quantos deseja adicionar?\n", MAX-(grafo->num_vertices));
    scanf("%d", &add);
    grafo->num_vertices = grafo->num_vertices + add;

    // Inicializa a matriz de adjacência com zeros
    for (i > grafo->num_vertices; i <= add; i++) {
        grafo->grau[i] = 0;
        for (j = grafo->num_vertices; j <= add; j++) {
            grafo->matriz[i][j] = 0;
        }
    }

    return grafo;
}

//Método para adicionar arestas
void adicionar_aresta(Grafo* grafo, int v1, int v2) {
    if (v1 >= 0 && v1 < grafo->num_vertices && v2 >= 0 && v2 < grafo->num_vertices) {
        if(grafo->matriz[v1][v2] == 1 || v1 == v2){
            grafo->matriz[v1][v2] = 2;
            grafo->matriz[v2][v1] = 2;
            arestas++;
            grafo->grau[v1]+2;
            grafo->grau[v2]+2;
        }else{
            int i = 0;
            grafo->matriz[v1][v2] = 1;
            grafo->matriz[v2][v1] = 1; // Para grafos não direcionados
            arestas++;
            grafo->grau[v1]++;
            grafo->grau[v2]++;
        }
    }
}

//Método para remover arestas
void remover_aresta(Grafo* grafo, int v1, int v2) {
    if (v1 >= 0 && v1 < grafo->num_vertices && v2 >= 0 && v2 < grafo->num_vertices) {
        grafo->matriz[v1][v2] = 0;
        grafo->matriz[v2][v1] = 0; // Para grafos não direcionados
        arestas--;
        grafo->grau[v1]--; //= grafo->grau[v1]--;
        grafo->grau[v2]--; //= grafo->grau[v2]--;
    }
}

//Método para a contagem dos graus de um vértice
void grau_vertice(Grafo* grafo, int vertice){
    int grau = grafo->grau[vertice];
    printf("O grau do vertice e: %d\n\n", grau);
}

//Método para desehar a matriz do grafo
void desenhar_matriz(Grafo* grafo) {

    printf("\nNumero de vertices: %d\n", grafo->num_vertices);
    printf("\nNumero de arestas: %d\n", arestas);
    printf("\nMatriz de Adjacencia:\n");
    for (int i = 0; i < grafo->num_vertices; i++) {
        for (int j = 0; j < grafo->num_vertices; j++) {
            printf("%d ", grafo->matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//Menu para a escolha das opções
void menu(){
    system("cls");
    printf("\nEscolha uma das seguintes opcoes: \n");
    printf("1 - Criar um grafo \n");
    printf("2 - Adicionar vertices \n");
    printf("3 - Adicionar uma aresta \n");
    printf("4 - Remover uma aresta \n");
    printf("5 - Imprimir grafo 1 \n");
    printf("6 - Imprimir grafo 2 \n");
    printf("7 - Descobrir o grau de um vertice\n");
    printf("0 - Sair \n\n");
}

