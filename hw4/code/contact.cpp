#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string>
#include <fstream>
#include "contact.h"
#include <iostream>

using namespace std;

void Contact::load(string file_name){
    char c_str[1024];
    strcpy(c_str, file_name.c_str());

    ifstream fin(c_str);//Opening a file using c_str
    if(!fin.is_open()){//Print error message when file opening fails
        printf("Cannot open %s\n", c_str);
        return;
    }

    string line;
    while(getline(fin, line)){//Read line by line from a file
        if (line.empty()) continue;//Skip blank lines
        char buffer[256];//An array of strings to store one line
        strncpy(buffer, line.c_str(), sizeof(buffer));//Copy string to char*
        buffer[sizeof(buffer) - 1] = '\0';//Add NULL character at the end

        persons[total_num++] = str2person(trim(buffer));//Convert data to a Person structure and store it in an array
    }

    fin.close();//file close
}


void Contact::print(){//Print all contact information
    for(int i=0; i<total_num; ++i) {
        printf("[%s][%04d%02d%02d][%s][%s]\n",
            persons[i].name,
            persons[i].dob.year,
            persons[i].dob.month,
            persons[i].dob.day,
            persons[i].email,
            persons[i].phone
        );
    }
}

char* Contact::trim(char* s) {
    if (!s) return NULL;//Return if NULL
    while (isspace(*s)) s++;//Remove leading whitespace
    char* end = s + strlen(s) - 1;//Set pointer to end of string
    while (end > s && isspace(*end)) end--;//뒤쪽 공백 제거
    *(end + 1) = '\0';
    return s;
}

Date Contact::str2date(char* str) {
    Date date;
    char temp[10];//Temporary array to store date information

    strncpy(temp, str, 4);//Copy 4-digit year from string
    temp[4] = '\0';
    date.year = atoi(temp);//Convert string to number and store year

    strncpy(temp, str + 4, 2);
    temp[2] = '\0';
    date.month = atoi(temp);

    strncpy(temp, str + 6, 2);
    temp[2] = '\0';
    date.day = atoi(temp);

    return date;
}

Person Contact::str2person(char* line) {
    Person p;
    char* token;
    int i = 0;

    token = strtok(line, ";");//Split strings based on semicolon
    while (token) {
        switch (i) {
            case 0: strcpy(p.name, trim(token)); break;
            case 1: p.dob = str2date(trim(token)); break;
            case 2: strcpy(p.email, trim(token)); break;
            case 3: strcpy(p.phone, trim(token)); break;
        }
        token = strtok(NULL, ";");//Move to next token
        i++;
    }
    return p;
}