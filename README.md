# 📝 ft_printf

<div align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c&logoColor=white" alt="Language">
  <img src="https://img.shields.io/badge/Standard-C99-green?style=for-the-badge" alt="Standard">
  <img src="https://img.shields.io/badge/Status-Completed-success?style=for-the-badge" alt="Status">
</div>

## 📋 Overview

**ft_printf** is a custom implementation of the famous `printf` function from the C standard library. This project demonstrates deep understanding of **variadic functions**, **string manipulation**, and **format specifiers**.

## ✨ Features

### Supported Format Specifiers:
- `%c` - Character
- `%s` - String  
- `%p` - Pointer address
- `%d` - Decimal integer
- `%i` - Integer
- `%u` - Unsigned decimal
- `%x` - Lowercase hexadecimal
- `%X` - Uppercase hexadecimal
- `%%` - Literal percent sign

### Key Capabilities:
- **Memory safe** implementation
- **Exact return value** matching original printf
- **Null pointer handling** for strings and pointers
- **Edge case management** (negative numbers, zero values)
- **Efficient parsing** of format strings


## 🚀 Usage

### Compilation
```bash
make
``
### Compilation with your project
```bash
cc -Wall -Wextra -Werror your_file.c libftprintf.a
```

## 📚 Resources & References

- [Printf Manual](https://man7.org/linux/man-pages/man3/printf.3.html)
- [Variadic Functions in C](https://en.cppreference.com/w/c/variadic)
- [C Standard Library](https://en.wikipedia.org/wiki/C_standard_library)

---

<div align="center">
  
**"The devil is in the details, but so is the salvation."** - Hyman Rickover

</div>
