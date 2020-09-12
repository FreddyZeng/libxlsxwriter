/*
 * Example of writing some data to a simple Excel file using libxlsxwriter.
 *
 * Copyright 2014-2018, John McNamara, jmcnamara@cpan.org
 *
 */
#include <stdlib.h>
#include "xlsxwriter.h"

int main(int argc, char  *argv[]) {

    int max_row;
    int max_col;
    int max_length;
    char string[] = "abcdefghijklmnopqrstuvwxyz_";

    if (argc < 3) {
        puts("usage: perf_test row_num col_num string_length");
        return -1; 
    }

    max_row    = atoi(argv[1]);
    max_col    = atoi(argv[2]);
    max_length = atoi(argv[3]);

    if (max_length > 26) {
        puts("usage: perf_test row_num col_num string_length");
        puts("       string_length must be <= 26");
    }

    string[max_length] = '\0';
    printf("rows = %d x cols = %d x string length = %d\n", max_row, max_col, max_length);


    lxw_workbook_options options = {.constant_memory = LXW_TRUE};
    lxw_workbook  *workbook  = workbook_new_opt("test.xlsx", &options);
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);

    for (int row_num = 0; row_num < max_row; row_num++)
        for (int col_num = 0; col_num < max_col; col_num++)
            worksheet_write_string(worksheet, row_num, col_num, string, NULL);

    workbook_close(workbook);

    return 0;
}
