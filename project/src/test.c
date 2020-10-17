#include "test_write.h"
#include "test_read.h"
#include "stdio.h"

void test_write_to_file() {
  printf("START TEST\n");
  const char *filename = "test.txt";
  Data emplo = {1, name_1, surname_1, address_1, tel_1, 80, 150, 20};
  write_to_file(filename, &emplo);
  Data got_data = NULL;
  read_from_file(filename, &got_data);
  if (got_data == emplo) {
    printf("Прочитанные и записанные данные совпали!\n");
  } else {
  printf("Прочитанные и записанные данные не совпали!");
  }
  printf("END TEST\n");
}
