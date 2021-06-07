// { dg-additional-options -fmodules-ts }
// { dg-require-effective-target exceptions_enabled }
import foo;

void bar ()
{
  thrower ();
}

void baz ()
{
  try 
    {
      throw 1;
    }
  catch (...)
    {
    }
}
