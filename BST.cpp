#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;

};

struct node* newNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root->left != NULL){
    traverseInOrder(root->left);
  }

  cout << root->key << " , ";

  if(root->right!=NULL){
    traverseInOrder(root->right);
  }

}

struct node *findMinimum(struct node *node){
while(node->left!=NULL){
  node=node->left;
}
return node;
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
  
   
    if (node == NULL){
        return newNode(key);
    }
    
    if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);

    return node;

}
struct node *deleteNode(struct node *root, int key){
   if (root==NULL){
  return root;
 }
 if (key<root->key){
  root->left=deleteNode(root->left,key);
 }else if(key>root->key){
  root->right = deleteNode(root->right,key);
 }else {
  root=root->right;
 
 
 }
 return root;
}

// Deleting a node

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}
