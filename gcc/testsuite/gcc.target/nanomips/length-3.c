/* { dg-options "-dp -mno-gpopt -mcmodel=medium -march=nms1 -mno-pcrel -fno-pic" } */
/* { dg-final { scan-assembler "\[^\n\]*l=4\[^\n\]*movsi_nanomips/6" } } */
/* { dg-xfail-if "incompatible with PID mode" { *-*-* } { "-mpid" } { "" } } */

int g;

int* f1()
{
  return &g;
}

