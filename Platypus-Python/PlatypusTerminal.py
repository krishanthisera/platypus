from Handler import Session
import sys
import calendar
import time
from colorama import Fore, Back, Style
class PlatypusTerminal:
    

    ses = Session("aa")
    ses.getMenuJson()

    
    
    orderType=0
    qty=0
    sessionId=calendar.timegm(time.gmtime())
    def curOrderStatus(args):
        print("Order Name: " + Style.RESET_ALL + Back.GREEN + Fore.WHITE + args['session']['ID'] + Style.RESET_ALL)
        print("Quantity of Pasta: " + Style.RESET_ALL + Back.GREEN + Fore.WHITE + str(args['session']['qty']['pasta']) + Style.RESET_ALL)
        print("Total cost of Pasta Order: " + Style.RESET_ALL + Back.GREEN + Fore.WHITE + str(args['session']['cost']['pasta']) + Style.RESET_ALL)
        print("Quantity of Pizza: " + Style.RESET_ALL + Back.GREEN + Fore.WHITE + str(args['session']['qty']['pizza']) + Style.RESET_ALL)
        print("Total cost of Pizza Order: " + Style.RESET_ALL + Back.GREEN + Fore.WHITE + str(args['session']['cost']['pizza']) + Style.RESET_ALL)
        print("Total Cost of Order: " + Style.RESET_ALL + Back.GREEN + Fore.WHITE + str(args['session']['cost']['pasta'] + args['session']['cost']['pizza']) + Style.RESET_ALL)
        print("General Offers : " + Style.RESET_ALL + Back.GREEN + Fore.WHITE + args['session']['offers']['pizza']['item'] + " : " + str(args['session']['offers']['pizza']['qty']) + Style.RESET_ALL)
        print("General Offers : " + Style.RESET_ALL + Back.GREEN + Fore.WHITE + args['session']['offers']['pasta']['item'] + Style.RESET_ALL +" : " +  Style.RESET_ALL + Back.GREEN + Fore.WHITE + str(args['session']['offers']['pasta']['qty']) + Style.RESET_ALL)
        print("Special Offers : " + Style.RESET_ALL + Back.GREEN + Fore.WHITE + args['session']['offers']['specialOffers']['item'] + Style.RESET_ALL +" : " +  Style.RESET_ALL + Back.GREEN + Fore.WHITE + str(args['session']['offers']['specialOffers']['qty']) + Style.RESET_ALL)
        
    
    while True:
        newSession=True
        sessionId=input(Fore.BLUE + Back.GREEN + "Please Provide the order a name: ")
        if (sessionId.lower() == '-999'):
                print("Exit on user request")
                sys.exit(0)
        elif (sessionId.lower() == '-777'):
               continue
        else:
             session = Session(sessionId)
        newSession=False
        while True:
            if (newSession):
                break
            print(Style.RESET_ALL + Fore.GREEN +  "\n" + "#"*30)
            print("For Pizza order enter \"1\"")
            print("Pasta order enter \"9\"") 
            print("To go to upper menu press X any time")
            print("Type \"-777\" to kill the app")
            print("#"*30)
            orderType=input(Style.RESET_ALL + Back.GREEN + Fore.BLUE  +"Order type: ")
            if (orderType == "1"):
                orderType='pasta'
            elif (orderType == "9"):
                orderType='pizza'
            elif (orderType.lower() == '-777'):
                break
            elif (orderType.lower() == '-999'):
                print(Style.RESET_ALL + Fore.RED  +"Exit on user request")
                sys.exit(0)
            else:
                print(Style.RESET_ALL + Fore.RED  +"Cannot fine order type " + orderType.capitalize())
                continue
            newSession=False
            statusFlag=True
            while True:
                if ( not statusFlag):
                    break
                print(Style.RESET_ALL  +"It is a " + orderType.capitalize() + " order")
                qty=input(Style.RESET_ALL + Back.GREEN + Fore.BLUE  +"It is a " + orderType.capitalize() + " order\n" + "How many " + orderType.capitalize() +"'s (Quantity):")
                try:
                    qty=int(qty)
                except :
                    print (Style.RESET_ALL + Fore.RED  +"Quantity Must be an Integer")
                    continue
                if (isinstance(qty, int) and qty != -999 and qty != -777):
                    print(Style.RESET_ALL +"#!"*30)
                    session.makeOrder(orderType.lower(),qty)
                    print(Style.RESET_ALL +"#!"*30)
                    curOrderStatus(session.readSession())
                    print(Style.RESET_ALL + Fore.GREEN +  "\n" + "#"*30)
                    print(Style.RESET_ALL + Fore.GREEN +"To Finalise the order Enter \"-444\"")
                    status=input(Style.RESET_ALL + Fore.GREEN +"To Finalise the order Enter \"-444\"\n" + "To add another item to order Enter \"-111\" :")
                    print(Style.RESET_ALL + Fore.GREEN +  "\n" + "#"*30 + Style.RESET_ALL)
                    if (status.lower() == '-444'):
                        print(Style.RESET_ALL +"#!"*10 + " ORDER " + sessionId.capitalize() + " " + "#!"*10 +  Style.RESET_ALL)
                        curOrderStatus(session.readSession())
                        print(Style.RESET_ALL +"#!"*10 + " THANK YOU " + sessionId.capitalize() +" " + "#!"*8 +  Style.RESET_ALL)
                        newSession=True
                        break
                    elif (status.lower() == '-111'):
                        break
                    elif (status.lower() == -999):
                        print(Style.RESET_ALL + Fore.RED  +"Exit on user request")
                        sys.exit(0)
                    else:
                        statusFlag=False
                        break
                    
                elif (qty == -777):
                    break
                elif (qty == -999):
                    print(Style.RESET_ALL + Fore.RED  +"Exit on user request")
                    sys.exit(0)
                else:
                    break
                    
        
    
        
                    
                    