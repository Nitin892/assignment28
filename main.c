//1. Define a class Complex with appropriate instance variables and member functions.
//Overload following operators
//        a. << insertion operator
//        b. >> extraction operator
//
#include <iostream>

using namespace std;

class Complex {
private:
    int real;
    int img;
public:
    Complex() {}

    Complex(int r, int i) { real = r, img = i; }

    friend ostream &operator<<(ostream &, Complex);

    friend istream &operator>>(istream &, Complex &);
};

ostream &operator<<(ostream &output, Complex c) {
    cout << c.real << " " << c.img;
    return output;
}

istream &operator>>(istream &input, Complex &c) {
    cin >> c.real;
    cin >> c.img;
    return input;
}


int main() {
    Complex c1(3, 6);
    Complex c2;
    cout << "Enter two numbers:";
    cin >> c2;
    cout << c2;
    return 0;
}

//2. Define a class Complex with appropriate instance variables and member functions.
//One of the functions should be setData() to set the properties of the object. Make
//        sure the names of formal arguments are the same as names of instance variables.

#include <iostream>

using namespace std;
class Complex{
private:
    int real;
    int img;
public:
    void setvalues(int real,int img){
        this->img=img;
        this->real=real;
    }
    void showdata(){
        cout<<this->real<<endl;
        cout<< this->img<<endl;
    }
};
int main(){
    Complex c;
    c.setvalues(3,6);
    c.showdata();
    return 0;
}

//3. Overload subscript operator [] that will be useful when we want to check for an index
//out of bound.
#include <iostream>
#include <stdlib.h>

using namespace std;

class Array {
private:
   int *a;
   int size;
public:
   Array() {}

   Array(int *arr, int s) {
       size = s;
       a = (int *) malloc(size * sizeof(int));
       for (int i = 0; i < s; ++i) {
           a[i]=arr[i];
       }
   }

   int operator[](int index) {
       if(index>=size || index<0){
           cout<<"index of range";
       }
       else
           return a[index];
   }

};

int main() {
   int arr[] = {2, 3, 4, 5, 6};
   Array a(arr, 5);
   int index = a[1];
   cout << index;
   return 0;
}


4. Create a student class and overload new and delete operators as a member function
of the class.

#include <iostream>
#include <stdlib.h>

using namespace std;

class Student {
private:
   int age;
public:
   Student() {};

   void *operator new(size_t size) {
       void *p = malloc(size);
       return p;
   }

   void operator delete(void *p) {
       free(p);

   }
};

int main() {
   Student *s = new Student[5];
   int *a = new int(8);
   delete[] a, s;
   return 0;
}

5. Create a student class and overload new and delete operators outside the class.

#include <iostream>
#include <stdlib.h>

void *operator new(size_t size){
   void *p= malloc(size);
   return p;
}
void operator delete (void *p){
   free(p);

}
using namespace std;
class Student{
private:
   int age;
public:
   Student(){};
};

int main(){
   Student *s = new Student[5];
   int *a = new int(8);
   delete[] a,s;
   return 0;
}


6. Create a complex class and overload assignment operator for that class.
#include <iostream>

using namespace std;

class Complex {
private:
   int real, img;
public:
   Complex() {};

   Complex(int r, int i) {
       real = r;
       img = i;
   }

   void operator=(Complex c1) {
       real = c1.real;
       img = c1.img;
   }


   void change(int x,int y){
       real=x;
       img=y;
   }
   void show() {
       cout << real << " " << img;
   }
};


int main() {
   Complex c1(3, 5);
   Complex c2 = c1;
   c2.change(90,80);
   c1.show();
   return 0;
}

7. Create an Integer class and overload logical not operator for that class.
#include<iostream>

using namespace std;

class Interger {
private:
   int x;
public:
   Interger(int a) { x = a; }

   Interger() {}

   bool operator!() {
       return !x;
   }

   friend ostream &operator<<(ostream &, Interger);
};

ostream &operator<<(ostream &output, Interger i) {
   cout << i.x;
   return output;
}

int main() {
   Interger i1(0);
   Interger i2;
   i2 = !i1;
   cout << i2;
   return 0;
}

8. Create a Coordinate class for 3 variables x,y and z and overload comma operator
       such that when you write c3 = (c1 , c2 ) then c2 is assigned to c3. Where c1,c2,and
       c3 are objects of 3D coordinate class.

#include <iostream>

using namespace std;

class Coordinate {
private:
   int x, y, z;
public:
   Coordinate() {}

   Coordinate(int a, int b, int c) { x = a, y = b, z = c; }
   Coordinate operator,(Coordinate c){
       Coordinate t;
       t.x = c.x;
       t.y = c.y;
       t.z = c.z;
       return t;
   }
   friend ostream &operator<<(ostream &, Coordinate);
};

ostream &operator<<(ostream &output, Coordinate c) {
   cout << c.x<<" "<<c.y<<" "<<c.z;
   return output;
}

int main() {
   Coordinate c1(3, 6, 9);
   Coordinate c2(4, 8, 12);
   Coordinate c3;
   c3 = (c1, c2);
   cout<<c3;

   return 0;
}

9. Create an Integer class that contains int x as an instance variable and overload
  casting int() operator that will type cast your Integer class object to int data type.

#include <iostream>
#include <typeinfo>
using namespace std;

class Integer {
private:
   int x;
public:
   Integer() {}

   Integer(int a) { x = a; }

    operator int () {
       int a;
       int b = (int) x;
       return b;
   }

};

int main() {
   Integer i1(10);
   int b = (int) i1;
   cout << typeid(i1).name();
   return 0;
}

10. Create a Distance class having 2 instance variable feet and inches. Also create
default constructor and parameterized constructor takes 2 variables . Now overload ()
function call operator that takes 3 arguments a , b and c and set feet = a + c + 5 and
                                                                        inches = a+b + 15.


#include <iostream>
using namespace std;

class Distance{
private:
   int feet,inches;
public:
   Distance(){}

   Distance(int a,int b){feet=a,inches=b;}

   void operator()(int a,int b,int c){
       Distance t;
       feet = a + b + 5;
       inches = a + b + 15;
   }

   void show(){
       cout<<feet<<" "<<inches;
   }
};

int main(){
   Distance d;
   d(5,8,2);
   d.show();
   return 0;
}

11. Create a class Marks that have one member variable marks and one member
function that will print marks. We know that we can access member functions using
(.) dot operator. Now you need to overload (->) arrow operator to access that
function

#include <iostream>
using namespace std;
class Marks{
private:
   int m;
public:
   void set(int a){m=a;}
   void show(){
       cout<<m;
   }

   Marks* operator->(){
       return this;
   }
   
};

int main(){
   Marks m;
   m->set(9);
   m->show();
   return 0;

}
