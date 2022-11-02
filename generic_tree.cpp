#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    vector<node*> children;

    node(int val){
        data = val;
        for (auto i: children){
            i = nullptr;
        }
    }
};

node* construct(vector<int> &input){
    
    stack<node*> st;
    node* root;

    for (int i=0; i<input.size(); i++){

        if (input[i] == -1){
            st.pop(); 
        } else {
            node* curr = new node(input[i]);

            if (!st.empty()){
                st.top()->children.push_back(curr);
            } else {
                root = curr;
            }

            st.push(curr);
        }
    }

    return root;
}

void display(node* root){
    
    string s = "";
    s += to_string(root->data) + " -> ";

    for (node* child: root->children){
        s += to_string(child->data) + " , ";
    }

    cout << s << "." << endl;

    for (node* child: root->children){
        display(child);
    }
}

int main(){
    vector<int> input = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};

    // for (int i: input){
    //     cout << i << " ";
    // }
    // cout << endl;
    node *root = construct(input);

    display(root);
    return 0;
}