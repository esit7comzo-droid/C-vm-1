🖥️ EPS VM (Fake GRUB + Einux)

A C-based virtual environment that simulates a bootloader (GRUB-like UI) and a minimal OS with a custom package system.

---

✨ Features

- Fake GRUB boot screen
- Custom boot command system
- Einux (lightweight simulated OS)
- Built-in shell ("eps@localhost>")
- Package manager system:
  - "repo- [URL]"
  - "repo install- [package]"
- ".eps" package format (tar-based)
- Automatic:
  - Download
  - Extract
  - Compile (C)
  - Execute

---

🚀 Boot Flow

Welcome to GRUB!
(화면 지움)
eps:>

select EPI-4090b
→ EPI 4090 address has been selected.

boot to 4090
→ Einux 로고
→ 5초 후
eps@localhost>

---

📦 Package System

Set Repository

repo- http://your-server.com/packages

Install Package

repo install- hello

Package Structure

hello.eps
 └── hello.c

---

⚙️ Build

🔹 Linux / Termux

pkg install clang cmake
mkdir build
cd build
cmake ..
make
./eps

---

🔹 Windows

cmake .
cmake --build .
eps.exe

---

📁 Project Structure

.
├── main.c
├── CMakeLists.txt
└── README.md

---

🛠️ Requirements

- C compiler (gcc / clang)
- CMake
- wget or curl
- tar

---

💡 Example Package

hello.c

#include <stdio.h>

int main() {
    printf("Hello from EPS package!\n");
    return 0;
}

Create Package

tar -cf hello.eps hello.c

---

📜 License

This project is licensed under the MIT License.

---

⚠️ Disclaimer

This is NOT a real operating system or bootloader.
It is a simulation for learning and fun purposes.

---

😎 Future Plans

- ncurses UI (real OS feel)
- Advanced package manager
- Multi-file package support
- Network repo improvements
- QEMU auto integration

inquiry: admin@epsomm.kro.kr
