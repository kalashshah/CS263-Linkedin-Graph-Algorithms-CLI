#include <bits/stdc++.h>
#include "main.cpp"
using namespace std;

map<int, vector<string>> mp;
map<int, string> mpName;


class dhyeyAlgo {
    public:
    // mutual interests
    void solver(vector<vector<detailsOfUser>> &v, string name){
        int userID;
        bool a = false;

        for(int i=0; i<v.size(); i++){
            for(int j=0; j<v[i].size(); j++){
                if(v[i][j].name == name){
                    userID = v[i][j].id;
                    a = true;
                    break;
                }
                cout<<v[i][j].name<<" ";
            }
            if(a){
                break;
            }
        }

        vector<string> skills = mp[userID];
        int size = skills.size();
        map<int,vector<string>>:: iterator itr;
        vector<pair<int,int>> vec;

        int counter = 0;
        for(itr = mp.begin(); itr != mp.end(); itr++){
            counter = 0;
            if(itr->first != userID){
                for(int i=0; i<skills.size(); i++){ // 2
                    for(int j=0; j<itr->second.size(); j++){ // 2 --> 1
                        if(itr->second[i] == skills[j]){
                            counter++;
                            break;
                        }
                    }
                }
                vec.push_back({counter, itr->first});

            }
        }

        sort(vec.rbegin(), vec.rend());
        
        vector<pair<int,int>>::iterator it;
        for(it = vec.begin(); it != vec.end(); it++){
            cout<<mpName[it->second]<<"\n";
        }

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
    vector<string> skills9 = {"Web Developer", "Flutter", "CP"};
    vector<string> skills10= {"Web Developer", "Flutter", "DSA"};

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

    mp[0] = skills1;
    mp[1] = skills2;
    mp[2] = skills3;
    mp[3] = skills4;
    mp[4] = skills5;
    mp[5] = skills6;
    mp[6] = skills7;
    mp[7] = skills8;
    mp[8] = skills9;
    mp[9] = skills10;
    mp[10] = skills11;
    mp[11] = skills12;
    mp[12] = skills13;
    mp[13] = skills14;
    mp[14] = skills15;
    mp[15] = skills16;

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

    // mutual interest
    string name;
    cin.clear(); cin.sync();
    getline(cin,name);


    // calling
    dhyeyAlgo dhyey;
    dhyey.solver(adjList,name);
    return 0;
}