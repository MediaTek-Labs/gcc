/* { dg-do compile } */
/* { dg-options "-mfunc-opt-list=func-opt-list-syntax.txt" } */
/* { dg-warning "Unknown attribute 'comment' for 'a'" "func-opt-list-syntax.txt:4" { target *-*-* } 1 } */
/* { dg-warning "Unknown attribute 'x' for 'b'" "func-opt-list-syntax.txt:7" { target *-*-* } 1 } */
/* { dg-warning "Unknown attribute 'Ov101' for 'h'" "func-opt-list-syntax.txt:20" { target *-*-* } 1 } */
/* { dg-warning "Attribute 'Os' cannot be applied to function 'j' as it has the conflicting attribute 'O3'" "func-opt-list-syntax.txt:26" { target *-*-* } 1 } */
/* { dg-warning "Attribute 'O1' cannot be applied to function 'k' as it has the conflicting attribute 'Os'" "func-opt-list-syntax.txt:30" { target *-*-* } 1 } */
/* { dg-warning ":30:2: Unexpected '\\('. Attribute parameters not preceded by an attribute" "func-opt-list-syntax.txt:31" { target *-*-* } 1 } */
/* { dg-warning ":33:2: Unexpected '\\('. Attribute parameters not preceded by an attribute" "func-opt-list-syntax.txt:34" { target *-*-* } 1 } */
/* { dg-error ":39:11: Unexpected ','" "func-opt-list-syntax.txt:39" { target *-*-* } 1 } */
/* { dg-error ":46:11: Unexpected ','" "func-opt-list-syntax.txt:46" { target *-*-* } 1 } */
/* { dg-error ":66:8: Expected '\"'" "func-opt-list-syntax.txt:66" { target *-*-* } 1 } */
/* { dg-error ":69:8: Expected '\\('" "func-opt-list-syntax.txt:69" { target *-*-* } 1 } */
/* { dg-error ":69:9: Expected '\"'" "func-opt-list-syntax.txt:69" { target *-*-* } 1 } */
/* { dg-error ":69:9: Expected '\\)'" "func-opt-list-syntax.txt:69" { target *-*-* } 1 } */
/* { dg-error ":72:16: Expected '\\)'" "func-opt-list-syntax.txt:72" { target *-*-* } 1 } */


#include <stddef.h>

int a (int x)
{
  return x + 1;
}

int b (int x)
{
  return x - 1;
}

int c (int x)
{
  return x++;
}

int d (void *x, void *y)
{
  *(int *)y = *(int *)x;
  return *(int *)y;
}

int e (int *y)
{
  return d (y, NULL);
}
