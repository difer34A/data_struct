#include <iostream>
using namespace std;

template <typename T>
struct deque{
    struct node{
        T data;
        node *forward;
        node *backward;
    };
    unsigned int hem;
    node* head; 
    node* rear;
    deque() {
        hem=0; head=NULL; rear=NULL;
    }
    bool empty(){
        if(hem) return 0;
        return 1;
    }
    unsigned int size(){
        return hem;
    }
    void push_front(T n){
        node* temp = new struct node;
        if(empty()) {head = temp;rear=temp;}
        else{ head->backward = temp; temp->forward = head;}
        temp->backward=NULL;
        temp->data = n;
        head = temp;    
        hem++;
    }
    void push_back(T n){
        node* temp = new struct node;
        if(empty()) {head = temp;rear=temp;}
        else{ rear->forward = temp; temp->backward = rear;}
        temp->forward = NULL;
        temp->data = n;
        rear = temp;
        hem++;
    }
    T front(){
        return head->data;
    }
    T back(){
        return rear->data;
    }
    void pop_front(){
        node* temp = head;
        head = temp->forward;
        head->backward = NULL;
        delete temp;
    }
    void pop_back(){
        node* temp = rear;
        rear = temp->backward;
        rear->forward = NULL;
        delete temp;
    }
    ~deque(){
        while (!empty())
        {
            pop_front();
        }
        
    }
};

int main(){
    deque<int> l;

    l.push_front(2);
    l.push_front(3);
    l.push_front(4);
    l.push_front(5);
    l.push_back(10);
    l.push_back(100);

    cout << l.back() << endl;
    l.pop_back();
    cout << l.back() << endl;
}