package mvc.controllers;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import mvc.models.ItemsViewModel;
import mvc.models.RateAnythingModel;
/** Sends data to the jsp that will display the list of items that people like.
 * @author William Freeman
 */
public class ViewController extends HttpServlet {
	/**
	 * 
	 */
	private static final long serialVersionUID = 6094012353381476354L;
	/** Called when the page is first loaded. Sends data to the jsp page.
	 */
	public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException{
		RequestDispatcher rd = null;
		RateAnythingModel rateModel = new RateAnythingModel();
		
		ItemsViewModel result = new ItemsViewModel(rateModel.GetItems());
		
		rd = request.getRequestDispatcher("/views/index.jsp");
		request.setAttribute("viewModel", result);
		rd.forward(request, response);
	}
}
