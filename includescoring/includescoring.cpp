#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


class Score {
    public: 
        int s, p, f, o, score, id;

    Score(int numSolved, int timePenalty, int timeSubmitted, int extra, int id) 
        : s(numSolved)
        , p(timePenalty)
        , f(timeSubmitted)
        , o(extra)
        , id(id)
        {
    }

    void setScore(int score){
        this -> score = score;
    }

    bool operator ==(Score other){
        return this -> s == other.s && this -> p == other.p && this -> f == other.f;
    }

    bool operator <(Score other){
        return this -> s > other.s || (this -> s == other.s && this -> p < other.p) || (this -> s == other.s && this -> p == other.p && this -> f < other.f);
    }

};

int main() {
    int numOfContestants;
    std::cin >> numOfContestants;
    std::vector<Score> contestants;
    int sTemp, pTemp, fTemp, oTemp;
    int scoresTable[] = {100, 75, 60, 50, 45, 40, 36, 32, 29, 26, 24, 22, 20, 18, 
                         16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};


    for (int i = 0; i < numOfContestants; i++) {
        std::cin >> sTemp >> pTemp >> fTemp >> oTemp;
        Score temp = Score(sTemp, pTemp, fTemp, oTemp, i);
        contestants.push_back(temp);
    }


    std::vector<Score> scoreSort = contestants;
    std::sort(scoreSort.begin(), scoreSort.end());

    for (int i = 0; i < numOfContestants; i++) {
        /*if (scoreSort[i].s == 0){
            //contestants[scoreSort[i].id].setScore(0 + contestants[scoreSort[i].id].o);
        }*/
        if (i != numOfContestants - 1 && scoreSort[i] == scoreSort[i+1]) {
            int counter = i;
            double subsetSum = 0;
            while (true) {
                if (!(scoreSort[i] == scoreSort[counter+1]) || counter == numOfContestants-1) {
                    if (counter < 30) subsetSum += scoresTable[counter];
                    break;
                } else {
                    if (counter < 30) subsetSum += scoresTable[counter];
                    counter++;
                }
            }

            double scoreSplit = std::ceil(subsetSum/(counter-i+1));
            for (int j = i; j <= counter; j++) {
                contestants[scoreSort[j].id].setScore(scoreSplit + contestants[scoreSort[j].id].o);
            }
            i = counter;
        } else if (i < 30) {
            contestants[scoreSort[i].id].setScore(scoresTable[i] + contestants[scoreSort[i].id].o);
        } else {
            contestants[scoreSort[i].id].setScore(contestants[scoreSort[i].id].o);
        }
    }


    for (const auto &contestant: contestants) {
        std::cout << contestant.score << "\n";
    }
    return 0;
}