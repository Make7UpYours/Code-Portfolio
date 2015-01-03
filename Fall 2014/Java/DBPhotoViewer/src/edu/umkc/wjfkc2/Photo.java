package edu.umkc.wjfkc2;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
/** This class stores the photo data, keeps the image, description and date
 *  information for each photo.
 */
public class Photo{
	public byte[] image;
	public String description;
	public String date;
	public Photo(){
		image = null;
		date = "1/1/1988";
		description = "";
	}
	public Photo(Path fileName) throws IOException{
		image = Files.readAllBytes(fileName);
		date = "1/1/1988";
		description = "";
	}
	/*public Photo(String fileName, String param_date){
		image = new ImageIcon(fileName);
		date = param_date;
		description = "";
	}
	public Photo(String fileName, String param_date, String desc){
		image = new ImageIcon(fileName);
		date = param_date;
		description = desc;
	}*/
}

