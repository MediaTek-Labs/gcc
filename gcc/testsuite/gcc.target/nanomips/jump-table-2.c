/* { dg-options "-march=32r6" } */
/* { dg-additional-options "-mjump-table-opt" } */
/* { dg-skip-if "code quality test" { *-*-* } { "-O0" } { "" } } */

#include "branch-helper.h"

int x0, x1, x2, x3, x4, x5, x6, x7, x8;

int
foo (int i)
{
  switch (i)
    {
    case 1: OCCUPY_0x3ffc; OCCUPY_0x7fc; return x1;
    case 2: OCCUPY_0x3ffc; OCCUPY_0x7fc; return x2;
    case 3: OCCUPY_0x3ffc; OCCUPY_0x7fc; return x3;
    case 4: OCCUPY_0x3ffc; OCCUPY_0x7fc; return x4;
    case 5: OCCUPY_0x3ffc; OCCUPY_0x7fc; return x5;
    case 6: OCCUPY_0x3ffc; OCCUPY_0x7fc; return x6;
    case 7: OCCUPY_0x3ffc; OCCUPY_0x7fc; return x7;
    case 8: OCCUPY_0x7fc; return x8;
    default: return x0;
    }
}

/* { dg-final { scan-assembler "\tlhuxs\t" } } */
/* { dg-final { scan-assembler-times "\t\\.hword\t" 8 } } */
