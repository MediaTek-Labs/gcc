// { dg-do compile }
// { dg-require-effective-target rtti_enabled }

struct A { virtual ~A() { }; };
struct B : A { };

void f(B* bp)
{
  bp =
#ifdef __GXX_RTTI
  dynamic_cast<B*>(static_cast<A*>(0));
#endif
}
