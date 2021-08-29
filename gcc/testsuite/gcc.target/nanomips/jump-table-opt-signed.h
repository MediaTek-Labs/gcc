#define F(n)								\
__attribute__((noclone, noinline)) int					\
f##n (int fa1, int fa2, int fa3, int fa4, int fa5, int fa6, int fa7, int fa8) \
{									\
  return n;								\
}

#define TESTS					\
F (0) \
F (1) \
F (2) \
F (3) \
F (4) \
F (5)

/* Declare a large array to blow up the common section.  */
int a0[524288];
/* All of these end-up outside direct GP-relative range.  */
volatile int a1, a2, a3, a4, a5, a6, a7, a8;

TESTS
#undef F
#define F(n) case n: ret = f##n (a1, a2, a3, a4, a5, a6, a7, a8); break;

int
main (void)
{
  int i;
  for (i = 0; i <= 6; i++)
    {
      int ret;
      int flag = 0;
stop:
     /* Prevent optimizer from duplicating this block */
      __asm__ __volatile__("nop\nnop\nnop\nnop\n"
			   "nop\nnop\nnop\nnop\n"
			   "nop\nnop\nnop\nnop\n"
			   "nop\nnop\nnop\nnop\n"
			   :"+r"(flag));
      if (flag++)
        return 0;

      switch (i) {
	TESTS
	case 6: goto stop;
	default: ret = 0; break;
	  }
      if (ret != i)
	return 1;
    }
  return 1;
}
