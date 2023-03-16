#include <iostream>
using namespace std;

template<typename T>
struct queue{
    struct node{
        T data;
        node *point;
    };
    unsigned int hem;
    node* head; 
    node* rear;
    queue() {
        hem=0; head=NULL; rear=NULL;
    }
    bool empty(){
        if(hem) return 0;
        return 1;
    }
    unsigned int size(){
        return hem;
    }
    void push(T n){
        node* temp = new struct node;
        if(empty()) {head = temp;rear=temp;}
        else{ rear->point = temp;}
        temp->data = n;
        temp->point = NULL;
        rear = temp;
        hem++;
    }
    void pop(){
        node* ptr = head;
        head = ptr->point;
        delete ptr;
        hem--;
    }
    T front(){
        return head->data;
    }
    T back(){
        return rear->data;
    }

    ~queue(){
        while (!empty())
        {
            pop();
        }
    }
};

int main(){
    queue<int> q;

    cout << q.empty() << endl;

    q.push(5);
    q.push(10);
    q.push(123123);
    q.push(145345);
    q.push(1123412);
    q.push(995513);

    cout << "the rear item is : " << q.back() << endl;
    cout << "the front item is : " << q.front() << endl;
    cout << "the size is now : " << q.size() << endl;
    cout << endl;

    q.pop();
    q.pop();
    cout << "the front item is : " << q.front() << endl;
    cout << "the size is now : " << q.size() << endl;

    cout << q.empty() << endl;
}