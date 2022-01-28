#ifndef MONITOR_ITEM_HPP
#define MONITOR_ITEM_HPP

#include <gui_generated/containers/Monitor_ItemBase.hpp>

class Monitor_Item : public Monitor_ItemBase
{
public:
    Monitor_Item();
    virtual ~Monitor_Item() {}

    virtual void initialize();
protected:
};

#endif // MONITOR_ITEM_HPP
