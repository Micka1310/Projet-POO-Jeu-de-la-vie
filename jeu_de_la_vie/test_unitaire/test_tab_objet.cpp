#include <vector>

#include "../case.h"
#include "../case.cpp"

using namespace std;

int main()
{
    vector<Case> tab_case;

    for (int i = 0; i < 5; i++)
    {
        tab_case.push_back(Case());
    }

    for (int i = 0; i < 5; i++)
    {
        tab_case[i].afficherCase();
    }

    cout << "Changement de valeur\n" << endl;

    for (int i = 0; i < 5; i++)
    {
        tab_case[i].setCoord_x(i);
        tab_case[i].setCoord_y(i);
        tab_case[i].setEtat(true);
    }

    for (int i = 0; i < 5; i++)
    {
        tab_case[i].afficherCase();
    }

    return 0;
}