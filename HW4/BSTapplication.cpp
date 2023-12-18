//Name: Wilson Kelly
//CSE310 - Summer
//BSTapplication.cpp

#include <iostream>
using namespace std;


struct airPort
{
    airPort *left;
    airPort *right;
    int key;
    string numFlight;
};

airPort* remove(airPort, int);
void display(airPort );
airPort check(airPort, int, string, int);
void add(airPort, int, string);
airPort* minSearch(airPort* );


void add(airPort **x,int k,string flightName) {
    if(*x==NULL) { // first 
        *x=new airPort;
        (*x)->left=NULL;
        (*x)->key=k;
        (*x)->numFlight=flightName;
        (*x)->right=NULL;
    }
    else {
        if((*x)->key>k) { //add in a bst, k is the key
            add(&((*x)->left),k,flightName);
        }
        else {
            add(&((*x)->right),k,flightName);
        } 
    }
    return;
}


airPort* check(airPort *x, int k, string flightName, int gap) {
    int y;
    if(x!=NULL) {
        if((x)->key>k) { //used to find the highest value
            y=(x)->key-k;
        }
        else {
            y=k-(x)->key;
        }
        if(y-gap>=1) { 
            check(x->left,k,flightName,gap);
            check(x->right,k,flightName,gap);
        }
        else {
            return x;
        }
    }   
    return NULL;
}

airPort* minSearch(airPort* x) {
    while(x->left != NULL) {
        x = x->left;
    }
    return x;
}

//search, then remove
airPort* remove(airPort *x, int k) { 
    //BST search code starts here
    if(x == NULL) {
        return x; 
    }
    else if(k < x->key) {
        x->left = remove(x->left,k);
    }
    else if (k > x->key) {
        x->right = remove(x->right,k);
    }
    //BST search code ends, delete code begins
    else {
        airPort *y;
        if(x->left == NULL && x->right == NULL) { // 0 children
            delete x;
            x = NULL;
        }
        else if(x->left == NULL) { // 1 children
            y = x;
            x = x->right;
            delete y;
        }
        else if(x->right == NULL) {
            y= x;
            x = x->left;
            delete y;
        }
        else { // 2 children
            y = minSearch(x->right);
            x->key = y->key;
            x->right = remove(x->right,y->key);
        }
    }
    return x;
}

void display(airPort *x) { //display vals in tree
    cout << endl << endl;
    if(x!=NULL) {
        display((x)->left);
        cout << " Flight number is: " << x->numFlight << endl;
        cout << " Landing time is: " << x->key << endl;
        display((x)->right);
    }
    else {
        return;
    }
}

int main()
{
    airPort *x;
    int gap,choice,k;
    string flightName;
    x=NULL;
    
    cout << endl << endl;
    cout << " Enter the gap of time: ";
    cin >> gap;

    while(true)
    {
        cout << "1. Request a landing " << endl;
        cout << "2. remove a landing request " << endl;
        cout << "3. display landing times and flight numbers " << endl;
        cout << "4. Exit " << endl;
        cout << " Enter your choice : ";
        cin >> choice;
        
        switch(choice)
        {
        case 1: cout << " Enter landing time ";
            cin >> k;
            cout << " Enter flight number ";
            cin >> flightName ;
            if(x==NULL) {     
                add(&x,k,flightName);
                cout << (" Landing request confirmed ") << endl;
            }
            else if(check(x,k,flightName,gap)==NULL) {
                add(&x,k,flightName);
                cout << (" Landing request confirmed ") << endl;

            }
            else {
                cout << (" Landing request denied ") << endl;
            }
            break;
        case 2: cout << ("Enter landing time") << endl;
            cin >> k;
            x = remove(x,k);
            break;
        case 3: display(x);
            break;
        case 4: system("pause");
            return 0;
        break;
        default:
            cout << "incorrect input";
        break;
    }     
    }
}
//To do: fix looping bug caused by char input