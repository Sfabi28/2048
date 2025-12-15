# 2048 - Terminal Edition 🎮

![C](https://img.shields.io/badge/Language-C-00599C?style=flat&logo=c&logoColor=white)
![Ncurses](https://img.shields.io/badge/Library-Ncurses-green)
![42](https://img.shields.io/badge/School-42-black)

A robust and feature-rich implementation of the **2048** game for the terminal, developed as a **Rush** project at 42.

## ✨ Features

### 🔹 Core Gameplay (Mandatory)
* **Game Logic**: Authentic movement, merging rules, and random spawning (2 or 4).
* **Win/Loss**: Detects **2048** victory (with option to continue) and Game Over states.
* **Stability**: Handles window resizing signals (`SIGWINCH`) seamlessly.

### 🔸 Bonus Extensions
* **Dynamic Grid**: Choose between **4x4** (Classic) and **5x5** (Big Board) via Settings.
* **Visuals**: Custom **ASCII Art** font for numbers, box-drawing borders, and dynamic **Colors** (cold to hot gradient).
* **Persistence**: Independent **High Scores** saved for each grid size (`.best_score_4`, `.best_score_5`). Scores are saved in real-time to prevent data loss.

## 🛠️ Installation & Usage

### 1. Requirements
* GCC, Make
* `libncurses` (standard on macOS/Linux)
* `libft` and `ft_printf` (Ensure they are accessible as per Makefile)

### 2. Build
```bash
git clone https://github.com/Sfabi28/2048.git
cd 2048/mandatory
make
./2048
```

### 2.5 Bonus Build
```bash
git clone https://github.com/Sfabi28/2048.git
cd 2048/bonus
make
./2048
```

### 3. Controls
Key,Context,Action
<kbd>↑</kbd> <kbd>↓</kbd> <kbd>←</kbd> <kbd>→</kbd>,Game,Move tiles / Merge numbers
<kbd>↑</kbd> <kbd>↓</kbd>,Menu,Navigate options
<kbd>1</kbd> / <kbd>2</kbd>,Menu,Quick select (Start / Settings)
<kbd>ESC</kbd>,Global,Return to Menu / Quit Game
<kbd>ENTER</kbd>,Win,Continue playing after 2048

### 4. Valgrind

valgrind --leak-check=full --show-leak-kinds=all --suppressions=ignore_ncurses.supp ./2048
