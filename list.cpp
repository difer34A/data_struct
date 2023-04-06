#include <iostream>
using namespace std;

template <typename T>
struct list{
    struct node{
        T data;
        node *forward;
        node *backward;
    };
    unsigned int hem;
    node* head; 
    node* rear;
    list() {
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
    void insert(int x, T n){
        node* z = head;
        for(int i=-1; i<x; i++){
            z = z->forward;
        }
        node* temp = new struct node;
        node* bef = z->backward;
        temp->data = n;
        temp->forward = z; temp->backward = bef;
        bef->forward = temp; z->backward = temp;
    }
};

int main(){
    list<int> l;

    l.push_front(2);
    l.push_front(3);
    l.push_front(4);
    l.push_front(5);

    cout << l.back() << endl;
    l.insert(2, 6);
    l.pop_back();
    cout << l.back() << endl;

}