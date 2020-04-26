import java.util.*;
public class TestExceptions1{
  public void test() throws ScaryException {
    if(true){
      throw new ScaryException();
    }
    return;
  }
}
class ScaryException extends Exception{

}
