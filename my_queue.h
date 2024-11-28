#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>

using namespace std;

struct Queue{
    int queue[10] = {0};
    int begin = 0;
    int end = 0;
};

class MyQueue{
public:
    MyQueue(){}

public:
    void enqueue(int val){
        if(m_queue.end == 10){
            cout << "队列已满！" << endl;
            return;
        }
        m_queue.queue[m_queue.end] = val;
        m_queue.end++;
    }

    int dequeue(){
        if(m_queue.begin == m_queue.end){
            cout << "队列已空！" << endl;
            return -1;
        }
        int temp = m_queue.queue[m_queue.begin];
        m_queue.begin++;
        return temp;
    }

    void print(){
        for(int i = m_queue.begin; i < m_queue.end; ++i){
            cout << m_queue.queue[i] << ", ";
        }
        cout << endl;
    }

private:
    Queue m_queue;

};

#endif //MYQUEUE_H