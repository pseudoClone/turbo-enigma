template<typename V>
struct type_is{
        using type = V;
};
template<typename T>
struct removeVolatile : type_is<T>{};

template<typename U>
struct removeVolatile<U volatile>: type_is<U>{};
