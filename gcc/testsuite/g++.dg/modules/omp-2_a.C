// { dg-additional-options "-fmodules-ts -fopenmp" }
// { dg-xfail-if "" { ! fopenmp } }

export module foo;
// { dg-module-cmi foo { xfail { ! fopenmp } } }

// The OpenMPness doesn't escape to the interface.
export void frob (unsigned (&ary)[64])
{
  int sum = 0;

#pragma omp for
  for (unsigned ix = 0; ix < 64; ix++)
    sum += ary[ix];

#pragma omp simd safelen(16) aligned (ary : 16)
  for (unsigned ix = 0; ix < 64; ix++)
    ary[ix] *= 2;
}
