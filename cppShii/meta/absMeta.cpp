#include <iostream>
#include <climits>
#include <cstdlib>
template<int N>
struct absx { //Absoulte Value meta function
        static_assert(N!=INT_MAX, "Failed size requirements");
        static constexpr int value = (N < 0) ? -N : N;
};
int main (int argc, char *argv[]) {
        std::cout << absx<-2>::value<<std::endl;
        return 0;
}
