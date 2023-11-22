#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;

    }
};

Node* InsertIntoBST(Node* root, int d){
    // base case
    if(root==NULL){
        root = new Node(d);
        return root;
    }
    if(root->data<d){
        // left part mai insert karna hn
        root->right=InsertIntoBST(root->right,d);
    }
    else{
        // right part mai insert karna hn
        root->left=InsertIntoBST(root->left,d);
    }
    return root;
}

void takeInput(Node * &root){
    int data;
    cin>>data;
    while(data !=-1){
        root=InsertIntoBST(root,data);
        cin>>data;
    }

}

Node* minVal(Node* root){
    Node*temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

Node* maxVal(Node* root){
    Node*temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}

void inorder(Node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
bool searching_BST_recursive(Node*root,int x){
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

Node* deleteFromBST(Node*root,int val){
    if(root==NULL){
        return root;
    }
    if(root->data==val){
        // 0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        // 1 child
        //left child
        if(root->left!=NULL && root->right==NULL){
            Node* temp= root->left;
            delete root;
            return temp;
        }
        //right child
        if(root->right!=NULL && root->left==NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }


        // 2 child
        if(root->left!=NULL && root->right!=NULL){
            int mini=minVal(root->right)->data;
            root->data=mini;
            root->right=deleteFromBST(root->right,mini);
            return root;

        }
    }

    if(root->data<val){
        root->right=deleteFromBST(root->right,val);
        return root;
    }
    else if(root->data>val){
        root->left=deleteFromBST(root->left,val);
        return root;
    }
}



int main(){
    Node* root=NULL;
    cout<<"Enter values into BST: "<<endl;
    takeInput(root);

    // cout<<"enter number to be searched"<<endl;
    // int number;
    // cin>>number;
    // if(searching_BST_recursive(root,number)){
    //     cout<<"It's Present"<<endl;
    // }
    // else{
    //     cout<<"It's not present"<<endl;
    // }

    // cout<<endl<<"the min value of BST is "<<minVal(root)->data;
    // cout<<endl<<"the max value of BST is "<<maxVal(root)->data;
    inorder(root);
cout<<endl;
    deleteFromBST(root,40);
cout<<endl;
    inorder(root);


}