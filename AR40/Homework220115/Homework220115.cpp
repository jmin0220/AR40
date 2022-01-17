#include <iostream>

// _Start �������� -> �������� �˻��� ���� 
int CountFirst(const char* _Text, int _Start, const char* _FindStr)
{
    int _TextLength = 0;
    int _FindStrLength = 0;

    // _TextLength�� ���� ����
    for (int i = 0; _Text[i] != 0; i++)
    {
        _TextLength++;
    }

    // _FindStrLength�� ���� ����
    for (int i = 0; _FindStr[i] != 0; i++)
    {
        _FindStrLength++;
    }

    // �˻� ����
    // aaa eee ttt asdfasd eee
    if (_Start < _TextLength)
    {
        // �˻��� ������ ���� ���� ����
        int FoundLength = 0;

        // _Start��ġ���� �˻� ����
        for (int i = _Start; i < _TextLength; i++)
        {
            if (_Text[i] == _FindStr[FoundLength])
            {
                FoundLength++;

                if (FoundLength == _FindStrLength)
                {
                    // �˻��� ���ڿ��� ������ġ�� ��ȯ
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
        // �Է�ġ ����
        return -2;
    }
}

// _End�������� <- �������� �˻��� ���� 
int CountLast(const char* _Text, int _End, const char* _FindStr)
{
    int _TextLength = 0;
    int _FindStrLength = 0;

    // _TextLength�� ���� ����
    for (int i = 0; _Text[i] != 0; i++)
    {
        _TextLength++;
    }

    // _FindStrLength�� ���� ����
    for (int i = 0; _FindStr[i] != 0; i++)
    {
        _FindStrLength++;
    }

    // �˻� ����
    // aaa eee asdfasd eee
    if (_End < _TextLength)
    {
        // �˻��� ������ ���� ���� ����
        int FoundLength = _FindStrLength -1;

        for (int i = _End; 0 <= i; i--)
        {
            if (_Text[i] == _FindStr[FoundLength])
            {
                FoundLength--;

                if (FoundLength == 0)
                {
                    // �˻��� ���ڿ��� ������ġ�� ��ȯ
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
        // �Է�ġ ����
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
