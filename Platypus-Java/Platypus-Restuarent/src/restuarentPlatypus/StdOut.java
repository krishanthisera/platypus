package restuarentPlatypus;

import java.util.HashMap;

public class StdOut {
	
	private int terminalWidth;
	
	public StdOut(int terminalWidth) {
		this.terminalWidth = terminalWidth;
	}
	
	public void orderSumary(HashMap<String, Object> session) {
			
			HashMap<String, Object> sessionDescription = (HashMap<String, Object>) session.get("session");
			easyPrint(terminalWidth, "#");
			easyPrint("Session ID", sessionDescription.get("ID"));
			easyPrint(terminalWidth, "#");
			easyPrint(terminalWidth, ">");
			easyPrint("Quantity of Pasta", ((HashMap<String, Object>) sessionDescription.get("qty")).get("pasta"));
			easyPrint("Cost of Pasta(s)", ((HashMap<String, Object>) sessionDescription.get("cost")).get("pasta"));
			easyPrint("General offers offers for this Pasta order", ((HashMap<String, Object>) ((HashMap<String, Object>) sessionDescription.get("offers")).get("pasta")).get("item"));
			easyPrint("This Pasta order deserve", ((HashMap<String, Object>) ((HashMap<String, Object>) sessionDescription.get("offers")).get("pasta")).get("qty"));
			easyPrint(terminalWidth, "<");
			easyPrint(terminalWidth, ">");
			easyPrint("Quantity of Pizza", ((HashMap<String, Object>) sessionDescription.get("qty")).get("pizza"));
			easyPrint("Cost of Pizza(s)", ((HashMap<String, Object>) sessionDescription.get("cost")).get("pizza"));
			easyPrint("General offers offers for this Pizza order", ((HashMap<String, Object>) ((HashMap<String, Object>) sessionDescription.get("offers")).get("pizza")).get("item"));
			easyPrint("This Pizza order deserve", ((HashMap<String, Object>) ((HashMap<String, Object>) sessionDescription.get("offers")).get("pizza")).get("qty"));
			easyPrint(terminalWidth, "<");
			easyPrint(terminalWidth, ">");
			easyPrint("Eligible Special Offers", ((HashMap<String,Object>) ((HashMap<String, Object>) sessionDescription.get("offers")).get("specialOffers")).get("item"));
			easyPrint("This Order Deserve", ((HashMap<String,Object>) ((HashMap<String, Object>) sessionDescription.get("offers")).get("specialOffers")).get("qty"));
		}
		
		public void easyPrint(String desc , Object val) {
			System.out.println(desc + ": " + val.toString());
		}
		public void easyPrint(int itr, String charactor) {
			StringBuilder charSet = new StringBuilder();
		    for(int i = 0; i < itr; i++){
		        charSet.append(charactor);
		    }
			System.out.println(charSet.toString());
		}
		public void easyPrint(String greeting) {
			if (greeting.toLowerCase().equalsIgnoreCase("bye")) {
				System.out.print("\r\n" + 
						"                                                                                                                                              \r\n" + 
						"                                                                   dddddddd                                                                   \r\n" + 
						"        GGGGGGGGGGGGG                                              d::::::d     BBBBBBBBBBBBBBBBB                                             \r\n" + 
						"     GGG::::::::::::G                                              d::::::d     B::::::::::::::::B                                            \r\n" + 
						"   GG:::::::::::::::G                                              d::::::d     B::::::BBBBBB:::::B                                           \r\n" + 
						"  G:::::GGGGGGGG::::G                                              d:::::d      BB:::::B     B:::::B                                          \r\n" + 
						" G:::::G       GGGGGG   ooooooooooo      ooooooooooo       ddddddddd:::::d        B::::B     B:::::Byyyyyyy           yyyyyyy eeeeeeeeeeee    \r\n" + 
						"G:::::G               oo:::::::::::oo  oo:::::::::::oo   dd::::::::::::::d        B::::B     B:::::B y:::::y         y:::::yee::::::::::::ee  \r\n" + 
						"G:::::G              o:::::::::::::::oo:::::::::::::::o d::::::::::::::::d        B::::BBBBBB:::::B   y:::::y       y:::::ye::::::eeeee:::::ee\r\n" + 
						"G:::::G    GGGGGGGGGGo:::::ooooo:::::oo:::::ooooo:::::od:::::::ddddd:::::d        B:::::::::::::BB     y:::::y     y:::::ye::::::e     e:::::e\r\n" + 
						"G:::::G    G::::::::Go::::o     o::::oo::::o     o::::od::::::d    d:::::d        B::::BBBBBB:::::B     y:::::y   y:::::y e:::::::eeeee::::::e\r\n" + 
						"G:::::G    GGGGG::::Go::::o     o::::oo::::o     o::::od:::::d     d:::::d        B::::B     B:::::B     y:::::y y:::::y  e:::::::::::::::::e \r\n" + 
						"G:::::G        G::::Go::::o     o::::oo::::o     o::::od:::::d     d:::::d        B::::B     B:::::B      y:::::y:::::y   e::::::eeeeeeeeeee  \r\n" + 
						" G:::::G       G::::Go::::o     o::::oo::::o     o::::od:::::d     d:::::d        B::::B     B:::::B       y:::::::::y    e:::::::e           \r\n" + 
						"  G:::::GGGGGGGG::::Go:::::ooooo:::::oo:::::ooooo:::::od::::::ddddd::::::dd     BB:::::BBBBBB::::::B        y:::::::y     e::::::::e          \r\n" + 
						"   GG:::::::::::::::Go:::::::::::::::oo:::::::::::::::o d:::::::::::::::::d     B:::::::::::::::::B          y:::::y       e::::::::eeeeeeee  \r\n" + 
						"     GGG::::::GGG:::G oo:::::::::::oo  oo:::::::::::oo   d:::::::::ddd::::d     B::::::::::::::::B          y:::::y         ee:::::::::::::e  \r\n" + 
						"        GGGGGG   GGGG   ooooooooooo      ooooooooooo      ddddddddd   ddddd     BBBBBBBBBBBBBBBBB          y:::::y            eeeeeeeeeeeeee  \r\n" + 
						"                                                                                                          y:::::y                             \r\n" + 
						"                                                                                                         y:::::y                              \r\n" + 
						"                                                                                                        y:::::y                               \r\n" + 
						"                                                                                                       y:::::y                                \r\n" + 
						"                                                                                                      yyyyyyy                                 \r\n" + 
						"                                                                                                                                              \r\n" + 
						"                                                                                                                                              \r\n" + 
						""
						
						);
				
			}
			if (greeting.toLowerCase().equalsIgnoreCase("welcome")) {
				System.out.print("\r\n" + 
						"                                                                                                                                 \r\n" + 
						"8 888888888o   8 8888                  .8.    8888888 8888888888 `8.`8888.      ,8' 8 888888888o   8 8888      88    d888888o.   \r\n" + 
						"8 8888    `88. 8 8888                 .888.         8 8888        `8.`8888.    ,8'  8 8888    `88. 8 8888      88  .`8888:' `88. \r\n" + 
						"8 8888     `88 8 8888                :88888.        8 8888         `8.`8888.  ,8'   8 8888     `88 8 8888      88  8.`8888.   Y8 \r\n" + 
						"8 8888     ,88 8 8888               . `88888.       8 8888          `8.`8888.,8'    8 8888     ,88 8 8888      88  `8.`8888.     \r\n" + 
						"8 8888.   ,88' 8 8888              .8. `88888.      8 8888           `8.`88888'     8 8888.   ,88' 8 8888      88   `8.`8888.    \r\n" + 
						"8 888888888P'  8 8888             .8`8. `88888.     8 8888            `8. 8888      8 888888888P'  8 8888      88    `8.`8888.   \r\n" + 
						"8 8888         8 8888            .8' `8. `88888.    8 8888             `8 8888      8 8888         8 8888      88     `8.`8888.  \r\n" + 
						"8 8888         8 8888           .8'   `8. `88888.   8 8888              8 8888      8 8888         ` 8888     ,8P 8b   `8.`8888. \r\n" + 
						"8 8888         8 8888          .888888888. `88888.  8 8888              8 8888      8 8888           8888   ,d8P  `8b.  ;8.`8888 \r\n" + 
						"8 8888         8 888888888888 .8'       `8. `88888. 8 8888              8 8888      8 8888            `Y88888P'    `Y8888P ,88P' \r\n" + 
						"\n");
		}
			
}
}