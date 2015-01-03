package edu.umkc.wjfkc2;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.ResultSet;
import java.sql.SQLException;
/** Provides control to the user interface based upon the actions taken by
 *  the user. Communicates directly with AccountDBAccess to query and modify
 *  the database when needed.
 */
public class TransactionControl implements ActionListener {
	private AccountDBAccess db = null;
	private String toAct = null;
	private String fromAct = null;
	private String amount = null;
	private String toActAmt = null;
	private String fromActAmt = null;
	private boolean fromActFound = false;
	private boolean toActFound = false;
	
	public TransactionControl(){
		try {
			db = new AccountDBAccess();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			System.out.println(e);
		}
	}
	/** Performs the requested action based upon the user's GUI input.
	 *  If the user clicks on the clear button then the method will reset the
	 *  text fields to a default value. If the user pressed the transfer button
	 *  then the method will verify the user's input and proceed to update the
	 *  database if correct.
	 */
	@Override
	public void actionPerformed(ActionEvent evt) {
		if(evt.getSource() == TransactionLayout.getClearButton()){
			//Reset the text fields.
			TransactionLayout.getAmountField().setText("0");
			TransactionLayout.getFromField().setText("0");
			TransactionLayout.getToField().setText("0");
		}
		else if(evt.getSource() == TransactionLayout.getTransferButton()){
			//Get data from text fields.
			toAct = TransactionLayout.getToField().getText();
			fromAct = TransactionLayout.getFromField().getText();
			amount = TransactionLayout.getAmountField().getText();
			if(checkBalance()){
				//Reset found values.
				fromActFound = false;
				toActFound = false;
				//Calculate the new amounts.
				calculateAmounts();
			}else{
				//Display error message to user.
				if(!(fromActFound && toActFound)){
					TransactionLayout.displayActErrorMsg();
				}else{
					TransactionLayout.displayBalanceErrorMsg();
				}
			}
			
			try {
				TransactionLayout.updateUI(getResultSet());
			} catch (SQLException e) {
				System.out.println("Issue in TransactionControl(): " + e);
			}
		}
		
	}
	/** Method determines the updated account amounts after the requested
	 *  transaction. Once calculated the method will update the database
	 *  with the new amounts.
	 *  METHOD SHOULD ONLY BE CALLED AFTER VERIFYING CORRECT USER INPUT!
	 */
	private void calculateAmounts(){
		try {
			ResultSet rs = db.queryTable();
			boolean more = rs.next();
			while(more){
				if(Integer.parseInt(rs.getString("account_id"))
						== Integer.parseInt(fromAct)){
					//Update the new account balance.
					fromActAmt = Integer.toString(
							Integer.parseInt(rs.getString("account_balance"))
							- Integer.parseInt(amount));
				}
				else if (Integer.parseInt(rs.getString("account_id"))
						== Integer.parseInt(toAct)){
					//Update the new account balance.
					toActAmt = Integer.toString(
							Integer.parseInt(rs.getString("account_balance"))
							+ Integer.parseInt(amount));
				}
				more = rs.next();
			}
			db.executeTransfer(Integer.parseInt(toAct), 
					Integer.parseInt(fromAct), toActAmt, fromActAmt);
		} catch (SQLException e) {
			System.out.println("Error in calculateAmounts(): " + e);
		}
	}
	/** Method queries the database and determines if there is enough in the 
	 *  account for the transaction. Will also check to see if the user is
	 *  attempting to transfer from the correct accounts.
	 *  @return - Returns false if there is not enough funds in the account,
	 *  will also return false if the accounts are not found.
	 */
	private boolean checkBalance(){
		try {
			ResultSet rs = db.queryTable();
			boolean more = rs.next();
			while(more){
				//Search for both accounts & check the balance.
				if(Integer.parseInt(rs.getString("account_id"))
						== Integer.parseInt(fromAct)){
					fromActFound = true;
					if(Integer.parseInt(amount) > 
					Integer.parseInt(rs.getString("account_balance"))){
						//Not enough in account.
						toActFound = true; //Hotfix to correct issue with displaying incorrect error messages.
						return false;
					}
				}else if(Integer.parseInt(rs.getString("account_id"))
						== Integer.parseInt(toAct)){
					toActFound = true;
				}
				more = rs.next();
			}
			if(fromActFound && toActFound){
				return true;
			}
			//Reset found variable.
			fromActFound = false;
			toActFound = false;
		} catch (SQLException e) {
			System.out.println("Problem with query: " + e);
		}
		return false;
	}
	/** Query database and return the result found from that query.
	 *  @return - The ResultSet from database query.
	 *  @throws SQLException - If there is an error in the database query.
	 */
	public ResultSet getResultSet() throws SQLException{
		return db.queryTable();
	}

}
