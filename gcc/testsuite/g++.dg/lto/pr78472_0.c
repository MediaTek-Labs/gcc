// { dg-lto-do link }
// { dg-require-effective-target rtti_enabled }

extern struct S
{
  unsigned i:4;
  unsigned :0;
} s;
static void *f(void)
{
  return &s;
}
int main() {}
