
EXTERN(main)
ENTRY(main)

SECTIONS
{
  .text :
  {
    "*archive_name.a:object_name_c.o" (.text*)
    "*archive_name.a:object_name_b.o" (.text*)
    *object_name_a.o (.text*)
  }
  /DISCARD/ : { *(*) }
}
