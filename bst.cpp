#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	char nama[50];
	int nilai;
	struct node *left, *right;
}*root;

void push(node **curr, char nama[], int nilai){
	if(!(*curr)) {
		*curr = (node*)malloc(sizeof(node));
		strcpy((*curr)->nama, nama);
		(*curr)->nilai = nilai;
		(*curr)->left = (*curr)->right = 0;
	} else {
		if(strcmp(nama, (*curr)->nama) < 0) {
			push(&(*curr)->left, nama, nilai);
		} else if(strcmp(nama, (*curr)->nama) > 0) {
			push(&(*curr)->right, nama, nilai);
		}
	}
}

void view(node *curr, int level){
	if(curr){
		view(curr->right, level+1);
		for(int i=0;i<level;i++)printf("\t");
		printf("%s - %d\n", curr->nama, curr->nilai);
		view(curr->left, level+1);
	}
}

void in_order(node *curr) { // lmr
	if(curr){
		in_order(curr->left);
		printf("%s - %d\n", curr->nama, curr->nilai);
		in_order(curr->right);
	}
}
void pre_order(node *curr) { // mlr
	if(curr){
		printf("%s - %d\n", curr->nama, curr->nilai);
		pre_order(curr->left);
		pre_order(curr->right);
	}
}
void post_order(node *curr) { // lrm
	if(curr){
		post_order(curr->left);
		post_order(curr->right);
		printf("%s - %d\n", curr->nama, curr->nilai);
	}
}

void pop_all(node **curr){
	if(*curr){
		pop_all(&(*curr)->left);
		pop_all(&(*curr)->right);
		free(*curr);
		*curr = 0;
	}
}

int main(){
	push(&root, "Kevin", 88);
	push(&root, "Jojo", 75);
	push(&root, "Bibi", 90);
	push(&root, "Lili", 65);
	push(&root, "Zozo", 82);
	push(&root, "Kaka", 85);
	view(root, 0); puts("");
	in_order(root); puts("");
	pre_order(root); puts("");
	post_order(root); puts("");
	pop_all(&root);
	return 0;
}
