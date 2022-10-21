int human = -1;
int computer = 1;
char h_choice = 'X';
char c_choice = 'O';
char first = 'N';
int empt_len = 0;
int glbest = 0;
int board[9] = {
1,-1,1,
0,1,-1,
0,1,-1
};
int wins(int *board2, int player) {
  int win_state[8][3] = {
      {board2[0], board2[1], board2[2]}, {board2[3], board2[4], board2[5]},
      {board2[6], board2[7], board2[8]}, {board2[2], board2[4], board2[6]},
      {board2[2], board2[5], board2[8]}, {board2[0], board2[3], board2[6]},
      {board2[0], board2[4], board2[8]}, {board2[1], board2[4], board2[7]}};
  for (int i = 0; i < 8; i++) {
    int player_check[3] = {player, player, player};
    if (win_state[i][0] == player && win_state[i][1] == player &&
        win_state[i][2] == player) {
      return 1;
    }
  }
  return 0;
}
int evaluate(int *board2) {
  if (wins(board2, 1) == 1) {
    return 1;
  } else if (wins(board2, -1) == 1) {
    return -1;
  } else {
    return 0;
  }
}
void emptyCells(int *board2) {
  empt_len = 0;
  for (int e = 0; e < 9; e++) {
    if (board2[e] == 0) {
      empt_len += 1;
    }
  }
  return;
}
int gameOver(int *board2) {
  if (wins(board2, -1) == 1 || wins(board2, 1) == 1) {
    return 1;
  }
  return 0;
}
int validMove(int place) {
  if (board[place] == 0) {
    return 1;
  }
  return 0;
}
int setMove(int place, int player) {
  if (validMove(place) == 1) {
    board[place] = player;
    return 1;
  } else {
    return 0;
  }
}

// int potential;
// int best;
int potential_marker;
int potential_coord;

int minimax(int depth, int player, int *board2, int *coordinate) {
  int best;
  if (player == computer) {
    best = -4000;
  } else if (player == human) {
    best = 4000;
  }
  int best_coord = -1;

  if (depth == 0 || gameOver(board2) == 1) {
    return evaluate(board2);
  }
  for (int t = 0; t < 9; t++) {
    if (board[t] == 0) {
      int coord = -1;
      board2[t] = player;
      int potential = minimax(depth - 1, -player, board2, &coord);
      board2[t] = 0;
      coord = t;
      if (player == computer) {
        if (potential > best) {
          best = potential;
          best_coord = coord;
        }
      } else {
        if (potential < best) {
          best = potential;
          best_coord = coord;
        }
      }
    }
  }
  *coordinate = best_coord;
  return best;
}

void aiturn() {
  emptyCells(board);
  int depth = empt_len;
  int coord2;
  int move = 0;
  // struct Score move;
  if (depth == 0 || gameOver(board) == 1) {
    return;
  }
  if (depth == 9) {
    setMove(4, computer);
  } else {
    minimax(depth, computer, board, &move);
  }
  setMove(move, computer);
  printf("%d", move);
  return;
}
void humanturn(int move) {
  emptyCells(board);
  int mmove = -1;
  int depth = empt_len;
  if (depth == 0 || gameOver(board) == 1) {
    return;
  }
  // render the screen
  while (mmove < 1 || mmove > 9) {
    mmove = move;
    int can_move = setMove(mmove - 1, human);
    if (can_move == 0) {
      // BAD MOVE
      move = -1;
    } else {
    }
  }
}
int main() {
  emptyCells(board);
  // while(empt_len > 0 && gameOver() != 1){
  //     emptyCells();
  //     aiturn();
  //     humanturn(1);
  // }
  // if(wins(human) == 1){
  //     // render to screen
  //     //HUMAN WINS
  //   }
  // else if(wins(computer) == 1){
  //     // render to screen
  //     //AI WINS
  // }
  // else{
  //     // render the screen
  //     // DRAW
  // }

  // balls.coord = -1;
  // balls.marker = -1;
  aiturn();
  // printf("%d", balls);
  // evaluate(board);
  // minimax(6, computer, 0, board);
  // printf("%d", best_array[ARRAY_COUNTER]);
  // printf("OUTCOME: %d ", best_marker_array[glbest]);
  return 0;
}