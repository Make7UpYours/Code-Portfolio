package edu.umkc.wjfkc2;
import java.net.*;
import java.io.*;

public class Server {
   
    private static final int PortNumber = 1056;
    private ServerSocket ss = null;
   
    public Server(){
        try {
           
            ss = new ServerSocket(PortNumber);
            System.out.println("Listening on port: " + PortNumber);
        }
        catch (Exception e) {
            System.out.println("Error in RemoteConnection thread:" + e);
        }
    }
    
    public void Listen(){
    	try{
    		while (true) {
                Socket clientSocket = ss.accept();
                String hostName = clientSocket.getInetAddress().getHostName();

                OutputStream out = clientSocket.getOutputStream();
                InputStream in = clientSocket.getInputStream();

                int nextByte = in.read();
                while (nextByte != -1) {
                    System.out.write(nextByte);
                    nextByte = in.read();
                }

                System.out.println(hostName + " disconnecting");
               
                if (in != null)
                    in.close();
                if (out != null)
                    out.close();
                if (clientSocket != null)
                    clientSocket.close();    
            }
    	}
    	catch (Exception e) {
    		System.out.println("Error in RemoteConnection thread:" + e);
    	}
    }
}
