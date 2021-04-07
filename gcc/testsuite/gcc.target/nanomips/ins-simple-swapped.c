/* { dg-do run } */
/* { dg-options "-march=32r6" } */
/* { dg-skip-if "code quality test" { *-*-* } { "-O0" } { "" } } */
/* { dg-final { scan-assembler "\tins\t" } } */

extern void abort (void);

__attribute__((noinline)) int test (int x, int y) {
  const int pos = 4;
  const int len = 12;
  const unsigned mask = ( 0xffffffffu >> (32 - len) );
  return (x & ~ (mask<<pos) )|  ( (y&mask) << pos);
}

struct {
  unsigned x; unsigned y; unsigned result;
} data[] = {
  { 0xf2404ed9, 0x7e1bbdcc, 0xf240dcc9 },
  { 0xd05db768, 0x11aefbee, 0xd05dbee8 },
  { 0x1e46b904, 0x96401c03, 0x1e46c034 },
  { 0xb7b3875c, 0xc9a9d9e6, 0xb7b39e6c },
  { 0x2b5efceb, 0x161a58de, 0x2b5e8deb },
  { 0x5dae0ea2, 0xce677654, 0x5dae6542 },
  { 0x2679ef55, 0x37051a40, 0x2679a405 },
  { 0xb642fabb, 0x1ff09691, 0xb642691b },
  { 0x222e37cf, 0x6f11aabb, 0x222eabbf },
  { 0x1d6fd678, 0xb14a3565, 0x1d6f5658 },
};

int main (void) {
  int i;

  for (i = 0; i < sizeof(data)/sizeof(data[0]); i++) {
    if (test (data[i].x, data[i].y) != data[i].result)
      abort ();
  }
  return 0;
}
