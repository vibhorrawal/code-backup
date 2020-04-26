class myRunnable implements Runnable{
  public void run(){
    go();
  }
  void go(){
    goAgain();
  }
  void goAgain(){
    System.out.println("I am running as a thread!");
    //Thread.sleep() also works here
  }
}

public class testThread{
  public static void main(String[] args) {
    Runnable t = new myRunnable();
    Thread th = new Thread(t);

    th.start();
    try {
      System.out.println("Sweety went to sleep");
      th.sleep(1000);

    }catch(InterruptedException ex){
      ex.printStackTrace();
      System.out.println("Sweety interrupted in sleep");
    }
    System.out.println("How adorable!");
  }
}
