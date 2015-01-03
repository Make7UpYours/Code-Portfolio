package edu.umkc.wjfkc2;

import java.sql.ResultSet;
import java.sql.SQLException;
/** This class stores an array of photos and controls which photo will be
 *  selected. Controls all the adding and removing of photos.
 */
public class PhotoControl{
	private PhotoDBAccess db = null;
	private static int curPhotoIndex = 0;
	
	public PhotoControl(){
		try {
			db = new PhotoDBAccess();
			if(getNumPhotos() > 0){
				curPhotoIndex = 1;
			}
		} catch (SQLException e) {
			System.out.println("Error initializing PhotoControl: " + e);
		}
	}
	public void updatePhoto(Photo photo){
		try {
			db.updatePhoto(curPhotoIndex, photo.description, photo.date);
		} catch (SQLException e) {
			System.out.println("Error updating photo: " + e);
		}
	}
	public Photo getCurPhoto(){
		try {
			if(getNumPhotos() == 0){
				//No need to access database.
				return new Photo();
			}
		} catch (SQLException e1) {
			System.out.println("Error obtaining numPhotos from getCurPhoto(): "
					+ e1);
		}
		try {
			ResultSet rs = db.queryPhoto(Integer.toString(curPhotoIndex));
			rs.next();
			Photo photo = new Photo();
			photo.date = rs.getString("date");
			photo.description = rs.getString("description");
			photo.image = rs.getBytes("photo");
			return photo;
		} catch (SQLException e) {
			System.out.println("Error retrieving photo from DB: " + e);
		}
		//Return default photo if there is an error.
		return new Photo();
	}
	
	public int getCurPhotoNum(){
		return curPhotoIndex;
	}
	
	public int getNumPhotos() throws SQLException{
		ResultSet rs = null;
		try {
			rs = db.getPhotoCount();
			rs.next();
		} catch (SQLException e) {
			System.out.println("Error retrieving count from db: " + e);
		}
		return rs.getInt(1);
	}
	public void nextPhoto(){
		curPhotoIndex++;
	}
	public void prevPhoto(){
		curPhotoIndex--;
	}
	public void addPhoto(Photo photo){
		try {
			db.insertPhoto(curPhotoIndex + 1, photo.image,
					photo.description, photo.date);
		} catch (SQLException e) {
			System.out.println("Error adding photo: " + e);
		}
		if(curPhotoIndex <= 0){
			curPhotoIndex = 1;
		}
	}
	/** Removes the current photo from the photos database. Function checks to see
	 *  if we are attempting to remove the last photo and will not allow the 
	 *  last photo to be removed. Changes the current photo index if it is on
	 *  the last photo.
	 * @throws SQLException 
	 */
	public void removeCurPhoto() throws SQLException{
		if(getNumPhotos() == 0){
			//Do nothing, prevent user from deleting last photo.
			curPhotoIndex = 0;
			return;
		}
		db.deletePhoto(Integer.toString(curPhotoIndex));
		if(curPhotoIndex >= getNumPhotos()){
			curPhotoIndex--;	
		}
	}
	/** Changes the current photo the the passed parameter i. Function checks
	 *  to see if i is a valid index. If it is not then the current photo
	 *  index will be changed to the min or max.
	 * @param i - The desired photo index.
	 * @throws SQLException 
	 */
	public void selectPhoto(int i) throws SQLException{
		if(i < 1){
			curPhotoIndex = 1;
		}else if(i > getNumPhotos()){
			curPhotoIndex = getNumPhotos();
		}else{
			curPhotoIndex = i;
		}
	}
}
