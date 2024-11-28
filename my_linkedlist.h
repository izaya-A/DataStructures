#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

struct listNode{
    int data;
    listNode* next;
};

class MyLinkedList{
public:
    MyLinkedList(){
        head = new listNode;
        head->data = -1;
        head->next = nullptr;
    }

public:
    void addHead(int val){
        listNode* temp = new listNode;
        temp->data = val;
        temp->next = head->next;
        head->next = temp;
    }

    void addEnd(int val){
        listNode* temp = new listNode;
        temp->data = val;
        temp->next = nullptr;
        listNode* find = head;
        while(find->next != nullptr){
            find = find->next;
        }
        find->next = temp;
    }

    void del(int val){
        listNode* find = head;
        listNode* temp = nullptr;
        while(find->next != nullptr){
            if(find->next->data == val){
                temp = find;
                break;
            }
            find = find->next;
        }
        if(!temp){
            cout << "没有找到这个节点：" << val << endl;
            return;
        }
        listNode* nn = temp->next->next;
        delete temp->next;
        temp->next = nn;
    }

    void print(){
        listNode* temp = head;
        while(temp != nullptr){
            cout << temp->data << ", ";
            temp = temp->next;
        }
        cout << endl;
    }

private:
    listNode* head;

};

#endif //MYLINKEDLIST_H