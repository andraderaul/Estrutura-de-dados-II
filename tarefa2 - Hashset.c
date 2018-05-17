#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
int C = 0;

typedef struct Node{
  struct Node* next;
  int data;
} Node;

// inicio funcoes da lista
int search(Node** head, int data){
  Node *current = *head;
  /* procurando o elemento */
  while (current) {
    C++;
    if(current->data == data)
      return true;
    current = current->next;
  }
  return false;
}

int insert(Node** head, int data){

  if(!search(head,data)){
    // criando um novo nó
    Node* new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;

    if(!(*head)){
      new_node->next = NULL;
      (*head) = new_node;
    }
    else{
      new_node->next = (*head);
      (*head) = new_node;
    }
    return true;
  }
  return false;

}
int remover(Node** head, int data){

  if(search(head,data)){
    Node *current = *head;
    Node *prev = NULL;
    /* procurando o elemento */
    do{
      if(current->data == data){
        break;
      }
      prev = current;
      current = current->next;
    }while(current);

    /* primeiro elemento */
    if(current == *head){
      prev = *head;
      *head = current->next;
      free(prev);
      return true;
    }
    if(current->next == NULL){
      prev->next = NULL;
      free(current);
      return true;
    }

    prev->next = current->next;
    free(current);
    return true;
  }
  return false;
}
void show(Node* head){
  Node* current_node = head;
  while (current_node) {
    printf("[%d]->",current_node->data);
    current_node = current_node->next;
  }
//  printf("NULL\n");
}
// fim das funcoes da lista
// funcoes do problema
int functionDispersing(int K, int M){
  return K % M;
}
int main(){

  int M = 7; // // Tamanho da tabela: a tabela deve ter uma capacidade inicial m=7.
  float alfa = 0.0;
  char input[4];
  int num;

  /// Inicializando Tabela
  Node** table;
  Node** aux;
  int* size;
  table = (Node**)malloc(sizeof(Node*)*M);
  size = (int*)calloc(M, sizeof(int));

  //Iniciaando a leitura

  // I = numero da operação
  // R = resultado da operacao
  // C = numero de comparaçoes feitas
  // M = tamanho
  // L = comprimento da maior lista da tabela

  int i = 0,a = 0, R = 0;
  while (scanf("%s %d", input,&num)!=EOF) {
      int h = functionDispersing(num,M);
      switch (input[0]){
        case 'A':
          // show(table[h]);
          // printf("-----\n");
          R = insert(&table[h],num); // retorna se foi adicionado ou nao
          printf("%d %d %d\n", i, R, C);
          if(R){ // se foi adicionado incrementa atualiza o tamanho da tabela e o tamanho da lista
            a++;
            size[h]++;
            // printf("  inserido %d\n",num);

            /// alfa >= 0.75 todos os elementos da tabela atual devem ser redistribuidos (rehashing) numa nova tabela de tamanho 2*m-1 por
            alfa = (float)a/M;
            //printf("a = %d alfa = %f\n",a, alfa);
            if(alfa >= 0.75){
              /// tamanho novo
              int oldM = M;
              M = 2*M-1;

              // rehashing
              aux = (Node**) malloc(sizeof(Node*)*M);
              size = (int*)calloc(M, sizeof(int));
              int j = 0;
              for (j = 0; j < oldM; j++) {
                while(table[j] != NULL) {
                  h = functionDispersing(table[j]->data,M);
                  insert(&aux[h],table[j]->data);
                  size[h]++;
                  table[j] = table[j]->next;
                }
              }
              table = aux;

              // printf("REHASING %d\n",M );
              // for (int j = 0; j < M; j++) {
              //   printf("[%d]: ", j);
              //   while(table[j]) {
              //     printf("%d -> ", table[j]->data );
              //     table[j] = table[j]->next;
              //   }
              //   printf("\n");
              // }

            }

          }
        break;
        case 'H':
          R = search(&table[h],num);
          printf("%d %d %d\n", i, R, C);
        break;
        case 'D':
          R = remover(&table[h],num); // retorna se foi removido ou nao
          printf("%d %d %d\n", i, R, C);
          if(R){ // se removido decrementa e atuaaliza o tamanho da tabela e da lista
            a--;
            size[h]--;
          }
        break;
        case 'P':
          int x = 0, k = 0;
          for(k = 0; k < M; k++){
            if(x < size[k])
              x = size[k];
          }
          printf("%d %d %d %d\n",i,M,a,x);
        break;
      }

      i++; C = 0;

  }





  return 0;
}
