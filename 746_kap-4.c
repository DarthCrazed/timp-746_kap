#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	int value;
	struct node *next;
	struct node *prev;
} node;

typedef node* list;

// инициализация списка
int init(list *root){
	*root = NULL;
	return 1;
}

// удаление списка
int destroy(list *root){
	list nodde;
	while(*root != NULL){
		nodde = *root;
		*root = (*root)->next;
		free(nodde);
	}
return 1;
}

// проверка списка на пустоту
bool isEmpty(list root){
	if(root != NULL){
		return 1;
		}
	else{
		return 0;
	}
}

// поиск элемента по значению, вернуть NULL, если элемент не найден
list find(list root, int value){
	while(root->value != value){
		if(root == NULL){
			return NULL;
		}
		root = root->next;
	}
	return root;
}


//добавление в начало очереди
int pushbegin(list *root,int value)
{
    if(((*root) == NULL)){
		list nodde = (list)malloc(sizeof(node));
		nodde->value = value;
		nodde->next = NULL;
		nodde->prev = NULL;
		*root = nodde;
		return 1;
	}
	else
		{
		list nodde = (list)malloc(sizeof(node));
		nodde->value = value;
		nodde->next = *root;
		nodde->prev = NULL;
		(*root)->prev = nodde;
		(*root) = (*root)->prev;
		return 1;
		}

}

//удаление из начала очереди
int popbegin(list *root)
{
    if (*root == NULL)
        return NULL;
    int val = (*root)->value;
    if (*root != NULL) {
		list nodde = *root;
		if ((*root)->next != NULL) {
			(*root)->next->prev = NULL;
			(*root) = (*root)->next;
		}
		free(nodde);
	}
	return val;
}

//добавление в конец очереди
int pushback(list *root,int value)
{
    list nodde = *root;
    while((nodde)->next != NULL)
	{
		nodde = (nodde)->next;
	}
       thepushback(&nodde, value);
}

int thepushback(list *root,int value)
{
    if(((*root) == NULL)){
		list nodde = (list)malloc(sizeof(node));
		nodde->value = value;
		nodde->next = NULL;
		nodde->prev = NULL;
		*root = nodde;
		return 1;
	}else
		if((*root)->next == NULL){
			list nodde = (list)malloc(sizeof(node));
			nodde->value = value;
			nodde->next = NULL;
			nodde->prev = *root;
			(*root)->next = nodde;
			return 1;
		}

}

//удаление из конца очереди
int popback(list *root)
{
    int val;
    list nodde = *root;
    while((nodde)->next != NULL)
	{
		nodde = (nodde)->next;
	}
    val = thepopback(&nodde);
    return val;
}

int thepopback(list *root)
{
    int val;
    val = (*root)->value;
    if (*root != NULL) {
		list nodde = *root;
		if (((*root)->next == NULL) && ((*root)->prev != NULL)) {
			(*root)->prev->next = NULL;
		}
		free(nodde);
	}
	return val;
}


int print(list *root){
	list nodde = *root;
	do{
		printf("%d ", nodde->value);
		nodde = nodde->next;
	}
	while( nodde != NULL);

	printf("\n");

	return 1;
}

int main()
{
	int a;
	list root, nodde;
	init(&root);

	pushbegin(&root,3);
	print(&root);
	pushbegin(&root,4);
	print(&root);
	pushbegin(&root,7);
	print(&root);


	a=popbegin(&root);
	print(&root);
	printf("%d \n", a);
	a=popbegin(&root);
	print(&root);
	printf("%d \n", a);


	pushback(&root,5);
	print(&root);
	pushback(&root,9);
	print(&root);
	pushback(&root,0);
	print(&root);


	a = popback(&root);
	print(&root);
	printf("%d \n", a);
	a = popback(&root);
	print(&root);
	printf("%d \n", a);
	a = popback(&root);
	print(&root);
	printf("%d \n", a);


	return 0;
}

