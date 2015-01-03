package edu.umkc.wjfkc2;

import java.awt.event.KeyEvent;

import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
/** Class controls the menu for the program.
 */
public class MenuPanel extends JMenuBar{
	private JMenuItem exitMenuItem = null;
	private JMenuItem browseMenuItem = null;
	private JMenuItem maintainMenuItem = null;
	public MenuPanel(){
		//Create the first menu.
		JMenu fileMenu = new JMenu("File");
		fileMenu.setMnemonic(KeyEvent.VK_F);
		this.add(fileMenu);
		//Create an item for the first menu.
		exitMenuItem = new JMenuItem("Exit", KeyEvent.VK_X);
		fileMenu.add(exitMenuItem);
		
		//Create View menu.
		JMenu viewMenu = new JMenu("View");
		viewMenu.setMnemonic(KeyEvent.VK_V);
		this.add(viewMenu);
		//Create View menu items.
		browseMenuItem = new JMenuItem("Browse", KeyEvent.VK_B);
		maintainMenuItem = new JMenuItem("Maintain", KeyEvent.VK_M);
		viewMenu.add(browseMenuItem);
		viewMenu.add(maintainMenuItem);
	}
	/** Returns menu items based upon parameter i.
	 * @param i - Parameter to control which menu item is returned.
	 * @return - Returns the requested menu item.
	 * @throws Exception - If i is not a valid menu selection.
	 */
	public JMenuItem getMenuItem(int i) throws Exception{
		if (i < 0 || i > 2){
			Exception e = new Exception("i is an invalid param.");
			throw e;
		}
		if (i == 0){
			return exitMenuItem;
		}else if(i == 1){
			return browseMenuItem;
		}
		return maintainMenuItem;
	}
	/** Sets the action listener for GUI components.
	 * @param wnd - The action listener that responds to action events.
	 */
	public void addListeners(MainWindow wnd){
		exitMenuItem.addActionListener(wnd);
		browseMenuItem.addActionListener(wnd);
		maintainMenuItem.addActionListener(wnd);
	}
}

