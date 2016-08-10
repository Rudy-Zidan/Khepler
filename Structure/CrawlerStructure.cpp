#include<vector>
#include<string>
#include<iostream>


using namespace std;


class Value{
private:
    string timespan;
    string content;
public:
    Value(){timespan="";content="";}
    Value(string timespan,string content){
        this->timespan = timespan;
        this->content = content;
    }
    void SetTimeSpan(string timespan){this->timespan.append(timespan);}
    void SetContent(string content){this->content = content;}
    string GetTimeSpan(){return this->timespan;}
    string GetContent(){return this->content;}
   ~Value(){}
};


class Link{
private:
    string uri;
    vector<Value*>valuelist;
public:
    Link(){}
    Link(string uri,Value *value){this->uri = uri;this->valuelist.push_back(value);}
    void SetURI(string uri){this->uri = uri;}
    void AddValue(Value *value){this->valuelist.push_back(value);}
    string GetURI(){return this->uri;}
    vector<Value*> GetValue(){return this->valuelist;}
    void DisplayValue(){
      for(long unsigned int i=0; i<this->valuelist.size();i++){
          cout<<this->valuelist.at(i)->GetTimeSpan()<<" : "<<this->valuelist.at(i)->GetContent()<<endl;
      }  
    }
    ~Link(){
//       for(long unsigned int i=0; i<this->valuelist.size();i++){
//           delete this->valuelist.at(i);
//      }
//       this->valuelist.clear();
    }
};


class Site{
private:
    string key;
    vector<Link*>linklist;
public:
    Site(){}
    Site(string key,Link *link){this->key = key;this->linklist.push_back(link);}
    void SetKey(string key){this->key = key;}
    void AddLink(Link *link){this->linklist.push_back(link);}
    string GetKey(){return this->key;}
    vector<Link*> GetLink(){return this->linklist;}
    void DisplayLink(){
        for(long unsigned int i=0;i<this->linklist.size();i++){
            this->linklist.at(i)->DisplayValue();
        }
    }
    ~Site(){
//        for(long unsigned int i=0;i<this->linklist.size();i++){
//            delete this->linklist.at(i);
//        }
//        this->linklist.clear();
    }
};


class CrawlerStructure{
private:
    vector<Site*>sitelist;
public:
    CrawlerStructure(){}
    CrawlerStructure(Site *site){this->sitelist.push_back(site);}
    void AddSite(Site *site){this->sitelist.push_back(site);}
    void DisplaySite(){
        for(long unsigned int i=0;i<this->sitelist.size();i++){
            this->sitelist[i]->DisplayLink();
        }
    }
    ~CrawlerStructure(){
//        for(long unsigned int i=0;i<this->sitelist.size();i++){
//            delete this->sitelist.at(i);
//        }
//        this->sitelist.clear();
    }
};
