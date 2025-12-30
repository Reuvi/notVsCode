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

\* Standard writing in a text editor implementation.

\* Created simple incremental search.

# Features

\-Ctrl-K to quit.

\-Ctrl-S to save.

\-Ctrl-L to refresh.

\-Ctrl-N to search.

\-Arrow Up, Down, Left, Right to move around cursor.

\-Pg-Up (and Mac varients) to bring cursor to top of prev page (or top of first page).

\-Pg-Down (and Mac varients) to bring cursor to bottom of next page (or bottom of last page).

\-Home (and Mac varients) to bring cursor to left-end of text line.

\-End (and Mac varients) to bring cursor to right-end of text line.

\-./notVsCode fileName opens a file with path fileName. If filename occluded, editor will prompt for you to save it with a selected filename on save.

\-Return creates a new line.

\-Backspace deletes the previous character.

\-DEL key deletes the character highlighted by the cursor.

# Attribution

Original project followed this snaptoken book before I customized it -> https://viewsourcecode.org/snaptoken/kilo/index.html
