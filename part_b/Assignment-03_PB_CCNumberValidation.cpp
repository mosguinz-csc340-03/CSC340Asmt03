#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

bool isvalidcc(const string &);

//@formatter:off
int main()
{
	//
	// PLEASE DO NOT CHANGE function main
	//
	vector<string> cardnumbers = {
		 "371449635398431", "4444444444444448", "4444424444444440", "4110144110144115",
		"4114360123456785", "4061724061724061", "5500005555555559", "5115915115915118",
		"5555555555555557", "6011016011016011", "372449635398431", "4444544444444448",
		"4444434444444440", "4110145110144115", "4124360123456785", "4062724061724061",
		"5501005555555559", "5125915115915118", "5556555555555557", "6011116011016011",
		 "372449635397431", "4444544444444448", "4444434444544440", "4110145110184115",
		"4124360123457785", "4062724061724061", "5541005555555559", "5125115115915118",
		"5556551555555557", "6011316011016011"
	};

	int i;
	vector<string>::iterator itr;

	for (i = 1, itr = cardnumbers.begin(); itr != cardnumbers.end(); ++itr, i++) {
		cout << setw(2)  << i << " "
			 << setw(17) << *itr
			 << ((isvalidcc(*itr)) ? " is valid" : " is not valid") << endl;
	}

	return 0;
}
//@formatter:on

bool isvalidcc(string const &card) {
    unsigned int odd_sum = 0, even_sum = 0;

    for (int i = card.length() - 1, j = 1; i >= 0; i--, j++) {
        unsigned int digit = card[i] - '0';
        if (j % 2) {
            odd_sum += digit;
            continue;
        }
        unsigned int doubled = digit * 2;
        even_sum += doubled > 9 ? (doubled / 10) + (doubled % 10) : doubled;
    }
    return (odd_sum + even_sum) % 10 == 0;
}