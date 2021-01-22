#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <limits>

void clearInput();
int gcd(int a, int b);
bool withinLower(char i);
bool withinUpper(char i);
int modInverse(int a, int b); // from https://rosettacode.org/wiki/Modular_inverse#C.2B.2B

int main()
{
    std::string choice;
    do
    {
        std::cout << "Encrypt or Decrypt? [e/d] = ";
        std::getline(std::cin, choice);
        std::transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
    } while (choice != "e" && choice != "d");

    std::cout << "\nInput string: ";
    std::string input;
    std::getline(std::cin, input);

    int a, b;
    do
    {
        a = 0, b = 0;
        std::cout << "\na dan b harus coprime\na = ";
        std::cin >> a;
        clearInput();
        std::cout << "b = ";
        std::cin >> b;
        clearInput();
    } while (std::cin.fail() && gcd(a, b) != 1);

    std::cout << '\n';

    if (choice == "e")
    {
        for (unsigned int i = 0; i < input.length(); ++i)
        {
            if (withinLower(input[i]))
            {
                std::cout << (char)((a * (input[i] - 'a') + b) % 26 + 'a');
            }
            else if (withinUpper(input[i]))
            {
                std::cout << (char)((a * (input[i] - 'A') + b) % 26 + 'A');
            }
            else
            {
                std::cout << input[i];
            }
        }
    }
    else
    {
        for (unsigned int i = 0; i < input.length(); ++i)
        {
            if (withinLower(input[i]))
            {
                std::cout << (char)(modInverse(a, 26) * (26 + input[i] - 'a' - b) % 26 + 'a');
            }
            else if (withinUpper(input[i]))
            {
                std::cout << (char)(modInverse(a, 26) * (26 + input[i] - 'A' - b) % 26 + 'A');
            }
            else
            {
                std::cout << input[i];
            }
        }
    }

    std::cout << '\n';
    return 0;
}

void clearInput()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

bool withinLower(char i)
{
    return i >= 'a' && i <= 'z' ? true : false;
}

bool withinUpper(char i)
{
    return i >= 'A' && i <= 'Z' ? true : false;
}

int modInverse(int a, int b)
{
    int b0 = b, t, q;
    int x0 = 0, x1 = 1;
    if (b == 1)
        return 1;
    while (a > 1)
    {
        q = a / b;
        t = b, b = a % b, a = t;
        t = x0, x0 = x1 - q * x0, x1 = t;
    }
    if (x1 < 0)
        x1 += b0;
    return x1;
}