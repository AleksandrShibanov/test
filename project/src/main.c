#include "data_struct.h"
#include "write_funcs.h"
#include "stdlib.h"

#define true 1

int main(void) {
  int choice = 0;
  FILE *client_data_file = NULL, *transfer_data_file = NULL, *blackrecord_file = NULL;
  Data client_data = {}, transfer = {};
  while (true) {
    printf("%s", "please enter action\n1 enter data client:\n2 enter data transaction:\n3 update base\n");
    if (scanf("%d", &choice) != 1)
      break;
    switch (choice) {
      case 1:
        client_data_file = fopen("record.dat", "r+");
        if (client_data_file == NULL) {
          printf("NO ACCESS\n");
        } else {
                 master_write(client_data_file, client_data);
                 fclose(client_data_file);
        }
        break;
      case 2:
        transfer_data_file = fopen("transaction.dat", "r+");
        if (transfer_data_file == NULL) {
          printf("NO ACCESS\n");
        } else {
                 transaction_write(transfer_data_file, transfer);
                 fclose(transfer_data_file);
        }
        break;
      case 3:
        client_data_file = fopen("record.dat", "r");
        transfer_data_file = fopen("transaction.dat", "r");
        blackrecord_file = fopen("blackrecord.dat", "w");
        if (client_data_file == NULL || transfer_data_file == NULL || blackrecord_file == NULL) {
          printf("ERROR\n");
        } else {
                 black_record(client_data_file, transfer_data_file, blackrecord_file, client_data, transfer);
                 fclose(client_data_file);
                 fclose(transfer_data_file);
                 fclose(blackrecord_file);
        }
        break;
      default:
        printf("ERROR\n");
      }
    }
  return 0;
}
