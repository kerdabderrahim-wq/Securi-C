# Securi-C: Security Utility Library Suite

**Securi-C** is a comprehensive C library suite designed for cybersecurity tasks, education, and analysis. It provides a modular command-line interface (CLI) and a graphical user interface (GUI) for various security operations including encryption, user management, and auditing.

**Academic Year:** 2025/2026  
**Developed by:** Kerd Abderrahim & Akeb Abdelkarim (Group B03)  
**Supervised by:** Dr. Berghout Yasser

---

## 🚀 Features

The project is organized into several core modules:

1.  **Encryption & Decryption Library**
    - Cesar, XOR, and Substitution ciphers.
    - Message analysis (frequency, coincidence index).
    - String utilities (case conversion, reverse, remove spaces).

2.  **Mathematical & Security Tools**
    - Prime checking, GCD, LCM, Modular Exponentiation.
    - Matrix operations (Add, Multiply, Transpose, Determinant).
    - Array statistics and number theory tools.

3.  **User Management System**
    - User CRUD operations (Add, Delete, Search, Update).
    - Role management (Admin/User).
    - Password strength analysis and policy enforcement.
    - Data persistence (Save/Load users).

4.  **Security Audit and Analysis**
    - Password security reporting.
    - Key generation (Hex, Random).
    - Email and login format validation.
    - Global security level assessment.

5.  **Log Management & Monitoring**
    - Activity logging (Logins, Errors, Suspicious Activity).
    - Log analysis and statistics.
    - CSV Import/Export.

---

## 🛠️ Requirements

To build and run this project, you need:

-   **GCC** (GNU Compiler Collection)
-   **Make** (Build automation tool)
-   **GTK+ 3.0** (Required for the GUI version)
    -   *Windows:* Install via MSYS2 or similar environment.
    -   *Linux:* `sudo apt-get install libgtk-3-dev`

---

## 📦 Compilation & Usage

This project uses a `Makefile` for easy compilation.

### 1. Build All (CLI & GUI)
```bash
make
```

### 2. Build CLI Only
```bash
make cli
```

### 3. Build GUI Only
```bash
make gui
```

### 4. Clean Build Files
Remove executables to start fresh:
```bash
make clean
```

---

## 🖥️ Running the Application

### Command Line Interface (CLI)
Run the main executable to access the interactive menu:
```bash
./cli.exe
```
*Note: Use `cli` on Linux/Mac if the extension differs.*

### Graphical User Interface (GUI)
Launch the graphical dashboard:
```bash
./gui.exe
```

---
*Developed for the "Algorithmic & Data Structures" project at NSCS, Algeria.*
