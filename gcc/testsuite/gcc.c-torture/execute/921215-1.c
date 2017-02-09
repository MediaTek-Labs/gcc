/* { dg-require-effective-target trampolines } */

/* { dg-skip-if "nanoMIPS: needs fixing" { nanomips-*-* } { "*" } { "" } } */
main()
{
  void p(void ((*f) (void ())))
    {
      void r()
	{
	  foo ();
	}

      f(r);
    }

  void q(void ((*f)()))
    {
      f();
    }

  p(q);

  exit(0);
}

foo(){}
