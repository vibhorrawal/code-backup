void stackChange(int currentStack,int nextStack){
  if(currentStack==1)
  {
    while(value()!=31)
    setline();
    if(nextStack==2)
    {
      rightTurn();
      delay(HARDTURN);
    }
    else {
      straight();
      delay(STRAIGHTDELAY);
    }
  }
    else if(currentStack==2){
       while(value()!=31)
    setline();
    if(nextStack==1)
    rightTurn();
    else leftTurn();
    delay(HARDTURN);
    }
    else if(currentStack==3){
      while(value()!=31)
      setline();
      if(nextStack==2)
      rightTurn();
      delay(HARDTURN);
      else {
        straight();
        delay(STRAIGHTDELAY);
      }
    }
  }

