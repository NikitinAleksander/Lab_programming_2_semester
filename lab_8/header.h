#pragma once

template <class T,T n>
class Predicate {
public:
    bool operator()(const T x) {
        return x < n;
    }
};

template <class iterator, class Predicate>
bool any_of(iterator begin, iterator end, Predicate predicate) {
    for(; begin != end; begin++) {
        if(predicate(*begin))
            return true;
    }
    return false;
}

template <class iterator, class Predicate>
bool one_of(iterator begin, iterator end, Predicate predicate) {
    int count = 0;
    for(; begin != end; begin++) {
        if(predicate(*begin)) {
            count++;
        }
        if(count > 1)
            return false;
    }

    return count>0;
}

template <class iterator, class T>
iterator find_not(iterator begin, iterator end, T find) {
    for(; begin != end; begin++) {
        if(!(*begin == find))
            break;
    }
    return begin;
}
