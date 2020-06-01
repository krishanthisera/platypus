package restuarentPlatypus;

import java.util.Scanner;

public class StdIn {
private int terminalWidth;
private Scanner terminalInput;
	
	public StdIn(int terminalWidth) {
		this.terminalWidth = terminalWidth;
		this.terminalInput = new Scanner(System.in);
				
		  
       
	}
	
	public Object getInput(String text) {
		System.out.print(text + " :");
		return terminalInput.nextLine(); 
	}
}
