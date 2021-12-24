#include <bits/stdc++.h>
#include "main.cpp"
using namespace std;

// Suggest user suggested connections based on profession
pair<string, set<detailsOfUser>> suggestedConnectionsBasedOnProfessionBruteForce(vector<vector<detailsOfUser>> &matrix, detailsOfUser &user) {
  // iterate through adjacency list named matrix
  // for each user, check if the user has same profession
  // if yes, add to a vector of suggested connections
  // return the vector
  set<detailsOfUser> suggestionsBasedOnProfession;
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      if (matrix[i][j].profession == user.profession && !(matrix[i][j] == user)) {
        suggestionsBasedOnProfession.insert(matrix[i][j]);
      }
    }
  }
  return make_pair(user.profession, suggestionsBasedOnProfession);
}

// Suggest user suggested connections based on similar skills
map<string, set<detailsOfUser>> suggestionsBasedOnSkillsBruteForce(vector<vector<detailsOfUser>> &matrix, detailsOfUser &user) {
  // iterate through adjacency list named matrix
  // for each user, check if the user has a similar skills
  // if yes, add to a vector of suggested connections
  // return the vector
  map<string, set<detailsOfUser>> suggestedConnections;
  vector<detailsOfUser> suggestionsBasedOnSkills;
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      if(matrix[i][j] == user) 
        continue;
      for(string skill : user.skills) {
        // If same skill is found add it to suggested connections according to the skill
        if(find(matrix[i][j].skills.begin(), matrix[i][j].skills.end(), skill) != matrix[i][j].skills.end()) {
          suggestedConnections[skill].insert(matrix[i][j]);
        }
      }
    }
  }
  return suggestedConnections;
}

// Print the suggested connections
void showSuggestedConnectionsBruteForce(vector<vector<detailsOfUser>> &matrix, detailsOfUser &user) {
  // Suggest user suggested connections based on profession
  pair<string, set<detailsOfUser>> suggestedAccToProfession = suggestedConnectionsBasedOnProfessionBruteForce(matrix, user);
  cout << "Suggested connections based on profession: " << suggestedAccToProfession.first << "\n";
  for (detailsOfUser x : suggestedAccToProfession.second) {
    cout << x.name << "\n";
  }

  // Suggest user suggested connections based on similar skills
  map<string, set<detailsOfUser>> suggestedAccToSkills = suggestionsBasedOnSkillsBruteForce(matrix, user);
  cout << "\nSuggested connections based on similar skills: \n";
  for (auto x : suggestedAccToSkills) {
    cout << "Profession: " << x.first << "\n";
    for (detailsOfUser y : x.second) {
      cout << y.name << "\n";
    }
    cout << "\n";
  }
}


int main(){
    
    vector<string> skills1 = {"Web Developer", "Flutter"};
    vector<string> skills2 = {"Web Developer", "Flutter", "React"};
    vector<string> skills3 = {"Web Developer", "Flutter", "DSA"};
    vector<string> skills4 = {"Web Developer", "Flutter", "JAVA"};
    vector<string> skills5 = {"Web Developer", "Flutter", "Algo"};
    vector<string> skills6 = {"Web Developer"};
    vector<string> skills7 = {"Web Developer", "BlockChain Developer"};
    vector<string> skills8 = {"Android", "IOS Swift"};
    vector<string> skills9 = {"Web Developer", "Flutter", "CPP"};
    vector<string> skills10 = {"Web Developer", "Flutter", "DSA"};

    vector<string> skills11 = {"Web Developer", "Flutter"};
    vector<string> skills12 = {"Web Developer", "Flutter", "ML/AI"};
    vector<string> skills13 = {"ML/AI"};
    vector<string> skills14 = {"Web Developer", "React Developer"};

    vector<string> skills15 = {"Web Developer", "Flutter"};
    vector<string> skills16 = {"Web Developer", "DSA"};


    detailsOfUser User1("Dhruv", "Software Developer", 10, skills1, "I am a software Developer", 0);
    detailsOfUser User2("Kalash Shah", "React Developer", 10, skills2, "I am React Developer.", 1);
    detailsOfUser User3("Brijesh", "DSA Mentor", 9, skills3, "I love exploring DS and Algos", 2);
    detailsOfUser User4("Dhyey", "Software Developer", 8, skills4, "I am Flutter Developer", 3);
    detailsOfUser User5("Parth", "Designer", 10, skills5, "I am interested in designing", 4);
    detailsOfUser User6("Hritik", "Software Developer", 5, skills6, "I am also interested in development", 5);
    detailsOfUser User7("Kalash Kala", "Software Developer", 8, skills7, "I am also interested in development", 6);
    detailsOfUser User8("Gyan", "React Developer", 10, skills8, "I am also interested in development", 7);
    detailsOfUser User9("Jay", "DSA Mentor", 10, skills9, "I am also interested in development", 8);
    detailsOfUser User10("Kewal", "Web Developer", 10, skills10, "I am also interested in development", 9);

    detailsOfUser User11("User 11", "Flutter", 4, skills11, "I am also interested in development", 10);
    detailsOfUser User12("User 12", "ML/AI", 2, skills12, "I am also interested in development", 11);
    detailsOfUser User13("User 13", "UI/UX", 9, skills13, "I am also interested in development", 12);
    detailsOfUser User14("User 14", "Embedded Systems", 10, skills14, "I am also interested in development", 13);

    detailsOfUser User15("User 15", "Software Developer", 10, skills15, "I am also interested in development", 14);
    detailsOfUser User16("User 16", "Flutter", 8, skills16, "I am also interested in development", 15);


    addConnection(User1, User2);
    addConnection(User1, User3);
    addConnection(User2, User5);
    addConnection(User5, User4);
    addConnection(User2, User7);
    addConnection(User7, User8);
    addConnection(User8, User6);
    addConnection(User6, User1);
    addConnection(User9, User10);
    addConnection(User1, User9);

    addConnection(User11, User12);
    addConnection(User12, User13);
    addConnection(User13, User14);

    addConnection(User15, User16);

    showSuggestedConnectionsBruteForce(adjList, User1);
    
    return 0;
}