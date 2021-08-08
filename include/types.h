#pragma once

struct AsioBased
{
};
struct LibuvBased
{
};
struct CustomThreadBased
{
};

struct LightBulbSelector
{
    AsioBased thread_selector;
};

struct ShutterSelector
{
    LibuvBased thread_selector;
};