# notVsCode

A command line text editor to replace vscode.

# Implementation

Written in C.
Works on Linux Enviroments. (any linux distro, macOS, windows wsl)

\*Terminal set to 'Raw Mode'.

\*Refreshes screen after every input using one call to write. (custom append buffer made for processing)

\*Processes keycodes based on their raw value including escape codes. (multi-byte sequences)

\*Error handling present throughout for smooth exit.

# Features

\-Cntl-L to quit.

\-Arrow Up, Down, Left, Right to move around cursor.

\-Pg-Up (and Mac varients) to bring cursor to top of screen.

\-Pg-Down (and Mac varients) to bring cursor to bottom of screen.

\-Home (and Mac varients) to bring cursor to left-end of screen.

\-End (and Mac varients) to bring cursor to right-end of screen.

\-./notVsCode fileName opens a file with path fileName. If fileName is excluded creates new FD for you to save a name to on exit.
