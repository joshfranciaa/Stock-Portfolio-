# 📈 Stock Portfolio Project  
A C++ program that simulates stock orders, users, and firm portfolios using OOP principles, dynamic memory, operator overloading, and file processing.

---

## 🎥 Demo Video  
Click below to watch the project demo:

[▶️ **Watch Demo Video**](Stock%20Portfolio%20Test.mp4)

---

## 🚀 Features  
- Handles stock orders with price, quantity, and total value  
- Supports multiple users  
- Operator overloading (`+`, `++`, `>`, `<`, `=`)  
- Combines firms and compares order counts  
- Dynamic memory allocation for orders  
- Writes formatted output to a file (`firm_info.txt`)  
- Reads data back and displays portfolio summaries  

---

## 🛠️ Technologies Used  
- **C++**  
- **Object-oriented programming**  
- **Vectors & dynamic allocation**  
- **Git LFS** for large video support  
- **File handling (ifstream/ofstream)**  

---

## 📂 Files Overview  
- `main.cpp` — program entry point  
- `COrderImp.cpp` / `COrder.h` — order class  
- `CUserImp.cpp` / `CUser.h` — user class  
- `CFirmImp.cpp` / `CFirm.h` — firm class  
- `CFileImp.cpp` / `CFile.h` — file output class  
- `firm_info.txt` — generated portfolio report  

---

## ▶️ Running the Program  
Compile with:

```sh
make
./main < input.txt
