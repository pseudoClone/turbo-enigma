#include <iostream>
#include <chrono>
#include <thread>

int main (int argc, char *argv[]) {
        using namespace std::literals::chrono_literals;
        auto start = std::chrono::high_resolution_clock::now(); // Get current time method

        std::this_thread::sleep_for(1s); // Current thread sleep for 1 second
        
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<float> duration = end - start;
        std::cout<<duration.count()<<"s"<<std::endl;
        return 0;
}
