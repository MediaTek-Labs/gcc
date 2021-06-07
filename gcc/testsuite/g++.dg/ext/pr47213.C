// { dg-do compile }
// { dg-require-visibility "" }
// { dg-options "-fvisibility-ms-compat" }
// { dg-require-effective-target rtti_enabled }

#include <typeinfo>

template < typename T > void
bar ()
{
  typeid (T);
}

void
foo ()
{
  bar < int () > ();
}
