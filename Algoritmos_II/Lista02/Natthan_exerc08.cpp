#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese");

    string vowels("aeiouAEIOU");
    string text;
    int total = 0, space = 0, vowel = 0, odd = 0, num = 0, spec = 0;

    cout << "Digite um texto qualquer: ";
    getline(cin, text);
    fflush(stdin);

    for(int i = 0; i < text.size(); i++)
    {
        total++;

        if(isspace(text[i]))
            space++;
        else if(isalnum(text[i]))
        {
            if(isdigit(text[i]))
            num++;
        }
        else
            spec++;

        for(int j = 0; j < vowels.size(); j++)
        {
            if(text[i] == vowels[j])
                vowel++;
        }
    }

    odd = total - (vowel + space);

    cout << "\nO texto tem " << total << " caracteres.";
    cout << "\nO texto tem " << space << " espacos em branco.";
    cout << "\nO texto tem " << vowel << " vogais.";
    cout << "\nO texto tem " << odd << " consoantes.";
    cout << "\nO texto tem " << num << " numeros.";
    cout << "\nO texto tem " << spec << " caracteres especiais.\n";

    return EXIT_SUCCESS;
}
