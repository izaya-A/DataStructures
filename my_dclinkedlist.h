#ifndef MYDCLINKEDLIST_H
#define MYDCLINKEDLIST_H

#include <iostream>

using namespace std;

struct dcListNode{
    int data;
    dcListNode* prev;
    dcListNode* next;
};

class MyDCLinkedList{
public:
    MyDCLinkedList(){
        head = new dcListNode;
        head->data = -1;
        head->prev = head->next = nullptr;
    }

public:
    void addEnd(int val){
        if(!head->next){
            dcListNode* temp = new dcListNode;
            temp->data = val;
            head->next = head->prev = temp;
            temp->next = temp->prev = head;
        }else{
            dcListNode* temp = new dcListNode;
            temp->data = val;
            temp->next = head->next;
            head->next = temp;
            temp->prev = head;
        }
    }

    void addHead(int val){
        if(!head->prev){
            dcListNode* temp = new dcListNode;
            temp->data = val;
            head->prev = head->next = temp;
            temp->prev = temp->next = head;
        }else{
            dcListNode* temp = new dcListNode;
            temp->data = val;
            temp->next = head;
            temp->prev = head->prev;
            head->prev = temp;
        }
    }

    void del(int val){
        dcListNode* find = head;
        dcListNode* temp = nullptr;
        while(find->next != head){
            if(find->next->data == val){
                temp = find;
                break;
            }
            find = find->next;
        }
        if(!temp){
            cout << "没有这个节点：" << val << endl;
            return;
        }
        temp->next = temp->next->next;
        temp->next->next->prev = temp;
        delete temp->next;
    }

    void print(){
        dcListNode* temp = head;
        while(temp->next != head){
            cout << temp->data << ", ";
            temp = temp->next;
        }
        cout << endl;
    }

private:
    dcListNode* head;

};


#endif //MYDCLINKEDLIST_H