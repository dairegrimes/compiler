#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "Token.h"
#include <typeinfo>
#include <vector>
using namespace std;

bool isKeyword(string token, int x, int y);
bool isSingleOperators(string token, int x, int y);
bool isVariable(string token, int x, int y);
bool isLetter(string token, int x, int y);
bool CheckSubstring(string firstString, string secondString);
string returnVar(string token, int x , int y);

int main(void)
{
    
    string curToken;
    string lastToken;
    string token;
    string whiteSpace = " ";
    string found;
    string varNames = "";
    int length = 0;
    int x = 0;
    int y = 0;
    
    
    
    ifstream input("file.txt");
    if (!input)
    {
        cerr << "No file" << endl;
        return 1;
    }
    
    

    while (getline(input, token))
    {
        length = (int)token.length();
        
        for(x = 0; x < token.length(); x ++)
        {
            //y = 0;
            
            for(y = 0; y < (length - x) + 1 ; y ++)
            {
                //if the length of the line is 0 is will skip the iteration
                if(length == 0)
                {
                    continue;
                }
                
                // if there is whitespace it will skip the iteration
                if(CheckSubstring(token.substr(x,y),whiteSpace) || token.substr(x,y) == "")
                {
                    continue;
                }
                
                
                if(isKeyword(token,x,y))
                {
                    cout << token.substr(x,y) << endl;
                }
                
                
                
                if(isSingleOperators(token,x,y))
                {
                    cout << token.substr(x,y) << endl;
                }
                
                if(isVariable(token, x, y))
                {
                    cout << token.substr(x,y) << endl;
                    lastToken = token.substr(x,y);
                }
                
                // checks for variable names
                if(token.substr(x,y) == "var")
                {
                    cout << returnVar(token, x, y) << endl;
                }
                
            }
            
        }
    }
    
    
    return 0;
}



// checks if is a keyword
bool isKeyword(string token, int x, int y)
{
    for(int i = 0; i < 26; i ++)
    {
        if(token.substr(x,y).compare(keyWords[i]) == 0)
        {
            return true;
        }
    }
    return false;
}


// checks if is a isSingleOperators
bool isSingleOperators(string token, int x, int y)
{
    for(int i = 0; i < 22; i ++)
    {
        if(token.substr(x,y).compare(singleOperators[i]) == 0)
        {
            return true;
        }
    }
    return false;
}


// checks if is a letter
bool isLetter(string token, int x, int y)
{
    for(int i = 0; i < 52; i ++)
    {
        if(token.substr(x,y).compare(letters[i]) == 0)
        {
            return true;
        }
    }
    return false;
}


// checks if is a Variable
bool isVariable(string token, int x, int y)
{
    for(int i = 0; i < 4; i ++)
    {
        if(token.substr(x,y).compare(variables[i]) == 0)
        {
            return true;
        }
    }
    return false;
}


// checks if a string is in another string
bool CheckSubstring(string firstString, string secondString)
{
    if(secondString.size() > firstString.size())
    {
        return false;
    }
    
    for (int i = 0; i < firstString.size(); i++)
    {
        int j = 0;
        if(firstString[i] == secondString[j])
        {
            while (firstString[i] == secondString[j] && j < secondString.size())
            {
                j++;
                i++;
            }
            
            if (j == secondString.size())
            {
                return true;
            }
        }
    }
    return false;
}


// returns variable name
string returnVar(string token, int x , int y)
{
    int i = 0;
    int j = 0;
    i = y;
    j = 0;
    do
    {
        i ++;
        /*
        if(token.substr(i,1) == "\"")
        {
            break;
        }
         */
        
    }
    while(!isLetter(token, i, 1));
    
    do
    {
        if(j == token.length() - 1)
        {
            break;
        }
        
        if(CheckSubstring(token.substr(i,j),","))
        {
            break;
        }
        
        j ++;
    }
    while(!CheckSubstring(token.substr(i,j)," "));
    
    return token.substr(i,j - 1);
    
}


