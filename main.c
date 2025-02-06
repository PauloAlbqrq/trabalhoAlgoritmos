/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TMN_MAXIMO 3

typedef struct{
  char pilhaArray[TMN_MAXIMO][50];
  int apontador;
  int tamanho;
} pilha;

void inicializarPilha(pilha* stack){
  stack->apontador = -1;
  stack->tamanho = 0;
}

void empilhar(pilha* stack, const char* item){
  if (stack->apontador < TMN_MAXIMO) {
    stack->apontador++;
    strncpy(stack->pilhaArray[stack->apontador], item, 50);
    stack->pilhaArray[stack->apontador][49] = '\0';
    stack->tamanho++;
    return;
  }
  
}

char* desempilhar(pilha* stack){
  if (stack->apontador >= 0) {
    char* retorno = stack->pilhaArray[stack->apontador];
    stack->apontador--;
    stack->tamanho--;
    return retorno;
  }
  return NULL; // Stack underflow
}

void exibirHistorico(pilha* stack){
  for (int i = 0; i <= stack->apontador; i++){
    printf("%s\n", stack->pilhaArray[i]);
  }
}

void menu(pilha* stack) {
    bool loop = true; // variável de controle do loop
    while (loop) {
        int num;
        printf("Escolha uma opção: \n 1 - Pesquisar \n 2 - Voltar \n 3 - Ver historico \n 4 - Sair \n");
        // loop que repete até que a função scanf retorne que a atribuição da variável foi um sucesso
        while (scanf("%d", &num) < 1) { 
            printf("Escolha uma opção: \n 1 - Pesquisar \n 2 - Voltar \n 3 - Ver historico \n 4 - Sair \n");
            while (getchar() != '\n'); // Isso limpa o buffer ou o input, mas não entendi bem como
        }
        // usa um switch para não ficar escrevendo if e else if
        switch(num) {
            case 1:
                char input[100]; // isso aqui deu problema por eu tentar usar um ponteiro pra um char sem memória alocada, então usei um array pra armazenar a string de caracteres
                printf("Escreva o que deseja Pesquisar: ");
                scanf(" %[^\n]", input); // não me pergunte. Só sei que o input não precisa do & por que toda variável de array já é um endereço de memória
                empilhar(stack, input);
                break;
            case 2:
                printf("%s \n", desempilhar(stack));
                break;
            case 3:
                exibirHistorico(stack);
                break;
            case 4:
                loop = false;
                break;
           
        }
    }
}

int main(void) {
    
  pilha historico;
  inicializarPilha(&historico);

  menu(&historico);

  return 0;
}
