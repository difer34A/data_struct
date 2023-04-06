#include <iostream>
using namespace std;

struct p_queue{
    struct node{
        int data;
        node *point;
    };
    unsigned int hem;
    node* head; 
    node* rear;
    p_queue() {
        hem=0; head=NULL; rear=NULL;
    }
    bool empty(){
        if(hem) return 0;
        return 1;
    }
    unsigned int size(){
        return hem;
    }
    node* findPlace(int val){
        node* temp = head;
        while(temp->point->data > val || temp->point == NULL){
            temp = temp->point;
            
            if(temp->point == NULL) return temp;
        }
        return temp;
    }
    void push(int n){
        node* temp = new struct node;
        temp->data = n;
        if(empty()) {head = temp;rear=temp;temp->point = NULL;}
        else{ 
            // hamgiin tom baival urd ni
            if(head->data < n) {temp->point = head; head = temp;}
            // gold ni yumuu ard ni
            else{
                node* temp_before = findPlace(n);
                temp->point = temp_before->point;
                temp_before->point = temp;
            }
        }
        hem++;
    }
    void pop(){
        node* ptr = head;
        head = ptr->point;
        delete ptr;
        hem--;
    }
    int front(){
        return head->data;
    }
    int back(){
        return rear->data;
    }

    ~p_queue(){
        while (!empty())
        {
            pop();
        }
    }
};

int main(){
    p_queue q;

    q.push(-1);
    q.push(3);
    q.push(12);
    q.push(-100);

    cout << "front : " << q.front() << endl;
    q.pop();
    cout << "front : " << q.front() << endl;
    q.pop();
    cout << "front : " << q.front() << endl;
    q.pop();
    cout << "front : " << q.front() << endl;
    q.pop();
}