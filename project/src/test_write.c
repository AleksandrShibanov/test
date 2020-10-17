#include "data_struct.h"
void write_to_file(const char *filename, Data *data) {
  file = fopen(filename, "r+");
    if (file == NULL) {
      printf("NO ACCESS\n");
    } else {
             fprintf(file, "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n",
                            data.number,
                            data.name,
                            data.surname,
                            data.adress,
                            data.tel_number,
                            data.indebtedness,
                            data.credit_limit,
                            data.cash_payments);
  }
}
