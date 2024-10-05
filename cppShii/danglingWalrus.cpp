#include <iostream>
#include <string>

auto makeWalrus(const std::string& name)
{
  return [&]() {
    std::cout << "I am a walrus, my name is " << name << '\n'; // Undefined behavior
  };
}

int main()
{
  auto sayName{ makeWalrus("Roofus") };

  sayName();

  return 0;
}
