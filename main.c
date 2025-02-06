#include <stdio.h>
#include <string.h>

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
  if (stack->apontador < TMN_MAXIMO - 1) {
    stack->apontador++;
    strncpy(stack->pilhaArray[stack->apontador], item, 50);
    stack->pilhaArray[stack->apontador][49] = '\0';
    stack->tamanho++;
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

int main(void) {
  pilha historico;
  inicializarPilha(&historico);

  empilhar(&historico, "www.google.com");
  empilhar(&historico, "www.youtube.com");
  empilhar(&historico, "www.facebook.com");

  desempilhar(&historico);

  exibirHistorico(&historico);

  return 0;
}

