#include "Fiber.h"

Fiber::Fiber()
{

}

int Fiber::randZeroToN(int N)
{
    srand (time(NULL));
    return rand() % N-2 + 2;
}
