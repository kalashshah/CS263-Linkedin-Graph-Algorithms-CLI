#include <bits/stdc++.h>
using namespace std;

class User {
public:
  string name;
  vector<User> friends;
  int age;

  User(string name, int age) {
    this->name = name;
    this->age = age;
    this->friends = vector<User>();
  }
};

class Linkedin {
public:
  vector<User> users;
  Linkedin() {
    this->users = vector<User>();
  }
};

int main() {
  cout << "<--------------------------WELCOME TO LINKEDIN CLI PROGRAM-------------------------->\n";
  Linkedin* linkedin = new Linkedin();
  linkedin->users.push_back(User("A", 20));
  linkedin->users.push_back(User("B", 30));
  cout << "Our users are: " << endl;
  for(int i = 0; i < linkedin->users.size(); i++) {
    cout << "User: " << linkedin->users[i].name << " Age: " << linkedin->users[i].age << endl;
  }
}