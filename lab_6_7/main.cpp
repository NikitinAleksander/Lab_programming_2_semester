#include <iostream>
#include <vector>

template<typename T>
void pow(T value, int n) {
    T tmp = value;
    try {


        if (n == 0) {
            std::cout << '1' << std::endl;
        } else {
            if (n > 0) {
                n--;
                for (int i = 0; i < n; i++) {
                    tmp *= value;
                }
                if(tmp<=0&&value!=0){
                    throw 1;
                }
                std::cout << tmp << std::endl;
            } else {
                n *= -1;
                n--;
                for (int i = 0; i < n; i++) {
                    tmp *= value;
                }
                if(tmp<=0&&value!=0){
                    throw 1;
                }
                std::cout << 1 / tmp << std::endl;
            }
        }

    }
    catch(int i){
        std::cout<<"|   error limit!!!";
    }

}

template<int n, typename D>
class queue {
private:
    std::vector<D> q;
public:

    void push(D tmp) {
        try {
            if (q.size() == n) {
                throw 2;
            }
            q.push_back(tmp);
        }
        catch (int i) {
            if (i == 2) {
                std::cout << "| too many elements!!!" << std::endl;
            }
        }

    }

    void pop() {
        try {
            if (q.size() == 0) {
                throw 1;
            }
            q.erase(q.begin());
        }
        catch (int i) {
            if (i == 1) {
                std::cout << "| queue is empty!!!" << std::endl;
            }
        }
    }

    void print() {
        for (int i = 0; i < q.size(); i++) {
            std::cout << q[i] << " ";
        }
        std::cout << std::endl;
    }

};

int main() {
    pow(0.5,-1);
    pow(2,4);
    pow(10,100);
    std::cout<<std::endl;
    queue<3,char> first;
    first.pop();
    first.push('a');
    first.push('b');
    first.push('c');
    first.push('d');
    first.print();
    first.pop();
    first.pop();
    first.print();
    return 0;
}