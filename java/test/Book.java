class Book {

  private int total,...;
  Book(int total, int type1Pages...){
    this.total = total;
  }
  // ye class alag b rakh sakta aur andar bhi
  class Type {
    int costPerPage;
    private int noOfPages;

    Type(int cost, int pages){
      costPerPage = cost;
      noOfPages = pages;
    }
    public int getCost(){
      return costPerPage * noOfPages;
    }
  }

  public Type t1 = new Type(2,type1Pages); // private b bna sakta
  public Type t2 = new Type(3,type1Pages);
  public Type t3 = new Type(5,type1Pages);

  public totalCostOfBook() {
    return // t1.getCost() + t2.get....
  }
}
