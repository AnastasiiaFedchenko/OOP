#pragma once

class BaseManager
{
public:
    BaseManager() = default;
    ~BaseManager() = default;
};

class BaseSceneManager : public BaseManager
{
public:
    BaseSceneManager() = default;
    ~BaseSceneManager() = default;
};

class BaseDrawManager : public BaseManager
{
public:
    BaseDrawManager() = default;
    ~BaseDrawManager() = default;
};

class BaseLoadManager : public BaseManager
{
public:
    BaseLoadManager() = default;
    ~BaseLoadManager() = default;
};
