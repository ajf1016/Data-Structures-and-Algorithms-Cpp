#include <iostream>
using namespace std;
#include <string>

void printText(string text, int key)
{
    int newKey = key % 26;
    char newText[text.length()];
    for (int i = 0; i < text.length(); i++)
    {
        int textPosition = text[i] + newKey;
        if (textPosition <= 122)
        {
            newText[i] = static_cast<char>(textPosition);
        }
        else
        {
            newText[i] = static_cast<char>(96 + textPosition % 122);
        }
    }
    string newString = newText;
    cout<<newString<<endl;
}

int main()
{
    cout << "Hello world\n";
    printText("Hai",2);
    return 0;
}