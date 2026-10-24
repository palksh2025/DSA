class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days;
        days.push_back(31);
        days.push_back(28);
        days.push_back(31);
        days.push_back(30);
        days.push_back(31);
        days.push_back(30);
        days.push_back(31);
        days.push_back(31);
        days.push_back(30);
        days.push_back(31);
        days.push_back(30);
        days.push_back(31);

        int numArrA = 0;
        int month = 10 * int(arriveAlice[0] - 48) + int(arriveAlice[1] - 48);
        for(int i = 0; i < month - 1; i++){
            numArrA = numArrA + days[i];
        }
        numArrA = numArrA + 10 * int(arriveAlice[3] - 48) + int(arriveAlice[4] - 48);

        int numLeaA = 0;
        month = 10 * int(leaveAlice[0] - 48) + int(leaveAlice[1] - 48);
        for(int i = 0; i < month - 1; i++){
            numLeaA = numLeaA + days[i];
        }
        numLeaA = numLeaA + 10 * int(leaveAlice[3] - 48) + int(leaveAlice[4] - 48);

        int numLeaB = 0;
        month = 10 * int(leaveBob[0] - 48) + int(leaveBob[1] - 48);
        for(int i = 0; i < month - 1; i++){
            numLeaB = numLeaB + days[i];
        }
        numLeaB = numLeaB + 10 * int(leaveBob[3] - 48) + int(leaveBob[4] - 48);

        int numArrB = 0;
        month = 10 * int(arriveBob[0] - 48) + int(arriveBob[1] - 48);
        for(int i = 0; i < month - 1; i++){
            numArrB = numArrB + days[i];
        }
        numArrB = numArrB + 10 * int(arriveBob[3] - 48) + int(arriveBob[4] - 48);

        cout<<"Alice Arrival: "<<numArrA<<endl;
        cout<<"Alice Leave: "<<numLeaA<<endl;
        cout<<"Bob Arrival: "<<numArrB<<endl;
        cout<<"Bob Leave: "<<numLeaB<<endl;

        if(numLeaA < numArrB){
            return 0;
        }

        if(numLeaB < numArrA){
            return 0;
        }

        if(numArrA >= numArrB && numLeaA <= numLeaB){
            cout<<"Case 1";
            return numLeaA - numArrA + 1;
        }

        if(numArrB >= numArrA && numLeaB <= numLeaA){
            cout<<"Case 2";
            return numLeaB - numArrB + 1;
        }

        if(numLeaA >= numArrB && numArrA <= numArrB){
            cout<<"Case 3";
            return numLeaA - numArrB + 1;
        }

        if(numLeaB >= numArrA && numArrB <= numArrA){
            cout<<"Case 4";
            return numLeaB - numArrA + 1;
        }        

        return -1;
    }
};