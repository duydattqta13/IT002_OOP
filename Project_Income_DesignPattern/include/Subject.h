#ifndef SUBJECT_H
#define SUBJECT_H

#include <bits/stdc++.h>
#include "Observer.h"

using namespace std;
class Observer;

class Subject{
    public:
        Subject();
        Subject(int More);

        void addObserver (Observer *observer, int type);

        void notify (int type);

        virtual ~Subject();

    protected:

    private:
        vector <pair<int, Observer * > > observerList;
        int more = 0;
};

#endif // SUBJECT_H
