from itertools import *
from copy import copy


def is_distinct( list ):
    '''Auxiliary function to is_solved
    checks if all elements in a list are distinct
    (ignores 0s though)
    '''
    used = []
    for i in list:
        if i == 0:
            continue
        if i in used:
            return False
        used.append(i)
    return True


def is_valid( brd ):
    '''Checks if a 3x3 mini-Sudoku is valid.'''
    for i in range(3):
        row = [brd[i][0],brd[i][1],brd[i][2]]
        if not is_distinct(row):
            return False
        col = [brd[0][i],brd[1][i],brd[2][i]]
        if not is_distinct(col):
            return False
    return True

def solve( brd , empties = 9):
    '''
      Solves a mini-Sudoku
      brd is the board
      empty is the number of empty cells
    '''

    if empties == 0:
        #Base case
        return is_valid( brd )
    for row,col in product(range(3),repeat=2):
        #Run through every cell
        cell = brd[row][col]
        if cell != 0:
            #If its not empty jump
            continue
        brd2 = copy( brd )
        for test in [1,2,3]:
            brd2[row][col] = test
            if is_valid(brd2) and solve(brd2,empties-1):
                return True
            #BackTrack
            brd2[row][col] = 0
    return False

Board = [ [ 0 , 0 , 0 ],
          [ 1 , 0 , 0 ],
          [ 0 , 3 , 1 ] ]
solve( Board , 9 - 3 )


for row in Board:#Prints a solution
    print (row)      
