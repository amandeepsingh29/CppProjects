#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*left,*right;

    Node(int d){
        this->data=data;
        this->left=this->right=NULL;
    }

};







Node* InsertIntoBST(Node*root, int d){
    if (root==NULL){
        root=new Node(d);
        return root;
    }
    if(root->data<d){
        root->right=InsertIntoBST(root->right,d);
    }
    else{
        root->left=InsertIntoBST(root->left,d);
    }

    return root;
}



void inorder(Node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* minVal(Node* root){
    Node*temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
void takevalues(Node* &root){
    int value;
    cin>>value;
    while(value!=-1){
        root=InsertIntoBST(root,value);
        cin>>value;
    }
}


int main(){
    Node*root=NULL;

    cout<<"enter values for BST"<<endl;
    takevalues(root);
    cout<<endl;


}




// deleting a node from BST 
// 0 child 
// 1 child
// 2 children


Node* deleteFromBST(Node* root,int x){
    if(root==NULL){
        return root;
    }
    if(root->data==x){
        // 0child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        // 1child
        // left child
        if(root->left!=NULL && root->right==NULL){
            Node*temp=root->left;
            delete root;
            return temp;
        }

        // right child
        if(root->left==NULL && root->right!=NULL){
            Node*temp=root->right;
            delete root;
            return temp;}

        // 2child
        if(root->left!=NULL && root->right!=NULL){
            int mini=minVal(root->right)->data;
            root->data=mini;
            root->right=deleteFromBST(root->right,mini);
            return root;
        }

    }
    if(root->data<x){
        root->right=deleteFromBST(root->right,x);
        return root;
    }
    if(root->data>x){
        root->left=deleteFromBST(root->left,x);
        return root;
    }
}


































