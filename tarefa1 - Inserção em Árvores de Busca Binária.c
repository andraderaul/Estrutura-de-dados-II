#include <stdio.h>
#include <stdlib.h>


struct node{
	int key;
	struct node *left;
	struct node *right;
};

// criando um novo no para arvore
struct node* newNode(int key){
	struct node *temp = (struct node*)malloc(sizeof(struct node)); 
	temp->key = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

// percurso em ordem
void inorder(struct node *root){
	printf(" (");
	if(root != NULL){
		printf(" %d ", root->key);
		inorder(root->left);
		inorder(root->right);
	}
	printf(") ");
}
	
// inserir um novo no na arvore de busca
struct node* insert(struct node* node, int key){
	
	// checando se a arvore esta vazia
	if(node == NULL) return newNode(key);
	
	//inserindo na arvore
	if(key < node->key) node->left = insert(node->left, key);
	else if(key >= node->key) node->right = insert(node->right,key);
	
	
	return node;		
}

int main(){
	
	struct node *root = NULL;
	
	int n, flag = 0;
	while(scanf("%d", &n)!=EOF){
		if(flag == 1){
			insert(root,n);
		}
		else{
			root = insert(root,n);
			flag = 1;
		}
		printf("----\n");
		printf("Adicionando %d\n  ", n);
		inorder(root);
		printf("\n");
	}
	printf("----\n");
	
	
	return 0;
}
