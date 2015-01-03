package edu.umkc.wjfkc2;

import java.awt.Graphics;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.util.ArrayList;
import java.util.Iterator;

import javax.swing.JPanel;

public class MyCanvas extends JPanel implements MouseListener, MouseMotionListener {
	private ArrayList<ArrayList<Line>> lineListHist = new ArrayList<ArrayList<Line>>();
	private ArrayList<Line> curLineList = new ArrayList<Line>();
	private Points prevPoints = null;
	
	public MyCanvas(){
		addMouseListener(this);
		addMouseMotionListener(this);
	}
	
	/** Method will cause the screen to clear by assigning the history arrays
	 *  to new values. Method then repaints the screen.
	 */
	public void clearCanvas(){
		lineListHist = new ArrayList<ArrayList<Line>>();
		curLineList = new ArrayList<Line>();
		prevPoints = null;
		this.repaint();
	}
	
	@Override
	/** Method will obtain the current x, y position on the screen, store these
	 *  values into curLineList and draws a point onto the screen.
	 */
	public void mouseClicked(MouseEvent e) { 
		int x = e.getX();
		int y = e.getY();
		Points p1 = new Points(x, y);
		Points p2 = new Points(x, y);
		Line line = new Line(p1, p2);
		curLineList.add(line);
		Graphics g = getGraphics();
		g.drawLine(line.m_p1.m_x, line.m_p1.m_y, line.m_p2.m_x, line.m_p2.m_y);
	}

	@Override
	public void mouseEntered(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseExited(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mousePressed(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	/** Method will save the line history in lineListHist, will also clear data
	 *  in order to start a new line.
	 */
	public void mouseReleased(MouseEvent e) {
		//Store line history.
		lineListHist.add(curLineList);
		//Start a new list to hold lines.
		curLineList = new ArrayList<Line>();
		prevPoints = null;
	}

	@Override
	/** Method will obtain the current x, y coords from the screen and will
	 *  store this data as a line. Will also draw the line to the screen.
	 */
	public void mouseDragged(MouseEvent e) {
		if(prevPoints == null){
			//New line.
			int x = e.getX();
			int y = e.getY();
			Points p1 = new Points(x, y);
			Points p2 = new Points(x, y);
			prevPoints = p2;
			Line line = new Line(p1, p2);
			curLineList.add(line);
			Graphics g = getGraphics();
			g.drawLine(line.m_p1.m_x, line.m_p1.m_y, line.m_p2.m_x, line.m_p2.m_y);
		}else{
			//Continuing line.
			int x = e.getX();
			int y = e.getY();
			Points p1 = prevPoints;
			Points p2 = new Points(x, y);
			prevPoints = p2;
			Line line = new Line(p1, p2);
			curLineList.add(line);
			Graphics g = getGraphics();
			g.drawLine(line.m_p1.m_x, line.m_p1.m_y, line.m_p2.m_x, line.m_p2.m_y);
		}
	}

	@Override
	public void mouseMoved(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}
	
	/** Method preserves the on screen graphics when the screen focus is lost
	 *  or resized. Method iterates through lineListHist and then iterates
	 *  through the line array and redraws lines onto the screen.
	 */
	public void paintComponent(Graphics g){
		super.paintComponent(g);
		for(Iterator<ArrayList<Line>> it = lineListHist.iterator();
				it.hasNext();){
			ArrayList<Line> lines = it.next();
			for(Iterator<Line> itr = lines.iterator(); itr.hasNext();){
				Line curLine = itr.next();
				g.drawLine(curLine.m_p1.m_x, curLine.m_p1.m_y,
						curLine.m_p2.m_x, curLine.m_p2.m_y);
			}
		}
	}
}
