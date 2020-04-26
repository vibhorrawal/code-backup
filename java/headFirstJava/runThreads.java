public class runThreads implements Runnable{
  public static void main(String[] args) {
    runThreads r = new runThreads();
    Thread a = new Thread(r);
    Thread b = new Thread(r);

    a.setName("alpha");
    b.setName("beta");

    a.start();
    b.start();
  }

  public void run(){
    for (int i = 0; i < 10 ;i++ ) {
      System.out.println(Thread.currentThread() . getName() + " is running");
    }
  }

}
