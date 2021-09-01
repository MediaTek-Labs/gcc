// { dg-do link { target nanomips*-*-* } }
// { dg-options "-nortti-libstdc++" }

/* Using a throwing new with -nortti-libstdc++ should not
   try to throw std::bad_alloc */

int main (void)
{
   __asm__ __volatile__ (""::"r"(new int(0)));
   return 0;
}

/* { dg-final { scan-symbol "_Znwj" } } */
/* { dg-final { scan-symbol-not "__cxa_allocate_exception" } } */