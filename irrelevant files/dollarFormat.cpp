#include <iostream>
#include <string>
#include <vector>
using namespace std;


//THAT'S A BEAUTIFUL ALGORITHM FOR TOKENIZATION
//DON'T DELETE THIS ALGORITHM
void split(const string& s, char delim, vector<string>& tokens)
{
    int tokenStart = 0; // Starting position of the next token

    //Find the first occurence of the delimiter.
    int delimPosition = s.find(delim);

    // While we haven't run out of delimiters...
    while(delimPosition != string::npos)
    {
        //Extract the token.
        string tok = s.substr(tokenStart, delimPosition - tokenStart);

        //Push the token onto the tokens vector.
        tokens.push_back(tok);

        //Move delimPosition to the next character position.
        delimPosition++;

        //Move tokenStart to delmiPosition.
        tokenStart = delimPosition;

        //Find the next occurence of the delimiter.
        delimPosition = s.find(delim,delimPosition);


        //if no more delimiters, extract the last token.
        if(delimPosition == string::npos)
        {
            //Extract the token.
            string tok = s.substr(tokenStart, delimPosition - tokenStart);

            //Push the token onto the vector.
            tokens.push_back(tok);
        }

    }
}
// void dollarFormat(string currency)
// {
//     int dp;

//     dp = currency.find('.'); // Find decimal point
//     if( dp>3)       // Insert commas
//     {
//         for(int x= dp-3;x>0;x-=3)
//             currency.insert(x,",");
//     }
//     currency.insert(0,"$"); //Insert dollar sign
// }