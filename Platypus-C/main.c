#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "headers.h"

//Main Function
int main(int argc, size_t *argv[])
{
    printLogo();

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




