
class BankAccount{
    private:
        float balance;
    public:
        BankAccount();
        float CheckBalance();
        void Deposit(float);
        void Withdrawl();
};

BankAccount::BankAccount(){
    balance = 0;
}

float BankAccount::CheckBalance(){
    return balance;
}

void BankAccount::Deposit(float money){
    balance = balance + money;
}

void BankAccount::Withdrawl(){
    balance = balance - 100;
}
