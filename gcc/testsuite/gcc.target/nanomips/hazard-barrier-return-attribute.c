/* Test attribute for clearing hazards while returning.  */
/* { dg-do compile } */

extern int bar ();

static int __attribute__ ((use_hazard_barrier_return))
foo0 ()
{
  return bar ();
}

int
foo1 ()
{
  return foo0 ();
}

/* { dg-final { scan-assembler "foo0:" } } */
/* { dg-final { scan-assembler-times "\tjrc.hb\t\\\$ra" 1 } } */
