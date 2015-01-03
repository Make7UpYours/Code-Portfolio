package edu.umkc.wjfkc2;

import java.io.ByteArrayInputStream;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class PhotoDBAccess {
	private static Connection con;
    private static Statement stmt;

    // Load class and create a connection to the database
    public PhotoDBAccess() throws SQLException {
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
    /** Queries the photo database and returns a result set containing the photo
     *	which is associated with the index.
     *	@return - The ResultSet containing photo data.
     *	@param index - The index of the photo to return.
     */
    public ResultSet queryPhoto(String index) throws SQLException {
    	String query = "SELECT pictnum, description, date, photo" +
    			" FROM photos WHERE pictnum = " + index;
    	return stmt.executeQuery(query);
    }
    /** Removes the requested photo from the photo database.
     * 	@param index - The index of the photo to delete.
     * 	@throws SQLException - If there is an issue running the SQL statement.
     */
    public void deletePhoto(String index) throws SQLException {
    	//Delete photo and update indices.
    	try{
    		con.setAutoCommit(false);
    		String sqlCmd1 = "DELETE FROM photos WHERE pictnum = " + index;
    		stmt.executeUpdate(sqlCmd1);
        	String sqlCmd2 = "UPDATE photos SET pictnum = pictnum - 1" +
        			" WHERE pictnum >= " + index;
        	stmt.executeUpdate(sqlCmd2);
        	con.commit();
    	}catch(Exception e){
    		System.out.println("Error removing photo from DB: " + e);
    		con.rollback();
    	}
    	con.setAutoCommit(true);
    }
    /** Obtains the current amount of photos stored in the database.
     *  @return - The ResultSet containing the number of photos.
     *  @throws SQLException - If there is an issue executing the SQL command
     */
    public ResultSet getPhotoCount() throws SQLException{
    	String sqlCmd = "SELECT COUNT(*) AS total FROM photos";
    	return stmt.executeQuery(sqlCmd);
    }
    /** Updates the information for the photo stored at index in the photo
     *  database.
     * 	@param index - The index of the photo to be updated.
     * 	@param desc - The description information of the photo.
     * 	@param date - The date information of the photo.
     * 	@throws SQLException - If there is an issue executing the SQL command.
     */
    public void updatePhoto(int index, String desc, String date)
    		throws SQLException {
    	try{
    		con.setAutoCommit(false);
        	//Update the description and date of photo
        	String sqlCmd = "UPDATE photos SET description = '" + desc +
        			"', date = '" + date + "' WHERE pictnum = " + index;
        	stmt.executeUpdate(sqlCmd);
        	con.commit();
    	}catch (Exception e){
    		System.out.println("Error during db photo update: " + e);
    		con.rollback();
    	}
    	con.setAutoCommit(true);
    }
    /** Inserts the photo into the database and updates the index for all other
     *  photos that need to be updated.
     * 	@param index - Index of the photo to be inserted at.
     * 	@param pic - A byte array of the image.
     * 	@param desc - The description of the photo.
     * 	@param date - The date information of the photo.
     * 	@throws SQLException - If there is an error executing the SQL command.
     */
    public void insertPhoto(int index, byte[] pic, String desc, String date)
    		throws SQLException {
    	PreparedStatement pstmt = null;
    	try{
    		con.setAutoCommit(false);
        	//Update indices.
        	String sqlCmd1 = "UPDATE photos SET pictnum = pictnum + 1" +
        			" WHERE pictnum >= " + index;
        	stmt.executeUpdate(sqlCmd1);
        	
        	//Insert photo.
        	String sqlCmd2 = "INSERT INTO photos (pictnum,description," +
        			"date,photo) VALUES(" + index + ",'"
        			+ desc + "','" + date + "'," + "?)";
        	pstmt = con.prepareStatement(sqlCmd2);
        	ByteArrayInputStream bis = new ByteArrayInputStream(pic);
        	pstmt.setBinaryStream(1, bis, (int)pic.length);
        	pstmt.executeUpdate();
        	pstmt.close();
        	con.commit();
    	}catch (Exception e){
    		System.out.println("Error during db photo insert: " + e);
    		con.rollback();
    	}
    	con.setAutoCommit(true);
    }
    
}
