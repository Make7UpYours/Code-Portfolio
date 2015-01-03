package edu.umkc.wjfkc2;

public class Message {
	public String m_msg;
	public String m_ip;
	public String m_senderName;
	
	public Message(){
		m_msg = null;
		m_ip = null;
		m_senderName = null;
	}
	
	public Message(String msg, String ip, String sName){
		m_msg = msg;
		m_ip = ip;
		m_senderName = sName;
	}
}
