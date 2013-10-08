//
//  $Id: ThreadExample3.java,v 1.1 2011/03/24 16:14:32 khj Exp $
//
//    CS4520/5520
//    KH Jacker (modified by Michael Kepple)
//

public class ThreadExample3 
{

    public static void main(String[] arg) 
    {
	DisplayThread helloThread = new DisplayThread("Hello!",300);
        DisplayThread goodbyeThread = new DisplayThread("Goodbye!",700);
	helloThread.start();
        goodbyeThread.start();
    }
}

class DisplayThread extends Thread 
{
    int waitPeriod;

    public DisplayThread (String name, int waitPeriod)
    {
	super(name);
        this.waitPeriod = waitPeriod;
    }

    public void run() 
    {
        while (true)
        {
	    System.out.println(getName());
            try
            {
                Thread.sleep(waitPeriod);
            }
            catch (Exception ex)
            {
                ex.printStackTrace();
            }
        }
    }
}
