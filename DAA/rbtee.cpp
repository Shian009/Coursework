#include <bits/stdc++.h>
 using namespace std;

struct node {
    int data{};
    node* left = NULL;
    node* right = NULL;
    node* parent = NULL;
    string color;
};

 class RB_TREE {

    node* root;

    public:
        RB_TREE() : root(NULL) {}

        node* GetRoot(){ return root; }

         void InsertNode(int x) {
           if(root == NULL){
               root = new node();
               root->data = x;
               root->parent = NULL;
               root->color = "BLACK";
               cout << "Element inserted.\n";
           }
           else {
               auto linker = GetRoot();
               node* newnode = new node();
               newnode->data = x;

               while(linker != NULL){
                   if(linker->data > x){
                       if(linker->left == NULL){
                           linker->left = newnode;
                           newnode->color = "RED";
                           newnode->parent = linker;
                           cout << "Element inserted.\n"; break; }
                       else { linker = linker->left; }
                   } else {
                       if(linker->right == NULL){
                           linker->right = newnode;
                           newnode->color = "RED";
                           newnode->parent = linker;
                           cout << "Element inserted.\n"; break; }
                       else {  linker = linker->right; }
                   }
               }
            RB_Insert_Fixup(newnode);
           }
        }

        void RB_Insert_Fixup(node* z) {
            while(z->parent->color == "RED") {
                auto grandparent = z->parent->parent;
                auto uncle = GetRoot();
                if(z->parent == grandparent->left) {
                    if(grandparent->right) { uncle = grandparent->right; }
                    if(uncle->color == "RED"){
                        z->parent->color = "BLACK";
                        uncle->color = "BLACK";
                        grandparent->color = "RED";
                        if(grandparent->data != root->data){ z = grandparent; }
                        else { break; }
                    }
                    else if(z == grandparent->left->right) {
                       LeftRotate(z->parent);
                    }
                    else {
                        z->parent->color = "BLACK";
                        grandparent->color = "RED";
                        RightRotate(grandparent);
                        if(grandparent->data != root->data){ z = grandparent; }
                        else { break; }
                    }
                }
                else {
                    if(grandparent->left) { uncle = grandparent->left; }
                    if(uncle->color == "RED"){
                        z->parent->color = "BLACK";
                        uncle->color = "BLACK";
                        grandparent->color = "RED";
                        if(grandparent->data != root->data){ z = grandparent; }
                        else { break; }
                    }
                    else if(z == grandparent->right->left){
                        RightRotate(z->parent);
                    }
                    else {
                        z->parent->color = "BLACK";
                        grandparent->color = "RED";
                        LeftRotate(grandparent);
                        if(grandparent->data != root->data){ z = grandparent; }
                        else { break; }
                    }
                }
            }
            root->color = "BLACK";
        }


        void RemoveNode(node* parent, node* curr, int x) {
            if(curr == NULL) { return; }
            if(curr->data == x) {
                //CASE -- 1
                if(curr->left == NULL && curr->right == NULL) {
                    if(parent->data == curr->data){ root = NULL; }
                    else if(parent->right == curr) {
                        RB_Delete_Fixup(curr);
                        parent->right = NULL;
                    } 
                    else { 
                        RB_Delete_Fixup(curr);
                        parent->left = NULL;
                    }
                }
                //CASE -- 2
                else if(curr->left != NULL && curr->right == NULL) {
                    int swap = curr->data;
                    curr->data = curr->left->data;
                    curr->left->data = swap;
                    RemoveNode(curr, curr->right, x);
                }
                else if(curr->left == NULL && curr->right != NULL) {
                    int swap = curr->data;
                    curr->data = curr->right->data;
                    curr->right->data = swap;
                    RemoveNode(curr, curr->right, x);
                }
                //CASE -- 3
                else {
                    bool flag = false;
                    node* temp = curr->right;
                    while(temp->left) { flag = true; parent = temp; temp = temp->left; }
                    if(!flag) { parent = curr; }
                    int swap = curr->data;
                    curr->data = temp->data;
                    temp->data = swap;
                    RemoveNode(parent, temp, swap);
                }
            }
        }

        void Remove(int x) {
            auto temp = root;
            auto parent = temp;
            bool flag = false;
            if(!temp) { RemoveNode(NULL, NULL, x); }

            while(temp) {
                if(x == temp->data) { flag = true; RemoveNode(parent, temp, x); break; }
                else if(x < temp->data) { parent = temp ; temp = temp->left; }
                else { parent = temp ; temp = temp->right; }
            }

            if(!flag) { cout << "\nElement doesn't exist in the table"; }
        }

        void RB_Delete_Fixup(node* z) { 
            while(z->data != root->data && z->color == "BLACK") {
                auto sibling = GetRoot();
                if(z->parent->left == z) {
                    if(z->parent->right){ sibling = z->parent->right; }
                    if(sibling) {
                        //CASE -- 1
                        if(sibling->color == "RED") {
                            sibling->color = "BLACK";
                            z->parent->color = "RED";
                            LeftRotate(z->parent);
                            sibling = z->parent->right;
                        }
                         //CASE -- 2
                        if(sibling->left == NULL && sibling->right == NULL) {
                            sibling->color = "RED";
                            z = z->parent;
                        }
                        else if(sibling->left->color == "BLACK" && sibling->right->color == "BLACK") {
                            sibling->color = "RED";
                            z = z->parent;
                        }
                        //CASE -- 3
                        else if(sibling->right->color == "BLACK") {
                            sibling->left->color = "BLACK";
                            sibling->color = "RED";
                            RightRotate(sibling);
                            sibling = z->parent->right;
                        } else {
                            sibling->color = z->parent->color;
                            z->parent->color = "BLACK";
                            if(sibling->right){ sibling->right->color = "BLACK"; }
                            LeftRotate(z->parent);
                            z = root;
                        }
                    } 
                } else {
                    if(z->parent->right == z){
                        if(z->parent->left){ sibling = z->parent->left; }
                        if(sibling) {
                            //CASE -- 1
                            if(sibling->color == "RED"){
                                sibling->color = "BLACK";
                                z->parent->color = "RED";
                                RightRotate(z->parent);
                                sibling = z->parent->left;
                            }
                            //CASE -- 2
                             if(sibling->left == NULL && sibling->right == NULL) {
                                sibling->color = "RED";
                                z = z->parent;
                            }
                            else if(sibling->left->color == "BLACK" && sibling->right->color == "BLACK") {
                                sibling->color = "RED";
                                z = z->parent;
                            }
                            //CASE -- 3 
                            else if(sibling->left->color == "BLACK") {
                                sibling->right->color = "BLACK";
                                sibling->color = "RED";
                                RightRotate(sibling);
                                sibling = z->parent->left;
                            } else {
                                sibling->color = z->parent->color;
                                z->parent->color = "BLACK";
                                if(sibling->left){ sibling->left->color = "BLACK"; }
                                LeftRotate(z->parent);
                                z = root;
                            }
                        } 
                    }

                }
            }
            z->color = "BLACK";
        }

        node* TreeSearch(int x,string &s) {
            auto temp = GetRoot();
            s="";
            if(temp == NULL) { return NULL; }

            while(temp) {
                if(x == temp->data)
                { 
                    s=temp->color;
                    return temp;
                }
                else if(x < temp->data){ temp = temp->left; }
                else { temp = temp->right; }
            }
            return NULL;
        }

         void LeftRotate(node* x) {
            node* nw_node = new node();
            if(x->right->left) { nw_node->right = x->right->left; }
            nw_node->left = x->left;
            nw_node->data = x->data;
            nw_node->color = x->color;
            x->data = x->right->data;

            x->left = nw_node;
            if(nw_node->left){ nw_node->left->parent = nw_node; }
            if(nw_node->right){ nw_node->right->parent = nw_node; }
            nw_node->parent = x;

            if(x->right->right){ x->right = x->right->right; }
            else { x->right = NULL; }

            if(x->right){ x->right->parent = x; }
        }

        void RightRotate(node* x) {
            node* nw_node = new node();
            if(x->left->right){ nw_node->left = x->left->right; }
            nw_node->right = x->right;
            nw_node->data = x->data;
            nw_node->color = x->color;

            x->data = x->left->data;
            x->color = x->left->color;

            x->right = nw_node;
            if(nw_node->left){ nw_node->left->parent = nw_node; }
            if(nw_node->right){ nw_node->right->parent = nw_node; }
            nw_node->parent = x;

            if(x->left->left){ x->left = x->left->left; }
            else { x->left = NULL; }

            if(x->left){ x->left->parent = x; }
        }
 };

 int main(){
    RB_TREE tree;
        int choice, input;
        string COLOR="";
        do
        {
            cout<< "\n\tMenu\n1. Insert elements into the tree.\n2. Search for an element.\n3. Remove an element from the tree.\n4. Exit.\nYour Choice -- ";
            cin >> choice;
            switch (choice){
                case 1: cout << "\nElement to be inserted -- ";
                        cin >> input; tree.InsertNode(input);
                        break;

                case 2: cout << "\nElement to be searched -- ";
                        cin >> input;
                        if(tree.TreeSearch(input,COLOR))
                        { cout << "Element found with color : \n"<<COLOR; }
                        else { cout << "Element not found.\n"; }
                        break;

                case 3: cout << "\nElement to be deleted? -- ";
                        cin >> input;
                        tree.Remove(input);
                        break;
                case 4: return 0;
                default: cout << "Wrong Choice.\n";
            }
        }while(true);
    return 0;
 }