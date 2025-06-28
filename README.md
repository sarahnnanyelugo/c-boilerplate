# C Input Utilities Boilerplate
This project provides a simple C boilerplate with reusable input functions (`get_int`, `get_double`, `get_string`, `get_bool`, `get_char`, `get_float`) for safe and user-friendly input handling.

## Getting Started

### 1. Fork and Clone the Repository

First, fork the repository to your own GitHub account using the "Fork" button on the repository page. Then, clone your forked repository:

```sh
git clone https://github.com/YOUR-USERNAME/c-boilerplate.git project-name
cd project-name
```
Replace `YOUR-USERNAME` with your GitHub username.

### 2. Build the Project

You must compile both `main.c` and `input_utils.c` together, since the input functions are implemented separately from your main program.

#### Using gcc

```sh
gcc main.c input_utils.c -o myprogram
```

#### Using make

If a `Makefile` is provided, simply run:

```sh
make
```

### 3. Run the Program

After building, run the executable:

```sh
./myprogram
```

### 4. Project Structure

- `main.c` — Example usage of the input utility functions.
- `input_utils.h` — Declarations for all input functions.
- `input_utils.c` — Implementations of the input functions.

### 5. Extending the Boilerplate

You can add your own logic to `main.c` or create new files as needed. Use the input functions for safe and consistent user input.

---

Feel free to open issues or pull requests if you have suggestions or improvements.

Credit: [@hexxondiv](https://github.com/hexxondiv)
