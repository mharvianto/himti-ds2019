#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

struct node{
	// data
	char nama[50];
	int nilai;
	// link
	struct node *prev, *next;
} *head, *tail;

void push_head(char nama[], int nilai) {
	node *curr = (node*)malloc(sizeof(node));
	strcpy(curr->nama, nama);
	curr->nilai = nilai;
	if(!head) { // head kosong
		head = tail = curr;
	} else {
		curr->next = head;
		head->prev = curr;
		head = curr;
	}
	head->prev = tail->next = 0;
}

void push_tail(char nama[], int nilai) {
	node *curr = (node*)malloc(sizeof(node));
	strcpy(curr->nama, nama);
	curr->nilai = nilai;
	if(!head) { // head kosong
		head = tail = curr;
	} else {
		curr->prev = tail;
		tail->next = curr;
		tail = curr;
	}
	head->prev = tail->next = 0;
}

void pop_head() {
	if(head) {
		if(head == tail) { // cuma 1 data
			free(head);
			head = tail = 0;
		} else {
			node *curr = head;
			head = head->next;
			head->prev = 0;
			free(curr);
		}
	}
}

void pop_tail() {
	if(head) {
		if(head == tail) { // cuma 1 data
			free(head);
			head = tail = 0;
		} else {
			node *curr = tail;
			tail = tail->prev;
			tail->next = 0;
			free(curr);
		}
	}
}

void view() {
	node *curr = head;
	while(curr) {
		printf("%s - %d\n", curr->nama, curr->nilai);
		curr = curr->next;
	}
}

void pop_all() {
	while(head) {
		pop_head();
	}
}

void push_middle(char nama[], int nilai){
	if(!head) {
		push_head(nama, nilai);
	} else {
		if(strcmp(nama, head->nama) < 0) {
			push_head(nama, nilai);
		} else if(strcmp(nama, tail->nama) > 0) {
			push_tail(nama, nilai);
		} else {
			node *search = head;
			while(strcmp(nama, search->next->nama) > 0){
				search = search->next;
			}
			
			node *curr = (node*)malloc(sizeof(node));
			strcpy(curr->nama, nama);
			curr->nilai = nilai;
			
			curr->next = search->next;
			curr->prev = search;
			search->next->prev = curr;
			search->next = curr;
		}
	}
}

void pop_middle(char nama[]) {
	if(head){
		node *search = head;
		while(search && strcmp(nama, search->nama) != 0) {
			search = search->next;
		}
		
		if(search) {
			if(search == head) {
				pop_head();
			} else if(search == tail) {
				pop_tail();
			} else {
				search->next->prev = search->prev;
				search->prev->next = search->next;
				free(search);
			}
		}
	}
}

int main(){
	push_middle("Kevin", 88);
	push_middle("Jojo", 75);
	push_middle("Bibi", 90);
	push_middle("Lili", 65);
	push_middle("Dodo", 82);
	push_middle("Ibnu", 85);
	view();
	puts(""); // printf("%s\n", "");
	//pop_head();
	//pop_tail();
	pop_middle("Kaka");
	pop_middle("Bibi");
	pop_middle("Lili");
	pop_middle("Ibnu");
	view();
	return 0;
}
