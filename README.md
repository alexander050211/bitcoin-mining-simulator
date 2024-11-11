## How to run
When initially running, the user can manually set the mining difficulty. If not, the default difficulty is set to 4. Since the time complexity for mining is $O(16^{difficulty})$, I suggest to keep the difficulty 5 or lower. If an invalid input is given as the difficulty, it will be set to default.

## Commands
There are various commands to use. You can type "help" to get information about these commands.

### create_account
You can create an account by giving the name and initial balance. The balance will compute up to two decimal places.
```
> create_account Alice 1000.00
Account created successfully
```

### random
A single block of the blockchain can hold up to 10 transactions. It will be annoying for the user to create enough transactions to mine multiple blocks. So, you can use this command to generate random transactions. Of course, there should be at least 2 accounts for this to happen.

### mine
Transactions are temporarily stored in a pending pool. A new block is mined whenever the number of transactions in the pool exceed the maximum limit. Whenever the user tends to manually empty the pool, you can use this command. There should be at least 1 pending transaction.

### balances
You can use this command to see the current balance for all accounts.

### pending
You can use this command to see the pending transactions.

### chain
You can use this command to see the information of all blocks including their hash values that form the blockchain.

### help
Whenever you feel lost, you can always use this command to use other commands properly.

### exit
You can use this command to terminate the program.