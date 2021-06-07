// PR 99239 ICE on catch clause
// { dg-additional-options -fmodule-header }
// { dg-require-effective-target exceptions_enabled }
// { dg-module-cmi {} { xfail { ! exceptions_enabled } } }

inline void Foo ()
{
  try
    {}
  catch(...)
    {
    }
}

