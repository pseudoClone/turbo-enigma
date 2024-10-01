#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include <cstdlib>

int value(char roman_char)
{
        int roman_int;
        switch (roman_char) {
                case 'I': return 1;
                case 'V': return 5;
                case 'X': return 10;
                case 'L': return 50;
                case 'C': return 100;
                case 'D': return 500;
                case 'M': return 1000;
                default: return 0;
        }
}
int main (int argc, char *argv[]) {

        int result {};
        std::string roman_string {};
        std::cout<<"Enter the string(use Capitals only) : ";
        std::cin>>roman_string;
        for (size_t i = 0; i <= roman_string.length() - 1; i++) {
                int s1 = value(roman_string[i]);
                if((i + 1) < roman_string.length()){
                        int s2 = value(roman_string[i+1]);
                        if(s1 < s2) {
                                result -= s1;
                        }
                        else {
                                result += s1;
                        }
                }
                else {
                        result += s1;
                }
        }
        std::cout<<"The number is: " << result<<std::endl;
        return 0;
}
