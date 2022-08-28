#include <string>
#include <iostream>

using namespace std;

int main()
{
    string sentence = "Hello there.";
    for (int i=0; i < sentence.size(); i++)
    {
        if (sentence[i] == 'o')
        {
            cout << "Found and o!\n";
            continue;
        }
        cout << sentence[i] << endl;
    }
    cout << "\nDone.\n";

    return 0;
}