/* { dg-do compile } */
/* { dg-final { scan-assembler "\tnot\t" } } */

int
foo (int a)
{
  return ~a;
}
