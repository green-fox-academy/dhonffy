#include "ask_value.h"
#include <stdio.h>
int ask_value(int x, int y)
{
    int consol_input;
    printf("Please, type the number [%d][%d]!\n", x, y);
    scanf("%d", &consol_input);
    return consol_input;
}
