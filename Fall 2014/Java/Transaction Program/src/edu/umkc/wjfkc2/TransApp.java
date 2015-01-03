package edu.umkc.wjfkc2;

import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import java.sql.SQLException;

import javax.swing.JFrame;
/** App that allows the user to communicate with an account database and 
 *  transfer funds from one account to another.
 */
public class TransApp {

	public static void main(String[] args) {
		JFrame frame = new TransactionLayout();
		WindowListener l = new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				try {
					AccountDBAccess.cleanup();
				} catch (SQLException e1) {
					System.out.println(e1);
				}
				System.exit(0);
			}
		};
		frame.addWindowListener(l);
		frame.pack();
		frame.setVisible(true);
	}

}
