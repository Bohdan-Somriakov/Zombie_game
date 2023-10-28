#include <locale> // tolower
#include <string>
using namespace std;
string to_lower(string s) {
    for (char& c : s)
        c = tolower(c);
    return s;
}