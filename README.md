# 🌲 Árvore Binária de Busca em C (BST)

Projeto desenvolvido como **Trabalho Prático** para a disciplina de **Estruturas de Dados - Nível Introdutório** do curso de **Engenharia de Software**.

## 📌 Sobre o Projeto

Este repositório contém um programa escrito em C que implementa do zero uma **Árvore Binária de Busca (BST - Binary Search Tree)**. O objetivo principal foi aplicar na prática os conceitos teóricos de estruturas de dados não lineares, incluindo manipulação de ponteiros, alocação dinâmica de memória e algoritmos de travessia recursivos.

## 🛠️ Funcionalidades Implementadas

O sistema roda diretamente no terminal (configurado para suportar acentuação UTF-8) e possui um menu interativo com as seguintes opções:

- **Inserção Ordenada:** Adiciona novos valores respeitando a regra da BST (menores à esquerda, maiores à direita) e ignora automaticamente valores duplicados.
- **Busca de Elementos:** Percorre os ramos da árvore para verificar de forma eficiente se um número específico existe.
- **Três Tipos de Percursos:**
  - **Pré-ordem** (Raiz -> Esquerda -> Direita)
  - **Em ordem** (Esquerda -> Raiz -> Direita)
  - **Pós-ordem** (Esquerda -> Direita -> Raiz)

## 🧪 Caso de Teste Documentado

Conforme a especificação do trabalho, o programa foi testado inserindo a seguinte sequência exata de números: `50, 30, 70, 20, 40, 60, 80`. 
Os resultados obtidos (e validados) nos percursos foram:

*   **Pré-ordem:** `50, 30, 20, 40, 70, 60, 80`
*   **Em ordem:** `20, 30, 40, 50, 60, 70, 80`
*   **Pós-ordem:** `20, 40, 30, 60, 80, 70, 50`

## 🚀 Como Compilar e Executar

### Pré-requisitos
* Ter um compilador C instalado (como o `gcc` via MinGW no Windows ou build-essential no Linux).
* Terminal ou Prompt de Comando.

### Passos (no terminal)
1. Clone este repositório:
  git clone https://github.com/LuisHey/arvore_binaria_busca_C

2. Acesse a pasta do projeto:
   cd arvore-binaria-busca-c

3. Compile o código-fonte:
   gcc arvore.c -o arvore

4. Execute o programa:
  No Windows: arvore.exe

  No Linux/Mac: ./arvore
