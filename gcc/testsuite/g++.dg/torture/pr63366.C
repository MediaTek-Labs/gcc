// { dg-do run }
// { dg-options "-pedantic" }
// { dg-require-effective-target rtti_enabled }

#include <typeinfo>

int
main (void)
{
  return typeid (__complex) != typeid (__complex double); /* { dg-warning "ISO C\\+\\+ does not support plain 'complex' meaning 'double complex'" } */
}
