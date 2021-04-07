/* { dg-do run } */
/* { dg-options "-march=32r6" "-save-temps" } */
/* { dg-skip-if "code quality test" { *-*-* } { "-O0" } { "" } } */
/* { dg-final { scan-assembler "\tins\t" } } */

extern void abort (void);

__attribute__((noinline))
int test (int x) {
  return (x << 7) & ( 0xfffff << 7);
}

struct {
  unsigned x; unsigned result;
} data[] = {
  { 0xf9b39697, 0x1cb4b80 },
  { 0xd94dd93c, 0x6ec9e00 },
  { 0x2db75861, 0x3ac3080 },
  { 0x2f8ca00d, 0x6500680 },
  { 0xfc31c46, 0x18e2300 },
  { 0xec205bec, 0x2df600 },
  { 0x3798b0cd, 0x4586680 },
  { 0xcd93314c, 0x198a600 },
  { 0xace4f236, 0x2791b00 },
};

int main (void) {
  int i;

  for (i = 0; i < sizeof(data)/sizeof(data[0]); i++) {
   if (test (data[i].x) != data[i].result)
      abort ();
  }
  return 0;
}
