template<typename T>
struct type_is {
        using type = T;
};

template<bool, typename T, typename>
struct IF : type_is<T>{};

template<typename T, typename F>
struct IF<false, T, F> : type_is<F>{};
