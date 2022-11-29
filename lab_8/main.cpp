#include <vector>
#include <iostream>
#include "header.h"

using namespace std;

int main() {
    vector<int> v={-1,0,0,0,1,2,3,4,2};
    if(any_of(v.begin(), v.end(), Predicate<int,-2>())) {
        cout << "Some element satisfies the predicate"<<endl;
    }else{
        cout << "Not one element satisfies the predicate"<<endl;
    }
    if(one_of(v.begin(), v.end(), Predicate<int,0>())) {
        cout << "One element satisfies the predicate"<<endl;
    }else{
        cout << "Not one element satisfies the predicate"<<endl;
    }
    int count=-1;
    if(find_not(v.begin(),v.end(),count)!=v.end()){
        cout<<"First element != "<<count<<" : "<<*find_not(v.begin(),v.end(),count);
    }else{
        cout << "All element's = "<<count<<endl;
    }
    return 0;
}
