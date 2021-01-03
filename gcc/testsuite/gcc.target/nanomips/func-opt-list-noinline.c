/* { dg-do compile }
/* { dg-options "-mfunc-opt-list=func-opt-list.txt" } */
/* { dg-additional-options "-Wno-attributes" } */
/* { dg-skip-if "code quality test" { *-*-* } { "-O0" "-O1" "-Os" } } */

/* { dg-final { scan-assembler "foo:.*balc\t\[^\n\]*noinl_attr" } } */
static int noinl_attr (int x, int y) __attribute__((noinline));
static int noinl_attr (int x, int y)
{
 return x + y;
}
int foo (int a, int b)
{
  return noinl_attr (b, a) + 1;
}

/* { dg-final { scan-assembler "bar:.*balc\t\[^\n\]*noinl_list" } } */
static int noinl_list (int x, int y)
{
 return x & y;
}
int bar (int a, int b)
{
  return noinl_list (b, a) + 1;
}

/* Control version for sanity.  */
/* { dg-final { scan-assembler-not "baz:\[^:\]*balc\t\[^\n\]*inl" } } */
static int inl (int x, int y)
{
 return x | y;
}
int baz (int a, int b)
{
  return inl (b, a) + 1;
}

/* Check noinline + always_inline combinations.
   An attribute in the source takes precedence over one via func-opt-list;
   if both are in the same place, noinline wins.  */

/* { dg-final { scan-assembler "qux:.*balc\t\[^\n\]*noinl_always_attr" } } */
static int noinl_always_attr (int x, int y) __attribute__((noinline,
                                                          always_inline));
static int noinl_always_attr (int x, int y)
{
 return x * y;
}
int qux (int a, int b) {
  return noinl_always_attr (b, a) + 1;
}

/* { dg-final { scan-assembler "quux:.*balc\t\[^\n\]*noinl_attr_always_list" } } */
static int noinl_attr_always_list (int x, int y) __attribute__((noinline));
static int noinl_attr_always_list (int x, int y)
{
 return x ^ y;
}
int quux (int a, int b)
{
  return noinl_attr_always_list (b, a) + 1;
}

/* { dg-final { scan-assembler-not "quuz:\[^:\]*balc\t\[^\n\]*noinl_list_always_attr" } } */
static inline int noinl_list_always_attr (int x, int y) __attribute__((always_inline));
static int noinl_list_always_attr (int x, int y)
{
 return x - y;
}
int quuz (int a, int b)
{
  return noinl_list_always_attr (b, a) + 1;
}

/* { dg-final { scan-assembler-not "fred:\[^:\]*balc\t\[^\n\]*noinl_always_list" } } */
static int noinl_always_list (int x, int y)
{
 return x % y;
}
int fred (int a, int b)
{
  return noinl_always_list (b, a) + 1;
}

#pragma gcc optimize 0
/* flatten trumps a noinline from -func-opt-list,
   but not one in the source. */

/* { dg-final { scan-assembler "noflat:.*balc\t\[^\n\]*inl" } } */
int noflat (int a, int b)
{
  return inl (b, a) + 6;
}

/* { dg-final { scan-assembler-not "flat_do:\[^:\]*balc\t\[^\n\]*inl" } } */
__attribute__((flatten)) int flat_do (int a, int b)
{
  return inl (b, a) + 7;
}

/* { dg-final { scan-assembler "flat_dont:.*balc\t\[^\n\]*noinl_attr" } } */
__attribute__((flatten)) int flat_dont (int a, int b)
{
  return noinl_attr (b, a) + 7;
}

/* { dg-final { scan-assembler "flat_dont_list:.*balc\t\[^\n\]*noinl_list" } } */
__attribute__((flatten)) int flat_dont_list (int a, int b)
{
  return noinl_list (b, a) + 7;
}
