#include "data_struct.h"
#include "write_funcs.h"

#define true 1

void master_write(FILE* o_file, Data client) {
  while (true) {
    char data[8][30] = {"1 Account number:", "2 Client name: ",
                        "3 Client surname: ", "4 Client adress : ",
                        "5 Client Telnum: ", "6 Client indebtedness: ",
                        "7 Client credit limit: ", "8 Client cash payments: "};
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 30; ++j) {
        printf("%c", data[i][j]);
      }
      printf("\n");
    }
    if (scanf("%12d%11s%11s%16s%20s%14lf%14lf%14lf",
               &client.number,
                client.name,
                client.surname,
                client.adress,
                client.tel_number,
               &client.indebtedness,
               &client.credit_limit,
               &client.cash_payments) != 8)
      break;
    fprintf(o_file, "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n",
                      client.number,
                      client.name,
                      client.surname,
                      client.adress,
                      client.tel_number,
                      client.indebtedness,
                      client.credit_limit,
                      client.cash_payments);
    }
}

void transaction_write(FILE* o_file, Data transfer) {
  while (true) {
    printf("%10s\n%10s\n", "1 Account number: ", "2 Client cash payments: ");
    if (scanf("%3d%8lf", &transfer.number, &transfer.cash_payments) != 2)
      break;
    fprintf(o_file, "%-3d%-6.2f\n", transfer.number, transfer.cash_payments);
  }
}

void black_record(FILE* client_data_file, FILE* transfer_data_file,
                  FILE* blackrecord_file, Data client_data, Data transfer) {
  while (fscanf(client_data_file, "%12d%11s%11s%16s%20s%14lf%14lf%14lf",
                                   &client_data.number,
                                    client_data.name,
                                    client_data.surname,
                                    client_data.adress,
                                    client_data.tel_number,
                                   &client_data.indebtedness,
                                   &client_data.credit_limit,
                                   &client_data.cash_payments) == 8) {
    while (fscanf(transfer_data_file, "%d %lf", &transfer.number, &transfer.cash_payments) == 2)
      if (client_data.number == transfer.number && transfer.cash_payments != 0)
        client_data.credit_limit += transfer.cash_payments;
    fprintf(blackrecord_file, "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n",
                                client_data.number,
                                client_data.name,
                                client_data.surname,
                                client_data.adress,
                                client_data.tel_number,
                                client_data.indebtedness,
                                client_data.credit_limit,
                                client_data.cash_payments);
    rewind(transfer_data_file);
    }
}
