#Minimax C 
Minimax C is a C implementation of the minimax algorithm, a recursive backtracking algorithm that is here used to determine the best possible move in tic tac toe.

Using a special algorithm, the computer is able to look through every possible move and map out which position gives it the ultimate edge, returning that position to the user.

**YOU CAN TRY IT YOURSELF!**
by modifying the below variable in the code, you are able to ask the program for the optimal move of any tic tac toe situation. Below, the **-1 represents the human player, or the opponent**, and the **1 represents the computer**. **0 means blank space**.

*int board[9] = {
-1,-1,0,
0,0,0,
0,0,0
};

This value of board is default, and simply exists to prove that the algorithm does in fact work, by choosing to place a piece at position 3, also known as index 2, blocking a potential win by the opponent.
