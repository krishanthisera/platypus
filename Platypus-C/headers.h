/*Find this REPO on GIT : https://github.com/krishanthisera/platypus.git */
//Maximum number of orders that system can handle.
#define MAX 10



int maxOrderCount;
/*------------------------------------- Structures-------------------------------------*/
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

    //Miscellaneous Item, Used in Special offers in this context
    struct ItemMetaData misc_1;
    //Miscellaneous Item, used in Item not defined contexts
    struct ItemMetaData misc_NULL;

    struct Order orderArray[MAX];

/*------------------------------------- Functions-------------------------------------*/
void initItems();
float calcAmount(struct ItemMetaData item, int qty);
struct Order makeOrder(struct ItemMetaData item, char orderId, int qty);
int minFuntion(int val1, int val2);
void printReciept(char orderId, int pizzaQty, float pizzaValue, int pastaQty, float pastaValue, int terminalWidth);
void printLogo();
void printPizzaLogo();
void printPastaLogo();

