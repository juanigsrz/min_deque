#define forn(i,n) for(int i=0; i<int(n); i++)
#define fst first
#define snd second
#define op(x,y) min(x,y)

template<typename T>
class rastack : public std::stack<T> {
    public: using std::stack<T>::c;
    T &operator[](int i){ return c[i]; }
};

template<class T>
struct op_deque{
    rastack<pair<T,T>> s1, s2;
    int size(){ return s1.size() + s2.size(); }
    T &operator[](unsigned int i){
        return i < s1.size() ? s1[s1.size()-i-1].fst : s2[i-s1.size()].fst;
    }
    void balance(){
        if(3 * min(s1.size(), s2.size()) < max(s1.size(), s2.size())){
            int n = this->size(), half = n/2, rest = n-half;
            vector<T> af(half), ab(rest);
            forn(i,half) af[half-i-1] = (*this)[i];
            forn(i,rest) ab[i] = (*this)[half+i];
            s1 = rastack<pair<T,T>>(), s2 = rastack<pair<T,T>>();
            forn(i,half) s1.push({af[i], i ? op(af[i], s1.top().snd) : af[i]});
            forn(i,rest) s2.push({ab[i], i ? op(ab[i], s2.top().snd) : ab[i]});
        }
    }
    void pop_front(){ if(s1.empty()) s2.pop(); else s1.pop(); balance(); }
    void pop_back(){ if(s2.empty()) s1.pop(); else s2.pop(); balance(); }
    void push_front(T x){
        s1.push({x, s1.empty() ? x : op(x, s1.top().snd)});
        balance();
    }
    void push_back(T x){
        s2.push({x, s2.empty() ? x : op(x, s2.top().snd)});
        balance();
    }
    T front(){ return s1.empty() ? s2.top().fst : s1.top().fst; }
    T back(){ return s2.empty() ? s1.top().fst : s2.top().fst; }
    T get(){
        if(s1.empty() or s2.empty())
            return s1.empty() ? s2.top().snd : s1.top().snd;
        return op(s1.top().snd, s2.top().snd);
    }
};
