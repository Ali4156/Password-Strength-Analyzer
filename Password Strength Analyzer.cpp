#include <iostream>
#include <string>
using namespace std;

int main() {
    string password;
    int score = 0;

    cout << "Enter your password: ";
    cin >> password;

    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;

    for (char c : password) {
        if (isupper(c))
            hasUpper = true;
        else if (islower(c))
            hasLower = true;
        else if (isdigit(c))
            hasDigit = true;
        else
            hasSpecial = true;
    }

    if (password.length() >= 8)
        score++;

    if (hasUpper)
        score++;

    if (hasLower)
        score++;

    if (hasDigit)
        score++;

    if (hasSpecial)
        score++;

    cout << "\nPassword Analysis:\n";

    if (score <= 2) {
        cout << "Strength: Weak\n";
    }
    else if (score == 3 || score == 4) {
        cout << "Strength: Medium\n";
    }
    else {
        cout << "Strength: Strong\n";
    }

    cout << "\nSuggestions to improve password:\n";

    if (password.length() < 8)
        cout << "- Use at least 8 characters\n";

    if (!hasUpper)
        cout << "- Add uppercase letters\n";

    if (!hasLower)
        cout << "- Add lowercase letters\n";

    if (!hasDigit)
        cout << "- Add numbers\n";

    if (!hasSpecial)
        cout << "- Add special characters (!@#$ etc)\n";

    return 0;
}