#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

//Função principal
int main() {
    int op = 1;
    Grafo* grafo_1 = criarGrafo(5);
    Grafo* grafo_2 = criarGrafo(5);
    while(op != 0){
        //system("pause");
        menu();
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("Escolha a quantidade de vertices do grafo de 1 a %d:\n", MAX);
                scanf("%d", &q);
                Grafo* grafo = criarGrafo(q);
                desenhar_matriz(grafo);
                break;
            case 2:
                adicionar_vertice(grafo);
                desenhar_matriz(grafo);
                break;
            case 3:
                printf("Digite v1: ");
                scanf("%d", &v1);
                printf("\nDigite v2: ");
                scanf("%d", &v2);
                adicionar_aresta(grafo, v1, v2);
                desenhar_matriz(grafo);
                break;
            case 4:
                printf("Digite v1: ");
                scanf("%d", &v1);
                printf("\nDigite v2: ");
                scanf("%d", &v2);
                remover_aresta(grafo, v1, v2);
                desenhar_matriz(grafo);
                break;
            case 5:
                adicionar_aresta(grafo_1, 0, 1);
                adicionar_aresta(grafo_1, 1, 2);
                adicionar_aresta(grafo_1, 1, 4);
                adicionar_aresta(grafo_1, 2, 2); //será 2, por ser laço
                adicionar_aresta(grafo_1, 2, 4);
                adicionar_aresta(grafo_1, 2, 3);
                adicionar_aresta(grafo_1, 3, 1);
                adicionar_aresta(grafo_1, 3, 4);
                adicionar_aresta(grafo_1, 4, 2);

                desenhar_matriz(grafo_1);
                break;
            case 6:
                adicionar_aresta(grafo_2, 0, 1);
                adicionar_aresta(grafo_2, 0, 2);
                adicionar_aresta(grafo_2, 0, 3);
                adicionar_aresta(grafo_2, 0, 4);
                adicionar_aresta(grafo_2, 1, 2);
                adicionar_aresta(grafo_2, 1, 3);
                adicionar_aresta(grafo_2, 1, 4);
                adicionar_aresta(grafo_2, 2, 3);
                adicionar_aresta(grafo_2, 2, 4);
                adicionar_aresta(grafo_2, 3, 4);

                desenhar_matriz(grafo_2);
                break;
            case 7:
                printf("Digite o numero do vertice que deseja descobrir o valor do grau: \n");
                scanf("%d", &vertice);
                grau_vertice(grafo, vertice);
            default : printf("Informe uma opcao valida!");
        }
        system("pause");
    }
    return 0;
}
