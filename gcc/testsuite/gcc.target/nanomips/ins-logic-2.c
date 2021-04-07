/* { dg-do run } */
/* { dg-options "-march=32r6" "-save-temps" } */
/* { dg-skip-if "code quality test" { *-*-* } { "-O0" } { "" } } */
/* { dg-final { scan-assembler "\tins\t" } } */

extern void abort (void);

__attribute__((noinline))
int test (int x, int y, int z) {
  const int pos = 4;
  const int len = 12;
  const unsigned mask = ( 0xffffffffu >> (32 - len) );
  const int zpos = 20;
  const int zlen = 8;
  const unsigned zmask = ( 0xffffffffu >> (32 - zlen) );
  unsigned xy = (x & ~ (mask<<pos) ) | ( (y&mask) << pos);
  unsigned xyz = (xy & ~(zmask<<zpos)) | ( (z&zmask) <<zpos);
  return xyz;
}

struct {
  unsigned x; unsigned y; unsigned z; unsigned result;
} data[] = {
  { 0xf9b39697, 0x770d499d, 0x6c765537, 0xf37399d7 },
  { 0xd94dd93c, 0x3d39dceb, 0x9bd49221, 0xd21dcebc },
  { 0x2db75861, 0x6cdc2282, 0x277b2cc, 0x2cc72821 },
  { 0x2f8ca00d, 0xa7d7a022, 0x60b8d3c8, 0x2c8c022d },
  { 0xfc31c46, 0x9509bb92, 0xf871a768, 0x683b926 },
  { 0xec205bec, 0x7f2cacdb, 0xcfd659fe, 0xefe0cdbc },
  { 0x3798b0cd, 0x8d48f129, 0x39917307, 0x3078129d },
  { 0xcd93314c, 0xc7b5e937, 0x8ecd5e09, 0xc093937c },
  { 0xace4f236, 0x60b5ab69, 0xc08ff213, 0xa134b696 },
};

int main (void) {
  int i;
  for (i = 0; i < sizeof(data)/sizeof(data[0]); i++) {
    if (test (data[i].x, data[i].y, data[i].z) != data[i].result)
      abort ();
  }
  return 0;
}
