void Tcase{
  //1st block
  forward();

  for (i = 0; i < 3; i++)
  {
    while (distance() > MINDISTANCE)
      followLine();
    grip();

    do {                            //180 degree turn
      rotate();
    } while (value() != 48 || value() != 120);

    while (value() != 252)        //  untill T is encountered
      followLine();

    if (colormatch(r[0], g[0], b[0]))
    {
      left();                       // turn left
      while (distance() > BREADTH)
        followLine();
      ungrip();

      do {                            //180 degree turn
        rotate();
      } while (value() != 48 || value() != 120);

      while (value() != 252)        //  untill T is encountered
        followLine();
      right();                  //turn right
    }
    else
    {
      right();                  //turn right

      while (distance() > BREADTH)
        followLine();
      ungrip();

      do {                            //180 degree turn
        rotate();
      } while (value() != 48 || value() != 120);

      while (value() != 252)        //  untill T is encountered
        followLine();
      left();                       //turn left
    }


  }

  //last block
  while (distance() > MINDISTANCE)
    followLine();
  if !(colormatch(r[3], g[3], b[3]))
  {
    grip();

    do {                            //180 degree turn
      rotate();
    } while (value() != 48 || value() != 120);

    while (value() != 252)        //  untill T is encountered
      followLine();



    right();                       // turn right
    while (distance() > BREADTH)
      followLine();
    ungrip();

    do {                            //180 degree turn
      rotate();
    } while (value() != 48 || value() != 120);

    while (value() != 252)        //  untill T is encountered
      followLine();
    forward();                  //go straight

    while (distance() > BREADTH)
      followLine();

    1      grip();

    do {                            //180 degree turn
      rotate();
    } while (value() != 48 || value() != 120);

    while (value() != 252)        //  untill T is encountered
      followLine();
    right();

    while (distance() > BREADTH)
      followLine();
    ungrip();

    do {                            //180 degree turn
      rotate();
    } while (value() != 48 || value() != 120);

    while (value() != 252)        //  untill T is encountered
      followLine();

  }
  else
  {
    do {                            //180 degree turn
      rotate();
    } while (value() != 48 || value() != 120);

    while (value() != 252)        //  untill T is encountered
      followLine();
  }




  //2nd block

  for (i = 0; i < 3; i++)
  {
    right();

    while (distance() > BREADTH)
      followLine();
    grip();

    do {                            //180 degree turn
      rotate();
    } while (value() != 48 || value() != 120);

    while (value() != 252)        //  untill T is encountered
      followLine();

    if (colormatch(r[1], g[1], b[1]))
    {
      left();
      while (distance() > BREADTH)
        followLine();
      ungrip();

      do {                            //180 degree turn
        rotate();
      } while (value() != 48 || value() != 120);

      while (value() != 252)        //  untill T is encountered
        followLine();

    }

    else
    {
      forward();
      while (distance() > BREADTH)
        followLine();
      ungrip();

      do {                            //180 degree turn
        rotate();
      } while (value() != 48 || value() != 120);

      while (value() != 252)        //  untill T is encountered
        followLine();
      right();

      while (distance() > 5 * BREADTH)
        followLine();

      do {                            //180 degree turn
        rotate();
      } while (value() != 48 || value() != 120);

      while (value() != 252)        //  untill T is encountered
        followLine();

    }

  }



  //3rd Block


  left();
  while (distance() > BREADTH)
    followLine();
  grip();

  do {                            //180 degree turn
    rotate();
  } while (value() != 48 || value() != 120);

  while (value() != 252)        //  untill T is encountered
    followLine();

  if (colormatch(r[2], g[2], b[2]))
  {
    right();

    while (distance() > BREADTH)
      followLine();
    ungrip();

    do {                            //180 degree turn
      rotate();
    } while (value() != 48 || value() != 120);

    while (value() != 252)        //  untill T is encountered
      followLine();

    //4th block
    left();
    while (distance() > BREADTH)
      followLine();
    grip();

    do {                            //180 degree turn
      rotate();
    } while (value() != 48 || value() != 120);

    while (value() != 252)        //  untill T is encountered
      followLine();

    right();

    while (distance() > BREADTH)
      followLine();
    ungrip();

    do {                            //180 degree turn
      rotate();
    } while (value() != 48 || value() != 120);

    while (value() != 252)        //  untill T is encountered
      followLine();


  }

  else
  {
    forward();

    while (distance() > BREADTH)
      followLine();
    ungrip();

    do {                            //180 degree turn
      rotate();
    } while (value() != 48 || value() != 120);

    while (value() != 252)        //  untill T is encountered
      followLine();

    forward();
    while (distance() > BREADTH)
      followLine();
    grip();

    do {                            //180 degree turn
      rotate();
    } while (value() != 48 || value() != 120);

    while (value() != 252)        //  untill T is encountered
      followLine();

    right();

    while (distance() > BREADTH)
      followLine();
    ungrip();

    do {                            //180 degree turn
      rotate();
    } while (value() != 48 || value() != 120);

    while (value() != 252)        //  untill T is encountered
      followLine();

    right();

    while (distance() > BREADTH)
      followLine();
    grip();

    do {                            //180 degree turn
      rotate();
    } while (value() != 48 || value() != 120);

    while (value() != 252)        //  untill T is encountered
      followLine();

    left();

    while (distance() > BREADTH)
      followLine();
    ungrip();

    do {                            //180 degree turn
      rotate();
    } while (value() != 48 || value() != 120);

    while (value() != 252)        //  untill T is encountered
      followLine();


  }
}


