package mvc.controllers;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import mvc.models.ItemsViewModel;
import mvc.models.RateAnythingModel;
/** Class handles logic for adding likes to items in the RateAnythingModel 
 *  class.
 * @author William Freeman
 */
public class LikeItemController extends HttpServlet{
	/**
	 * 
	 */
	private static final long serialVersionUID = 7963615310513020315L;
	/** Called when user clicks the like button on the UI and updates
	 *  RateAnythingModel accordingly.
	 */
	public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException{
		String likeQuery = request.getQueryString();
		
		RequestDispatcher rd = null;
		RateAnythingModel rateModel = new RateAnythingModel();
		//Update likes
		rateModel.AddLike(FindItemNum(likeQuery));
		
		ItemsViewModel result = new ItemsViewModel(rateModel.GetItems());
		rd = request.getRequestDispatcher("/views/index.jsp");
		request.setAttribute("viewModel", result);
		rd.forward(request, response);
	}
	/** Returns the index of the item that the user clicked on
	 *  @param query - Query path of the URL.
	 *  @return - Index of item.
	 */
	private int FindItemNum(String query){
		return Integer.parseInt(query.substring(5));
	}
}
