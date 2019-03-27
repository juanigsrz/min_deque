#include <iostream>
#include "op_deque.cpp"

using namespace std;

template<class T>
struct get_min{ T operator()(T &a, T &b){ return a < b ? a : b; } };

int main(){
    op_deque<int, get_min<int>> D;
    D.push_back(3);
    cout << D.size() << endl;

    return 0;
}
