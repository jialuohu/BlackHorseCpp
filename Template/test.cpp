#include <iostream>
using namespace std;

namespace shit {
    template<typename Allocator, typename hehe>
    class hello {
    public:
        void printit() {
            cout << "hello world" << endl;
        }
    };

    template<typename Allocator>
    class hello<bool, Allocator> {
    public:
        void printit() {
            cout << "hello world" << endl;
        }
    };

    void test() {
        hello<bool, int> a1;
        a1.printit();
    }
}

int main(){

    return 0;
}