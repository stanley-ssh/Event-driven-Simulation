#include "Events.hpp"

#include "PQueue.hpp"
class EventsList : public PQueue  {
    private:
    PQueue * alist ;
    public:
    EventsList(){
        alist = new PQueue();
    }
};