# Numerical Analysis Methods - Term Project

**Yıldız Technical University**  
**BLM1022 - Numerical Analysis**  
**2024-2025 Spring Semester - 1st Year Term Project**

---

## 📌 About This Project

This project is a comprehensive tool that implements fundamental numerical analysis methods using the C programming language. It's an interactive console application that can parse mathematical functions and perform calculations using 10 different numerical methods.

## ✨ Features

### 🔧 Implemented Numerical Methods

1. **Bisection Method** - Root finding
2. **Regula-Falsi (False Position) Method** - Root finding
3. **Newton-Raphson Method** - Root finding
4. **Inverse Matrix** - Linear equation systems
5. **Cholesky (LU Decomposition) Method** - Matrix decomposition
6. **Gauss-Seidel Method** - Iterative equation solving
7. **Numerical Differentiation** - Forward, backward, and central difference
8. **Simpson's Rule** - Numerical integration (1/3 and 3/8)
9. **Trapezoidal Rule** - Numerical integration
10. **Gregory-Newton Interpolation** - Polynomial interpolation

### 🎯 Core Capabilities

- **Mathematical Expression Parser**: Accepts and evaluates complex mathematical functions as strings
- **Supported Functions**:
  - Trigonometric: `sin(x)`, `cos(x)`, `tan(x)`, `cot(x)`
  - Inverse Trigonometric: `arcsin(x)`, `arccos(x)`, `arctan(x)`, `arccot(x)`
  - Logarithmic: `log(x)`, `log_n(x)` (for any base n)
  - Exponential: `exp(x)`, `e^x`, `2^x`
  - Constants: `pi`, `e`
- **Interactive User Interface**: Menu-driven easy-to-use interface
- **Detailed Iteration Information**: Computation details at each step

## 🚀 Installation and Running

### Requirements

- GCC or any C compiler
- `math.h` library support

### Compilation

```bash
gcc numerical_analysis.c -o numerical_analysis -lm
```

### Running

```bash
./numerical_analysis
```

For Windows:
```bash
numerical_analysis.exe
```

## 📖 Usage

When you start the program, you'll be greeted with a menu:

```
---------------------------------------------------------
Quit: 0
Bisection: 1
Regula-Falsi: 2
Newton-Raphson: 3
Inverse Matrix: 4
Cholesky Method: 5
Gauss-Seidal: 6
Numerical differentiation: 7
Simpson's Rule: 8
Trapezoidal Rule: 9
Gregory-Newton: 10
---------------------------------------------------------
```

### Example Usage

#### Root Finding (Bisection Method):
```
Which operation do you want to do? 1
Please enter your function:
> x^3 - 2*x - 5
Enter a value: 2
Enter b value: 3
Enter max error: 0.0001
Enter maximum iterations: 100
```

#### Numerical Differentiation:
```
Which operation do you want to do? 7
Please enter your function:
> sin(x) + x^2
At what x value do you want to calculate the derivative? 1.5
What will be the h value? (recommended to be small like 0.0001) 0.0001
```

#### Simpson Integration:
```
Which operation do you want to do? 8
Please enter your function:
> x^2 + 2*x + 1
Lower limit of the integration? 0
Upper limit of the integration? 2
How many parts do you want to split the integral into? 10
```

## 📁 Project Files

- `numerical_analysis.c` - Main source code
- `examples.pdf` - Solved example problems
- `project_report.pdf` - Detailed project report and methodology
- `README.md` - Project documentation

## 🔍 Mathematical Expression Syntax Rules

- **Variable**: Use `x`
- **Exponentiation**: `^` operator (e.g., `x^2`, `2^x`)
- **Multiplication/Division**: `*` and `/`
- **Addition/Subtraction**: `+` and `-`
- **Parentheses**: `(` and `)` are supported
- **Trigonometric functions**: Work in radians
- **Special constants**: `pi` ≈ 3.14159, `e` ≈ 2.71828

### Example Functions:
- `x^3 - 2*x + 1`
- `sin(x) + cos(2*x)`
- `log(x) + x^2`
- `exp(x) - 3*x`
- `(x+1)*(x-2)/(x+3)`

## 🛠️ Technical Details

### Data Structures

The program represents mathematical expressions using **Abstract Syntax Tree (AST)**:

```c
typedef enum {
    NODE_CONSTANT,    // Constant values
    NODE_VARIABLE,    // Variables (x)
    NODE_OPERATOR,    // +, -, *, /, ^
    NODE_FUNCTION     // sin, cos, log, etc.
} NodeType;
```

### Parser Architecture

Mathematical expressions are parsed using recursive descent parsing:
- `addsub_parser()` - Addition/subtraction
- `muldiv_parser()` - Multiplication/division
- `exp_parser()` - Exponentiation
- `parse_primary()` - Primary expressions (numbers, variables, functions)

## 📊 Performance and Precision

- **Maximum iterations**: User-definable
- **Error tolerance**: Adjustable (e.g., 1e-6, 1e-10)
- **Memory management**: Dynamic memory allocation for flexible matrix sizes
- **Numerical stability**: Pivot selection and condition checking

## 🐛 Known Limitations

- Functions work only with single variable (`x`)
- Trigonometric functions operate in radian mode
- Matrix operations require square matrices
- Gregory-Newton requires equally spaced points

## 📚 References

The algorithms and methods used in this project are taken from standard numerical analysis sources:
- Numerical Analysis (Burden & Faires)
- Numerical Methods for Engineers (Chapra & Canale)
- BLM1022 Numerical Analysis Course Notes

## 👨‍💻 Developer

**Yıldız Technical University**

Aziz Eren YILDIRIM  
Computer Engineering - 1st Year  
2024-2025 Spring Semester

## 📄 License

This project is licensed under the MIT License. See the `LICENSE` file for details.

---

## 🤝 Contributing

This is a student project. Feel free to open issues or submit pull requests for suggestions and improvements.

## ⭐ Support

If you like this project, don't forget to give it a star! ⭐

---

**Note**: This project is for educational purposes and was developed as part of the Numerical Analysis course at Yıldız Technical University.
