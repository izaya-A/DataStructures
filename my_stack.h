#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>

using namespace std;

const int MAXSIZE = 10;
struct myStack{
    int stack[MAXSIZE] = {0};
    int p = 0;
};

class MyStack{
public:
    MyStack(){}

public:
    void push(int val){
        if(m_stack.p == MAXSIZE){
            cout << "栈空间已满！" << endl;
            return;
        }
        m_stack.stack[m_stack.p] = val;
        m_stack.p++;
    }

    void pop(){
        if(m_stack.p = 0){
            cout << "当前栈为空！" << endl;
            return;
        }
        m_stack.p--;
    }

    void select(){
        for(int i = 0; i < m_stack.p; ++i){
            cout << m_stack.stack[i] << ", ";
        }
        cout << endl;
    }

private:
    myStack m_stack;

};

#endif //MYSTACK_H