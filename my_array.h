#include <iostream>

using namespace std;

class MyArray{
public:
    MyArray(){
        m_size = 10;
    }

public:
    void creatArray(){
        int l_array[m_size];
        for(int i = 0; i < m_size; ++i){
            l_array[i] = 0;
        }
        m_array = l_array;
        m_p = 0;
    }

    void add(int val){
        if(m_p == m_size){
            cout << "数组元素以满" << endl;
            return;
        }
        m_array[m_p] = val;
        m_p++;
    }

    void del(int val){
        if(m_p == 0){
            cout << "容器为空！" << endl;
            return;
        }
        int pos = -1;
        for(int i = 0; i < m_p; ++i){
            if(m_array[i] == val){
                pos = i;
                break;
            }
        }
        if(pos == -1){
            cout << "容器中没有元素：" << val << endl;
            return;
        }
        for(int i = pos; i < m_p - 1; ++i){
            m_array[i] = m_array[i + 1];
        }
        m_p--;
    }

    void update(int key, int val){
        if(key > m_p){
            cout << "超出容器范围了!" << endl;
            return;
        }
        m_array[key] = val;
    }

    void select(){
        for(int i = 0; i < m_p; ++i){
            cout << m_array[i] << ", " << endl;
        }
    }

private:
    int m_size = 10;
    int* m_array;
    int m_p = 0;

};