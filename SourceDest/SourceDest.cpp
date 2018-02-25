//
//  SourceDest.cpp
//  SourceDest
//
//  Created by Tapas Behera on 2/23/18.
//  Copyright © 2018 com.tapas. All rights reserved.
//

#include "SourceDest.hpp"
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <thread>

vector<string> SourceDest::getPath(string source, string dest, set<string> words){
    vector<string> retArray;
    queue<string> q;
    q.push(source);
    words.insert(dest);
    while(!q.empty()){
        string currentWord = q.front();
        q.pop();
        string tmp = neighbourClosestToDest(currentWord,dest,words);
        if(!tmp.empty()){
            words.erase(tmp);
            retArray.push_back(tmp);
            if(tmp.compare(dest)==0){
                return retArray;
            }else{
                q.push(tmp);
            }
        }
    }
    retArray.clear();
    return retArray;
}

string SourceDest::neighbourClosestToDest(string word,string dest,set<string>& words){
    int min = INT_MAX;
    string ret;
    set<string>::iterator it = words.begin();
    while(it!=words.end()){
        string tmp = *it;
        it++;
        if(isNeighbour(word,tmp)){
            int diff = 0;
            size_t n = tmp.length();
            for (int i = 0; i < n; i++)
            {
                if (dest[i] != tmp[i]) diff++;
            }
            if(diff<min){
                min = diff;
                ret = tmp;
            }
        }
    }
    return ret;
}

bool SourceDest::isNeighbour(string word,string nextWord){
    int count = 0;
    size_t n = word.length();
    for (int i = 0; i < n; i++)
    {
        if (word[i] != nextWord[i]){
            count++;
            if (count > 1)
            {
                return false;
            }
        }
    }
    return true;
}

