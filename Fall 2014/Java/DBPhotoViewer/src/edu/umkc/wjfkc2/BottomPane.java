package edu.umkc.wjfkc2;

import java.awt.FlowLayout;
import java.sql.SQLException;

import javax.swing.BoxLayout;
import javax.swing.JPanel;
/** This class is the south pane on the main window. Class will control
 *  functionality for all sub-panes stored within this pane.
 */
public class BottomPane extends JPanel{
	private static SouthButtonPane southButtonPane = null;
	private static DescriptionPane descriptionPane = null;
	private static DatePane datePane = null;
	
	public BottomPane(){
		this.setLayout(new BoxLayout(this, BoxLayout.PAGE_AXIS));
		
		descriptionPane = new DescriptionPane();
		datePane = new DatePane(descriptionPane.GetLabel());
		southButtonPane = new SouthButtonPane();
		
		FlowLayout flowLayout = (FlowLayout) southButtonPane.getLayout();
		flowLayout.setAlignment(FlowLayout.LEFT);
		
		this.add(descriptionPane);
		this.add(datePane);
		this.add(southButtonPane);
		
	}
	/** Updates the GUI, calls update functions for all the sub-panes stored
	 *  within this pane.
	 * @param controller - The current instance of the photo controller.
	 */
	public void UpdateUI(PhotoControl controller){
		try {
			southButtonPane.UpdateUI(controller);
		} catch (SQLException e) {
			System.out.println("Error updating the southButtonPane in" +
					" BottomPane.UpdateUI(): " + e);
		}
		datePane.UpdateUI(controller);
		descriptionPane.UpdateUI(controller);
	}
	public DescriptionPane getDescriptionPane(){
		return descriptionPane;
	}
	public DatePane getDatePane(){
		return datePane;
	}
	public SouthButtonPane getSouthPane(){
		return southButtonPane;
	}
	/** Sets the current window view into browse mode by locking the text areas
	 *  and hides maintenance buttons from view.
	 */
	public void setBrowseMode(){
		datePane.disableEdits();
		descriptionPane.disableEdits();
		datePane.hideButtons();
	}
	/** Sets the current window view into maintenance mode and makes the text
	 *  areas editable and shows the maintenance view buttons.
	 */
	public void setMaintenanceMode(){
		datePane.enableEdits();
		descriptionPane.enableEdits();
		datePane.showButtons();
	}
}
