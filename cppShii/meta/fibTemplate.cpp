template<int N>
struct Fibo {
        static constexpr int value = Fibo<N - 1>::value + Fibo<N - 2>::value;
};

template <>
struct Fibo<0> {
        static constexpr int value = 0;
};

template <>
struct Fibo<1> {
        static constexpr int value = 1;
};

int main (int argc, char *argv[]) {
        constexpr int fib_10 = Fibo<10>::value;
        return 0;
}
