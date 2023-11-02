#include <iostream>
#include <vector>

using namespace std;

// Khai báo cấu trúc ô bàn cờ
struct Cell {
  char value;
  bool isOccupied;
};

// Khai báo lớp bàn cờ
class Board {
public:
  // Hàm khởi tạo
  Board(int n) {
    board_ = vector<vector<Cell>>(n, vector<Cell>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        board_[i][j].value = ' ';
        board_[i][j].isOccupied = false;
      }
    }
  }

  // Hàm đọc bàn cờ từ tệp
  void ReadBoard(char *path) {
    fstream f(path);
    int n;
    f >> n;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        f >> board_[i][j].value;
        if (board_[i][j].value == 'O' || board_[i][j].value == 'X') {
          board_[i][j].isOccupied = true;
        }
      }
    }
  }

  // Hàm kiểm tra xem ô (i, j) có bị bao vây hay không
  bool IsCellSurrounded(int i, int j) {
    // Kiểm tra các ô xung quanh
    for (int x = i - 1; x <= i + 1; x++) {
      for (int y = j - 1; y <= j + 1; y++) {
        if (x >= 0 && x < board_.size() && y >= 0 && y < board_[0].size()) {
          if (board_[x][y].value == board_[i][j].value) {
            return false;
          }
        }
      }
    }
    return true;
  }

  // Hàm tính diện tích vùng đất của quân trắng và đen
  int CountArea(char value) {
    int area = 0;
    for (int i = 0; i < board_.size(); i++) {
      for (int j = 0; j < board_[0].size(); j++) {
        if (board_[i][j].value == value && board_[i][j].isOccupied) {
          area++;
          // Di chuyển quân trắng bị bao vây sang quân đen
          if (value == 'O' && IsCellSurrounded(i, j)) {
            board_[i][j].value = 'X';
          }
        }
      }
    }
    return area;
  }

  // Hàm trả về bên thắng cuộc
  int GetWinner() {
    int area_white = CountArea('O');
    int area_black = CountArea('X');
    if (area_white > area_black) {
      return 1;
    } else if (area_white < area_black) {
      return -1;
    } else {
      return 0;
    }
  }

private:
  // Mảng lưu trữ bàn cờ
  vector<vector<Cell>> board_;
};

int main() {
  // Đọc bàn cờ từ tệp
  Board board(5);
  board.ReadBoard("input.txt");

  // Xác định bên thắng cuộc
  int winner = board.GetWinner();

  // In kết quả
  if (winner == 1) {
    cout << "Quân trắng thắng." << endl;
  } else if (winner == -1) {
    cout << "Quân đen thắng." << endl;
  } else {
    cout << "Hai bên hòa." << endl;
  }
  return 0;
}