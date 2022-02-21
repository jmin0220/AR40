#include <iostream>
#include <vector>
#include <conio.h>

template<typename DataType>
class DataNode
{
public:
    DataType Data;
    DataNode* Next;
};

class Action
{
public:
    const char* ActionName;
    std::vector<Action*> NextSkill_;

public:
    Action* KeyCheck()
    {
        std::cout << ActionName << " Start" << std::endl;

        int Value = _getch();

        if (0 == NextSkill_.size())
        {
            std::cout << " Action End " << std::endl;
            return nullptr;
        }

        if (Value == 'a')
        {
            return NextSkill_[0];
        }
        if (Value == 's')
        {
            return NextSkill_[1];
        }

        return nullptr;
    }
};


int main()
{
    // 이니셜라이저 리스트 초기화가 가능하다.
    DataNode<int> Node0 = { 1, nullptr };
    DataNode<int> Node1 = { 2, nullptr };
    DataNode<int> Node2 = { 3, nullptr };
    DataNode<int> Node3 = { 4, nullptr };
    DataNode<int> Node4 = { 5, nullptr };
    DataNode<int> Node5 = { 6, nullptr };

    Node0.Next = &Node1;
    Node1.Next = &Node2;
    Node2.Next = &Node3;
    Node3.Next = &Node4;
    Node4.Next = &Node5;

    DataNode<int>* NewPtr = &Node0;

    while (nullptr != NewPtr)
    {
        std::cout << NewPtr->Data << std::endl;
        NewPtr = NewPtr->Next;
    }

    Action sAction0 = { "약공0" };
    Action sAction1 = { "약공1" };
    Action sAction2 = { "약공2" };

    Action pAction0 = { "강공0" };
    Action pAction1 = { "강공1" };
    Action pAction2 = { "강공2" };

    sAction0.NextSkill_.push_back(&sAction1);
    sAction0.NextSkill_.push_back(&pAction1);

    sAction1.NextSkill_.push_back(&sAction2);
    sAction1.NextSkill_.push_back(&pAction2);

    pAction0.NextSkill_.push_back(&sAction1);
    pAction0.NextSkill_.push_back(&pAction1);

    pAction1.NextSkill_.push_back(&sAction2);
    pAction1.NextSkill_.push_back(&pAction2);

    int Value = _getch();

    Action* CurAction = nullptr;
    if (Value == 'a')
    {
        CurAction = &sAction0;
    }
    if (Value == 's')
    {
        CurAction = &pAction0;
    }

    while (nullptr != CurAction)
    {
        CurAction = CurAction->KeyCheck();
    }


    std::cout << "Hello World!\n";
}
