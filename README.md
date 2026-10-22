Mini Attendance Tracker:

A simple **C-based menu-driven console application** for managing student attendance during a single class session.

Project Description:

Mini Attendance Tracker allows the user to set the class size, mark students as **Present (P)** or **Absent (A)**, update individual attendance records, view attendance summaries, and display present or absent roll numbers.

The program is designed for a single session and does not permanently save attendance data.

Features:

- Set or change class size from **1 to 60 students**
- Mark attendance for all students
- Mark students as **Present (P)** or **Absent (A)**
- Update the attendance of a specific roll number
- Display present and absent roll-number lists
- Calculate present and absent counts
- Calculate attendance percentage
- Reset the current attendance session
- Accept both uppercase and lowercase `P/A`
- Validate invalid input and out-of-range roll numbers

Technologies Used:

- **Language:** C
- **Compiler:** MinGW-GCC
- **IDE:** Dev-C++
- **Standard:** C11
- **Data Structure:** 1D character array
- **Input Handling:** `fgets()` and `sscanf()`

C Concepts Used:

- Arrays
- Functions
- `for` and `while` loops
- `if/else` statements
- `switch-case`
- Character handling using `toupper()`
- Input validation
- Formatted output

How It Works

1. Set the required class size.
2. Mark each student's attendance as `P` or `A`.
3. View the attendance summary.
4. View present or absent roll numbers.
5. Update an individual student's status when required.
6. Reset the session when starting a new attendance session.

How to Run

Compile `main.c` using a C compiler such as GCC/MinGW.

Example:

```bash
gcc main.c -o attendance
```

Then run the program:

```bash
attendance
```

On Windows, the generated executable can also be run as:

```bash
attendance.exe
```

 Project Structure

```text
mini-attendance-tracker/
│
├── main.c
└── README.md
```

Project Limitations

- Attendance is stored only during the current program session.
- Data is not saved to a file or database.
- Maximum class size is 60 students.
- The application is console-based.


 Project

**Mini Attendance Tracker**

C Programming Mini Project
