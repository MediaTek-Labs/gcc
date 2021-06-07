// { dg-additional-options -fmodules-ts }
// { dg-require-effective-target rtti_enabled }

#include <string_view>
import hello;
int main (void)
{
  greeter ("world");
  return 0;
}
