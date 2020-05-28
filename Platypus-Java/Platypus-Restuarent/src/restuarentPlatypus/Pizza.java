package restuarentPlatypus;

import java.util.HashMap;
import java.util.Map;

public class Pizza implements Orders{

	private static String order = "pizza";
	private int qty;
	private float unitPrice;
//	private float eligibleOffers;
	private int minQtyForOffer;
	private float discount;
	@SuppressWarnings("unchecked")
	public Pizza(int qty, HashMap<String, Object> menu) {
		this.qty = qty;
		this.unitPrice = (float)((Map<String, Object>) ((Map<String,Object>) menu.get("main")).get("price")).get(order);
		this.minQtyForOffer = (Integer) ((HashMap<String, Object>) ((HashMap<String, Object>) ((HashMap<String, Object>) menu.get("offers")).get("for-3-offer")).get(order)).get("minQty");
		
		if (this.qty > 0 && this.qty < 3) {
			this.discount = (float) ((HashMap<String, Object>) ((HashMap<String, Object>) menu.get("main")).get("for-" + String.valueOf(qty) + "-discount")).get(order);
		}
		else if (qty >= 3) {
			this.discount = (float) ((HashMap<String, Object>) ((HashMap<String, Object>) menu.get("main")).get("for-N-discount")).get(order);
		}
		else
			this.discount=0;
		
	}
	@Override
	public float getAmount() {
		return this.qty*this.unitPrice*this.discount;
	}


	@Override
	public float getOffers() {
		return (Integer)this.qty/(Integer)this.minQtyForOffer;
	}
	public float getUnitPrice() { 
		return this.unitPrice;
	}

}
