# JadenCase 문자열 만들기
* 범주: 연습문제
* 레벨: 2
* 날짜: 2022-09-01
* 소요시간: 20 분
* 링크: https://school.programmers.co.kr/learn/courses/30/lessons/12951

# 설명
c-style 문자열을 사용하기 위해 `std::string#c_str()` 메서드와 `const_cast<>()` 캐스팅을 사용했다. `0x20` 비트를 추가하면 소문자 알파벳, 제거하면 대문자 알파벳이 되니 알아두면 좋다.

`&&`(우선순위:11)가 `||`(우선순위:12)보다 우선순위가 높으니 불필요한 괄호를 제거할 수 있다.

```cpp
*p >= 'a' && *p <= 'z' || *p >= 'A' && *p <= 'Z'
// equals to
(*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z')
```

# 소스코드
```cpp
#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    char* p = const_cast<char*>(s.c_str()); // bad code
    bool isHead = true;
    
    while (*p != '\0')
    {
        if (*p == ' ')
        {
            isHead = true;
        }
        else if (*p >= 'a' && *p <= 'z' || *p >= 'A' && *p <= 'Z')
        {
            if (isHead)
            {
                *p &= ~(0x20);
            }
            else
            {
                *p |= 0x20;
            }
            isHead = false;
        }
        else if (*p >= '0' && *p <= '9')
        {
            isHead = false;
        }
        ++p;
    }
    
    return s;
}
```

# 결과
```
정확성  테스트
테스트 1 〉	통과 (0.01ms, 4.12MB)
테스트 2 〉	통과 (0.01ms, 3.66MB)
테스트 3 〉	통과 (0.01ms, 4.18MB)
테스트 4 〉	통과 (0.01ms, 4.18MB)
테스트 5 〉	통과 (0.01ms, 4.19MB)
테스트 6 〉	통과 (0.01ms, 4.17MB)
테스트 7 〉	통과 (0.01ms, 4.25MB)
테스트 8 〉	통과 (0.01ms, 3.66MB)
테스트 9 〉	통과 (0.01ms, 4.18MB)
테스트 10 〉	통과 (0.01ms, 3.64MB)
테스트 11 〉	통과 (0.01ms, 3.68MB)
테스트 12 〉	통과 (0.01ms, 4.24MB)
테스트 13 〉	통과 (0.01ms, 4.18MB)
테스트 14 〉	통과 (0.01ms, 4.04MB)
테스트 15 〉	통과 (0.01ms, 4.18MB)
테스트 16 〉	통과 (0.01ms, 4.11MB)
테스트 17 〉	통과 (0.01ms, 4.18MB)
테스트 18 〉	통과 (0.01ms, 4.14MB)
채점 결과
정확성: 100.0
합계: 100.0 / 100.0
```