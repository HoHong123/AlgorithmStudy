/*
이진트리 순회 3가지
각 노드가 최대 2개의 자식노드를 가질 때 이진트리라고 한다. 따라서, 이진트리는 자식이 없을 수도 있고 하나만 있을 수도 있다. 
트리를 계속 서브트리로 쪼갠다. 

전위순회 (preorder) : 루트, 왼쪽자식, 오른쪽자식
루트 노드 방문 (최상단)
왼쪽 서브트리 preorder 
오른쪽 서브트리 preorder

중위순회 (inorder) : 왼쪽자식, 루트, 오른쪽자식
왼쪽 서브트리 inorder (왼쪽 서브트리가 없어질때까지 안올라옴), 다없어지면 그때 왼쪽자식, 루트, 오른쪽자식 순회 (inorder)
루트 노드 방문 (최상단)
오른쪽 서브트리 inorder

후위순회 (postorder) : 왼쪽자식, 오른쪽자식, 루트
왼쪽 서브트리 postorder
오른쪽 서브트리 postorder
루트 노트 방문 (최상단 노드, 맨 마지막에 방문)
*/

#include <iostream>

using namespace std;


struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
};

//노드 초기화 함수. 
//data는 입력받은 값으로 저장, left와 right 포인터는 null포인터로 초기화.
TreeNode* new_node(char data) {
	TreeNode* newNode = new TreeNode();
	newNode->data = data;
	newNode->left = nullptr;
	newNode->right = nullptr;
	return newNode;
}

//input으로 현재값, 왼쪽값, 오른쪽값 다 받았을 경우에 노드 생성 함수. 
void create_node(TreeNode* node, char data, char left, char right){
	node->data = data;
	if (left != '.') {
        //왼쪽 자식노드를 생성해 그것을 가리킨다. 현재 왼쪽 자식노드는 값 말고 아는 것이 없으므로 new_node로 초기화.
		node->left = new_node(left);
	}
	if (right != '.') {
		//오른쪽 자식노드를 생성해 그것을 가리킨다. 
        node->right = new_node(right);
	}
}

TreeNode* search_node(TreeNode* next, char key) {
	if (next == nullptr) return nullptr;
	else {
        //자신이 nullptr이 아니고 찾는 노드라면 자신 반환
		if (next->data == key) return next;

        //왼쪽 트리로 계속 들어가며 찾는 노드인지 검사 (왼쪽 자식노드 검사)
        //맨 왼쪽까지 들어가면 자식노드가 없으므로 nullptr이 되어 자기 자신(왼쪽 자식노드)으로 돌아와 다음 코드 실행됨
		TreeNode* leftNode = search_node(next->left, key);

        //만약 next 왼쪽 자식노드가 nullptr이 아니면 왼쪽 노드를 반환
		if (leftNode != nullptr) return leftNode;
        //그렇지 않다면 next 오른쪽 자식노드 반환. 오른쪽 노드도 nullptr이라면 그 윗단계(next)로 올라감
		return search_node(next->right, key);
	}
	
}

void preorder_tree(TreeNode* tree);
void inorder_tree(TreeNode* tree);
void postorder_tree(TreeNode* tree);

int main()
{
    int N;
    cin >> N;
    
    TreeNode* tree = new_node(NULL);
    
    for(int i = 0; i<N ; i++){
        char data, left, right;
        cin >> data >> left >> right;
        
        //tree에서 data 값을 가진 노드 검색
        TreeNode* tempNode = search_node(tree, data);

        //tree에 data 값을 가진 노드가 있다면 해당 노드에 값을 저장하고 자식 노드를 달아줌
		if (tempNode != nullptr) {			
			create_node(tempNode, data, left, right);
		}
        //만약 tree에 data값을 가진 노드가 없다면(맨 처음 트리에 노드를 저장할 때) tree에 노드를 달아줌
		else {
			create_node(tree, data, left, right);			
		}
    }

    preorder_tree(tree);
    cout << '\n';
    inorder_tree(tree);
    cout << '\n';
    postorder_tree(tree);

}


void preorder_tree(TreeNode* tree)
{   
    //함수를 재귀적으로 호출하다 더이상 넘겨줄 자식노드가 존재하지 않으면 자신을 호출했던 윗단계 함수에게 return을 반환.
    //윗단계 함수는 그 다음 코드 실행
    if (tree == nullptr) return;

    //루트, 왼쪽, 오른쪽 순으로 방문
    cout << tree->data;
    preorder_tree(tree->left);
    preorder_tree(tree->right);
}
void inorder_tree(TreeNode* tree)
{
    if (tree == nullptr) return;

    inorder_tree(tree->left);
    cout << tree->data;
    inorder_tree(tree->right);
}
void postorder_tree(TreeNode* tree)
{
    if (tree == nullptr) return;

    postorder_tree(tree->left);
    postorder_tree(tree->right);
    cout << tree->data;
}




