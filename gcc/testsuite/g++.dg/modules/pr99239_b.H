// { dg-additional-options {-fmodule-header -fno-module-lazy} }
// { dg-require-effective-target exceptions_enabled }
// { dg-module-cmi {} { xfail { ! exceptions_enabled } } }
import  "pr99239_a.H";
       
inline void
  _M_remove_reference() throw()
{
  try
    { }
  catch(...)
    { }
}
