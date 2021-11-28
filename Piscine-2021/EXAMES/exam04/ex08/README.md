```
======================================./4-5-check_mate.txt=========================================
Assignment name  : checkmate 
Expected files   : *.c, *.h
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program who takes rows of a chessboard in argument and check if your 
King is in a check position.

Chess is played on a chessboard, a squared board of 8-squares length with 
specific pieces on it : King, Queen, Bishop, Knight, Rook and Pawns.
For this exercice, you will only play with Pawns, Bishops, Rooks and Queen...
and obviously a King.

Each piece have a specific method of movement, and all patterns of capture are
detailled in the examples.txt file.

A piece can capture only the first ennemy piece it founds on its capture
patterns.

The board have a variable size but will remains a square. There's only one King
and all other pieces are against it. All other characters except those used for
pieces are considered as empty squares.

The King is considered as in a check position when an other enemy piece can
capture it. When it's the case, you will print "Success" on the standard output
followed by a newline, otherwise you will print "Fail" followed by a newline.

If there is no arguments, the program will only print a newline.

Examples:

$> ./check_mate '..' '.K' | cat -e
Fail$
$> ./check_mate 'R...' '.K..' '..P.' '....' | cat -e
Success$
$> ./check_mate 'R...' 'iheK' '....' 'jeiR' | cat -e
Success$
$> ./check_mate | cat -e
$
$>
*************************************************
Some subject.en.txts on the web have this example:
$> ./chessmate 'R...' '..P.' '.K..' '....' | cat -e
Success$
Which would indicate that checks need to be down both ways.
Most solutions will:
Fail$
As they are only checking in one direction.
*************************************************
==========================================================================================


```
