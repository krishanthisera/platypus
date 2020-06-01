from Order import Order
class Pizza(Order):
   
    def __init__(self,qty,menu):
        
        self.__qty=qty
        __order="pizza"
        self.__unitPrice=float(menu['main']['price'][__order])
        self.__eligibleOffers=menu['offers']['for-3-offer'][__order]['item']
        self.__minQtyForOffer=menu['offers']['for-3-offer'][__order]['minQty']
        
        if (self.__qty > 0and self.__qty < 3):
            self.__discount=float(menu['main']['for-'+ str(qty) +'-discount'][__order])
        elif (self.__qty >= 3):
            self.__discount=float(menu['main']['for-N-discount'][__order])  
        else:
            self.__discount=0
        
    def calcAmount(self):
        return self.__qty*self.__unitPrice*self.__discount
 
    def getOffers(self):
#        return str(self.__eligibleOffers) + ":" + str(self.__qty//self.__minQtyForOffer)
        return self.__qty//self.__minQtyForOffer
    
    
        
    