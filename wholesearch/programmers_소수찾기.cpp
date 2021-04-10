#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> numarray;
vector<int> choices;
vector<int> choice(7,0);
int maxLength;

bool check(int target)
{
    if (target < 2) return false;
    for (int i = 2; i * i <= target; i++)
    {
        if (target % i == 0) return false;
    }
    return true;
}

void comb(int number, int idx, int maxL)
{
    if (idx > maxL)
    {
       //choice selected
        int result = 0;
        for (int i = 1; i <= maxL; i++)
        {
            result += result * 10 + choice[i];
        }

       choices.push_back(result);
       return;
    }
    
    if (number > maxLength) return;

    choice[idx] = numarray[number-1];

    comb(number + 1, idx + 1, maxL);
    comb(number + 1, idx, maxL);

}

int solution(string numbers) {
    int answer = 0;
    maxLength = numbers.length();

    //문자열 분리
    for (int each = 0; each < numbers.length(); each++)
    {
        numarray.push_back((int)(numbers[each]) - '0');
    }

    //조합 찾기
    for (int length = 1; length <= numbers.length(); length++)
        comb(1, 1, length);

    //중복된 값 지우기
    sort(choices.begin(), choices.end());
    choices.erase(unique(choices.begin(), choices.end()), choices.end());

    //소수 체크
    for (int i = 0; i < choices.size(); i++)
    {
        if (check(choices[i])) answer += 1;
    }


    return answer;
}

int main()
{
    string input;
    cin >> input;

    cout << solution(input);


    return 0;
}