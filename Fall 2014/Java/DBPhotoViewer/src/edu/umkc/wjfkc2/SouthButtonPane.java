package edu.umkc.wjfkc2;

import java.sql.SQLException;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.border.Border;
/** This class contains the GUI components located in the very south pane of
 *  the window. Controls these GUI components.
 */
public class SouthButtonPane extends JPanel {
	private static JButton prevButton = null;
	private static JButton nextButton = null;
	private static JLabel pictureCountLabel = null;
	private static JTextField pictureNumberTextField = null;
	public SouthButtonPane(){
		pictureNumberTextField = new JTextField("1",4);
		pictureCountLabel = new JLabel(" of 1");
		prevButton = new JButton("<prev");
		nextButton = new JButton("next>");
		
		this.add(pictureNumberTextField);
		this.add(pictureCountLabel);
		this.add(prevButton);
		this.add(nextButton);
		
		Border border = BorderFactory.createEtchedBorder();
		this.setBorder(border);
	}
	/** Updates the GUI, disabling and enabling buttons.
	 *  Disables the previous button when curPicIndex is equal to 1,
	 *  disables the next button when curPicIndex is equal to numPics.
	 *  Function should be called at any point where the UI might change.
	 * @throws SQLException 
	 */
	public void UpdateUI(PhotoControl controller) throws SQLException{
		if(controller.getCurPhotoNum() == 1 &&
				controller.getCurPhotoNum() == controller.getNumPhotos()){
			prevButton.setEnabled(false);
			nextButton.setEnabled(false);
		}
		else if(controller.getCurPhotoNum() == 1){
			prevButton.setEnabled(false);
			nextButton.setEnabled(true);
		}else if (controller.getCurPhotoNum() == controller.getNumPhotos()){
			nextButton.setEnabled(false);
			prevButton.setEnabled(true);
		}
		else{
			prevButton.setEnabled(true);
			nextButton.setEnabled(true);
		}
		pictureNumberTextField.setText(Integer.toString(controller.getCurPhotoNum()));
		try {
			pictureCountLabel.setText(" of " + Integer.toString(controller.getNumPhotos()));
		} catch (SQLException e) {
			System.out.println("Error obtaining the number of phots in SouthButtonPane.UpdateUI(): " + e);
		}
		if(controller.getNumPhotos() == 0){
			//No photos but the default photo.
			nextButton.setEnabled(false);
			prevButton.setEnabled(false);
		}
	}
	/** Assigns action listeners to the GUI components.
	 * @param wnd - The window that responds to GUI actions.
	 */
	public void addListeners(MainWindow wnd){
		prevButton.addActionListener(wnd);
		nextButton.addActionListener(wnd);
		pictureNumberTextField.addActionListener(wnd);
	}
	
	public JTextField getTextField(){
		return pictureNumberTextField;
	}
	
	public JButton getNextButton(){
		return nextButton;
	}
	
	public JButton getPrevButton(){
		return prevButton;
	}
}
