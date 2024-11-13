template <typename T>
struct type_is {
        using dog = T;
};

template <bool, typename T> // Note that you can instantiate the class/typename to default to void
struct SFINAE : type_is<T>{};

template <class T>
struct SFINAE<false, T>{};
