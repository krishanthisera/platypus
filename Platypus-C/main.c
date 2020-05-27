#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

//float calcAmount(struct ItemMetaData item, int qty);
float printReciept(char orderId, int pizzaQty, float pizzaValue, int pastaQty, float pastaValue, int terminalWidth);
struct Order{
    char orderID;
    char orderType;
    char offerType;
    int offerQty;
    int qty;
    float amount;

};

struct ItemMetaData{
    char type;
    char offerType;
    float discForOne;
    float discForTwo;
    float discForMulti;
    float unitPrice;
    int offerReq;
};

    struct ItemMetaData pizza;
    struct ItemMetaData pasta;

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
}

struct Order *orderArray;


struct Order makeOrder(struct ItemMetaData item, char orderId, int qty){
    struct Order thisOrder;
    thisOrder.amount+=calcAmount(item,qty);
    thisOrder.offerQty=(int)qty/3;
    thisOrder.offerType=item.offerType;
    thisOrder.qty=qty;
    thisOrder.orderType=item.type;
    printf("Make Order qty %d", thisOrder.qty);
    return thisOrder;
}

int maxOrderCount=2;

int main(int argc, int *argv[])
{
    //Command Line Arguments
    if( argc >= 2 ) {

        //maxOrders=atoi(argv[1]);
        maxOrderCount=atoi(argv[1]);
        printf("Initiating the System with maximum order count ->> %d\n", maxOrderCount);

   }
   else {
      printf("One argument expected.\n");
      perror("At least one argument expected!!!");
      exit(2);
   }

    //Initialize Item Meta Data
    initItems();
    //Memory allocation for orders


    //flags
    char keepOrderAlive="n";
    char keepSystemAlive="n";





    do{
        int orderCounter=0;
        size_t orderIndex =0;
        //Get Order ID
        printf("Order ID :");
        char orderId;
        scanf("%s", &orderId);

        do {
            printf("Maximum Order Count %d \n", maxOrderCount);
            printf("Now Order Count %d \n", orderCounter);
            //Handle order count

            if (orderCounter>=maxOrderCount){
                printf("Maximum Order Count reached %d", orderCounter);
                break;
            }
            //Type of order
            int orderTypeIn;
            struct ItemMetaData orderType;
            printf("Order Type - Pizza [1]Pasta [9] :");
            scanf("%d", &orderTypeIn);
            if (orderTypeIn = 1)
                orderType = pizza;
            else if (orderTypeIn = 9)
                orderType = pasta;
            else{
                perror("Invalid Order Type");
                continue;
            }
            //Order Quantity
            int orderQty;
            printf("Order Quantity :");
            scanf("%d", &orderQty);
            printf("Order Quantity ----> %d", orderQty);
            //Process Order
            orderArray = malloc(maxOrderCount*sizeof(struct Order));

            orderArray[orderIndex] = makeOrder(orderType, orderId, orderQty);
            printf("\n \n Order processing qty %d \n \n",orderArray[orderIndex].qty);

            //orderIndex=orderIndex+1;
            orderIndex++;
            orderCounter++;
            printf("Order Count %d \n", orderCounter);
            //Set Flags
            printf("Add another Item to this order - %s ?:" , &orderId);
            scanf("%s", &keepOrderAlive);


        } while (tolower(keepOrderAlive) == 'y' );

        //Calculate Quantities
        size_t i;
        int pastaQty=0;
        int pizzaQty=0;
        float pizzaAmount=0.0;
        float pastaAmount=0.0;
        printf("HERE %s", orderArray[0].orderType);
        for (i = 0; i < orderIndex; i++) {
                printf("HERE %s", orderArray[0].orderType);
                if (strcmp(orderArray[i].orderType,"pasta")){
                    //pastaQty+=orderArray[i].qty;
                    //pastaAmount+=orderArray[i].amount;
                }
               // if (strcmp(orderArray[i].orderType,"pizza")){
                    //pizzaQty+=orderArray[i].qty;
                    //pizzaAmount+=orderArray[i].amount;
                //}

        }
        free(orderArray);
        printReciept(orderId,pizzaQty,pizzaAmount,pastaQty,pastaAmount,40);
        printf("Keep the System UP : ");
        scanf("%s", &keepSystemAlive);

    } while (tolower(keepSystemAlive) == 'y');
    return 0;
}



float printReciept(char orderId, int pizzaQty, float pizzaValue, int pastaQty, float pastaValue, int terminalWidth){
    char charactor;
    //memset(charactor,'#',terminalWidth);
    //puts(charactor);
    //printf("\Order ID : %s", orderId);
    //memset(charactor,'-',terminalWidth);
    printf(charactor);
    printf("\n Quantity of Pasta Order :%d", pastaQty);
    printf("\n Value of Pasta Order :%f", pastaValue);
    printf("\n Eligible generic Offers :%f", pasta.offerType);
    printf("\n This order deserve :%d ", (int)(pastaQty/pasta.offerReq));
    //memset(charactor,'-',terminalWidth);
    //printf(charactor);
    printf("\n Quantity of Pizza Order :%d", pizzaQty);
    printf("\n Value of Pizza Order :%f", pizzaValue);
    printf("\n Eligible generic Offers :%f", pizza.offerType);
    printf("\n This order deserve :%d ", (int)(pizzaQty/pizza.offerReq));
    //memset(charactor,'-',terminalWidth);
    //printf(charactor);
    //printf("/n");
    //memset(charactor,'-',terminalWidth);
    //printf(charactor);

}
