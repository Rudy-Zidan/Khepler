/* 
 * File:   main.cpp
 * Author: rudy
 *
 * Created on March 21, 2013, 10:27 PM
 */

#include <cstdlib>
#include<iostream>
#include<vector>
#include"Structure/CrawlerStructure.cpp"
#include"URLConnection/URLConnection.cpp"
#include "HTML/HtmlExtractor.cpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Value *v = new Value();
    v->SetTimeSpan("x");v->SetContent("hellop");
    Link *link = new Link();
    link->SetURI("http");link->AddValue(v);
    link->AddValue(v);
    Site *s = new Site();
    s->SetKey("xo");s->AddLink(link);
    s->AddLink(link);
    CrawlerStructure cs(s);
    cs.DisplaySite();
    
    URLConnection con;
    string html(con.OpenConnection("http://en.wikipedia.org/wiki/NASA"));
    string tmp(html);
    HtmlExtractor htmlextractor;
    cout<<htmlextractor.GetText(html);
    vector<string>urilist;
    urilist = htmlextractor.GetURI(tmp);
    for(long unsigned int i =0;i<urilist.size();i++){
        cout << urilist.at(i)<<endl;
    }
    
    return 0;
}

