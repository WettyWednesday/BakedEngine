#ifndef BASELEAF_H
#define BASELEAF_H

#include <utility>

class BaseLeaf
{
public:
    virtual ~BaseLeaf() = default;

protected:
    virtual void setPosition(int _x, int _y);
    virtual std::pair<int,int> getPosition();

private:
    int posX = 0;
    int posY = 0;
};


#endif //BASELEAF_H
