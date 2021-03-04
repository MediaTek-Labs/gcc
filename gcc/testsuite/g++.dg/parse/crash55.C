// PR c++/42038
// { dg-require-effective-target exceptions_enabled }

extern int __cxa_begin_catch;

void f(void)
{
  try { } catch (int) { } // { dg-error "cannot be used" }
}
