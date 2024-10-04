#include <algorithm>
#include <iostream>
#include <array>
#include <vector>

std::vector<int> func(const int* p, std::size_t size)
{
        const int* begin = p; //Use auto if needed
        const int* end = p + size; // Use auto if needed
        //std::cout<<typeid(decltype(begin)).name()<<std::endl<<typeid(decltype(end)).name()<<std::endl;
        std::vector<int>np;
        std::for_each(p, end, [&np](int elem){
                        np.push_back(elem);
                        });// Use catching by reference for now
        return np;
}

int main()
{
        std::array<int, 5> arr1{{1, 2, 3, 4, 5}};
        std::cout << "Size of array: " << arr1.size() << std::endl;
        std::cout << "Last element: " << arr1[4] << std::endl;

        auto d = func(arr1.data(), arr1.size());
        for(auto i: d){
                std::cout<<i;
        }
        std::cout << "\n";

        return 0;
}
