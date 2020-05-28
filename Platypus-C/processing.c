#include "headers.h"

//Amount Calculation
float calcAmount(struct ItemMetaData item, int qty){
    if (qty == 1)
        return qty*item.discForOne*item.unitPrice;
    else if (qty == 2)
        return qty*item.discForTwo*item.unitPrice;
    else if (qty >= 3)
        return qty*item.discForMulti*item.unitPrice;
    else
        perror("Invalid Quantity");
        exit(1) ; // Generic Error - Operation not permitted
}

//Initialize Menu
void initItems(){
    //For Pizza
    pizza.type = "pizza";
    pizza.offerType = "Garlic Bread";
    pizza.discForOne =1.0;
    pizza.discForTwo =0.91666667;
    pizza.discForMulti=0.83333333;
    pizza.unitPrice = 12.0;
    pizza.offerReq = 3;

    //For Pasta
    pasta.type = "pasta";
    pasta.offerType = "Soft Drink";
    pasta.discForOne =1.0;
    pasta.discForTwo =0.9375;
    pasta.discForMulti=0.875;
    pasta.unitPrice=8.0;
    pasta.offerReq = 3;

    //Miscellaneous Items
    misc_1.type = "Special Offers";
    misc_1.offerType = "Baklawa";
    misc_1.discForOne =0;
    misc_1.discForTwo =0;
    misc_1.discForMulti=0;
    misc_1.unitPrice=0;
    misc_1.offerReq =0;
}

//Make Order - Adding items
struct Order makeOrder(struct ItemMetaData item, char orderId, int qty){
    struct Order thisOrder;
    thisOrder.amount+=calcAmount(item,qty);
    thisOrder.offerQty=(int)qty/3;
    thisOrder.offerType=item.offerType;
    thisOrder.qty=qty;
    thisOrder.orderType=item.type;
    return thisOrder;

}
