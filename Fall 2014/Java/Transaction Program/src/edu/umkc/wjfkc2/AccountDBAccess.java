package edu.umkc.wjfkc2;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
/** Connects and executes SQL statements with the account database.
 */
public class AccountDBAccess {
	private static Connection con;
    private static Statement stmt;

    // Load class and create a connection to the database
    public AccountDBAccess() throws SQLException {
        // The ODBC Data Source Name (DSN) is example
        String url = "jdbc:mysql://Kc-isia-mysql1d.kc.umkc.edu/wjfkc2";
        String userID = "wjfkc2";
        String password = "4jGfq3u5v";
    
        try {
            Class.forName("com.mysql.jdbc.Driver");
        } catch(java.lang.ClassNotFoundException e) {
            System.out.println(e); 
            System.exit(0);
        }
        
        con = DriverManager.getConnection(url,userID,password);
        stmt = con.createStatement();                             
    }

    public static void cleanup() throws SQLException {
        // Close connection and statement
        // Connections, statements, and result sets are
        // closed automatically when garbage collected
        // but it is a good idea to free them as soon
        // as possible.
        // Closing a statement closes its current result set.
        // Operations that cause a new result set to be
        // created for a statement automatically close
        // the old result set.
        stmt.close();
        con.close();
    }
    /** Updates the specified database entries to the new value. Ensures that
     *  the requests are complete in a database transaction.
     *  @param to_id - account_id for the account funds are being transfered to.
     *  @param from_id - account_id for the account funds are being transfered from.
     *  @param newToAmt - New amount to be stored for the account where funds
     *  are deposited.
     *  @param newFromAmt - New amount to be stored for the account where funds
     *  are withdrawn.
     *  @throws SQLException - If there is an issue with the SQL update.
     */
    public void executeTransfer(int to_id, int from_id, String newToAmt,
    		String newFromAmt) throws SQLException{
    	String sqlCmd1 = "UPDATE Account " + "SET account_balance = '" + newToAmt + "'"
    			+ "WHERE account_id = " + Integer.toString(to_id);
    	String sqlCmd2 = "UPDATE Account " + "SET account_balance = '" + newFromAmt + "'"
    			+ "WHERE account_id = " + Integer.toString(from_id);
    	//Ensure transaction to DB.
    	try{
	    	con.setAutoCommit(false);
	    	stmt.executeUpdate(sqlCmd1);
	    	stmt.executeUpdate(sqlCmd2);
	    	con.commit();
    	}catch (Exception e){
    		System.out.println("Error during transfer transaction:" + e);
    		con.rollback();
    	}
    	con.setAutoCommit(true);
    }
    /** Returns a ResultSet containing the account_id, account_name, and
     *  account_balance for the account database.    
     *  @return - The ResultSet containing database information.
     *  @throws SQLException - If there is an error in the query statement.
     */
    public ResultSet queryTable() throws SQLException {
    	String query = "SELECT account_id, account_name, account_balance " +
    			"FROM account";
    	return stmt.executeQuery(query);
    }

}
