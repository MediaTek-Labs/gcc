// PR c++/54249
// { dg-do compile { target c++11 } }
// { dg-xfail-if "not for upstream" { *-*-musl* } }

#include <stddef.h>

::nullptr_t n;
