package restuarentPlatypus;

import java.util.HashMap;
import java.util.Map;


public class Session {
	private HashMap<String, Object> menuToken = new  HashMap<String, Object>();
	private HashMap<String, Object> sessionToken = new  HashMap<String, Object>();
	private String sessionId;
	
	public Session(String sessionId) {
		//this.sessionId=sessionId;
		this.menuToken=initMenu();
		this.sessionToken=initSession(sessionId);
	}
	
	@SuppressWarnings("unchecked")
	public void makeOrder(String orderType, int qty) {
		
		if (this.sessionToken == null || orderType == null ) {
			System.exit(-1);
		}
		else {
			Orders objOrder = null;
			if (orderType.toLowerCase() == "pasta") {
				objOrder = new Pasta(qty, menuToken);
			}
			else if (orderType.toLowerCase() == "pizza") {
				objOrder = new Pizza(qty, menuToken);
			}
			else {
				System.exit(-19);
			}
					//Update the quanity
					
			
					int curQty = (Integer) ((HashMap<String, Object>) ((HashMap<String, Object>) sessionToken.get("session")).get("qty")).get(orderType.toLowerCase());
					((HashMap<String, Object>) ((HashMap<String, Object>) sessionToken.get("session")).get("qty")).put(orderType.toLowerCase(),curQty + qty);
					
					//Update the cost
					float curCost = (float) ((HashMap<String, Object>) ((HashMap<String, Object>) sessionToken.get("session")).get("cost")).get(orderType.toLowerCase());
					((HashMap<String, Object>) ((HashMap<String, Object>) sessionToken.get("session")).get("cost")).put(orderType.toLowerCase(),curCost + objOrder.getAmount());
					
					//Update offers
					//int curOffers = ((Integer) ((HashMap<String,Object>) ((HashMap<String,Object>) ((HashMap<String, Object>) sessionToken.get("session")).get("offers")).get(orderType.toLowerCase())).get("qty"));
					//((HashMap<String, Object>) ((HashMap<String, Object>) ((HashMap<String, Object>) sessionToken.get("session")).get("offers")).get(orderType.toLowerCase())).put("qty", (int)curOffers + (int)objOrder.getOffers());
					
					genericOffers(orderType);
					specialOffers();
				}
			}
				
		
	
	//To change any menu item use set menu or menu HashMap
	@SuppressWarnings("unchecked")
	private HashMap<String, Object> initSession(String sessionId) {
		//Jason: https://jsoneditoronline.org/#left=cloud.71ea5180664e4f3fa9a5687ce5f167b1
		//For better implementation gson is recommended
		
		HashMap<String, Object>  sessionDescription = new HashMap<String, Object>();
		HashMap<String, Object>  _session = new HashMap<String, Object>();
		HashMap<String, Object>  __qty = new HashMap<String, Object>();
		HashMap<String, Float>  __cost = new HashMap<String, Float>();
		HashMap<String, Object>  __offers = new HashMap<String, Object>();
		HashMap<String, Object>  ___offersPizza = new HashMap<String, Object>();
		HashMap<String, Object>  ___offersPasta = new HashMap<String, Object>();
		HashMap<String, Object>  ___offersSpecial = new HashMap<String, Object>();
		
		sessionDescription.put("session", _session);
		_session.put("ID", sessionId);
		_session.put("qty", __qty);
		_session.put("cost", __cost);
		_session.put("offers", __offers);
		__qty.put("pasta", 0);
		__qty.put("pizza", 0);
		__cost.put("pasta", (float) 0);
		__cost.put("pizza", (float) 0);
		__offers.put("pasta",___offersPasta);
		__offers.put("pizza",___offersPizza);
		__offers.put("specialOffers",___offersSpecial);
		___offersPasta.put("item",(String)((HashMap<String,Object>) ((HashMap<String, Object>) ((HashMap<String, Object>) menuToken.get("offers")).get("for-3-offer")).get("pasta")).get("item"));
		___offersPasta.put("qty",0);
		___offersPizza.put("item", (String)((HashMap<String,Object>) ((HashMap<String, Object>) ((HashMap<String, Object>) menuToken.get("offers")).get("for-3-offer")).get("pizza")).get("item"));
		___offersPizza.put("qty", 0);
		___offersSpecial.put("item", (String)(((HashMap<String, Object>) ((HashMap<String, Object>) menuToken.get("offers")).get("3-from-2-offer")).get("offer")));
		___offersSpecial.put("qty",0);
		
		
		return sessionDescription;	
	}
	
	private HashMap<String, Object> initMenu() {
		//Json https://jsoneditoronline.org/#left=cloud.f3260bfdd86947a68fd7252a315c4f6d
		HashMap<String, Object>  menu = new HashMap<String, Object>();
		HashMap<String, Object>  _main = new HashMap<String, Object>();
		HashMap<String, Object>  _offers = new HashMap<String, Object>();
		HashMap<String, Float>  __price = new HashMap<String, Float>();
		HashMap<String, Float>  __for_1_discount = new HashMap<String, Float>();
		HashMap<String, Float>  __for_2_discount = new HashMap<String, Float>();
		HashMap<String, Float>  __for_N_discount = new HashMap<String, Float>();
		HashMap<String, Object>  __for_3_offer = new HashMap<String, Object>();
		HashMap<String, Object>  __3_from_2_offer = new HashMap<String, Object>();
		HashMap<String, Object>  ___pizza_for_3_offer = new HashMap<String, Object>();
		HashMap<String, Object>  ___pasta_for_3_offer = new HashMap<String, Object>();
		
		menu.put("main",_main);
		menu.put("offers",_offers);
		_main.put("price",__price);
		_main.put("for-1-discount",__for_1_discount);
		_main.put("for-2-discount",__for_2_discount);
		_main.put("for-N-discount",__for_N_discount);
		_offers.put("for-3-offer", __for_3_offer);
		_offers.put("3-from-2-offer", __3_from_2_offer);
		__price.put("pizza",(float) 12.0);
		__price.put("pasta",(float) 8.0);
		__for_1_discount.put("pizza",(float) 1.0);
		__for_1_discount.put("pasta",(float) 1.0);
		__for_2_discount.put("pizza",(float) 0.91666667);
		__for_2_discount.put("pasta",(float) 0.9375);
		__for_N_discount.put("pizza",(float) 0.91666667);
		__for_N_discount.put("pasta",(float) 0.9375);
		__3_from_2_offer.put("offer", "Baklava");
		__for_3_offer.put("pizza",___pizza_for_3_offer);
		__for_3_offer.put("pasta", ___pasta_for_3_offer);
		___pizza_for_3_offer.put("minQty", 3);
		___pizza_for_3_offer.put("item", "Garlic Bread");
		___pasta_for_3_offer.put("minQty", 3);
		___pasta_for_3_offer.put("item", "Soft Drink");
		
		this.menuToken=menu;
		return menu;
		
		
	}
	
	@SuppressWarnings("unchecked")
	private void specialOffers() {
		int curPizzaQty=(int) ((HashMap<String, Object>) ((HashMap<String, Object>) sessionToken.get("session")).get("qty")).get("pizza");
		int curPastaQty=(int) ((HashMap<String, Object>) ((HashMap<String, Object>) sessionToken.get("session")).get("qty")).get("pasta");
		( (HashMap<String, Object>) ((HashMap<String, Object>) ((HashMap<String,Object>) sessionToken.get("session")).get("offers")).get("specialOffers")).put("qty",(int)(Math.min(curPastaQty,curPizzaQty))/3);
	}
	
	public HashMap<String, Object> readSession(){	
		return sessionToken;
		
	}
	@SuppressWarnings("unchecked")
	private void genericOffers(String orderType) {
		int curQty = (Integer) ((HashMap<String, Object>) ((HashMap<String, Object>) sessionToken.get("session")).get("qty")).get(orderType.toLowerCase());
		((HashMap<String, Object>) ((HashMap<String, Object>) ((HashMap<String, Object>) sessionToken.get("session")).get("offers")).get(orderType.toLowerCase())).put("qty", (int)(curQty/3));
	}
	
	
	
	public float getUnitPrice() {
		Map map = new HashMap();
		float unitPrice = (float)((Map<String, Object>) ((Map<String,Object>) this.menuToken.get("main")).get("price")).get("pizza");
		return unitPrice;
	}
	
}
