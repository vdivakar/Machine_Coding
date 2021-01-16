// #include<iostream>
// #include<fstream>
// #include<vector>
// #include<string>
#include <stdc++.h>

// #include<pair>
// #include "Card.cpp"
// #include "Trello.cpp"
using namespace std;

void print_vector(vector<string> v){
    for(string s: v){
        cout << s << endl;
    }
    cout << endl;
}

void print_vector2(vector<pair<string, string> > v){
    for(auto s: v){
        cout << s.first << " " << s.second << endl;
    }
    cout << endl;
}

bool compare(pair<string, string> a, pair<string, string> b){
    return a.second < b.second;
}

int main(int argc, char **argv){
    // User user1 = User(12, "Divakar", "dummy@gmail.com");
    // Trello trello = Trello();

    cout << "Number of arguments: " << argc << endl;
    if(argc > 1){
        for(int i=1; i<argc; i++){
            vector<string> v;
            fstream file(argv[i]);
            string str;
            vector<pair<string, string> > vec;
            while(file>>str){
                string s2;
                file>>s2;
                vec.push_back(make_pair(str, s2));
            }
            // while(getline(file, str)){
            //     v.push_back(str);
            // }
            file.close();

            sort(vec.begin(), vec.end(), &compare);
            print_vector2(vec);
        }
    }
    
    return 0;
}