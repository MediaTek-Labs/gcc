/* { dg-do run } */
/* { dg-options "-march=32r6" "-save-temps" } */
/* { dg-skip-if "code quality test" { *-*-* } { "-O0" } { "" } } */
/* { dg-final { scan-assembler "\tins\t" } } */

extern void abort (void);

__attribute__((noinline))
int test (int x, int y, int z) {
  return ((x & 0xf) << 30) | ( ( y & 0xf) << 20) | ( ( z & 0x1f) << 10);
}

struct {
  unsigned x; unsigned y; unsigned z; unsigned result;
} data[] = {
  { 0xf9b39697, 0x770d499d, 0x6c765537, 0xc0d05c00 },
  { 0xd94dd93c, 0x3d39dceb, 0x9bd49221, 0xb00400 },
  { 0x2db75861, 0x6cdc2282, 0x277b2cc, 0x40203000 },
  { 0x2f8ca00d, 0xa7d7a022, 0x60b8d3c8, 0x40202000 },
  { 0xfc31c46, 0x9509bb92, 0xf871a768, 0x80202000 },
  { 0xec205bec, 0x7f2cacdb, 0xcfd659fe, 0xb07800 },
  { 0x3798b0cd, 0x8d48f129, 0x39917307, 0x40901c00 },
  { 0xcd93314c, 0xc7b5e937, 0x8ecd5e09, 0x702400 },
  { 0xace4f236, 0x60b5ab69, 0xc08ff213, 0x80904c00 },
};

int main (void) {
  int i;

  for (i = 0; i < sizeof(data)/sizeof(data[0]); i++) {
    if (test (data[i].x, data[i].y, data[i].z) != data[i].result)
      abort ();
  }
  return 0;
}
