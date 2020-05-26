#include <stdio.h>
#include <stdlib.h>

struct Order{
    char *orderID;
    char *orderType;
    char *offerType;
    int *offerQty;
    int *qty;
    float *amount;

};

struct ItemMetaData{
    char *offerType;
    float discForOne;
    float discForTwo;
    float discForMulti;
};

struct ItemMetaData pizza;
struct ItemMetaData pasta;
int main()
{
    initItems();
   printf(pasta.offerType);
    return 0;
}

void initItems(){
    //For Pizza

    pizza.offerType = "Garlic Bread";
    pizza.discForOne =1.0;
    pizza.discForTwo =0.91666667;
    pizza.discForMulti=0.83333333;

    //For Pasta

    pasta.offerType = "Soft Drink";
    pasta.discForOne =1.0;
    pasta.discForTwo =0.9375;
    pasta.discForMulti=0.875;
}
