
# 성격 유형 검사하기
* 범주: 2022 KAKAO TECH INTERNSHIP
* 레벨: 1
* 날짜: 2022-09-01
* 소요시간: 30 분
* 링크: https://school.programmers.co.kr/learn/courses/30/lessons/118666

# 설명
핵심은 이것이다: choice 값의 범위가 1 ~ 7 인데, 4를 빼면 -3 ~ 3 로 만들 수 있다.

값이 음수면 왼쪽 선택지에 체크를 한 것이고, 양수면 오른쪽 선택지에 체크를 한 것으로 볼 수 있다. 또한 절대값을 취하면 해당 선택지의 점수 가중치까지 얻을 수 있다.

# 소스코드
```cpp
#include <string>
#include <vector>

using namespace std;

enum
{
    MAX_LABEL_COUNT = 8
};

inline int getIndex(const char c)
{
    switch (c)
    {
        case 'R':
            return 0;
        case 'T':
            return 1;
        case 'C':
            return 2;
        case 'F':
            return 3;
        case 'J':
            return 4;
        case 'M':
            return 5;
        case 'A':
            return 6;
        case 'N':
            return 7;
        default:
            return (-1);
    }
}

string solution(vector<string> survey, vector<int> choices)
{
    string answer = "";
    
    int scores[MAX_LABEL_COUNT] = { 0 };
    const char* labels = "RTCFJMAN";
    
    for (int i = 0; i < survey.size(); ++i)
    {
        const char left = survey[i][0];
        const char right = survey[i][1];
        const int leftIndex = getIndex(left);
        const int rightIndex = getIndex(right);
        const int score = choices[i] - 4;
        
        if (score < 0)
        {
            scores[leftIndex] += (-score);
        }
        else
        {
            scores[rightIndex] += score;
        }
    }
    
    for (int i = 0; i < MAX_LABEL_COUNT; i += 2)
    {
        if (scores[i] < scores[i + 1])
        {
            answer += labels[i + 1];
        }
        else
        {
            answer += labels[i];
        }
    }
    
    return answer;
}
```