/*Find this REPO on GIT : https://github.com/krishanthisera/platypus.git */
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "headers.h"
#include <stdio.h>
#include <stdbool.h>

//Main Function
int main(int argc, size_t *argv[])
{
    printLogo();

/*-------------------------------------Command Line Arguments-------------------------------------*/
    if( argc >= 2 ) {
        //Control Max Order Counter
        if (MAX < argv[1] ){
            maxOrderCount=atoi(argv[1]);
            printf("<-[Platypus]-> - Maximum order count not specified!!\n");
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

/*-------------------------------------System Initialization -------------------------------------*/
    //Initialize Item Meta Data
    initItems();

    //flags
    char keepOrderAlive="n";
    char keepSystemAlive="n";


/*-------------------------------------Main Loop [System Life-cycle]-------------------------------------*/
    do{
        //Print Log
        printf("!-------------------------<-[New Order]->------------------------!\n");
        //Initializing the counters
        size_t orderIndex =0;
        //Get Order ID
        printf("Order ID :");
        char thisOrderId[20];
        scanf("%s", thisOrderId);

/*-------------------------------------Secondary Loop [Order Life-cycle]-------------------------------------*/
        do {
            printf("<-[Platypus]->Maximum Order Count %d \n", maxOrderCount);
            printf("<-[Platypus]->Current Order Count %d \n", orderIndex);
            //Handle order count
            if (orderIndex>=maxOrderCount){
                printf("\n*************************************************");
                printf("\n<-[Platypus]->Maximum Order Count reached %d!!!!!", orderIndex);
                printf("\n*************************************************\n");
                break;
            }
            //Add Items to the Order
            printf("!-------------------------<-[Add Item]->-------------------------!\n");
            //Type of order
            int orderTypeIn;
            struct ItemMetaData orderTypeMetaData;


            do {
            printf("Order Type - Pizza [1]Pasta [9] : ");
            if(!scanf("%*c%d", &orderTypeIn)){
                printf("\n<-[Platypus]->Order Type cannot be a non numerical character!!\n");
                continue;
            }
            if (orderTypeIn == 1){
                //printPizzaLogo();
                orderTypeMetaData = pizza;
                break;
            }
            else if (orderTypeIn == 9){
                //printPastaLogo();
                orderTypeMetaData = pasta;
                break;
            }
            else{


                printf("\n<-[Platypus]->Invalid Order Type!! \n");
                orderTypeIn=0;
                orderTypeMetaData=misc_NULL;
                continue;
            }

            } while (true);



            //Order Quantity
            int orderQty;

            do {
            printf("Order Quantity :");
            if (!scanf("%*c%d", &orderQty)){
                printf("\n<-[Platypus]->Invalid Order Quantity!! \n");
                continue;
            }
            else
                break;
            } while(true);

            //Process Order
            orderArray[orderIndex] = makeOrder(orderTypeMetaData, thisOrderId, orderQty);
            orderIndex++;
            //Print Counters
            printf("Order Count : %d ", orderIndex);
            do{
            printf("Add another Item to this order - %s [Y/N]? : " , &thisOrderId);
            scanf("%*c%s", &keepOrderAlive);
            if (tolower(keepOrderAlive) == 'y' || tolower(keepOrderAlive) == 'n')
                break;
            } while(true);


        } while (tolower(keepOrderAlive) == 'y' );

            //Calculation
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
            do{
            printf("Keep the System UP [Y/N]: ");
            scanf("%*c%s", &keepSystemAlive);
            if (tolower(keepSystemAlive) == 'y' || tolower(keepSystemAlive) == 'n')
                break;
            } while(true);
    } while (tolower(keepSystemAlive) == 'y');
    exit(EXIT_SUCCESS);
    return 0;
}




