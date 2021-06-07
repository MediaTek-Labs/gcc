// { dg-do run  }
// { dg-options "-O" }
// { dg-require-effective-target rtti_enabled }

#include <iostream>
#include <typeinfo>

int main() {
  int *i1, *i2;
  std::cerr << (typeid(i1)==typeid(i2)) << std::endl;
}
