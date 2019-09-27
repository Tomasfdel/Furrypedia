// AC ARRAYSUB - https://www.spoj.com/status/ns=22910678#
#define op(x,y) min(x,y)
template<class T>
struct min_queue{
    stack<pair<T,T>> s1, s2;
    int size(){ return s1.size() + s2.size(); }
    T get(){
        if(s1.empty() or s2.empty())
            return s1.empty() ? s2.top().snd : s1.top().snd;
        return op(s1.top().snd, s2.top().snd);
    }
    void push(T elem){
        T m = s1.empty() ? elem : op(elem, s1.top().snd);
        s1.push({elem, m});
    }
    T pop(){
        if(s2.empty())
        while(!s1.empty()){
            T elem = s1.top().fst;
            s1.pop();
            T m = s2.empty() ? elem : op(elem, s2.top().snd);
            s2.push({elem, m});
        }
        T res = s2.top().fst;
        s2.pop();
        return res;
    }
};
