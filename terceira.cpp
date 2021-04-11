#include <bits/stdc++.h>
using namespace std;
int k=0;

vector<string> preposition = {"on","over","through"},
 noums = {"man","dog","fish","computer",""},
 trans_verb = {"struck","saw","bit","took"},
 intrans_verb = {"slept","jumped","walked","swam"},
 article = {"the","a"},
 adjective = {"green","small","rabid","quick"},
 adverb = {"nearly","suddenly","restlessly"},
 empty = {""};

string sentece(){
    k=(k%2)+1;
    string r;
    switch (k){
        case 1:
            r = trans_setence();
        break;
        case 2:
            r = intrans_sentence();
        break;
        case 3:
            r = 
    }
    return r;
}
string trans_setence(){
    string r;
    r += subject() + ' ' + verb_phrase() + ' ';
    object[];
}
string intrans_sentence(){

}
string subject(){

}
string object(){

}
string noun_phrase(){

}
string modified_noun(){

}
string modifier(){
}
string verb_phrase(){

}
string prep_phrase(){

}
int main(){
    
    return 0;
}