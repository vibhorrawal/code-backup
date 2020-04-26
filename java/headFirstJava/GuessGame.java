public class GuessGame{
  Player p1;
  Player p2;
  Player p3;

  public void startGame(){
    p1 = new Player();
    p2 = new Player();
    p3 = new Player();

    boolean p1isRight = false, p2isRight = false, p3isRight = false;

    int target = (int) (Math.random() * 10);
    System.out.println("The number to guess is: " + target);

    while (true) {
      p1.guess();
      p2.guess();
      p3.guess();

      if(p1.number == target) p1isRight = true;
      if(p2.number == target) p2isRight = true;
      if(p3.number == target) p3isRight = true;

      if (p3isRight || p2isRight || p1isRight) {
        System.out.println("*** We have a winner ***");
        System.out.println("Player 1 got it right? " + p1isRight);
        System.out.println("Player 2 got it right? " + p2isRight);
        System.out.println("Player 3 got it right? " + p3isRight);
        System.out.println("Game over\n********");
        break;

      }
      else {
        System.out.println("Players will have to try again :(\n");
      }
    }
  }
}
