// PR c++/28109
// { dg-do compile }
// { dg-require-effective-target rtti_enabled }

#include <typeinfo>

struct A;

void foo()
{
  A a;  // { dg-error "incomplete type" }
  typeid (a);
}
