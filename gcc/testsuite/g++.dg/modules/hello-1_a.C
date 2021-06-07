// { dg-module-do run }
// { dg-additional-options -fmodules-ts }
// { dg-require-effective-target rtti_enabled }

module;
#include <iostream>
#include <string_view>
export module hello;
// { dg-module-cmi hello { xfail { ! rtti_enabled } } }
export void greeter (std::string_view const &name)
{
  std::cout << "Hello " << name << "!\n";
}
