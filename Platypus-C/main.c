#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "functions.h"
//Maximum number of orders that system can handle.
#define MAX 10

int maxOrderCount;

struct Order{
    char *orderID;
    char *orderType;
    char *offerType;
    int offerQty;
    int qty;
    float amount;
};

struct ItemMetaData{
    char *type;
    char *offerType;
    float discForOne;
    float discForTwo;
    float discForMulti;
    float unitPrice;
    int offerReq;
};

    struct ItemMetaData pizza;
    struct ItemMetaData pasta;
    //Miscellaneous Items, Used in Special offers in this context
    struct ItemMetaData misc_1;



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

//Main Function
int main(int argc, size_t *argv[])
{
    printLogo();
    struct Order orderArray[MAX];
    //Command Line Arguments
    if( argc >= 2 ) {
        //Control Max Order Counter
        if (MAX < argv[1] ){
            maxOrderCount=atoi(argv[1]);
            printf("<-[Platypus]-> - Initiating the System with maximum order count -> %d\n", maxOrderCount);
        }
        else{
            printf("<-[Platypus]-> - Maximum order count should not exceed -> %d \n", MAX);
            exit(2);
        }

   }
   else {
      printf("<-[Platypus]-> - Using default value as Maximum Number of Orders [%d].\n", MAX);
      exit(2);
   }

    //Initialize Item Meta Data
    initItems();

    //flags
    char keepOrderAlive="n";
    char keepSystemAlive="n";

    do{
        //Print Log
        printf("!-------------------------<-[New Order]->------------------------!\n");
        //Initializing the counters
        size_t orderIndex =0;
        //Get Order ID
        printf("Order ID :");
        char thisOrderId[20];
        scanf("%s", thisOrderId);

        do {
            printf("Maximum Order Count %d \n", maxOrderCount);
            printf("Now Order Count %d \n", orderIndex);
            //Handle order count
            if (orderIndex>=maxOrderCount){
                printf("Maximum Order Count reached %d", orderIndex);
                break;
            }
            //Add Items to the Order
            printf("!-------------------------<-[Add Item]->-------------------------!\n");
            //Type of order
            int orderTypeIn;
            struct ItemMetaData orderTypeMetaData;
            printf("Order Type - Pizza [1]Pasta [9] :");
            scanf("%d", &orderTypeIn);
            if (orderTypeIn == 1){
                printPizzaLogo();
                orderTypeMetaData = pizza;
            }
            else if (orderTypeIn == 9){
                printPastaLogo();
                orderTypeMetaData = pasta;
            }
            else{
                perror("Invalid Order Type");
                continue;
            }

            //Order Quantity
            int orderQty;
            printf("Order Quantity :");
            scanf("%d", &orderQty);

            //Process Order
            orderArray[orderIndex] = makeOrder(orderTypeMetaData, thisOrderId, orderQty);
            orderIndex++;
            //Print Counters
            printf("Order Count : %d ", orderIndex);
            printf("Add another Item to this order - %s [Y/N]? : " , &thisOrderId);
            scanf("%s", &keepOrderAlive);

        } while (tolower(keepOrderAlive) == 'y' );

        //Calculate Quantities
        size_t i;
        int pastaQty=0;
        int pizzaQty=0;
        float pizzaAmount=0.0;
        float pastaAmount=0.0;
        for (i = 0; i < orderIndex; i++) {

                if (!strcmp(orderArray[i].orderType,"pasta")){
                    pastaQty+=orderArray[i].qty;
                    pastaAmount+=orderArray[i].amount;
                }
                if (!strcmp(orderArray[i].orderType,"pizza")){
                    pizzaQty+=orderArray[i].qty;
                    pizzaAmount+=orderArray[i].amount;
                }
        }
        //free(orderArray);
        printReciept(&thisOrderId,pizzaQty,pizzaAmount,pastaQty,pastaAmount,40);
        printf("Keep the System UP [Y/N]: ");
        scanf("%s", &keepSystemAlive);
    } while (tolower(keepSystemAlive) == 'y');
    return 0;
}



void printReciept(char orderId, int pizzaQty, float pizzaValue, int pastaQty, float pastaValue, int terminalWidth){
    printf("\n \n \n!-------------------------<-[PlatypuS]->-------------------------!\n");

    printPizzaLogo();
    printf("!---------------------------<-[Pizza]->--------------------------!\n");
    printf("\n Quantity of Pizza Order :%d", pizzaQty);
    printf("\n Value of Pizza Order :%f", pizzaValue);
    printf("\n Eligible generic Offers :%s", pizza.offerType);
    printf("\n This order deserve :%d \n", (int)(pizzaQty/pizza.offerReq));


    printPastaLogo();
    printf("!--------------------------<-[Pasta]->---------------------------!\n");
    printf("\nQuantity of Pasta Order :%d", pastaQty);
    printf("\nValue of Pasta Order :%f", pastaValue);
    printf("\nEligible generic Offers :%s", pasta.offerType);
    printf("\nThis order deserve :%d \n", (int)(pastaQty/pasta.offerReq));
    printf("!-------------------------<-[PlatypuS]->-------------------------!\n");

    printf("\n!------------------------<-[Total Cost]->------------------------!");
    printf("\nTotal Cost of this Order: %f \n", pastaValue + pizzaValue );
    printf("\n!----------------------<-[%s]->----------------------!", misc_1.type);
    printf("\nEligible Special Offers :%s", misc_1.offerType );
    printf("\nThis order deserve :%d ", minFunction(pizzaQty,pastaQty)/3);
    printf("\n!-------------------------<-[PlatypuS]->-------------------------!\n");
}
