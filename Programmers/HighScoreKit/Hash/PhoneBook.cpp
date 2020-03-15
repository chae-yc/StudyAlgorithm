#include <string>
#include <vector>
#include <map>

#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    
    for (int comp1 = 0; comp1 < phone_book.size(); ++comp1) {
        for (int comp2 = comp1+1; comp2 < phone_book.size(); ++comp2) {
            if (phone_book[comp1].rfind(phone_book[comp2], 0) == 0) {
                
                return false;
            }
        }
    }
        
    return true;
}

int main() {
    vector<string> phone_book = { "119", "97674223", "1195524421" };
    // auto result = solution(phone_book);
    cout << "12" << endl;
    return 0;
}