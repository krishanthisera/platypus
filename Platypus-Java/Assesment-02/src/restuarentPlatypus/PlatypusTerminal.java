package restuarentPlatypus;

public class PlatypusTerminal {
	public static void main(String[] args) {
		Session s = new Session("Krishan");
		s.makeOrder("pasta", 4);
		System.out.println(s.readSession());
	}
}
