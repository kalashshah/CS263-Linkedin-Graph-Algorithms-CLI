#include <bits/stdc++.h>
#include "main.cpp"
using namespace std;
map<int, string> mpName;

void brijesh(vector<vector<detailsOfUser>> &adj, int id1, int id2)
{
    if (adj[id1].size() < adj[id2].size())
    {
        for (int i = 0; i < adj[id1].size(); i++)
        {
            for (int j = 0; j < adj[id2].size(); j++)
            {
                if (adj[id1][i].name == adj[id2][j].name)
                {
                    cout << adj[id1][i].name << endl;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < adj[id2].size(); i++)
        {
            for (int j = 0; j < adj[id1].size(); j++)
            {
                if (adj[id2][i].name == adj[id1][j].name)
                {
                    cout << adj[id1][i].name << endl;
                }
            }
        }
    }
}

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
    vector<string> skills9 = {"Web Developer", "Flutter", "CP"};
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

    mpName[0] = User1.name;
    mpName[1] = User2.name;
    mpName[2] = User3.name;
    mpName[3] = User4.name;
    mpName[4] = User5.name;
    mpName[5] = User6.name;
    mpName[6] = User7.name;
    mpName[7] = User8.name;
    mpName[8] = User9.name;
    mpName[9] = User10.name;
    mpName[10] = User11.name;
    mpName[11] = User12.name;
    mpName[12] = User13.name;
    mpName[13] = User14.name;
    mpName[14] = User15.name;
    mpName[15] = User16.name;

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

    cout << "Enter the names: ";
    string name1, name2;
    cin >> name1 >> name2;
    map<int, string>::iterator itr;
    int id1, id2;
    for (itr = mpName.begin(); itr != mpName.end(); itr++)
    {
        if (itr->second == name1)
            id1 = itr->first;

        if (itr->second == name2)
            id2 = itr->first;
    }
    itr = mpName.find(id1);
    cout << "Mutual Relations of " << itr->second << " and ";
    itr = mpName.find(id2);
    cout << itr->second << endl;
    brijesh(adjList, id1, id2);
}