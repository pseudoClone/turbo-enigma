#include <iostream>
#include <string>

void someshitfunc(std::string& carlando)
{
        std::cout<<carlando<<std::endl;
        carlando = "Lanno, There is no Fish";
}

int main (int argc, char *argv[]) {
        
        std::string carlando = {"Maria Karey"};
        someshitfunc(carlando); /* Here is pass by value but it binds to &carlando*/
        std::cout<<carlando<<std::endl;
        return 0;
}
