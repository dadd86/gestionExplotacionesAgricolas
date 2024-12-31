Agricultural Holdings Management Project
This project is designed to manage agricultural holdings within an agribusiness. 
It allows users to register and manage holdings with detailed information such as cadastral reference, name, surface area, purchase amount, purchase date, and irrigation type. 
Additionally, it includes functionalities to calculate the best surface-to-price ratio and count the number of holdings exceeding a specified surface area.

Project Description:
The program enables users to register multiple agricultural holdings within an agribusiness, specify the details of each holding, and calculate useful metrics, 
such as the best surface-to-price ratio and the count of holdings exceeding a given surface area. The information for each holding is efficiently organized and stored.

Data Structures:
Date: Represents a date with three fields: day, month, and year.
Word: A custom type for storing text with controlled length, including a character array (letters) and a field for the current text length (length).
tExplotacion: Represents an agricultural holding, with:
	referenciaCatastral: 
	Cadastral reference code.
	denominacionColoquial: Common name of the holding.
	superficieProductiva: Productive surface area in hectares.
	importeCompra: Purchase price of the holding.
	fechaCompra: Purchase date of the holding.
	esRegadio: Boolean indicating whether the land is irrigated.

tEmpresaAgraria: Represents an agribusiness, with:
	nif: Tax ID of the company.
	denominacion: Company name.
	poblacion: Location of the company.
	codigoPostal: Postal code.
	telefono: Contact phone number.
	direccion: Company address.
	explotaciones: Array of agricultural holdings.
	numExplotaciones: Number of registered holdings.

Functionalities:
Register Holding: Allows users to enter the details of an agricultural holding (cadastral reference, name, surface area, price, purchase date, and irrigation status).
Register Multiple Holdings: Allows users to register multiple agricultural holdings simultaneously, limited by the defined maximum number.
Calculate Best Surface-to-Price Ratio: Calculates and returns the best surface-to-price ratio among all holdings.
Count Holdings by Surface Area: Counts how many holdings have a surface area greater than a specified value.

Menu Options:
The program does not include an interactive menu, as it is designed to directly input holdings and calculate metrics from the main function. The primary flow is as follows:

1. The user inputs data for the agricultural holdings.
2. The best surface-to-price ratio is calculated.
3. The number of holdings with a surface area greater than a specified value (e.g., 50 hectares) is calculated.
4. The results are displayed in the console.

Requirements:
Compiler: A C compiler compatible with the C99 standard or higher is required.
Operating System: Works on Windows, Linux, and macOS operating systems.

Usage Instructions:
Compilation and Execution:
To compile the project, use a C compiler (e.g., GCC) with the following command:

gcc -o agricultural_management agricultural_management.c

To run the program, use the following command:

./agricultural_management

Interaction:
The program requests the data for each holding through standard input (console).
After entering the data for all holdings, the program calculates the best surface-to-price ratio and displays the count of holdings exceeding a specified surface area.

Example Usage:
Register Holding:
	Users enter information such as cadastral reference, name, surface area (in hectares), purchase price, purchase date, and whether it is irrigated.
Calculate Best Surface-to-Price Ratio:
	Once holdings are registered, the program calculates which holding has the best surface-to-price ratio.
Count Holdings by Surface Area:
	The program counts how many holdings have a surface area greater than the value entered by the user (e.g., 50 hectares).

Contributions:
Contributions to the project are welcome. If you wish to improve the code, add new functionalities, or fix bugs, please follow these steps:

Fork the repository.
Create a new branch for your changes:
	git checkout -b feature/new-feature

Make your changes and commit them:
	git commit -am 'Add new feature'

Push to the branch:
	git push origin feature/new-feature

Create a pull request describing the changes made.