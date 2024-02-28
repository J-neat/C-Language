// Tree2.c
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {//노드의 타입 정의
	int key;//키 값
	Node *right;//오른쪽 자식 노드
	Node *left;//왼쪽 자식 노드

}Node;

Node* insert(Node* root, int key) {
	Node* pos;//위치
	Node* newNode = (Node*)malloc(sizeof(Node));//초기화
	newNode->key = key;//newNnode.key 의 의미는 newNode.key이다.
	newNode->left = newNode->right = NULL;//초기화

	if (root == NULL) {//루트 노드 받는 경우
		root = newNode;
		return root;
	}

	pos = root;
	//위치에 처음 입력인 root 노드 할당
	while (pos) {
		if (key > pos->key) {
			if (pos->right == NULL) {
				pos->right = newNode;//오른쪽 서브
				return root;
			}
			else {
				pos = pos->right;
			}
		}
		else {//왼쪽 서브
			if (pos->left == NULL) {
				pos->left = newNode;
				return root;
			}
			else {
				pos = pos->left;
			}
		}
	}
}

void print(Node* root) {
	if (root == NULL) {
		return;
	}
	printf("%d ", root->key);
	print(root->left);//출력시 전회 순회방식이므로 왼쪽부터
	print(root->right);
}



int main()
{
	Node* root = NULL;
	Node* pos = NULL;

	while (1) {
		int num;
		int key;

		printf("\n0: 종료\n1: 검색 \n2: 삽입\n3: 삭제\n4: 출력\n메뉴를 선택하세요: ");
		scanf_s("%d", &num);

		switch (num) {

		case 0:
			return;
		case 1:
			printf("검색할 키 값을 입력하세요: ");


			break;
		case 2:
			printf("삽입할 키 값을 입력하세요: ");
			scanf_s("%d", &key);

			root = insert(root, key);//삽입
			break;
		case 3:
			printf("삭제할 키 값을 입력하세요: ");
			break;
		case 4:
			printf("출력결과 >>");//출력값 적을것
			print(root);
			break;
		}
	}
}
