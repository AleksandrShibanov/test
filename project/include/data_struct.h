#ifndef PROJECT_INCLUDE_DATA_STRUCT_H_
#define PROJECT_INCLUDE_DATA_STRUCT_H_
typedef struct {
    int number;
    char name[20];
    char surname[20];
    char adress[30];
    char tel_number[15];
    double indebtedness;
    double credit_limit;
    double cash_payments;
} Data;
#endif  // PROJECT_INCLUDE_DATA_STRUCT_H_
