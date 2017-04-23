# include <iostream>
# include <string>
# include <cctype>
# include <iomanip>
# include <fstream>

using namespace std;

// PROTOTYPES
int contractSetup(int & numContracts, int & conCnt);
float setCostsCon(float & conCost, float & electric, float & plumb, float & roof, float & landscape);
float setCostsEmp(float & salEmp);
void totals(int numContracts, float conCost, float salCon, float salEmp, float matCost, float electric, float plumb, float roof, 
	float landscape, float & totalSal, float & totalCon, float & profitLoss, float & sumProfit, float & sumElectric, float & sumPlumb, float & sumRoof, 
	float & sumLandscape, float & sumTotalCon, float & sumMats, float & sumSalaries, float & sumProfitLoss);
void contractTotal(ofstream & results, int numContracts, int conCnt, float conCost, float totalCon, float profitLoss);
void overall(ofstream & results, int numContracts, float sumProfit, float sumElectric, 
	float sumPlumb, float sumRoof, float sumLandscape, float sumTotalCon, float sumMats, float sumSalaries, float sumProfitLoss); 

int main()
{ 
ofstream results;
results.open("results.txt");	// opens file to write to later in the program
	
float conCost, salCon, electric, plumb, roof, landscape, salEmp, matCost, totalCon, profitLoss, sumProfit, sumElectric, 
	sumPlumb, sumRoof, sumLandscape, sumTotalCon, sumMats, totalSal, sumSalaries, sumProfitLoss;
int numContracts, conCnt;

contractSetup(numContracts, conCnt);	
	for (conCnt; conCnt<=numContracts; conCnt++)
	
	{
cout << endl << "Start of Contract " << conCnt << " of " << numContracts << endl << endl;	
// INPUT
salCon= setCostsCon(conCost, electric, plumb, roof, landscape); //setting salary for Contractors
matCost= setCostsEmp(salEmp);	//setting material cost
cin.get();
cin.ignore();
system("CLS");
// PROCESS
totals(numContracts, conCost, salCon, salEmp, matCost, electric, plumb, roof, 
landscape, totalSal, totalCon, profitLoss, sumProfit, sumElectric, sumPlumb, sumRoof, 
sumLandscape, sumTotalCon, sumMats, sumSalaries, sumProfitLoss);
// OUTPUT
contractTotal(results, numContracts, conCnt, conCost, totalCon, profitLoss);
	}
overall(results, numContracts, sumProfit, sumElectric, sumPlumb, sumRoof, sumLandscape, 
	sumTotalCon, sumMats, sumSalaries, sumProfitLoss);
results.close();	// closes the file being written to	
return 0;

}

// contractsetup() will ask the user to inter the amount of contracts needed and set up the loop to count the contracts
int contractSetup(int & numContracts, int & conCnt)
{	
conCnt=1;
cout << "Welcome to Passaic County Contracting Company!" << endl;
cout << "Please enter  the following information relating to the contracts:" << endl;
cout << "Enter # of Contracts: "; cin >> numContracts;
return numContracts;	
}

//setCostsCon() allows user to input the wages for the 4 Contractor employees and return their total wages
float setCostsCon(float & conCost, float & electric, float & plumb, float & roof, float & landscape)
{
cout << "Enter Contract Profit: $"; cin >> conCost;
cout << "Salaries for Subcontractors" << endl;
cout << "Electrician: $"; cin >> electric;
cout << "Plumber: $"; cin >> plumb;
cout << "Roofer: $"; cin >> roof;
cout << "Landscaper: $"; cin >> landscape;
return electric + plumb + roof + landscape;
}
	
// setCostsEmp() allows the user to enter Company Employee salaries, with a minimum of 5 Employees
float setCostsEmp(float & salEmp)
{	
salEmp=0.00;
int numEmp=0;
float salInp, wood, concrete, windows, doors, sheetrock, spackle;
cout << endl << "Employee Salaries" << endl;
cout << "Please enter the salaries to be paid to company employees. ";
cout << "You MUST have a minimum of 5 employees." << endl;
cout << "Enter 0 to finish entering the salaries." << endl;
while ((numEmp<=5) || (salInp>0))
{	
		
cout << "Enter Salary for Employee # " << numEmp+1 << ": $"; cin >> salInp; 
salEmp= salEmp+ salInp;	
numEmp++;	
	if ((numEmp<=5) && (salInp<=0))
	{	
	numEmp=0;
	salEmp=0.00;
	cout << "Incorrect entry." << endl;
	cout << "Please enter Employees Salaries once again. Your minimum amount of employees is 5." << endl << endl;	
	cout << "Enter Salary for Employee # " << numEmp+1 << ": $"; cin >> salInp; 
	salEmp= salEmp+ salInp;
	numEmp++;
	}
}
cout << "Cost of Materials" << endl;
cout << "Wood: $"; cin >> wood;
cout << "Concrete: $"; cin >> concrete;
cout << "Windows: $"; cin >> windows;
cout << "Doors: $"; cin >> doors;
cout << "Sheetrock: $"; cin >> sheetrock;
cout << "Spackle: $"; cin >> spackle;	
return wood + concrete + windows + doors + sheetrock + spackle;
}

// totals() will calculate all final totals needed for output
void totals(int numContracts, float conCost, float salCon, float salEmp, float matCost, float electric, float plumb, float roof, 
float landscape, float & totalSal, float & totalCon, float & profitLoss, float & sumProfit, float & sumElectric, float & sumPlumb, float & sumRoof, 
float & sumLandscape, float & sumTotalCon, float & sumMats, float & sumSalaries, float & sumProfitLoss)
{
//for calculating total for 1 contract
totalSal= salCon+ salEmp;
totalCon= salCon + salEmp + matCost;
profitLoss= conCost-totalCon; 
//for calculating all contract totals
sumProfit= sumProfit + conCost;
sumElectric= sumElectric + electric;
sumPlumb= sumPlumb + plumb;
sumRoof= sumRoof + roof;
sumLandscape= sumLandscape + landscape;
sumTotalCon= sumTotalCon + totalCon;
sumMats= sumMats + matCost;
sumSalaries= sumSalaries + salEmp;
sumProfitLoss= sumProfitLoss + profitLoss;
}

// contractTotal() will output all totals for a specific contract to the file specified in main
void contractTotal(ofstream & results, int numContracts, int conCnt, float conCost, float totalCon, float profitLoss)
{
if (results.is_open())
{
results << "Contract # " << conCnt << " of " << numContracts << endl;
results << fixed << showpoint << setprecision(2);
results << "Contract Revenue: $" << conCost << endl;
results << "Costs Total: $" << totalCon << endl;
results << "Gross Profit: $" << profitLoss << endl << endl;

}
else
{
cout<< "ERROR. File not detected, run program again to attempt to write to file again.";	
}

}

// overall() will output the totals for all contracts and output it to the same file as contractTotal()
void overall(ofstream & results, int numContracts, float sumProfit, float sumElectric, float sumPlumb, 
float sumRoof, float sumLandscape, float sumTotalCon, float sumMats, float sumSalaries, float sumProfitLoss)
{
if (results.is_open())
{
cout << "Writing Information to file... " << endl;
cout << "Please see the related file, \'result.txt\', for your totals." << endl << endl;;

	
results << "Total Number of Contracts: " << numContracts << endl;
results << fixed << showpoint << setprecision(2);
results << "Total Contract Revenue: $" << sumProfit << endl;
results << "Total for Electrician Service: $" << sumElectric << endl;
results << "Total for Plumbing Services: $" << sumPlumb << endl;
results << "Total for Roofing Services: $" << sumRoof << endl;
results << "Total for Landscaping Services: $" << sumLandscape << endl;
results << "Total Employee Salary Cost: $" << sumSalaries << endl;
results << "Total Material Cost: $" << sumMats << endl << endl;
results << "Total Expenses: $" << sumTotalCon << endl;
results << "Net Profit: $" << sumProfitLoss << endl;
}
else
{
cout<< "ERROR. File not detected, run program again to attempt to write to file again.";	
}
}
