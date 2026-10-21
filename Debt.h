
#include <string>
using namespace std;

class Debt{
private:
    string creditor;
    string debitor;
    float amount;

public:
    // Constructor
    Debt(string crdtor, string dbtor, float amnt):creditor(crdtor),debitor(dbtor),amount(amnt){}

    // setters
    void setCreditor(string name)
    {
        creditor = name;
    }
    void setDebitor(string name)
    {
        debitor = name;
    }
    void setAmount(float amnt)
    {
        amount = amnt;
    }

    //getters
    string getCreditor() const{
        return creditor;
    }
    string getDebitor() const{
        return debitor;
    }
    float getAmount() const{
        return amount;
    }
    void summaryOfDebt()
    {
        
    }
};