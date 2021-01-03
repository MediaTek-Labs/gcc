/* { dg-do compile }
/* { dg-options "-mfunc-opt-list=func-opt-list.txt" } */
/* { dg-additional-options "-O0" } */
/* { dg-skip-if "" { *-*-* } { "-g" } } */
/* { dg-final { scan-assembler-not "sabrina" } } */
/* { dg-final { scan-assembler-not "jessica" } } */

#include "func-opt-alwaysinline.c"
