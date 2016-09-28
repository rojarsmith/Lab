/*
 You want to buy public transport tickets for the upcoming month.
 You know exactly the days on which you will be travelling.
 The month has 30 days and there are three types of ticket:

 1-day ticket, costs 2, valid for one day;
 7-day ticket, costs 7, valid for seven consecutive days (e.g. if the first valid day is X, then the last valid day is X+6);
 30-day ticket, costs 25, valid for all thirty days of the month.
 
 You want to pay as little as possible.

 You are given a sorted (in increasing order) array A of dates when you will be travelling. For example, given:

 A[0] = 1
 A[1] = 2
 A[2] = 4
 A[3] = 5
 A[4] = 7
 A[5] = 29
 A[6] = 30

You can buy one 7-day ticket and two 1-day tickets. The two 1-day tickets should be used on days 29 and 30.
The 7-day ticket should be used on the first seven days of the month.
The total cost is 11 and there is no possible way of paying less.

Write a function:

class Solution { public int solution(int[] a); }

that, given a zero-indexed array A consisting of N integers that specifies days on which you will be traveling, returns the minimum amount of money that you have to spend on tickets for the month.

For example, given the above data, the function should return 11, as explained above.

Assume that:
-N is an integer within the range [0..30];

-each element of array A is an integer within the range [1..30];

-array A is sorted in increasing order;

-the elements of A are all distinct.
 */

package lab.algorithm;

public class TicketsNeededMinimumCost {
	public static int solution(int A[]) {
		if (A.length >= 25) //25+ days = 25
			return 25;
		if (A.length <= 3) { // 3 days * 2 = 6 
			return (A.length * 2);
		}

		int index = 0;
		int daysCount = 0;
		int finalAmount = 0;
		int seventh = 0;
		int totalCount = 0;
		boolean isJLoopFinish = false;

		for (int i = 0; i < A.length; i++) {

			if (isJLoopFinish == true) {
				seventh++;
				break;
			}

			daysCount = 0;
			index = A[i] + 7;
			totalCount++;

			for (int j = i+1; j < A.length ; j++) {
				if ((daysCount >= 3)  && (A[j] < index) && (j == (A.length-1))) {					
					isJLoopFinish = true;
				}

				if (A[j] < index) {
					daysCount++;
				} else {
					if (daysCount > 3) {
						seventh++;
						daysCount = 0;
						i = j-1;
					} else {
						daysCount = 0;
					}
					break;
				}
			}
		}

		totalCount = totalCount - seventh;
		finalAmount = (totalCount * 2) + (seventh * 7);

		if (finalAmount > 25) {
			finalAmount = 25;
		}
		return finalAmount;
	}
}
