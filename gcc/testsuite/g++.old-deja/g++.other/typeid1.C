// { dg-do assemble  }
// { dg-options "" }
// { dg-require-effective-target rtti_enabled }
// Origin: sk@gluit.de

#include <typeinfo>

int main ()
{
  typeid(char*);
  
  int len = 1;
  char carr[len];
  typeid(typeof(carr)); // { dg-error "" } type has variable size
  typeid(carr); // { dg-error "" } type has variable size
}
