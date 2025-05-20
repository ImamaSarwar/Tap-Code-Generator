# Tap Code Generator/Converter
This C++ project provides a simple, console-based application for converting text to Tap Code and vice-versa. It implements the classic Polybius Square cipher for encoding and decoding messages using only numerical sequences, represented visually by 'taps'.
## Constraints:
- No std::string: All string operations, including length calculation, concatenation, and manipulation, are performed using raw char arrays and manual null-termination.
- No Inbuilt String Functions: Functions like strlen, strcpy, strcat, etc., from the <cstring> library were avoided. Custom implementations were written from scratch, enhancing algorithmic thinking, problem-solving, and a deeper understanding of string manipulation in C++.
## Features
### String to Tap Code Conversion
- Converts an alphabetic string into its corresponding Tap Code representation
### Tap Code to String Conversion
- Deciphers a numeric Tap Code sequence back into its original alphabetic string.
### Visual Tap Code Representation
- Displays the generated Tap Code visually using asterisks, mimicking the "tapping" action
### Input Validation
- Basic validation for both alphabetic and numeric inputs ensures correct usage.
### Polybius Square Implementation
- Utilizes a 5x5 Polybius square to map characters to their numerical coordinates.
### Polybius Square:
![square](https://github.com/ImamaSarwar/Tap-Code-Generator/raw/425498fd0797689f6d5615178993c3b8e3c8604a/Reference%20Image.png)
### User Interface:
![UI](https://github.com/ImamaSarwar/Tap-Code-Generator/raw/28ad8dbc5e7fcfc6dc7fb5b88d2d584b0c114094/UI.png)
