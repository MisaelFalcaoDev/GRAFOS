#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int v1, v2, arestas = 0;

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
    printf("Você pode adicionar mais %d vertices. Quantos deseja adicionar?\n", MAX-(grafo->num_vertices));
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
    printf("O grau do vertice é: %d\n\n", grau);
}


//Método para desehar a matriz do grafo
void desenhar_matriz(Grafo* grafo) {
    
    printf("\nNumero de vertices: %d\n", grafo->num_vertices);
    printf("\nNumero de arestas: %d\n", arestas);
    printf("\nMatriz de Adjacência:\n");
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


//Função principal
int main() {
    int op = 1;
    while(op != 0){
        //system("pause");
        menu();
        scanf("%d", &op);
        switch(op){
            case 1: 
                int num_vertices;
                printf("Escolha a quantidade de vertices do grafo de 1 a %d:\n", MAX);
                scanf("%d", &num_vertices);
                Grafo* grafo = criarGrafo(num_vertices);
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
                Grafo* grafo_1 = criarGrafo(5);
                                 
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
                Grafo* grafo_2 = criarGrafo(5); 
                
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
                int vertice;
                printf("Digite o número do vertice que deseja descobrir o valor do grau: \n");
                scanf("%d", &vertice);
                grau_vertice(grafo, vertice);
            default : printf("Informe uma opcao valida!");
        }
        system("pause");
    }
    
    return 0;
}




