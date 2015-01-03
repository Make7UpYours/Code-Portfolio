package edu.umkc.wjfkc2;

import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import java.sql.SQLException;
/** App that will let the user store photos into a database and view and modify
 *  these stored photos.
 */
public class PhotoApp {
	static MainWindow wnd = new MainWindow("Photo Viewer", 800, 600);
	public static void main(String[] args) {
		WindowListener l = new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				try {
					PhotoDBAccess.cleanup();
				} catch (SQLException e1) {
					System.out.println("Error closing DB connection upon app exit: " + e);
				}
				System.exit(0);
			}
		};
		wnd.addWindowListener(l);
		wnd.pack();
		wnd.setVisible(true);

	}

}
