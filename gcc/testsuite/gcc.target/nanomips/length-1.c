/* { dg-options "-dp" } */
/* { dg-final { scan-assembler "\[^\n\]*l=6\[^\n\]*movsi_nanomips/5" } } */
/* { dg-final { scan-assembler "\[^\n\]*l=4\[^\n\]*movsi_nanomips/5" } } */

int f1 ()
{
  return 0x87654321;
}

int f2 ()
{
  return -0x000000f1;
}
