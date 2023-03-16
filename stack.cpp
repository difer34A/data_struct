#include <iostream>

using namespace std;

template<typename T>
struct stack{
    struct node {
        T val;
        node* prev;
    };
    node* root;
    unsigned int hem;
    stack() {
        cout << "test\n";
        hem = 0;
        root = NULL;
    }
    // functions
    void push(T n){
        struct node* temp = new struct node;
        temp->val = n;
        temp->prev = root;
        root = temp;
        hem++;
    }
    T top(){
        if(hem) return root->val;
        return -1;
    }
    unsigned int size(){
        return hem;
    }
    bool empty(){
        if(hem) return 0;
        // hervee hooson bol return 1
        return 1;
    }
    void pop(){
        // herev hooson return -1
        node* ptr = root;
        root = ptr->prev;
        delete ptr;
        hem--;
    }
    ~stack() {
        cout << "deleted\n";
        while(!empty()){
            pop();
        }
    }
};


int main() {
    
    stack<int> st;
    
    st.push(93);
    st.push(11);
    st.push(69);
    st.pop();
    cout << st.top() << endl;
    
    cout << "stack size " << st.size() << endl;
    cout << "hooson or not is : " << st.empty() << endl;
    
}