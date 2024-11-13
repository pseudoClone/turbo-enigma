#include <cstddef>
#include <iostream>
template <typename U>
struct rank {
        static const size_t value = 0u;
};

template <typename U, size_t N>
struct rank<U[N]>{
        static const size_t value = 1u + rank<U>::value;
};

int main (int argc, char *argv[]) {
        
        std::cout<<rank<int[10][20][30]>::value<<std::endl;
        return 0;
}
