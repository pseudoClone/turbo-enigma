int main (int argc, char *argv[]) {
        [[maybe_unused]]const char charVal{'a'};
        // char& ref {charVal}; 
        /* Invalid since ref cannot bind to const lvalues */
        [[maybe_unused]]const char& ref {charVal}; //Valid since non-modifiable reference to non-modifiable lvalue
        /* Also valid if bound to modifiable lvalue such as int x{5} */
        [[maybe_unused]]const int& iref {5}; // Can bind to rvalues
        
        /* Remeber that const references can point to either static or non-modifiable/const lvalues or rvalues*/
        return 0;
}
