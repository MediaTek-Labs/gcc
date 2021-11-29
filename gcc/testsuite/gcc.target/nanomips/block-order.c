/* { dg-do compile } */
/* { dg-skip-if "" { *-*-* } { "-O1" "-O2" "-O3" "-O0" } { "" } } */

typedef struct list_head_s {
  struct list_head_s *next;
} list_head;

list_head *core_list_reverse (list_head *list)
{
  list_head *next = 0, *tmp;
  while (list) {
    tmp = list->next;
    list->next = next;
    next = list;
    list = tmp;
  }
  return next;
}

/* { dg-final { scan-assembler "\tbc.*L\[0-9\]+\n.L\[0-9\]+:\n" } } */
