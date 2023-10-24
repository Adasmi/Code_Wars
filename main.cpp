#include <iostream>

using namespace std;

int material(int spaceship[], int siz)
{
    int maxi=0, result=0;

    for (int i=0; i<siz; i++) {
        if (spaceship[i]>maxi) maxi = spaceship[i];
    }

    for (int i=maxi; i>0; i--) {
        int range=0, start=-1;
        for (int j=0; j<siz; j++) {
            if (spaceship[j]>=i) {
                if (start==-1) start = j;
                else {
                    range += j - start - 1;
                    start = j;
                }
            }
        }

        result += range;

    }

    return result;
}

int main()
{
    int a[26] = {6, 4, 2, 0, 3, 2, 0, 3, 1, 4, 5, 3, 2, 7, 5, 3, 0, 1, 2, 1, 3, 4, 6, 8, 1, 3},
    b[18] = {6, 2, 1, 1, 8, 0, 5, 5, 0, 1, 8, 9, 6, 9, 4, 8, 0, 0};

    cout << material(a, sizeof(a)/sizeof(int)) << endl;
    cout << material(b, sizeof(b)/sizeof(int)) << endl;

    return 0;
}

