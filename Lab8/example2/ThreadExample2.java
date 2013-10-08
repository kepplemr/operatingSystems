//
//  $Id: ThreadExample2.java,v 1.1 2011/03/24 16:14:32 khj Exp $
//
//    CS4520/5520
//    KH Jacker (modified by Michael Kepple)
//

public class ThreadExample2 
{
    public static void main(String[] arg) 
    {
	DisplayThread helloThread = new DisplayThread("Hello!");
        DisplayThread goodbyeThread = new DisplayThread("Goodbye!");
	helloThread.start();
        goodbyeThread.start();
    }
}

class DisplayThread extends Thread 
{
    public DisplayThread (String name) { super(name); }

    public void run() { System.out.println(getName()); }
}
