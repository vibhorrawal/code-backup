import java.util.*;

public class TestExceptions2{
  public static void main(String[] args) {
    TestExceptions1 t = new TestExceptions1();
    try{
      t.test();
      System.out.println("Success");

    }
    catch (ScaryException ex){
      System.out.println("Failed");
      ex.getMessage();
      ex.printStackTrace();
    }
  }
}
