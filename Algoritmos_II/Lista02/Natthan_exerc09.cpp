#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese");

    string text, text2, text3;

    cout << "Digite um texto qualquer: ";
    getline(cin, text);
    fflush(stdin);

    cout << "Digite um segundo texto qualquer: ";
    getline(cin, text2);
    fflush(stdin);

    cout << "Digite um terceiro texto qualquer: ";
    getline(cin, text3);
    fflush(stdin);

    for(int i = 0; i < text.size(); i++)
        text[i] = toupper(text[i]);

    for(int i = 0; i < text2.size(); i++)
        text2[i] = toupper(text2[i]);

    for(int i = 0; i < text3.size(); i++)
        text3[i] = toupper(text3[i]);

    int txtsize = text.size();
    int txtsize2 = text2.size();
    int txtsize3 = text3.size();

    if(txtsize < txtsize2 && txtsize < txtsize3)
    {
        cout << "\nA menor string é: " << text << "\n";
        if(txtsize2 < txtsize3)
        {
            cout << "A string intermediaria é: " << text2 << "\n";
            cout << "A maior string é: " << text3 << "\n";
        }
        else
        {
            cout << "A string intermediaria é: " << text3 << "\n";
            cout << "A maior string é: " << text2 << "\n";
        }
    }
    else if(txtsize2 < txtsize && txtsize2 < txtsize3)
    {
        cout << "\nA menor string é: " << text2 << "\n";
        if(txtsize < txtsize3)
        {
            cout << "A string intermediaria é: " << text << "\n";
            cout << "A maior string é: " << text3 << "\n";
        }
        else
        {
            cout << "A string intermediaria é: " << text3 << "\n";
            cout << "A maior string é: " << text << "\n";
        }
    }
    else if(txtsize3 < txtsize && txtsize3 < txtsize)
    {
        cout << "\nA menor string é: " << text3 << "\n";
        if(txtsize < txtsize2)
        {
            cout << "A string intermediaria é: " << text << "\n";
            cout << "A maior string é: " << text2 << "\n";
        }
        else
        {
            cout << "A string intermediaria é: " << text2 << "\n";
            cout << "A maior string é: " << text << "\n";
        }
    }

    return EXIT_SUCCESS;
}
