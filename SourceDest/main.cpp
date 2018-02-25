//
//  main.cpp
//  SourceDest
//
//  Created by Tapas Behera on 2/23/18.
//  Copyright © 2018 com.tapas. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include "SourceDest.hpp"

using namespace std;

bool isCorrectImpl(string input,string output);

int main(int argc, const char * argv[]) {
    // Test cases for isNeighbour
    printf("--Test cases for isNeighbour--\n");
    SourceDest* s = new SourceDest();
    s->isNeighbour("aaaaa", "aaaab") ? printf("passed\n"):printf("failed\n");
    s->isNeighbour("aaacb", "aaaab") ? printf("passed\n"):printf("failed\n");
    s->isNeighbour("aadcb", "aaacb") ? printf("passed\n"):printf("failed\n");
    s->isNeighbour("aedcb", "aadcb") ? printf("passed\n"):printf("failed\n");
    s->isNeighbour("fedcb", "aedcb") ? printf("passed\n"):printf("failed\n");
    s->isNeighbour("aaaaa", "aaabb") ? printf("failed\n"):printf("passed\n");
    s->isNeighbour("aaabb", "aaccb") ? printf("failed\n"):printf("passed\n");
    s->isNeighbour("aaccb", "aaaaa") ? printf("failed\n"):printf("passed\n");
    s->isNeighbour("ddddd", "aaabb") ? printf("failed\n"):printf("passed\n");
    s->isNeighbour("ddddd", "aaaad") ? printf("failed\n"):printf("passed\n");
    
    // Test cases for neighbour closest to dest
    printf("--Test cases for neighbour closest to dest--\n");
    //Test Case - 1
    set<string> dictionary{"start","stark","stack","slack","black","blank","bland","brand","braid","brain"};
    "start"==s->neighbourClosestToDest("smart", "brain", dictionary) ? printf("passed\n"):printf("failed\n");
    
    //Test Case - 2
    set<string> dictionary1{"smark","smark"};
    "smark"==s->neighbourClosestToDest("smart", "smark", dictionary1) ? printf("passed\n"):printf("failed\n");
    
    //Test Case - 3
    set<string> dictionary2{"bbcde","abcee","abcdf"};
    "abcdf"==s->neighbourClosestToDest("abcde", "abcdf", dictionary2) ? printf("passed\n"):printf("failed\n");
    
    //Test Case - 4
    set<string> dictionary4{"abcee","abcdf","bbcde"};
    "bbcde"==s->neighbourClosestToDest("abcde", "bbcde", dictionary2) ? printf("passed\n"):printf("failed\n");
    
    //Test Case - 5
    set<string> dictionary5{"accde","aaade","abcee","accda","aaaae","aaaaa","abcdf","aacde","aaaaa"};
    "aacde"==s->neighbourClosestToDest("abcde", "aaaaa", dictionary5) ? printf("passed\n"):printf("failed\n");
    
    printf("--Test cases for shorted path--\n");
    // Test Cases for finding shorted path
    // Test Case - 1
    string input = "smart,start,stark,stack,slack,black,blank,bland,brand,braid,brain";
    string output = "smart,start,stark,stack,slack,black,blank,bland,brand,braid,brain";
    (isCorrectImpl(input,output)) ? printf("passed\n"):printf("failed\n");
    
    // Test Case - 2
    input = "smart,smark,smark";
    output = "smart,smark";
    (isCorrectImpl(input,output)) ? printf("passed\n"):printf("failed\n");
    
    // Test Case - 3
    input = "abcde,bbcde,abcee,abcdf";
    output = "abcde,abcdf";
    (isCorrectImpl(input,output)) ? printf("passed\n"):printf("failed\n");
    
    // Test Case - 4
    input = "abcde,abcee,abcdf,bbcde";
    output = "abcde,bbcde";
    (isCorrectImpl(input,output)) ? printf("passed\n"):printf("failed\n");
    
    // Test Case - 5
    input = "abcde,accde,abcee,abcdf,bbcde";
    output = "abcde,bbcde";
    (isCorrectImpl(input,output)) ? printf("passed\n"):printf("failed\n");
    
    // Test Case - 6
    input = "abcde,accde,aaade,abcee,accda,aaaae,aaaaa,abcdf,aacde,aaaaa";
    output = "abcde,aacde,aaade,aaaae,aaaaa";
    (isCorrectImpl(input,output)) ? printf("passed\n"):printf("failed\n");
    
    // Test Case - 7
    input = "abcde,accde,abcee,accda,aaaae,aaada,aacda,aaaaa,abcdf,aacde,aaaaa";
    output = "abcde,aacde,aacda,aaada,aaaaa";
    (isCorrectImpl(input,output)) ? printf("passed\n"):printf("failed\n");
    
    // Test Case - 8
    input = "abcde,accde,abcee,accda,aaaae,aaada,aacda,aaaaa,abcdf,aacde,aaaaa";
    output = "abcde,aacde,aacda,aaada,aaaaa";
    (isCorrectImpl(input,output)) ? printf("passed\n"):printf("failed\n");
    
    return 0;
}

bool isCorrectImpl(string input,string output){
    string source;
    string dest;
    set<string> words;
    string tmp="";
    int count = 0;
    for(int i=0;i<input.length();i++){
        if(input.at(i)==','){
            if(count==0){
                source = tmp;
            }else{
                words.insert(tmp);
            }
            tmp  = "";
            count++;
        }else{
            tmp = tmp + input.at(i);
        }
    }
    dest = tmp;
    SourceDest* s = new SourceDest();
    vector<string> path = s->getPath(source, dest, words);
    string calculatedPath = "";
    for(int i=0;i<path.size();i++){
        if(i==path.size()-1){
            calculatedPath = calculatedPath + path[i];
        }else{
            calculatedPath = calculatedPath + path[i] + ",";
        }
    }
    calculatedPath = source + "," + calculatedPath;
    
    if(calculatedPath.compare(output)==0){
        return true;
    }
    return false;
}

