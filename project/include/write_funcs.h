#include "stdio.h"
#ifndef PROJECT_INCLUDE_WRITE_FUNCS_H_
#define PROJECT_INCLUDE_WRITE_FUNCS_H_
void master_write(FILE* o_file, Data client);
void transaction_write(FILE* o_file, Data transfer);
void black_record(FILE* client_data_file,
                  FILE* transfer_data_file,
                  FILE* blackrecord_file,
                  Data client_data,
                  Data transfer);
#endif  // PROJECT_INCLUDE_WRITE_FUNCS_H_
