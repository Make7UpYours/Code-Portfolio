package edu.umkc.wjfkc2;

import javax.swing.JFrame;

public class ChitChatApp {
	public static void main(String[] args) {
        JFrame frame = new ChitChatWindow();
        frame.pack();
        frame.setVisible(true);
        Server s = new Server();
        s.Listen();
    }
}
