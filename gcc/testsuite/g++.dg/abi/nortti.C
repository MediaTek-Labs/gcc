// { dg-do link { target nanomips*-*-* } }
// { dg-options "-nortti-libstdc++" }

#include <stdexcept>


// Derived from libstdc++/2089
class fuzzy_logic : public std::logic_error
{
public:
  fuzzy_logic() : std::logic_error("") { }
};

int test03()
{
  try
    { throw fuzzy_logic(); }
  catch(const fuzzy_logic& obj)
    { return 0; }
  catch(...)
    { return 1; }
}

int main(void)
{
  return test03();
}

// { dg-excess-errors "undefined reference to 'typeinfo for std::logic_error'" }
