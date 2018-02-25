//
//  SourceDest.hpp
//  SourceDest
//
//  Created by Tapas Behera on 2/23/18.
//  Copyright © 2018 com.tapas. All rights reserved.
//

#ifndef SourceDest_hpp
#define SourceDest_hpp

#include <stdio.h>
#include <string>
#include <set>

using namespace std;

class SourceDest
{
public:
    vector<string> getPath(string source,string dest,set<string> words);
    
    // This to function finally should be private. Made public to run test cases
    bool isNeighbour(string word,string nextWord);
    string neighbourClosestToDest(string word,string dest,set<string>& words);
    
private:
    
    
    
};

#endif /* SourceDest_hpp */
