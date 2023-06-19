// Cordoba Emiro Variant 8
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>



// Structure for entries in a file
struct AutotechCenter {
    std::string name;
    std::string ownerName;
    int rating;
    std::string reviews;
    std::string phoneNumber;
    std::string email;
};



// function for a typed file
void createFile(const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);



    // check if the file has opened
    if (!file) {
        std::cout << "the typed file has been created." << std::endl;
        return;
    }



    file.close();
    std::cout << "the typed file has been created." << std::endl;
}



//function to add to a file
void addRecord(const std::string& filename, const AutotechCenter& record) {
    std::ofstream file(filename, std::ios::binary | std::ios::app);
    // check if the file has opened
    if (!file) {
        std::cout << "file opening error." << std::endl;
        return;
    }



    file.write(reinterpret_cast<const char*>(&record), sizeof(AutotechCenter));
    file.close();
    std::cout << "." << std::endl;
}



// function for deleting from a file
void deleteRecord(const std::string& filename, int recordIndex) {
    std::ifstream file(filename, std::ios::binary);



    // check if the file has opened
    if (!file) {
        std::cout << "file opening error." << std::endl;
        return;
    }



    file.seekg(0, std::ios::end);
    int fileSize = file.tellg();
    file.close();
    std::vector<AutotechCenter> records;
    int recordSize = sizeof(AutotechCenter);
    int numRecords = fileSize / recordSize;



    if (recordIndex < 0 || recordIndex >= numRecords) {
        std::cout << "invalid record index." << std::endl;
        return;
    }



    std::ifstream fileIn(filename, std::ios::binary);
    std::ofstream fileOut("temp.dat", std::ios::binary);



    for (int i = 0; i < numRecords; ++i) {
        AutotechCenter tempRecord;
        fileIn.read(reinterpret_cast<char*>(&tempRecord), sizeof(AutotechCenter));
        if (i != recordIndex) {
            fileOut.write(reinterpret_cast<const char*>(&tempRecord), sizeof(AutotechCenter));
        }
    }



    fileIn.close();
    fileOut.close();
    std::remove(filename.c_str());
    std::rename("temp.dat", filename.c_str());
    std::cout << "the entry was deleted from the file." << std::endl;
}



// function for viewing in a file
void viewRecords(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);



    // check if the file has opened
    if (!file) {
        std::cout << "file opening error." << std::endl;
        return;
    }



    file.seekg(0, std::ios::end);
    int fileSize = file.tellg();
    file.close();
    std::vector<AutotechCenter> records;
    int recordSize = sizeof(AutotechCenter);
    int numRecords = fileSize / recordSize;
    std::ifstream fileIn(filename, std::ios::binary);



    for (int i = 0; i < numRecords; ++i) {
        AutotechCenter tempRecord;
        fileIn.read(reinterpret_cast<char*>(&tempRecord), sizeof(AutotechCenter));
        records.push_back(tempRecord);
    }



    fileIn.close();



    for (const auto& record : records) {
        std::cout << "title: " << record.name << std::endl;
        std::cout << "owner: " << record.ownerName << std::endl;
        std::cout << "rating: " << record.rating << std::endl;
        std::cout << "reviews: " << record.reviews << std::endl;
        std::cout << "telephone: " << record.phoneNumber << std::endl;
        std::cout << "E-mail: " << record.email << std::endl;
        std::cout << "-------------------" << std::endl;
    }
}



// function for updating by index
void updateRecord(const std::string& filename, int recordIndex, const AutotechCenter& updatedRecord) {
    std::fstream file(filename, std::ios::binary | std::ios::in | std::ios::out);



    // check if the file has opened
    if (!file) {
        std::cout << "file opening error." << std::endl;
        return;
    }



    file.seekg(0, std::ios::end);
    int fileSize = file.tellg();
    file.close();
    int recordSize = sizeof(AutotechCenter);
    int numRecords = fileSize / recordSize;



    if (recordIndex < 0 || recordIndex >= numRecords) {
        std::cout << "invalid record index." << std::endl;
        return;
    }



    std::fstream fileInOut(filename, std::ios::binary | std::ios::in | std::ios::out);
    fileInOut.seekp(recordIndex * recordSize, std::ios::beg);
    fileInOut.write(reinterpret_cast<const char*>(&updatedRecord), sizeof(AutotechCenter));
    fileInOut.close();
    std::cout << "record has been updated." << std::endl;
}



// function for performing a task with a matrix
void performMatrixTask() {
    const int N = 3;  // matrix size



    int matrix[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };



    int rowSums[N] = { 0 };



    for (int i = 0; i < N; ++i) {
        int sum = 0;
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] > 0 && matrix[i][j] % 2 == 0) {
                sum += matrix[i][j];
            }
        }



        rowSums[i] = sum;
    }



    std::cout << "characteristics of matrix rows:" << std::endl;



    for (int i = 0; i < N; ++i) {
        std::cout << "line " << i + 1 << ": " << rowSums[i] << std::endl;
    }
}



// function for filling the queue and displaying its contents in reverse order
void fillAndPrintQueue() {
    std::queue<int> myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);
    myQueue.push(5);
    std::cout << "the contents pf the queue are in the reverse order of filling:" << std::endl;



    while (!myQueue.empty()) {
        std::cout << myQueue.back() << " ";
        myQueue.pop();
    }
    std::cout << std::endl;
}



int main() {
    const std::string filename = "autotechcenters.dat";
    int choice;



    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Create a typed file." << std::endl;
        std::cout << "2. Add an entry to a file." << std::endl;
        std::cout << "3. Delete an entry  from a file." << std::endl;
        std::cout << "4. Viewing records from a file." << std::endl;
        std::cout << "5. Update the record by index." << std::endl;
        std::cout << "6. Complete a task with a matrix." << std::endl;
        std::cout << "7. Fill in the queue and output in reverse order." << std::endl;
        std::cout << "8. Exit." << std::endl;
        std::cout << "Select an action  (1-8): ";
        std::cin >> choice;



        switch (choice) {
        case 1:
            createFile(filename);
            break;
        case 2: {
            std::cin.ignore();
            AutotechCenter record;
            std::cout << "Enter a name: ";
            std::getline(std::cin, record.name);
            std::cout << "Enter the owner: ";
            std::getline(std::cin, record.ownerName);
            std::cout << "Enter the rating: ";
            std::cin >> record.rating;
            std::cin.ignore();
            std::cout << "Enter reviews: ";
            std::getline(std::cin, record.reviews);
            std::cout << "Enter telephone: ";
            std::getline(std::cin, record.phoneNumber);
            std::cout << "Enter E-mail: ";
            std::getline(std::cin, record.email);
            addRecord(filename, record);
            break;
        }
        case 3: {
            int recordIndex;
            std::cout << "Enter the index of the record to delete: ";
            std::cin >> recordIndex;
            deleteRecord(filename, recordIndex);
            break;
        }
        case 4:
            viewRecords(filename);
            break;
        case 5: {
            int recordIndex;
            std::cout << "Enter the index of the record to update: ";
            std::cin >> recordIndex;
            std::cin.ignore();
            AutotechCenter updatedRecord;
            std::cout << "Enter name: ";
            std::getline(std::cin, updatedRecord.name);
            std::cout << "Enter the owner: ";
            std::getline(std::cin, updatedRecord.ownerName);
            std::cout << "Enter the rating: ";
            std::cin >> updatedRecord.rating;
            std::cin.ignore();
            std::cout << "Enter reviews: ";
            std::getline(std::cin, updatedRecord.reviews);
            std::cout << "Enter telephone: ";
            std::getline(std::cin, updatedRecord.phoneNumber);
            std::cout << "Enter E-mail: ";
            std::getline(std::cin, updatedRecord.email);
            updateRecord(filename, recordIndex, updatedRecord);
            break;
        }
        case 6:
            performMatrixTask();
            break;
        case 7:
            fillAndPrintQueue();
            break;
        case 8:
            std::cout << "Exit." << std::endl;
            break;
        default:
            std::cout << "Wrong choice.Try again." << std::endl;
        }
    } while (choice != 8);



    return 0;
}

// Cordoba Emiro Variant 8 #include <iost... de Эррера Ромеро Эснеидер Алехандро
Эррера Ромеро Эснеидер Алехандро23:13

// Cordoba Emiro Variant 8
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>



// Structure for entries in a file
struct AutotechCenter {
    std::string name;
    std::string ownerName;
    int rating;
    std::string reviews;
    std::string phoneNumber;
    std::string email;
    std::string reviewsDate;
};



// function for a typed file
void createFile(const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);



    // check if the file has opened
    if (!file) {
        std::cout << "the typed file has been created." << std::endl;
        return;
    }



    file.close();
    std::cout << "the typed file has been created." << std::endl;
}



//function to add to a file
void addRecord(const std::string& filename, const AutotechCenter& record) {
    std::ofstream file(filename, std::ios::binary | std::ios::app);
    // check if the file has opened
    if (!file) {
        std::cout << "file opening error." << std::endl;
        return;
    }



    file.write(reinterpret_cast<const char*>(&record), sizeof(AutotechCenter));
    file.close();
    std::cout << "." << std::endl;
}



// function for deleting from a file
void deleteRecord(const std::string& filename, int recordIndex) {
    std::ifstream file(filename, std::ios::binary);



    // check if the file has opened
    if (!file) {
        std::cout << "file opening error." << std::endl;
        return;
    }



    file.seekg(0, std::ios::end);
    int fileSize = file.tellg();
    file.close();
    std::vector<AutotechCenter> records;
    int recordSize = sizeof(AutotechCenter);
    int numRecords = fileSize / recordSize;



    if (recordIndex < 0 || recordIndex >= numRecords) {
        std::cout << "invalid record index." << std::endl;
        return;
    }



    std::ifstream fileIn(filename, std::ios::binary);
    std::ofstream fileOut("temp.dat", std::ios::binary);



    for (int i = 0; i < numRecords; ++i) {
        AutotechCenter tempRecord;
        fileIn.read(reinterpret_cast<char*>(&tempRecord), sizeof(AutotechCenter));
        if (i != recordIndex) {
            fileOut.write(reinterpret_cast<const char*>(&tempRecord), sizeof(AutotechCenter));
        }
    }



    fileIn.close();
    fileOut.close();
    std::remove(filename.c_str());
    std::rename("temp.dat", filename.c_str());
    std::cout << "the entry was deleted from the file." << std::endl;
}



// function for viewing in a file
void viewRecords(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);



    // check if the file has opened
    if (!file) {
        std::cout << "file opening error." << std::endl;
        return;
    }



    file.seekg(0, std::ios::end);
    int fileSize = file.tellg();
    file.close();
    std::vector<AutotechCenter> records;
    int recordSize = sizeof(AutotechCenter);
    int numRecords = fileSize / recordSize;
    std::ifstream fileIn(filename, std::ios::binary);



    for (int i = 0; i < numRecords; ++i) {
        AutotechCenter tempRecord;
        fileIn.read(reinterpret_cast<char*>(&tempRecord), sizeof(AutotechCenter));
        records.push_back(tempRecord);
    }



    fileIn.close();



    for (const auto& record : records) {
        std::cout << "title: " << record.name << std::endl;
        std::cout << "owner: " << record.ownerName << std::endl;
        std::cout << "rating: " << record.rating << std::endl;
        std::cout << "reviews: " << record.reviews << std::endl;
        std::cout << "telephone: " << record.phoneNumber << std::endl;
        std::cout << "E-mail: " << record.email << std::endl;
        std::cout << "-------------------" << std::endl;
    }
}



// function for updating by index
void updateRecord(const std::string& filename, int recordIndex, const AutotechCenter& updatedRecord) {
    std::fstream file(filename, std::ios::binary | std::ios::in | std::ios::out);



    // check if the file has opened
    if (!file) {
        std::cout << "file opening error." << std::endl;
        return;
    }



    file.seekg(0, std::ios::end);
    int fileSize = file.tellg();
    file.close();
    int recordSize = sizeof(AutotechCenter);
    int numRecords = fileSize / recordSize;



    if (recordIndex < 0 || recordIndex >= numRecords) {
        std::cout << "invalid record index." << std::endl;
        return;
    }



    std::fstream fileInOut(filename, std::ios::binary | std::ios::in | std::ios::out);
    fileInOut.seekp(recordIndex * recordSize, std::ios::beg);
    fileInOut.write(reinterpret_cast<const char*>(&updatedRecord), sizeof(AutotechCenter));
    fileInOut.close();
    std::cout << "record has been updated." << std::endl;
}



// function for performing a task with a matrix
void performMatrixTask() {
    const int N = 3;  // matrix size



    int matrix[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };



    int rowSums[N] = { 0 };



    for (int i = 0; i < N; ++i) {
        int sum = 0;
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] > 0 && matrix[i][j] % 2 == 0) {
                sum += matrix[i][j];
            }
        }



        rowSums[i] = sum;
    }



    std::cout << "characteristics of matrix rows:" << std::endl;



    for (int i = 0; i < N; ++i) {
        std::cout << "line " << i + 1 << ": " << rowSums[i] << std::endl;
    }
}



// function for filling the queue and displaying its contents in reverse order
void fillAndPrintQueue() {
    std::queue<int> myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);
    myQueue.push(5);
    std::cout << "the contents pf the queue are in the reverse order of filling:" << std::endl;



    while (!myQueue.empty()) {
        std::cout << myQueue.back() << " ";
        myQueue.pop();
    }
    std::cout << std::endl;
}



void findReviewsInRange(const std::string& filename, const std::string& startDate, const std::string& endDate) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cout << "Error opening the file." << std::endl;
        return;
    }



    std::vector<AutotechCenter> matchingReviews;



    AutotechCenter record;
    while (file.read(reinterpret_cast<char*>(&record), sizeof(AutotechCenter))) {
        std::string reviewDate = record.reviewsDate;  // Assuming the review date is stored in the "reviewsDate" field



        // Extracting month and year from the date string
        std::string month = reviewDate.substr(0, reviewDate.find(' '));
        std::string year = reviewDate.substr(reviewDate.find(' ') + 1);



        // Checking if the review date falls within the specified range
        if (month >= startDate && month <= endDate && year == "2023") {
            matchingReviews.push_back(record);
        }
    }



    file.close();



    // Displaying the matching reviews
    std::cout << "Reviews from June 2023 to August 2023:" << std::endl;
    for (const auto& review : matchingReviews) {
        std::cout << "Name: " << review.name << std::endl;
        std::cout << "Owner: " << review.ownerName << std::endl;
        std::cout << "Rating: " << review.rating << std::endl;
        std::cout << "Reviews: " << review.reviews << std::endl;
        std::cout << "Phone: " << review.phoneNumber << std::endl;
        std::cout << "Email: " << review.email << std::endl;
        std::cout << "-------------------" << std::endl;
    }
}



int main() {
    const std::string filename = "autotechcenters.dat";
    int choice;



    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "0. Find reviews from June to August 2023." << std::endl;
        std::cout << "1. Create a typed file." << std::endl;
        std::cout << "2. Add an entry to a file." << std::endl;
        std::cout << "3. Delete an entry  from a file." << std::endl;
        std::cout << "4. Viewing records from a file." << std::endl;
        std::cout << "5. Update the record by index." << std::endl;
        std::cout << "6. Complete a task with a matrix." << std::endl;
        std::cout << "7. Fill in the queue and output in reverse order." << std::endl;
        std::cout << "8. Exit." << std::endl;
        std::cout << "Select an action  (1-8): ";
        std::cin >> choice;



        switch (choice) {
        case 0:
            findReviewsInRange(filename, "june", "august");
            break;
        case 1:
            createFile(filename);
            break;
        case 2: {
            std::cin.ignore();
            AutotechCenter record;
            std::cout << "Enter a name: ";
            std::getline(std::cin, record.name);
            std::cout << "Enter the owner: ";
            std::getline(std::cin, record.ownerName);
            std::cout << "Enter the rating: ";
            std::cin >> record.rating;
            std::cin.ignore();
            std::cout << "Enter reviews: ";
            std::getline(std::cin, record.reviews);
            std::cout << "Enter telephone: ";
            std::getline(std::cin, record.phoneNumber);
            std::cout << "Enter E-mail: ";
            std::getline(std::cin, record.email);
            addRecord(filename, record);
            break;
        }
        case 3: {
            int recordIndex;
            std::cout << "Enter the index of the record to delete: ";
            std::cin >> recordIndex;
            deleteRecord(filename, recordIndex);
            break;
        }
        case 4:
            viewRecords(filename);
            break;
        case 5: {
            int recordIndex;
            std::cout << "Enter the index of the record to update: ";
            std::cin >> recordIndex;
            std::cin.ignore();
            AutotechCenter updatedRecord;
            std::cout << "Enter name: ";
            std::getline(std::cin, updatedRecord.name);
            std::cout << "Enter the owner: ";
            std::getline(std::cin, updatedRecord.ownerName);
            std::cout << "Enter the rating: ";
            std::cin >> updatedRecord.rating;
            std::cin.ignore();
            std::cout << "Enter reviews: ";
            std::getline(std::cin, updatedRecord.reviews);
            std::cout << "Enter telephone: ";
            std::getline(std::cin, updatedRecord.phoneNumber);
            std::cout << "Enter E-mail: ";
            std::getline(std::cin, updatedRecord.email);
            updateRecord(filename, recordIndex, updatedRecord);
            break;
        }
        case 6:
            performMatrixTask();
            break;
        case 7:
            fillAndPrintQueue();
            break;
        case 8:
            std::cout << "Exit." << std::endl;
            break;
        default:
            std::cout << "Wrong choice.Try again." << std::endl;
        }
    } while (choice != 8);



    return 0;
}

