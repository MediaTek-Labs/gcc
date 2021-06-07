// { dg-module-do run }
// { dg-additional-options -fmodules-ts }
// { dg-require-effective-target rtti_enabled }
export module foo;
// { dg-module-cmi foo { xfail { ! rtti_enabled } } }

export struct Visitor
{
  virtual int Visit ();
};

// Key function explicitly not in line (regardless of p1779's state)
// We emit vtables & rtti only in this TU
int Visitor::Visit ()
{
  return 0;
}

export int Visit (Visitor *v)
{
  return v->Visit ();
}

// { dg-final { scan-assembler {_ZTV7Visitor:} } }
// { dg-final { scan-assembler {_ZTI7Visitor:} } }
// { dg-final { scan-assembler {_ZTS7Visitor:} } }
