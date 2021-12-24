#include <bits/stdc++.h>
#include "main.cpp"
using namespace std;

map<int, detailsOfUser*> mp;

// Suggest users based on profession using brute force
pair<string, set<detailsOfUser>> suggestBasedOnProfessionBruteForce(vector<vector<detailsOfUser>> &matrix, detailsOfUser &user) {
  // iterate through adjacency list named matrix
  // for each user, check if the user has same profession
  // if yes, add to a set of suggested users
  // return the set
  set<detailsOfUser> suggestionsBasedOnProfession;
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      bool isAlreadyConnected = find(adjList[user.id].begin(), adjList[user.id].end(), matrix[i][j]) != adjList[user.id].end();
      if (matrix[i][j].profession == user.profession && !(matrix[i][j] == user) && !isAlreadyConnected) {
        suggestionsBasedOnProfession.insert(matrix[i][j]);
      }
    }
  }
  return make_pair(user.profession, suggestionsBasedOnProfession);
}

// Suggest users based on profession using DFS traversal algorithm
pair<string, vector<detailsOfUser>> suggestBasedOnProfession(vector<vector<detailsOfUser>> &matrix, detailsOfUser &user) {
  // Add the user to the vector if the user has same profession
  vector<detailsOfUser> suggestionsBasedOnProfession;
  // visited array to keep track of visited nodes
  vector<bool> visited(matrix.size(), false);
  // stack for dfs traversal
  stack<int> st;
  int idd = user.id;
  st.push(idd);
  while(!st.empty()) {
    idd = st.top();
    st.pop();
    if(!visited[idd]) {
      bool isAlreadyConnected = find(adjList[user.id].begin(), adjList[user.id].end(), *mp[idd]) != adjList[user.id].end();
      if((*mp[idd]).profession == user.profession && !(*mp[idd] == user) && !isAlreadyConnected) {
        suggestionsBasedOnProfession.push_back(*mp[idd]);
      }
      visited[idd] = true;
    }
    for(auto i = adjList[idd].begin(); i != adjList[idd].end(); i++) {
      if(!visited[i->id]) {
        st.push(i->id);
      }
    }
  }
  return make_pair(user.profession, suggestionsBasedOnProfession);
}

// Suggest users based on similar skills using Brute Force
map<string, set<detailsOfUser>> suggestBasedOnSkillsBruteForce(vector<vector<detailsOfUser>> &matrix, detailsOfUser &user) {
  // iterate through adjacency list named matrix
  // for each user, check if the user has a similar skills
  // if yes, add to a set of suggested connections
  // return the set
  map<string, set<detailsOfUser>> suggestedConnections;
  vector<detailsOfUser> suggestionsBasedOnSkills;
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      bool isAlreadyConnected = find(adjList[user.id].begin(), adjList[user.id].end(), matrix[i][j]) != adjList[user.id].end();
      if(matrix[i][j] == user || isAlreadyConnected) 
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

// Suggest users based on similar skills using DFS traversal
map<string, vector<detailsOfUser>> suggestBasedOnSkills(vector<vector<detailsOfUser>> &matrix, detailsOfUser &user) {
  map<string, vector<detailsOfUser>> suggested;
  // visited array to keep track of visited nodes
  vector<bool> visited(matrix.size(), false);
  // stack for dfs traversal
  stack<int> st;
  int idd = user.id;
  st.push(idd);
  while(!st.empty()) {
    idd = st.top();
    st.pop();
    if(!visited[idd]) {
      // cout << idd << endl;
      bool isAlreadyConnected = find(adjList[user.id].begin(), adjList[user.id].end(), *mp[idd]) != adjList[user.id].end();
      if(!isAlreadyConnected) {
        for(string skill : user.skills) {
        // If same skill is found add it to suggested connections according to the skill
        if(find((*mp[idd]).skills.begin(), (*mp[idd]).skills.end(), skill) != (*mp[idd]).skills.end() && !(*mp[idd] == user)) {
          suggested[skill].push_back(*mp[idd]);
        }
      }
      }
      visited[idd] = true;
    }
    for(auto i = adjList[idd].begin(); i != adjList[idd].end(); i++) {
      if(!visited[i->id]) {
        st.push(i->id);
      }
    }
  }
  return suggested;
}

// Print the suggested connections
void showSuggestionsBruteForce(vector<vector<detailsOfUser>> &matrix, detailsOfUser &user) {
  // Suggest user suggested connections based on profession
  pair<string, set<detailsOfUser>> suggestedAccToProfession = suggestBasedOnProfessionBruteForce(matrix, user);
  cout << "Suggested users based on profession: " << suggestedAccToProfession.first << "\n";
  for (detailsOfUser x : suggestedAccToProfession.second) {
    cout << x.name << "\n";
  }

  // Suggest user suggested connections based on similar skills
  map<string, set<detailsOfUser>> suggestedAccToSkills = suggestBasedOnSkillsBruteForce(matrix, user);
  cout << "\nSuggest users based on similar skills: \n";
  for (auto x : suggestedAccToSkills) {
    cout << "Skill: " << x.first << "\n";
    for (detailsOfUser y : x.second) {
      cout << y.name << "\n";
    }
    cout << "\n";
  }
}

void showSuggestions(vector<vector<detailsOfUser>> &matrix, detailsOfUser &user) {
  pair<string, vector<detailsOfUser>> suggestedAccToProfession = suggestBasedOnProfession(matrix, user);
  cout << "Suggested users based on profession: " << suggestedAccToProfession.first << "\n";
  for (detailsOfUser x : suggestedAccToProfession.second) {
    cout << x.name << "\n";
  }

  map<string, vector<detailsOfUser>>suggestedAccToSkills = suggestBasedOnSkills(matrix, user);
  cout << "\nSuggest users based on similar skills: \n";
  for (auto x : suggestedAccToSkills) {
    cout << "Skill: " << x.first << "\n";
    for (detailsOfUser y : x.second) {
      cout << y.name << "\n";
    }
    cout << "\n";
  }
}


int main() {
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
  
  mp.insert(make_pair(0, new detailsOfUser(User1)));
  mp.insert(make_pair(1, new detailsOfUser(User2)));
  mp.insert(make_pair(2, new detailsOfUser(User3)));
  mp.insert(make_pair(3, new detailsOfUser(User4)));
  mp.insert(make_pair(4, new detailsOfUser(User5)));
  mp.insert(make_pair(5, new detailsOfUser(User6)));
  mp.insert(make_pair(6, new detailsOfUser(User7)));
  mp.insert(make_pair(7, new detailsOfUser(User8)));
  mp.insert(make_pair(8, new detailsOfUser(User9)));
  mp.insert(make_pair(9, new detailsOfUser(User10)));

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

  // Call functions
  cout << "Brute force algorithms\n"; 
  showSuggestionsBruteForce(adjList, User1);
  cout << "DFS algorithms\n";
  showSuggestions(adjList, User1);
  
  return 0;
}
