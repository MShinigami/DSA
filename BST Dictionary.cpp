#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Dictnode{
public:
    string key;
    string value;
    Dictnode* left;
    Dictnode* right;
    Dictnode(const string& k, const string& v): key(k), value(v), left(nullptr), right(nullptr){}
};

class Dictionary{
private:
    int comparisons;
    Dictnode* root;
    vector<Dictnode*> insertionOrder;
public:
    Dictionary() : root(nullptr){}
    void add(const string& key, const string& value){
        root = addnode(root, key, value);
    }
    void remove(const string& key){
        root = removenode(root, key);
    }
    void find(const string& key){
        comparisons = 0;
        Dictnode* result = searchnode(root, key);
        if (result != nullptr){
            cout << "Key found" << endl;
            cout << "Key: " << result->key << "\nValue: " << result->value << endl;
            cout << "Number of comparisons: " << comparisons << endl;
        }
        else{
            cout << "Key not found." << endl;
        }
    }
    void update(const string& key){
        comparisons = 0;
        Dictnode* result = searchnode(root, key);
        if(result != nullptr){
            cout << "Key found" << endl;
            cout << "Enter the new value for the key: ";
            cin.ignore();
            getline(cin, result->value);
            cout << "Key: " << key << " New value: " << result->value << endl;
        }else{
            cout << "Key not found.\nAdd it first." << endl;
        }
    }
    void display(){
        if(!insertionOrder.empty()){
            for(Dictnode* node : insertionOrder){
                cout << "Key: " << node->key << "\tValue: " << node->value << endl;
            }
        }else{
            cout << "\nDictionary is empty" << endl;
        }
    }
    void ascending(){
        if(root!=nullptr){
            inorder(root);
        }else{
            cout << "\nDictionary is empty" << endl;
        }
    }
    void descending(){
        if(root!=nullptr){
            inverseInorder(root);
        }else{
            cout << "\nDictionary is empty" << endl;
        }
    }
    int Max_comparisons(){
        return max_height(root);
    }
    
private:
    Dictnode* addnode(Dictnode* node, const string& key, const string& value){
        if(node==nullptr){
            Dictnode* temp = new Dictnode(key, value);
            insertionOrder.push_back(temp);
            return temp;
        }
        int result = key.compare(node->key);
        if(result<0){
            node->left = addnode(node->left, key, value);
        }else if(result>0){
            node->right = addnode(node->right, key, value);
        }else{
            cout << "\nKey already exists." << endl;
        }
        return node;
    }
    
    Dictnode* removenode(Dictnode* node, const string& key){
        if(node==nullptr){
            return nullptr;
        }
        int result = key.compare(node->key);
        if(result<0){
            node->left = removenode(node->left, key);
        }
        else if(result>0){
            node->right = removenode(node->right, key);
        }else{
            if(node->left==nullptr){
                Dictnode* temp = node->right;
                delete node;
                return temp;
            }else if(node->right==nullptr){
                Dictnode* temp = node->left;
                delete node;
                return temp;
            }else{
                Dictnode* temp = findMin(node->right);
                node->key = temp->key;
                node->value = temp->value;
                node->right = removenode(node->right, temp->key);
            }
        }
        return node;
    }
    
    Dictnode* findMin(Dictnode* node){
        while(node->left!=nullptr){
            node = node->left;
        }
        return node;
    }
    
    Dictnode* searchnode(Dictnode* node, const string& key){
        comparisons++;
        if(node == nullptr || key == node->key){
            return node;
        }
        if(key < node->key){
            return searchnode(node->left, key);
        }
        else{
            return searchnode(node->right, key);
        }
    }

    void inorder(Dictnode* node){
        if(node!=nullptr) {
            inorder(node -> left);
            cout << node -> key << ": " << node -> value << endl;
            inorder(node -> right);
        }
    }
    
    void inverseInorder(Dictnode* node){
        if(node!=nullptr){
            inverseInorder(node->right);
            cout << node -> key << ": " << node -> value << endl;
            inverseInorder(node->left);
        }
    }

    int max_height(Dictnode* node){
        if (node == nullptr){
            return 0;
        }
        int leftheight = max_height(node->left);
        int rightheight = max_height(node->right);
        return max(leftheight, rightheight) + 1;
    }
};

int main(){
    Dictionary d;
    int choice;
    string key, value;
    do{
        cout << "\n\nMenu:\n1.Insertion\n2.Deletion\n3.Searching\n4.Display\n5.Update\n6.Ascending Display\n7.Descending Display\n8.Exit\nEnter your choice: " << endl;
        cin >> choice;
        switch(choice) {
            case 1:{
                cout << "Enter the Key: ";
                cin >> key;
                cout << "Enter the value of the key: ";
                cin.ignore();
                getline(cin, value);
                d.add(key, value);
                break;
            }
            case 2:{
                cout << "Enter the key you want to delete: ";
                cin >> key;
                d.remove(key);
                break;
            }
            case 3: {
                cout << "Enter the key you want to search: ";
                cin >> key;
                d.find(key);
                cout << "Maximum comparisons required: " << d.Max_comparisons() << endl;
                break;
            }
            case 4:{
                cout << "Dictionary: " << endl;
                d.display();
                break;
            }
            case 5:{
                cout << "Enter the keyword to update: ";
                cin >> key;
                d.update(key);
                break;
            }
            case 6:{
                cout << "Dictionary in Ascending order: ";
                d.ascending();
                break;
            }
            case 7:{
                cout << "Dictionary in Descending order: ";
                d.descending();
                break;
            }
            case 8:{
                break;
            }
            default:
                cout << "Invalid choice." << endl;
        }   
    } while(choice != 8);
    return 0;
}