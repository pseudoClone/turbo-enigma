#include <iostream>
template<unsigned M, unsigned N>
struct gcd {
        static constexpr int value = gcd<N, M % N>::value;
};
template<unsigned M>
struct gcd<M,0>{
        static_assert(M != 0, "Invalid operation" );
        static constexpr int value = M;
};
int main (int argc, char *argv[]) {
        
        std::cout<< gcd<25, 0>::value<< std::endl;

        return 0;
}
