/*

problem URL : https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/

In a mystic dungeon, n magicians are standing in a line. Each magician has an attribute that gives you energy. Some magicians can give you negative energy, which means taking energy from you.

You have been cursed in such a way that after absorbing energy from magician i, you will be instantly transported to magician (i + k). This process will be repeated until you reach the magician where (i + k) does not exist.

In other words, you will choose a starting point and then teleport with k jumps until you reach the end of the magicians' sequence, absorbing all the energy during the journey.

You are given an array energy and an integer k. Return the maximum possible energy you can gain.

Note that when you are reach a magician, you must take energy from them, whether it is negative or positive energy.


Example 1:
Input: energy = [5,2,-10,-5,1], k = 3
Output: 3
Explanation: We can gain a total energy of 3 by starting from magician 1 absorbing 2 + 1 = 3.

Example 2:
Input: energy = [-2,-3,-1], k = 2
Output: -1
Explanation: We can gain a total energy of -1 by starting from magician 2.

Constraints:
• 1 <= energy.length <= 105
• -1000 <= energy[i] <= 1000
• 1 <= k <= energy.length - 1

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maximumEnergy(int* energy, int energySize, int k) {
    int *dp = (int*)malloc(sizeof(int)*energySize);
    int res = INT_MIN;

    for (int i=energySize-1; i >= 0; i--) {
        if ((i + k) < energySize)   { dp[i] = dp[i + k] + energy[i]; }
        else                        { dp[i] = energy[i]; }

        if (dp[i] > res) { res = dp[i]; }
    }

    return res;
}

int main(void) {
    // example 1
    int energy[5] = {5,2,-10,-5,1};
    int energySize = 5;
    int k = 3;

    // example 2
    // int energy[3] = {-2,-3,-1};
    // int energySize = 3;
    // int k = 2;

    int ret = maximumEnergy(energy, energySize, k);
    printf("ret : %d\n", ret);

    return 0;
}

