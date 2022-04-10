#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

class Name {
private:
    char *mp=NULL;
    int size=0;
public:
    Name(const char *p);
    ~Name();
    void display();
    void reverse();
};

Name::Name(const char *p){
    for(int i=0;i<strlen(p);i++){
        mp = (char*)realloc(mp,sizeof(char)*(i+1));
        *(mp+i) = *(p+i);
        size++;
    }
}

Name::~Name(){
    delete[] mp;
}

void Name::display(){
    cout << "Name is " << mp << endl;
}

void Name::reverse(){    
    for(int i=0;i<size/2;i++){
        char temp = mp[i];
        mp[i] = mp[size-i-1];
        mp[size-i-1] = temp;
    }
}

int main(){

    Name myname("Berat");

    myname.display();
    myname.reverse();
    myname.display();

    return 0;
}