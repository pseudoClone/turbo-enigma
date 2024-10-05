#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <ostream>

int main (int argc, char *argv[]) {
        std::srand(time(NULL));
        long long int fgate = rand() % 15; // 0 to 15 random number
        std::cout<<fgate<<std::endl;
        auto x = [&]() {
                fgate += 1;
        };
        x();//Fucking call the function
        std::cout << fgate<<std::endl;
        
        //Direct List initialization Lambda
        auto nicolton {[&] (){
                fgate *= 10;
        }};
        nicolton();
        std::cout<<fgate<<std::endl;

        return 0;
}
