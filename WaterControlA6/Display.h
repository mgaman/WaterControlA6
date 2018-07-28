void displayInit();
struct sU8item {
  int x,y;   // position
  char *s;   // string
};
void displayAddLine(int, char *);
#define SCREEN_ROWS 3
#define SCREEN_COLS 16
void displayShow();

