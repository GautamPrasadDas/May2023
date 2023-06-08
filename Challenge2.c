#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef struct my_date_t
{
    uint8_t date;  /*< date */
    uint8_t month; /*< month */
    uint16_t year; /*< year */
} my_date_t;

typedef enum status_t
{
    SUCCESS,
    NULL_PTR,
    INCORRECT
} status_t;

status_t string_to_date_converter(char *input_string, my_date_t *dateStruct)
{
    if (input_string == NULL || dateStruct == NULL)
    {
        return NULL_PTR;
    }

    int date, month, year;
    if (sscanf(input_string, "%d/%d/%d", &date, &month, &year) != 3)
    {
        return INCORRECT;
    }
    if (date < 1 || date > 31 || month < 1 || month > 12 || year < 0)
    {
        return INCORRECT;
    }
    dateStruct->date = (uint8_t)date;
    dateStruct->month = (uint8_t)month;
    dateStruct->year = (uint16_t)year;
    return SUCCESS;
}

int main()
{
    my_date_t date;
    char str[12];
    printf("Enter the date in format(DD/MM/YYYY):");
    scanf("%s", str);
    status_t result = string_to_date_converter(str, &date);
    // int DD,MM,YYYY;
    if (result == SUCCESS)
    {
        printf("Function has successfully converted the string to structure");
    }
    else if (result == NULL_PTR)
    {
        printf("Function is given NULL pointers to work with");
    }
    else if (result == INCORRECT)
    {
        printf("Incorrect values for date or month or year");
    }
    return 0;
}