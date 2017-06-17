
//
//  Token.h
//  Compiler
//
//  Created by Daire Grimes on 29/05/2017.
//  Copyright © 2017 Daire Grimes. All rights reserved.
//

#ifndef Token_h
#define Token_h
#include <iostream>
#include "string.h"
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>

using namespace std;

enum Token {
    identifiers = -1,
    keywords = -2,
    operators = -3,
    delimiters = -4,
    literals = -5
};

// 52
const string letters[] =
{
    "a","b","c","d","e","f","g","h","i",
    "j","k","l","m","n","o","p","q","r","s","t","u","v",
    "w","x","y","z","A","B","C","D","E","F","G","H",
    "I","J","K","L","M","N","O","P","Q","R","S","T","U","V"
    "W","X","Y","Z"
};

const string variables[] =
{
    "int","string","float","char"

};


// 26
const string keyWords[] =
{
    "break","default","func","interface","select",
    "case","defer","go","map","struct",
    "chan", "else","goto","package","switch",
    "const","fallthrough","if","range","type",
    "continue","for","import","return","var","main"
};

// 22 
const string singleOperators[]
{
    "+", "&","(",")",
    "-","|","<","[","]",
    "*","^",">", "{","}"
    "/","=",",",";",
    "%","!" ,".",
    ":"
};


const string doubleOperators[]
{
    "+=","&=","&&","==","!=",
    "-=","|=","||","<=",
    "*=","^=","<-",">=",
    "<<","/=","<<=","++",":=",
    ">>","%=",">>=","--","...",
    "&^","&^="
};


#endif
