/* { dg-options "-ffat-lto-objects" } */
/* { dg-skip-if "Code quality test" { *-*-* } { "-O0" } { "" } } */

int foo (unsigned int a)
{
    return __builtin_clz (~a);
}

/* { dg-final { scan-assembler-not "\tclz\t" } } */
/* { dg-final { scan-assembler "\tclo\t" } } */
