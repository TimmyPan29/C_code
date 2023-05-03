#include <stdio.h>


void transpose(int p[3][3], int t[3][3]); //transpose會吃這兩筆回傳資料 把副程式模組include進來的意思

int main() {
  int i, j;
  int p[3][3], t[3][3];

  printf("Enter matrix P\n");
  fflush(stdout);

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("Enter the elements of matrix P [%d,%d]: ", i, j);
	  fflush(stdout);
      scanf("%d", & p[i][j]);
    }
  }
  
  transpose(p, t); //我準備要用副模組了 所以這裡我把處理過的data叫進來

  printf("Transpose of matrix P is:\n\n");
  fflush(stdout);

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%d ", t[i][j]);
	  fflush(stdout);
    }
    printf("\n");
	fflush(stdout);
  }

} //主程式結尾

void transpose(int p[3][3], int t[3][3]) { //副程式
  int row, col;

  for (row = 0; row < 3; row++) {
    for (col = 0; col < 3; col++) {
      t[row][col] = p[col][row];
    }
  }

}
