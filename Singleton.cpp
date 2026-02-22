// Singleton is a creational design pattern that ensures a class has only one instance and provides a global point of access to it.

// Advantages:
// - Only one instance exists (controlled access)
// - Useful for shared resources (logging, config, etc.)
// - Lazy initialization possible
// Disadvantages:
// - Harder to test (global state)
// - Can hide dependencies (tight coupling)
// - Not thread-safe by default

#include<iostream>

class FileManager {
private:
    static FileManager* file;
    FileManager(){};
public:
    static FileManager* getInstance(){ // always returns the same object
        if(!file){
            file = new FileManager();
        }
        return file;
    }
    FileManager(FileManager& other) = delete; // Delete copy constructor to prevent copying
    FileManager& operator=(const FileManager&) = delete; // Delete assignment operator to prevent assignment
};

FileManager* FileManager::file = nullptr; //can be allocated in stack as well

int main(){
    FileManager* f1 =FileManager::getInstance();
    std::cout<<f1<<std::endl;
    FileManager* f2 =FileManager::getInstance();
    std::cout<<f2<<std::endl;
    return 0;
}