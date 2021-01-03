/* { dg-do compile }
/* { dg-options "-mfunc-opt-list=func-opt-list.txt" } */
/* { dg-additional-options "-O0 -DOPTOFF" } */
/* { dg-final { scan-assembler-not "sabrina" } } */
/* { dg-skip-if "" { *-*-* } { "-O3 -g" } } */

#include "func-opt-alwaysinline.c"

