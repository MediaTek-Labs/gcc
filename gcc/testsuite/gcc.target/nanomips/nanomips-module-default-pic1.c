/* Default for linux is pic1  */
/* { dg-do compile { target nanomips*-linux-* } }  */
/* { dg-options "-march=32r6 -ffat-lto-objects" }  */
/* { dg-final { scan-assembler "\\\.module\tpic1" } }  */

void foo (void) { }
