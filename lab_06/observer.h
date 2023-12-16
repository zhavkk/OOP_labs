#pragma once
#include <iostream>
#include <fstream>
#include <memory>

class NPC;

class Observer {
public:
    Observer() = default;
    virtual void update(NPC*, NPC*, bool) = 0;
};

class ConsoleObserver: public Observer {
public:
    ConsoleObserver() = default;
    void update(NPC*, NPC*, bool) override;
};

class FileObserver: public Observer {
    std::unique_ptr<std::ostream> _stream;
public:
    FileObserver(std::ofstream&);
    
    void update(NPC*, NPC*, bool) override;
};