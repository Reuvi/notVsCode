# notVsCode

A command line text editor that is not vscode.

# Implementation

Written in C.
Works on Linux Enviroments. (any linux distro, macOS, windows wsl)

\*Terminal set to 'Raw Mode'.

\*Refreshes screen after every input using one call to write. (custom append buffer made for processing)

\*Rendered rows formated from configurable presets of special characters in the text buffer.

\*Horizontal and Vertical scrolling.

\*Horizontal and Vertical cursor line jumping at end of lines.

\*Processes keycodes based on their raw value including escape codes. (multi-byte sequences)

\*Error handling present throughout for smooth exit.

\* Status Bar and Status Message appended to bottom of text editor with action/file information.

# Features

\-Cntl-L to quit.

\-Arrow Up, Down, Left, Right to move around cursor.

\-Pg-Up (and Mac varients) to bring cursor to top of prev page (or top of first page).

\-Pg-Down (and Mac varients) to bring cursor to bottom of next page (or bottom of last page).

\-Home (and Mac varients) to bring cursor to left-end of text line.

\-End (and Mac varients) to bring cursor to right-end of text line.

\-./notVsCode fileName opens a file with path fileName. If fileName is excluded creates new FD for you to save a name to on exit.
