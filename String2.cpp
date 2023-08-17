#include <iostream>
using namespace std;
#include <string>

void stringCount(string text)
{
    string newString;
    int count = 1;
    char current = text[0];
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == current)
        {

            count++;
        }else{
            newString+=to_string(count) + current;
            current = text[i];
            count = 1;
        }
    }

    newString+=to_string(count) + current;

    cout<<newString<<endl;
}

int main()
{
    cout << "Hello world!" << endl;
    stringCount("AAABBBCCCDDDAAA");
    return 0;
}

// AAABBAA
// 65,65,65,66,66,65,65