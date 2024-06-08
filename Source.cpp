#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

const string alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ ,.!?";
const int alphabetSize = alphabet.length();

string encryptMessage(const string& message, const string& key)
{
    string encryptedMessage = message;

    for (size_t i = 0; i < encryptedMessage.length(); i++)
    {
        char currentChar = encryptedMessage[i];
        size_t charIndex = alphabet.find(currentChar);

        if (charIndex != string::npos)
        {
            char keyChar = key[i % key.length()];
            size_t keyIndex = alphabet.find(keyChar);

            charIndex = (charIndex + keyIndex) % alphabetSize;

            encryptedMessage[i] = alphabet[charIndex];
        }
    }

    return encryptedMessage;
}

string decryptMessage(const string& encryptedMessage, const string& key)
{
    string decryptedMessage = encryptedMessage;

    for (size_t i = 0; i < decryptedMessage.length(); i++)
    {
        char currentChar = decryptedMessage[i];
        size_t charIndex = alphabet.find(currentChar);

        if (charIndex != string::npos)
        {
            char keyChar = key[i % key.length()];
            size_t keyIndex = alphabet.find(keyChar);

            charIndex = (charIndex - keyIndex + alphabetSize) % alphabetSize;

            decryptedMessage[i] = alphabet[charIndex];
        }
    }

    return decryptedMessage;
}

string inputMessage()
{
    string message;
    cout << "Введите сообщение: ";
    getline(cin, message);
    return message;
}

string inputKey()
{
    string key;
    cout << "Введите ключ: ";
    getline(cin, key);
    return key;
}

void printVigenereTable()
{
    cout << "Шифр Виженера (Vigenere Table):" << endl;

    for (int row = 0; row < alphabetSize; row++)
    {
        for (int col = 0; col < alphabetSize; col++)
        {
            int index = (row + col) % alphabetSize;
            cout << alphabet[index];
        }

        cout << endl;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printVigenereTable();

    string message = inputMessage();
    string key = inputKey();

    cout << "Выберите режим: " << endl;
    cout << "1. Зашифровать сообщение" << endl;
    cout << "2. Расшифровать сообщение" << endl;
    cout << "Ваш выбор: ";

    int choice;
    cin >> choice;
    cin.ignore(); 

    if (choice == 1)
    {
        string encryptedMessage = encryptMessage(message, key);
        cout << "Зашифрованное сообщение: " << encryptedMessage << endl;
    }
    else if (choice == 2)
    {
        string decryptedMessage = decryptMessage(message, key);
        cout << "Расшифрованное сообщение: " << decryptedMessage << endl;
    }
    else
    {
        cout << "Неверный выбор." << endl;
        return 1;
    }

    return 0;
}
