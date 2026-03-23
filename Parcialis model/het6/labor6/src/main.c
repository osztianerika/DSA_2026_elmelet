#include "functions.h"
#include <stdio.h>
#include <customs/constants.h>

int main(void)
{
    Order_t order1, order2;
    //readOneOrder(&order1);
    //printOneOrder(order1);
    if(!freopen("order_one.txt", "r", stdin))
    {
        printf(FILE_OPENING_ERROR_MESSAGE);
        return FILE_OPENING_ERROR_CODE;
    }
    readOneOrder(&order2);
    freopen("con", "r", stdin);
    printOneOrder(order2);
    Order_t order3 = {100, 
        "pityoka", 
        2.35f, 
        {2020, 06, 13, 20, 53},
        ONLINE,
        1
    };
    printOneOrder(order3);
    return 0;
}