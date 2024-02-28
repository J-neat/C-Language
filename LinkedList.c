// Practice.c 201921624 컴퓨터정보공학부 김정효
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
	char name[100];//데이터 저장할 변수들
	int student_ID;
	int status;

	struct Node* next;//다음 노드를 가리킬 포인터
}Node;

typedef struct LinkedList {
	Node* head;
	Node* tail;
	int size;
}LinkedList;

void CreateList() {
	struct Node* list = NULL;
	struct Node* node = NULL;
	struct Node* cur = NULL;

	struct Node* head = malloc(sizeof(struct Node));
	head->next = NULL;

	if (list == NULL) {
		list = node;
	}
	else {
		cur = list;
		while (cur->next != NULL) {
			cur = cur->next;
		}
	}
}
void add(LinkedList* linked, char name[]) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	strcpy(tmp->name, name);
	strcpy(tmp->student_ID, student_ID);
	strcpy(tmp->status, status);

	linked->tail->next = tmp;
	linked->tail = tmp;
	++linked->size;
}
void inset(LinkedList* linked, int n, char name[]) {
	if (n == size(linked) + 1) {
		add(linked, name);
		add(linked, student_ID);
		add(linked, status);
	}
		
	else if (n > size(linked) + 1 || n < 1)
		printf("노드 삽입 불가\n");
	else {
		Node* tmp = (Node*)malloc(sizeof(Node));
		strcpy(tmp->name, name);
		strcpy(tmp->student_ID, student_ID);//아이디 작성
		strcpy(tmp->status, status);//상태 작성

		Node* pre = linked->head;
		while (--n)
			pre = pre->next;

		tmp->next = pre->next;
		pre->next = tmp;
		++linked->size;
	}
}

int main(void) {
	CreateList();

}