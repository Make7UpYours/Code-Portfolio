package edu.umkc.wjfkc2;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.JButton;
import javax.swing.JFrame;

public class DrawApp extends JFrame implements ActionListener {
	private static MyCanvas drawingCanvas;
	
	public DrawApp(String title){
		super(title);
		setSize(800, 600);
		
		addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				System.exit(0);
			}
		});
		
		Container contentPane = getContentPane();
		drawingCanvas = new MyCanvas();
		JButton clear = new JButton("Clear");
		clear.addActionListener(this);
		contentPane.add(drawingCanvas, BorderLayout.CENTER);
		contentPane.add(clear, BorderLayout.SOUTH);
	}
	
	public static void main(String[] args) {
		JFrame frame = new DrawApp("Drawing Board");
		frame.setVisible(true);
	}

	@Override
	public void actionPerformed(ActionEvent arg0) {
		drawingCanvas.clearCanvas();	
	}

}
