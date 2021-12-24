#include <bits/stdc++.h>
#include "main.cpp"
using namespace std;

// Suggest user suggested connections based on profession
pair<string, vector<detailsOfUser>> suggestedConnectionsBasedOnProfession(vector<vector<detailsOfUser>> &matrix, detailsOfUser &user) {
  // iterate through adjacency list named matrix
  // for each user, check if the user has same profession
  // if yes, add to a vector of suggested connections
  // return the vector
  vector<detailsOfUser> suggestionsBasedOnProfession;
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      if (matrix[i][j].profession == user.profession) {
        suggestionsBasedOnProfession.push_back(matrix[i][j]);
      }
    }
  }
  return make_pair(user.profession, suggestionsBasedOnProfession);
}

// Suggest user suggested connections based on similar skills
map<string, vector<detailsOfUser>> suggestionsBasedOnSkills(vector<vector<detailsOfUser>> &matrix, detailsOfUser &user) {
  // iterate through adjacency list named matrix
  // for each user, check if the user has a similar skills
  // if yes, add to a vector of suggested connections
  // return the vector
  map<string, vector<detailsOfUser>> suggestedConnections;
  vector<detailsOfUser> suggestionsBasedOnSkills;
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      for(string skill : user.skills) {
        // If same skill is found add it to suggested connections according to the skill
        if(find(matrix[i][j].skills.begin(), matrix[i][j].skills.end(), skill) != matrix[i][j].skills.end()) {
          suggestedConnections[skill].push_back(matrix[i][j]);
        }
      }
    }
  }
  return suggestedConnections;
}

// Print the suggested connections
void showSuggestedConnections(vector<vector<detailsOfUser>> &matrix, detailsOfUser &user) {
  // Suggest user suggested connections based on profession
  pair<string, vector<detailsOfUser>> suggestedAccToProfession = suggestedConnectionsBasedOnProfession(matrix, user);
  cout << "Suggested connections based on profession: " << suggestedAccToProfession.first << "\n";
  for (detailsOfUser x : suggestedAccToProfession.second) {
    cout << x.name << "\n";
  }

  // Suggest user suggested connections based on similar skills
  map<string, vector<detailsOfUser>> suggestedAccToSkills = suggestionsBasedOnSkills(matrix, user);
  cout << "\nSuggested connections based on similar skills: \n";
  for (auto x : suggestedAccToSkills) {
    cout << x.first << "\n";
    for (detailsOfUser y : x.second) {
      cout << y.name << "\n";
    }
  }
}
