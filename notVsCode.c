/*** includes ***/

#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <errno.h>

/*** data ***/

struct termios orig_termios;

/*** terminal ***/

void die(const char *s) {
  perror(s);
  exit(1);
}

void disableRawMode() {
  if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios) == -1) {
    die("tcsetattr");
  }
}

void enableRawMode() {
  if (tcgetattr(STDIN_FILENO, &orig_termios) == -1) die("tcgetattr");
  atexit(disableRawMode);

  //Saves old setting and copys to raw struct
  struct termios raw = orig_termios;
  
  // Input Flags
  // Turns off Control S and Control Q which are software flow control
  // Turn off control M defaulting to new lines from terminal assuming carraige returns are newlines
  // if BRKINT is on a break condition will cause sigInt to be sent
  // INPCK enables parity checking which doesnt apply to modern terminal emulators
  // ISTRIP causes the 8th but of each byte to be stripped meaning it will be set to 0, we turn t off
  raw.c_iflag &= ~(IXON | ICRNL | BRKINT | INPCK | ISTRIP);

  // Local Flags for the Terminal

  //We want to disable any outside functionalitys of our keywords

  //Echo Turns off Echoing what we type into the terminal
  //ICANON turns off line by line reading from STDIN into byte by byte
  //ISIG turns off sig handlers from cntrlC and cntrlZ
  //Control V on terminals doesnt always paste, it sents out the byte of the next thing you send
  //For example contrl V contrl C would give you the 3 byte
  raw.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);

  // This is a bit mask with multiple bits which we set using the bitwise OR. It sets the characterSize to 8 bits per byte
  // Default is 8 but we had to make sure
  raw.c_cflag |= (CS8);

  //Output Flags
  //Turns off newlines being formatted as \r\n which is a carraige return
  raw.c_oflag &= ~(OPOST);

  // VMIN sets min number of bytes needed before read can return
  // VTIME is max amount of time to wait before read returns it is is 10ths of a second or 100 milliseconds
  raw.c_cc[VMIN] = 0;
  raw.c_CC[VTIME] = 1;
  if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) die("tcsetattr");
}

/*** init ***/

int 
main() {
  enableRawMode();
  while(1) {
    char c = '\0';
    // In Cygwin if read time out it returns neg 1 with EAGAIN set, we check for this weird case
    if (read(STDIN_FILENO, &c, 1) == -1 && errno != EAGAIN) die("read");
    if (iscntrl(c)) {
      printf("%d\r\n", c);
    } else {
      printf("%d ('%c')\r\n", c, c);
    }
    if ( c == 'q') break;
  }
  return 0;
}