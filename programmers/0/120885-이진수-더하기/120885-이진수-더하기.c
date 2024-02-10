#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int binary2decimal(const char* bin)
{
    int dec = 0;

    while (*bin != '\0')
    {
        dec <<= 1;
        dec += (int)(*bin++ - '0');
    }

    return dec;
}

char* decimal2binary(int decimal)
{
    char* bin = NULL;
    bin = (char*)malloc(13);

    char* p = bin;
    char* q = bin;

    if (decimal == 0)
    {
        *q = '0';
        *(q + 1) = '\0';
        goto lb_exit;
    }

    while (decimal > 0)
    {
        *q++ = (decimal & 1) + '0';
        decimal >>= 1;
    }
    *q-- = '\0';

    while (p < q)
    {
        int temp = *p;
        *p = *q;
        *q = temp;
        ++p;
        --q;
    }

lb_exit:
    return bin;
}

char* solution(const char* bin1, const char* bin2)
{
    int dec1 = binary2decimal(bin1);
    int dec2 = binary2decimal(bin2);
    int result_dec = dec1 + dec2;
    char* result_bin = decimal2binary(result_dec);

    return result_bin;
}