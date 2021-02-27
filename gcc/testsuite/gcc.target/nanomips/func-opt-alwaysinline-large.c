/* { dg-do compile }
/* { dg-options "-mfunc-opt-list=func-opt-list.txt" } */
/* { dg-additional-options "-DOPTOFF" } */
/* { dg-skip-if "optimization controlled by -mfunc-opt-list" { *-*-* } { "-O1" "-O2" "-O3" "-Os" "-mno-pcrel" } } */
/* { dg-skip-if "C model specific pattern" { *-*-* } { "*" } { "-mcmodel=large" } } */
/* { dg-final { scan-assembler "baz:\[^:\]*lapc.b\t(\[^,\]+),andrea\n\tjalrc\t\\1\n" } } */

#include "func-opt-alwaysinline.c"

