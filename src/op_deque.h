#ifndef __OP_DEQUE_H__
#define __OP_DEQUE_H__

#include <stack>

template<typename T>
class rastack : public std::stack<T> {
    public: using std::stack<T>::c;
    T& operator[](int i){ return c[i]; }
};

template<typename T, typename F>
class op_deque{
private:
    rastack<std::pair<T,T>> s1, s2;
    F op;
    void balance();
public:
    int size();
    T& operator[](unsigned int i);
    void pop_front();
    void pop_back();
    void push_front(T x);
    void push_back(T x);
    T front();
    T back();
    T get();
};
    

#endif // __OP_DEQUE_H__
