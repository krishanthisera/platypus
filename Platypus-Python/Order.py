from abc import ABC, abstractmethod
class Order:
   
        
    @abstractmethod
    def calcAmount(self):
        pass
    
        
    @abstractmethod
    def getOffers(self):
        pass
    