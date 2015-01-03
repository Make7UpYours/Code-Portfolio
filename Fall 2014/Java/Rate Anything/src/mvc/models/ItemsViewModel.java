package mvc.models;

import java.util.ArrayList;

import mvc.Item;
/**Encapsulates data to be sent to the jsp page for processing.
 * @author William Freeman
 */
public class ItemsViewModel {
	public  ArrayList<Item> itemList;
	
	public ItemsViewModel(ArrayList<Item> items){
		this.itemList = new ArrayList<Item>();
		this.itemList = items;
	}
}
