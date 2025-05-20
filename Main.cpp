#include <iostream>
#include "Manager.h"
using namespace std;

int lengthOfArrays(const char* input) {
    int length = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        length++;
    }
    return length;
}
bool isValidAlphabeticInput(const char* input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (!((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z')))
            return false;
    }
    return true;
}

bool isValidNumericInput(const char* input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (!(input[i] >= '0' && input[i] <= '9'))
            return false;
    }
    return true;
}

char* tapCodeDecipher::convertToTapCode(char* input)
{
    int count = 0;
    int length = lengthOfArrays(input);
    int size = length * 2;
    char* arr = new char[size];

    for (int k = 0; k < length; k++) {
        // Map 'K' or 'k' to 'C' or 'c'
        char ch = input[k];
        if (ch == 'K') ch = 'C';
        else if (ch == 'k') ch = 'c';

        bool found = false;
        for (int i = 0; i < 5 && !found; i++) {
            for (int j = 0; j < 5; j++) {
                if (polybiusSquareCapital[i][j] == ch || polybiusSquareSmall[i][j] == ch) {
                    arr[count++] = '0' + (i + 1); // row
                    arr[count++] = '0' + (j + 1); // col
                    found = true;
                    break;
                }
            }
        }
    }

    return arr;
}

char* tapCodeDecipher::convertToString(const char* input) 
{
    int originalLength = lengthOfArrays(input);
    
    int numericLength = 0;
    for (int i = 0; i < originalLength; ++i) {
        if (input[i] >= '0' && input[i] <= '9') {
            numericLength++;
        }
    }

    if (numericLength % 2 != 0) 
    {
        char* error_str = new char[1];
        error_str[0] = '\0';
        return error_str;
    }

    char* string1 = new char[numericLength / 2 + 1]; 
    int string1_idx = 0;

    for (int i = 0; i < originalLength; ) 
    {
        if (input[i] >= '0' && input[i] <= '9') 
        {
            int row_I = (input[i] - '0');
            if (i + 1 < originalLength && (input[i + 1] >= '0' && input[i + 1] <= '9')) 
            {
                int col_I = (input[i + 1] - '0');
                if (row_I >= 1 && row_I <= 5 && col_I >= 1 && col_I <= 5) 
                {
                    string1[string1_idx++] = polybiusSquareCapital[row_I - 1][col_I - 1];
                    i += 2; 
                }
                else 
                {
                    cout<< "Warning: Invalid tap code pair: " << input[i] << input[i + 1] << std::endl;
                    i += 2; 
                }
            }
            else 
            {
                cout << "Warning: Single digit in tap code without a pair: " << input[i] << std::endl;
                i++;
            }
        }
        else 
        {
            i++;
        }
    }
    string1[string1_idx] = '\0'; 

    return string1;
}
int main()
{
    tapCodeDecipher tapDecoder;
    char choice;
    char input[100];
    do {
        int length = 0;
        cout << "\n\t ----TAP CODE CONVERTER----\n\n";
        cout << "Do you want to enter a string or a Tapcode?" << endl << "Press 1 for String" << endl << "Press 2 for Tap Code" << endl <<"Press 0 to exit\n";
        cin >> choice;
        if (choice == '1')
        {
            cout << "Enter the string ";
            cin.ignore();
            cin.getline(input, 100);
            if (input[0] == '\0') {
                cout << "Error: Empty input." << endl;
                return 1;
            }
            if (!isValidAlphabeticInput(input)) {
                cout << "Error: Input should contain only alphabets." << endl;
                return 1;
            }
            length = lengthOfArrays(input);
            char* arr = new char[length + 1];
            for (int i = 0; input[i] != '\0'; i++)
            {
                arr[i] = input[i];
            }
            arr[length] = '\0';
            char* result = new char[length * 2];

            result = tapDecoder.convertToTapCode(arr);
            cout << endl << "Tap Code: ";
            for (int i = 0; i < (length * 2); i++)
            {
                cout << result[i];
            }
            cout << endl;
            for (int i = 0; i < (length * 2); i++)
            {
                for (int j = (result[i]) - 48; j != 0; j--)
                {
                    cout << "*";
                }
                cout << " ";
            }
            cout << endl << endl;
            delete[] arr;
            arr = NULL;
            delete[] result;
            result = NULL;
        }
        else if (choice == '2')
        {
            cout << "Enter the Tap Code: ";
            cin.ignore();
            cin.getline(input, 100);
            if (input[0] == '\0') {
                cout << "Error: Empty input." << endl;
                return 1;
            }

            if (!isValidNumericInput(input)) {
                cout << "Error: Tap Code must contain only digits." << endl;
                return 1;
            }

            if (lengthOfArrays(input) % 2 != 0) {
                cout << "Error: Tap Code must have even number of digits (row & column pairs)." << endl;
                return 1;
            }

            length = lengthOfArrays(input);
            input[length] = '\0';
            char* arr = new char[length + 1];
            for (int i = 0; input[i] != '\0'; i++)
            {
                arr[i] = input[i];
            }
            arr[length] = '\0';
            char* result = new char[length / 2];

            result = tapDecoder.convertToString(arr);
            cout << "String: ";
            for (int i = 0; result[i] != '\0'; i++)
            {
                cout << result[i];
            }
            cout << endl <<endl;
            delete[] arr;
            arr = NULL;
            delete[] result;
            result = NULL;
        }
        else if (choice == '0')
        {
            cout << "\nExiting the program..." << endl;
        }
        else
        {
            cout << "Invaid choice. Kindly press either 1,2 or 0\n";
        }
    } while (choice != '0');
    

    return 0;
}

