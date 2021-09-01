// { dg-do run { target nanomips*-*-* } }
// { dg-require-effective-target exceptions_enabled }

/* We expect for std::logic_error vtable  to pull in its type_info
   when libstdc++ exports one */

extern char _ZTVSt11logic_error;

extern char _ZTISt11logic_error __attribute__((weak));

int main (void)
{
   __asm__ __volatile__(""::"r"(&_ZTVSt11logic_error));

   if (&_ZTISt11logic_error)
      return 0;
   return 1;
}
