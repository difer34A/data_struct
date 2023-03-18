#include <iostream>
using namespace std;

template<typename T>
struct list{
    struct node{
        T data;
        node* forward;
        node* backward;
    };
    unsigned int hem;
    node* head;
    node* rear;
    list(){
        hem = 0;
        head = NULL;
        rear = NULL;
    }
    bool empty(){
        if(hem) return 0;
        return 1;
    }
    unsigned int size(){
        return hem;
    }
    void push_back(T n){
        node* temp = new struct node;
        temp->data = n;
        if(empty()) {head = temp; temp->backward = NULL;}
        else {rear->forward = temp; temp->backward = rear;}
        temp->forward = NULL;
        rear = temp;
        hem++;
    }
    void push_front(T n){
        node* temp = new struct node;
        temp->data = n;
        if(empty()) {head = temp; rear = temp; temp->forward = NULL;}
        else {head->backward = temp; temp->forward = head;}
        temp->backward = NULL;
        head = temp;
        hem++;
    }
    void pop_back(){
        node* temp = rear;
        rear = temp->backward;
        rear->forward = NULL;
        delete temp;
        hem--;
    }
    void pop_front(){
        node* temp = head;
        head = temp->forward;
        head->backward = NULL;
        delete temp;
        hem--;
    }

    T front(){return head->data;}
    T back(){return rear->data;}
};


int main(){
    list<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    cout << "front : " << l.front() << endl;
    l.pop_front();
    cout << "front : " << l.front() << endl;
    l.push_front(1);
    cout << endl;

    cout << "back : " << l.back() << endl;
    l.pop_back();
    cout << "back : " << l.back() << endl;
    l.push_back(3);
    cout << endl;

    cout << "size : " << l.size() << endl;
    
}