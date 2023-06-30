#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int v1, v2, arestas = 0, vertice,q;

// Método para representar um vértice
struct Vertices {
    int vertice;
    struct Vertices* proximo;
};

// Método para representar o grafo
struct Grafo {
    int numVertices;
    struct Vertices* listaAdjacencia[MAX];
};

//CRIAR MÉTODO PARA ADICIONAR UM VÉRTICE

// Método para criar um grafo com um número determinado de vértices
struct Grafo* criarGrafo(int numVertices) {
    struct Grafo* grafo = (struct Grafo*)malloc(sizeof(struct Grafo));
    grafo->numVertices = numVertices;

    // Inicializa as listas de adjacência como NULL
    for (int i = 0; i < numVertices; i++) {
        grafo->listaAdjacencia[i] = NULL;
    }

    return grafo;
}

// Método para adicionar uma aresta ao grafo
void adicionarAresta(struct Grafo* grafo, int v1, int v2) {
    // Cria um novo vértice para a lista de adjacência de v1, vértice o qual se liga com v1
    struct Vertices* novoVertice = adicionarVertice(grafo,v2);
    novoVertice->proximo = grafo->listaAdjacencia[v1];
    grafo->listaAdjacencia[v1] = novoVertice;

    // No caso de um grafo não direcionado devemos adicionar o contrário também, p vértice que se liga com v2
    novoVertice = adicionarVertice(grafo, v1);
    novoVertice->proximo = grafo->listaAdjacencia[v2];
    grafo->listaAdjacencia[v2] = novoVertice;
    
}
// CRIAR MÉTODO PARA REMOVER ARESTA
// CRIAR MÉTODO PARA CONTAR OS GRAUS

// Método para imprimir o grafo
void imprimirGrafo(struct Grafo* grafo) {
    for (int i = 0; i < grafo->numVertices; i++) {
        struct Vertices* atual = grafo->listaAdjacencia[i];
        printf("Vértice %d:", i);
        while (atual != NULL) {
            printf(" -> %d", atual->vertice);
            atual = atual->proximo;
        }
        printf("\n");
    }
}

//Menu para a escolha das op  es
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

// Função principal
int main() {
    int op = 1;
    struct Grafo* grafo_1 = criarGrafo(5);
    struct Grafo* grafo_2 = criarGrafo(5);
    while(op != 0){
        //system("pause");
        menu();
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("Escolha a quantidade de vertices do grafo de 1 a %d:\n", MAX);
                scanf("%d", &q);
                struct Grafo* grafo = criarGrafo(q);
                imprimirGrafo(grafo);
                break;
            case 2:
                printf("Digite um vertice para adicionar: ");
                scanf("%d", &vertice);
                adicionarVertice(grafo, vertice);
                imprimirGrafo(grafo);
                break;
            case 3:
                printf("Digite v1: ");
                scanf("%d", &v1);
                printf("\nDigite v2: ");
                scanf("%d", &v2);
                adicionarAresta(grafo, v1, v2);
                imprimirGrafo(grafo);
                break;
            /*case 4:
                printf("Digite v1: ");
                scanf("%d", &v1);
                printf("\nDigite v2: ");
                scanf("%d", &v2);
                remover_aresta(grafo, v1, v2);
                imprimirGrafo(grafo);
                break;*/
            case 5:
                adicionarAresta(grafo_1, 0, 1);
                adicionarAresta(grafo_1, 1, 2);
                adicionarAresta(grafo_1, 1, 4);
                adicionarAresta(grafo_1, 2, 2); //ser  2, por ser la o
                adicionarAresta(grafo_1, 2, 4);
                adicionarAresta(grafo_1, 2, 3);
                adicionarAresta(grafo_1, 3, 1);
                adicionarAresta(grafo_1, 3, 4);
                adicionarAresta(grafo_1, 4, 2);

                imprimirGrafo(grafo_1);
                break;
            case 6:
                adicionarAresta(grafo_2, 0, 1);
                adicionarAresta(grafo_2, 0, 2);
                adicionarAresta(grafo_2, 0, 3);
                adicionarAresta(grafo_2, 0, 4);
                adicionarAresta(grafo_2, 1, 2);
                adicionarAresta(grafo_2, 1, 3);
                adicionarAresta(grafo_2, 1, 4);
                adicionarAresta(grafo_2, 2, 3);
                adicionarAresta(grafo_2, 2, 4);
                adicionarAresta(grafo_2, 3, 4);

                imprimirGrafo(grafo_2);
                break;
            /*case 7:
                printf("Digite o numero do vertice que deseja descobrir o valor do grau: \n");
                scanf("%d", &vertice);
                grau_vertice(grafo, vertice);*/
            default : printf("Informe uma opcao valida!");
        }
        system("pause");
    }
    return 0;
}


