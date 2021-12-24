#include <bits/stdc++.h>
#include "main.cpp"
using namespace std;

class dhruv_Algo
{
public:
    vector<detailsOfUser> filtering;

    // Filtering by profession
    void filterOptions(vector<vector<detailsOfUser>> &matrix, vector<bool> &visited, detailsOfUser startVertex, string value)
    {
        // We will first filter according to profession
        if (startVertex.profession == value)
        {
            filtering.push_back(startVertex);
        }
        visited[startVertex.id] = true;
        for (auto x : matrix[startVertex.id])
        {
            if (!visited[x.id])
            {
                filterOptions(matrix, visited, x, value);
            }
        }
    }

    vector<detailsOfUser> filter(vector<vector<detailsOfUser>> &v, string value, detailsOfUser sv)
    {
        vector<bool> visited(10, false);
        for (int i = 0; i < visited.size(); i++)
        {
            if (!visited[i])
            {
                filterOptions(v, visited, sv, value);
            }
        }
        return filtering;
    }

    // filtering by experience
    void filterOptionsExp(vector<vector<detailsOfUser>> &matrix, vector<bool> &visited, detailsOfUser startVertex, int value)
    {
        if (startVertex.experience == value)
        {
            filtering.push_back(startVertex);
        }
        visited[startVertex.id] = true;
        for (auto x : matrix[startVertex.id])
        {
            if (!visited[x.id])
            {
                filterOptionsExp(matrix, visited, x, value);
            }
        }
    }

    vector<detailsOfUser> filterExp(vector<vector<detailsOfUser>> &v, int value, detailsOfUser sv)
    {
        vector<bool> visited(10, false);
        for (int i = 0; i < visited.size(); i++)
        {
            if (!visited[i])
            {
                filterOptionsExp(v, visited, sv, value);
            }
        }
        return filtering;
    }

    // Acording to skills
    void filterOptionsSkill(vector<vector<detailsOfUser>> &matrix, vector<bool> &visited, detailsOfUser startVertex, string value)
    {
        for(int i=0; i<startVertex.skills.size(); i++){
            if(startVertex.skills[i] == value){
                filtering.push_back(startVertex);
            }
        }
        visited[startVertex.id] = true;
        for (auto x : matrix[startVertex.id])
        {
            if (!visited[x.id])
            {
                filterOptionsSkill(matrix, visited, x, value);
            }
        }
    }

    vector<detailsOfUser> filterSkill(vector<vector<detailsOfUser>> &v, string skill, detailsOfUser sv)
    {
        vector<bool> visited(10, false);
        for (int i = 0; i < visited.size(); i++)
        {
            if (!visited[i])
            {
                filterOptionsSkill(v, visited, sv, skill);
            }
        }
        return filtering;
    }

};
int main()

{
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

    

    string filterBy;
    cout<<"How do you wanna filter the users: "<<"\n";
    cin>>filterBy;


    vector<detailsOfUser> result;

    dhruv_Algo dhruv;
    if (filterBy == "profession")
    {
        string value;
        cout<<"Enter the profession you are looking for: "<<"\n";
        cin.clear(); cin.sync();
        getline(cin,value);
        result = dhruv.filter(adjList, value, User1);
    }
    else if (filterBy == "experience")
    {
        int experience;
        cout<<"Enter the experience you want in the user: "<<"\n";
        cin >> experience;
        result = dhruv.filterExp(adjList, experience, User1);
    }

    else if(filterBy == "skills"){
        string skill;
        cout<<"Enter the skill you are looking for: "<<"\n";
        cin.clear(); cin.sync();
        getline(cin,skill);
        result = dhruv.filterSkill(adjList,skill,User1);
    }

    cout<<"Results: "<<"\n";
    for (int i = 0; i < result.size(); i++)
    {
        cout << i+1 << ". "<< result[i].name << "\n";
    }
    return 0;
}

/*
    Mutual Relations:
    1. If a particular user wants to have a connection with someone else then they can see mutual connections with the other person
    2. If they are sharing a common interest or same profession then they will have a suggestion to join a group.
*/