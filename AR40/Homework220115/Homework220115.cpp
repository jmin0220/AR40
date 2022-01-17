#include <iostream>

// _Start 지점부터 -> 방향으로 검색을 시작 
int CountFirst(const char* _Text, int _Start, const char* _FindStr)
{
    int _TextLength = 0;
    int _FindStrLength = 0;

    // _TextLength의 길이 측정
    for (int i = 0; _Text[i] != 0; i++)
    {
        _TextLength++;
    }

    // _FindStrLength의 길이 측정
    for (int i = 0; _FindStr[i] != 0; i++)
    {
        _FindStrLength++;
    }

    // 검색 시작
    // aaa eee ttt asdfasd eee
    if (_Start < _TextLength)
    {
        // 검색한 글자의 길이 저장 변수
        int FoundLength = 0;

        // _Start위치부터 검색 시작
        for (int i = _Start; i < _TextLength; i++)
        {
            if (_Text[i] == _FindStr[FoundLength])
            {
                FoundLength++;

                if (FoundLength == _FindStrLength)
                {
                    // 검색한 문자열의 시작위치를 반환
                    return i - FoundLength + 1;
                }
            }
            else
            {
                FoundLength = 0;
            }
        }

        // not found
        return -1;
    }
    else
    {
        // 입력치 오류
        return -2;
    }
}

// _End지점부터 <- 방향으로 검색을 시작 
int CountLast(const char* _Text, int _End, const char* _FindStr)
{
    int _TextLength = 0;
    int _FindStrLength = 0;

    // _TextLength의 길이 측정
    for (int i = 0; _Text[i] != 0; i++)
    {
        _TextLength++;
    }

    // _FindStrLength의 길이 측정
    for (int i = 0; _FindStr[i] != 0; i++)
    {
        _FindStrLength++;
    }

    // 검색 시작
    // aaa eee asdfasd eee
    if (_End < _TextLength)
    {
        // 검색한 글자의 길이 저장 변수
        int FoundLength = _FindStrLength -1;

        for (int i = _End; 0 <= i; i--)
        {
            if (_Text[i] == _FindStr[FoundLength])
            {
                FoundLength--;

                if (FoundLength == 0)
                {
                    // 검색한 문자열의 시작위치를 반환
                    return i - 1;
                }
            }
            else
            {
                FoundLength = _FindStrLength -1;
            }
        }

        // not found
        return -1;
    }
    else
    {
        // 입력치 오류
        return -2;
    }
}


int main()
{
    int Count1 = CountFirst("abcdeeefg", 0, "eee");
    int Count2 = CountLast("hijkkklmnop", 10, "kkk");
    

    std::cout << Count1 << "\n";
    std::cout << Count2 << "\n";
}
