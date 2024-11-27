#include <iostream>

using namespace std;

class MyArray{
public:
    MyArray(){}

public:
    void creatArray(){
        for(int i = 0, i < 10, ++i){
            m_array[i] = 0;
        }
        m_p = 0;
    }

    void add(int val){
        if(m_p == m_size){
            cout << "数组元素以满" << endl;
            return;
        }
        m_array[m_p] = key;
        m_p++;
    }

    void del(int val){
        for(int i = 0; i < m_p; ++i){

        }
    }

private:
    int m_size = 10;
    int[m_size] m_array;
    int m_p = 0;

};