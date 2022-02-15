#include <iostream>
#include <assert.h>
#include <crtdbg.h>

using DataType = int;

class GameArray
{
private:
    int Size_;
    DataType* ArrData_;

public:
    // �迭�� ũ�⸦ ��ȯ
    int GetSize()
    {
        return Size_;
    }
    
    // [] ������, ũ��ٱ��� �ε����� �����Ϸ��� �Ұ�� assert
    DataType& operator[](int _Index)
    {
        if (Size_ <= _Index)
        {
            assert(false);
        }

        return ArrData_[_Index];
    }

    // = ������, 
    inline void operator=(const GameArray& _Other)
    {
        ReSize(_Other.Size_);

        for (size_t i = 0; i < this->Size_; i++)
        {
            this->ArrData_[i] = _Other.ArrData_[i];
        }

        return;
    }

    // �迭 �ʱ�ȭ
    inline void AllValueSetting(const DataType& Data)
    {
        for (size_t i = 0; i < this->Size_; i++)
        {
            this->ArrData_[i] = Data;
        }
    }

    // �迭 �޸� ����
    inline void Release()
    {
        if (nullptr != ArrData_)
        {
            delete[] ArrData_;
            ArrData_ = nullptr;
        }
    }

    // �迭�� ���� ����
    void ReSize(unsigned int _Size)
    {
        DataType* TmpArrData_ = new DataType[_Size];

        // �޸� ������ �����͸� ���� ����
        for (size_t i = 0; i < _Size; i++)
        {
            if (i >= Size_)
            {
                break;
            }

            TmpArrData_[i] = ArrData_[i];
        }

        Release();
        ArrData_ = new DataType[_Size];
        Size_ = _Size;

        // ���Ӱ� ������ ArrData_�� �����صξ��� tmp�����͸� ��������
        for (size_t i = 0; i < Size_; i++)
        {
            ArrData_[i] = TmpArrData_[i];
        }

    }

public:
    GameArray(unsigned int _Size)
        : ArrData_(nullptr)
        , Size_(0)
    {
        ReSize(_Size);
    }

    ~GameArray()
    {
        Release();
    }
};

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    GameArray NewArray = GameArray(10);
    // GameArray NewArray2 = GameArray(5);
    // GameArray NewArray2 = GameArray(20);

    int Size = sizeof(GameArray);

    for (size_t i = 0; i < NewArray.GetSize(); i++)
    {
        NewArray[i] = i;
    }

    // ����׽�Ʈ---------------
    for (size_t i = 0; i < NewArray.GetSize(); i++)
    {
        std::cout << "NewArray >> " << NewArray[i] << std::endl;
    }
    // ����׽�Ʈ---------------


    // ���� �� ������ + �����Ⱚ[10]
    NewArray.ReSize(20);

    // ����׽�Ʈ---------------
    for (size_t i = 0; i < NewArray.GetSize(); i++)
    {
        std::cout << "NewArray >> " << NewArray[i] << std::endl;
    }
    // ����׽�Ʈ---------------


    // ���� �� ������[5]
    NewArray.ReSize(5);

    // ����׽�Ʈ---------------
    for (size_t i = 0; i < NewArray.GetSize(); i++)
    {
        std::cout << "NewArray >> " << NewArray[i] << std::endl;
    }
    // ����׽�Ʈ---------------


    // ���� �� ������[5] + �����Ⱚ[5]
    NewArray.ReSize(10);

    // ����׽�Ʈ---------------
    for (size_t i = 0; i < NewArray.GetSize(); i++)
    {
        std::cout << "NewArray >> " << NewArray[i] << std::endl;
    }
    // ����׽�Ʈ---------------

    std::cout << "Hello World!\n";
}