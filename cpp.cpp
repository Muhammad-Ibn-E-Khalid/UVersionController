#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

class Student {
private:
    string Name;
    int Age;
    string DateOfBirth;
    string Gender;
    int RollNo;
    string sClass;
    char sSection;
    string PhoneNo;

    std::map<std::string, std::string> dataMap; // Map to store headings and data

public:
    void showall()
    {
        cout << "\n\t\tTake A Review\n";
        cout << "Name = " << Name << endl;
        cout << "Age = " << Age << endl;
        cout << "Date Of Birth = " << DateOfBirth << endl;
        cout << "Gender = " << Gender << endl;
        cout << "RollNo = " << RollNo << endl;
        cout << "Class = " << sClass << endl;
        cout << "Section = " << sSection << endl;
        cout << "PhoneNo = " << PhoneNo << endl << endl;

        char c;
        do {
            cout << "Do you want to submit or edit data this data? (S/E): ";
            cin >> c;
            if (c != 'S' && c != 's' && c != 'E' && c != 'e') {
                cout << "Invalid choice. Please enter 'y' or 'n'." << endl;
            }
        } while (c != 'S' && c != 's' && c != 'E' && c != 'e');

        if (c == 'S' || c == 's') {
            SubmitNewData();
            system("pause");
            system("cls");
            DisplayMainMenu();
        }

        else if (c == 'E' || c == 'e') {
            GotoToEditData();
        }
    }

    void GotoToEditData()
    {
        system("cls");
        int cho;
        cout << "What You Want To Edit from data?" << endl;
        cout << "1: All Data" << endl;
        cout << "2: Name" << endl;
        cout << "3: Age" << endl;
        cout << "4: Date Of Birth" << endl;
        cout << "5: Gender" << endl;
        cout << "6: Roll Number" << endl;
        cout << "7: Class" << endl;
        cout << "8: Section" << endl;
        cout << "9: Phone Number" << endl;
        cout << "option: ";
        cin >> cho;

        while (true) {
            if (!(cin >> cho)) {
                cin.clear(); // clear input buffer to restore cin to a usable state
                cin.ignore(INT_MAX, '\n'); // ignore last input
                cout << "Invalid input. Please enter a number." << endl;
                cout << "Enter your choice: ";
            }
            else if (cho < 1 || cho > 9) {
                cout << "Invalid option! Please choose a valid option." << endl;
                cout << "Enter your choice: ";
            }
            else {
                break;
            }
        }

        system("cls");

        // Handle options based on the user's choice
        switch (cho) {
        case 1:
            NewStudentData();
            break;
        case 2:
            SetName();
            break;
        case 3:
            SetAge();
            break;
        case 4:
            SetDateOfBirth();
            break;
        case 5:
            SetGender();
            break;
        case 6:
            SetRollNo();
            break;
        case 7:
            SetsClass();
            break;
        case 8:
            SetsSection();
            break;
        case 9:
            SetPhoneNo();
            break;
        }

        showall();
    }

    void NewStudentData()
    {
        system("cls");
        system("color A0");
        cout << "\n\t\t\tStudent New Record\n";
        SetName();
        SetAge();
        SetDateOfBirth();
        SetGender();
        SetPhoneNo();
        SetRollNo();
        SetsClass();
        SetsSection();
        showall();
    }

    void EditStudentData()
    {
        cout << "\n\t\t\tThis Part Of Program Is Under Construction.\n";
        system("pause");
        system("cls");
        DisplayMainMenu();
        /*
        
        std::string rollNumber, sClass;
        char sSection;

        std::cout << "Enter Student Roll Number: ";
        std::cin >> rollNumber;
        std::cout << "Enter Student Class: ";
        std::cin.ignore(); // Clear the newline character from the buffer
        std::getline(std::cin, sClass);
        std::cout << "Enter Student Section: ";
        std::cin >> sSection;

        // Search for the student with the specified Roll Number, Class, and Section
        SearchAndRetriveStudentData(rollNumber, sClass, sSection);

        // Ask the user which field they want to edit
        int choice;
        std::cout << "\nWhat You Want To Edit from data?" << std::endl;
        std::cout << "1: All Data" << std::endl;
        std::cout << "2: Name" << std::endl;
        std::cout << "3: Age" << std::endl;
        std::cout << "4: Date Of Birth" << std::endl;
        std::cout << "5: Gender" << std::endl;
        std::cout << "6: Roll Number" << std::endl;
        std::cout << "7: Class" << std::endl;
        std::cout << "8: Section" << std::endl;
        std::cout << "9: Phone Number" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Ensure the choice is valid
        while (choice < 1 || choice > 9) {
            std::cout << "Invalid option! Please choose a valid option." << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
        }
        
        system("cls");

        // Handle options based on the user's choice
        switch (choice) {
        case 1:
            NewStudentData();
            break;
        case 2:
            SetName();
            break;
        case 3:
            SetAge();
            break;
        case 4:
            SetDateOfBirth();
            break;
        case 5:
            SetGender();
            break;
        case 6:
            SetRollNo();
            break;
        case 7:
            SetsClass();
            break;
        case 8:
            SetsSection();
            break;
        case 9:
            SetPhoneNo();
            break;
        }

        showall();
        */
    }

    void SubmitNewData()
    {
        // Open the CSV file in append mode
        std::ofstream outputFile("students.csv", std::ios::app);

        // Check if the file is opened successfully
        if (!outputFile.is_open()) {
            std::cerr << "Error opening the CSV file." << std::endl;
            return;
        }

        // Write the student data to the CSV file
        outputFile << Name << "," << Age << "," << DateOfBirth << "," << Gender
            << "," << RollNo << "," << sClass << "," << sSection << ","
            << "\"" << PhoneNo << "\"" << std::endl;

        // Close the file
        outputFile.close();

        std::cout << "Data submitted successfully!" << std::endl;
    }

    void SearchStudentData()
    {
        system("cls");
        // system("pause");
        string Hheading, headingValue, hheadingN;
        cout << "Search By?" << endl;
        cout << "1: Name" << endl;
        cout << "2: Age" << endl;
        cout << "3: Date Of Birth" << endl;
        cout << "4: Gender" << endl;
        cout << "5: Roll Number" << endl;
        cout << "6: Class" << endl;
        cout << "7: Section" << endl;
        cout << "8: Phone Number" << endl;
        cout << "9: Goto Main Menu" << endl;

        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore(); // Clear the newline character from the buffer

        while (choice < 1 || choice > 9) {
            cout << "Invalid option! Please choose a valid option." << endl;
            cout << "Option: ";
            cin >> choice;
        }

        switch (choice) {
        case 1:
            Hheading = "Name";
            hheadingN = "Name";

            break;
        case 2:
            Hheading = "Age";
            hheadingN = "Age";
            break;
        case 3:
            Hheading = "DateOfBirth";
            hheadingN = "DateOfBirth";
            break;
        case 4:
            Hheading = "Gender";
            hheadingN = "Gender";
            break;
        case 5:
            Hheading = "RollNo";
            hheadingN = "RollNo";
            break;
        case 6:
            Hheading = "Class";
            hheadingN = "Class";
            break;
        case 7:
            Hheading = "Section";
            hheadingN = "Section";
            break;
        case 8:
            Hheading = "PhoneNo";
            hheadingN = "PhoneNo";
            break;
        case 9:
            system("cls");
            DisplayMainMenu();
            break;
        }

        cout << "Enter " << hheadingN << " to search: ";
        getline(cin, headingValue);

        SearchStudentDataPrivateFunction(Hheading, headingValue);
    }

    void DeleteStudentData()
    {
        string rlno, sclas;
        char scsect;
        cout << "Enter Student Roll Number: ";
        cin >> rlno;
        cout << "Enter Student Class: ";
        cin.ignore(); // Add this line to clear the newline character from the
        // buffer
        getline(cin, sclas);
        cout << "Enter Student Section: "; // Clarify the prompt
        cin >> scsect;

        DeleteStudentDataInPrivateFunction(rlno, sclas, scsect);
    }

    void ShowAllStudentsData()
    {
        std::ifstream file("students.csv");

        if (file.is_open()) {
            system("cls");
            cout << "\n\t\t\tAll Student Data\n\n";

            std::string line;
            int serialNumber = 1; // Counter for serial number
            bool isFirstLine = true; // To skip the header in the first iteration

            while (getline(file, line)) {
                if (isFirstLine) {
                    // Skip the header in the first iteration
                    isFirstLine = false;
                    continue;
                }

                std::stringstream ss(line);
                std::vector<std::string> data;
                std::string cell;

                while (getline(ss, cell, ',')) {
                    data.push_back(cell);
                }

                cout << "Serial Number: " << serialNumber << "\n";
                cout << "Name: " << data[0] << "\n";
                cout << "Age: " << data[1] << "\n";
                cout << "Date of Birth: " << data[2] << "\n";
                cout << "Gender: " << data[3] << "\n";
                cout << "Roll No: " << data[4] << "\n";
                cout << "Class: " << data[5] << "\n";
                cout << "Section: " << data[6] << "\n";
                cout << "Phone No: " << data[7] << "\n\n";

                ++serialNumber; // Increment serial number for the next entry
            }

            file.close();
        }
        else {
            std::cerr << "Unable to open file." << std::endl;
        }

        system("pause");
        system("cls");
        DisplayMainMenu();
    }

    void DisplayMainMenu()
    {
        Student Stud;

        string Choice;
        system("color 0A");
        cout << "\t\t\tMain Menu\n\n";
        cout << "I  : New Student Data" << endl;
        cout << "II : Edit Student Data" << endl;
        cout << "III: Delete Student Data" << endl;
        cout << "IV : Serach Student Data" << endl;
        cout << "V  : Show All Students Data" << endl;
        cout << "E  : Exit" << endl;
        cout << "Your Choice: ";
        cin >> Choice;

        while (Choice != "I" && Choice != "II" && Choice != "III" && Choice != "IV"
            && Choice != "V" && Choice != "i" && Choice != "ii" && Choice != "iii"
            && Choice != "iv" && Choice != "v" && Choice != "1" && Choice != "2"
            && Choice != "3" && Choice != "4" && Choice != "5" && Choice != "E"
            && Choice != "e") {
            cout << "Invalid Choice. Please Enter Again\n";
            cout << "Your Choice: ";
            cin >> Choice;
        }

        if (Choice == "I" || Choice == "i" || Choice == "1") {
            Stud.NewStudentData();
        }

        else if (Choice == "II" || Choice == "ii" || Choice == "2") {

            Stud.EditStudentData();
        }

        else if (Choice == "III" || Choice == "iii" || Choice == "3") {
            Stud.DeleteStudentData();
        }

        else if (Choice == "IV" || Choice == "iv" || Choice == "4") {
            Stud.SearchStudentData();
        }

        else if (Choice == "V" || Choice == "v" || Choice == "5") {

            Stud.ShowAllStudentsData();
        }

        else if (Choice == "E" || Choice == "e") {

            exit(1);
        }
    }

#pragma region NoReading

    void SetName()
    {
        cout << "\nEnter Name: ";
        cin.ignore();
        getline(cin, Name);
    }

    void SetAge()
    {
        do {
            cout << "\nEnter Age: ";
            cin >> Age;
            cin.ignore();
            if (Age <= 0) {
                cout << "Age cannot be negative. Please enter a valid age.\n";
            }
        } while (Age <= 0);
    }

    void SetDateOfBirth()
    {
        cout << "\nEnter Date Of Birth (DD/MM/YYYY): ";
        cin >> DateOfBirth;

        while (DateOfBirth.length() != 10 || DateOfBirth[2] != '/'
            || DateOfBirth[5] != '/') {
            cout << "Invalid date format. Please enter in DD/MM/YYYY format: ";
            cin >> DateOfBirth;
        }
        cin.ignore();
    }

    void SetRollNo()
    {
        do {
            cout << "\nEnter Roll Number: ";
            cin >> RollNo;
            cin.ignore();
            if (RollNo < 0) {
                cout << "Roll Number should be a positive integer. Please enter a "
                    "valid roll number.\n";
            }
        } while (RollNo < 0);
    }

    void SetsClass()
    {
        cout << "\nEnter Class: ";
        getline(cin, sClass);
        // cin.ignore();
    }

    void SetsSection()
    {
        cout << "\nEnter Section: ";
        cin >> sSection;
        cin.ignore();
    }

    void SetGender()
    {
        int g;
        do {
            cout << "\nEnter 1 if Male or 0 if Female: ";
            cin >> g;
            cin.ignore();
            if (g != 0 && g != 1) {
                cout << "Invalid input. Please enter 1 for Male or 0 for Female.\n";
            }
        } while (g != 0 && g != 1);

        Gender = (g == 1) ? "Male" : "Female";
    }

    void SetPhoneNo()
    {
        string pn;
        cout << "\nEnter Phone Number (with country code): +";
        getline(cin, pn);
        PhoneNo = "+" + pn;
    }

private:

    void SearchAndRetriveStudentData(
        const std::string& rollNumber, const std::string& sClass, char sSection)
    {
        std::ifstream file("students.csv");

        if (file.is_open()) {
            std::string line;
            bool isFirstLine = true; // To skip the header in the first iteration
            bool recordFound = false;

            std::string foundName, foundAge, foundDateOfBirth, foundGender,
                foundRollNo, foundClass, foundSection, foundPhoneNo;

            while (getline(file, line)) {
                if (isFirstLine) {
                    // Parse and store headings in the map
                    ParseAndStoreHeadings(line);
                    isFirstLine = false;
                    continue;
                }

                std::stringstream ss(line);
                std::vector<std::string> rowData;
                std::string cell;

                while (getline(ss, cell, ',')) {
                    rowData.push_back(cell);
                }

                // Assuming the order of data is Name, Age, DateOfBirth, Gender, RollNo,
                // Class, Section, PhoneNo
                UpdateDataMap(rowData);

                // Check if the combination of Roll Number, Class, and Section matches
                // the specified criteria
                if (dataMap["RollNo"] == rollNumber && dataMap["Class"] == sClass
                    && dataMap["Section"] == std::string(1, sSection)) {
                    Name = dataMap["Name"];
                    Age = std::stoi(dataMap["Age"]);
                    DateOfBirth = dataMap["DateOfBirth"];
                    Gender = dataMap["Gender"];
                    RollNo = std::stoi(dataMap["RollNo"]);
                    const std::string& sClass = dataMap["Class"]; // Use a const reference
                    sSection = dataMap["Section"][0];
                    PhoneNo = dataMap["PhoneNo"];

                    recordFound = true;
                    break; // No need to continue searching once the record is found
                }
            }

            if (recordFound) {
                // Display the found data
                cout << "\nFound Student Data:\n";
                cout << "Name: " << Name << "\n";
                cout << "Age: " << Age << "\n";
                cout << "DateOfBirth: " << DateOfBirth << "\n";
                cout << "Gender: " << Gender << "\n";
                cout << "RollNo: " << RollNo << "\n";
                cout << "Class: " << sClass << "\n";
                cout << "Section: " << sSection << "\n";
                cout << "PhoneNo: " << PhoneNo << "\n\n";
            }
            else {
                std::cout << "No records found for the specified criteria."
                    << std::endl;
                system("pause");
                system("cls");
                DisplayMainMenu();
            }

            file.close();
        }
        else {
            std::cerr << "Unable to open file." << std::endl;
        }
    }

    void DeleteStudentDataInPrivateFunction(
        const std::string& rollNumber, const std::string& sClass, char sSection)
    {
        std::ifstream inputFile("students.csv");
        std::ofstream outputFile("temp.csv", std::ios::out);

        if (!inputFile.is_open() || !outputFile.is_open()) {
            std::cerr << "Error opening files." << std::endl;
            return;
        }

        std::string line;
        bool isFirstLine = true;
        bool dataFound
            = false; // Flag to check if data is found for the specified criteria

        while (getline(inputFile, line)) {
            if (isFirstLine) {
                // Copy the header to the new file
                outputFile << line << std::endl;
                isFirstLine = false;
                continue;
            }

            std::stringstream ss(line);
            std::vector<std::string> rowData;
            std::string cell;

            while (getline(ss, cell, ',')) {
                rowData.push_back(cell);
            }

            // Assuming the order of data is RollNo, Name, Age, DateOfBirth, Gender,
            // Class, Section, PhoneNo
            if (rowData[4] != rollNumber || rowData[5] != sClass
                || rowData[6][0] != sSection) {
                // If the combination of Roll Number, Class, and Section does not match
                // the specified criteria, copy the row to the new file
                outputFile << line << std::endl;
            }
            else {
                // Data found for the specified criteria
                dataFound = true;
            }
        }

        inputFile.close();
        outputFile.close();

        if (!dataFound) {
            std::cout << "Student with Roll Number " << rollNumber << " in Class "
                << sClass << " Section " << sSection
                << " not found in the file." << std::endl;
            system("pause");
            system("cls");
            DisplayMainMenu();
            return;
        }

        // Remove the original file
        remove("students.csv");

        // Rename the temporary file to the original file name
        rename("temp.csv", "students.csv");

        std::cout << "Data deleted successfully!" << std::endl;

        system("pause");
        system("cls");
        DisplayMainMenu();
    }

    // Search Student Data related

    void SearchStudentDataPrivateFunction(
        const std::string& heading, const std::string& searchValue)
    {
        std::ifstream file("students.csv");

        if (file.is_open()) {
            std::string line;
            bool isFirstLine = true; // To skip the header in the first iteration
            bool recordFound = false;

            while (getline(file, line)) {
                if (isFirstLine) {
                    // Parse and store headings in the map
                    ParseAndStoreHeadings(line);
                    isFirstLine = false;
                    continue;
                }

                std::stringstream ss(line);
                std::vector<std::string> rowData;
                std::string cell;

                while (getline(ss, cell, ',')) {
                    rowData.push_back(cell);
                }

                // Assuming the order of data is Name, Age, DateOfBirth, Gender, RollNo,
                // Class, Section, PhoneNo
                UpdateDataMap(rowData);

                // Check if the search value matches the specified heading
                if (heading == "Name" && dataMap["Name"] == searchValue
                    || heading == "Age" && dataMap["Age"] == searchValue
                    || heading == "DateOfBirth" && dataMap["DateOfBirth"] == searchValue
                    || heading == "Gender" && dataMap["Gender"] == searchValue
                    || heading == "RollNo" && dataMap["RollNo"] == searchValue
                    || heading == "Class" && dataMap["Class"] == searchValue
                    || heading == "Section" && dataMap["Section"] == searchValue
                    || heading == "PhoneNo" && dataMap["PhoneNo"] == searchValue) {
                    DisplaySearchResult();
                    recordFound = true;
                }
            }

            if (!recordFound) {
                std::cout << "No records found for the specified criteria."
                    << std::endl;
                system("pause");
                system("cls");
                DisplayMainMenu();
            }

            file.close();
        }
        else {
            std::cerr << "Unable to open file." << std::endl;
        }
    }

    void ParseAndStoreHeadings(const std::string& headerLine)
    {
        std::stringstream ss(headerLine);
        std::string cell;

        while (getline(ss, cell, ',')) {
            // Store headings in the map
            dataMap[cell] = "";
        }
    }

    void UpdateDataMap(const std::vector<std::string>& rowData)
    {
        // Update the map with the latest row data
        dataMap["Name"] = rowData[0];
        dataMap["Age"] = rowData[1];
        dataMap["DateOfBirth"] = rowData[2];
        dataMap["Gender"] = rowData[3];
        dataMap["RollNo"] = rowData[4];
        dataMap["Class"] = rowData[5];
        dataMap["Section"] = rowData[6];
        dataMap["PhoneNo"] = rowData[7];
    }

    void DisplaySearchResult()
    {
        cout << "\nSearch Result:\n";
        cout << "Name: " << dataMap["Name"] << "\n";
        cout << "Age: " << dataMap["Age"] << "\n";
        cout << "DateOfBirth: " << dataMap["DateOfBirth"] << "\n";
        cout << "Gender: " << dataMap["Gender"] << "\n";
        cout << "RollNo: " << dataMap["RollNo"] << "\n";
        cout << "Class: " << dataMap["Class"] << "\n";
        cout << "Section: " << dataMap["Section"] << "\n";
        cout << "PhoneNo: " << dataMap["PhoneNo"] << "\n\n";
    }
};

void CreateCSVStudentFile()
{
    const std::string filename = "students.csv";

    std::ifstream checkFile(filename);

    if (!checkFile) {
        // File doesn't exist, create it and write the header
        std::ofstream createFile(filename);

        if (createFile.is_open()) {
            createFile << "Name"
                << ","
                << "Age"
                << ","
                << "DateOfBirth"
                << ","
                << "Gender"
                << ","
                << "RollNo"
                << ","
                << "Class"
                << ","
                << "Section"
                << ","
                << "PhoneNo" << std::endl;

            std::cout << "File created successfully with header!" << std::endl;

            // Close the file
            createFile.close();
        }
        else {
            std::cerr << "Error creating the CSV file." << std::endl;
            // Handle the error appropriately, e.g., by returning an error code
        }
        system("pause");
        system("cls");
    }
}
#pragma endregion

int main()
{
    Student st;

    // Check if the CSV file exists
    // IF File doesn't exist, create it and write the header
    CreateCSVStudentFile();

    st.DisplayMainMenu();
    system("pause");



    /*
     Student st;

    CreateCSVStudentFile();
    st.SubmitNewData();

    system("pause");
    system("pause");
    system("pause");


   

    for (int i = 0; i < 5; i++)
    {
        st.Name = "Test Name";
        st.Age = 0 + i;
        st.DateOfBirth = "1/28/2024";
        st.Gender = "Male";
        st.RollNo = 0 + i;
        st.sClass = "2nd Year";
        st.sSection = 'D';
        st.PhoneNo = "923336135864";
        st.SubmitNewData();
        system("pause");
    }

    system("pause");*/
    return 0;
}