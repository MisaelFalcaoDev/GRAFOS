#include <stdio.h>
#include <stdlib.h>
#include "estrutura.h"

// Função principal
int main() {
    int op = 1, q, vertice, v1, v2, grau;
    struct Grafo* grafo_1 = criarGrafo(5);
    struct Grafo* grafo_2 = criarGrafo(5);
    while(op != 0){
        //system("pause");
        menu();
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("Escolha a quantidade de vertices do grafo: ");
                scanf("%d", &q);
                struct Grafo* grafo = criarGrafo(q);
                imprimirGrafo(grafo);
                break;
            case 2:
                adicionarVertice(grafo, vertice);
                imprimirGrafo(grafo);
                break;
            case 3:
                adicionarVertice(grafo, vertice);
                imprimirGrafo(grafo);
                break;
            case 4:
                printf("Digite v1: ");
                scanf("%d", &v1);
                printf("\nDigite v2: \n");
                scanf("%d", &v2);
                adicionarAresta(grafo, v1, v2);
                imprimirGrafo(grafo);
                break;
            case 5:
                printf("Digite v1: ");
                scanf("%d", &v1);
                printf("\nDigite v2: ");
                scanf("%d", &v2);
                removerAresta(grafo, v1, v2);
                imprimirGrafo(grafo);
                break;
            case 6:
                adicionarAresta(grafo_1, 0, 1);
                adicionarAresta(grafo_1, 1, 2);
                adicionarAresta(grafo_1, 1, 4);
                adicionarAresta(grafo_1, 2, 2);
                adicionarAresta(grafo_1, 2, 4);
                adicionarAresta(grafo_1, 2, 3);
                adicionarAresta(grafo_1, 3, 1);
                adicionarAresta(grafo_1, 3, 4);
                adicionarAresta(grafo_1, 4, 2);

                imprimirGrafo(grafo_1);
                break;
            case 7:
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
            case 8:
                printf("Digite o numero do vertice que deseja descobrir o valor do grau: \n");
                scanf("%d", &vertice);
                grau = contarGraus(grafo, vertice);
                printf("O grau do vertice %d é: %d\n", vertice, grau);
            default : printf("\nInforme uma opcao valida!\n");
        }
        system("pause");
    }
    return 0;
}
