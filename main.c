// ADS 2024
// Autores: Eduarda Leigue, Paulo Ximenes, Matheus Henrique.


// importa bibliotecas
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// define um tamanho máximo para a pilha
#define TMN_MAXIMO 100

// estrutura da pilha
typedef struct {
  char pilhaArray[TMN_MAXIMO][50]; // array de strings
  int apontador; // indica o topo da pilha
  int tamanho; // indica o tamanho da pilha
} pilha; // nome da estrutura

// função para inicializar a pilha
void inicializarPilha(pilha *stack) {
  stack->apontador = -1; // inicializa o apontador como -1 (pilha vazia)
  stack->tamanho = 0; // define o tamanho como 0
}

// função para empilhar um item na pilha
void empilhar(pilha *stack, const char *item) {
  if (stack->apontador < TMN_MAXIMO - 1) { // verifica se a pilha não está cheia
    stack->apontador++; // incrementa o apontador
    strncpy(stack->pilhaArray[stack->apontador], item, 50); // copia o item para a pilha
    stack->pilhaArray[stack->apontador][49] = '\0'; // garante que a string termina com \0
    stack->tamanho++; // incrementa o tamanho da pilha
    return; // sai da função
  }
  // se a pilha estivere cheia, não faz nada (stack overflow)
}

// função para desempilhar um item da pilha
char *desempilhar(pilha *stack) {
  if (stack->apontador >= 0) { // verifica se a pilha não está vazia
    char *retorno = stack->pilhaArray[stack->apontador]; // salva o item do topo que será desempilhado
    stack->apontador--; // diminui o apontador
    stack->tamanho--; // diminui o tamanho da pilha
    return retorno; // retorna o item desempilhado
  }
  return NULL; // retorna NULL se a pilha estiver vazia (stack underflow)
}

// função para exibir o histórico da pilha
void exibirHistorico(pilha *stack) {
  for (int i = 0; i <= stack->apontador; i++) { // percorre todos os itens da pilha
    printf("%s\n", stack->pilhaArray[i]); // exibe o item
  }
}

// função para exibir o menu e interagir com o usuário
void menu(pilha *stack) {
  bool loop = true; // variável de controle do loop
  while (loop) { // loop principal
      int num;
      char input[100]; // declara um array de char
      printf("\033[1;36m");
      printf("\n===============================\n");
      printf("             MENU!             \n");
      printf("===============================\n");
      printf("      [1] PESQUISAR            \n");
      printf("      [2] VOLTAR               \n");
      printf("      [3] HISTÓRICO            \n");
      printf("      [4] SAIR                 \n");
      printf("===============================\n");
      printf("\n-> ESCOLHA UMA OPÇÃO: \033[1;36m");

      while (scanf("%d", &num) < 1) { // verifica se o usuário digitou um número
          printf("ESCOLHA UMA OPÇÃO: \n 1 - PESQUISAR \n 2 - VOLTAR \n 3 - HISTÓRICO \n 4 - SAIR \n");
          while (getchar() != '\n'); // limpa o buffer de entrada
      }

      // switch para escolher a opção (melhor que if else)
      switch (num) {
          case 1:
              printf("\n===============================\n");
              printf("\n-> PESQUISE O QUE DESEJA: "); // pede uma entrada do usuário
              scanf(" %[^\n]", input); // lê a entrada do usuário
              empilhar(stack, input); // chama a função empilhar passando a entrada do usuário
              break;
          case 2:
              printf("\n===============================\n");
              printf("VOLTANDO...\n");
              printf("===============================\n");
              printf("%s \n", desempilhar(stack)); // chama a função desempilhar e exibe o item desempilhado
              break;
          case 3:
              printf("\n===============================\n");
              printf("           HISTÓRICO              ");
              printf("\n===============================\n");
              exibirHistorico(stack); // exibe o histórico da pilha
              break;
          case 4:
              printf("\n===============================\n");
              printf("\n       PROGRAMA ENCERRADO        ");
              loop = false; // encerra o loop
              break;
      }
  }
}

// funcão principal para executar o programa
int main(void) {
  pilha historico; // declara uma variável do tipo pilha
  inicializarPilha(&historico); // inicializa a pilha
  menu(&historico); // chama a função menu passando a pilha como argumento

  return 0; // retorna 0 para indicar que o programa foi encerrado
}
