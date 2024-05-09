#include<iostream>
#include<algorithm>
using namespace std;

struct Node{
    int key;
    int value;
    Node* left;
    Node* right;
};

Node* createNewNode(int key, int value){
    Node* node = new Node;
    node->key = key;
    node->value = value;
    node->left=nullptr;
    node->right=nullptr;
    return node;
}

Node* searchNode(Node* root, int key){
    if (root == nullptr || root -> key == key){
        return root;
    }
    if (key<root->key){
        return searchNode(root->left,key);
    }else{
        return searchNode(root->right,key);
    }
}

void insert(Node*& root, int key, int value){
    if (root==nullptr) {
        root = createNewNode(key, value);
    }else{
        if(root->key > key){
            if (root->left== nullptr){
                root->left = createNewNode(key, value);
            }
            else{
                insert(root->left, key, value);
            }
        }
        else if (root->key < key){
            if (root -> right == nullptr){
                root ->right = createNewNode(key, value);
            }
            else{
                insert(root->right, key, value);
            }
        }
        else{
            cout << "The key already exists in the tree"<< endl;
        }
    }
}

void display(Node* root){
    if (root!= nullptr){
        display(root->left);
        cout<<root->key<<": "<<root->value<<" ";
        display(root->right);
    }
}

int main()
{
    Node* root = nullptr;
    int choice;

    do{
        cout<<"\nMenu\n1)Insert\n2)Display\n3)Search\n4)Exit.\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:{
                int key, value;
                cout<<"Enter the key: ";
                cin>>key;
                cout<<"Enter the value: ";
                cin>>value;
                insert(root, key, value);
                break;
            }
            case 2:{
                cout<<"Dictionary Contents: ";
                display(root);
                cout<<endl;
                break;
            }
            case 3:{
                int key;
                cout<<"Enter the key you want to search:";
                cin>>key;
                Node* result = searchNode(root,key);
                if(result!=nullptr){
                    cout<<"The value associated with key "<<key<<" is "<<result->value<<endl;
                }else{
                    cout<<"The key "<<key<<" is not found in the dictionary."<<endl;
                }
                break;
            }
            case 4:
                break;
            default:
                cout<<"Invalid choice!"<<endl;
        }
    }while (choice !=4 );

    return 0;
}
