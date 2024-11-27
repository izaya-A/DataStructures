#include <iostream>
#include <my_array.h>

using namespace std;

int main(){
    cout << "hello wrold!" << endl;
    MyArray marray;
    marray.creatArray();
    marray.add(10);
    // marray.update(3, 1);
    marray.select();
    marray.del(7);
    return 0;
}