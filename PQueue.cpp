

#include "PQueue.hpp"
#include "Events.hpp"
void PQueue::push(Events *event)
{
    AQueue->orderedInsert(event);
}
bool PQueue::isEmpty()
{
    return AQueue->isEmpty();
}
Events *PQueue::pop()
{
    Events *ret = NULL;
    ret = dynamic_cast<Events *>(AQueue->pop());

    return ret;
}

void PQueue::print()
{
    AQueue->print();
}
