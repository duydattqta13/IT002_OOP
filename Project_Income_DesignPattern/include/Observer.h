#ifndef OBSERVER_H
#define OBSERVER_H

#include <bits/stdc++.h>
#include "Subject.h"

using namespace std;
class Subject;

class Observer
{
    public:

        Observer();
        virtual ~Observer();

        virtual void update(Subject *subject, int type) = 0;

    protected:

    private:
};

#endif // OBSERVER_H
