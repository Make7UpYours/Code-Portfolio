package edu.umkc.wjfkc2;

import java.awt.Container;
import java.awt.Dimension;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Vector;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.table.DefaultTableModel;
/** GUI component that displays the account transaction interface for
 *  the user to interact with. When the user does interact with a component,
 *  class will send control over to TransactionControl to handle the events.
 */
public class TransactionLayout extends JFrame {
	private static JTable table;
	private static JTextField fromField = null;
	private static JTextField toField = null;
	private static JTextField amountField = null;
	private static JButton clearButton = null;
	private static JButton transferButton = null;
	private static TransactionControl transControl = null;
	
	private static String[] columnNames = {"Account ID",
            "Account Name",
            "Balance"};
	private Object[][] data = {
			{new Integer(3), "Savings", new Integer(500)},
			{new Integer(4), "Checking", new Integer(270)}};
	
	public TransactionLayout() {
		Container contentPane = getContentPane();
		contentPane.setLayout(new GridBagLayout());
		
		DefaultTableModel dtm = new DefaultTableModel(data,columnNames);		
		table = new JTable(dtm);
		// The default size of a JTable is something like
		// 450 X 400.
		Dimension smallerSize = new Dimension(450, 50);
		table.setPreferredScrollableViewportSize(smallerSize );
		
		JScrollPane scrollPaneForTable = new JScrollPane(table);
				
		GridBagConstraints constraints = new GridBagConstraints();

		constraints.gridx = 0;
		constraints.gridy = 0;
		constraints.gridwidth = 2;
		constraints.gridheight = 1;
		constraints.weightx = 1;
		constraints.weighty = 1;
		constraints.insets = new Insets(4, 4, 4, 4);
		constraints.fill = GridBagConstraints.BOTH;

		contentPane.add(scrollPaneForTable,constraints);
		
		constraints.gridx = 0;
//		constraints.gridy = 1;
		constraints.weighty = 0;
		constraints.gridy = GridBagConstraints.RELATIVE;
		constraints.insets = new Insets(2, 4, 2, 4);
		constraints.fill = GridBagConstraints.NONE;
		constraints.gridwidth = 1;
		constraints.anchor = GridBagConstraints.NORTHEAST;
		JLabel toLabel = new JLabel("From:");
		contentPane.add(toLabel,constraints);
		
		constraints.gridx = 1;
		constraints.anchor = GridBagConstraints.NORTHWEST;
		fromField = new JTextField("3",8);
		// Workaround, because of: http://bugs.java.com/bugdatabase/view_bug.do?bug_id=4247013
		fromField.setMinimumSize(fromField.getPreferredSize());
		contentPane.add(fromField,constraints);
		
		constraints.gridx = 0;
//		constraints.gridy = 2;
		constraints.anchor = GridBagConstraints.NORTHEAST;
		JLabel fromLabel = new JLabel("To:");
		contentPane.add(fromLabel,constraints);
		
		constraints.gridx = 1;
//		constraints.gridy = 2;
		constraints.anchor = GridBagConstraints.NORTHWEST;
		toField = new JTextField("4",8);
		toField.setMinimumSize(toField.getPreferredSize());
		contentPane.add(toField,constraints);

		constraints.gridx = 0;
//		constraints.gridy = 2;
		constraints.anchor = GridBagConstraints.NORTHEAST;
		JLabel amountLabel = new JLabel("Amount:");
		contentPane.add(amountLabel,constraints);
		
		constraints.gridx = 1;
//		constraints.gridy = 2;
		constraints.anchor = GridBagConstraints.NORTHWEST;
		amountField = new JTextField("100",8);
		amountField.setMinimumSize(amountField.getPreferredSize());
		contentPane.add(amountField,constraints);

		constraints.gridx = 0;
//		constraints.gridy = 2;
		constraints.anchor = GridBagConstraints.NORTHEAST;
		clearButton = new JButton("Clear");
		contentPane.add(clearButton,constraints);
		
		constraints.gridx = 1;
//		constraints.gridy = 2;
		constraints.anchor = GridBagConstraints.NORTHWEST;
		transferButton = new JButton("Transfer");
		
		transControl = new TransactionControl();
		
		addActionListeners();
		contentPane.add(transferButton,constraints);

		try {
			updateUI(transControl.getResultSet());
		} catch (SQLException e) {
			System.out.println("Error in TransactionLayout(): " + e);
		}
	}
	/** Sets event action listeners to the GUI components.
	 */
	private void addActionListeners(){
		clearButton.addActionListener(transControl);
		transferButton.addActionListener(transControl);
	}
	
	public static JButton getClearButton(){
		return clearButton;
	}
	
	public static JButton getTransferButton(){
		return transferButton;
	}
	
	public static JTextField getFromField(){
		return fromField;
	}
	
	public static JTextField getToField(){
		return toField;
	}
	
	public static JTextField getAmountField(){
		return amountField;
	}
	/** Updates the UI based upon the data contained in the ResultSet.
	 *  Cycles through the ResultSet and places the data into the table.
	 * @param rs - The ResultSet that contains database data.
	 */
	public static void updateUI(ResultSet rs){
		DefaultTableModel dtm = (DefaultTableModel)(table.getModel());
		int rowCount = dtm.getRowCount();
		try {
			boolean more = rs.next();
			int row = 0;
			int column = 0;
			while(more){
				dtm.setValueAt(rs.getInt("account_id"), row, column);
				column++;
				dtm.setValueAt(rs.getString("account_name"), row, column);
				column++;
				dtm.setValueAt(rs.getInt("account_balance"), row, column);
				more = rs.next();
				column = 0;
				row++;
				//Add a new row of empty data if needed.
				if(row >= rowCount && more){
					dtm.addRow(new Vector());
				}
			}
		} catch (SQLException e) {
			System.out.println("Error in UpdateUI():" + e);
		}
		table.setModel(dtm);
	}
	
	public static void displayActErrorMsg(){
		//Display an error message for the account.
		JOptionPane.showMessageDialog(null, "ERROR: Account not found.");
	}
	
	public static void displayBalanceErrorMsg(){
		//Display an error message for the balance.
		JOptionPane.showMessageDialog(null,
				"ERROR: Not enough funds to complete transaction.");
	}
}
