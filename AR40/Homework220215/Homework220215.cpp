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
    // 배열의 크기를 반환
    int GetSize()
    {
        return Size_;
    }
    
    // [] 연산자, 크기바깥의 인덱스를 참조하려고 할경우 assert
    DataType& operator[](int _Index)
    {
        if (Size_ <= _Index)
        {
            assert(false);
        }

        return ArrData_[_Index];
    }

    // = 연산자, 
    inline void operator=(const GameArray& _Other)
    {
        ReSize(_Other.Size_);

        for (size_t i = 0; i < this->Size_; i++)
        {
            this->ArrData_[i] = _Other.ArrData_[i];
        }

        return;
    }

    // 배열 초기화
    inline void AllValueSetting(const DataType& Data)
    {
        for (size_t i = 0; i < this->Size_; i++)
        {
            this->ArrData_[i] = Data;
        }
    }

    // 배열 메모리 해제
    inline void Release()
    {
        if (nullptr != ArrData_)
        {
            delete[] ArrData_;
            ArrData_ = nullptr;
        }
    }

    // 배열의 길이 설정
    void ReSize(unsigned int _Size)
    {
        DataType* TmpArrData_ = new DataType[_Size];

        // 메모리 해제전 데이터를 깊은 복사
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

        // 새롭게 설정된 ArrData_에 저장해두었던 tmp데이터를 깊은복사
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

    // 출력테스트---------------
    for (size_t i = 0; i < NewArray.GetSize(); i++)
    {
        std::cout << "NewArray >> " << NewArray[i] << std::endl;
    }
    // 출력테스트---------------


    // 값이 잘 보존됨 + 쓰레기값[10]
    NewArray.ReSize(20);

    // 출력테스트---------------
    for (size_t i = 0; i < NewArray.GetSize(); i++)
    {
        std::cout << "NewArray >> " << NewArray[i] << std::endl;
    }
    // 출력테스트---------------


    // 값이 잘 보존됨[5]
    NewArray.ReSize(5);

    // 출력테스트---------------
    for (size_t i = 0; i < NewArray.GetSize(); i++)
    {
        std::cout << "NewArray >> " << NewArray[i] << std::endl;
    }
    // 출력테스트---------------


    // 값이 잘 보존됨[5] + 쓰레기값[5]
    NewArray.ReSize(10);

    // 출력테스트---------------
    for (size_t i = 0; i < NewArray.GetSize(); i++)
    {
        std::cout << "NewArray >> " << NewArray[i] << std::endl;
    }
    // 출력테스트---------------

    std::cout << "Hello World!\n";
}