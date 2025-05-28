#ifndef BST_H
#define BST_H

#include <string>
using namespace std;

// 하나의 노드를 나타내는 클래스
class Node {
public:
    int key;            // 노드의 키 값 (BST의 정렬 기준)
    string value;       // 노드에 저장될 문자열 값
    Node* left;         // 왼쪽 자식 노드 (작은 key)
    Node* right;        // 오른쪽 자식 노드 (큰 key)

    // 생성자: key, value를 초기화하고 자식 노드는 nullptr로 설정
    Node(int k, string v) {
        key = k;
        value = v;
        left = nullptr;
        right = nullptr;
    }
};

// 이진 탐색 트리를 관리하는 클래스
class BST {
private:
    Node* root; // 트리의 루트 노드

    // 새로운 노드를 삽입하는 재귀 함수
    Node* insert(Node* node, int key, string value);

    // 노드를 삭제하는 재귀 함수. found는 삭제 성공 여부를 반환
    Node* removeNode(Node* node, int key, bool& found);

    // 주어진 서브트리에서 최소 key를 가진 노드를 찾음 (삭제 시 필요)
    Node* findMin(Node* node);

    // 중위 순회를 통해 (key, value) 쌍을 출력
    void inorder(Node* node);

public:
    // 생성자: 루트를 nullptr로 초기화
    BST();

    // 주어진 key와 value를 트리에 삽입 (중복은 무시)
    void add(int key, string value);

    // 주어진 key를 가진 노드를 트리에서 삭제
    void remove(int key);

    // 트리를 중위 순회하여 출력
    void print();
};

#endif