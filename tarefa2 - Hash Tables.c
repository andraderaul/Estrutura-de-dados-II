#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}node_t;

node_t* criar_Node(int data){
    node_t* node = (node_t*) malloc(sizeof(node_t));
    node->data = data;
    node->next = NULL;
    return node;
}

node_t* inserir_Node(int data, node_t* node){
    if(node == NULL){
        return criar_Node(data);
    }
    while(node->next != NULL)
        node = node->next;
    node->next = criar_Node(data);

}

void printar_Lista(node_t* node){
    if(node == NULL) return;

    if(node->data != -1)
    printf(" -> %d", node->data);

    printar_Lista(node->next);
}

int funcao_Hash(int x, int mod){
    return x%mod;
}

void imprime_tabela(node_t** tabela, int m){
    int i = 0;
    for (i = 0; i <m; i++) {
        printf("%d", i);
        printar_Lista(tabela[i]);
        printf(" -> \\\n");
    }

}

int main() {


    int n, flag = 1, i = 0, j = 0;
    scanf("%d",&n);
    while(n--){
        node_t ** tabela;
        int m, c; //m é mod, c é quantidade de numeros a serem lidos
        scanf("%d %d", &m,&c);

        tabela = (node_t**)malloc(sizeof(node_t*)*m); // iniciando o vetor de listas
        for (j = 0; j < m; j++) { //iniciando as listas com -1
            tabela[j] = inserir_Node(-1,tabela[j]);
        }

        for (i = 0; i <c ; i++){
            int x, aux;
            scanf("%d",&x);
            aux = funcao_Hash(x,m);
            inserir_Node(x,tabela[aux]);
        }

        if(!flag) printf("\n");
        flag = 0;
        imprime_tabela(tabela,m);

    }



/*

    node_t ** vetor;
    vetor=  (node_t**) malloc(sizeof(node_t*)*10);
    for (int i = 0; i <10 ; i++) {
        vetor[i] = inserir_Node(20,vetor[i]);
        inserir_Node(23,vetor[i]);


        printf("%d %d\n", vetor[i]->data,vetor[i]->next->data);
    }
*/
 /*
    node_t* lista = inserir_Node(11,lista);
    inserir_Node(23,lista);
    inserir_Node(34,lista);
    inserir_Node(24,lista);
    inserir_Node(10,lista);

    printar_Lista(lista);
*/
    return 0;
}