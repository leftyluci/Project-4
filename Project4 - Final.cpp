# include <iostream>
# include <string>
# include <cctype>
# include <iomanip>
# include <fstream>

using namespace std;

// PROTOTYPES
int contractsetup(int & numContracts, int & conCnt);
float setCostsCon(float & electric, float & plumb, float & roof, float & landscape);
float setCostsEmp(float & salEmp);
void totals(int numContracts, float salCon, float salEmp, float matCost, float electric, float plumb, float roof, 
	float landscape, float & totalSal, float & totalCon, float & sumElectric, float & sumPlumb, float & sumRoof, float & sumLandscape, 
	float & sumTotalCon, float & sumMats, float & sumSalaries);
void contractTotal(ofstream & results, int numContracts, int conCnt, float electric, float plumb, float roof, float landscape,
	float salCon, float salEmp, float matCost, float totalSal, float totalCon);
void print(ofstream & results, int numContracts, int conCnt, float salCon, float salEmp, float matCost, float electric, float plumb, float roof, 
	float landscape, float totalCon, float sumElectric, float sumPlumb, float sumRoof, float sumLandscape, 
	float sumTotalCon, float sumMats, float sumSalarie); 

int main()
{ 
ofstream results;
results.open("results.txt");	// opens file to write to later in the program
	
float salCon, electric, plumb, roof, landscape, salEmp, matCost, totalCon, profitLoss, sumElectric, 
	sumPlumb, sumRoof, sumLandscape, sumTotalCon, sumMats, totalSal, sumSalaries;
int numContracts, conCnt;
	contractsetup(numContracts, conCnt);	
	for (conCnt; conCnt<=numContracts; conCnt++)
	
	{
cout << endl << "Start of Contract " << conCnt << " of " << numContracts << endl << endl;	
// INPUT
salCon= setCostsCon(electric, plumb, roof, landscape); //setting salary for Contractors
matCost= setCostsEmp(salEmp);	//setting material cost
cout << endl << "End of Contract " << conCnt << " of " << numContracts << endl;
system("CLS");
// PROCESS
totals(numContracts, salCon, salEmp, matCost, electric, plumb, roof, landscape, totalSal, 
	totalCon, sumElectric, sumPlumb, sumRoof, sumLandscape, sumTotalCon, sumMats, sumSalaries);
// OUTPUT
contractTotal(results, numContracts, conCnt, electric, plumb, roof, landscape,
	salCon, salEmp, matCost, totalSal, totalCon);
	}
print(results, numContracts, conCnt, salCon, salEmp, matCost, electric, plumb, roof, landscape, 
	totalCon, sumElectric, sumPlumb, sumRoof, sumLandscape, sumTotalCon, sumMats, sumSalaries); 

results.close();	// closes the file being written to	
return 0;

}

// contractsetup() will ask the user to inter the amount of contracts needed and set up the loop to count the contracts
int contractsetup(int & numContracts, int & conCnt)
{	
conCnt=1;
cout << "Welcome to COMPANY!" << endl;
cout << "Enter # of Contracts: "; cin >> numContracts;
return numContracts;	
}

//setCostsCon() allows user to input the wages for the 4 Contractor employees and return their total wages
float setCostsCon(float & electric, float & plumb, float & roof, float & landscape)
{
cout << "Salaries for Subcontractors" << endl;
cout << "Electrician: "; cin >> electric;
cout << "Plumber: "; cin >> plumb;
cout << "Roofer: "; cin >> roof;
cout << "Landscaper: "; cin >> landscape;
return electric + plumb + roof + landscape;
}
	
// setCostsEmp() allows the user to enter Company Employee salaries, with a minimum of 5 Employees
float setCostsEmp(float & salEmp)
{	
salEmp=0.00;
int numEmp=0;
float salInp, wood, concrete, windows, doors, sheetrock, spackle;
cout << endl << "Employee Salaries" << endl;
while ((numEmp<=5) || (salInp>0))
{	
		
cout << "Enter Salary for Employee # " << numEmp+1 << ": "; cin >> salInp; 
salEmp= salEmp+ salInp;	
numEmp++;	
	if ((numEmp<=5) && (salInp<=0))
	{	
	numEmp=0;
	salEmp=0.00;
	cout << "Incorrect entry." << endl;
	cout << "Please enter Employees Salaries once again. Your minimum amount of employees is 5." << endl << endl;	
	cout << "Enter Salary for Employee # " << numEmp+1 << ": "; cin >> salInp; 
	salEmp= salEmp+ salInp;
	numEmp++;
	}
}
cout << "Cost of Materials" << endl;
cout << "Wood: "; cin >> wood;
cout << "Concrete: "; cin >> concrete;
cout << "Windows: "; cin >> windows;
cout << "Doors: "; cin >> doors;
cout << "Sheetrock: "; cin >> sheetrock;
cout << "Spackle: "; cin >> spackle;	
return wood + concrete + windows + doors + sheetrock + spackle;
}

// totals() will calculate all final totals needed for output
void totals(int numContracts, float salCon, float salEmp, float matCost, float electric, float plumb, float roof, 
float landscape, float & totalSal, float & totalCon, float & sumElectric, float & sumPlumb, float & sumRoof, float & sumLandscape, 
float & sumTotalCon, float & sumMats, float & sumSalaries)
{
//for calculating total for 1 contract
totalSal= salCon+ salEmp;
totalCon= salCon + salEmp + matCost;
//for calculating all contract totals
sumElectric= sumElectric + electric;
sumPlumb= sumPlumb + plumb;
sumRoof= sumRoof + roof;
sumLandscape= sumLandscape + landscape;
sumTotalCon= sumTotalCon + totalCon;
sumMats= sumMats + matCost;
sumSalaries= sumSalaries + totalSal;
}

// contractTotal() will output all totals for a specific contract to the file specified in main
void contractTotal(ofstream & results, int numContracts, int conCnt, float electric, float plumb, float roof, float landscape,
	float salCon, float salEmp, float matCost, float totalSal, float totalCon)
{
if (results.is_open())
{
results << "Contract # " << conCnt << " of " << numContracts << endl;
cout << fixed << showpoint << setprecision(2);
results << "Cost of Electrician Service: $" << electric << endl;
results << "Cost for Plumbing Services: $" << plumb << endl;
results << "Cost for Roofing Services: $" << roof << endl;
results << "Cost for Landscaping Services: $" << landscape << endl;
results << "Material Cost: $" << matCost << endl;
results << "Employee Salary: $" << salEmp << endl;
results << "Contractor Salary: $" << salCon << endl;
results << "Salary Cost: $" << totalSal << endl;
results << "Contract Total: $" << totalCon << endl << endl;

}
else
{
cout<< "ERROR. File not detected, run program again to attempt to write to file again.";	
}

}

// print() will output the totals for all contracts and output it to the same file as contractTotal()
void print(ofstream & results, int numContracts, int conCnt, float salCon, float salEmp, float matCost, float electric, float plumb, float roof, 
float landscape, float totalCon, float sumElectric, float sumPlumb, float sumRoof, float sumLandscape, 
float sumTotalCon, float sumMats, float sumSalaries)
{
if (results.is_open())
{
cout<< endl << endl << "Writing Information to file... " << endl;
cout << "Please see the related file, /'result.txt/', for your totals." << endl << endl;;

	
results << "Total Number of Contracts: " << numContracts << endl;
results << fixed << showpoint << setprecision(2);
results << "Total Contract Cost: $" << sumTotalCon << endl;
results << "Total for Electrician Service: $" << sumElectric << endl;
results << "Total for Plumbing Services: $" << sumPlumb << endl;
results << "Total for Roofing Services: $" << sumRoof << endl;
results << "Total for Landscaping Services: $" << sumLandscape << endl;
results << "Total Material Cost: $" << sumMats << endl;
results << "Total Salary Cost: $" << sumSalaries << endl;
}
else
{
cout<< "ERROR. File not detected, run program again to attempt to write to file again.";	
}
}
