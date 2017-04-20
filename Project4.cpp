# include <iostream>
# include <string>
# include <cctype>
# include <iomanip>

using namespace std;

// PROTOTYPES
int contractsetup(int & numContracts);
float setCostsCon(float & electric, float & plumb, float & roof, float & landscape);
float setCostsEmp(float & salEmp, float & matCost);
void total(int numContracts, float salCon, float salEmp, float matCost, float & totalCon, float & profitLoss);
void overall(int numContracts, float sumElectric, 
	float sumPlumb, float sumRoof, float sumLandscape, float sumProfitLoss, float sumMats, float sumSalaries);

// GLOBAL VARIABLE
float BUDGET=500000;	// max amount company will spend on all materials


int main()
{ 
float salCon, electric, plumb, roof, landscape, salEmp, matCost, totalCon, profitLoss, sumElectric, 
	sumPlumb, sumRoof, sumLandscape, sumProfitLoss, sumMats, totalSal, sumSalaries;
int numContracts, conCnt=1;
	contractsetup(numContracts);	
	for (conCnt; conCnt<=numContracts; conCnt++)
	{
	cout << "Start of Contract " << conCnt << " of " << numContracts << endl << endl;	
	
	salCon= setCostsCon(electric, plumb, roof, landscape); 
	matCost= setCostsEmp(salEmp, matCost);
	
	cout << "End of Contract " << conCnt << " of " << numContracts << endl << endl;
	total(numContracts, salCon, salEmp, matCost, totalCon, profitLoss);
	
	sumElectric= sumElectric + electric;
	sumPlumb= sumPlumb + plumb;
	sumRoof= sumRoof + roof;
	sumLandscape= sumLandscape + landscape;
	sumProfitLoss= sumProfitLoss + profitLoss;
	sumMats= sumMats + matCost;
	totalSal=(salCon+salEmp);
	sumSalaries= sumSalaries + totalSal;
	}
	overall(numContracts, sumElectric, sumPlumb, sumRoof, sumLandscape, sumProfitLoss, 
	sumMats, sumSalaries);

return 0;

}

int contractsetup(int & numContracts)
{	
	cout << "Welcome to COMPANY!" << endl;
	cout << "Enter # of Contracts: "; cin >> numContracts;
return numContracts;	
}


float setCostsCon(float & electric, float & plumb, float & roof, float & landscape)
{
	cout << "Salaries for Subcontractors" << endl;
	cout << "Electrician: "; cin >> electric;
	cout << "Plumber: "; cin >> plumb;
	cout << "Roofer: "; cin >> roof;
	cout << "Landscaper: "; cin >> landscape;
return electric + plumb + roof + landscape;
}
	
float setCostsEmp(float & salEmp, float & matCost)
{	int numEmp=1;
	float salInp, wood, concrete, windows, doors, sheetrock, spackle;
	salEmp=0.00;
	
	do{	
		cout << "Enter Salary for Employee # " << numEmp << ": "; cin >> salInp; 
		salEmp= salEmp+ salInp;
		numEmp ++;
		
		if ((numEmp<6) && salInp==0)
	{	
		do{
		numEmp=1;
		salEmp=0.00;
		cout << "Incorrect entry." << endl;
		cout << "Please enter Employees Salaries once again. Your minimum amount of employees is 5." << endl << endl;	
		cout << "Enter Salary for Employee # " << numEmp << ": "; cin >> salInp; 
		salEmp= salEmp+ salInp;
		numEmp ++;
		} while ((numEmp<6) && salInp==0);
		}
		} while ((numEmp<6) || salInp!=0);
	
	cout << "Cost of Materials" << endl;
	cout << "Wood: "; cin >> wood;
	cout << "Concrete: "; cin >> concrete;
	cout << "Windows: "; cin >> windows;
	cout << "Doors: "; cin >> doors;
	cout << "Sheetrock: "; cin >> sheetrock;
	cout << "Spackle: "; cin >> spackle;	
return wood + concrete + windows + doors + sheetrock + spackle;
}

void total(int numContracts, float salCon, float salEmp, float matCost, float & totalCon, float & profitLoss)
{
totalCon= (salCon + salEmp + matCost);
profitLoss= (BUDGET- totalCon);
cout << fixed << showpoint << setprecision(2);
cout << "Total for Contract: $" <<  totalCon << endl;
cout << "Profit/Loss: $" << profitLoss << endl << endl; 
}

void overall(int numContracts, float sumElectric, 
	float sumPlumb, float sumRoof, float sumLandscape, float sumProfitLoss, float sumMats, float sumSalaries)
{
	
cout << "Total Number of Contracts: " << numContracts << endl;
cout << fixed << showpoint << setprecision(2);
cout << "Total for Electrician Service: $" << sumElectric << endl;
cout << "Total for Plumbing Services: $" << sumPlumb << endl;
cout << "Total for Roofing Services: $" << sumRoof << endl;
cout << "Total for Landscaping Services: $" << sumLandscape << endl;
cout << "Total Material Cost: $" << sumMats << endl;
cout << "Total Salary Cost: $" << sumSalaries << endl;	
}
