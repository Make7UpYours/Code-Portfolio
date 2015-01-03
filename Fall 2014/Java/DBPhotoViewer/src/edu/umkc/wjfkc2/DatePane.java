package edu.umkc.wjfkc2;

import java.awt.Dimension;
import java.awt.FlowLayout;

import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
/** Class controls the Date pane in the GUI layout.
 */
public class DatePane extends JPanel{
	private static JTextField dateTextField = null;
	private static MaintenanceButtonPane maintenancePane = null;
	public DatePane(JLabel descriptionLabel){
		this.setLayout(new FlowLayout(FlowLayout.LEFT));
		
		JLabel dateLabel = new JLabel("Date:");
		dateLabel.setPreferredSize(new 
				Dimension(descriptionLabel.getPreferredSize().width,
				dateLabel.getPreferredSize().height));
		dateTextField = new JTextField("1/1/2014", 6);
		maintenancePane = new MaintenanceButtonPane();
		this.add(dateLabel);
		this.add(dateTextField);
		this.add(maintenancePane);
		
		maintenancePane.setVisible(false);
		dateTextField.setEditable(false);
	}
	public MaintenanceButtonPane getMaintenancePane(){
		return maintenancePane;
	}
	public void enableEdits(){
		dateTextField.setEditable(true);
	}
	public void disableEdits(){
		dateTextField.setEditable(false);
	}
	/** Updates the date text field based upon the date information held in
	 *  the current photo that is displayed.
	 * @param controller - The photo controller that contains photos to be
	 * displayed.
	 */
	public void UpdateUI(PhotoControl controller){
		dateTextField.setText(controller.getCurPhoto().date);
	}
	public JTextField getTextField(){
		return dateTextField;
	}
	public void hideButtons()
	{
		maintenancePane.setVisible(false);
	}
	public void showButtons()
	{
		maintenancePane.setVisible(true);
	}
}
