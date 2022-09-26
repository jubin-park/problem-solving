# [3차] 파일명 정렬
* 범주: 2018 KAKAO BLIND RECRUITMENT
* 레벨: 2
* 날짜: 2022-09-05
* 소요시간: 29 분
* 링크: https://school.programmers.co.kr/learn/courses/30/lessons/17686

# 설명
`FilenameInfo` 클래스를 만들었다.
`Head`는 Windows 처럼 대소문자를 구별하지 않는다. `Number`는 int형으로 변환했다. `Tail`은 굳이 만들 필요가 없어서 뺐다. 그 대신, 입력 순서를 유지해야 하므로 `Seq` 멤버에 배열의 index position을 등록했다. STL의 sort 함수와 Compare를 정의하여 문제를 해결했다.

# 소스코드
```cpp
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class FilenameInfo
{
public:
    FilenameInfo(const string& filename, const int seq)
        : Number(0)
        , Seq(seq)
    {
        Src = filename;
        const char* p = filename.c_str();
        while (*p < '0' || *p > '9')
        {
            if (*p >= 'A' && *p <= 'Z')
            {
                Head += *p++ | 0x20;
            }
            else
            {
                Head += *p++;
            }
        }
        while (*p >= '0' && *p <= '9')
        {
            Number *= 10;
            Number += *p++ - '0';
        }
        cout << Head << '\t' << Number << '\t' << Seq << '\n';
    }
    
    string Src;
    string Head;
    int Number;
    int Seq;
};

bool Compare(const FilenameInfo& lhs, const FilenameInfo& rhs)
{
    if (lhs.Head == rhs.Head)
    {
        if (lhs.Number == rhs.Number)
        {
            return lhs.Seq < rhs.Seq;
        }
        return lhs.Number < rhs.Number;
    }
    return lhs.Head < rhs.Head;
}

vector<string> solution(vector<string> files)
{
    vector<string> answer;
    vector<FilenameInfo> filenameInfos;
    
    answer.reserve(files.size());
    filenameInfos.reserve(files.size());
    
    for (int i = 0; i < files.size(); ++i)
    {
        filenameInfos.push_back(FilenameInfo(files[i], i));
    }
    
    sort(filenameInfos.begin(), filenameInfos.end(), Compare);
    
    for (const FilenameInfo& filenameInfo : filenameInfos)
    {
        answer.push_back(filenameInfo.Src);
    }
    
    return answer;
}
```

# 결과
```
채점을 시작합니다.
정확성  테스트
테스트 1 〉	통과 (0.03ms, 4.18MB)
테스트 2 〉	통과 (0.03ms, 4.1MB)
테스트 3 〉	통과 (1.33ms, 4.18MB)
테스트 4 〉	통과 (0.84ms, 4.05MB)
테스트 5 〉	통과 (0.79ms, 4.18MB)
테스트 6 〉	통과 (1.32ms, 4.12MB)
테스트 7 〉	통과 (1.25ms, 4.11MB)
테스트 8 〉	통과 (0.89ms, 4.11MB)
테스트 9 〉	통과 (0.83ms, 4.02MB)
테스트 10 〉	통과 (0.86ms, 4.19MB)
테스트 11 〉	통과 (1.21ms, 4.12MB)
테스트 12 〉	통과 (1.30ms, 3.89MB)
테스트 13 〉	통과 (0.64ms, 4.11MB)
테스트 14 〉	통과 (1.39ms, 4.17MB)
테스트 15 〉	통과 (1.42ms, 4.19MB)
테스트 16 〉	통과 (1.22ms, 4.11MB)
테스트 17 〉	통과 (0.60ms, 4.03MB)
테스트 18 〉	통과 (0.62ms, 3.98MB)
테스트 19 〉	통과 (0.67ms, 4.17MB)
테스트 20 〉	통과 (1.29ms, 3.98MB)
채점 결과
정확성: 100.0
합계: 100.0 / 100.0
```