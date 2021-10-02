#include <algorithm>
#include <string>
#include <iostream>

for (int i = n; i > 0; --i)
{
    Np = num % fact[i - 1]; //Определение номера группы перест.
    d = num / fact[i - 1];  //Определение индекса текущей цифры
    
    if (Np)
        d++;
    else
        Np += fact[i - 1];

    num = Np;
    int pos = 0;

    for (int j = 1; j <= n; ++j)
    { //Определение текущей цифры
        if (!digit[j])
            pos++;
        if (pos == d)
        {
            digit[j] = 1;
            res.push_back(j); //Формирование перестановки
            break;
        }
    }
}
