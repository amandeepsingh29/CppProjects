ool searching_BST_recursive(Node*root,int x){
    if(root==NULL){
        return false;
    }
    if(root->data==x){
        return true;
    }
    if(root->data<x){
        searching_BST_recursive(root->right,x);
    }
    if(root->data>x){
        searching_BST_recursive(root->left,x);
    }
}