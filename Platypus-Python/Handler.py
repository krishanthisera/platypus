from Order import Order
from Pizza import Pizza
from Pasta import Pasta
import sys
import json

class Session:
                            
    __sessionToken={}
    __menuToken={}
    
    def __init__(self, sessionId):
        self.__menuToken=self.__initMenu()
        self.__sessionToken=self.__initSession(sessionId)
        
                     
    def setMenu(self,**args):
       #Set or add new item to the menu (to be implement)
       pass
  
    def getMenu(self):
       return self.__menuToken
   
    def makeOrder(self,orderType,qty):
        if self.__sessionToken is None or orderType is None or  qty is None or not isinstance(qty, int):
            print("Error Making the order", file=sys.stderr)
            sys.exit(-1)
                        
        else:
            if (orderType.lower() == 'pasta'):
                __objOrder = Pasta(qty,self.__menuToken)
            elif (orderType.lower() == 'pizza'):
                 __objOrder = Pasta(qty,self.__menuToken)
            else:
                print("Error Making the order", file=sys.stderr)
                sys.exit(-19)
                 
        self.__sessionToken['session']['qty'][orderType.lower()]+=qty
        self.__sessionToken['session']['cost'][orderType.lower()]+=__objOrder.calcAmount()
        self.__sessionToken['session']['offers'][orderType.lower()]['qty']+=__objOrder.getOffers()
        self.__specialOffers()
       
            
    #To chnage any menu item use set menu or __menu dictionary
    def __initSession(self,sessionId):
        __sessionDescription= {'session':{
        'ID':sessionId,
        'qty':{'pasta':0,'pizza':0},
        'cost':{'pasta':0,'pizza':0},
        'offers':{
            'pizza':{
                'item':self.__menuToken['offers']['for-3-offer']['pizza']['item'],
                'qty':0},
            'pasta':{
                'item':self.__menuToken['offers']['for-3-offer']['pasta']['item'],
                'qty':0},
            'specialOffers':{
                'item':self.__menuToken['offers']['3-from-2-offer']['offer'],
                'qty':''}}}}  
        return __sessionDescription
    
    def __initMenu(self):
        __menu = {'main': 
                {'price': 
                    {'pizza':12, 
                     'pasta':8}, 
                'for-1-discount': 
                    {'pizza':1, 
                     'pasta':1}, 
                'for-2-discount': 
                    {'pizza':0.91666667, 
                     'pasta':0.9375}, 
                'for-N-discount': 
                    {'pizza':0.83333333, 
                     'pasta':0.875}}, 
            'offers':
                {'3-from-2-offer':
                    {'offer': 'Baklava' },
                'for-3-offer':
                    {'pizza': {'minQty' : 3,'item':'Garlic Bread'}, 
                     'pasta': {'minQty' : 3, 'item':'Soft Drink'}} }}
        return __menu
    
    def __specialOffers(self):
        curPizzaQty=self.__sessionToken['session']['qty']['pizza']
        curPastaQty=self.__sessionToken['session']['qty']['pasta']
        self.__sessionToken['session']['offers']['specialOffers']['qty']=min(curPizzaQty,curPastaQty)//3
    
    def readSession(self):
        return self.__sessionToken
    
    def getSessionJson(self):
        __jObj = json.dumps(self.__sessionToken)
        print(__jObj)    
        
    def getMenuJson(self):
        __jObj = json.dumps(self.__menuToken)
        print(__jObj)
    
        
    
    
   
        
