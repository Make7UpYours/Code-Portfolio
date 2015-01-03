package edu.umkc.wjfkc2;

import javax.swing.JButton;
import javax.swing.JPanel;
/** Class controls the maintenance buttons that will be displayed when in
 *  maintenance mode.
 */
public class MaintenanceButtonPane extends JPanel {
	private static JButton delete = null;
	private static JButton save = null;
	private static JButton add = null;
	public MaintenanceButtonPane(){
		delete = new JButton("Delete");
		save = new JButton("Save Changes");
		add = new JButton("Add Photo");
		
		this.add(delete);
		this.add(save);
		this.add(add);
	}
	public void addListeners(MainWindow wnd){
		delete.addActionListener(wnd);
		save.addActionListener(wnd);
		add.addActionListener(wnd);
	}
	/** Returns the button based upon the parameter selection.
	 * @param i - Index of the button to return.
	 * @return - Returns the button based upon i.
	 * @throws Exception - If i is not an valid input.
	 */
	public JButton getMaintenanceButton(int i) throws Exception{
		if(i < 0 || i > 2){
			Exception e = new Exception("Invalid parameter i");
			throw e;
		}
		if(i == 0){
			return delete;
		}else if (i == 1){
			return save;
		}
		return add;
	}
}
