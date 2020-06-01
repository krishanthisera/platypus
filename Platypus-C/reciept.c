#include "headers.h"

void printReciept(char orderId, int pizzaQty, float pizzaValue, int pastaQty, float pastaValue, int terminalWidth){
    printf("\n \n \n!-------------------------<-[PlatypuS]->-------------------------!\n");

    printPizzaLogo();
    printf("!---------------------------<-[Pizza]->--------------------------!\n");
    printf("\n Quantity of Pizza Order :%d", pizzaQty);
    printf("\n Value of Pizza Order :%2f", pizzaValue);
    printf("\n Eligible generic Offers :%s", pizza.offerType);
    printf("\n This order deserve :%d \n", (int)(pizzaQty/pizza.offerReq));


    printPastaLogo();
    printf("!--------------------------<-[Pasta]->---------------------------!\n");
    printf("\nQuantity of Pasta Order :%d", pastaQty);
    printf("\nValue of Pasta Order :%.2f", pastaValue);
    printf("\nEligible generic Offers :%s", pasta.offerType);
    printf("\nThis order deserve :%d \n", (int)(pastaQty/pasta.offerReq));
    printf("!=========================<-[PlatypuS]->=========================!\n");

    printf("\n!------------------------<-[Total Cost]->------------------------!\n");
    printf("\nTotal Cost of this Order: %.2f \n", pastaValue + pizzaValue );
    printf("\n!----------------------<-[%s]->----------------------!\n", misc_1.type);
    printf("\nEligible Special Offers :%s", misc_1.offerType );
    printf("\nThis order deserve :%d \n", minFunction(pizzaQty,pastaQty)/3);
    printf("\n!-------------------------<-[PlatypuS]->-------------------------!\n");
}
