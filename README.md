# Smart-Library-Management-System
## Student names and roll numbers: Muhammad Daniyal Siddiqui(25K-0644) Huzaifa Bin Faisal(25K-0746)

# C++ Library Management System

An Object-Oriented, modular, and menu-driven Library Management System built in C++. This project demonstrates core OOP concepts (Inheritance, Polymorphism, Encapsulation, Abstraction) and features a persistent local data storage system using file handling.

## 📌 Use Cases
This system supports the following core use cases:
1. **Library Inventory Management:** Librarians or admins can add new books to the library system, assigning unique IDs automatically.
2. **User Registration & Authentication:** New users can register for an account and log in/out of the system to manage their active sessions.
3. **Book Borrowing System:** Logged-in users can borrow available books. The system automatically updates the book's availability status and logs the transaction.
4. **Book Return System:** Users can return borrowed books, making them available in the library once again for other readers.
5. **Transaction Tracking:** Every borrow and return action is securely logged with a unique transaction ID, capturing the user details, book details, and transaction type.
6. **AI Book Recommendation:** Logged-in users can request a randomized "AI" book recommendation from the library's current available inventory.
7. **Persistent Data Storage:** System state (books, users, and availability/login statuses) is saved to local text files (`books.txt` and `users.txt`) upon exit and reloaded on the next startup.

---

## 🛠️ Instructions to Compile the Project

Because this project uses a modular design (separate `.h` and `.cpp` files), you must compile all source files together.

**Using G++ (via Command Line / Terminal):**
1. Open your terminal or command prompt.
2. Navigate to the directory containing the project files.
3. Run the following command to compile all `.cpp` files into a single executable:
   ```bash
   g++ *.cpp -o library_system


  ## Instructions to Run the Project

After successfully compiling the code, a new executable file will be generated in your project folder. You can run it directly from your terminal using the following command based on your operating system:

* **Windows:**
  cmd
  .\library_system.exe


  ## Instructions to use the system
  
  Once the program is running, you will be greeted by an interactive Command Line Interface (CLI) menu. Follow the on-screen prompts by typing the corresponding number and pressing Enter.
  1.Initial Setup: On the first run, choose option 1 (Add a Book) and 2 (Register a User) to populate the system with data.
  2.Logging In: Before borrowing a book or getting an AI recommendation, you must log in. Press 3 and enter the User ID assigned to you during registration.
  3.Borrowing/Returning: Select 5 to borrow a book (you will need your User ID and the target Book ID). Select 6 to return it.
  4.Saving Progress: Do not close the console window forcefully. To ensure your library inventory and user accounts are saved to books.txt and users.txt, always exit the program gracefully by selecting option 8.

  ## Assumptions
  - Trust-Based Inputs: The system assumes the user provides the correct data types (e.g., entering an integer when asked for an ID). Entering letters when numbers are expected is caught by a basic fail-safe, but complex invalid inputs may cause unexpected behavior.
  - Plaintext Storage: For simplicity and demonstration purposes, passwords and user data are stored in plaintext in the users.txt file.
  - Fixed Library Capacity: The MainLibrary object instantiated in main() is assumed to have a fixed initial physical capacity for books, users, and branches.

  ## Limitations
  - Fixed Array Limits: The system currently relies on fixed-size pointer arrays (e.g., Book*[100], User*[100], and Transaction transactions[100]). The system cannot hold more than 100 books, users, or transactions per session without triggering a capacity error.
  - Basic Search/Matching: Searching for users and books is done sequentially using raw IDs. There is no hash map or binary search optimization for large datasets.
  - Simulated AI: The "AI Book Recommendation" feature uses the <random> library to simulate an AI decision by picking a random available book. It does not use machine learning or analyze user reading history.
  - Single-Session Transactions: Transaction logs are currently kept in memory and displayed in the console. They are not written to a persistent text file; only the library inventory and user base are saved to the disk upon exit.

Connect with me on Linkedin: https://www.linkedin.com/in/mds970?utm_source=share_via&utm_content=profile&utm_medium=member_android
