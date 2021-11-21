#include <cassert>
#include <iostream>

#include "cord-utilities.hpp"
#include "cord.hpp"

int main() {
  Cord* c1 = new Cord("hello");
  Cord* c2 = new Cord(" world!");
  // Cord* c3 = ConcatCords(c1, c2);

  Cord* c4 = new Cord(c1, c2);

  std::cout << c4->ToString() << std::endl;
  std::cout << c4->At(7) << std::endl;

  // std::cout << c3->ToString();  // should print hello world!

  // delete c1;
  // delete c2;
  // delete c3;

  return 0;
}
