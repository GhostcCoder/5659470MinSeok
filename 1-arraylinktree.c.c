/* 전위 순회: 현재 노드 -> 왼쪽 자식 -> 오른쪽 자식
 중위 순회: 왼쪽 자식 -> 현재 노드 -> 오른쪽 자식
 후위 순회: 왼쪽 자식 -> 오른쪽 자식 -> 현재 노드
 동일한 내용의 배열- 트리와 연결 리스트- 트리를 각각 생성하고, 각자의 순회를 비교
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;                // 노드 데이터
    struct TreeNode *left;   // 왼쪽 자식 노드
    struct TreeNode *right;  // 오른쪽 자식 노드
} TreeNode;

// 배열- 전위 순회
void ArrayPreOrder(int *tree, int index, int size) {
    if (index >= size || tree[index] == 0) return;  // 배열 범위를 벗어나거나 노드가 없으면 종료
    printf("%d ", tree[index]);                     // 현재 노드 출력
    ArrayPreOrder(tree, 2 * index + 1, size);       // 왼쪽 자식 순회
    ArrayPreOrder(tree, 2 * index + 2, size);       // 오른쪽 자식 순회
}

// 배열- 중위 순회
void ArrayInOrder(int *tree, int index, int size) {
    if (index >= size || tree[index] == 0) return;  // 배열 범위를 벗어나거나 노드가 없으면 종료
    ArrayInOrder(tree, 2 * index + 1, size);        // 왼쪽 자식 순회
    printf("%d ", tree[index]);                     // 현재 노드 출력
    ArrayInOrder(tree, 2 * index + 2, size);        // 오른쪽 자식 순회
}

// 배열- 후위 순회
void ArrayPostOrder(int *tree, int index, int size) {
    if (index >= size || tree[index] == 0) return;  // 배열 범위를 벗어나거나 노드가 없으면 종료
    ArrayPostOrder(tree, 2 * index + 1, size);      // 왼쪽 자식 순회
    ArrayPostOrder(tree, 2 * index + 2, size);      // 오른쪽 자식 순회
    printf("%d ", tree[index]);                     // 현재 노드 출력
}


// 배열 순회 함수 호출
void ArrayOrders(int *tree, int size) {
    ArrayPreOrder(tree, 0, size);   //전위
    printf("\n");
    ArrayInOrder(tree, 0, size);    //중위
    printf("\n");
    ArrayPostOrder(tree, 0, size);  //후위
    printf("\n");
}

// 배열 트리 생성 함수
void GenerateArrayTree(int *tree) {
    int list[] = {1, 2, 3, 4, 6, 5, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    // list 배열(의 값을) tree 배열에 복사
    for (int i = 0; i < 15; i++) {
        tree[i] = list[i];
    }
    //tree 배열 출력
    for (int i = 0; i < 15; i++) {
        printf("%d ", tree[i]);
    }
    printf("\n");
}

// 노드를 트리에 추가하는 함수
void PlaceNode(TreeNode *node, int direction, int data) {
    // 새로운 노드를 생성하고 데이터 값을 설정    
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    // direction 값에 따라 왼쪽 또는 오른쪽 자식 설정
    if (direction == 0) {
        node->left = newNode;
    } else {
        node->right = newNode;
    }
}

// 링크드 리스트로 트리를 생성하는 함수
TreeNode* GenerateLinkTree() {
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    root->data = 1;
    root->left = NULL;
    root->right = NULL;
    PlaceNode(root, 0, 2);
    PlaceNode(root, 1, 3);
    PlaceNode(root->left, 0, 4);
    PlaceNode(root->left, 1, 6);
    PlaceNode(root->right, 0, 5);
    PlaceNode(root->right, 1, 7);
    PlaceNode(root->left->left, 0, 8);
    PlaceNode(root->left->left, 1, 9);
    PlaceNode(root->left->right, 0, 10);
    PlaceNode(root->left->right, 1, 11);
    PlaceNode(root->right->left, 0, 12);
    PlaceNode(root->right->left, 1, 13);
    PlaceNode(root->right->right, 0, 14);
    PlaceNode(root->right->right, 1, 15);
    return root;
}

// 링크드 리스트를 이용한 전위 순회 함수
void LinkPreOrder(TreeNode *node) {
    if (node == NULL) return;           // 노드가 NULL이면 종료
    printf("%d ", node->data);          // 현재 노드 출력     
    LinkPreOrder(node->left);           // 왼쪽 자식 순회  
    LinkPreOrder(node->right);          // 오른쪽 자식 순회
}

// 링크드 리스트를 이용한 중위 순회 함수
void LinkInOrder(TreeNode *node) {
    if (node == NULL) return;          
    LinkInOrder(node->left);           // 왼쪽 자식 순회
    printf("%d ", node->data);         // 현재 노드 출력
    LinkInOrder(node->right);          // 오른쪽 자식 순회
}

// 링크드 리스트를 이용한 후위 순회 함수
void LinkPostOrder(TreeNode *node) {
    if (node == NULL) return;          
    LinkPostOrder(node->left);         // 왼쪽 자식 순회
    LinkPostOrder(node->right);        // 오른쪽 자식 순회
    printf("%d ", node->data);         // 현재 노드 출력
}

// 링크드 리스트 순회 함수 호출
void LinkOrders(TreeNode *root) {
    LinkPreOrder(root);   // 전위 순회
    printf("\n");
    LinkInOrder(root);    // 중위 순회
    printf("\n");
    LinkPostOrder(root);  // 후위 순회
    printf("\n");
}


int main() {
    int arr[15];
    TreeNode *root = NULL;

    // 각각 배열, 연결 리스트로 트리 생성
    GenerateArrayTree(arr);
    root = GenerateLinkTree();

    // 각 방법으로 순회
    printf("Array Orders:\n");
    ArrayOrders(arr, 15);

    printf("Link Orders:\n");
    LinkOrders(root);

    return 0;
}