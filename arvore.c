#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h> // Apenas para imprimir os acentos

//Estrutura do nó
typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

// Função auxiliar para criar um novo nó na memória
No* criarNo(int valor) {
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->esquerda = NULL; // Como é um nó folha, não tem filhos ainda
    novo->direita = NULL;
    return novo;
}

// Função para inserir valores
No* inserir(No *raiz, int valor) {
    // Se chegamos em um ponto vazio da árvore (ou se ela estiver vazia logo no início), criamos o nó aqui
    if (raiz == NULL) {
        printf("Inserção concluída!\n");

        return criarNo(valor);
    }

    // Comparação de valores
    if (valor < raiz->valor) {
        // valor < nó atual -> seguir para a esquerda
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } 
    else if (valor > raiz->valor) {
        // valor > nó atual -> seguir para a direita
        raiz->direita = inserir(raiz->direita, valor);
    } 
    else {
        // valor = nó atual -> não inserir duplicado
        printf("Valor %d já existe na árvore. Não inserido!\n", valor);
    }

    return raiz;
}

// Funções de percurso
void preOrdem(No *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor); // Imprime a Raiz
        preOrdem(raiz->esquerda);   // Visita a Esquerda
        preOrdem(raiz->direita);    // Visita a Direita
    }
}

void emOrdem(No *raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);    // Visita a Esquerda
        printf("%d ", raiz->valor); // Imprime a Raiz
        emOrdem(raiz->direita);     // Visita a Direita
    }
}

void posOrdem(No *raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);   // Visita a Esquerda
        posOrdem(raiz->direita);    // Visita a Direita
        printf("%d ", raiz->valor); // Imprime a Raiz
    }
}

// Função para buscar
No* buscar(No *raiz, int valor) {
    // Se a raiz for NULL (não achou) ou se o valor for igual ao do nó atual (achou!)
    if (raiz == NULL || raiz->valor == valor) {
        return raiz;
    }

    // Se o valor procurado for menor que o valor do nó atual, busca na esquerda
    if (valor < raiz->valor) {
        return buscar(raiz->esquerda, valor);
    }
    // Se o valor procurado for maior, busca na direita
    else {
        return buscar(raiz->direita, valor);
    }
}

int main() {
    SetConsoleOutputCP(65001); // Para imprimir os acentos

    No *raiz = NULL; // Inicializa a raiz da árvore como NULL, pois está vazia
    int opcao, valor;

    do {
        // Exibe o menu de opções
        printf("\n===== ÁRVORE BINÁRIA DE BUSCA =====\n");
        printf("1 - Inserir número\n");
        printf("2 - Percurso pré-ordem\n");
        printf("3 - Percurso em ordem\n");
        printf("4 - Percurso pós-ordem\n");
        printf("5 - Buscar número\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor para inserir: ");
                scanf("%d", &valor);

                // Chama a função passando a raiz atual, e atualiza a raiz
                raiz = inserir(raiz, valor);

                break;
            case 2:
                printf("\nPercurso pré-ordem: ");

                preOrdem(raiz);

                printf("\n");

                break;
            case 3:
                printf("\nPercurso em ordem: ");

                emOrdem(raiz);

                printf("\n");

                break;
            case 4:
                printf("\nPercurso pós-ordem: ");

                posOrdem(raiz);

                printf("\n");

                break;
            case 5:
                printf("Digite o valor para buscar: ");
                scanf("%d", &valor);
                
                // Chama a função e guarda o resultado em um ponteiro auxiliar
                No *resultado = buscar(raiz, valor);
                
                // Se o resultado não for NULL, significa que o nó foi encontrado
                if (resultado != NULL) {
                    printf("O valor %d foi ENCONTRADO na árvore!\n", valor);
                } else {
                    printf("O valor %d NÃO foi encontrado na árvore.\n", valor);
                }
                break;
            case 0:
                printf("Encerrando o programa... Até logo!\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}