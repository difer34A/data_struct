#include <iostream>
using namespace std;

struct list{
    struct node{
        int data;
        node* point;
    };
    unsigned int hem;
    node* head;
    list(){
        hem = 0;
        head = NULL;
    }
    bool empty(){
        if(hem) return 0;
        return 1;
    }
    unsigned int size(){
        return hem;
    }
   
    void insert(int n){
        node* temp = new struct node;
        temp->data = n;
        temp->point = NULL;
        hem++;

        if(empty()) {head=temp;return;}
        if(n < head->data){temp->point = head; head = temp; return;}

        node* curr=head;
        while(curr->point !=NULL && curr->point->data < n) curr = curr->point;

        temp->point = curr->point;
        curr->point = temp;
    }

    void print(){
        node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->point;
        }
    }

    int front(){return head->data;}
};


int main(){
    list l;
    l.insert(1);
    l.insert(4);
    l.insert(2);
    l.insert(5);
    l.print();
}