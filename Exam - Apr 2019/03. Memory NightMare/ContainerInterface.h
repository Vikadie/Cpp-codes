#pragma once
#ifndef CONTAINER_INTERFACE_H
#define CONTAINER_INTERFACE_H

#include <cstddef>

class ContainerInterface {

public:
    ContainerInterface() {};

    virtual size_t getOccupiedMemory() const = 0;

    virtual ~ContainerInterface() {};
};

#endif // !CONTAINER_INTERFACE_H
