#pragma once
namespace test
{
    class context
    {
        void* _data;
    public:
        virtual ~context() = 0;
    };
}
