// { dg-additional-options -fmodule-header }
// { dg-require-effective-target exceptions_enabled }
// { dg-module-cmi {} { xfail { ! exceptions_enabled } } }

class bad_optional_access
{
public:

  virtual ~bad_optional_access() noexcept = default; // { dg-bogus "" }
};

inline void
__throw_bad_optional_access()
{
  throw bad_optional_access ();
}

