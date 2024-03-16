#include <iostream>
#include <fstream>
#include <string>
#include <codecvt>

using namespace std;

// Function prototypes
void encryptFile(const wstring& filePath, const wstring& password);
void decryptFile(const wstring& filePath, const wstring& password);

int main() {
    wstring filePath, password;
    wchar_t choice;

    wcout << L"Enter file path: ";
    getline(wcin, filePath);

    wcout << L"Enter password: ";
    getline(wcin, password);

    wcout << L"Do you want to encrypt (e) or decrypt (d) the file? ";
    wcin >> choice;

    switch (choice) {
    case L'e':
        encryptFile(filePath, password);
        wcout << L"File encrypted successfully!" << endl;
        break;
    case L'd':
        decryptFile(filePath, password);
        wcout << L"File decrypted successfully!" << endl;
        break;
    default:
        wcout << L"Invalid choice!" << endl;
        break;
    }

    return 0;
}

// Function to encrypt a file
void encryptFile(const wstring& filePath, const wstring& password) {
    wifstream inputFile(filePath, ios::binary);
    wofstream outputFile(filePath + L".encrypted", ios::binary);

    wchar_t ch;
    size_t i = 0;
    while (inputFile.get(ch)) {
        ch = ch ^ password[i % password.length()]; // XOR encryption with password
        outputFile.put(ch);
        ++i;
    }

    inputFile.close();
    outputFile.close();
}

// Function to decrypt a file
void decryptFile(const wstring& filePath, const wstring& password) {
    wifstream inputFile(filePath, ios::binary);
    wofstream outputFile(filePath.substr(0, filePath.find_last_of(L'.')), ios::binary);

    wchar_t ch;
    size_t i = 0;
    while (inputFile.get(ch)) {
        ch = ch ^ password[i % password.length()]; // XOR decryption with password
        outputFile.put(ch);
        ++i;
    }

    inputFile.close();
    outputFile.close();
}
