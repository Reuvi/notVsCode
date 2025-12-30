# notVsCode

A command line text editor that is not vscode.

## Technical Highlights

- Manual terminal raw-mode configuration. (no ncurses)
- Full ANSI escape-sequence parsing for navigation and cursor control.
- Single-frame render pipeline using a custom append buffer. (one write() sys call per refresh)
- Dual row representation. (raw text buffer and a rendered buffer)
- Precise cursor math with tab expansion and render-space mapping.
- Viewport-aware rendering with horizontal and vertical scrolling.
- Guaranteed terminal state restoration on exit or error.

### Editor Safety and UX

- Multi-step quit confirmation when unsaved changes exist.
- Status bar and timed status messages for user feedback.
- Graceful recovery from I/O or terminal failures.
- Cursor position preserved across searches and canceled prompts.

### Search

- Live incremental search while typing.
- Directional navigation through matches using arrow keys.
- Search state resets cleanly on exit or cancel.

### Terminal Compatibility

- Works across Linux terminals, macOS terminals, and Windows WSL
- Fallback cursor position detection using ANSI queries when `ioctl` fails.
- Handles multi-byte escape sequences for special keys. (arrows, page keys, home/end)

### Rendering Model

- Flicker-free rendering via off-screen buffering.
- Seperate logical cursor position and rendered cursor position.

### File Handling

- Safe file loading with newline normalization
- Atomic save behavior using truncate-then-write
- Dirty-state tracking to detect unsaved changes.

# Controls

\-Ctrl-K to quit.

\-Ctrl-S to save.

\-Ctrl-L to refresh.

\-Ctrl-N to search.

\-ESC used to exit the editorPrompt in most scenarios.

\-Arrow Up, Down, Left, Right to move around cursor.

\-Pg-Up (and Mac varients) to bring cursor to top of prev page (or top of first page).

\-Pg-Down (and Mac varients) to bring cursor to bottom of next page (or bottom of last page).

\-Home (and Mac varients) to bring cursor to left-end of text line.

\-End (and Mac varients) to bring cursor to right-end of text line.

\-./notVsCode fileName opens a file with path fileName. If filename occluded, editor will prompt for you to create a fileName for it.

\-Return creates a new line.

\-Backspace deletes the previous character.

\-DEL key deletes the character highlighted by the cursor.

## Why Did I make this?

- I wanted to understand how real text editors work at the terminal level.
- Focussed on low-level input handling, rendering, and memory management.

# Attribution

I followed this snaptoken book/walkthrough before I customized it -> https://viewsourcecode.org/snaptoken/kilo/index.html
