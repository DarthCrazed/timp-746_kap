#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
int value;
struct node next;
struct node prev;
} node;

typedef node list;

int init(list root){
root = NULL;
return 1;
}

int destroy(list root){
list nodde;
while(root != NULL){
nodde = root;
root = (root)-next;
free(nodde);
}
return 1;
}

bool isEmpty(list root){
if(root != NULL){
return 1;
}
else{
return 0;
}
}

list find(list root, int value){
while(root-value != value){
if(root == NULL){
return NULL;
}
root = root-next;
}
return root;
}


int append(list lst, int value){
if(((lst) == NULL)){
list nodde = (list)malloc(sizeof(node));
nodde-value = value;
nodde-next = NULL;
nodde-prev = NULL;
lst = nodde;
return 1;
}else if((lst)-next == NULL){
list nodde = (list)malloc(sizeof(node));
nodde-value = value;
nodde-next = NULL;
nodde-prev = lst;
(lst)-next = nodde;
return 1;
}else{
list nodde = (list)malloc(sizeof(node));
nodde-next = (lst)-next;
nodde-value = value;
nodde-prev = lst;
(lst)-next-prev = nodde;
(lst)-next = nodde;
return 1;
}
}


int prepend(list lst, int value){
if(((lst) == NULL)){
list nodde = (list)malloc(sizeof(node));
nodde-value = value;
nodde-next = NULL;
nodde-prev = NULL;
lst = nodde;
return 1;
}else if((lst)-prev == NULL){
list nodde = (list)malloc(sizeof(node));
nodde-value = value;
nodde-next = lst;
nodde-prev = NULL;
(lst)-prev = nodde;
(lst) = (lst)-prev;
return 1;
}else{
list nodde = (list)malloc(sizeof(node));
nodde-prev = (lst)-prev;
nodde-value = value;
nodde-next = lst;
(lst)-prev-next = nodde;
(lst)-prev = nodde;
return 1;
}
}


int remove1(list lst){
if (lst != NULL) {
list nodde = lst;
if (((lst)-next != NULL) && ((lst)-prev != NULL)) {
(lst)-prev-next = (lst)-next;
(lst)-next-prev = (lst)-prev;
}
if (((lst)-next != NULL) && ((lst)-prev == NULL)) {
(lst)-next-prev = NULL;
(lst) = (lst)-next;
}
if (((lst)-next == NULL) && ((lst)-prev != NULL)) {
(lst)-prev-next = NULL;
}
free(nodde);
}
return 1;
}

 вывод списка в stdout в прямом порядке через пробел
int print(list lst){
list nodde = lst;
do{
printf(%d , nodde-value);
nodde = nodde-next;
}
while( nodde != NULL);

printf(n);

return 1;
}

int main()
{
list root, nodde;
init(&root);
int n, i, k, m, a, c, x, b, d;


scanf("%d", &n);
while(n<0){
printf("Error! Invalid number\n");
scanf("%d", &n);
}
scanf("%d", &x);
append(&root, x);
nodde = root;


for(i = 1; i=<n; i++){
scanf("%d", &x);
append(&nodde, x);
nodde = nodde->next;
}
print(&root);


scanf("%d", &k);

while(n<k){
printf("Error! Invalid number\n");
scanf("%d", &k);
}

if(k==1){
remove1(&root);
}else{
nodde = root;
for(i=1; i=<k; i++){
nodde = nodde->next;
}
remove1(&nodde);
}
print(&root);


scanf("%d", &m);

nodde = find(root, m);

if(nodde == root){
remove1(&root);
}else{
remove1(&nodde);
}
print(&root);


scanf("%d%d", &a, &b);
nodde = root;
for(i=1; i=<a; i++){
nodde=nodde->next;
}
ap
pend(&nodde, b);

print(&root);


scanf("%d%d", &c, &d);
if(c==1){
prepend(&root, d);
}else{
nodde = root;
for(i=1; i=<c; i++){
nodde=nodde->next;
}
prepend(&nodde, d);
}

print(&root);

return 0;
}
