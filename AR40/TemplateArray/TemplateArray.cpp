#include<iostream>
#include<assert.h>

template<typename DataType>
class GameArray
{
private:
    int Size_;
    DataType* ArrData_;

public:
    int GetCapacity()
    {
        return Size_;
    }

    DataType& operator[](int _Index)
    {
        if (Size_ <= _Index)
        {
            assert(false);
        }

        return ArrData_[_Index];
    }

    inline void operator=(const GameArray& _Other)
    {
        ReSize(_Other.Size_);

        // 이걸 쉘로우 카피 
        // 혹은 얕은 복사라고 한다.
        //this->ArrData_ = _Other.ArrData_;
        //this->Size_ = _Other.Size_;

        // 이걸 딥 카피
        // 혹은 깊은 복사라고 한다.
        for (size_t i = 0; i < this->Size_; i++)
        {
            this->ArrData_[i] = _Other.ArrData_[i];
        }

        return;
    }

    inline void AllValueSetting(const DataType& Data)
    {
        for (size_t i = 0; i < this->Size_; i++)
        {
            this->ArrData_[i] = Data;
        }
    }


    inline void Release()
    {
        if (nullptr != ArrData_)
        {
            delete[] ArrData_;
            ArrData_ = nullptr;
        }
    }

    void ReSize(unsigned int _Size)
    {
        Release();
        ArrData_ = new DataType[_Size];
        Size_ = _Size;
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

class Player
{
public:
    int Att;
    int Hp;

};

class A {

};

int main()
{
    GameArray<Player> DataArray0 = GameArray<Player>(10);

    DataArray0[0].Att = 200;

    GameArray<int> DataArray1 = GameArray<int>(5);


    for (size_t i = 0; i < DataArray0.GetCapacity(); i++)
    {
        DataArray0[i].Att = 20;
        DataArray0[i].Hp = 100;
    }

}