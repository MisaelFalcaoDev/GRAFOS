#include <stdio.h>
#include <stdlib.h>

struct Vertice {
    int valor;
    struct Vertice* proximo;
};

struct Grafo {
    int numVertices;
    struct Vertice** listaAdjacencia;
};

// Método para criar um vértice
struct Vertice* criarVertice(int valor) {
    struct Vertice* novoVertice = (struct Vertice*)malloc(sizeof(struct Vertice));
    novoVertice->valor = valor;
    novoVertice->proximo = NULL;
    return novoVertice;
}

// Método para criar um grafo vazio
struct Grafo* criarGrafo(int numVertices) {
    struct Grafo* grafo = (struct Grafo*)malloc(sizeof(struct Grafo));
    grafo->numVertices = numVertices;
    grafo->listaAdjacencia = (struct Vertice**)malloc(numVertices * sizeof(struct Vertice*));
    int i;
    for (i = 0; i < numVertices; i++) {
        grafo->listaAdjacencia[i] = NULL;
    }
    return grafo;
}

// Método para adicionar uma aresta ao grafo
void adicionarAresta(struct Grafo* grafo, int v1, int v2) {
    // Cria um novo vértice para a lista de adjacência de v1, vértice ao qual v1 está ligado
    struct Vertice* novoVertice = criarVertice(v2);
    novoVertice->proximo = grafo->listaAdjacencia[v1];
    grafo->listaAdjacencia[v1] = novoVertice;

    // Cria um novo vértice para a lista de adjacência de v2, vértice ao qual v2 está ligado
    novoVertice = criarVertice(v1);
    novoVertice->proximo = grafo->listaAdjacencia[v2];
    grafo->listaAdjacencia[v2] = novoVertice;
}

// Método para adicionar um vértice ao grafo
void adicionarVertice(struct Grafo* grafo, int valor) {
    struct Vertice* novoVertice = criarVertice(valor);

    // Aumenta o tamanho do vetor de listas de adjacência
    grafo->numVertices++;
    grafo->listaAdjacencia = realloc(grafo->listaAdjacencia, grafo->numVertices * sizeof(struct Vertice*));
}

// Método para remover uma aresta do grafo
void removerAresta(struct Grafo* grafo, int v1, int v2) {
    struct Vertice* atual = grafo->listaAdjacencia[v1];
    struct Vertice* anterior = NULL;

    // Procura a aresta a ser removida na lista de adjacência de v1
    while (atual != NULL && atual->valor != v2) {
        anterior = atual;
        atual = atual->proximo;
    }
    // Se encontrar a aresta, remove-a
    if (atual != NULL) {
        if (anterior != NULL) {
            anterior->proximo = atual->proximo;
        } else {
            grafo->listaAdjacencia[v1] = atual->proximo;
        }
        free(atual);
    }

    // Repete o processo para a lista de adjacência de v2
    atual = grafo->listaAdjacencia[v2];
    anterior = NULL;

    while (atual != NULL && atual->valor != v1) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL) {
        if (anterior != NULL) {
            anterior->proximo = atual->proximo;
        } else {
            grafo->listaAdjacencia[v2] = atual->proximo;
        }
        free(atual);
    }
}

// Método para remover um vértice do grafo
void removerVertice(struct Grafo* grafo, int valor) {
    int i;

    // Remove todas as arestas que contêm o vértice a ser removido
    for (i = 0; i < grafo->numVertices; i++) {
        struct Vertice* atual = grafo->listaAdjacencia[i];
        struct Vertice* anterior = NULL;

        while (atual != NULL) {
            if (atual->valor == valor) {
                if (anterior != NULL) {
                    anterior->proximo = atual->proximo;
                    free(atual);
                    atual = anterior->proximo;
                } else {
                    grafo->listaAdjacencia[i] = atual->proximo;
                    free(atual);
                    atual = grafo->listaAdjacencia[i];
                }
            } else {
                anterior = atual;
                atual = atual->proximo;
            }
        }
    }

    // Remove o vértice do vetor de listas de adjacência
    for (i = valor; i < grafo->numVertices - 1; i++) {
        grafo->listaAdjacencia[i] = grafo->listaAdjacencia[i + 1];
    }

    grafo->numVertices--;

    // Reduz o tamanho do vetor de listas de adjacência
    grafo->listaAdjacencia = realloc(grafo->listaAdjacencia, grafo->numVertices * sizeof(struct Vertice*));
}

// Método para imprimir a estrutura de adjacência do grafo
void imprimirGrafo(struct Grafo* grafo) {
    int i;
    for (i = 0; i < grafo->numVertices; i++) {
        struct Vertice* atual = grafo->listaAdjacencia[i];
        printf("Vértice %d: ", i);
        while (atual != NULL) {
            printf("%d -> ", atual->valor);
            atual = atual->proximo;
        }
        printf("NULL\n");
    }
}

// Função para contar o número de graus de um vértice
int contarGraus(struct Grafo* grafo, int vertice) {
    int graus = 0;
    struct Vertice* atual = grafo->listaAdjacencia[vertice];
    
    while (atual != NULL) {
        graus++;
        atual = atual->proximo;
    }
    
    return graus;
}


//Menu para a escolha das opções
void menu(){
    system("cls");
    printf("\nEscolha uma das seguintes opcoes: \n");
    printf("1 - Criar um grafo \n");
    printf("2 - Adicionar um vertice \n");
    printf("3 - Remover um vertice \n");
    printf("4 - Adicionar uma aresta \n");
    printf("5 - Remover uma aresta \n");
    printf("6 - Imprimir grafo 1 \n");
    printf("7 - Imprimir grafo 2 \n");
    printf("8 - Descobrir o grau de um vertice\n");
    printf("0 - Sair \n\n");
}
