// { dg-do run  }
// { dg-require-effective-target rtti_enabled }
#include <typeinfo>

int main() {
  typeid(bool);
}
