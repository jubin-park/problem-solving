# 35. Search Insert Position
* Topic: `Array` and `Binary Search`
* Level: Easy
* Date: 2022-09-30
* Elapsed Time: 45 min.
* Problem Link: https://leetcode.com/problems/search-insert-position/

# Solution
나는 이분 탐색에 약하다. 특히 while문의 종료 조건 때문에 알고리듬이 오답인 경우가 많다. 문제에서 주어진 배열은 각각 구별된다고 했으니, 이 말인 즉 중복되는 요소가 없다는 것과 같다. 또한 배열은 오름차순 정렬된 입력 데이터가 들어온다고 한다. 공책에 입력이 들어오는 경우의 수를 따졌다. 크게는 3가지로 볼 수 있다.

1. target이 nums[0]보다 작을 때
2. target이 nums[numsSize - 1] 보다 클 때
3. target이 nums[0]과 nums[numsSize - 1] 사이에 있을 때
   * 이분탐색 실행(mid를 기준으로 살펴보기)
     * nums[mid] 가 target과 같은지?
     * nums[mid] 가 target과 다르다면, nums[mid] 양쪽에 이웃한 요소와의 대소관계가 어떤지?

여기서 중요한 건, while 문에서 return을 한다는 것이다. while 바깥에는 -1을 return 하는 라인이 있다. 잘못된 데이터가 들어왔다면, -1을 반환할 것이다. 

처음에는 `while (left < right)` 식을 적용했는데, 반례가 있었다. `nums=[1,3], target=3`일 때 그렇다. while문을 한 번만 실행하고 left가 0에서 1로 바뀌면서 while문이 종료(left=1, right=1)되고 -1를 반환하는 것이었다. `while (left <= right)`로 바꾸니 해결됐는데, 아무튼 이러한 반례들이 생기면 문제가 어려워지는 것 같다.

여담으로 두 정수의 평균을 bit shift 연산자 `>>` 로 나타내 보았는데, 괄호로 안 감싸도 되니 편하다. 앞으로 자주 쓸 것 같다.
```c
int mid = (left + right) / 2;
// equals to
int mid = left + right >> 1;
```

## Input
```
[1,3,5,6]
5

[2,3,5,7,8,9]
4

[8]
8

[8]
5

[8]
15

[4,6,10,14,16,17]
5

[1,3]
3

[1,3]
1
```
## Output
```
2
2
0
0
1
1
1
0
```
# Source Code
```c
int searchInsert(const int* const nums, const int numsSize, const int target)
{
    if (target < nums[0])
    {
        return 0;
    }
    else if (nums[numsSize - 1] < target)
    {
        return numsSize;
    }
    
    int left = 0;
    int right = numsSize - 1;
    
    while (left <= right)
    {
        int mid = left + right >> 1;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            if (target < nums[mid + 1])
            {
                return mid + 1;
            }
            left = mid + 1;
        }
        else // target < nums[mid]
        {
            if (nums[mid - 1] < target)
            {
                return mid;
            }
            right = mid - 1;
        }
    }
    
    return (-1);
}
```