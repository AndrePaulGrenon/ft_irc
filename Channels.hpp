#ifndef CHANNELS_HPP
#define CHANNELS_HPP

#pragma once
#include <string>

class Channels
{
public:
    Channels(std::string Top);
    ~Channels();

private:
    std::string Topic;
};

#endif