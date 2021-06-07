// { dg-do compile }
// { dg-require-effective-target exceptions_enabled }

void
a (int b)
{
  if (b)
    throw;
  try
    {
      a (3);
    }
  catch (int)
    {
    }
  catch (int) // { dg-warning "will be caught by earlier handler" }
    {
    }
}

