package edu.umkc.wjfkc2;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.nio.file.Paths;
import java.sql.SQLException;

import javax.swing.ImageIcon;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JScrollPane;
import javax.swing.SwingConstants;
import javax.swing.SwingUtilities;
/** This class displays the main window for this application. All GUI elements
 *  are controlled by this class.
 */
public class MainWindow extends JFrame implements ActionListener{
	/*TODO: BUG OCCURS WHEN USER MASHES ON PREV OR NEXT BUTTONS,
	 * 		THIS IS A THREADING ISSUE BUT NOT SURE OF THE CAUSE ATM!
	 * 		PROGRAM STILL FUNCTIONS JUST THROWS A java.lang.NullPointerException.
	 * 		ONE POSSIBLE FIX COULD BE TO JUST INGORE OR DISABLE PREV & NEXT BUTTONS
	 * 		UNTIL LOAD IS COMPLETE.
	 */
	private static PhotoControl photoController = new PhotoControl();
	private static BottomPane botPane = null;
	private static MenuPanel menuBar = null;
	private static JLabel imageLabel = null;
	private static boolean browseMode = true;
	private static Photo newPhoto = null;
	private final JFileChooser fc = new JFileChooser();
	
	public MainWindow(String wName, int width, int height){
		super(wName);
		this.setSize(width, height);
		//Add bottom pane.
		botPane = new BottomPane();
		Container contentPane = getContentPane();
		contentPane.add(botPane, BorderLayout.SOUTH);
		
		//Add Image Panel.
		imageLabel = new JLabel("", SwingConstants.CENTER);
		JScrollPane scrollPane = new JScrollPane(imageLabel);
		//Import the image.
		Photo photo = photoController.getCurPhoto();
		if(photo.image != null){
			ImageIcon image = new ImageIcon(photo.image);
			imageLabel.setIcon(image);	
		}else{
			//Load a default image.
			imageLabel.setIcon(new ImageIcon("UMKC1.jpg"));
		}
		contentPane.add(scrollPane);
		
		//Add a menu.
		menuBar = new MenuPanel();
		setJMenuBar(menuBar);
		botPane.getSouthPane().addListeners(this);
		botPane.getDatePane().getMaintenancePane().addListeners(this);
		menuBar.addListeners(this);
		
		InitUI();
	}
	/** Initializes the UI. To be used in the MainWindow() constructor, does
	 *  not create a seperate thread.
	 */
	private static void InitUI(){
		if(browseMode == true){
			botPane.setBrowseMode();
		}else{
			botPane.setMaintenanceMode();
		}
		botPane.UpdateUI(photoController);
	}
	/** Sets the current UI layout depending upon which mode the program is set
	 *  to. In Browse mode, the description and date pane are locked and 
	 *  modification buttons are hidden. In maintenance mode, fields are 
	 *  editable and buttons are no longer hidden.
	 */
	private static void UpdateUI(){
		if(browseMode == true){
			botPane.setBrowseMode();
		}else{
			botPane.setMaintenanceMode();
		}
		botPane.UpdateUI(photoController);
		//Create a separate thread to access DB.
		Runnable r = new Runnable(){
			@Override
			public void run(){
				Photo photo = photoController.getCurPhoto();
				if(photo.image != null){
					ImageIcon image = new ImageIcon(photo.image);
					imageLabel.setIcon(image);	
				}else{
					imageLabel.setIcon(new ImageIcon("UMKC1.jpg"));
				}
			}
		};
		Thread t = new Thread(r);
		t.start();		
	}
	
	public PhotoControl getController(){
		return photoController;
	}
	/** Detects interaction with GUI elements and calls functions based upon
	 *  the user's selection.
	 */
	@Override
	public void actionPerformed(ActionEvent evt) {
		//Check Prev/Next buttons.
		if(evt.getSource() == botPane.getSouthPane().getNextButton()){
			photoController.nextPhoto();
			UpdateUI();
		}else if (evt.getSource() == botPane.getSouthPane().getPrevButton()){
			photoController.prevPhoto();
			UpdateUI();
		}
		
		//Check Menu options.
		try{
			if(evt.getSource() == menuBar.getMenuItem(0)){
				PhotoDBAccess.cleanup();
				System.exit(0);
			}else if(evt.getSource() == menuBar.getMenuItem(1)){
				browseMode = true;
				UpdateUI();
			}
			else if(evt.getSource() == menuBar.getMenuItem(2)){
				browseMode = false;
				UpdateUI();
			}
		}catch(Exception e){
			System.out.println("Invalid parameter for getMenuItem()");
			UpdateUI();
		}
		
		//Check MaintenanceButtons.
		try{
			if(evt.getSource() == 
					botPane.getDatePane().getMaintenancePane().getMaintenanceButton(0)){
				//Delete button pressed.
				Runnable r = new Runnable(){
					//Access database on separate thread.
					@Override
					public void run() {
						try {
							photoController.removeCurPhoto();
						} catch (SQLException e) {
							System.out.println("Error removing photo from " +
									"controller: " + e);
						}
						SwingUtilities.invokeLater(new Runnable(){
							@Override
							public void run(){
								UpdateUI();
							}
						});
					}
				};
				Thread t = new Thread(r);
				t.start();
					
			}else if(evt.getSource() == 
					botPane.getDatePane().getMaintenancePane().getMaintenanceButton(1)){
				//Save button pressed.
				Runnable r = new Runnable() {
					@Override
					//Access DB on separate thread.
					public void run(){
						if(newPhoto != null){
							//A new photo has been added and needs saved.
							newPhoto.date = botPane.getDatePane().getTextField().getText();
							newPhoto.description = botPane.getDescriptionPane().getTextArea().getText();
							photoController.addPhoto(newPhoto);
							//Reset data.
							newPhoto = null;
							botPane.getDatePane().getTextField().setText(
									photoController.getCurPhoto().date);
							botPane.getDescriptionPane().getTextArea().setText(
									photoController.getCurPhoto().description);
						}else{
							Photo photo = new Photo();
							photo.date = botPane.getDatePane().getTextField().getText();
							photo.description = botPane.getDescriptionPane().getTextArea().getText();	
							photoController.updatePhoto(photo);
						}
						SwingUtilities.invokeLater(new Runnable(){
							@Override
							public void run(){
								UpdateUI();
							}
						});
					}
				};
				Thread t = new Thread(r);
				t.start();
				
			}else if(evt.getSource() == 
					botPane.getDatePane().getMaintenancePane().getMaintenanceButton(2)){
				//Add photo button pressed.
				int returnVal = fc.showOpenDialog(this);
				if (returnVal == JFileChooser.APPROVE_OPTION) {
		            File file = fc.getSelectedFile();
		            newPhoto = new Photo(Paths.get(file.getAbsolutePath()));
		            //Display the new photo.
		            ImageIcon image = new ImageIcon(newPhoto.image);
		    		imageLabel.setIcon(image);
		    		//Clear data.
		    		botPane.getDatePane().getTextField().setText("1/1/1988");
					botPane.getDescriptionPane().getTextArea().setText("");
		    		return;
		        }
				UpdateUI();
			}
		}catch(Exception e){
			System.out.println("Invalid parameter for getMaintenanceButton()");
		}
		
		//Check Picture number text field.
		if(evt.getSource() == botPane.getSouthPane().getTextField()){
			try {
				photoController.selectPhoto(Integer.valueOf(botPane.getSouthPane().getTextField().getText()));
				UpdateUI();
			} catch (NumberFormatException | SQLException e) {
				System.out.println("Error in selectPhoto call: " + e);
				UpdateUI();
			}
		}
	}
}

