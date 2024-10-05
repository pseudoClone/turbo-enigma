#include <iostream>
#include <ostream>

int main (int argc, char *argv[]) {
        
        double yak = 3.14159265;
        auto rage1{[&] () {
                std::cout<<yak<<std::endl;
                yak++;
        }};
        auto imissthe{rage1}; // While assigning no need for the braces

        imissthe();
        rage1();

        auto& hellCopying {imissthe};

        hellCopying();
        return 0;
}
