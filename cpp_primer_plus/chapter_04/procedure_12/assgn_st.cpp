// assgn_st.cpp -- assigning structures
#include <iostream>

struct inflatable
{
    char name[20];
    float volumn;
    double price;
};

int main()
{
    using namespace std;
    inflatable bouquet = {
        "sunflower",
        0.20,
        12.49,
    };
    inflatable choice;
    cout << "bouquet: " << bouquet.name << " for $" << bouquet.price << endl;

    choice = bouquet;
    cout << "choice: " << choice.name << " for $" << choice.price << endl;

    return 0;
}