package mvc.controllers;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import mvc.models.ItemsViewModel;
import mvc.models.RateAnythingModel;
/** Class handles logic for adding new items to the RateAnythingModel class.
 * @author William Freeman
 */
public class AddItemController extends HttpServlet {
	/**
	 * 
	 */
	private static final long serialVersionUID = -8885422709633491616L;
	/** Called when user clicks the Add button on the UI and updates
	 *  RateAnythingModel accordingly.
	 */
	public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException{
		String add = request.getParameter("newItem");
		RequestDispatcher rd = null;
		RateAnythingModel rateModel = new RateAnythingModel(add);
		
		ItemsViewModel result = new ItemsViewModel(rateModel.GetItems());
		
		rd = request.getRequestDispatcher("/views/index.jsp");
		request.setAttribute("viewModel", result);
		rd.forward(request, response);
	}

}
