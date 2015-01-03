package mvc.models;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.ArrayList;

import mvc.Item;
/** Handles business logic for the Rate Anything webapp. Contains a list of 
 *  Items that the user have added to a list of things to like.
 *  @author William Freeman
 */
public class RateAnythingModel implements Serializable{
	/**
	 * 
	 */
	private static final long serialVersionUID = -2292477021189357236L;
	private ArrayList<Item> items = new ArrayList<Item>();
	
	public RateAnythingModel(){
		Read();
	}
	
	public RateAnythingModel(String name){
		Read();
		if(!name.isEmpty()){
			AddItem(name);
		}
	}
	/** Returns a list of Items.
	 *  @return - The list of items the users have liked.
	 */
	public ArrayList<Item> GetItems(){
		return items;
	}
	/** Increments the number of likes for a specified item.
	 *  @param index - The index of the item liked.
	 */
	public void AddLike(int index){
		items.get(index).mLikes++;
		Save();
	}
	/** Adds a new item to the items list.
	 *  @param name - The name of the item to be added.
	 */
	public void AddItem(String name){
		if(CheckDups(name)){
			items.add(new Item(name));
			Save();
		}
	}
	/** Checks for duplicates in the items array. If the item is in the array,
	 *  the method will return false.
	 *  @param name - Name of the Item to be checked.
	 *  @return - true if not found, false otherwise.
	 */
	private boolean CheckDups(String name){
		for(int i = 0; i < items.size(); i++){
			if(items.get(i).mName.equals(name)){
				return false;
			}
		}
		return true;
	}
	/** Reads in data from a serialized text file.
	 */
	@SuppressWarnings("unchecked")
	private void Read(){
		try{
			ObjectInputStream ois = new ObjectInputStream(new FileInputStream("oos.txt"));
			items = (ArrayList<Item>)ois.readObject();
	        ois.close();
		}
		catch(Exception e){
			System.out.println(e);
		}
	}
	/** Saves data to a serialized text file.
	 */
	private void Save(){
		try{
			ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("oos.txt"));
	        oos.writeObject(items);
	        oos.close();
		}
		catch(Exception e){
			
		}
	}
}
