#include "Subject.h"

Subject::Subject()
{
    //ctor
}

Subject::Subject(int More)
{
    more = More;
}

Subject::~Subject()
{
    //dtor
}

void Subject::addObserver (Observer *observer, int type){
    observerList.push_back({type, observer});
    observer->update(this, type);
}

void Subject::notify (int type){
    typename vector<pair<int, Observer * >>::iterator it;
    for (it = observerList.begin(); it!=observerList.end(); it++)
        if((*it).first == type){
            (*it).second->update(this, type);
        }
}
