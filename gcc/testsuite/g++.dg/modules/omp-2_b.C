// { dg-additional-options "-fmodules-ts" }
// { dg-xfail-if "" { ! fopenmp } }

import foo;

unsigned ary[64];

int main ()
{
  frob (ary);
}
