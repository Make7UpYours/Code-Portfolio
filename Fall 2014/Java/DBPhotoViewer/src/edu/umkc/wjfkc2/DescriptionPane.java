package edu.umkc.wjfkc2;

import java.awt.FlowLayout;

import javax.swing.Box;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;
/** Class controls the Description pane in the GUI layout.
 */
public class DescriptionPane extends JPanel {
	private JLabel descriptionLabel = null;
	private JTextArea descriptionTextArea = null;
	public DescriptionPane(){
		this.setLayout(new FlowLayout(FlowLayout.LEFT));
		
		descriptionLabel = new JLabel("Description:");
		descriptionTextArea = new JTextArea(4,20);		
		
		this.add(descriptionLabel);
		this.add(descriptionTextArea);
		this.add(Box.createHorizontalGlue());
		
		descriptionTextArea.setEditable(false);
	}
	public JLabel GetLabel(){
		return descriptionLabel;
	}
	public void enableEdits(){
		descriptionTextArea.setEditable(true);
	}
	public void disableEdits(){
		descriptionTextArea.setEditable(false);
	}
	public JTextArea getTextArea(){
		return descriptionTextArea;
	}
	/** Updates the description text area based upon the current photo that is
	 *  being displayed.
	 * @param controller - The photo control object.
	 */
	public void UpdateUI(PhotoControl controller){
		descriptionTextArea.setText(controller.getCurPhoto().description);
	}
}
