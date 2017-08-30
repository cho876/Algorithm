/**
 * 문제:
 * 피보나치 수열의 각 항은 바로 앞의 항 두 개를 더한 것이 된다.
 * 1과 2로 시작하는 경우 이 수열은 아래와 같습니다.1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 * 짝수이면서 4백만 이하인 모든 항을 더하면 얼마가 되는가?
 *
 * @author sungkwonCho
 */


public class test {

    public static void main(String[] args) {
        int result = 0;
        for (int i = 1; fibo(i) <= 4000000; i++) {
            if (fibo(i) % 2 == 0)
                result += fibo(i);
        }
        System.out.println(result);
    }

    /**
     * 피보나치 수열 연산
     *
     * @param number 판별할 숫자
     * @return 피보나치 수열
     */
    public static int fibo(final int number) {
        if (number == 1) {
            return 1;
        } else if (number == 2) {
            return 2;
        } else {
            return fibo(number - 2) + fibo(number - 1);
        }
    }
}