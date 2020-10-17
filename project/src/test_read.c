void read_from_file(const char *filename, Data *data) {
  file = fopen(filename, "r+");
    if (file == NULL) {
      printf("NO ACCESS\n");
    } else {
             fscanf(client_data_file, "%12d%11s%11s%16s%20s%14lf%14lf%14lf",
                                       &data.number,
                                        data.name,
                                        data.surname,
                                        data.adress,
                                        data.tel_number,
                                       &data.indebtedness,
                                       &data.credit_limit,
                                       &data.cash_payments)
}
}
