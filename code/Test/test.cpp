#include <iostream>
#include <vector>
#include <queue>


//binary tree 資料結構
struct Node
{
	Node* parent;
	Node* left;
	Node* right;
	int data;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// 即是breadth-first search。
// level-order traversal 層序遍歷
void bfs(Node* root) {
    if (!root) return;

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        std::cout << current->data << " ";  // 輸出節點資料

        if (current->left) {
            q.push(current->left);
        }
        if (current->right) {
            q.push(current->right);
        }
    }
}

// 即是depth-first search。
// 前序遍歷 (Preorder: 根 -> 左 -> 右)
void preorder(Node* root) {
    if (!root) return;
    std::cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// 即是depth-first search。
// 中序遍歷 (Inorder: 左 -> 根 -> 右)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

// 即是depth-first search。
// 後序遍歷 (Postorder: 左 -> 右 -> 根)
void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    std::cout << root->data << " ";
}

int main()
{

   // 建立簡單的樹
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->parent = root;
    root->right->parent = root;

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->parent = root->left;
    root->left->right->parent = root->left;

    // std::cout << "BFS result: ";
    // bfs(root);
    // std::cout << std::endl;

    std::cout << "Preorder: ";
    preorder(root);
    std::cout << std::endl;

    std::cout << "Inorder: ";
    inorder(root);
    std::cout << std::endl;

    std::cout << "Postorder: ";
    postorder(root);
    std::cout << std::endl;

    return 0;
}
