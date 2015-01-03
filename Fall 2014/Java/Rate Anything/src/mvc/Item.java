package mvc;

import java.io.Serializable;

/** Data class that contains information with regards to the number of likes
 *  and the name of the item on the RateAnything WebApp.
 *  @author William Freeman
 */
public class Item implements Serializable{
	/**
	 * 
	 */
	private static final long serialVersionUID = 7886354815349934039L;
	public String mName;
	public int mLikes;
	
	public Item(String name){
		this.mName = name;
		this.mLikes = 1;
	}
}
