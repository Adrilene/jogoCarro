
#include <string>
#include <vector>
//#include <GL/glut.h>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

typedef struct {
    string player;
    int score;
}pontuacoes;

vector<pontuacoes> points;

int main(){
    ifstream myFileStream("rank.csv");
    if(!myFileStream.is_open()){
        cout << "fAILED" << endl;
    }
    string player;
    int score;
    string myString;
    string line;
    pontuacoes point;

    while(getline(myFileStream, line)){
        stringstream ss(line);
        getline(ss, player, ',');
        getline(ss, score, ',');
        point.player = player;
        point.score = score;
        points.push_back(point);
    }

    for(int i = 0; i<points.size(); i++){
        cout << points[i] << endl;
    }
}