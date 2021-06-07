// PR c++/92009
// { dg-require-effective-target rtti_enabled }

namespace std {
  class type_info {};
}

bool
a2 ()
{
  return ((void **) &typeid (int))[0];
}
