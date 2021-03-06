//Find this REPO @ https://github.com/krishanthisera/platypus.git
//git clone https://github.com/krishanthisera/platypus.git
package restuarentPlatypus;

import java.util.HashMap;
import java.util.Scanner;

public class PlatypusTerminal {
	public static void main(String[] args) {
		String orderType = "None";
		String orderTypeIn = "0";
		StdIn input = new StdIn(50);
		StdOut out = new StdOut(50);
		
		
		out.easyPrint("welcome");
		do {
			Session session = new Session(input.getInput("Give this Order an ID").toString());
			do {
				
				try {
				orderTypeIn = input.getInput("Order Type Pizza [1] for Pasta [9]").toString();
				}
				catch (Exception e) {	
					out.easyPrint("Invalid Order Type :", e);
					continue;
				}
				if (orderTypeIn.equalsIgnoreCase("pizza") || orderTypeIn.contentEquals("1")) {
					orderType = "pizza";
				}
				
				else if (orderTypeIn.equalsIgnoreCase("pasta") || orderTypeIn.contentEquals("9")) {
					orderType = "pasta";
				}
				else {
					out.easyPrint("Error Making the order [Order Type]", orderType);
					continue;
				}
				try {
				int orderQtyIn=Integer.parseInt((input.getInput("How many of them (Quantity)").toString()));
				session.makeOrder(orderType,orderQtyIn);
				}
				catch (Exception e) {
					out.easyPrint("Error Making the order", e);
					continue;
				}
			}
			while(input.getInput("Do you want to Add another Item [Yy][Nn]").toString().equalsIgnoreCase("Y"));
			out.orderSumary(session.readSession());
			}
			while(input.getInput("Do you want to Continue[Yy][Nn]").toString().equalsIgnoreCase("Y"));
		out.easyPrint("bye");
		
			
	}
	
}


