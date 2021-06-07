// { dg-additional-options -fmodules-ts }
// { dg-require-effective-target exceptions_enabled }
// Make sure we're not confused by an imported declaration of a
// library fn
export module foo;
// { dg-module-cmi foo { xfail { ! exceptions_enabled } } }

export inline void thrower ()
{
  try 
    {
      throw 1;
    }
  catch (...)
    {
    }
}
