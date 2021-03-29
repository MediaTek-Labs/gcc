
extern int foo (int i);
extern int bar (int i);

int main (void)
{
  return foo (bar (1));
}
