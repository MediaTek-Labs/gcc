/* { dg-do compile }
/* { dg-options "-mfunc-opt-list=func-opt-list.txt" } */
/* { dg-additional-options "-DOPTOFF" } */
/* { dg-skip-if "optimization controlled by -mfunc-opt-list" { *-*-* } { "-O1" "-O2" "-O3" "-Os" } } */
/* { dg-skip-if "C model specific pattern" { *-*-* } { "-mcmodel=large" } } */

#ifdef OPTOFF
#pragma gcc optimize 0
#endif

/* { dg-final { scan-assembler-not "sabrina" } } */
static inline int sabrina (void) __attribute__((always_inline));
static inline int sabrina (void)
{
  return 13;
}
int foo (void)
{
  return sabrina () + 68;
}

/* { dg-final { scan-assembler-not "jessica" } } */
static inline int jessica (void)
{
  return 17;
}
int bar (void)
{
  return jessica () + 68;
}

/* { dg-final { scan-assembler "baz:\[^:\]*balc\t\[^\n\]*andrea" } } */
static inline int andrea (void)
{
  return 21;
}
int baz (void)
{
  return andrea () + 68;
}
