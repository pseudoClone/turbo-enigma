#include <iostream>
class IDK {
public:
        static void makeSound() /** const **/{ // Static members cannot have const qualifier
                std::cout << "Make some sound"<<std::endl;
        }
};

/** A reminder that virtual functions cannot be global 
 * or static as they rely on specific object to determine 
 * which implementation of function is called **/

int main (int argc, char *argv[]) {
        
        IDK::makeSound(); //Call without objects
        return 0;
}
