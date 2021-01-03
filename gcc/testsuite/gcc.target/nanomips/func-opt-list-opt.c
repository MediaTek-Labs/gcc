/* { dg-do compile }
/* { dg-options "-mfunc-opt-list=func-opt-list.txt" } */
/* { dg-additional-options "-fdump-tree-gimple" } */

/* { dg-final { scan-tree-dump "__attribute__\\(\\(optimize \\(\"O0\"\\)\\)\\)\[\n\r\]O_func" "gimple" } } */
int O_func (int x, int y)
{
  return x + y;
}

/* { dg-final { scan-tree-dump "__attribute__\\(\\(optimize \\(\"O2\"\\)\\)\\)\[\n\r\]O2_func" "gimple" } } */
int O2_func (int x, int y)
{
  return x | y;
}

/* { dg-final { scan-tree-dump "__attribute__\\(\\(optimize \\(\"O3\"\\)\\)\\)\[\n\r\]O3_func" "gimple" } } */
int O3_func (int x, int y)
{
  return x ^ y;
}

/* { dg-final { scan-tree-dump "__attribute__\\(\\(optimize \\(\"Os\"\\)\\)\\)\[\n\r\]Os_func" "gimple" } } */
int Os_func (int x, int y)
{
  return x * y;
}
